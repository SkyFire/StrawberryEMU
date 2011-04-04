/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2010 MaNGOS <http://getmangos.com/>
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
#include "CharacterDatabaseCleaner.h"
#include "World.h"
#include "Database/DatabaseEnv.h"
#include "DBCStores.h"

void CharDBCleaner::CleanDatabase()
{
    // config to disable
    if (!sWorld->getBoolConfig(CONFIG_CLEAN_CHARACTER_DB))
        return;

    sLog->outString("Cleaning character database...");

    uint32 oldMSTime = getMSTime();

    // check flags which clean ups are necessary
    QueryResult result = CharDB.Query("SELECT value FROM worldstates WHERE entry = 20004");
    if (!result)
        return;

    uint32 flags = (*result)[0].GetUInt32();
    
    // clean up
    if (flags & CLEANING_FLAG_ACHIEVEMENT_PROGRESS)
        CleanCharacterAchievementProgress();

    if (flags & CLEANING_FLAG_SKILLS)
        CleanCharacterSkills();

    if (flags & CLEANING_FLAG_SPELLS)
        CleanCharacterSpell();

    if (flags & CLEANING_FLAG_TALENTS)
        CleanCharacterTalent();

    if (flags & CLEANING_FLAG_QUESTSTATUS)
        CleanCharacterQuestStatus();

    // NOTE: In order to have persistentFlags be set in worldstates for the next cleanup, 
    // you need to define them at least once in worldstates.
    flags &= sWorld->getIntConfig(CONFIG_PERSISTENT_CHARACTER_CLEAN_FLAGS);
    CharDB.DirectPExecute("UPDATE worldstates SET value = %u WHERE entry = 20004", flags);

    sWorld->SetCleaningFlags(flags);

    sLog->outString(">> Cleaned character database in %u ms", GetMSTimeDiffToNow(oldMSTime));
    sLog->outString();
}

void CharDBCleaner::CheckUnique(const char* column, const char* table, bool (*check)(uint32))
{
    QueryResult result = CharDB.PQuery("SELECT DISTINCT %s FROM %s", column, table);
    if (!result)
    {
        sLog->outString("Table %s is empty.", table);
        return;
    }

    bool found = false;
    std::ostringstream ss;
    do
    {

        Field *fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();

        if (!check(id))
        {
            if (!found)
            {
                ss << "DELETE FROM " << table << " WHERE " << column << " IN (";
                found = true;
            }
            else
                ss << ",";

            ss << id;
        }
    }
    while(result->NextRow());

    if (found)
    {
        ss << ")";
        CharDB.Execute(ss.str().c_str());
    }
}

bool CharDBCleaner::AchievementProgressCheck(uint32 criteria)
{
    return sAchievementCriteriaStore.LookupEntry(criteria);
}

void CharDBCleaner::CleanCharacterAchievementProgress()
{
    CheckUnique("criteria", "character_achievement_progress", &AchievementProgressCheck);
}

bool CharDBCleaner::SkillCheck(uint32 skill)
{
    return sSkillLineStore.LookupEntry(skill);
}

void CharDBCleaner::CleanCharacterSkills()
{
    CheckUnique("skill", "character_skills", &SkillCheck);
}

bool CharDBCleaner::SpellCheck(uint32 spell_id)
{
    return sSpellStore.LookupEntry(spell_id) && !GetTalentSpellPos(spell_id);
}

void CharDBCleaner::CleanCharacterSpell()
{
    CheckUnique("spell", "character_spell", &SpellCheck);
}

bool CharDBCleaner::TalentCheck(uint32 talent_id)
{
    TalentEntry const *talentInfo = sTalentStore.LookupEntry(talent_id);
    if (!talentInfo)
        return false;

    return sTalentTabStore.LookupEntry(talentInfo->TalentTab);
}

void CharDBCleaner::CleanCharacterTalent()
{
    CharDB.DirectPExecute("DELETE FROM character_talent WHERE spec > %u", MAX_TALENT_SPECS);
    CheckUnique("spell", "character_talent", &TalentCheck);
}

void CharDBCleaner::CleanCharacterQuestStatus()
{
    CharDB.DirectExecute("DELETE FROM character_queststatus WHERE status = 0");
}

