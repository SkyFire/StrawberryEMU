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

#include "QuestDef.h"
#include "Player.h"
#include "Unit.h"
#include "World.h"

Quest::Quest(Field * questRecord)
{
    QuestId = questRecord[0].GetUInt32();
    QuestMethod = questRecord[1].GetUInt32();
    ZoneOrSort = questRecord[2].GetInt32();
    SkillOrClassMask = questRecord[3].GetInt32();
    MinLevel = questRecord[4].GetUInt32();
    MaxLevel = questRecord[5].GetUInt32();
    QuestLevel = questRecord[6].GetInt32();
    Type = questRecord[7].GetUInt32();
    RequiredRaces = questRecord[8].GetUInt32();
    RequiredSkillValue = questRecord[9].GetUInt32();
    RepObjectiveFaction = questRecord[10].GetUInt32();
    RepObjectiveValue = questRecord[11].GetInt32();
    RepObjectiveFaction2 = questRecord[12].GetUInt32();
    RepObjectiveValue2 = questRecord[13].GetInt32();
    RequiredMinRepFaction = questRecord[14].GetUInt32();
    RequiredMinRepValue = questRecord[15].GetInt32();
    RequiredMaxRepFaction = questRecord[16].GetUInt32();
    RequiredMaxRepValue = questRecord[17].GetInt32();
    SuggestedPlayers = questRecord[18].GetUInt32();
    LimitTime = questRecord[19].GetUInt32();
    QuestFlags = questRecord[20].GetUInt32();
    uint32 SpecialFlags = questRecord[21].GetUInt16();
    CharTitleId = questRecord[22].GetUInt32();
    PlayersSlain = questRecord[23].GetUInt32();
    BonusTalents = questRecord[24].GetUInt32();
    RewArenaPoints = questRecord[25].GetInt32();
    RewSkillLineId = questRecord[26].GetInt32();
    RewSkillPoints = questRecord[27].GetInt32();
    RewFactionMask = questRecord[28].GetInt32();
    QuestTurnInPortraitID = questRecord[29].GetInt32();
    QuestGiverPortraitId = questRecord[30].GetInt32();
    PrevQuestId = questRecord[31].GetInt32();
    NextQuestId = questRecord[32].GetInt32();
    ExclusiveGroup = questRecord[33].GetInt32();
    NextQuestInChain = questRecord[34].GetUInt32();
    XPId = questRecord[35].GetUInt32();
    SrcItemId = questRecord[36].GetUInt32();
    SrcItemCount = questRecord[37].GetUInt32();
    SrcSpell = questRecord[38].GetUInt32();
    Title = questRecord[39].GetString();
    Details = questRecord[40].GetString();
    Objectives = questRecord[41].GetString();
    OfferRewardText = questRecord[42].GetString();
    RequestItemsText = questRecord[43].GetString();
    EndText = questRecord[44].GetString();
    CompletedText = questRecord[45].GetString();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ObjectiveText[i] = questRecord[46+i].GetString();

    QuestGiverPortraitText = questRecord[50].GetString();
    QuestGiverPortraitUnk = questRecord[51].GetString();
    QuestTurnInPortraitText = questRecord[52].GetString();
    QuestTurnInPortraitUnk = questRecord[53].GetString();
    CriteriaSpellID = questRecord[54].GetUInt32();

    for (int i = 0; i < QUEST_CURRENCY_OBJECTIVES_COUNT; ++i)
        ReqCurrencyId[i] = questRecord[55+i].GetUInt32();

    for (int i = 0; i < QUEST_CURRENCY_OBJECTIVES_COUNT; ++i)
        ReqCurrencyCount[i] = questRecord[59+i].GetUInt32();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        ReqItemId[i] = questRecord[63+i].GetUInt32();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        ReqItemCount[i] = questRecord[69+i].GetUInt32();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        ReqSourceId[i] = questRecord[75+i].GetUInt32();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        ReqSourceCount[i] = questRecord[79+i].GetUInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqCreatureOrGOId[i] = questRecord[83+i].GetInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqCreatureOrGOCount[i] = questRecord[87+i].GetUInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqSpell[i] = questRecord[91+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewChoiceItemId[i] = questRecord[95+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewChoiceItemCount[i] = questRecord[101+i].GetUInt32();

    for (int i = 0; i < QUEST_CURRENCY_COUNT; ++i)
        RewCurrencyId[i] = questRecord[107+i].GetUInt32();

    for (int i = 0; i < QUEST_CURRENCY_COUNT; ++i)
        RewCurrencyCount[i] = questRecord[111+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        RewItemId[i] = questRecord[115+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        RewItemCount[i] = questRecord[119+i].GetUInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewRepFaction[i] = questRecord[123+i].GetUInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewRepValueId[i] = questRecord[128+i].GetInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewRepValue[i] = questRecord[133+i].GetInt32();

    RewHonorAddition = questRecord[138].GetUInt32();
    RewHonorMultiplier = questRecord[139].GetFloat();
    RewOrReqMoney = questRecord[140].GetInt32();
    RewMoneyMaxLevel = questRecord[141].GetUInt32();
    RewSpell = questRecord[142].GetUInt32();
    RewSpellCast = questRecord[143].GetInt32();
    RewMailTemplateId = questRecord[144].GetUInt32();
    RewMailDelaySecs = questRecord[145].GetUInt32();
    PointMapId = questRecord[146].GetUInt32();
    PointX = questRecord[147].GetFloat();
    PointY = questRecord[148].GetFloat();
    PointOpt = questRecord[149].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmote[i] = questRecord[150+i].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmoteDelay[i] = questRecord[154+i].GetUInt32();

    IncompleteEmote = questRecord[158].GetUInt32();
    CompleteEmote = questRecord[159].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmote[i] = questRecord[160+i].GetInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmoteDelay[i] = questRecord[164+i].GetInt32();

    SoundId = questRecord[168].GetUInt32();
    SoundId2 = questRecord[169].GetUInt32();
    QuestStartScript = questRecord[170].GetUInt32();
    QuestCompleteScript = questRecord[171].GetUInt32();

    QuestFlags |= SpecialFlags << 20;
    if (QuestFlags & QUEST_SPECIAL_FLAGS_AUTO_ACCEPT)
        QuestFlags |= QUEST_FLAGS_AUTO_ACCEPT;

    m_reqitemscount = 0;
    m_reqCreatureOrGOcount = 0;
    m_rewitemscount = 0;
    m_rewchoiceitemscount = 0;

    for (int i = 0; i < QUEST_CURRENCY_OBJECTIVES_COUNT; ++i)
        if (ReqCurrencyId[i])
            ++m_reqCurrencyCount;

    for (int i=0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        if (ReqItemId[i])
            ++m_reqitemscount;

    for (int i=0; i < QUEST_OBJECTIVES_COUNT; ++i)
        if (ReqCreatureOrGOId[i])
            ++m_reqCreatureOrGOcount;

    for (int i = 0; i < QUEST_CURRENCY_COUNT; ++i)
        if (ReqCurrencyId[i])
            ++m_rewCurrencyCount;

    for (int i=0; i < QUEST_REWARDS_COUNT; ++i)
        if (RewItemId[i])
            ++m_rewitemscount;

    for (int i=0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        if (RewChoiceItemId[i])
            ++m_rewchoiceitemscount;
}

uint32 Quest::XPValue(Player *pPlayer) const
{
    if (pPlayer)
    {
        int32 quest_level = (QuestLevel == -1 ? pPlayer->getLevel() : QuestLevel);
        const QuestXPEntry *xpentry = sQuestXPStore.LookupEntry(quest_level);
        if (!xpentry)
            return 0;

        int32 diffFactor = 2 * (quest_level - pPlayer->getLevel()) + 20;
        if (diffFactor < 1)
            diffFactor = 1;
        else if (diffFactor > 10)
            diffFactor = 10;

        uint32 xp = diffFactor * xpentry->Exp[XPId] / 10;
        xp = 5 * ((xp + 2) / 5);

        return xp;
    }

    return 0;
}

int32  Quest::GetRewOrReqMoney() const
{
    if (RewOrReqMoney <= 0)
        return RewOrReqMoney;

    return int32(RewOrReqMoney * sWorld->getRate(RATE_DROP_MONEY));
}

bool Quest::IsAllowedInRaid() const
{
    if (IsRaidQuest())
        return true;

    return sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_RAID);
}

/* 
uint32 Quest::CalculateHonorGain(uint8 level) const
{
    if (level > GT_MAX_LEVEL)
        level = GT_MAX_LEVEL;

    uint32 honor = 0;

    if (GetRewHonorAddition() > 0 || GetRewHonorMultiplier() > 0.0f)
    {
        honor = uint32(getLevel() * GetRewHonorMultiplier() * 0.1000000014901161);
        honor += GetRewHonorAddition();
    }

    return honor;
}*/
