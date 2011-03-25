/*
 * Copyright (C) 2010-2011 Strawberry-Pr0jcts <http://www.strawberry-pr0jcts.com/>
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

#include "ServerOpcodeHandler.h"
#include "WorldSession.h"

void ServerOpcodeTable()
{
    /***********************************************************/
    /********************* ATTACK OPCODES **********************/
    /***********************************************************/

    OPCODE(SMSG_ATTACKSTART,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);     
    OPCODE(SMSG_ATTACKSTOP,                             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_ATTACKSWING_NOTINRANGE,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_ATTACKSWING_BADFACING,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_ATTACKSWING_DEADTARGET,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_ATTACKSWING_CANT_ATTACK,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_ATTACKERSTATEUPDATE,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /******************** AUCTION OPCODES **********************/
    /***********************************************************/

    OPCODE(SMSG_AUCTION_COMMAND_RESULT,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AUCTION_LIST_RESULT,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AUCTION_OWNER_LIST_RESULT,              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AUCTION_BIDDER_NOTIFICATION,            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AUCTION_OWNER_NOTIFICATION,             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AUCTION_BIDDER_LIST_RESULT,             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AUCTION_REMOVED_NOTIFICATION,           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AUCTION_LIST_PENDING_SALES,             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /***************** AUTHENTICATION OPCODES ******************/
    /***********************************************************/

    OPCODE(SMSG_AUTH_SRP6_RESPONSE,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AUTH_CHALLENGE,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AUTH_RESPONSE,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_REALM_SPLIT,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_REDIRECT_CLIENT,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /******************* BATTLEFIELD OPCODES *******************/
    /***********************************************************/

    OPCODE(SMSG_BATTLEFIELD_PORT_DENIED,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_MGR_ENTRY_INVITE,           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_MGR_ENTERED,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_MGR_QUEUE_INVITE,           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_MGR_QUEUE_REQUEST_RESPONSE, STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_MGR_EJECT_PENDING,          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_MGR_EJECTED,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_MGR_STATE_CHANGE,           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_LIST,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_WIN_OBSOLETE,               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_LOSE_OBSOLETE,              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_STATUS,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /********************* BINDING OPCODES *********************/
    /***********************************************************/

    OPCODE(SMSG_BINDPOINTUPDATE,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BINDZONEREPLY,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_PLAYERBOUND,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_PLAYERBINDERROR,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BINDER_CONFIRM,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /******************** CALENDAR OPCODES *********************/
    /***********************************************************/

    OPCODE(SMSG_CALENDAR_SEND_CALENDAR,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_SEND_EVENT,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_FILTER_GUILD,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_ARENA_TEAM,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_EVENT_INVITE,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_EVENT_INVITE_REMOVED,          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_EVENT_STATUS,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_COMMAND_RESULT,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_RAID_LOCKOUT_ADDED,            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_RAID_LOCKOUT_REMOVED,          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_EVENT_INVITE_ALERT,            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_EVENT_INVITE_REMOVED_ALERT,    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_EVENT_INVITE_STATUS_ALERT,     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_EVENT_REMOVED_ALERT,           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_EVENT_UPDATED_ALERT,           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_EVENT_MODERATOR_STATUS_ALERT,  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_SEND_NUM_PENDING,              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_UPDATE_INVITE_LIST,            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_NULL);
    OPCODE(SMSG_CALENDAR_UPDATE_INVITE_LIST2,           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_NULL);
    OPCODE(SMSG_CALENDAR_UPDATE_INVITE_LIST3,           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_ACTION_PENDING,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /******************** CHARACTER OPCODES ********************/
    /***********************************************************/



    /***********************************************************/
    /********************** CHAT OPCODES ***********************/
    /***********************************************************/



    /***********************************************************/
    /********************* COMBAT OPCODES **********************/
    /***********************************************************/



    /***********************************************************/
    /********************** DUEL OPCODES ***********************/
    /***********************************************************/



    /***********************************************************/
    /******************** FACTION OPCODES **********************/
    /***********************************************************/



    /***********************************************************/
    /******************* GAMEMASTER OPCODES ********************/
    /***********************************************************/



    /***********************************************************/
    /****************** (GAME)OBJECT OPCODES *******************/
    /***********************************************************/



    /***********************************************************/
    /********************** GOSSIP OPCODES *********************/
    /***********************************************************/



    /***********************************************************/
    /********************** GROUP OPCODES **********************/
    /***********************************************************/



    /***********************************************************/
    /********************** GUILD OPCODES **********************/
    /***********************************************************/



    /***********************************************************/
    /******************** INSTANCE OPCODES *********************/
    /***********************************************************/



    /***********************************************************/
    /********************** ITEM OPCODES ***********************/
    /***********************************************************/



    /***********************************************************/
    /******************* LOGIN / OUT OPCODES *******************/
    /***********************************************************/



    /***********************************************************/
    /********************** LOOT OPCODES ***********************/
    /***********************************************************/



    /***********************************************************/
    /******************** MOVEMENT OPCODES *********************/
    /***********************************************************/



    /***********************************************************/
    /********************* MOVIE OPCODES ***********************/
    /***********************************************************/



    /***********************************************************/
    /****************** MOUNT / PET OPCODES ********************/
    /***********************************************************/



    /***********************************************************/
    /********************** MULTI OPCODES **********************/
    /***********************************************************/



    /***********************************************************/
    /********************* PLAYER OPCODES **********************/
    /***********************************************************/



    /***********************************************************/
    /********************* QUERY OPCODES ***********************/
    /***********************************************************/



    /***********************************************************/
    /********************* QUEST OPCODES ***********************/
    /***********************************************************/



    /***********************************************************/
    /********************* SPELL OPCODES ***********************/
    /***********************************************************/



    /***********************************************************/
    /******************* TRANSPORT OPCODES *********************/
    /***********************************************************/



    /***********************************************************/
    /****************** TIME / SPEED OPCODES *******************/
    /***********************************************************/



    /***********************************************************/
    /****************** UNCATEGORZIED OPCODES ******************/
    /***********************************************************/



    /***********************************************************/
    /********************** WORLD OPCODES **********************/
    /***********************************************************/



    

};


