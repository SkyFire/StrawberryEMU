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

#include "DatabaseEnv.h"
#include "AccountMgr.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Util.h"
#include "SHA1.h"

AccountMgr::AccountMgr() {}
AccountMgr::~AccountMgr() {}

AccountOpResult AccountMgr::CreateAccount(std::string username, std::string password)
{
    if (utf8length(username) > MAX_ACCOUNT_STR)
        return AOR_NAME_TOO_LONG;                           // username's too long

    normalizeString(username);
    normalizeString(password);

    if (GetId(username))
    {
        return AOR_NAME_ALREDY_EXIST;                       // username does already exist
    }

    RealmDB.PExecute("INSERT INTO account(username,sha_pass_hash,joindate) VALUES('%s','%s',NOW())", username.c_str(), CalculateShaPassHash(username, password).c_str());
    RealmDB.Execute("INSERT INTO realmcharacters (realmid, acctid, numchars) SELECT realmlist.id, account.id, 0 FROM realmlist,account LEFT JOIN realmcharacters ON acctid=account.id WHERE acctid IS NULL");

    return AOR_OK;                                          // everything's fine
}

AccountOpResult AccountMgr::DeleteAccount(uint32 accid)
{
    QueryResult result = RealmDB.PQuery("SELECT 1 FROM account WHERE id='%d'", accid);
    if (!result)
        return AOR_NAME_NOT_EXIST;                          // account doesn't exist

    // existed characters list
    result = CharDB.PQuery("SELECT guid FROM characters WHERE account='%d'",accid);
    if (result)
    {
        do
        {
            Field *fields = result->Fetch();
            uint32 guidlo = fields[0].GetUInt32();
            uint64 guid = MAKE_NEW_GUID(guidlo, 0, HIGHGUID_PLAYER);

            // kick if player currently
            if (Player* p = ObjectAccessor::FindPlayer(guid))
            {
                WorldSession* s = p->GetSession();
                s->KickPlayer();                            // mark session to remove at next session list update
                s->LogoutPlayer(false);                     // logout player without waiting next session list update
            }

            Player::DeleteFromDB(guid, accid, false);       // no need to update realm characters
        } while (result->NextRow());
    }

    // table realm specific but common for all characters of account for realm
    CharDB.PExecute("DELETE FROM character_tutorial WHERE account = '%u'",accid);
    CharDB.PExecute("DELETE FROM account_data WHERE account = '%u'",accid);

    SQLTransaction trans = RealmDB.BeginTransaction();

    trans->PAppend("DELETE FROM account WHERE id='%d'", accid);
    trans->PAppend("DELETE FROM account_access WHERE id ='%d'", accid);
    trans->PAppend("DELETE FROM realmcharacters WHERE acctid='%d'", accid);

    RealmDB.CommitTransaction(trans);

    return AOR_OK;
}

AccountOpResult AccountMgr::ChangeUsername(uint32 accid, std::string new_uname, std::string new_passwd)
{
    QueryResult result = RealmDB.PQuery("SELECT 1 FROM account WHERE id='%d'", accid);
    if (!result)
        return AOR_NAME_NOT_EXIST;                          // account doesn't exist

    if (utf8length(new_uname) > MAX_ACCOUNT_STR)
        return AOR_NAME_TOO_LONG;

    if (utf8length(new_passwd) > MAX_ACCOUNT_STR)
        return AOR_PASS_TOO_LONG;

    normalizeString(new_uname);
    normalizeString(new_passwd);

    std::string safe_new_uname = new_uname;
    RealmDB.escape_string(safe_new_uname);

    RealmDB.PExecute("UPDATE account SET v='0',s='0',username='%s',sha_pass_hash='%s' WHERE id='%d'", safe_new_uname.c_str(),
                CalculateShaPassHash(new_uname, new_passwd).c_str(), accid);

    return AOR_OK;
}

AccountOpResult AccountMgr::ChangePassword(uint32 accid, std::string new_passwd)
{
    std::string username;

    if (!GetName(accid, username))
        return AOR_NAME_NOT_EXIST;                          // account doesn't exist

    if (utf8length(new_passwd) > MAX_ACCOUNT_STR)
        return AOR_PASS_TOO_LONG;

    normalizeString(username);
    normalizeString(new_passwd);

    // also reset s and v to force update at next realmd login
    RealmDB.PExecute("UPDATE account SET v='0', s='0', sha_pass_hash='%s' WHERE id='%d'",
                CalculateShaPassHash(username, new_passwd).c_str(), accid);

    return AOR_OK;
}

uint32 AccountMgr::GetId(std::string username)
{
    RealmDB.escape_string(username);
    QueryResult result = RealmDB.PQuery("SELECT id FROM account WHERE username = '%s'", username.c_str());
    if (!result)
        return 0;
    else
    {
        uint32 id = (*result)[0].GetUInt32();
        return id;
    }
}

uint32 AccountMgr::GetSecurity(uint32 acc_id)
{
    QueryResult result = RealmDB.PQuery("SELECT gmlevel FROM account_access WHERE id = '%u'", acc_id);
    if (result)
    {
        uint32 sec = (*result)[0].GetUInt32();
        return sec;
    }

    return 0;
}

uint32 AccountMgr::GetSecurity(uint64 acc_id, int32 realm_id)
{
    QueryResult result = (realm_id == -1)
        ? RealmDB.PQuery("SELECT gmlevel FROM account_access WHERE id = '%u' AND RealmID = '%d'", acc_id, realm_id)
        : RealmDB.PQuery("SELECT gmlevel FROM account_access WHERE id = '%u' AND (RealmID = '%d' OR RealmID = '-1')", acc_id, realm_id);
    if (result)
    {
        uint32 sec = (*result)[0].GetUInt32();
        return sec;
    }

    return 0;
}

bool AccountMgr::GetName(uint32 acc_id, std::string &name)
{
    QueryResult result = RealmDB.PQuery("SELECT username FROM account WHERE id = '%u'", acc_id);
    if (result)
    {
        name = (*result)[0].GetString();
        return true;
    }

    return false;
}

bool AccountMgr::CheckPassword(uint32 accid, std::string passwd)
{
    std::string username;
    if (!GetName(accid, username))
        return false;

    normalizeString(username);
    normalizeString(passwd);

    QueryResult result = RealmDB.PQuery("SELECT 1 FROM account WHERE id='%d' AND sha_pass_hash='%s'", accid, CalculateShaPassHash(username, passwd).c_str());
    if (result)
        return true;

    return false;
}

uint32 AccountMgr::GetCharactersCount(uint32 acc_id)
{
    uint32 charcount = 0;
    // check character count
    QueryResult result = CharDB.PQuery("SELECT COUNT(guid) FROM characters WHERE account = '%d'", acc_id);
    if (result)
    {
        Field *fields=result->Fetch();
        charcount = fields[0].GetUInt32();
    }
    return charcount;
}

bool AccountMgr::normalizeString(std::string& utf8str)
{
    wchar_t wstr_buf[MAX_ACCOUNT_STR+1];

    size_t wstr_len = MAX_ACCOUNT_STR;
    if (!Utf8toWStr(utf8str,wstr_buf,wstr_len))
        return false;
#ifdef _MSC_VER
#pragma warning(disable: 4996)
#endif
    std::transform(&wstr_buf[0], wstr_buf+wstr_len, &wstr_buf[0], wcharToUpperOnlyLatin);
#ifdef _MSC_VER
#pragma warning(default: 4996)
#endif

    return WStrToUtf8(wstr_buf,wstr_len,utf8str);
}

std::string AccountMgr::CalculateShaPassHash(std::string& name, std::string& password)
{
    SHA1Hash sha;
    sha.Initialize();
    sha.UpdateData(name);
    sha.UpdateData(":");
    sha.UpdateData(password);
    sha.Finalize();

    std::string encoded;
    hexEncodeByteArray(sha.GetDigest(), sha.GetLength(), encoded);

    return encoded;
}

