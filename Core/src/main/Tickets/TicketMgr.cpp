/*
 * Copyright (C) 2010-2011 Strawberry-Pr0jcts <http://www.strawberry-pr0jcts.com/>
 *
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 *
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Common.h"
#include "DatabaseEnv.h"
#include "SQLStorage.h"
#include "Log.h"
#include "TicketMgr.h"
#include "WorldPacket.h"
#include "WorldSession.h"

TicketMgr::TicketMgr()
{
    m_GMticketid = 0; // this is initialized in LoadGMTickets() but it's best to be safe
    m_GMSurveyID = 0;
    m_openTickets = 0;
    lastChange = time(NULL);
    status = true;
}

uint64 TicketMgr::GenerateGMTicketId()
{
    return ++m_GMticketid;
}

void TicketMgr::LoadGMTickets()
{
    uint32 oldMSTime = getMSTime();

    if (!m_GMTicketList.empty())
        for (GmTicketList::const_iterator itr = m_GMTicketList.begin(); itr != m_GMTicketList.end(); ++itr)
            delete *itr;

    m_GMTicketList.clear();
    m_GMticketid = 0;
    m_openTickets = 0;

    QueryResult result = CharDB.Query("SELECT guid, playerGuid, name, message, createtime, map, posX, posY, posZ, timestamp, closed,"
                                                 "assignedto, comment, completed, escalated, viewed FROM gm_tickets");

    if (!result)
    {
        sLog->outString(">> Loaded 0 GM tickets. DB table `gm_tickets` is empty!");
        sLog->outString();
        return;
    }

    uint32 count = 0;
    
    do
    {
        Field *fields = result->Fetch();
        GM_Ticket *ticket = new GM_Ticket;
        ticket->guid = fields[0].GetUInt32();
        ticket->playerGuid = fields[1].GetUInt32();
        ticket->name = fields[2].GetString();
        ticket->message = fields[3].GetString();
        ticket->createtime = fields[4].GetUInt32();
        ticket->map = fields[5].GetUInt32();
        ticket->pos_x = fields[6].GetFloat();
        ticket->pos_y = fields[7].GetFloat();
        ticket->pos_z = fields[8].GetFloat();
        ticket->timestamp = fields[9].GetUInt32();
        ticket->closed = fields[10].GetInt32();
        if (ticket->closed == 0)
            m_openTickets++;

        ticket->assignedToGM = fields[11].GetUInt64();
        ticket->comment = fields[12].GetString();
        ticket->completed = fields[13].GetBool();
        ticket->escalated = fields[14].GetUInt8();
        ticket->viewed = fields[15].GetBool();
        ++count;

        m_GMTicketList.push_back(ticket);
    } while (result->NextRow());

    result = CharDB.Query("SELECT MAX(guid) from gm_tickets");

    if (result)
    {
        Field *fields = result->Fetch();
        m_GMticketid = fields[0].GetUInt64();
    }

    sLog->outString(">> Loaded %u GM tickets in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    sLog->outString();
}

void TicketMgr::LoadGMSurveys()
{
    uint32 oldMSTime = getMSTime();

    // we don't actually load anything into memory here as there's no reason to
    QueryResult result = CharDB.Query("SELECT MAX(surveyid) FROM gm_surveys");
    if (result)
    {
        Field *fields = result->Fetch();
        m_GMSurveyID = fields[0].GetUInt32();
    }
    else
        m_GMSurveyID = 0;

    sLog->outString(">> Loaded GM Survey count from database in %u ms", GetMSTimeDiffToNow(oldMSTime));
    sLog->outString();
}

void TicketMgr::AddOrUpdateGMTicket(GM_Ticket &ticket, bool create)
{
    if (create)
    {
        m_GMTicketList.push_back(&ticket);
        if (ticket.closed == 0)
            m_openTickets++;
    }

    _AddOrUpdateGMTicket(ticket);
}

void TicketMgr::_AddOrUpdateGMTicket(GM_Ticket &ticket)
{
    std::string msg(ticket.message), name(ticket.name), comment(ticket.comment);
    CharDB.escape_string(msg);
    CharDB.escape_string(name);
    CharDB.escape_string(comment);
    std::ostringstream ss;
    ss << "REPLACE INTO gm_tickets (guid, playerGuid, name, message, createtime, map, posX, posY, posZ, timestamp, closed, assignedto, comment, completed, escalated, viewed) VALUES (";
    ss << ticket.guid << ", ";
    ss << ticket.playerGuid << ", '";
    ss << name << "', '";
    ss << msg << "', " ;
    ss << ticket.createtime << ", ";
    ss << ticket.map << ", ";
    ss << ticket.pos_x << ", ";
    ss << ticket.pos_y << ", ";
    ss << ticket.pos_z << ", ";
    ss << ticket.timestamp << ", ";
    ss << ticket.closed << ", ";
    ss << ticket.assignedToGM << ", '";
    ss << comment << "', ";
    ss << (ticket.completed ? 1 : 0) << ", ";
    ss << uint32(ticket.escalated) << ", ";
    ss << (ticket.viewed ? 1 : 0) << ");";

    SQLTransaction trans = CharDB.BeginTransaction();
    trans->Append(ss.str().c_str());
    CharDB.CommitTransaction(trans);
}

void TicketMgr::RemoveGMTicket(GM_Ticket *ticket, int64 source, bool permanently)
{
    for (GmTicketList::iterator i = m_GMTicketList.begin(); i != m_GMTicketList.end(); ++i)
        if ((*i)->guid == ticket->guid)
        {
            if (permanently)
            {
                CharDB.PExecute("DELETE FROM gm_tickets WHERE guid = '%u'", ticket->guid);
                i = m_GMTicketList.erase(i);
                ticket = NULL;
                return;
            }
            (*i)->closed = source;

            if (source != 0)
                m_openTickets--;

            _AddOrUpdateGMTicket(*(*i));
        }
}

void TicketMgr::RemoveGMTicket(uint64 ticketGuid, int64 source, bool permanently)
{
    GM_Ticket *ticket = GetGMTicket(ticketGuid);
    ASSERT(ticket); // hmm
    RemoveGMTicket(ticket, source, permanently);
}
