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

#ifndef OPCODE_HANDLER
#define OPCODE_HANDLER

#include "Common.h"

// Note: this include need for be sure have full definition of class WorldSession
//       if this class definition not complite then VS for x64 release use different size for
//       struct OpcodeHandler in this header and Opcode.cpp and get totally wrong data from
//       table opcodeTable in source when Opcode.h included but WorldSession.h not included
#include "WorldSession.h"

enum Opcodes
{
    /**************************************************************************************
    ####################################CLIENT OPCODES#####################################
    **************************************************************************************/

    /***********************************************************/
    /********************* ATTACK OPCODES **********************/
    /***********************************************************/
    CMSG_ATTACKSWING                                    = 0x74A8,    // 29864 - 4.0.6.13623
    CMSG_ATTACKSTOP                                     = 0x62C4,    // 25284 - 4.0.6.13623

    /***********************************************************/
    /******************** AUCTION OPCODES **********************/
    /***********************************************************/
    CMSG_AUCTION_SELL_ITEM                              = 0xEE8C,    // 61068 - 4.0.6.13623
    CMSG_AUCTION_REMOVE_ITEM                            = 0x9F5D,    // 40797 - 4.0.6.13623
    CMSG_AUCTION_LIST_ITEMS                             = 0xE48C,    // 58508 - 4.0.6.13623
    CMSG_AUCTION_LIST_OWNER_ITEMS                       = 0x259,
    CMSG_AUCTION_PLACE_BID                              = 0x8777,    // 34679 - 4.0.6.13623
    CMSG_AUCTION_LIST_BIDDER_ITEMS                      = 0x260,
    CMSG_AUCTION_LIST_PENDING_SALES                     = 0x48F,

    /***********************************************************/
    /***************** AUTHENTICATION OPCODES ******************/
    /***********************************************************/
    CMSG_AUTH_SESSION                                   = 0x186C,    // 6252  - 4.1.0.13812
    CMSG_REALM_SPLIT                                    = 0xE570,    // 58736 - 4.1.0.13812
    CMSG_REDIRECTION_FAILED                             = 0x0509,    // 1289  - 4.0.6.13623
    CMSG_UNKNOWN_1296                                   = 0x510,
    CMSG_REDIRECTION_AUTH_PROOF                         = 0x086C,    // 2156  - 4.1.0.13812

    // SRP6
    CMSG_AUTH_SRP6_BEGIN                                = 0x033,     // 51   - 4.0.6.13623
    CMSG_AUTH_SRP6_PROOF                                = 0x034,     // 52   - 4.0.6.13623
    CMSG_AUTH_SRP6_RECODE                               = 0x035,     // 53   - 4.0.6.13623

    /***********************************************************/
    /******************* BATTLEFIELD OPCODES *******************/
    /***********************************************************/
    CMSG_BATTLEFIELD_LIST                               = 0x0093,    // 147   - 4.0.6.13623
    CMSG_BATTLEFIELD_JOIN                               = 0x23E,
    CMSG_BATTLEFIELD_STATUS                             = 0x2D3,
    CMSG_BATTLEFIELD_PORT                               = 0x2D5,
    CMSG_BATTLEMASTER_HELLO                             = 0x2D7,
    CMSG_LEAVE_BATTLEFIELD                              = 0x2E1,
    CMSG_BATTLEMASTER_JOIN_ARENA                        = 0x358,
    CMSG_BATTLEFIELD_MGR_ENTRY_INVITE_RESPONSE          = 0x4DF,
    CMSG_BATTLEFIELD_MGR_QUEUE_INVITE_RESPONSE          = 0x8108,    // 33032 - 4.0.6.13623
    CMSG_BATTLEFIELD_MGR_QUEUE_REQUEST                  = 0x4E3,
    CMSG_BATTLEFIELD_MGR_EXIT_REQUEST                   = 0x8580,    // 34176 - 4.0.6.13623

    /***********************************************************/
    /******************** CALENDAR OPCODES *********************/
    /***********************************************************/
    CMSG_CALENDAR_GET_CALENDAR                          = 0x429,
    CMSG_CALENDAR_GET_EVENT                             = 0x3580,    // 13696 - 4.0.6.13623
    CMSG_CALENDAR_GUILD_FILTER                          = 0xADAC,    // 44460 - 4.0.6.13623
    CMSG_CALENDAR_ARENA_TEAM                            = 0xE9AC,    // 59820 - 4.0.6.13623
    CMSG_CALENDAR_ADD_EVENT                             = 0xF488,    // 62600 - 4.0.6.13623
    CMSG_CALENDAR_UPDATE_EVENT                          = 0xF084,    // 61572 - 4.0.6.13623
    CMSG_CALENDAR_REMOVE_EVENT                          = 0x6C88,    // 27784 - 4.0.6.13623
    CMSG_CALENDAR_COPY_EVENT                            = 0xBF84,    // 49028 - 4.0.6.13623
    CMSG_CALENDAR_EVENT_INVITE                          = 0xF6C4,    // 63172 - 4.0.6.13623
    CMSG_CALENDAR_EVENT_RSVP                            = 0x757F,    // 30079 - 4.0.6.13623
    CMSG_CALENDAR_EVENT_REMOVE_INVITE                   = 0xEBCC,    // 60364 - 4.0.6.13623
    CMSG_CALENDAR_EVENT_STATUS                          = 0xBC84,    // 48260 - 4.0.6.13623
    CMSG_CALENDAR_EVENT_MODERATOR_STATUS                = 0xBDE4,    // 48612 - 4.0.6.13623
    CMSG_CALENDAR_COMPLAIN                              = 0x1E75,    // 7797  - 4.0.6.13623
    CMSG_CALENDAR_GET_NUM_PENDING                       = 0xEFAC,    // 61356 - 4.0.6.13623
    CMSG_CALENDAR_CONTEXT_EVENT_SIGNUP                  = 0xAEAC,    // 44716 - 4.0.6.13623

    /***********************************************************/
    /******************** CHARACTER OPCODES ********************/
    /***********************************************************/
    CMSG_MOVE_CHARACTER_CHEAT                           = 0x00D,
    CMSG_CHAR_CREATE                                    = 0xB672,    // 46706 - 4.1.0.13812
    CMSG_CHAR_ENUM                                      = 0xD676,    // 54902 - 4.1.0.13812
    CMSG_CHAR_DELETE                                    = 0xC744,    // 51012 - 4.1.0.13812
    CMSG_CHARACTER_POINT_CHEAT                          = 0x223,
    CMSG_CHAR_RENAME                                    = 0x27C4,    // 10180 - 4.0.6.13623
    CMSG_CHAR_CUSTOMIZE                                 = 0x6484,    // 25732 - 4.0.6.13623
    CMSG_CHAR_FACTION_CHANGE                            = 0xBBCC,    // 48076 - 4.0.6.13623
    CMSG_CHAR_RACE_CHANGE                               = 0x6EA4,    // 28324 - 4.0.6.13623

    // Character World Login / Logout
    CMSG_PLAYER_LOGIN                                   = 0x0014,    // 20    - 4.0.6.13623
    CMSG_PLAYER_LOGOUT                                  = 0xF78C,    // 63372 - 4.0.6.13623
    CMSG_LOGOUT_REQUEST                                 = 0xA7A8,    // 42920 - 4.0.6.13623
    CMSG_LOGOUT_CANCEL                                  = 0x04E,

    /***********************************************************/
    /********************** CHAT OPCODES ***********************/
    /***********************************************************/
    CMSG_CHAT_IGNORED                                   = 0xA78C,    // 42892 - 4.0.6.13623
    CMSG_GM_VISION                                      = 0x226,
    CMSG_CHAT_FILTERED                                  = 0x0D5D,    // 3421  - 4.0.3.13329,
    CMSG_GM_WHISPER                                     = 0x3B2,
    CMSG_FORCE_SAY_CHEAT                                = 0x47E,

    // Chat Message
    CMSG_MESSAGECHAT_SAY                                = 0x002A,    // 42    - 4.0.6.13623
    CMSG_MESSAGECHAT_YELL                               = 0x0802,    // 2050  - 4.0.6.13623
    CMSG_MESSAGECHAT_CHANNEL                            = 0x3A88,    // 14984 - 4.0.3.13329
    CMSG_MESSAGECHAT_WHISPER                            = 0x0000,    // 0     - 4.0.6.13623
    CMSG_MESSAGECHAT_GUILD                              = 0x0823,    // 2083  - 4.0.6.13623
    CMSG_MESSAGECHAT_OFFICER                            = 0x0861,    // 2145  - 4.0.6.13623
    CMSG_MESSAGECHAT_AFK                                = 0x086B,    // 2155  - 4.0.6.13623
    CMSG_MESSAGECHAT_DND                                = 0x0003,    // 3     - 4.0.6.13623
    CMSG_MESSAGECHAT_EMOTE                              = 0x0042,    // 66    - 4.0.6.13623
    CMSG_MESSAGECHAT_PARTY                              = 0x2A08,
    CMSG_MESSAGECHAT_PARTY_LEADER                       = 0x6A18,
    CMSG_MESSAGECHAT_RAID                               = 0x7A90,
    CMSG_MESSAGECHAT_RAID_LEADER                        = 0x4A80,
    CMSG_MESSAGECHAT_BATTLEGROUND                       = 0x1A10,
    CMSG_MESSAGECHAT_BATTLEGROUND_LEADER                = 0x7A80,
    CMSG_MESSAGECHAT_RAID_WARNING                       = 0x4A88,

    // Channel
    CMSG_JOIN_CHANNEL                                   = 0x0002,    // 2     - 4.0.6.13623
    CMSG_LEAVE_CHANNEL                                  = 0x000B,    // 11    - 4.0.6.13623
    CMSG_CHANNEL_LIST                                   = 0x0069,    // 105   - 4.0.6.13623
    CMSG_CHANNEL_PASSWORD                               = 0x080A,    // 2058  - 4.0.6.13623
    CMSG_CHANNEL_SET_OWNER                              = 0x0800,    // 2048  - 4.0.6.13623
    CMSG_CHANNEL_OWNER                                  = 0x0848,    // 2120  - 4.0.6.13623
    CMSG_CHANNEL_MODERATOR                              = 0x0828,    // 2088  - 4.0.6.13623
    CMSG_CHANNEL_UNMODERATOR                            = 0x0809,    // 2057  - 4.0.6.13623
    CMSG_CHANNEL_MUTE                                   = 0x0023,    // 35    - 4.0.6.13623
    CMSG_CHANNEL_UNMUTE                                 = 0x0841,    // 2113  - 4.0.6.13623
    CMSG_CHANNEL_INVITE                                 = 0x0020,    // 32    - 4.0.6.13623
    CMSG_CHANNEL_KICK                                   = 0x0068,    // 104   - 4.0.6.13623
    CMSG_CHANNEL_ROSTER_INFO                            = 0x0069,    // 105   - 4.0.6.13623
    CMSG_CHANNEL_BAN                                    = 0x000A,    // 10    - 4.0.6.13623
    CMSG_CHANNEL_UNBAN                                  = 0x0048,    // 72    - 4.0.6.13623
    CMSG_CHANNEL_ANNOUNCEMENTS                          = 0x004B,    // 75    - 4.0.6.13623
    CMSG_CHANNEL_MODERATE                               = 0x0A8,
    CMSG_CHANNEL_SILENCE_VOICE                          = 0x0801,    // 2049  - 4.0.6.13623
    CMSG_CHANNEL_SILENCE_ALL                            = 0x0021,    // 33    - 4.0.6.13623
    CMSG_CHANNEL_UNSILENCE_VOICE                        = 0x002B,    // 43    - 4.0.6.13623
    CMSG_CHANNEL_UNSILENCE_ALL                          = 0x0840,    // 2112  - 4.0.6.13623
    CMSG_CHANNEL_DISPLAY_LIST                           = 0x0009,    // 9     - 4.0.6.13623
    CMSG_GET_CHANNEL_MEMBER_COUNT                       = 0x3D4,
    CMSG_SET_CHANNEL_WATCH                              = 0x7FE0,    // 32736 - 4.0.6.13623
    CMSG_CLEAR_CHANNEL_WATCH                            = 0xA1E0,    // 41440 - 4.0.6.13623
    CMSG_DECLINE_CHANNEL_INVITE                         = 0xE68C,    // 59020 - 4.0.6.13623

    // Char Server Message
    CMSG_SERVER_BROADCAST                               = 0x2B2,
    CMSG_SERVER_INFO_QUERY                              = 0x4A0,

    /***********************************************************/
    /********************* COMBAT OPCODES **********************/
    /***********************************************************/
    CMSG_ENABLE_DAMAGE_LOG                              = 0x27D,

    /***********************************************************/
    /********************** DUEL OPCODES ***********************/
    /***********************************************************/
    CMSG_DUEL_ACCEPTED                                  = 0xA688,    // 42632 - 4.0.6.13623
    CMSG_DUEL_CANCELLED                                 = 0x6F8C,    // 28556 - 4.0.6.13623

    /***********************************************************/
    /******************** FACTION OPCODES **********************/
    /***********************************************************/
    CMSG_SET_FACTION_ATWAR                              = 0x125,
    CMSG_SET_FACTION_CHEAT                              = 0x126,
    CMSG_SET_ACTION_BUTTON                              = 0x72E8,    // 29416 - 4.0.6.13623
    CMSG_RESET_FACTION_CHEAT                            = 0x281,
    CMSG_SET_FACTION_INACTIVE                           = 0x317,
    CMSG_SET_WATCHED_FACTION                            = 0x318,

    /***********************************************************/
    /******************* GAMEMASTER OPCODES ********************/
    /***********************************************************/
    CMSG_GM_INVIS                                       = 0x1E6,
    CMSG_GM_SET_SECURITY_GROUP                          = 0x1F9,
    CMSG_GM_NUKE                                        = 0x1FA,
    CMSG_GM_TEACH                                       = 0x20F,
    CMSG_GM_CREATE_ITEM_TARGET                          = 0x210,
    CMSG_GM_SILENCE                                     = 0x228,
    CMSG_GM_REVEALTO                                    = 0x229,
    CMSG_GM_RESURRECT                                   = 0x22A,
    CMSG_GM_SUMMONMOB                                   = 0x22B,
    CMSG_GM_MOVECORPSE                                  = 0x22C,
    CMSG_GM_FREEZE                                      = 0x22D,
    CMSG_GM_UBERINVIS                                   = 0x22E,
    CMSG_GM_REQUEST_PLAYER_INFO                         = 0x22F,
    CMSG_GM_UNTEACH                                     = 0x2E5,
    CMSG_GM_NUKE_ACCOUNT                                = 0x30F,
    CMSG_GM_DESTROY_ONLINE_CORPSE                       = 0x311,
    CMSG_MAELSTROM_GM_SENT_MAIL                         = 0x395,
    CMSG_GM_SHOW_COMPLAINTS                             = 0x3CA,
    CMSG_GM_UNSQUELCH                                   = 0x3CB,
    CMSG_GM_CHARACTER_RESTORE                           = 0x3FA,
    CMSG_GM_CHARACTER_SAVE                              = 0x3FB,
    CMSG_GMRESPONSE_RESOLVE                             = 0x4F0,
    CMSG_GM_REPORT_LAG                                  = 0x502,

    // Gamemaster Ticket
    CMSG_GMTICKET_CREATE                                = 0x205,
    CMSG_GMTICKET_UPDATETEXT                            = 0x207,
    CMSG_GMTICKET_GETTICKET                             = 0xB4C4,    // 46276 - 4.0.6.13623
    CMSG_GMTICKET_DELETETICKET                          = 0x217,
    CMSG_GMTICKET_SYSTEMSTATUS                          = 0x21A,
    CMSG_GMTICKETSYSTEM_TOGGLE                          = 0x29A,
    CMSG_GM_UPDATE_TICKET_STATUS                        = 0x327,
    CMSG_GMSURVEY_SUBMIT                                = 0x32A,

    /***********************************************************/
    /****************** (GAME)OBJECT OPCODES *******************/
    /***********************************************************/
    CMSG_QUERY_OBJECT_POSITION                          = 0x004,
    CMSG_QUERY_OBJECT_ROTATION                          = 0x006,
    CMSG_CREATEGAMEOBJECT                               = 0x014,
    CMSG_GAMEOBJ_USE                                    = 0x29E4,    // 10724 - 4.0.6.13623
    CMSG_GAMEOBJ_REPORT_USE                             = 0x23A0,    // 9120  - 4.0.6.13623
    CMSG_DUMP_OBJECTS                                   = 0x48B,

    /***********************************************************/
    /********************** GOSSIP OPCODES *********************/
    /***********************************************************/
    CMSG_GOSSIP_HELLO                                   = 0x74C8,    // 29896 - 4.0.6.13623
    CMSG_GOSSIP_SELECT_OPTION                           = 0xFF88,    // 65416 - 4.0.6.13623
    CMSG_NPC_TEXT_QUERY                                 = 0x6664,    // 26212 - 4.1.0.13812
    CMSG_BATTLEMASTER_JOIN                              = 0x2EE,

    // Gossip Questgiver
    CMSG_QUESTGIVER_STATUS_QUERY                        = 0xFDEC,    // 65004 - 4.0.6.13623
    CMSG_QUESTGIVER_HELLO                               = 0x36AC,    // 13996 - 4.0.6.13623
    CMSG_QUESTGIVER_QUERY_QUEST                         = 0x2CC0,    // 11456 - 4.0.6.13623
    CMSG_QUESTGIVER_QUEST_AUTOLAUNCH                    = 0x187,
    CMSG_QUESTGIVER_ACCEPT_QUEST                        = 0x20C4,    // 8388  - 4.0.6.13623
    CMSG_QUESTGIVER_COMPLETE_QUEST                      = 0xB5AC,    // 46508 - 4.0.6.13623
    CMSG_QUESTGIVER_REQUEST_REWARD                      = 0x0E7D,    // 3709  - 4.0.6.13623
    CMSG_QUESTGIVER_CHOOSE_REWARD                       = 0x6AC0,    // 27328 - 4.0.6.13623
    CMSG_QUESTGIVER_CANCEL                              = 0x61EC,    // 25068 - 4.0.6.13623

    // Gossip Trainer
    CMSG_TRAINER_LIST                                   = 0xE5AC,    // 58796 - 4.0.6.13623
    CMSG_TRAINER_BUY_SPELL                              = 0xFDC8,    // 64968 - 4.0.6.13623

    /***********************************************************/
    /********************** GROUP OPCODES **********************/
    /***********************************************************/
    CMSG_GROUP_INVITE                                   = 0x27C0,    // 10176 - 4.0.6.13623
    CMSG_GROUP_CANCEL                                   = 0x070,
    CMSG_GROUP_ACCEPT                                   = 0x368C,    // 13964 - 4.0.6.13623
    CMSG_GROUP_DECLINE                                  = 0xB4CC,    // 46284 - 4.0.6.13623
    CMSG_GROUP_UNINVITE                                 = 0xE3C8,    // 58312 - 4.0.6.13623
    CMSG_GROUP_UNINVITE_GUID                            = 0x076,
    CMSG_GROUP_SET_LEADER                               = 0x078,
    CMSG_GROUP_DISBAND                                  = 0xBE88,    // 48776 - 4.0.6.13623
    CMSG_GROUP_CHANGE_SUB_GROUP                         = 0x27E,
    CMSG_GROUP_SWAP_SUB_GROUP                           = 0x280,
    CMSG_GROUP_RAID_CONVERT                             = 0x28E,
    CMSG_GROUP_ASSISTANT_LEADER                         = 0x28F,

    /***********************************************************/
    /********************** GUILD OPCODES **********************/
    /***********************************************************/
    CMSG_GUILD_CREATE                                   = 0x081,
    CMSG_GUILD_INVITE                                   = 0x2DA8,    // 11688 - 4.0.6.13623
    CMSG_GUILD_ACCEPT                                   = 0x084,
    CMSG_GUILD_DECLINE                                  = 0x085,
    CMSG_GUILD_INFO                                     = 0x6884,    // 26756 - 4.0.6.13623
    CMSG_GUILD_ROSTER                                   = 0xB2A4,    // 45732 - 4.0.6.13623
    CMSG_GUILD_PROMOTE                                  = 0x2109,    // 8457  - 4.0.6.13623
    CMSG_GUILD_DEMOTE                                   = 0x08C,
    CMSG_GUILD_LEAVE                                    = 0x3329,    // 13097 - 4.0.6.13623
    CMSG_GUILD_REMOVE                                   = 0x312D,    // 12589 - 4.0.6.13623
    CMSG_GUILD_DISBAND                                  = 0x08F,
    CMSG_GUILD_LEADER                                   = 0x2650,    // 9808  - 4.0.6.13623
    CMSG_GUILD_MOTD                                     = 0x272D,    // 10029 - 4.0.6.13623
    CMSG_GUILD_RANK                                     = 0x231,
    CMSG_GUILD_ADD_RANK                                 = 0x232,
    CMSG_GUILD_DEL_RANK                                 = 0x233,
    CMSG_GUILD_SET_PUBLIC_NOTE                          = 0x234,
    CMSG_GUILD_SET_OFFICER_NOTE                         = 0x235,
    CMSG_GUILD_INFO_TEXT                                = 0x2FC,
    CMSG_MAELSTROM_RENAME_GUILD                         = 0x400,

    // Guild Bank
    CMSG_GUILD_BANKER_ACTIVATE                          = 0xFFC4,    // 65476 - 4.0.6.13623
    CMSG_GUILD_BANK_QUERY_TAB                           = 0xBBE8,    // 48104 - 4.0.6.13623
    CMSG_GUILD_BANK_SWAP_ITEMS                          = 0xA8C4,    // 43204 - 4.0.6.13623
    CMSG_GUILD_BANK_BUY_TAB                             = 0x3EA,
    CMSG_GUILD_BANK_UPDATE_TAB                          = 0x3EB,
    CMSG_GUILD_BANK_DEPOSIT_MONEY                       = 0x3EC,
    CMSG_GUILD_BANK_WITHDRAW_MONEY                      = 0x3ED,
    CMSG_SET_GUILD_BANK_TEXT                            = 0x40B,

    // Guild Petition
    CMSG_PETITION_SHOWLIST                              = 0xFCC4,    // 64708 - 4.0.6.13623
    CMSG_PETITION_BUY                                   = 0xB3E4,    // 46052 - 4.0.6.13623
    CMSG_PETITION_SHOW_SIGNATURES                       = 0x2CA8,    // 11432 - 4.0.6.13623
    CMSG_PETITION_SIGN                                  = 0x1C0,
    CMSG_OFFER_PETITION                                 = 0x1C3,
    CMSG_TURN_IN_PETITION                               = 0x1C4,
    CMSG_PETITION_QUERY                                 = 0xE470,    // 58480 - 4.1.0.13812

    // Guild Party
    CMSG_REQUEST_PARTY_MEMBER_STATS                     = 0x70C8,    // 28872 - 4.0.6.13623
    CMSG_PARTY_SILENCE                                  = 0x3DD,
    CMSG_PARTY_UNSILENCE                                = 0x3DE,

    /***********************************************************/
    /******************** INSTANCE OPCODES *********************/
    /***********************************************************/
    CMSG_INSTANCE_LOCK_WARNING_RESPONSE                 = 0x13F,
    CMSG_REQUEST_RAID_INFO                              = 0x3DE4,    // 15844 - 4.0.6.13623
    CMSG_EXPIRE_RAID_INSTANCE                           = 0x415,
    CMSG_SET_ALLOW_LOW_LEVEL_RAID1                      = 0x35EC,    // 13804 - 4.0.6.13623
    CMSG_SET_ALLOW_LOW_LEVEL_RAID2                      = 0x29C4,    // 10692 - 4.0.6.13623

    // LFG
    CMSG_LFG_JOIN                                       = 0x35C,
    CMSG_LFG_LEAVE                                      = 0x35D,
    CMSG_SEARCH_LFG_JOIN                                = 0x35E,
    CMSG_SEARCH_LFG_LEAVE                               = 0x35F,
    CMSG_LFG_PROPOSAL_RESULT                            = 0x362,
    CMSG_SET_LFG_COMMENT                                = 0x366,
    CMSG_LFG_SET_ROLES                                  = 0x36A,
    CMSG_LFG_SET_NEEDS                                  = 0x36B,
    CMSG_LFG_SET_BOOT_VOTE                              = 0x36C,
    CMSG_LFD_PLAYER_LOCK_INFO_REQUEST                   = 0xE5E8,    // 58856 - 4.0.6.13623
    CMSG_LFG_TELEPORT                                   = 0x370,
    CMSG_LFD_PARTY_LOCK_INFO_REQUEST                    = 0x371,

    // Meetingstone
    CMSG_MEETINGSTONE_INFO                              = 0xF984,    // 63876 - 4.0.6.13623
    CMSG_MEETINGSTONE_CHEAT                             = 0x294,

    /***********************************************************/
    /********************** ITEM OPCODES ***********************/
    /***********************************************************/
    CMSG_CREATEITEM                                     = 0x013,
    CMSG_USE_ITEM                                       = 0x7080,    // 28800 - 4.0.6.13623
    CMSG_OPEN_ITEM                                      = 0xA2A8,    // 41640 - 4.0.6.13623
    CMSG_READ_ITEM                                      = 0xF3C0,    // 62400 - 4.0.6.13623
    CMSG_DESTROY_ITEMS                                  = 0x0B2,
    CMSG_SWAP_ITEM                                      = 0xE8AC,    // 59564 - 4.0.6.13623
    CMSG_SWAP_INV_ITEM                                  = 0x3EC4,    // 16068 - 4.0.6.13623
    CMSG_SPLIT_ITEM                                     = 0xFDAC,    // 64940 - 4.0.6.13623
    OBSOLETE_DROP_ITEM                                  = 0x110,
    CMSG_DESTROYITEM                                    = 0xB8A8,    // 47272 - 4.0.6.13623
    CMSG_SELL_ITEM                                      = 0x63A4,    // 25508 - 4.0.6.13623
    CMSG_BUY_ITEM                                       = 0xEA84,    // 60036 - 4.0.6.13623
    CMSG_BUY_ITEM_IN_SLOT                               = 0x1A3,
    CMSG_WRAP_ITEM                                      = 0x1D3,  
    CMSG_SET_DURABILITY_CHEAT                           = 0x287,
    CMSG_BUYBACK_ITEM                                   = 0xA4C4,    // 42180 - 4.0.6.13623
    CMSG_REPAIR_ITEM                                    = 0x2A8,
    CMSG_SHOWING_HELM                                   = 0xB7C0,    // 47040 - 4.0.6.13623
    CMSG_SHOWING_CLOAK                                  = 0x7AA4,    // 31396 - 4.0.6.13623
    CMSG_SOCKET_GEMS                                    = 0x347,
    CMSG_CANCEL_TEMP_ENCHANTMENT                        = 0xE484,    // 58500 - 4.0.6.13623
    CMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY                    = 0x39A,
    CMSG_UPDATE_MISSILE_TRAJECTORY                      = 0x462,
    CMSG_ITEM_REFUND_INFO                               = 0x31E0,    // 12768 - 4.0.6.13623
    CMSG_ITEM_REFUND                                    = 0x62E8,    // 25320 - 4.0.6.13623
    CMSG_UPDATE_PROJECTILE_POSITION                     = 0x4BE,

    // Item Equipment
    CMSG_AUTOEQUIP_GROUND_ITEM                          = 0x106,
    CMSG_AUTOSTORE_GROUND_ITEM                          = 0x2FC8,    // 12232 - 4.0.6.13623
    CMSG_AUTOSTORE_LOOT_ITEM                            = 0xB2E8,    // 45800 - 4.0.6.13623
    CMSG_AUTOEQUIP_ITEM                                 = 0xE1C0,    // 57792 - 4.0.6.13623
    CMSG_AUTOSTORE_BAG_ITEM                             = 0xEDCC,    // 60876 - 4.0.6.13623
    CMSG_AUTOEQUIP_ITEM_SLOT                            = 0xE8A8,    // 59560 - 4.0.6.13623
    CMSG_EQUIPMENT_SET_DELETE                           = 0x13E,
    CMSG_AUTOSTORE_BANK_ITEM                            = 0xF2AC,    // 62124 - 4.0.6.13623
    CMSG_AUTOBANK_ITEM                                  = 0x66E4,    // 26340 - 4.0.6.13623
    CMSG_EQUIPMENT_SET_SAVE                             = 0x4BD,
    CMSG_EQUIPMENT_SET_USE                              = 0x4D5,

    // Inventory / Trade
    CMSG_INSPECT                                        = 0x78A8,    // 30888 - 4.0.6.13623
    CMSG_INITIATE_TRADE                                 = 0x0411,    // 1041  - 4.0.6.13623
    CMSG_BEGIN_TRADE                                    = 0x117,
    CMSG_BUSY_TRADE                                     = 0x118,
    CMSG_IGNORE_TRADE                                   = 0x119,
    CMSG_ACCEPT_TRADE                                   = 0x11A,
    CMSG_UNACCEPT_TRADE                                 = 0x0F93,    // 3987  - 4.0.6.13623
    CMSG_CANCEL_TRADE                                   = 0x0013,    // 19    - 4.0.6.13623
    CMSG_SET_TRADE_ITEM                                 = 0x0811,    // 2065  - 4.0.6.13623
    CMSG_CLEAR_TRADE_ITEM                               = 0x11E,
    CMSG_SET_TRADE_GOLD                                 = 0x0793,    // 1939  - 4.0.6.1362
    CMSG_LIST_INVENTORY                                 = 0xEDC8,    // 60872 - 4.0.6.13623

    /***********************************************************/
    /********************** LOOT OPCODES ***********************/
    /***********************************************************/
    CMSG_LOOT_METHOD                                    = 0xFCCC,    // 64716 - 4.0.6.13623
    CMSG_STORE_LOOT_IN_SLOT                             = 0x7FCC,    // 32716 - 4.0.6.13623
    CMSG_LOOT                                           = 0xFCEC,    // 64748 - 4.0.6.13623
    CMSG_LOOT_MONEY                                     = 0x79E0,    // 31200 - 4.0.6.13623
    CMSG_LOOT_RELEASE                                   = 0x3CE8,    // 15592 - 4.0.6.13623
    CMSG_OPT_OUT_OF_LOOT                                = 0x409,

    // Loot Group
    CMSG_LOOT_ROLL                                      = 0xBDA8,    // 48552 - 4.0.6.13623
    CMSG_LOOT_MASTER_GIVE                               = 0x2A3,

    /***********************************************************/
    /******************** MOVEMENT OPCODES *********************/
    /***********************************************************/
    CMSG_MOVE_SET_RAW_POSITION                         = 0xF0C8,    // 61640 - 4.0.6.13623
    CMSG_MOVE_KNOCK_BACK_ACK                           = 0xF580,    // 62848 - 4.0.6.13623
    CMSG_MOVE_HOVER_ACK                                = 0xF4CC,    // 62668 - 4.0.6.13623
    CMSG_MOVE_TIME_SKIPPED                             = 0xE180,    // 57728 - 4.0.6.13623
    CMSG_MOVE_NOT_ACTIVE_MOVER                         = 0xB9A8,    // 47528 - 4.0.6.13623
    CMSG_MINIGAME_MOVE                                 = 0xB2E4,    // 45796 - 4.0.6.13623
    CMSG_MOVE_CHNG_TRANSPORT                           = 0x38D,
    CMSG_UNKNOWN_1303                                  = 0x517,

    // Movement Start / Stop
    CMSG_MOVE_START_SWIM_CHEAT                         = 0x2D8,
    CMSG_MOVE_STOP_SWIM_CHEAT                          = 0x2D9,

    // Movement Force
    CMSG_FORCE_RUN_SPEED_CHANGE_ACK                    = 0x26C8,    // 9928  - 4.0.6.13623
    CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK               = 0x78E4,    // 30948 - 4.0.6.13623
    CMSG_FORCE_SWIM_SPEED_CHANGE_ACK                   = 0xB1A0,    // 45472 - 4.0.6.13623
    CMSG_FORCE_MOVE_ROOT_ACK                           = 0x7184,    // 29060 - 4.0.6.13623
    CMSG_FORCE_MOVE_UNROOT_ACK                         = 0x7FA8,    // 32680 - 4.0.6.13623
    CMSG_FORCE_WALK_SPEED_CHANGE_ACK                   = 0x78CC,    // 30924 - 4.0.6.13623
    CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK              = 0xE8C4,    // 59588 - 4.0.6.13623
    CMSG_FORCE_TURN_RATE_CHANGE_ACK                    = 0xE384,    // 58244 - 4.0.6.13623
    CMSG_FORCE_FLIGHT_SPEED_CHANGE_ACK                 = 0xA98C,    // 43404 - 4.0.6.13623
    CMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK            = 0xFBC8,    // 64456 - 4.0.6.13623
    CMSG_FORCE_PITCH_RATE_CHANGE_ACK                   = 0xE6C0,    // 59072 - 4.0.6.13623
    CMSG_FORCE_UNK1_SPEED_CHANGE_ACK                   = 0xF0C0,    // 61632 - 4.0.6.13623
    CMSG_FORCE_UNK2_SPEED_CHANGE_ACK                   = 0x7DE8,    // 32232 - 4.0.6.13623

    // Movement Teleport / Fall / Fly / Water
    CMSG_MOVE_FALL_RESET                               = 0x2CA,
    CMSG_MOVE_FEATHER_FALL_ACK                         = 0x6EA8,    // 28328 - 4.0.6.13623
    CMSG_MOVE_WATER_WALK_ACK                           = 0x21C4,    // 8644  - 4.0.6.13623
    CMSG_MOVE_FLIGHT_ACK                               = 0xA3C8,    // 41928 - 4.0.6.13623

    // Movement Set / Unset
    CMSG_MOVE_SET_CAN_FLY_ACK                          = 0xFCAC,    // 64684 - 4.0.6.13623
    CMSG_MOVE_SET_FLY                                  = 0xE0E0,    // 57568 - 4.0.6.13623
    CMSG_MOVE_SET_RUN_SPEED                            = 0x3AB,

    // Spline
    CMSG_MOVE_SPLINE_DONE                              = 0x69E8,    // 27112 - 4.0.6.13623

    // Spline Set / Unset

    /***********************************************************/
    /********************* MOVIE OPCODES ***********************/
    /***********************************************************/
    // Cinematic
    CMSG_TRIGGER_CINEMATIC_CHEAT                       = 0x0F8,
    CMSG_OPENING_CINEMATIC                             = 0xB1E8,    // 45544 - 4.0.6.13623
    CMSG_NEXT_CINEMATIC_CAMERA                         = 0xB2CC,    // 45772 - 4.0.6.13623
    CMSG_COMPLETE_CINEMATIC                            = 0x2ACC,    // 10956 - 4.0.6.13623

    // Movie
    CMSG_COMPLETE_MOVIE                                = 0xE188,    // 57736 - 4.0.6.13623

    /***********************************************************/
    /****************** MOUNT / PET OPCODES ********************/
    /***********************************************************/
    CMSG_MOUNTSPECIAL_ANIM                             = 0x2EE4,    // 12004 - 4.0.6.13623
    CMSG_CANCEL_MOUNT_AURA                             = 0x64CC,    // 25804 - 4.0.6.13623

    // Pet
    CMSG_PET_SET_ACTION                                = 0x174,
    CMSG_PET_ACTION                                    = 0xAFC0,    // 44992 - 4.0.6.13623
    CMSG_PET_ABANDON                                   = 0x176,
    CMSG_PET_RENAME                                    = 0x177,
    CMSG_PET_STOP_ATTACK                               = 0x2EA,
    CMSG_PET_UNLEARN                                   = 0x2F0,
    CMSG_PET_LEARN_TALENT                              = 0xA7A0,    // 42912 - 4.0.6.13623
    CMSG_PET_UNLEARN_TALENTS                           = 0x47B,

    /***********************************************************/
    /********************* PLAYER OPCODES **********************/
    /***********************************************************/
    CMSG_UNDRESSPLAYER                                 = 0x020,
    CMSG_GODMODE                                       = 0x022,
    CMSG_PLAYER_DIFFICULTY_CHANGE                      = 0x1FD,
    CMSG_PLAYER_AI_CHEAT                               = 0x26C,
    CMSG_SET_ACTIONBAR_TOGGLES                         = 0x32C4,    // 12996 - 4.0.6.13623
    CMSG_IGNORE_REQUIREMENTS_CHEAT                     = 0x3A8,
    CMSG_SET_PLAYER_DECLINED_NAMES                     = 0xADC0,    // 44480 - 4.0.6.13623

    // Player Achievement
    CMSG_QUERY_INSPECT_ACHIEVEMENTS                    = 0x28EC,    // 10476 - 4.0.6.13623
    CMSG_COMPLETE_ACHIEVEMENT_CHEAT                    = 0x46E,
    CMSG_SET_CRITERIA_CHEAT                            = 0x470,
    CMSG_CHECK_LOGIN_CRITERIA                          = 0x4A2,

    // Player Exploration
    CMSG_SET_EXPLORATION                               = 0x2BE,
    CMSG_SET_EXPLORATION_ALL                           = 0x31B,

    // Friends / Contacts / ...
    CMSG_WHO                                            = 0xA4CC,    // 42188 - 4.0.6.13623
    CMSG_WHOIS                                          = 0x2180,    // 8576  - 4.0.6.13623
    CMSG_CONTACT_LIST                                   = 0xEAA4,    // 60068 - 4.0.6.13623
    CMSG_ADD_FRIEND                                     = 0x3980,    // 14720 - 4.0.6.13623
    CMSG_DEL_FRIEND                                     = 0x2980,    // 10624 - 4.0.6.13623
    CMSG_SET_CONTACT_NOTES                              = 0x7DCC,    // 32204 - 4.0.6.13623
    CMSG_SAVE_PLAYER                                    = 0x153,
    CMSG_REFER_A_FRIEND                                 = 0x40E,

    // Player Dance
    CMSG_PLAY_DANCE                                     = 0x2288,    // 8840  - 4.0.6.13623
    CMSG_STOP_DANCE                                     = 0x3080,    // 12416 - 4.0.6.13623
    CMSG_SYNC_DANCE                                     = 0x450,
    CMSG_DANCE_QUERY                                    = 0x3E40,    // 15936 - 4.1.0.13812

    // Player Level
    CMSG_LEVEL_CHEAT                                    = 0x025,
    CMSG_SET_GRANTABLE_LEVELS                           = 0x40C,
    CMSG_GRANT_LEVEL                                    = 0xB980,    // 47488 - 4.0.6.13623
    CMSG_ACCEPT_LEVEL_GRANT                             = 0xB5CC,    // 46540 - 4.0.6.13623

    // Player Pet
    CMSG_PET_LEVEL_CHEAT                                = 0x026,
    CMSG_STABLE_PET                                     = 0x270,
    CMSG_UNSTABLE_PET                                   = 0x271,
    CMSG_BUY_STABLE_SLOT                                = 0x272,
    CMSG_STABLE_REVIVE_PET                              = 0x274,
    CMSG_STABLE_SWAP_PET                                = 0x275,
    CMSG_REQUEST_PET_INFO                               = 0xEAE4,    // 60132 - 4.0.6.13623

    // Player PVP / Honor / ...
    CMSG_DISABLE_PVP_CHEAT                              = 0x030,
    CMSG_TOGGLE_PVP                                     = 0x6480,    // 25728 - 4.0.6.13623
    CMSG_SET_PVP_RANK_CHEAT                             = 0x288,
    CMSG_ADD_PVP_MEDAL_CHEAT                            = 0x289,
    CMSG_DEL_PVP_MEDAL_CHEAT                            = 0x28A,
    CMSG_SET_PVP_TITLE                                  = 0x28B,
    CMSG_SET_TITLE                                      = 0xEC8C,    // 60556 - 4.0.6.13623
    CMSG_CHEAT_SET_HONOR_CURRENCY                       = 0x37B,
    CMSG_ACTIVE_PVP_CHEAT                               = 0x399,
    CMSG_REPORT_PVP_AFK                                 = 0xE3AC,    // 58284 - 4.0.6.13623
    CMSG_SET_TITLE_SUFFIX                               = 0x3F7,

    // Player Arena
    CMSG_ARENA_TEAM_CREATE                              = 0x348,
    CMSG_ARENA_TEAM_QUERY                               = 0xD466,    // 54374 - 4.1.0.13812
    CMSG_ARENA_TEAM_ROSTER                              = 0x34D,
    CMSG_ARENA_TEAM_INVITE                              = 0xE9CC,    // 59852 - 4.0.6.13623
    CMSG_ARENA_TEAM_ACCEPT                              = 0x61AC,    // 25004 - 4.0.6.13623
    CMSG_ARENA_TEAM_DECLINE                             = 0xF2C0,    // 62144 - 4.0.6.13623
    CMSG_ARENA_TEAM_LEAVE                               = 0x64C4,    // 25796 - 4.0.6.13623
    CMSG_ARENA_TEAM_REMOVE                              = 0x7E84,    // 32388 - 4.0.6.13623
    CMSG_ARENA_TEAM_DISBAND                             = 0x698C,    // 27020 - 4.0.6.13623
    CMSG_ARENA_TEAM_LEADER                              = 0x218C,    // 8588  - 4.0.6.13623
    CMSG_CHEAT_SET_ARENA_CURRENCY                       = 0x37C,
    CMSG_CHANGE_PERSONAL_ARENA_RATING                   = 0x425,

    // Player Tutorial
    CMSG_TUTORIAL_FLAG                                  = 0xE4CC,    // 58572 - 4.0.6.13623
    CMSG_TUTORIAL_CLEAR                                 = 0xA5E4,    // 42468 - 4.0.6.13623
    CMSG_TUTORIAL_RESET                                 = 0xDE75,    // 56949 - 4.0.3.13329

    // Player Emote
    CMSG_EMOTE                                          = 0x7F5C,    // 59872 - 4.0.3.13329
    CMSG_TEXT_EMOTE                                     = 0xE9E0,    // 59872 - 4.0.6.13623

    // Player Corpse / Resurrect / Death
    CMSG_SETDEATHBINDPOINT                              = 0x154,
    CMSG_GETDEATHBINDZONE                               = 0x156,
    CMSG_REPOP_REQUEST                                  = 0xA9E4,    // 43492 - 4.0.6.13623
    CMSG_RESURRECT_RESPONSE                             = 0x15C,
    CMSG_RECLAIM_CORPSE                                 = 0x7CC8,    // 31944 - 4.0.6.13623
    CMSG_GHOST                                          = 0x1E5,
    CMSG_HEARTH_AND_RESURRECT                           = 0x49C,

    // Player Health / Power / Mana / ...
    CMSG_SET_RUNE_COUNT                                 = 0x458,
    CMSG_SET_RUNE_COOLDOWN                              = 0x459,

    // Player Glyph
    CMSG_SET_GLYPH_SLOT                                 = 0x466,
    CMSG_SET_GLYPH                                      = 0x467,
    CMSG_REMOVE_GLYPH                                   = 0x48A,

    // Player Talent / Skill
    CMSG_UNLEARN_TALENTS                                = 0x213,
    CMSG_USE_SKILL_CHEAT                                = 0x029,
    CMSG_SKILL_BUY_STEP                                 = 0x21F,
    CMSG_SKILL_BUY_RANK                                 = 0x220,
    CMSG_LEARN_TALENT                                   = 0xA7CC,    // 42956 - 4.0.6.13623
    CMSG_LEARN_PREVIEW_TALENTS                          = 0xFFAC,    // 65452 - 4.0.6.13623
    CMSG_LEARN_PREVIEW_TALENTS_PET                      = 0xBCE8,    // 48360 - 4.0.6.13623

    // Player Mail
    CMSG_SEND_MAIL                                       = 0x2DEC,    // 11756 - 4.0.6.13623
    CMSG_GET_MAIL_LIST                                   = 0xB284,    // 45700 - 4.0.6.13623
    CMSG_MAIL_TAKE_MONEY                                 = 0xE8EC,    // 59628 - 4.0.6.13623
    CMSG_MAIL_TAKE_ITEM                                  = 0x62A8,    // 25256 - 4.0.6.13623
    CMSG_MAIL_MARK_AS_READ                               = 0xE8C0,    // 59584 - 4.0.6.13623
    CMSG_MAIL_RETURN_TO_SENDER                           = 0x65A4,    // 26020 - 4.0.6.13623
    CMSG_MAIL_DELETE                                     = 0x7DE4,    // 32228 - 4.0.6.13623
    CMSG_MAIL_CREATE_TEXT_ITEM                           = 0xFAE4,    // 64228 - 4.0.6.13623

    // Player Voice
    CMSG_VOICE_SET_TALKER_MUTED_REQUEST                  = 0x3A1,
    CMSG_VOICE_SESSION_ENABLE                            = 0xFEA4,    // 65188 - 4.0.6.13623
    CMSG_SET_ACTIVE_VOICE_CHANNEL                        = 0x32A4,    // 12964 - 4.0.6.13623
    CMSG_CHANNEL_VOICE_ON                                = 0x5A98,
    CMSG_CHANNEL_VOICE_OFF                               = 0x7A88,
    CMSG_DEBUG_LIST_TARGETS                              = 0x3D8,
    CMSG_ADD_VOICE_IGNORE                                = 0x3DB,
    CMSG_DEL_VOICE_IGNORE                                = 0x3DC,

    // Player Totem
    CMSG_TOTEM_DESTROYED                                 = 0x34A0,    // 13472 - 4.0.6.13623

    /***********************************************************/
    /********************* QUERY OPCODES ***********************/
    /***********************************************************/
    CMSG_NAME_QUERY                                      = 0xCE64,    // 52836 - 4.1.0.13812
    CMSG_PET_NAME_QUERY                                  = 0xD776,    // 55158 - 4.1.0.13812
    CMSG_GUILD_QUERY                                     = 0x6D74,    // 28020 - 4.1.0.13812
    CMSG_ITEM_QUERY_SINGLE                               = 0x8588,    // 34184 - 4.0.6.13623
    CMSG_ITEM_QUERY_MULTIPLE                             = 0x0061,    // 97    - 4.0.6.13623
    CMSG_PAGE_TEXT_QUERY                                 = 0xFC42,    // 64578 - 4.1.0.13812
    CMSG_QUEST_QUERY                                     = 0x1F76,    // 8054  - 4.1.0.13812
    CMSG_GAMEOBJECT_QUERY                                = 0xEF72,    // 61298 - 4.1.0.13812
    CMSG_CREATURE_QUERY                                  = 0xC474,    // 50292 - 4.1.0.13812
    CMSG_ITEM_TEXT_QUERY                                 = 0xCF76,    // 53110 - 4.1.0.13812
    CMSG_ITEM_NAME_QUERY                                 = 0x2C4,
    CMSG_CORPSE_MAP_POSITION_QUERY                       = 0x23CC,    // 9164  - 4.0.6.13623

    /***********************************************************/
    /********************* QUEST OPCODES ***********************/
    /***********************************************************/
    CMSG_QUESTLOG_SWAP_QUEST                             = 0x193,
    CMSG_QUESTLOG_REMOVE_QUEST                           = 0xEDA8,    // 60840 - 4.0.6.13623
    CMSG_QUEST_CONFIRM_ACCEPT                            = 0x6FCC,    // 28620 - 4.0.6.13623
    CMSG_PUSHQUESTTOPARTY                                = 0x29E8,    // 10728 - 4.0.6.13623
    CMSG_QUEST_POI_QUERY                                 = 0x7DE0,    // 32224 - 4.0.6.13623
    CMSG_QUERY_QUESTS_COMPLETED                          = 0xECE8,    // 60648 - 4.0.6.13623

    // Questgiver
    CMSG_QUESTGIVER_STATUS_MULTIPLE_QUERY                = 0x2DAC,    // 11692 - 4.0.6.13623

    /***********************************************************/
    /********************* SPELL OPCODES ***********************/
    /***********************************************************/
    CMSG_RECHARGE                                        = 0x00F,
    CMSG_LEARN_SPELL                                     = 0x010,
    CMSG_NEW_SPELL_SLOT                                  = 0x12D,
    CMSG_CAST_SPELL                                      = 0x65C4,    // 26052 - 4.0.6.13623
    CMSG_CANCEL_CAST                                     = 0xA1C0,    // 41408 - 4.0.6.13623
    CMSG_CANCEL_CHANNELLING                              = 0xA780,    // 42880 - 4.0.6.13623
    CMSG_UNLEARN_SPELL                                   = 0x201,
    CMSG_DECHARGE                                        = 0x204,
    CMSG_CANCEL_AUTO_REPEAT_SPELL                        = 0x75CC,    // 30156 - 4.0.6.13623
    CMSG_SUMMON_RESPONSE                                 = 0x6BA0,    // 27552 - 4.0.6.13623
    CMSG_SEND_GENERAL_TRIGGER                            = 0x393,
    CMSG_SEND_COMBAT_TRIGGER                             = 0x394,
    CMSG_TARGET_CAST                                     = 0x3D0,
    CMSG_TARGET_SCRIPT_CAST                              = 0x3D1,
    CMSG_SPELLCLICK                                      = 0x3F8,
    CMSG_NO_SPELL_VARIANCE                               = 0x416,

    // Spell Aura
    CMSG_CANCEL_AURA                                     = 0x7684,    // 30340 - 4.0.6.13623
    CMSG_PET_CANCEL_AURA                                 = 0xF6C0,    // 63168 - 4.0.6.13623
    CMSG_CANCEL_GROWTH_AURA                              = 0xFECC,    // 65228 - 4.0.6.13623

    // Spell Cooldown
    CMSG_COOLDOWN_CHEAT                                  = 0x028,

    // Spell Pet
    CMSG_PET_CAST_SPELL                                  = 0x2888,    // 10376 - 4.0.6.13623
    CMSG_PET_SPELL_AUTOCAST                              = 0xB6A4,    // 46756 - 4.0.6.13623

    /***********************************************************/
    /******************* TRANSPORT OPCODES *********************/
    /***********************************************************/
    // Transport Taxi
    CMSG_TAXICLEARALLNODES                               = 0x1A6,
    CMSG_TAXIENABLEALLNODES                              = 0x1A7,
    CMSG_TAXISHOWNODES                                   = 0x1A8,
    CMSG_TAXINODE_STATUS_QUERY                           = 0xA1EC,    // 41452 - 4.0.6.13623
    CMSG_TAXIQUERYAVAILABLENODES                         = 0xB8E8,    // 47336 - 4.0.6.13623
    CMSG_ACTIVATETAXI                                    = 0x39A4,    // 14756 - 4.0.6.13623
    CMSG_TAXICLEARNODE                                   = 0x241,
    CMSG_TAXIENABLENODE                                  = 0x242,
    CMSG_ACTIVATETAXIEXPRESS                             = 0xFC8C,    // 64652 - 4.0.6.13623
    CMSG_SET_TAXI_BENCHMARK_MODE                         = 0x73C4,    // 29636 - 4.0.6.13623
    CMSG_ENABLETAXI                                      = 0x328C,    // 12940 - 4.0.6.13623

    /***********************************************************/
    /****************** TIME / SPEED OPCODES *******************/
    /***********************************************************/
    // Time
    CMSG_GAMETIME_SET                                    = 0x044,
    CMSG_SERVERTIME                                      = 0x048,
    CMSG_PLAYED_TIME                                     = 0xF480,    // 62592 - 4.0.6.13623
    CMSG_QUERY_TIME                                      = 0xB1C0,    // 45504 - 4.0.6.13623
    CMSG_TIME_SYNC_RESP                                  = 0xA8AC,    // 43180 - 4.0.6.13623
    CMSG_KEEP_ALIVE                                      = 0x506C,    // 20588 - 4.1.0.13812
    CMSG_WORLD_STATE_UI_TIMER_UPDATE                     = 0x3FA8,    // 16296 - 4.0.6.13623
    CMSG_READY_FOR_ACCOUNT_DATA_TIMES                    = 0xE766,    // 59238 - 4.1.0.13812
    // Speed
    CMSG_GAMESPEED_SET                                   = 0x046,

    /***********************************************************/
    /****************** UNCATEGORZIED OPCODES ******************/
    /***********************************************************/
    CMSG_ZONE_MAP                                        = 0x00A,
    CMSG_DEBUG_CHANGECELLZONE                            = 0x00C,
    CMSG_CREATEMONSTER                                   = 0x011,
    CMSG_DESTROYMONSTER                                  = 0x012,
    CMSG_MAKEMONSTERATTACKGUID                           = 0x016,
    CMSG_BOT_DETECTED2                                   = 0x017,
    CMSG_PETGODMODE                                      = 0x01C,
    CMSG_WEATHER_SPEED_CHEAT                             = 0x01F,
    CMSG_BEASTMASTER                                     = 0x021,
    CMSG_CHEAT_SETMONEY                                  = 0x024,
    CMSG_SET_WORLDSTATE                                  = 0x027,
    CMSG_ADVANCE_SPAWN_TIME                              = 0x031,
    CMSG_AREATRIGGER                                     = 0xADA8,    // 44456 - 4.0.6.13623
    CMSG_STANDSTATECHANGE                                = 0xFC88,    // 64648 - 4.0.6.13623
    CMSG_SET_SELECTION                                   = 0x6488,    // 25736 - 4.0.6.13623
    CMSG_UNUSED2                                         = 0x140,
    CMSG_BINDER_ACTIVATE                                 = 0xA48C,    // 42124 - 4.0.6.13623
    CMSG_BANKER_ACTIVATE                                 = 0xE7E0,    // 59360 - 4.0.6.13623
    CMSG_BUY_BANK_SLOT                                   = 0x1B9,
    CMSG_BUG                                             = 0x34AC,    // 13484 - 4.0.6.13623
    CMSG_SET_SKILL_CHEAT                                 = 0x1D8,
    CMSG_PING                                            = 0x064E,    // 1614  - 4.0.6.13623
    CMSG_SETSHEATHED                                     = 0xAAE4,    // 43748 - 4.0.6.13623
    CMSG_ZONEUPDATE                                      = 0x33E4,    // 13284 - 4.0.6.13623
    CMSG_UNLEARN_SKILL                                   = 0x202,
    CMSG_SPIRIT_HEALER_ACTIVATE                          = 0xF3AC,    // 62380 - 4.0.6.13623
    CMSG_SET_STAT_CHEAT                                  = 0x21D,
    CMSG_XP_CHEAT                                        = 0x221,
    CMSG_SERVER_COMMAND                                  = 0x227,
    CMSG_CLEAR_EXPLORATION                               = 0x237,
    CMSG_SET_AMMO                                        = 0x268,
    CMSG_SET_ACTIVE_MOVER                                = 0x6CA0,    // 27808 - 4.0.6.13623
    CMSG_FAR_SIGHT                                       = 0xB2EC,    // 45804 - 4.0.6.13623
    CMSG_SELF_RES                                        = 0xAEC4,    // 44740 - 4.0.6.13623
    CMSG_RUN_SCRIPT                                      = 0x2B5,
    CMSG_AREA_SPIRIT_HEALER_QUERY                        = 0xA6C0,    // 42688 - 4.0.6.13623
    CMSG_AREA_SPIRIT_HEALER_QUEUE                        = 0xF388,    // 62344 - 4.0.6.13623
    CMSG_WARDEN_DATA                                     = 0x2F84,    // 12164 - 4.0.6.13623
    CMSG_DEBUG_ACTIONS_START                             = 0x315,
    CMSG_DEBUG_ACTIONS_STOP                              = 0x316,
    CMSG_LUA_USAGE                                       = 0x323,
    CMSG_IGNORE_KNOCKBACK_CHEAT                          = 0x32C,
    CMSG_MAELSTROM_INVALIDATE_CACHE                      = 0x387,
    CMSG_SEND_LOCAL_EVENT                                = 0x392,
    CMSG_BOT_DETECTED                                    = 0x3C0,
    CMSG_CHEAT_PLAYER_LOGIN                              = 0x3C2,
    CMSG_CHEAT_PLAYER_LOOKUP                             = 0x3C3,
    CMSG_COMPLAIN                                        = 0x68C8,    // 26824 - 4.0.6.13623
    CMSG_GET_MIRRORIMAGE_DATA                            = 0xA08C,    // 41100 - 4.0.6.13623
    CMSG_IGNORE_DIMINISHING_RETURNS_CHEAT                = 0x405,
    CMSG_QUERY_SERVER_BUCK_DATA                          = 0x41B,
    CMSG_CLEAR_SERVER_BUCK_DATA                          = 0x41C,
    CMSG_ALTER_APPEARANCE                                = 0x426,
    CMSG_UNITANIMTIER_CHEAT                              = 0x472,
    CMSG_DISMISS_CRITTER                                 = 0xB7CC,    // 47052 - 4.0.6.13623
    CMSG_FLOOD_GRACE_CHEAT                               = 0x497,

    // Lottery
    CMSG_LOTTERY_QUERY_OBSOLETE                          = 0x334,
    CMSG_BUY_LOTTERY_TICKET_OBSOLETE                     = 0x336,

    // Action
    CMSG_FORCEACTION                                     = 0x018,
    CMSG_FORCEACTIONONOTHER                              = 0x019,
    CMSG_FORCEACTIONSHOW                                 = 0x01A,

    // Event
    CMSG_SEND_EVENT                                      = 0x02D,
    CMSG_DEBUG_AISTATE                                   = 0x02E,

    // Commentator
    CMSG_COMMENTATOR_ENABLE                              = 0x3B5,
    CMSG_COMMENTATOR_GET_MAP_INFO                        = 0x3B7,
    CMSG_COMMENTATOR_GET_PLAYER_INFO                     = 0x3B9,
    CMSG_COMMENTATOR_ENTER_INSTANCE                      = 0x3BC,
    CMSG_COMMENTATOR_EXIT_INSTANCE                       = 0x3BD,
    CMSG_COMMENTATOR_INSTANCE_COMMAND                    = 0x3BE,
    CMSG_COMMENTATOR_SKIRMISH_QUEUE_COMMAND              = 0x51B,

    // Vehicle
    CMSG_DISMISS_CONTROLLED_VEHICLE                      = 0xE3C0,    // 58304 - 4.0.6.13623
    CMSG_REQUEST_VEHICLE_EXIT                            = 0x208C,    // 8332  - 4.0.6.13623
    CMSG_REQUEST_VEHICLE_PREV_SEAT                       = 0x2DE4,    // 11748 - 4.0.6.13623
    CMSG_REQUEST_VEHICLE_NEXT_SEAT                       = 0x64E4,    // 25828 - 4.0.6.13623
    CMSG_REQUEST_VEHICLE_SWITCH_SEAT                     = 0xA8CC,    // 43212 - 4.0.6.13623
    CMSG_CHANGE_SEATS_ON_CONTROLLED_VEHICLE              = 0xE988,    // 59784 - 4.0.6.13623
    CMSG_QUERY_VEHICLE_STATUS                            = 0x4A4,
    CMSG_PLAYER_VEHICLE_ENTER                            = 0x4A8,
    CMSG_EJECT_PASSENGER                                 = 0xF688,    // 63112 - 4.0.6.13623

    /***********************************************************/
    /********************** WORLD OPCODES **********************/
    /***********************************************************/
    // World Teleport
    CMSG_WORLD_TELEPORT                                  = 0x8581,    // 34177 - 4.0.6.13623
    CMSG_WORLD_LOGIN                                     = 0x806D,    // 32877 - 4.1.0.13812
    CMSG_TELEPORT_TO_UNIT                                = 0xE1AC,    // 57772 - 4.0.6.13623
    CMSG_REQUEST_ACCOUNT_DATA                            = 0xEEAC,    // 61100 - 4.0.6.13623
    CMSG_UPDATE_ACCOUNT_DATA                             = 0x72A4,    // 29348 - 4.0.6.13623

    /**************************************************************************************
    #################################CLIENTSERVER OPCODES##################################
    **************************************************************************************/

    /********************************************/
    /************* CHANNEL OPCODES **************/
    /********************************************/
    MSG_CHANNEL_START                    = 0x2BAC,    // 11180 - 4.0.6.13623
    MSG_CHANNEL_UPDATE                   = 0x62AC,    // 25260 - 4.0.6.13623

    /********************************************/
    /************ GAMEMASTER OPCODES ************/
    /********************************************/
    MSG_GM_BIND_OTHER                    = 0x1E8,
    MSG_GM_SUMMON                        = 0x1E9,
    MSG_GM_SHOWLABEL                     = 0x1EF,
    MSG_GM_ACCOUNT_ONLINE                = 0x26E,
    MSG_GM_DESTROY_CORPSE                = 0x310,
    MSG_GM_RESETINSTANCELIMIT            = 0x33C,
    MSG_GM_GEARRATING                    = 0x3B4,
    MSG_GM_CHANGE_ARENA_RATING           = 0x40F,

    /********************************************/
    /************** GUILD OPCODES ***************/
    /********************************************/
    MSG_SAVE_GUILD_EMBLEM                = 0x31AC,    // 12716 - 4.0.6.13623
    MSG_GUILD_BANK_LOG_QUERY             = 0x3EE,
    MSG_GUILD_PERMISSIONS                = 0xF4C4,    // 62660 - 4.0.6.13623
    MSG_GUILD_BANK_MONEY_WITHDRAWN       = 0x6CE4,    // 27876 - 4.0.6a 13529
    MSG_GUILD_EVENT_LOG_QUERY            = 0x69EC,    // 27116 - 4.0.6.13623
    MSG_QUERY_GUILD_BANK_TEXT            = 0x40A,

    /********************************************/
    /************ INSTANCES OPCODES *************/
    /********************************************/
    MSG_BATTLEGROUND_PLAYER_POSITIONS    = 0x2E9,
    MSG_RAID_TARGET_UPDATE               = 0xA5AC,    // 42412 - 4.0.6.13623
    MSG_RAID_READY_CHECK                 = 0xFDC0,    // 64960 - 4.0.6.13623
    MSG_SET_DUNGEON_DIFFICULTY           = 0x74E0,    // 29920 - 4.0.6.13623
    MSG_PARTY_ASSIGNMENT                 = 0x28AC,    // 10412 - 4.0.6.13623
    MSG_RAID_READY_CHECK_CONFIRM         = 0xA2AC,    // 41644 - 4.0.6.13623
    MSG_RAID_READY_CHECK_FINISHED        = 0xA0A0,    // 41120 - 4.0.6.13623
    MSG_NOTIFY_PARTY_SQUELCH             = 0xE8E8,    // 59624 - 4.0.6.13623
    MSG_SET_RAID_DIFFICULTY              = 0xB5E8,    // 46568 - 4.0.6.13623

    /********************************************/
    /************* MOVEMENT OPCODES *************/
    /********************************************/
    // Movement Start
    MSG_MOVE_START_FORWARD               = 0xEBAC,    // 60332 - 4.0.6.13623
    MSG_MOVE_START_BACKWARD              = 0x72E4,    // 29412 - 4.0.6.13623
    MSG_MOVE_START_STRAFE_LEFT           = 0x60E8,    // 24808 - 4.0.6.13623
    MSG_MOVE_START_STRAFE_RIGHT          = 0x7DA4,    // 32164 - 4.0.6.13623
    MSG_MOVE_START_TURN_LEFT             = 0xB8C8,    // 47304 - 4.0.6.13623
    MSG_MOVE_START_TURN_RIGHT            = 0xF9E4,    // 63972 - 4.0.6.13623
    MSG_MOVE_START_PITCH_UP              = 0x60E4,    // 24804 - 4.0.6.13623
    MSG_MOVE_START_PITCH_DOWN            = 0xADC4,    // 44484 - 4.0.6.13623
    MSG_MOVE_START_SWIM                  = 0x26C0,    // 9920  - 4.0.6.13623
    MSG_MOVE_START_SWIM_CHEAT            = 0x26C0,    // 9920  - 4.0.6.13623
    MSG_MOVE_START_ASCEND                = 0xBDC0,    // 48576 - 4.0.6.13623
    MSG_MOVE_START_DESCEND               = 0x7880,    // 30848 - 4.0.6.13623

    // Movement Stop
    MSG_MOVE_STOP                        = 0x34E0,    // 13536 - 4.0.6.13623
    MSG_MOVE_STOP_STRAFE                 = 0xF9A8,    // 63912 - 4.0.6.13623
    MSG_MOVE_STOP_TURN                   = 0xE2E8,    // 58088 - 4.0.6.13623
    MSG_MOVE_STOP_PITCH                  = 0x28E8,    // 10472 - 4.0.6.13623
    MSG_MOVE_STOP_SWIM                   = 0xFDE8,    // 65000 - 4.0.6.13623
    MSG_MOVE_STOP_SWIM_CHEAT             = 0x6988,    // 27016 - 4.0.6.13623
    MSG_MOVE_STOP_ASCEND                 = 0xFCA8,    // 64680 - 4.0.6.13623

    // Movement Toggle
    MSG_MOVE_TOGGLE_LOGGING              = 0x0C4,
    MSG_MOVE_TOGGLE_FALL_LOGGING         = 0x0C8,
    MSG_MOVE_TOGGLE_COLLISION_CHEAT      = 0x0D9,
    MSG_MOVE_TOGGLE_GRAVITY_CHEAT        = 0x2AD,

    // Movement Teleport / Fall / Fly / Water
    MSG_MOVE_TELEPORT                    = 0x24E4,    // 9444  - 4.0.6.13623
    MSG_MOVE_TELEPORT_CHEAT              = 0xE7EC,    // 59372 - 4.0.6.13623
    MSG_MOVE_TELEPORT_ACK                = 0x6DAC,    // 28076 - 4.0.6.13623
    MSG_MOVE_JUMP                        = 0x65AC,    // 26028 - 4.0.6.13623
    MSG_MOVE_FALL_LAND                   = 0xAFAC,    // 44972 - 4.0.6.13623
    MSG_MOVE_WORLDPORT_ACK               = 0x2FC0,    // 12224 - 4.0.6.13623
    MSG_MOVE_FEATHER_FALL                = 0xB6A8,    // 46760 - 4.0.6.13623
    MSG_MOVE_WATER_WALK                  = 0xE1A4,    // 57764 - 4.0.6.13623
    MSG_MOVE_UPDATE_CAN_FLY              = 0x25E0,    // 9696  - 4.0.6.13623

    // Movement Set...
    MSG_MOVE_SET_RUN_MODE                = 0xE7A8,    // 59304 - 4.0.6.13623
    MSG_MOVE_SET_WALK_MODE               = 0x3FAC,    // 16300 - 4.0.6.13623
    MSG_MOVE_SET_RUN_SPEED_CHEAT         = 0x0CC,
    MSG_MOVE_SET_RUN_SPEED               = 0x64A0,    // 25760 - 4.0.6.13623
    MSG_MOVE_SET_RUN_BACK_SPEED_CHEAT    = 0x0CE,
    MSG_MOVE_SET_RUN_BACK_SPEED          = 0xB5EC,    // 46572 - 4.0.6.13623
    MSG_MOVE_SET_WALK_SPEED_CHEAT        = 0x0D0,
    MSG_MOVE_SET_WALK_SPEED              = 0xF284,    // 62084 - 4.0.6.13623
    MSG_MOVE_SET_SWIM_SPEED_CHEAT        = 0x0D2,
    MSG_MOVE_SET_SWIM_SPEED              = 0x2380,    // 9088  - 4.0.6.13623
    MSG_MOVE_SET_SWIM_BACK_SPEED_CHEAT   = 0x0D4,
    MSG_MOVE_SET_SWIM_BACK_SPEED         = 0xB0AC,    // 45228 - 4.0.6.13623
    MSG_MOVE_SET_ALL_SPEED_CHEAT         = 0x0D6,
    MSG_MOVE_SET_TURN_RATE_CHEAT         = 0x0D7,
    MSG_MOVE_SET_TURN_RATE               = 0xA3A8,    // 41896 - 4.0.6.13623
    MSG_MOVE_SET_FACING                  = 0xABC4,    // 43972 - 4.0.6.13623
    MSG_MOVE_SET_PITCH                   = 0xEBA0,    // 60320 - 4.0.6.13623
    MSG_MOVE_SET_RAW_POSITION_ACK        = 0xF4A0,    // 62624 - 4.0.6.13623
    MSG_MOVE_SET_FLIGHT_SPEED_CHEAT      = 0x37D,
    MSG_MOVE_SET_FLIGHT_SPEED            = 0xB088,    // 45192 - 4.0.6.13623
    MSG_MOVE_SET_FLIGHT_BACK_SPEED_CHEAT = 0x37F,
    MSG_MOVE_SET_FLIGHT_BACK_SPEED       = 0xB484,    // 46212 - 4.0.6.13623
    MSG_MOVE_SET_PITCH_RATE_CHEAT        = 0x45A,
    MSG_MOVE_SET_PITCH_RATE              = 0xABA4,    // 43940 - 4.0.6.13623

    // Movement Uncategorized
    MSG_MOVE_ROOT                        = 0xABA8,    // 43944 - 4.0.6.13623
    MSG_MOVE_UNROOT                      = 0x0ED,
    MSG_MOVE_HEARTBEAT                   = 0x22EC,    // 8940  - 4.0.6.13623
    MSG_MOVE_KNOCK_BACK                  = 0xB0E8,    // 45288 - 4.0.6.13623
    MSG_MOVE_HOVER                       = 0x2FCC,    // 12236 - 4.0.6.13623
    MSG_MOVE_TIME_SKIPPED                = 0x25E4,    // 9700  - 4.0.6.13623
    MSG_MOVE_UNKNOWN_1234                = 0x4D2,

    /********************************************/
    /************* PETITION OPCODES *************/
    /********************************************/
    MSG_PETITION_DECLINE                 = 0x32E0,    // 13024 - 4.0.6.13623
    MSG_PETITION_RENAME                  = 0x2C1,

    /********************************************/
    /*********** UNCATEGORIZED OPCODES **********/
    /********************************************/
    MSG_NULL_ACTION                      = 0x000,
    MSG_MINIMAP_PING                     = 0x1D5,
    MSG_TABARDVENDOR_ACTIVATE            = 0x2C80,    // 11392 - 4.0.6.13623
    MSG_RANDOM_ROLL                      = 0xB7A4,    // 47012 - 4.0.6.13623
    MSG_CORPSE_QUERY                     = 0xE0C8,    // 57544 - 4.0.6.13623
    MSG_AUCTION_HELLO                    = 0xB3A0,    // 45984 - 4.0.6.13623
    MSG_LIST_STABLED_PETS                = 0x6EAC,    // 28332 - 4.0.6.13623
    MSG_QUEST_PUSH_RESULT                = 0x22A4,    // 8868  - 4.0.6.13623
    MSG_QUERY_NEXT_MAIL_TIME             = 0x25C8,    // 9672  - 4.0.6.13623
    MSG_TALENT_WIPE_CONFIRM              = 0xBFC4,    // 49092 - 4.0.6.13623
    MSG_DELAY_GHOST_TELEPORT             = 0x32E,

    // PVP / Arena
    MSG_INSPECT_HONOR_STATS              = 0x2D6,
    MSG_PVP_LOG_DATA                     = 0x2E0,
    MSG_INSPECT_ARENA_TEAMS              = 0x377,

    /**************************************************************************************
    ####################################SERVER OPCODES#####################################
    **************************************************************************************/

    /***********************************************************/
    /********************* ATTACK OPCODES **********************/
    /***********************************************************/
    SMSG_ATTACKSTART                                     = 0xB68C,    // 46732 - 4.0.6.13623
    SMSG_ATTACKSTOP                                      = 0x6DCC,    // 28108 - 4.0.6.13623
    SMSG_ATTACKSWING_NOTINRANGE                          = 0x36C4,    // 14020 - 4.0.6.13623
    SMSG_ATTACKSWING_BADFACING                           = 0x67A8,    // 26536 - 4.0.6.13623
    SMSG_ATTACKSWING_DEADTARGET                          = 0xA7C4,    // 42948 - 4.0.6.13623
    SMSG_ATTACKSWING_CANT_ATTACK                         = 0x6188,    // 24968 - 4.0.6.13623
    SMSG_ATTACKERSTATEUPDATE                             = 0xBBC0,    // 48064 - 4.0.6.13623

    /***********************************************************/
    /******************** AUCTION OPCODES **********************/
    /***********************************************************/
    SMSG_AUCTION_COMMAND_RESULT                          = 0x25B,
    SMSG_AUCTION_LIST_RESULT                             = 0x25C,
    SMSG_AUCTION_OWNER_LIST_RESULT                       = 0x25D,
    SMSG_AUCTION_BIDDER_NOTIFICATION                     = 0x25E,
    SMSG_AUCTION_OWNER_NOTIFICATION                      = 0x25F,
    SMSG_AUCTION_BIDDER_LIST_RESULT                      = 0x265,
    SMSG_AUCTION_REMOVED_NOTIFICATION                    = 0x28D,
    SMSG_AUCTION_LIST_PENDING_SALES                      = 0x490,

    /***********************************************************/
    /***************** AUTHENTICATION OPCODES ******************/
    /***********************************************************/
    SMSG_AUTH_SRP6_RESPONSE                              = 0x039,
    SMSG_AUTH_CHALLENGE                                  = 0x06C4,    // 1732  - 4.1.0.13812
    SMSG_AUTH_RESPONSE                                   = 0x5D60,    // 23904 - 4.1.0.13812
    SMSG_REALM_SPLIT                                     = 0x25EC,    // 9708  - 4.0.6.13623
    SMSG_REDIRECT_CLIENT                                 = 0x05C0,    // 1472  - 4.1.0.13812

    /***********************************************************/
    /******************* BATTLEFIELD OPCODES *******************/
    /***********************************************************/
    SMSG_BATTLEFIELD_PORT_DENIED                         = 0x14B,
    SMSG_BATTLEFIELD_MGR_ENTRY_INVITE                    = 0x4DE,
    SMSG_BATTLEFIELD_MGR_ENTERED                         = 0x4E0,
    SMSG_BATTLEFIELD_MGR_QUEUE_INVITE                    = 0x4E1,
    SMSG_BATTLEFIELD_MGR_QUEUE_REQUEST_RESPONSE          = 0x4E4,
    SMSG_BATTLEFIELD_MGR_EJECT_PENDING                   = 0x4E5,
    SMSG_BATTLEFIELD_MGR_EJECTED                         = 0x4E6,
    SMSG_BATTLEFIELD_MGR_STATE_CHANGE                    = 0x4E8,
    SMSG_BATTLEFIELD_LIST                                = 0x23D,
    SMSG_BATTLEFIELD_WIN_OBSOLETE                        = 0x23F,
    SMSG_BATTLEFIELD_LOSE_OBSOLETE                       = 0x240,
    SMSG_BATTLEFIELD_STATUS                              = 0x2D4,

    /***********************************************************/
    /********************* BINDING OPCODES *********************/
    /***********************************************************/
    SMSG_BINDPOINTUPDATE                                 = 0x155,
    SMSG_BINDZONEREPLY                                   = 0xACAC,    // 44204 - 4.0.6.13623
    SMSG_PLAYERBOUND                                     = 0x6BCC,    // 27596 - 4.0.6.13623
    SMSG_PLAYERBINDERROR                                 = 0x1B6,
    SMSG_BINDER_CONFIRM                                  = 0x33C4,    // 13252 - 4.0.6.13623

    /***********************************************************/
    /******************** CALENDAR OPCODES *********************/
    /***********************************************************/
    SMSG_CALENDAR_SEND_CALENDAR                          = 0xB0A4,    // 45220 - 4.0.6.13623
    SMSG_CALENDAR_SEND_EVENT                             = 0xFAA4,    // 64164 - 4.0.6.13623
    SMSG_CALENDAR_FILTER_GUILD                           = 0x2FC4,    // 12228 - 4.0.6.13623
    SMSG_CALENDAR_ARENA_TEAM                             = 0x21E0,    // 8672  - 4.0.6.13623
    SMSG_CALENDAR_EVENT_INVITE                           = 0xA5A0,    // 42400 - 4.0.6.13623
    SMSG_CALENDAR_EVENT_INVITE_REMOVED                   = 0xA9E0,    // 43488 - 4.0.6.13623
    SMSG_CALENDAR_EVENT_STATUS                           = 0x7EC0,    // 32448 - 4.0.6.13623
    SMSG_CALENDAR_COMMAND_RESULT                         = 0xAD80,    // 44416 - 4.0.6.13623
    SMSG_CALENDAR_RAID_LOCKOUT_ADDED                     = 0x2AE0,    // 10976 - 4.0.6.13623
    SMSG_CALENDAR_RAID_LOCKOUT_REMOVED                   = 0xFCE0,    // 64736 - 4.0.6.13623
    SMSG_CALENDAR_EVENT_INVITE_ALERT                     = 0xAFA8,    // 44968 - 4.0.6.13623
    SMSG_CALENDAR_EVENT_INVITE_REMOVED_ALERT             = 0xFEE0,    // 65248 - 4.0.6.13623
    SMSG_CALENDAR_EVENT_INVITE_STATUS_ALERT              = 0xF7C8,    // 63432 - 4.0.6.13623
    SMSG_CALENDAR_EVENT_REMOVED_ALERT                    = 0x6288,    // 25224 - 4.0.6.13623
    SMSG_CALENDAR_EVENT_UPDATED_ALERT                    = 0x29C0,    // 10688 - 4.0.6.13623
    SMSG_CALENDAR_EVENT_MODERATOR_STATUS_ALERT           = 0xABC8,    // 43976 - 4.0.6.13623
    SMSG_CALENDAR_SEND_NUM_PENDING                       = 0xA8E0,    // 43232 - 4.0.6.13623
    SMSG_CALENDAR_UPDATE_INVITE_LIST                     = 0x71A0,    // 29088 - 4.0.6.13623
    SMSG_CALENDAR_UPDATE_INVITE_LIST2                    = 0xEDC4,    // 60868 - 4.0.6.13623
    SMSG_CALENDAR_UPDATE_INVITE_LIST3                    = 0xA2A0,    // 41632 - 4.0.6.13623
    SMSG_CALENDAR_ACTION_PENDING                         = 0x7E8C,    // 32396 - 4.0.6.13623

    /***********************************************************/
    /******************** CHARACTER OPCODES ********************/
    /***********************************************************/
    SMSG_CHAR_CREATE                                     = 0x8444,    // 33860 - 4.1.0.13812
    SMSG_CHAR_ENUM                                       = 0x7D40,    // 32064 - 4.1.0.13812
    SMSG_CHAR_DELETE                                     = 0xBC80,    // 5746  - 4.1.0.13812
    SMSG_CHARACTER_LOGIN_FAILED                          = 0x8D60,    // 36192 - 4.1.0.13812
    SMSG_CHAR_RENAME                                     = 0xE0EC,    // 57580 - 4.0.6.13623
    SMSG_CHAR_CUSTOMIZE                                  = 0x2DA4,    // 11684 - 4.0.6.13623
    SMSG_CHAR_FACTION_CHANGE                             = 0x23AC,    // 9132  - 4.0.6.13623
    SMSG_CHARACTER_PROFILE                               = 0x338,
    SMSG_CHARACTER_PROFILE_REALM_CONNECTED               = 0x339,

    /***********************************************************/
    /********************** CHAT OPCODES ***********************/
    /***********************************************************/
    SMSG_MESSAGECHAT                                     = 0x61E4,    // 25060 - 4.0.6.13623
    SMSG_CHAT_WRONG_FACTION                              = 0x219,
    SMSG_CHAT_PLAYER_NOT_FOUND                           = 0x2A9,
    SMSG_CHAT_RESTRICTED                                 = 0x2FD,
    SMSG_CHAT_PLAYER_AMBIGUOUS                           = 0x32D,
    SMSG_EXPECTED_SPAM_RECORDS                           = 0x6084,    // 24708 - 4.0.6.13623
    SMSG_DEFENSE_MESSAGE                                 = 0x65EC,    // 26092 - 4.0.6.13623
    SMSG_MOTD                                            = 0x77C0,    // 30656 - 4.0.6.13623
    SMSG_SERVER_INFO_RESPONSE                            = 0x4A1,

    // Channel
    SMSG_CHANNEL_NOTIFY                                  = 0x7CAC,    // 31916 - 4.0.6.13623
    SMSG_CHANNEL_LIST                                    = 0x69E0,    // 27104 - 4.0.6.13623
    SMSG_CHANNEL_MEMBER_COUNT                            = 0x2CEC,    // 11500 - 4.0.6.13623
    SMSG_AVAILABLE_VOICE_CHANNEL                         = 0xF8C8,    // 63688 - 4.0.6.13623

    /***********************************************************/
    /********************* COMBAT OPCODES **********************/
    /***********************************************************/
    SMSG_CANCEL_COMBAT                                   = 0xBAE4,   // 47844 - 4.0.6.13623

    // Combat Log
    SMSG_SPELLBREAKLOG                                   = 0xBDAC,    // 48556 - 4.0.6.13623
    SMSG_SPELLHEALLOG                                    = 0x6E84,    // 28292 - 4.0.6.13623
    SMSG_SPELLENERGIZELOG                                = 0xF0EC,    // 61676 - 4.0.6.13623
    SMSG_BREAK_TARGET                                    = 0x2488,    // 9352  - 4.0.6.13623
    SMSG_SPELLLOGMISS                                    = 0x24B,
    SMSG_SPELLLOGEXECUTE                                 = 0x24C,
    SMSG_DEBUGAURAPROC                                   = 0x24D,
    SMSG_PERIODICAURALOG                                 = 0x3388,    // 13192 - 4.0.6.13623
    SMSG_SPELLDAMAGESHIELD                               = 0x73A0,    // 29600 - 4.0.6.13623
    SMSG_SPELLNONMELEEDAMAGELOG                          = 0x74AC,    // 29868 - 4.0.6.13623
    SMSG_SPELLDISPELLOG                                  = 0x27B,
    SMSG_DAMAGE_CALC_LOG                                 = 0xFD84,    // 64900 - 4.0.6.13623
    SMSG_SPELLINSTAKILLLOG                               = 0x61C8,    // 25032 - 4.0.6.13623
    SMSG_SPELLSTEALLOG                                   = 0x333,
    SMSG_SPELL_CHANCE_PROC_LOG                           = 0x3AA,
    SMSG_AURACASTLOG                                     = 0x1D1,
    SMSG_RESISTLOG                                       = 0x1D6,
    SMSG_ENCHANTMENTLOG                                  = 0xF5AC,    // 62892 - 4.0.6.13623
    SMSG_PARTYKILLLOG                                    = 0xAB84,    // 43908 - 4.0.6.13623
    SMSG_ENVIRONMENTALDAMAGELOG                          = 0xE1C8,    // 57800 - 4.0.6.13623

    /***********************************************************/
    /********************** DUEL OPCODES ***********************/
    /***********************************************************/
    SMSG_DUEL_REQUESTED                                  = 0x3FC8,    // 16328 - 4.0.6.13623
    SMSG_DUEL_OUTOFBOUNDS                                = 0x68C0,    // 26816 - 4.0.6.13623
    SMSG_DUEL_INBOUNDS                                   = 0xECA4,    // 60580 - 4.0.6.13623
    SMSG_DUEL_COMPLETE                                   = 0xFCE8,    // 64744 - 4.0.6.13623
    SMSG_DUEL_WINNER                                     = 0x79E4,    // 31204 - 4.0.6.13623
    SMSG_DUEL_COUNTDOWN                                  = 0xE8E0,    // 59616 - 4.0.6.13623

    /***********************************************************/
    /******************** FACTION OPCODES **********************/
    /***********************************************************/
    SMSG_INITIALIZE_FACTIONS                             = 0x25C0,    // 9664  - 4.0.6.13623
    SMSG_SET_FACTION_VISIBLE                             = 0x3988,    // 14728 - 4.0.6.13623
    SMSG_SET_FACTION_STANDING                            = 0x718C,    // 29068 - 4.0.6.13623
    SMSG_SET_FACTION_ATWAR                               = 0x313,

    /***********************************************************/
    /******************* GAMEMASTER OPCODES ********************/
    /***********************************************************/
    SMSG_GM_PLAYER_INFO                                  = 0x230,
    SMSG_GM_MESSAGECHAT                                  = 0x3AEC,    // 15084 - 4.0.6.13623
    SMSG_GMRESPONSE_DB_ERROR                             = 0x4EE,
    SMSG_GMRESPONSE_RECEIVED                             = 0x4EF,
    SMSG_GMRESPONSE_STATUS_UPDATE                        = 0x4F1,

    // Ticket
    SMSG_GMTICKET_CREATE                                 = 0x206,
    SMSG_GMTICKET_UPDATETEXT                             = 0x208,
    SMSG_GMTICKET_GETTICKET                              = 0x2284,    // 8836  - 4.0.6.13623
    SMSG_GMTICKET_SYSTEMSTATUS                           = 0x21B,
    SMSG_GM_TICKET_STATUS_UPDATE                         = 0x328,
    SMSG_GMTICKET_DELETETICKET                           = 0x218,

    /***********************************************************/
    /****************** (GAME)OBJECT OPCODES *******************/
    /***********************************************************/
    SMSG_GAMEOBJECT_CUSTOM_ANIM                          = 0x2E8C,    // 11916 - 4.0.6.13623
    SMSG_GAMEOBJECT_PAGETEXT                             = 0xE5C8,    // 58824 - 4.0.6.13623
    SMSG_GAMEOBJECT_DESPAWN_ANIM                         = 0xBFA8,    // 49064 - 4.0.6.13623
    SMSG_GAMEOBJECT_RESET_STATE                          = 0x22E0,    // 8928  - 4.0.6.13623
    SMSG_DUMP_OBJECTS_DATA                               = 0x48C,

    /***********************************************************/
    /********************** GOSSIP OPCODES *********************/
    /***********************************************************/
    // Gossip General
    SMSG_GOSSIP_MESSAGE                                  = 0xBBC8,    // 48072 - 4.0.6.13623
    SMSG_GOSSIP_COMPLETE                                 = 0xF0AC,    // 61612 - 4.0.6.13623
    SMSG_NPC_TEXT_UPDATE                                 = 0xB2AC,    // 45740 - 4.0.6.13623
    SMSG_NPC_WONT_TALK                                   = 0x181,
    SMSG_GOSSIP_POI                                      = 0xB9AC,    // 47532 - 4.0.6.13623

    // Gossip Questgiver
    SMSG_QUESTGIVER_STATUS                               = 0x7988,    // 31112 - 4.0.6.13623
    SMSG_QUESTGIVER_QUEST_LIST                           = 0x2B88,    // 11144 - 4.0.6.13623
    SMSG_QUESTGIVER_QUEST_DETAILS                        = 0x68A0,    // 26784 - 4.0.6.13623
    SMSG_QUESTGIVER_REQUEST_ITEMS                        = 0x23A8,    // 9128  - 4.0.6.13623
    SMSG_QUESTGIVER_OFFER_REWARD                         = 0x3FCC,    // 16332 - 4.0.6.13623
    SMSG_QUESTGIVER_QUEST_INVALID                        = 0x18F,
    SMSG_QUESTGIVER_QUEST_COMPLETE                       = 0xF5C0,    // 62912 - 4.0.6.13623
    SMSG_QUESTGIVER_QUEST_FAILED                         = 0xA084,    // 41092 - 4.0.6.13623
    SMSG_QUESTGIVER_STATUS_MULTIPLE                      = 0x418,

    /***********************************************************/
    /********************** GROUP OPCODES **********************/
    /***********************************************************/
    SMSG_GROUP_INVITE                                    = 0xA8A8,    // 43176 - 4.0.6.13623
    SMSG_GROUP_CANCEL                                    = 0x6AAC,    // 27308 - 4.0.6.13623
    SMSG_GROUP_DECLINE                                   = 0xABAC,    // 43948 - 4.0.6.13623
    SMSG_GROUP_UNINVITE                                  = 0x3ACC,    // 15052 - 4.0.6.13623
    SMSG_GROUP_SET_LEADER                                = 0xE88C,    // 59532 - 4.0.6.13623
    SMSG_GROUP_DESTROYED                                 = 0x22CC,    // 8908  - 4.0.6.13623
    SMSG_GROUP_LIST                                      = 0x6D8C,    // 28044 - 4.0.6.13623
    SMSG_REAL_GROUP_UPDATE                               = 0x31C0,    // 12736 - 4.0.6.13623
    SMSG_GROUPACTION_THROTTLED                           = 0x411,

    /***********************************************************/
    /********************** GUILD OPCODES **********************/
    /***********************************************************/
    SMSG_GUILD_INVITE                                    = 0xB78C,    // 46988 - 4.0.6.13623
    SMSG_GUILD_DECLINE                                   = 0x7DEC,    // 32236 - 4.0.6.13623
    SMSG_GUILD_INFO                                      = 0x20A8,    // 8360  - 4.0.6.13623
    SMSG_GUILD_ROSTER                                    = 0x08A,
    SMSG_GUILD_EVENT                                     = 0xB7C4,    // 47044 - 4.0.6.13623
    SMSG_GUILD_COMMAND_RESULT                            = 0x23C0,    // 9152  - 4.0.6.13623
    SMSG_GUILD_BANK_LIST                                 = 0x3E8,

    // Party
    SMSG_PARTY_MEMBER_STATS                              = 0x07E,
    SMSG_PARTY_COMMAND_RESULT                            = 0x26E0,    // 9952  - 4.0.6.13623
    SMSG_PARTY_MEMBER_STATS_FULL                         = 0x2F2,
    SMSG_ECHO_PARTY_SQUELCH                              = 0x2AC4,    // 10948 - 4.0.6.13623

    // Petition
    SMSG_BUY_BANK_SLOT_RESULT                            = 0x1BA,
    SMSG_PETITION_SHOWLIST                               = 0x1BC,
    SMSG_PETITION_SHOW_SIGNATURES                        = 0xE2E0,    // 58080 - 4.0.6.13623
    SMSG_PETITION_SIGN_RESULTS                           = 0xA1A4,    // 41380 - 4.0.6.13623
    SMSG_TURN_IN_PETITION_RESULTS                        = 0x1C5,
    SMSG_PETITION_QUERY_RESPONSE                         = 0xFB80,    // 64384 - 4.0.6.13623
    SMSG_OFFER_PETITION_ERROR                            = 0x38F,

    /***********************************************************/
    /******************** INSTANCE OPCODES *********************/
    /***********************************************************/
    SMSG_INSTANCE_LOCK_WARNING_QUERY                     = 0x147,
    SMSG_UPDATE_INSTANCE_ENCOUNTER_UNIT                  = 0xEDA4,    // 60836 - 4.0.6.13623
    SMSG_RAID_GROUP_ONLY                                 = 0x286,
    SMSG_INSTANCE_SAVE_CREATED                           = 0xBBC4,    // 48068 - 4.0.6.13623
    SMSG_RAID_INSTANCE_INFO                              = 0x2CC,
    SMSG_RAID_INSTANCE_MESSAGE                           = 0x6680,    // 26240 - 4.0.6.13623
    SMSG_UPDATE_INSTANCE_OWNERSHIP                       = 0x3B8C,    // 15244 - 4.0.6.13623
    SMSG_INSTANCE_DIFFICULTY                             = 0x33B,
    SMSG_RESET_FAILED_NOTIFY                             = 0x396,
    SMSG_RAID_READY_CHECK_ERROR                          = 0x408,

    // Lfg
    SMSG_LFG_PLAYER_REWARD                               = 0x2C88,    // 11400 - 4.0.6.13623
    SMSG_LFG_TELEPORT_DENIED                             = 0xEAA0,    // 60064 - 4.0.6.13623
    SMSG_LFG_OFFER_CONTINUE                              = 0x63EC,    // 25580 - 4.0.6.13623
    SMSG_LFG_ROLE_CHOSEN                                 = 0xA9AC,    // 43436 - 4.0.6.13623
    SMSG_UPDATE_LFG_LIST                                 = 0x768C,    // 30348 - 4.0.6.13623
    SMSG_LFG_PROPOSAL_UPDATE                             = 0x32AC,    // 12972 - 4.0.6.13623
    SMSG_LFG_ROLE_CHECK_UPDATE                           = 0xF2A8,    // 62120 - 4.0.6.13623
    SMSG_LFG_JOIN_RESULT                                 = 0x338C,    // 13196 - 4.0.6.13623
    SMSG_LFG_QUEUE_STATUS                                = 0xB388,    // 45960 - 4.0.6.13623
    SMSG_LFG_UPDATE_PLAYER                               = 0xE284,    // 57988 - 4.0.6.13623
    SMSG_LFG_UPDATE_PARTY                                = 0x2CE8,    // 11496 - 4.0.6.13623
    SMSG_LFG_UPDATE_SEARCH                               = 0x3880,    // 14464 - 4.0.6.13623
    SMSG_LFG_BOOT_PLAYER                                 = 0x79AC,    // 31148 - 4.0.6.13623
    SMSG_LFG_PLAYER_INFO                                 = 0xE088,    // 57480 - 4.0.6.13623
    SMSG_LFG_PARTY_INFO                                  = 0x60A0,    // 24736 - 4.0.6.13623
    SMSG_LFG_DISABLED                                    = 0xF880,    // 63616 - 4.0.6.13623

    // Meetingstone
    SMSG_MEETINGSTONE_SETQUEUE                           = 0xED88,    // 60808 - 4.0.6.13623
    SMSG_MEETINGSTONE_COMPLETE                           = 0xF680,    // 63104 - 4.0.6.13623
    SMSG_MEETINGSTONE_IN_PROGRESS                        = 0xE7C4,    // 59332 - 4.0.6.13623
    SMSG_MEETINGSTONE_MEMBER_ADDED                       = 0x299,

    // Battleground
    SMSG_GROUP_JOINED_BATTLEGROUND                       = 0x2E8,
    SMSG_BATTLEGROUND_PLAYER_JOINED                      = 0x2EC,
    SMSG_BATTLEGROUND_PLAYER_LEFT                        = 0x2ED,
    SMSG_INSTANCE_RESET                                  = 0x30E8,    // 12520 - 4.0.6.13623
    SMSG_INSTANCE_RESET_FAILED                           = 0x3BA0,    // 15264 - 4.0.6.13623
    SMSG_UPDATE_LAST_INSTANCE                            = 0x33E8,    // 13288 - 4.0.6.13623
    SMSG_JOINED_BATTLEGROUND_QUEUE                       = 0x38A,
    SMSG_BATTLEGROUND_INFO_THROTTLED                     = 0x4A6,

    /***********************************************************/
    /********************** ITEM OPCODES ***********************/
    /***********************************************************/
    SMSG_READ_ITEM_OK                                    = 0xA988,    // 43400 - 4.0.6.13623
    SMSG_READ_ITEM_FAILED                                = 0xA4EC,    // 42220 - 4.0.6.13623
    SMSG_ITEM_COOLDOWN                                   = 0x6CC8,    // 27848 - 4.0.6.13623
    SMSG_ITEM_PUSH_RESULT                                = 0xFBE8,    // 64488 - 4.0.6.13623
    SMSG_ITEM_REFUND_INFO_RESPONSE                       = 0x4B2,
    SMSG_ITEM_REFUND_RESULT                              = 0x4B5,
    SMSG_UPDATE_ITEM_ENCHANTMENTS                        = 0x50B,

    // Inventory / Trade
    SMSG_INVENTORY_CHANGE_FAILURE                        = 0xAFCC,    // 45004 - 4.0.6.13623
    SMSG_OPEN_CONTAINER                                  = 0x113,
    SMSG_INSPECT                                         = 0x7AC8,    // 31432 - 4.0.6.13623
    SMSG_TRADE_STATUS                                    = 0x120,
    SMSG_TRADE_STATUS_EXTENDED                           = 0x121,
    SMSG_LIST_INVENTORY                                  = 0xF8AC,    // 63660 - 4.0.6.13623
    SMSG_EQUIPMENT_SET_LIST                              = 0xF1A8,    // 61864 - 4.0.6.13623

    // Equipment
    SMSG_EQUIPMENT_SET_SAVED                             = 0xB0C0,    // 45248 - 4.0.6.13623
    SMSG_EQUIPMENT_SET_USE_RESULT                        = 0x76AC,    // 30380 - 4.0.6.13623

    // Item Buy / Sell
    SMSG_SELL_ITEM                                       = 0x6CE8,    // 14252 - 4.0.6.13623
    SMSG_BUY_ITEM                                        = 0x69CC,    // 27084 - 4.0.6.13623
    SMSG_BUY_FAILED                                      = 0x6CE8,    // 27880 - 4.0.6.13623 wtf? duplicated opcode?

    /***********************************************************/
    /******************* LOGIN / OUT OPCODES *******************/
    /***********************************************************/
    // Logout
    SMSG_LOGOUT_RESPONSE                                 = 0xF788,    // 63368 - 4.0.6.13623
    SMSG_LOGOUT_COMPLETE                                 = 0x4E74,    // 20084 - 4.1.0.13812
    SMSG_LOGOUT_CANCEL_ACK                               = 0x3454,    // 13396 - 4.1.0.13812

    /***********************************************************/
    /********************** LOOT OPCODES ***********************/
    /***********************************************************/
    SMSG_LOOT_RESPONSE                                   = 0xF38C,    // 62348 - 4.0.6.13623
    SMSG_LOOT_RELEASE_RESPONSE                           = 0x23C8,    // 9160  - 4.0.6.13623
    SMSG_LOOT_REMOVED                                    = 0x6F88,    // 28552 - 4.0.6.13623
    SMSG_LOOT_MONEY_NOTIFY                               = 0x67C0,    // 26560 - 4.0.6.13623
    SMSG_LOOT_ITEM_NOTIFY                                = 0xAECC,    // 44748 - 4.0.6.13623
    SMSG_LOOT_CLEAR_MONEY                                = 0x3480,    // 13440 - 4.0.6.13623
    SMSG_LOOT_LIST                                       = 0xF684,    // 63108 - 4.0.6.13623
    SMSG_LOOT_SLOT_CHANGED                               = 0x31EC,    // 12780 - 4.0.6.13623

    // Loot Group
    SMSG_LOOT_ALL_PASSED                                 = 0x6AC4,    // 27332 - 4.0.6.13623
    SMSG_LOOT_ROLL_WON                                   = 0x6280,    // 25216 - 4.0.6.13623
    SMSG_LOOT_START_ROLL                                 = 0xEB84,    // 60292 - 4.0.6.13623
    SMSG_LOOT_ROLL                                       = 0x66A8,    // 26280 - 4.0.6.13623
    SMSG_LOOT_MASTER_LIST                                = 0xECC4,    // 60612 - 4.0.6.13623
    SMSG_DYNAMIC_DROP_ROLL_RESULT                        = 0x469,

    /***********************************************************/
    /********************** MAIL OPCODES ***********************/
    /***********************************************************/
    SMSG_SEND_MAIL_RESULT                                = 0xE5C0,    // 58816 - 4.0.6.13623
    SMSG_MAIL_LIST_RESULT                                = 0xF1C8,    // 61896 - 4.0.6.13623
    SMSG_RECEIVED_MAIL                                   = 0x75E4,    // 30180 - 4.0.6.13623

    /***********************************************************/
    /******************** MOVEMENT OPCODES *********************/
    /***********************************************************/
    SMSG_MOVE_CHARACTER_CHEAT                            = 0x00E,
    SMSG_MOVE_WATER_WALK                                 = 0x2E84,    // 11908 - 4.0.6.13623
    SMSG_MOVE_LAND_WALK                                  = 0x2084,    // 8324  - 4.0.6.13623
    SMSG_FORCE_SWIM_SPEED_CHANGE                         = 0x0E6,
    SMSG_MOVE_KNOCK_BACK                                 = 0xB0E8,    // 45288 - 4.0.6.13623
    SMSG_COMPRESSED_MOVES                                = 0x5C54,    // 23636 - 4.1.0.13812
    SMSG_MOVE_ABANDON_TRANSPORT                          = 0x45F,
    SMSG_UNKNOWN_1302                                    = 0x516,
    SMSG_UNKNOWN_1304                                    = 0x72E0,    // 29408 - 4.0.6.13623

    // Movement Force
    SMSG_FORCE_RUN_SPEED_CHANGE                          = 0xF1CC,    // 61900 - 4.0.6.13623
    SMSG_FORCE_RUN_BACK_SPEED_CHANGE                     = 0x0E4,
    SMSG_FORCE_MOVE_ROOT                                 = 0x2F88,    // 12168 - 4.0.6.13623
    SMSG_FORCE_MOVE_UNROOT                               = 0x30A0,    // 12448 - 4.0.6.13623
    SMSG_FORCE_WALK_SPEED_CHANGE                         = 0x68E8,    // 26856 - 4.0.6.13623
    SMSG_FORCE_SWIM_BACK_SPEED_CHANGE                    = 0x2DC,
    SMSG_FORCE_TURN_RATE_CHANGE                          = 0x2DE,
    SMSG_FORCE_FLIGHT_SPEED_CHANGE                       = 0x381,
    SMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE                  = 0x383,
    SMSG_FORCE_UNK1_SPEED_CHANGE                         = 0x4CE,
    SMSG_FORCE_UNK2_SPEED_CHANGE                         = 0x4D0,
    SMSG_FORCE_PITCH_RATE_CHANGE                         = 0x45C,

    // Movement Teleport / Fall / Fly / Water
    SMSG_MOVE_FEATHER_FALL                               = 0x0F2,
    SMSG_MOVE_NORMAL_FALL                                = 0x0F3,

    // Movement Set / Unset
    SMSG_MOVE_SET_HOVER                                  = 0x0F4,
    SMSG_MOVE_UNSET_HOVER                                = 0x0F5,
    SMSG_MOVE_SET_FLIGHT                                 = 0x33E,
    SMSG_MOVE_UNSET_FLIGHT                               = 0x33F,
    SMSG_MOVE_SET_CAN_FLY                                = 0x3084,    // 12420 - 4.0.6.13623
    SMSG_MOVE_UNSET_CAN_FLY                              = 0x344,

    // Spline
    SMSG_SPLINE_MOVE_UNROOT                              = 0x304,
    SMSG_SPLINE_MOVE_FEATHER_FALL                        = 0x305,
    SMSG_SPLINE_MOVE_NORMAL_FALL                         = 0x306,
    SMSG_SPLINE_MOVE_SET_HOVER                           = 0x307,
    SMSG_SPLINE_MOVE_UNSET_HOVER                         = 0x308,
    SMSG_SPLINE_MOVE_WATER_WALK                          = 0x61C0,    // 25024 - 4.0.6.13623
    SMSG_SPLINE_MOVE_LAND_WALK                           = 0xA7C8,    // 42952 - 4.0.6.13623
    SMSG_SPLINE_MOVE_START_SWIM                          = 0x30B,
    SMSG_SPLINE_MOVE_STOP_SWIM                           = 0x30C,
    SMSG_SPLINE_MOVE_SET_RUN_MODE                        = 0x30D,
    SMSG_SPLINE_MOVE_SET_WALK_MODE                       = 0x30E,
    SMSG_SPLINE_MOVE_ROOT                                = 0x31A,
    SMSG_SPLINE_MOVE_UNKNOWN_1235                        = 0x4D3,
    SMSG_SPLINE_MOVE_UNKNOWN_1236                        = 0x4D4,
    SMSG_SPLINE_SET_PITCH_RATE                           = 0x70C4,    // 28868 - 4.0.6.13623

    // Spline Set / Unset
    SMSG_SPLINE_SET_RUN_SPEED                            = 0xF9E8,    // 63976 - 4.0.6.13623
    SMSG_SPLINE_SET_RUN_BACK_SPEED                       = 0xE9C0,    // 59840 - 4.0.6.13623
    SMSG_SPLINE_SET_SWIM_SPEED                           = 0xB2C0,    // 45760 - 4.0.6.13623
    SMSG_SPLINE_SET_WALK_SPEED                           = 0x3EA8,    // 16040 - 4.0.6.13623
    SMSG_SPLINE_SET_SWIM_BACK_SPEED                      = 0x21C8,    // 8648  - 4.0.6.13623
    SMSG_SPLINE_SET_TURN_RATE                            = 0x7EAC,    // 32428 - 4.0.6.13623
    SMSG_SPLINE_SET_FLIGHT_SPEED                         = 0xE0C0,    // 57536 - 4.0.6.13623
    SMSG_SPLINE_SET_FLIGHT_BACK_SPEED                    = 0xF2EC,    // 62188 - 4.0.6.13623
    SMSG_SPLINE_MOVE_SET_FLYING                          = 0x422,
    SMSG_SPLINE_MOVE_UNSET_FLYING                        = 0x7688,    // 30344 - 4.0.6.13623
    
    /***********************************************************/
    /********************* MOVIE OPCODES ***********************/
    /***********************************************************/
    // Cinematic
    SMSG_TRIGGER_CINEMATIC                               = 0x73A4,    // 29604 - 4.0.6.13623

    // Movie
    SMSG_TRIGGER_MOVIE                                   = 0x464,

    /***********************************************************/
    /****************** MOUNT / PET OPCODES ********************/
    /***********************************************************/
    // Mount
    SMSG_MOUNTRESULT                                     = 0x16E,
    SMSG_DISMOUNTRESULT                                  = 0x16F,
    SMSG_PUREMOUNT_CANCELLED_OBSOLETE                    = 0x054E,    // 1358  - 4.0.6.13623
    SMSG_MOUNTSPECIAL_ANIM                               = 0x2388,    // 9096  - 4.0.6.13623
    SMSG_DISMOUNT                                        = 0x3CC4,    // 15556 - 4.0.6.13623

    // Pet
    SMSG_PET_TAME_FAILURE                                = 0xFDA8,    // 64936 - 4.0.6.13623
    SMSG_PET_NAME_INVALID                                = 0x178,
    SMSG_PET_SPELLS                                      = 0xB780,    // 46976 - 4.0.6.13623
    SMSG_PET_MODE                                        = 0x79C0,    // 31168 - 4.0.6.13623
    SMSG_PET_UPDATE_COMBO_POINTS                         = 0x7588,    // 30088 - 4.0.6.13623

    /***********************************************************/
    /********************** MULTI OPCODES **********************/
    /***********************************************************/
    SMSG_MULTIPLE_PACKETS                                = 0xFEC0,    // 65216 - 4.0.6.13623

    /***********************************************************/
    /********************* PLAYER OPCODES **********************/
    /***********************************************************/
    SMSG_PLAYER_DIFFICULTY_CHANGE                        = 0x2A80,    // 10880 - 4.0.6.13623
    SMSG_PLAYER_SKINNED                                  = 0xBAA0,    // 47776 - 4.0.6.13623
    SMSG_ADDON_INFO                                      = 0x3F76,    // 16246 - 4.1.0.13812
    SMSG_GHOSTEE_GONE                                    = 0x326,
    SMSG_TITLE_EARNED                                    = 0x6C8C,    // 27788 - 4.0.6.13623
    SMSG_UPDATE_COMBO_POINTS                             = 0x37A8,    // 14248 - 4.0.6.13623
    SMSG_CHEAT_PLAYER_LOOKUP                             = 0x3C4,
    SMSG_KICK_REASON                                     = 0xEAC8,    // 60104 - 4.0.6.13623
    SMSG_SET_PLAYER_DECLINED_NAMES_RESULT                = 0xBAAC,    // 47788 - 4.0.6.13623
    SMSG_HIGHEST_THREAT_UPDATE                           = 0x482,
    SMSG_THREAT_UPDATE                                   = 0xB480,    // 46208 - 4.0.6.13623
    SMSG_THREAT_REMOVE                                   = 0x29E0,    // 10720 - 4.0.6.13623
    SMSG_THREAT_CLEAR                                    = 0xFFC8,    // 65480 - 4.0.6.13623

    // Player Dance
    SMSG_NOTIFY_DANCE                                    = 0x3488,    // 13448 - 4.0.6.13623
    SMSG_PLAY_DANCE                                      = 0xB4EC,    // 46316 - 4.0.6.13623
    SMSG_STOP_DANCE                                      = 0xE0A8,    // 57512 - 4.0.6.13623
    SMSG_DANCE_QUERY_RESPONSE                            = 0x31A8,    // 12712 - 4.0.6.13623
    SMSG_INVALIDATE_DANCE                                = 0xBEE8,    // 48872 - 4.0.6.13623
    SMSG_LEARNED_DANCE_MOVES                             = 0x6F80,    // 28544 - 4.0.6.13623

    // Player Achievement
    SMSG_ACHIEVEMENT_EARNED                              = 0xF5E4,    // 62948 - 4.0.6.13623
    SMSG_CRITERIA_UPDATE                                 = 0xAFC8,    // 45000 - 4.0.6.13623
    SMSG_RESPOND_INSPECT_ACHIEVEMENTS                    = 0x46C,
    SMSG_ALL_ACHIEVEMENT_DATA                            = 0x400E,    // 16398 - 4.0.6.13623
    SMSG_SERVER_FIRST_ACHIEVEMENT                        = 0x68CC,    // 26828 - 4.0.6.13623
    SMSG_CRITERIA_DELETED                                = 0xAF84,    // 44932 - 4.0.6.13623
    SMSG_ACHIEVEMENT_DELETED                             = 0xE6A0,    // 59040 - 4.0.6.13623

    // Player Exploration
    SMSG_EXPLORATION_EXPERIENCE                          = 0xA9C4,    // 43460 - 4.0.6.13623

    // Player Corpse / Resurrect / Death
    SMSG_RESURRECT_REQUEST                               = 0xF3A0,    // 62368 - 4.0.6.13623
    SMSG_RESURRECT_FAILED                                = 0x252,
    SMSG_CORPSE_RECLAIM_DELAY                            = 0x31C4,    // 12740 - 4.0.6.13623
    SMSG_FEIGN_DEATH_RESISTED                            = 0x3BE8,    // 15336 - 4.0.6.13623
    SMSG_DEATH_RELEASE_LOC                               = 0x33C8,    // 13256 - 4.0.6.13623
    SMSG_FORCED_DEATH_UPDATE                             = 0xFFE8,    // 65512 - 4.0.6.13623
    SMSG_PRE_RESURRECT                                   = 0x66C4,    // 26308 - 4.0.6.13623
    SMSG_CORPSE_NOT_IN_INSTANCE                          = 0x506,

    // Player Pet
    SMSG_STABLE_RESULT                                   = 0xEACC,    // 60108 - 4.0.6.13623
    SMSG_SUMMON_REQUEST                                  = 0x3AE4,    // 15076 - 4.0.6.13623
    SMSG_PET_BROKEN                                      = 0x75E0,    // 30176 - 4.0.6.13623
    SMSG_PET_ACTION_FEEDBACK                             = 0x2584,    // 9604  - 4.0.6.13623
    SMSG_PET_UNLEARN_CONFIRM                             = 0x2F1,
    SMSG_PET_RENAMEABLE                                  = 0xB6C8,    // 46792 - 4.0.6.13623
    SMSG_PET_GUIDS                                       = 0xE4E8,    // 58600 - 4.0.6.13623
    SMSG_PET_ACTION_SOUND                                = 0x2472,    // 9330  - 4.1.0.13812
    SMSG_PET_DISMISS_SOUND                               = 0x6656,    // 26198 - 4.1.0.13812

    // Player PVP / Honor / Arena
    SMSG_PVP_CREDIT                                      = 0x37C8,    // 14280 - 4.0.6.13623
    SMSG_ARENA_TEAM_COMMAND_RESULT                       = 0x349,
    SMSG_ARENA_TEAM_QUERY_RESPONSE                       = 0x3DE8,    // 15848 - 4.0.6.13623
    SMSG_ARENA_TEAM_ROSTER                               = 0xB4A8,    // 46248 - 4.0.6.13623
    SMSG_ARENA_TEAM_INVITE                               = 0x63A0,    // 25504 - 4.0.6.13623
    SMSG_ARENA_TEAM_EVENT                                = 0x74C4,    // 29892 - 4.0.6.13623
    SMSG_ARENA_TEAM_STATS                                = 0x35B,
    SMSG_ARENA_ERROR                                     = 0x2FEC,    // 12268 - 4.0.6.13623
    SMSG_REPORT_PVP_AFK_RESULT                           = 0x78E8,    // 30952 - 4.0.6.13623
    SMSG_ARENA_OPPONENT_UPDATE                           = 0x28CC,    // 10444 - 4.0.6.13623
    SMSG_ARENA_TEAM_CHANGE_FAILED_QUEUED                 = 0xBFA0,    // 49056 - 4.0.6.13623

    // Player Currency
    SMSG_INIT_CURRENCY                                   = 0x091C,   // 2332  - 4.0.6.13623
    SMSG_UPDATE_CURRENCY                                 = 0x405E,   // 16478 - 4.0.6.13623
    SMSG_UPDATE_CURRENCY_WEEK_LIMIT                      = 0x4C5C,   // 19548 - 4.0.6.13623

    // Player Minigame
    SMSG_MINIGAME_SETUP                                  = 0x2F6,
    SMSG_MINIGAME_STATE                                  = 0x2F7,
    SMSG_MINIGAME_MOVE_FAILED                            = 0x2F9,

    // Friends / Contacts / ...
    SMSG_USERLIST_ADD                                    = 0xF8CC,    // 63692 - 4.0.6.13623
    SMSG_USERLIST_REMOVE                                 = 0xEF80,    // 61312 - 4.0.6.13623
    SMSG_USERLIST_UPDATE                                 = 0x2C8C,    // 11404 - 4.0.6.13623
    SMSG_REFER_A_FRIEND_FAILURE                          = 0x7FE0,    // 32736 - 4.0.6.13623

    // Talents
    SMSG_INSPECT_TALENT                                  = 0xF8C0,    // 63680 - 4.0.6.13623
    SMSG_TALENTS_INFO                                    = 0x75C4,    // 30148 - 4.0.6.13623
    SMSG_TALENTS_INVOLUNTARILY_RESET                     = 0x6680,    // 26240 - 4.0.6.13623

    // Totem
    SMSG_TOTEM_CREATED                                   = 0x2EAC,    // 11948 - 4.0.6.13623

    // Barber
    SMSG_ENABLE_BARBER_SHOP                              = 0x37E8,    // 14312 - 4.0.6.13623
    SMSG_BARBER_SHOP_RESULT                              = 0x3188,    // 12680 - 4.0.6.13623

    // Player Health / Power / Mana / ...
    SMSG_HEALTH_UPDATE                                   = 0xEF66,    // 61286 - 4.1.0.13812
    SMSG_POWER_UPDATE                                    = 0xAF44,    // 44868 - 4.1.0.13812
    SMSG_CONVERT_RUNE                                    = 0x486,
    SMSG_RESYNC_RUNES                                    = 0x487,
    SMSG_ADD_RUNE_POWER                                  = 0x488,

    // Player Vehicle
    SMSG_PLAYER_VEHICLE_DATA                             = 0xA5A4,    // 42404 - 4.0.6.13623

    /***********************************************************/
    /********************* QUERY OPCODES ***********************/
    /***********************************************************/
    SMSG_NAME_QUERY_RESPONSE                             = 0x7BC8,    // 31688 - 4.0.6.13623
    SMSG_PET_NAME_QUERY_RESPONSE                         = 0x68AC,    // 26796 - 4.0.6.13623
    SMSG_GUILD_QUERY_RESPONSE                            = 0x3F80,    // 16256 - 4.0.6.13623
    SMSG_ITEM_QUERY_SINGLE_RESPONSE                      = 0x0C4E,    // 3150  - 4.0.6.13623
    SMSG_ITEM_QUERY_MULTIPLE_RESPONSE                    = 0x059,
    SMSG_PAGE_TEXT_QUERY_RESPONSE                        = 0xB084,    // 45188 - 4.0.6.13623
    SMSG_QUEST_QUERY_RESPONSE                            = 0x7BA0,    // 31648 - 4.0.6.13623
    SMSG_GAMEOBJECT_QUERY_RESPONSE                       = 0xF4E8,    // 62696 - 4.0.6.13623
    SMSG_CREATURE_QUERY_RESPONSE                         = 0xE6AC,    // 59052 - 4.0.6.13623
    SMSG_ITEM_TEXT_QUERY_RESPONSE                        = 0x77C8,    // 30664 - 4.0.6.13623
    SMSG_ITEM_NAME_QUERY_RESPONSE                        = 0x7BC8,    // 31688 - 4.0.6.13623
    SMSG_QUEST_POI_QUERY_RESPONSE                        = 0x1770,    // 6000  - 4.1.0.13812
    SMSG_CORPSE_MAP_POSITION_QUERY_RESPONSE              = 0x4B7,
    SMSG_QUERY_QUESTS_COMPLETED_RESPONSE                 = 0xF1E8,    // 61928 - 4.0.6.13623

    /***********************************************************/
    /********************* QUEST OPCODES ***********************/
    /***********************************************************/
    SMSG_QUESTLOG_FULL                                   = 0x618C,    // 24972 - 4.0.6.13623
    SMSG_QUEST_FORCE_REMOVED                             = 0xA660,    // 42592 - 4.1.0.13812
    SMSG_QUEST_CONFIRM_ACCEPT                            = 0x7C8C,    // 31884 - 4.0.6.13623

    // Quest Update
    SMSG_QUESTUPDATE_FAILED                              = 0xE588,    // 58760 - 4.0.6.13623
    SMSG_QUESTUPDATE_FAILEDTIMER                         = 0xF7CC,    // 63436 - 4.0.6.13623
    SMSG_QUESTUPDATE_COMPLETE                            = 0xEDA0,    // 60832 - 4.0.6.13623
    SMSG_QUESTUPDATE_ADD_KILL                            = 0xADA0,    // 44448 - 4.0.6.13623
    SMSG_QUESTUPDATE_ADD_ITEM                            = 0x19A,
    SMSG_QUESTUPDATE_ADD_PVP_KILL                        = 0x78E0,    // 30944 - 4.0.6.13623

    /***********************************************************/
    /********************* SPELL OPCODES ***********************/
    /***********************************************************/
    SMSG_INITIAL_SPELLS                                  = 0x6584,    // 25988 - 4.0.6.13623
    SMSG_LEARNED_SPELL                                   = 0x76E8,    // 30440 - 4.0.6.13623
    SMSG_SUPERCEDED_SPELL                                = 0xE8E4,    // 59620 - 4.0.6.13623
    SMSG_CAST_FAILED                                     = 0x2A8C,    // 10892 - 4.0.6.13623
    SMSG_SPELL_START                                     = 0x6BA8,    // 27560 - 4.0.6.13623
    SMSG_SPELL_GO                                        = 0x30C0,    // 12480 - 4.0.6.13623
    SMSG_SPELL_FAILURE                                   = 0xF9CC,    // 63948 - 4.0.6.13623
    SMSG_DAMAGE_DONE_OBSOLETE                            = 0x14C,
    SMSG_UNIT_SPELLCAST_START                            = 0xBDE0,    // 48608 - 4.0.6.13623
    SMSG_SPELL_DELAYED                                   = 0xA3E8,    // 41960 - 4.0.6.13623
    SMSG_PLAY_SPELL_VISUAL                               = 0xFF8C,    // 65420 - 4.0.6.13623
    SMSG_PLAY_SPELL_IMPACT                               = 0xA3E4,    // 41956 - 4.0.6.13623
    SMSG_REMOVED_SPELL                                   = 0x7CA0,    // 31904 - 4.0.6.13623
    SMSG_DISPEL_FAILED                                   = 0xAAE8,    // 43752 - 4.0.6.13623
    SMSG_SPELLORDAMAGE_IMMUNE                            = 0x73C8,    // 29640 - 4.0.6.13623
    SMSG_SET_FLAT_SPELL_MODIFIER                         = 0x2BC8,    // 11208 - 4.0.6.13623
    SMSG_SET_PCT_SPELL_MODIFIER                          = 0xA6E8,    // 42728 - 4.0.6.13623
    SMSG_CANCEL_AUTO_REPEAT                              = 0x0E44,    // 3652  - 4.1.0.13812
    SMSG_SPELL_FAILED_OTHER                              = 0xE7A4,    // 59300 - 4.0.6.13623
    SMSG_SPELL_UPDATE_CHAIN_TARGETS                      = 0x36A4,    // 13988 - 4.0.6.13623
    SMSG_SPELL_CHANCE_RESIST_PUSHBACK                    = 0x404,
    SMSG_SUMMON_CANCEL                                   = 0x70A8,    // 28840 - 4.0.6.13623
    SMSG_NOTIFY_DEST_LOC_SPELL_CAST                      = 0x3588,    // 13704 - 4.0.6.13623
    SMSG_CAMERA_SHAKE                                    = 0x50A,

    // Cooldown
    SMSG_SPELL_COOLDOWN                                  = 0xF3E8,    // 62440 - 4.0.6.13623
    SMSG_COOLDOWN_EVENT                                  = 0xEAEC,    // 60140 - 4.0.6.13623
    SMSG_CLEAR_COOLDOWN                                  = 0x36CC,    // 14028 - 4.0.6.13623
    SMSG_COOLDOWN_CHEAT                                  = 0xAAA4,    // 43684 - 4.0.6.13623
    SMSG_MODIFY_COOLDOWN                                 = 0x30CC,    // 12492 - 4.0.6.13623

    // Pet
    SMSG_PET_CAST_FAILED                                 = 0xA9CC,    // 43468 - 4.0.6.13623
    SMSG_PET_LEARNED_SPELL                               = 0xB3C4,    // 46020 - 4.0.6.13623
    SMSG_PET_REMOVED_SPELL                               = 0xF28C,    // 62092 - 4.0.6.13623

    // Trainer
    SMSG_TRAINER_LIST                                    = 0xBBE0,    // 48096 - 4.0.6.13623
    SMSG_TRAINER_BUY_SUCCEEDED                           = 0x1B3,
    SMSG_TRAINER_BUY_FAILED                              = 0x6DEC,    // 28140 - 4.0.6.13623
    SMSG_SEND_UNLEARN_SPELLS                             = 0xBDE8,    // 48616 - 4.0.6.13623

    // Auras
    SMSG_INIT_EXTRA_AURA_INFO_OBSOLETE                   = 0x3A3,
    SMSG_SET_EXTRA_AURA_INFO_OBSOLETE                    = 0x3A4,
    SMSG_SET_EXTRA_AURA_INFO_NEED_UPDATE_OBSOLETE        = 0x3A5,
    SMSG_CLEAR_EXTRA_AURA_INFO_OBSOLETE                  = 0x3A6,
    SMSG_AURA_UPDATE_ALL                                 = 0x37E0,    // 14304 - 4.0.6.13623
    SMSG_AURA_UPDATE                                     = 0x65C0,    // 26048 - 4.0.6.13623
    SMSG_ON_CANCEL_EXPECTED_RIDE_VEHICLE_AURA            = 0x3380,    // 13184 - 4.0.6.13623

    /***********************************************************/
    /******************* TRANSPORT OPCODES *********************/
    /***********************************************************/
    // Transport Taxi
    SMSG_SHOWTAXINODES                                   = 0x1A9,
    SMSG_TAXINODE_STATUS                                 = 0x1AB,
    SMSG_ACTIVATETAXIREPLY                               = 0x1AE,
    SMSG_NEW_TAXI_PATH                                   = 0x1AF,
    SMSG_MONSTER_MOVE_TRANSPORT                          = 0x248C,    // 9356  - 4.0.6.13623

    /***********************************************************/
    /****************** TIME / SPEED OPCODES *******************/
    /***********************************************************/
    // Time
    SMSG_LOGIN_SETTIMESPEED                              = 0x39AC,    // 14764 - 4.0.6.13623
    SMSG_GAMETIME_UPDATE                                 = 0xF1EC,    // 61932 - 4.0.6.13623
    SMSG_GAMETIME_SET                                    = 0x045,
    SMSG_SERVERTIME                                      = 0x23A4,    // 9124  - 4.0.6.13623
    SMSG_PLAYED_TIME                                     = 0xE4C8,    // 58568 - 4.0.6.13623
    SMSG_QUERY_TIME_RESPONSE                             = 0xF1AC,    // 61868 - 4.0.6.13623
    SMSG_TIME_SYNC_REQ                                   = 0xAA80,    // 43648 - 4.0.6.13623
    SMSG_ITEM_TIME_UPDATE                                = 0x26A4,    // 3677  - 4.0.6.13623
    SMSG_ITEM_ENCHANT_TIME_UPDATE                        = 0x3B80,    // 14164 - 4.0.6a 13329
    SMSG_ACCOUNT_DATA_TIMES                              = 0x7280,    // 29312 - 4.0.6.13623
    SMSG_PLAY_TIME_WARNING                               = 0x32EC,    // 13036 - 4.0.6.13623
    SMSG_GAMETIMEBIAS_SET                                = 0x314,

    // Speed
    SMSG_GAMESPEED_SET                                   = 0x3EC0,    // 16064 - 4.0.6.13623

    /***********************************************************/
    /****************** UNCATEGORZIED OPCODES ******************/
    /***********************************************************/
    SMSG_QUERY_OBJECT_POSITION                           = 0x005,
    SMSG_QUERY_OBJECT_ROTATION                           = 0x007,
    SMSG_ZONE_MAP                                        = 0x00B,
    SMSG_CHECK_FOR_BOTS                                  = 0x015,
    SMSG_FORCEACTIONSHOW                                 = 0x01B,
    SMSG_PETGODMODE                                      = 0x01D,
    SMSG_REFER_A_FRIEND_EXPIRED                          = 0x01E,
    SMSG_GODMODE                                         = 0x023,
    SMSG_DEBUG_AISTATE                                   = 0x02F,
    SMSG_DESTRUCTIBLE_BUILDING_DAMAGE                    = 0xA0E0,    // 41184 - 4.0.6.13623
    SMSG_TRANSFER_PENDING                                = 0x7BE0,    // 31712 - 4.0.6.13623
    SMSG_TRANSFER_ABORTED                                = 0x2BE0,    // 11232 - 4.0.6.13623
    SMSG_WHO                                             = 0xBE8C,    // 48780 - 4.0.6.13623
    SMSG_WHOIS                                           = 0xB1A4,    // 45476 - 4.0.6.13623
    SMSG_CONTACT_LIST                                    = 0x748C,    // 29836 - 4.0.6.13623
    SMSG_FRIEND_STATUS                                   = 0xF68C,    // 63116 - 4.0.6.13623
    SMSG_MONSTER_MOVE                                    = 0xF1A4,    // 61860 - 4.0.6.13623
    SMSG_TUTORIAL_FLAGS                                  = 0x3384,    // 13188 - 4.0.6.13623
    SMSG_EMOTE                                           = 0xEEA0,    // 61088 - 4.0.6.13623
    SMSG_TEXT_EMOTE                                      = 0xBB8C,    // 48012 - 4.0.6.13623
    SMSG_SET_PROFICIENCY                                 = 0xBBA8,    // 48040 - 4.0.6.13623
    SMSG_ACTION_BUTTONS                                  = 0x2CCC,    // 11468 - 4.0.6.13623
    SMSG_AI_REACTION                                     = 0xDE52,    // 56914 - 4.1.0.13812
    SMSG_CLIENT_CONTROL_UPDATE                           = 0x3C84,    // 15492 - 4.0.6.13623
    SMSG_FLIGHT_SPLINE_SYNC                              = 0xC664,    // 50788 - 4.1.0.13812
    SMSG_SHOW_BANK                                       = 0x1B8,
    SMSG_NOTIFICATION                                    = 0xBC88,    // 48264 - 4.0.6.13623
    SMSG_LOG_XPGAIN                                      = 0xB880,    // 47232 - 4.0.6.13623
    SMSG_LEVELUP_INFO                                    = 0xB9C4,    // 47556 - 4.0.6.13623
    SMSG_START_MIRROR_TIMER                              = 0xA68C,    // 42636 - 4.0.6.13623
    SMSG_PAUSE_MIRROR_TIMER                              = 0x21EC,    // 8684  - 4.0.6.13623
    SMSG_STOP_MIRROR_TIMER                               = 0xB4A8,    // 46248 - 4.0.6.13623
    SMSG_PONG                                            = 0xA01B,    // 40987 - 4.0.6.13623
    SMSG_INVALID_PROMOTION_CODE                          = 0x1E7,
    SMSG_RWHOIS                                          = 0x1FE,
    SMSG_UPDATE_ACCOUNT_DATA                             = 0xF7A0,    // 63392 - 4.0.6.13623
    SMSG_CLEAR_FAR_SIGHT_IMMEDIATE                       = 0xBEE4,    // 48868 - 4.0.6.13623
    SMSG_SPIRIT_HEALER_CONFIRM                           = 0x7C8C,    // 31884 - 4.0.6.13623
    SMSG_ZONE_UNDER_ATTACK                               = 0xBD80,    // 48512 - 4.0.6.13623
    SMSG_PROCRESIST                                      = 0x7E80,    // 32384 - 4.0.6.13623
    SMSG_STANDSTATE_CHANGE_FAILURE_OBSOLETE              = 0x6DCC,    // 28108 - 4.0.6.13623
    SMSG_PLAY_MUSIC                                      = 0xACEC,    // 44628 - 4.0.6.13623
    SMSG_PLAY_OBJECT_SOUND                               = 0x7DA0,    // 32160 - 4.0.6.13623
    SMSG_SERVER_MESSAGE                                  = 0x78C0,    // 30912 - 4.0.6.13623
    SMSG_STANDSTATE_UPDATE                               = 0x29D,
    SMSG_SET_FORCED_REACTIONS                            = 0x2A5,
    SMSG_SCRIPT_MESSAGE                                  = 0x2B6,
    SMSG_AREA_TRIGGER_MESSAGE                            = 0xE4AC,    // 58540 - 4.0.6.13623
    SMSG_DURABILITY_DAMAGE_DEATH                         = 0x2BD,
    SMSG_PLAY_SOUND                                      = 0x2EA8,    // 11944 - 4.0.6.13623
    SMSG_AREA_SPIRIT_HEALER_TIME                         = 0x2E4,
    SMSG_WARDEN_DATA                                     = 0xF8A0,    // 63648 - 4.0.6.13623
    SMSG_INVALIDATE_PLAYER                               = 0xA884,    // 43140 - 4.0.6.13623
    SMSG_LOTTERY_QUERY_RESULT_OBSOLETE                   = 0x335,
    SMSG_LOTTERY_RESULT_OBSOLETE                         = 0x337,
    SMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY_RESPONSE            = 0x39B,
    SMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY_RESPONSE_WRITE_FILE = 0x39C,
    SMSG_IGNORE_REQUIREMENTS_CHEAT                       = 0x7C84,    // 31876 - 4.0.6.13623
    SMSG_CLEAR_TARGET                                    = 0xA7AC,    // 42924 - 4.0.6.13623
    SMSG_CROSSED_INEBRIATION_THRESHOLD                   = 0xA580,    // 42368 - 4.0.6.13623
    SMSG_COMPLAIN_RESULT                                 = 0x70CC,    // 28876 - 4.0.6.13623
    SMSG_FEATURE_SYSTEM_STATUS                           = 0x3DAC,    // 15788 - 4.0.6.13623
    SMSG_DEBUG_LIST_TARGETS                              = 0x3D9,
    SMSG_GOGOGO_OBSOLETE                                 = 0x3F5,
    SMSG_MIRRORIMAGE_DATA                                = 0x7E50,    // 32336 - 4.1.0.13812
    SMSG_FORCE_DISPLAY_UPDATE                            = 0x9462,    // 37986 - 4.1.0.13812
    SMSG_IGNORE_DIMINISHING_RETURNS_CHEAT                = 0x78E8,    // 30952 - 4.0.6.13623
    SMSG_OVERRIDE_LIGHT                                  = 0x2388,    // 9096  - 4.0.6.13623
    SMSG_SERVER_BUCK_DATA                                = 0x41D,
    SMSG_PROPOSE_LEVEL_GRANT                             = 0x41F,
    SMSG_UPDATE_ACCOUNT_DATA_COMPLETE                    = 0xB1CC,    // 45516 - 4.0.6.13623
    SMSG_SERVER_BUCK_DATA_START                          = 0x4A3,
    SMSG_CLIENTCACHE_VERSION                             = 0x8C50,    // 35920 - 4.1.0.13812
    SMSG_SET_PROJECTILE_POSITION                         = 0x2C84,    // 11396 - 4.0.6.13623
    SMSG_UNKNOWN_1240                                    = 0xB2C8,    // 45768 - 4.0.6.13623
    SMSG_TOGGLE_XP_GAIN                                  = 0x4ED,
    SMSG_UNKNOWN_1276                                    = 0x4FC,
    SMSG_UNKNOWN_1295                                    = 0x50F,
    SMSG_FORCE_SEND_QUEUED_PACKETS                       = 0x2880,    // 10368 - 4.0.6.13623
    SMSG_UNKNOWN_1300                                    = 0x514,
    SMSG_UNKNOWN_1301                                    = 0x515,
    SMSG_UNKNOWN_1310                                    = 0xA2A8,    // 41640 - 4.0.6.13623

    // Fishing
    SMSG_FISH_NOT_HOOKED                                 = 0x516,
    SMSG_FISH_ESCAPED                                    = 0x517,

    // Voice
    SMSG_VOICE_SESSION_ROSTER_UPDATE                     = 0xACC0,    // 44224 - 4.0.6.13623
    SMSG_VOICE_SESSION_LEAVE                             = 0x78A4,    // 30884 - 4.0.6.13623
    SMSG_VOICE_SESSION_ADJUST_PRIORITY                   = 0x3A0,
    SMSG_VOICE_SET_TALKER_MUTED                          = 0xE3E4,    // 58340 - 4.0.6.13623
    SMSG_VOICE_SESSION_ENABLE                            = 0x3B0,
    SMSG_VOICE_PARENTAL_CONTROLS                         = 0x71E8,    // 29160 - 4.0.6.13623
    SMSG_VOICE_CHAT_STATUS                               = 0x6B88,    // 27528 - 4.0.6.13623
    SMSG_VOICESESSION_FULL                               = 0xB088,    // 45192 - 4.0.6a 13329

    // Commentator
    SMSG_COMMENTATOR_STATE_CHANGED                       = 0xE0E4,    // 57572 - 4.0.6.13623
    SMSG_COMMENTATOR_MAP_INFO                            = 0xA4E8,    // 42216 - 4.0.6.13623
    SMSG_COMMENTATOR_GET_PLAYER_INFO                     = 0x758C,    // 30092 - 4.0.6.13623
    SMSG_COMMENTATOR_PLAYER_INFO                         = 0x3BB,
    SMSG_UNKNOWN_1308                                    = 0x61CC,    // 25036 - 4.0.6.13623
    SMSG_UNKNOWN_1309                                    = 0x51D,

    // Comsat
    SMSG_COMSAT_RECONNECT_TRY                            = 0x51F,
    SMSG_COMSAT_DISCONNECT                               = 0x52D,
    SMSG_COMSAT_CONNECT_FAIL                             = 0x53D,

    /***********************************************************/
    /********************** WORLD OPCODES **********************/
    /***********************************************************/
    SMSG_NEW_WORLD                                       = 0xBE0A,    // 48650 - 4.1.0.13812
    SMSG_UPDATE_OBJECT                                   = 0xD646,    // 54854 - 4.1.0.13812
    SMSG_DESTROY_OBJECT                                  = 0x5462,    // 21602 - 4.1.0.13812
    SMSG_COMPRESSED_UPDATE_OBJECT                        = 0x5E70,    // 24176 - 4.1.0.13812
    SMSG_LOGIN_VERIFY_WORLD                              = 0x1762,    // 5986  - 4.1.0.13812
    SMSG_INIT_WORLD_STATES                               = 0xF6E8,    // 63208 - 4.0.6.13623
    SMSG_UPDATE_WORLD_STATE                              = 0xF784,    // 63364 - 4.0.6.13623
    SMSG_WEATHER                                         = 0x79A0,    // 31136 - 4.0.6.13623
    SMSG_SET_PHASE_SHIFT                                 = 0x044C,    // 1100  - 4.0.6.13623
    SMSG_WORLD_STATE_UI_TIMER_UPDATE                     = 0x698C,    // 27020 - 4.0.6.13623

    NUM_MSG_TYPES                                        = 0xFFFF
};

extern void InitOpcodeTable();

/// Player state
enum SessionStatus
{
    STATUS_AUTHED = 0,                                      // Player authenticated (_player == NULL, m_playerRecentlyLogout = false or will be reset before handler call, m_GUID have garbage)
    STATUS_LOGGEDIN,                                        // Player in game (_player != NULL, m_GUID == _player->GetGUID(), inWorld())
    STATUS_TRANSFER,                                        // Player transferring to another map (_player != NULL, m_GUID == _player->GetGUID(), !inWorld())
    STATUS_LOGGEDIN_OR_RECENTLY_LOGGOUT,                    // _player!= NULL or _player == NULL && m_playerRecentlyLogout, m_GUID store last _player guid)
    STATUS_NEVER,                                           // Opcode not accepted from client (deprecated or server side only)
    STATUS_UNHANDLED,                                       // Opcode not handled yet
};

enum PacketProcessing
{
    PROCESS_INPLACE      = 0,                               //process packet whenever we receive it - mostly for non-handled or non-implemented packets
    PROCESS_THREADUNSAFE = 2,                               //packet is not thread-safe - process it in World::UpdateSessions()
    PROCESS_THREADSAFE   = 3                                //packet is thread-safe - process it in Map::Update()
};

class WorldPacket;

struct OpcodeHandler
{
    char const* name;
    SessionStatus status;
    PacketProcessing packetProcessing;
    void (WorldSession::*handler)(WorldPacket& recvPacket);
};

extern OpcodeHandler opcodeTable[NUM_MSG_TYPES];

// Lookup opcode name for human understandable logging
inline const char* LookupOpcodeName(uint32 id)
{
    if (id >= NUM_MSG_TYPES)
        return "Received unknown opcode, it's more than max!";
    return opcodeTable[id].name;
}

#endif
