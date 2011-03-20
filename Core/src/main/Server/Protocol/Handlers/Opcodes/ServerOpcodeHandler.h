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

#ifndef SERVER_OPCODES
#define SERVER_OPCODES

/**
* Declaration of Opcode values.
* Ordered by Category and value.
*/
enum ServerOpcodes
{
    /***********************************************************/
    /********************* ATTACK OPCODES **********************/
    /***********************************************************/
    SMSG_ATTACKSTART                                     = 0xB68C,    // 46732 - 4.0.6a 13623
    SMSG_ATTACKSTOP                                      = 0x6DCC,    // 28108 - 4.0.6a 13623
    SMSG_ATTACKSWING_NOTINRANGE                          = 0x36C4,    // 14020 - 4.0.6a 13623
    SMSG_ATTACKSWING_BADFACING                           = 0x67A8,    // 26536 - 4.0.6a 13623
    SMSG_ATTACKSWING_DEADTARGET                          = 0xA7C4,    // 42948 - 4.0.6a 13623
    SMSG_ATTACKSWING_CANT_ATTACK                         = 0x6188,    // 24968 - 4.0.6a 13623
    SMSG_ATTACKERSTATEUPDATE                             = 0xBBC0,    // 48064 - 4.0.6a 13623

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
    SMSG_AUTH_CHALLENGE                                  = 0x6019,    // 24601 - 4.0.6a 13623
    SMSG_AUTH_RESPONSE                                   = 0xB28C,    // 45708 - 4.0.6a 13623
    SMSG_REALM_SPLIT                                     = 0x25EC,    // 9708  - 4.0.6a 13623
    SMSG_REDIRECT_CLIENT                                 = 0x201B,    // 8219  - 4.0.6a 13623

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
    SMSG_BINDZONEREPLY                                   = 0xACAC,    // 44204 - 4.0.6a 13623
    SMSG_PLAYERBOUND                                     = 0x6BCC,    // 27596 - 4.0.6a 13623
    SMSG_PLAYERBINDERROR                                 = 0x1B6,
    SMSG_BINDER_CONFIRM                                  = 0x33C4,    // 13252 - 4.0.6a 13623

    /***********************************************************/
    /******************** CALENDAR OPCODES *********************/
    /***********************************************************/
    SMSG_CALENDAR_SEND_CALENDAR                          = 0x436,
    SMSG_CALENDAR_SEND_EVENT                             = 0x437,
    SMSG_CALENDAR_FILTER_GUILD                           = 0x438,
    SMSG_CALENDAR_ARENA_TEAM                             = 0x439,
    SMSG_CALENDAR_EVENT_INVITE                           = 0x43A,
    SMSG_CALENDAR_EVENT_INVITE_REMOVED                   = 0x43B,
    SMSG_CALENDAR_EVENT_STATUS                           = 0x43C,
    SMSG_CALENDAR_COMMAND_RESULT                         = 0xAD80,    // 44416 - 4.0.6a 13623
    SMSG_CALENDAR_RAID_LOCKOUT_ADDED                     = 0x43E,
    SMSG_CALENDAR_RAID_LOCKOUT_REMOVED                   = 0x43F,
    SMSG_CALENDAR_EVENT_INVITE_ALERT                     = 0x440,
    SMSG_CALENDAR_EVENT_INVITE_REMOVED_ALERT             = 0x441,
    SMSG_CALENDAR_EVENT_INVITE_STATUS_ALERT              = 0x442,
    SMSG_CALENDAR_EVENT_REMOVED_ALERT                    = 0x443,
    SMSG_CALENDAR_EVENT_UPDATED_ALERT                    = 0x444,
    SMSG_CALENDAR_EVENT_MODERATOR_STATUS_ALERT           = 0x445,
    SMSG_CALENDAR_SEND_NUM_PENDING                       = 0x448,
    SMSG_CALENDAR_UPDATE_INVITE_LIST                     = 0x460,
    SMSG_CALENDAR_UPDATE_INVITE_LIST2                    = 0x461,
    SMSG_CALENDAR_UPDATE_INVITE_LIST3                    = 0x471,
    SMSG_CALENDAR_ACTION_PENDING                         = 0x4BB,

    /***********************************************************/
    /******************** CHARACTER OPCODES ********************/
    /***********************************************************/
    SMSG_CHAR_CREATE                                     = 0xF7EC,    // 63468 - 4.0.6a 13623
    SMSG_CHAR_ENUM                                       = 0xECCC,    // 60620 - 4.0.6a 13623
    SMSG_CHAR_DELETE                                     = 0xBC80,    // 48256 - 4.0.6a 13623
    SMSG_CHARACTER_LOGIN_FAILED                          = 0x7ACC,    // 31436 - 4.0.6a 13623
    SMSG_CHAR_RENAME                                     = 0xE0EC,    // 57580 - 4.0.6a 13623
    SMSG_CHAR_CUSTOMIZE                                  = 0x2DA4,    // 11684 - 4.0.6a 13623
    SMSG_CHAR_FACTION_CHANGE                             = 0x23AC,    // 9132  - 4.0.6a 13623
    SMSG_CHARACTER_PROFILE                               = 0x338,
    SMSG_CHARACTER_PROFILE_REALM_CONNECTED               = 0x339,

    /***********************************************************/
    /********************** CHAT OPCODES ***********************/
    /***********************************************************/
    SMSG_MESSAGECHAT                                     = 0x61E4,    // 25060 - 4.0.6a 13623
    SMSG_CHAT_WRONG_FACTION                              = 0x219,
    SMSG_CHAT_PLAYER_NOT_FOUND                           = 0x2A9,
    SMSG_CHAT_RESTRICTED                                 = 0x2FD,
    SMSG_CHAT_PLAYER_AMBIGUOUS                           = 0x32D,
    SMSG_EXPECTED_SPAM_RECORDS                           = 0x6084,    // 24708 - 4.0.6a 13623
    SMSG_DEFENSE_MESSAGE                                 = 0x65EC,    // 26092 - 4.0.6a 13623
    SMSG_MOTD                                            = 0x33D,
    SMSG_SERVER_INFO_RESPONSE                            = 0x4A1,

    // Channel
    SMSG_CHANNEL_NOTIFY                                  = 0x7CAC,    // 31916 - 4.0.6a 13623
    SMSG_CHANNEL_LIST                                    = 0x69E0,    // 27104 - 4.0.6a 13623
    SMSG_CHANNEL_MEMBER_COUNT                            = 0x2CEC,    // 11500 - 4.0.6a 13623
    SMSG_AVAILABLE_VOICE_CHANNEL                         = 0xF8C8,    // 63688 - 4.0.6a 13623

    /***********************************************************/
    /********************* COMBAT OPCODES **********************/
    /***********************************************************/
    SMSG_CANCEL_COMBAT                                   = 0xBAE4,   // 47844 - 4.0.6a 13623

    // Combat Log
    SMSG_SPELLBREAKLOG                                   = 0xBDAC,    // 48556 - 4.0.6a 13623
    SMSG_SPELLHEALLOG                                    = 0x6E84,    // 28292 - 4.0.6a 13623
    SMSG_SPELLENERGIZELOG                                = 0xF0EC,    // 61676 - 4.0.6a 13623
    SMSG_BREAK_TARGET                                    = 0x152,
    SMSG_SPELLLOGMISS                                    = 0x24B,
    SMSG_SPELLLOGEXECUTE                                 = 0x24C,
    SMSG_DEBUGAURAPROC                                   = 0x24D,
    SMSG_PERIODICAURALOG                                 = 0x3388,    // 13192 - 4.0.6a 13623
    SMSG_SPELLDAMAGESHIELD                               = 0x73A0,    // 29600 - 4.0.6a 13623
    SMSG_SPELLNONMELEEDAMAGELOG                          = 0x74AC,    // 29868 - 4.0.6a 13623
    SMSG_SPELLDISPELLOG                                  = 0x27B,
    SMSG_DAMAGE_CALC_LOG                                 = 0xFD84,    // 64900 - 4.0.6a 13623
    SMSG_SPELLINSTAKILLLOG                               = 0x61C8,    // 25032 - 4.0.6a 13623
    SMSG_SPELLSTEALLOG                                   = 0x333,
    SMSG_SPELL_CHANCE_PROC_LOG                           = 0x3AA,
    SMSG_AURACASTLOG                                     = 0x1D1,
    SMSG_RESISTLOG                                       = 0x1D6,
    SMSG_ENCHANTMENTLOG                                  = 0xF5AC,    // 62892 - 4.0.6a 13623
    SMSG_PARTYKILLLOG                                    = 0xAB84,    // 43908 - 4.0.6a 13623
    SMSG_ENVIRONMENTALDAMAGELOG                          = 0xE1C8,    // 57800 - 4.0.6a 13623

    /***********************************************************/
    /********************** DUEL OPCODES ***********************/
    /***********************************************************/
    SMSG_DUEL_REQUESTED                                  = 0x3FC8,    // 16328 - 4.0.6a 13623
    SMSG_DUEL_OUTOFBOUNDS                                = 0x68C0,    // 26816 - 4.0.6a 13623
    SMSG_DUEL_INBOUNDS                                   = 0xECA4,    // 60580 - 4.0.6a 13623
    SMSG_DUEL_COMPLETE                                   = 0xFCE8,    // 64744 - 4.0.6a 13623
    SMSG_DUEL_WINNER                                     = 0x79E4,    // 31204 - 4.0.6a 13623
    SMSG_DUEL_COUNTDOWN                                  = 0xE8E0,    // 59616 - 4.0.6a 13623

    /***********************************************************/
    /******************** FACTION OPCODES **********************/
    /***********************************************************/
    SMSG_INITIALIZE_FACTIONS                             = 0x25C0,    // 9664  - 4.0.6a 13623
    SMSG_SET_FACTION_VISIBLE                             = 0x3988,    // 14728 - 4.0.6a 13623
    SMSG_SET_FACTION_STANDING                            = 0x718C,    // 29068 - 4.0.6a 13623
    SMSG_SET_FACTION_ATWAR                               = 0x313,

    /***********************************************************/
    /******************* GAMEMASTER OPCODES ********************/
    /***********************************************************/
    SMSG_GM_PLAYER_INFO                                  = 0x230,
    SMSG_GM_MESSAGECHAT                                  = 0x3AEC,    // 15084 - 4.0.6a 13623
    SMSG_GMRESPONSE_DB_ERROR                             = 0x4EE,
    SMSG_GMRESPONSE_RECEIVED                             = 0x4EF,
    SMSG_GMRESPONSE_STATUS_UPDATE                        = 0x4F1,

    // Ticket
    SMSG_GMTICKET_CREATE                                 = 0x206,
    SMSG_GMTICKET_UPDATETEXT                             = 0x208,
    SMSG_GMTICKET_GETTICKET                              = 0x2284,    // 8836  - 4.0.6a 13623
    SMSG_GMTICKET_SYSTEMSTATUS                           = 0x21B,
    SMSG_GM_TICKET_STATUS_UPDATE                         = 0x328,
    SMSG_GMTICKET_DELETETICKET                           = 0x218,

    /***********************************************************/
    /****************** (GAME)OBJECT OPCODES *******************/
    /***********************************************************/
    SMSG_GAMEOBJECT_CUSTOM_ANIM                          = 0x2E8C,    // 11916 - 4.0.6a 13623
    SMSG_GAMEOBJECT_PAGETEXT                             = 0xE5C8,    // 58824 - 4.0.6a 13623
    SMSG_GAMEOBJECT_DESPAWN_ANIM                         = 0xBFA8,    // 49064 - 4.0.6a 13623
    SMSG_GAMEOBJECT_RESET_STATE                          = 0x22E0,    // 8928  - 4.0.6a 13623
    SMSG_DUMP_OBJECTS_DATA                               = 0x48C,

    /***********************************************************/
    /********************** GOSSIP OPCODES *********************/
    /***********************************************************/
    // Gossip General
    SMSG_GOSSIP_MESSAGE                                  = 0xBBC8,    // 48072 - 4.0.6a 13623
    SMSG_GOSSIP_COMPLETE                                 = 0xF0AC,    // 61612 - 4.0.6a 13623
    SMSG_NPC_TEXT_UPDATE                                 = 0xB2AC,    // 45740 - 4.0.6a 13623
    SMSG_NPC_WONT_TALK                                   = 0x181,
    SMSG_GOSSIP_POI                                      = 0xB9AC,    // 47532 - 4.0.6a 13623

    // Gossip Questgiver
    SMSG_QUESTGIVER_STATUS                               = 0x7988,    // 31112 - 4.0.6a 13623
    SMSG_QUESTGIVER_QUEST_LIST                           = 0x2B88,    // 11144 - 4.0.6a 13623
    SMSG_QUESTGIVER_QUEST_DETAILS                        = 0x68A0,    // 26784 - 4.0.6a 13623
    SMSG_QUESTGIVER_REQUEST_ITEMS                        = 0x23A8,    // 9128  - 4.0.6a 13623
    SMSG_QUESTGIVER_OFFER_REWARD                         = 0x3FCC,    // 16332 - 4.0.6a 13623
    SMSG_QUESTGIVER_QUEST_INVALID                        = 0x18F,
    SMSG_QUESTGIVER_QUEST_COMPLETE                       = 0xF5C0,    // 62912 - 4.0.6a 13623
    SMSG_QUESTGIVER_QUEST_FAILED                         = 0xA084,    // 41092 - 4.0.6a 13623
    SMSG_QUESTGIVER_STATUS_MULTIPLE                      = 0x418,

    /***********************************************************/
    /********************** GROUP OPCODES **********************/
    /***********************************************************/
    SMSG_GROUP_INVITE                                    = 0xA8A8,    // 43176 - 4.0.6a 13623
    SMSG_GROUP_CANCEL                                    = 0x6AAC,    // 27308 - 4.0.6a 13623
    SMSG_GROUP_DECLINE                                   = 0xABAC,    // 43948 - 4.0.6a 13623
    SMSG_GROUP_UNINVITE                                  = 0x3ACC,    // 15052 - 4.0.6a 13623
    SMSG_GROUP_SET_LEADER                                = 0xE88C,    // 59532 - 4.0.6a 13623
    SMSG_GROUP_DESTROYED                                 = 0x22CC,    // 8908  - 4.0.6a 13623
    SMSG_GROUP_LIST                                      = 0x6D8C,    // 28044 - 4.0.6a 13623
    SMSG_REAL_GROUP_UPDATE                               = 0x31C0,    // 12736 - 4.0.6a 13623
    SMSG_GROUPACTION_THROTTLED                           = 0x411,

    /***********************************************************/
    /********************** GUILD OPCODES **********************/
    /***********************************************************/
    SMSG_GUILD_INVITE                                    = 0xB78C,    // 46988 - 4.0.6a 13623
    SMSG_GUILD_DECLINE                                   = 0x7DEC,    // 32236 - 4.0.6a 13623
    SMSG_GUILD_INFO                                      = 0x20A8,    // 8360  - 4.0.6a 13623
    SMSG_GUILD_ROSTER                                    = 0x08A,
    SMSG_GUILD_EVENT                                     = 0xB7C4,    // 47044 - 4.0.6a 13623
    SMSG_GUILD_COMMAND_RESULT                            = 0x23C0,    // 9152  - 4.0.6a 13623
    SMSG_GUILD_BANK_LIST                                 = 0x3E8,

    // Party
    SMSG_PARTY_MEMBER_STATS                              = 0x07E,
    SMSG_PARTY_COMMAND_RESULT                            = 0x26E0,    // 9952  - 4.0.6a 13623
    SMSG_PARTY_MEMBER_STATS_FULL                         = 0x2F2,
    SMSG_ECHO_PARTY_SQUELCH                              = 0x2AC4,    // 10948 - 4.0.6a 13623

    // Petition
    SMSG_BUY_BANK_SLOT_RESULT                            = 0x1BA,
    SMSG_PETITION_SHOWLIST                               = 0x1BC,
    SMSG_PETITION_SHOW_SIGNATURES                        = 0xE2E0,    // 58080 - 4.0.6a 13623
    SMSG_PETITION_SIGN_RESULTS                           = 0xA1A4,    // 41380 - 4.0.6a 13623
    SMSG_TURN_IN_PETITION_RESULTS                        = 0x1C5,
    SMSG_PETITION_QUERY_RESPONSE                         = 0xFB80,    // 64384 - 4.0.6a 13623
    SMSG_OFFER_PETITION_ERROR                            = 0x38F,

    /***********************************************************/
    /******************** INSTANCE OPCODES *********************/
    /***********************************************************/
    SMSG_INSTANCE_LOCK_WARNING_QUERY                     = 0x147,
    SMSG_UPDATE_INSTANCE_ENCOUNTER_UNIT                  = 0xEDA4,    // 60836 - 4.0.6a 13623
    SMSG_RAID_GROUP_ONLY                                 = 0x286,
    SMSG_INSTANCE_SAVE_CREATED                           = 0xBBC4,    // 48068 - 4.0.6a 13623
    SMSG_RAID_INSTANCE_INFO                              = 0x2CC,
    SMSG_RAID_INSTANCE_MESSAGE                           = 0x6680,    // 26240 - 4.0.6a 13623
    SMSG_UPDATE_INSTANCE_OWNERSHIP                       = 0x3B8C,    // 15244 - 4.0.6a 13623
    SMSG_INSTANCE_DIFFICULTY                             = 0x33B,
    SMSG_RESET_FAILED_NOTIFY                             = 0x396,
    SMSG_RAID_READY_CHECK_ERROR                          = 0x408,

    // Lfg
    SMSG_LFG_PLAYER_REWARD                               = 0x2C88,    // 11400 - 4.0.6a 13623
    SMSG_LFG_TELEPORT_DENIED                             = 0xEAA0,    // 60064 - 4.0.6a 13623
    SMSG_LFG_OFFER_CONTINUE                              = 0x63EC,    // 25580 - 4.0.6a 13623
    SMSG_LFG_ROLE_CHOSEN                                 = 0xA9AC,    // 43436 - 4.0.6a 13623
    SMSG_UPDATE_LFG_LIST                                 = 0x768C,    // 30348 - 4.0.6a 13623
    SMSG_LFG_PROPOSAL_UPDATE                             = 0x32AC,    // 12972 - 4.0.6a 13623
    SMSG_LFG_ROLE_CHECK_UPDATE                           = 0xF2A8,    // 62120 - 4.0.6a 13623
    SMSG_LFG_JOIN_RESULT                                 = 0x338C,    // 13196 - 4.0.6a 13623
    SMSG_LFG_QUEUE_STATUS                                = 0xB388,    // 45960 - 4.0.6a 13623
    SMSG_LFG_UPDATE_PLAYER                               = 0xE284,    // 57988 - 4.0.6a 13623
    SMSG_LFG_UPDATE_PARTY                                = 0x2CE8,    // 11496 - 4.0.6a 13623
    SMSG_LFG_UPDATE_SEARCH                               = 0x3880,    // 14464 - 4.0.6a 13623
    SMSG_LFG_BOOT_PLAYER                                 = 0x79AC,    // 31148 - 4.0.6a 13623
    SMSG_LFG_PLAYER_INFO                                 = 0xE088,    // 57480 - 4.0.6a 13623
    SMSG_LFG_PARTY_INFO                                  = 0x60A0,    // 24736 - 4.0.6a 13623
    SMSG_LFG_DISABLED                                    = 0xF880,    // 63616 - 4.0.6a 13623

    // Meetingstone
    SMSG_MEETINGSTONE_SETQUEUE                           = 0xED88,    // 60808 - 4.0.6a 13623
    SMSG_MEETINGSTONE_COMPLETE                           = 0xF680,    // 63104 - 4.0.6a 13623
    SMSG_MEETINGSTONE_IN_PROGRESS                        = 0xE7C4,    // 59332 - 4.0.6a 13623
    SMSG_MEETINGSTONE_MEMBER_ADDED                       = 0x299,

    // Battleground
    SMSG_GROUP_JOINED_BATTLEGROUND                       = 0x2E8,
    SMSG_BATTLEGROUND_PLAYER_JOINED                      = 0x2EC,
    SMSG_BATTLEGROUND_PLAYER_LEFT                        = 0x2ED,
    SMSG_INSTANCE_RESET                                  = 0x30E8,    // 12520 - 4.0.6a 13623
    SMSG_INSTANCE_RESET_FAILED                           = 0x3BA0,    // 15264 - 4.0.6a 13623
    SMSG_UPDATE_LAST_INSTANCE                            = 0x33E8,    // 13288 - 4.0.6a 13623
    SMSG_JOINED_BATTLEGROUND_QUEUE                       = 0x38A,
    SMSG_BATTLEGROUND_INFO_THROTTLED                     = 0x4A6,

    /***********************************************************/
    /********************** ITEM OPCODES ***********************/
    /***********************************************************/
    SMSG_READ_ITEM_OK                                    = 0x0AE,
    SMSG_READ_ITEM_FAILED                                = 0x0AF,
    SMSG_ITEM_COOLDOWN                                   = 0x0B0,
    SMSG_ITEM_PUSH_RESULT                                = 0x166,
    SMSG_ITEM_REFUND_INFO_RESPONSE                       = 0x4B2,
    SMSG_ITEM_REFUND_RESULT                              = 0x4B5,
    SMSG_UPDATE_ITEM_ENCHANTMENTS                        = 0x50B,

    // Inventory / Trade
    SMSG_INVENTORY_CHANGE_FAILURE                        = 0x112,
    SMSG_OPEN_CONTAINER                                  = 0x113,
    SMSG_INSPECT                                         = 0x115,
    SMSG_TRADE_STATUS                                    = 0x120,
    SMSG_TRADE_STATUS_EXTENDED                           = 0x121,
    SMSG_LIST_INVENTORY                                  = 0x19F,
    SMSG_EQUIPMENT_SET_LIST                              = 0x4BC,

    // Equipment
    SMSG_EQUIPMENT_SET_SAVED                             = 0x137,
    SMSG_EQUIPMENT_SET_USE_RESULT                        = 0x4D6,

    // Item Buy / Sell
    SMSG_SELL_ITEM                                       = 0x1A1,
    SMSG_BUY_ITEM                                        = 0x1A4,
    SMSG_BUY_FAILED                                      = 0x1A5,

    /***********************************************************/
    /******************* LOGIN / OUT OPCODES *******************/
    /***********************************************************/
    // Login
    // Logout
    SMSG_LOGOUT_RESPONSE                                 = 0x04C,
    SMSG_LOGOUT_COMPLETE                                 = 0x04D,
    SMSG_LOGOUT_CANCEL_ACK                               = 0x04F,

    /***********************************************************/
    /********************** LOOT OPCODES ***********************/
    /***********************************************************/
    SMSG_LOOT_RESPONSE                                   = 0x160,
    SMSG_LOOT_RELEASE_RESPONSE                           = 0x161,
    SMSG_LOOT_REMOVED                                    = 0x162,
    SMSG_LOOT_MONEY_NOTIFY                               = 0x163,
    SMSG_LOOT_ITEM_NOTIFY                                = 0x164,
    SMSG_LOOT_CLEAR_MONEY                                = 0x165,
    SMSG_LOOT_LIST                                       = 0x3F9,
    SMSG_LOOT_SLOT_CHANGED                               = 0x4FD,

    // Loot Group
    SMSG_LOOT_ALL_PASSED                                 = 0x29E,
    SMSG_LOOT_ROLL_WON                                   = 0x29F,
    SMSG_LOOT_START_ROLL                                 = 0x2A1,
    SMSG_LOOT_ROLL                                       = 0x2A2,
    SMSG_LOOT_MASTER_LIST                                = 0x2A4,
    SMSG_DYNAMIC_DROP_ROLL_RESULT                        = 0x469,

    /***********************************************************/
    /********************** MAIL OPCODES ***********************/
    /***********************************************************/
    SMSG_SEND_MAIL_RESULT                                = 0x239,
    SMSG_MAIL_LIST_RESULT                                = 0x23B,
    SMSG_RECEIVED_MAIL                                   = 0x285,

    /***********************************************************/
    /******************** MOVEMENT OPCODES *********************/
    /***********************************************************/
    SMSG_MOVE_CHARACTER_CHEAT                            = 0x00E,
    SMSG_MOVE_WATER_WALK                                 = 0x0DE,
    SMSG_MOVE_LAND_WALK                                  = 0x0DF,
    SMSG_FORCE_SWIM_SPEED_CHANGE                         = 0x0E6,
    SMSG_MOVE_KNOCK_BACK                                 = 0x0EF,
    SMSG_COMPRESSED_MOVES                                = 0x2FB,
    SMSG_MOVE_ABANDON_TRANSPORT                          = 0x45F,
    SMSG_UNKNOWN_1302                                    = 0x516,
    SMSG_UNKNOWN_1304                                    = 0x518,

    // Movement Force
    SMSG_FORCE_RUN_SPEED_CHANGE                          = 0x0E2,
    SMSG_FORCE_RUN_BACK_SPEED_CHANGE                     = 0x0E4,
    SMSG_FORCE_MOVE_ROOT                                 = 0x0E8,
    SMSG_FORCE_MOVE_UNROOT                               = 0x0EA,
    SMSG_FORCE_WALK_SPEED_CHANGE                         = 0x2DA,
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
    SMSG_MOVE_SET_CAN_FLY                                = 0x343,
    SMSG_MOVE_UNSET_CAN_FLY                              = 0x344,

    // Spline
    SMSG_SPLINE_MOVE_UNROOT                              = 0x304,
    SMSG_SPLINE_MOVE_FEATHER_FALL                        = 0x305,
    SMSG_SPLINE_MOVE_NORMAL_FALL                         = 0x306,
    SMSG_SPLINE_MOVE_SET_HOVER                           = 0x307,
    SMSG_SPLINE_MOVE_UNSET_HOVER                         = 0x308,
    SMSG_SPLINE_MOVE_WATER_WALK                          = 0x309,
    SMSG_SPLINE_MOVE_LAND_WALK                           = 0x30A,
    SMSG_SPLINE_MOVE_START_SWIM                          = 0x30B,
    SMSG_SPLINE_MOVE_STOP_SWIM                           = 0x30C,
    SMSG_SPLINE_MOVE_SET_RUN_MODE                        = 0x30D,
    SMSG_SPLINE_MOVE_SET_WALK_MODE                       = 0x30E,
    SMSG_SPLINE_MOVE_ROOT                                = 0x31A,
    SMSG_SPLINE_MOVE_UNKNOWN_1235                        = 0x4D3,
    SMSG_SPLINE_MOVE_UNKNOWN_1236                        = 0x4D4,
    SMSG_SPLINE_SET_PITCH_RATE                           = 0x45E,

    // Spline Set / Unset
    SMSG_SPLINE_SET_RUN_SPEED                            = 0x2FE,
    SMSG_SPLINE_SET_RUN_BACK_SPEED                       = 0x2FF,
    SMSG_SPLINE_SET_SWIM_SPEED                           = 0x300,
    SMSG_SPLINE_SET_WALK_SPEED                           = 0x301,
    SMSG_SPLINE_SET_SWIM_BACK_SPEED                      = 0x302,
    SMSG_SPLINE_SET_TURN_RATE                            = 0x303,
    SMSG_SPLINE_SET_FLIGHT_SPEED                         = 0x385,
    SMSG_SPLINE_SET_FLIGHT_BACK_SPEED                    = 0x386,
    SMSG_SPLINE_MOVE_SET_FLYING                          = 0x422,
    SMSG_SPLINE_MOVE_UNSET_FLYING                        = 0x423,
    
    /***********************************************************/
    /********************* MOVIE OPCODES ***********************/
    /***********************************************************/
    // Cinematic
    SMSG_TRIGGER_CINEMATIC                               = 0x0FA,

    // Movie
    SMSG_TRIGGER_MOVIE                                   = 0x464,

    /***********************************************************/
    /****************** MOUNT / PET OPCODES ********************/
    /***********************************************************/
    // Mount
    SMSG_MOUNTRESULT                                     = 0x16E,
    SMSG_DISMOUNTRESULT                                  = 0x16F,
    SMSG_PUREMOUNT_CANCELLED_OBSOLETE                    = 0x170,
    SMSG_MOUNTSPECIAL_ANIM                               = 0x172,
    SMSG_DISMOUNT                                        = 0x3AC,

    // Pet
    SMSG_PET_TAME_FAILURE                                = 0x173,
    SMSG_PET_NAME_INVALID                                = 0x178,
    SMSG_PET_SPELLS                                      = 0x179,
    SMSG_PET_MODE                                        = 0x17A,
    SMSG_PET_UPDATE_COMBO_POINTS                         = 0x492,

    /***********************************************************/
    /********************** MULTI OPCODES **********************/
    /***********************************************************/
    SMSG_MULTIPLE_PACKETS                                = 0x4CD,

    /***********************************************************/
    /********************* PLAYER OPCODES **********************/
    /***********************************************************/
    SMSG_PLAYER_DIFFICULTY_CHANGE                        = 0x20E,
    SMSG_PLAYER_SKINNED                                  = 0x2BC,
    SMSG_ADDON_INFO                                      = 0x2EF,
    SMSG_GHOSTEE_GONE                                    = 0x326,
    SMSG_TITLE_EARNED                                    = 0x373,
    SMSG_UPDATE_COMBO_POINTS                             = 0x39D,
    SMSG_CHEAT_PLAYER_LOOKUP                             = 0x3C4,
    SMSG_KICK_REASON                                     = 0x3C5,
    SMSG_SET_PLAYER_DECLINED_NAMES_RESULT                = 0x41A,
    SMSG_HIGHEST_THREAT_UPDATE                           = 0x482,
    SMSG_THREAT_UPDATE                                   = 0x483,
    SMSG_THREAT_REMOVE                                   = 0x484,
    SMSG_THREAT_CLEAR                                    = 0x485,

    // Player Dance
    SMSG_NOTIFY_DANCE                                    = 0x44A,
    SMSG_PLAY_DANCE                                      = 0x44C,
    SMSG_STOP_DANCE                                      = 0x44F,
    SMSG_DANCE_QUERY_RESPONSE                            = 0x452,
    SMSG_INVALIDATE_DANCE                                = 0x453,
    SMSG_LEARNED_DANCE_MOVES                             = 0x455,

    // Player Achievement
    SMSG_ACHIEVEMENT_EARNED                              = 0x468,
    SMSG_CRITERIA_UPDATE                                 = 0x46A,
    SMSG_RESPOND_INSPECT_ACHIEVEMENTS                    = 0x46C,
    SMSG_ALL_ACHIEVEMENT_DATA                            = 0x47D,
    SMSG_SERVER_FIRST_ACHIEVEMENT                        = 0x498,
    SMSG_CRITERIA_DELETED                                = 0x49E,
    SMSG_ACHIEVEMENT_DELETED                             = 0x49F,

    // Player Exploration
    SMSG_EXPLORATION_EXPERIENCE                          = 0x1F8,

    // Player Corpse / Resurrect / Death
    SMSG_RESURRECT_REQUEST                               = 0x15B,
    SMSG_RESURRECT_FAILED                                = 0x252,
    SMSG_CORPSE_RECLAIM_DELAY                            = 0x269,
    SMSG_FEIGN_DEATH_RESISTED                            = 0x2B4,
    SMSG_DEATH_RELEASE_LOC                               = 0x378,
    SMSG_FORCED_DEATH_UPDATE                             = 0x37A,
    SMSG_PRE_RESURRECT                                   = 0x494,
    SMSG_CORPSE_NOT_IN_INSTANCE                          = 0x506,

    // Player Pet
    SMSG_STABLE_RESULT                                   = 0x273,
    SMSG_SUMMON_REQUEST                                  = 0x2AB,
    SMSG_PET_BROKEN                                      = 0x2AF,
    SMSG_PET_ACTION_FEEDBACK                             = 0x2C6,
    SMSG_PET_UNLEARN_CONFIRM                             = 0x2F1,
    SMSG_PET_RENAMEABLE                                  = 0x475,
    SMSG_PET_GUIDS                                       = 0x4AA,
    SMSG_PET_ACTION_SOUND                                = 0x324,
    SMSG_PET_DISMISS_SOUND                               = 0x325,

    // Player PVP / Honor / Arena
    SMSG_PVP_CREDIT                                      = 0x28C,
    SMSG_ARENA_TEAM_COMMAND_RESULT                       = 0x349,
    SMSG_ARENA_TEAM_QUERY_RESPONSE                       = 0x34C,
    SMSG_ARENA_TEAM_ROSTER                               = 0x34E,
    SMSG_ARENA_TEAM_INVITE                               = 0x350,
    SMSG_ARENA_TEAM_EVENT                                = 0x357,
    SMSG_ARENA_TEAM_STATS                                = 0x35B,
    SMSG_ARENA_ERROR                                     = 0x376,
    SMSG_REPORT_PVP_AFK_RESULT                           = 0x3E5,
    SMSG_ARENA_OPPONENT_UPDATE                           = 0x4C7,
    SMSG_ARENA_TEAM_CHANGE_FAILED_QUEUED                 = 0x4C8,

    // Player Minigame
    SMSG_MINIGAME_SETUP                                  = 0x2F6,
    SMSG_MINIGAME_STATE                                  = 0x2F7,
    SMSG_MINIGAME_MOVE_FAILED                            = 0x2F9,

    // Friends / Contacts / ...
    SMSG_USERLIST_ADD                                    = 0x3F0,
    SMSG_USERLIST_REMOVE                                 = 0x3F1,
    SMSG_USERLIST_UPDATE                                 = 0x3F2,
    SMSG_REFER_A_FRIEND_FAILURE                          = 0x421,

    // Talents
    SMSG_INSPECT_TALENT                                  = 0x3F4,
    SMSG_TALENTS_INFO                                    = 0x4C0,
    SMSG_TALENTS_INVOLUNTARILY_RESET                     = 0x4FA,

    // Totem
    SMSG_TOTEM_CREATED                                   = 0x413,

    // Barber
    SMSG_ENABLE_BARBER_SHOP                              = 0x427,
    SMSG_BARBER_SHOP_RESULT                              = 0x428,

    // Player Health / Power / Mana / ...
    SMSG_HEALTH_UPDATE                                   = 0x47F,
    SMSG_POWER_UPDATE                                    = 0x480,
    SMSG_CONVERT_RUNE                                    = 0x486,
    SMSG_RESYNC_RUNES                                    = 0x487,
    SMSG_ADD_RUNE_POWER                                  = 0x488,

    // Player Vehicle
    SMSG_PLAYER_VEHICLE_DATA                             = 0x4A7,

    /***********************************************************/
    /********************* QUERY OPCODES ***********************/
    /***********************************************************/
    SMSG_NAME_QUERY_RESPONSE                             = 0x051,
    SMSG_PET_NAME_QUERY_RESPONSE                         = 0x053,
    SMSG_GUILD_QUERY_RESPONSE                            = 0x055,
    SMSG_ITEM_QUERY_SINGLE_RESPONSE                      = 0x058,
    SMSG_ITEM_QUERY_MULTIPLE_RESPONSE                    = 0x059,
    SMSG_PAGE_TEXT_QUERY_RESPONSE                        = 0x05B,
    SMSG_QUEST_QUERY_RESPONSE                            = 0x05D,
    SMSG_GAMEOBJECT_QUERY_RESPONSE                       = 0x05F,
    SMSG_CREATURE_QUERY_RESPONSE                         = 0x061,
    SMSG_ITEM_TEXT_QUERY_RESPONSE                        = 0x244,
    SMSG_ITEM_NAME_QUERY_RESPONSE                        = 0x2C5,
    SMSG_QUEST_POI_QUERY_RESPONSE                        = 0x1E4,
    SMSG_CORPSE_MAP_POSITION_QUERY_RESPONSE              = 0x4B7,
    SMSG_QUERY_QUESTS_COMPLETED_RESPONSE                 = 0x501,

    /***********************************************************/
    /********************* QUEST OPCODES ***********************/
    /***********************************************************/
    SMSG_QUESTLOG_FULL                                   = 0x195,
    SMSG_QUEST_FORCE_REMOVE                              = 0x21E,
    SMSG_QUEST_CONFIRM_ACCEPT                            = 0x19C,

    // Quest Update
    SMSG_QUESTUPDATE_FAILED                              = 0x196,
    SMSG_QUESTUPDATE_FAILEDTIMER                         = 0x197,
    SMSG_QUESTUPDATE_COMPLETE                            = 0x198,
    SMSG_QUESTUPDATE_ADD_KILL                            = 0x199,
    SMSG_QUESTUPDATE_ADD_ITEM                            = 0x19A,
    SMSG_QUESTUPDATE_ADD_PVP_KILL                        = 0x46F,

    /***********************************************************/
    /********************* SPELL OPCODES ***********************/
    /***********************************************************/
    SMSG_INITIAL_SPELLS                                  = 0x12A,
    SMSG_LEARNED_SPELL                                   = 0x12B,
    SMSG_SUPERCEDED_SPELL                                = 0x12C,
    SMSG_CAST_FAILED                                     = 0x130,
    SMSG_SPELL_START                                     = 0x131,
    SMSG_SPELL_GO                                        = 0x132,
    SMSG_SPELL_FAILURE                                   = 0x133,
    SMSG_DAMAGE_DONE_OBSOLETE                            = 0x14C,
    SMSG_UNIT_SPELLCAST_START                            = 0x14D,
    SMSG_SPELL_DELAYED                                   = 0x1E2,
    SMSG_PLAY_SPELL_VISUAL                               = 0x1F3,
    SMSG_PLAY_SPELL_IMPACT                               = 0x1F7,
    SMSG_REMOVED_SPELL                                   = 0x203,
    SMSG_DISPEL_FAILED                                   = 0x262,
    SMSG_SPELLORDAMAGE_IMMUNE                            = 0x263,
    SMSG_SET_FLAT_SPELL_MODIFIER                         = 0x266,
    SMSG_SET_PCT_SPELL_MODIFIER                          = 0x267,
    SMSG_CANCEL_AUTO_REPEAT                              = 0x29C,
    SMSG_SPELL_FAILED_OTHER                              = 0x2A6,
    SMSG_SPELL_UPDATE_CHAIN_TARGETS                      = 0x330,
    SMSG_SPELL_CHANCE_RESIST_PUSHBACK                    = 0x404,
    SMSG_SUMMON_CANCEL                                   = 0x424,
    SMSG_NOTIFY_DEST_LOC_SPELL_CAST                      = 0x48E,
    SMSG_CAMERA_SHAKE                                    = 0x50A,

    // Cooldown
    SMSG_SPELL_COOLDOWN                                  = 0x134,
    SMSG_COOLDOWN_EVENT                                  = 0x135,
    SMSG_CLEAR_COOLDOWN                                  = 0x1DE,
    SMSG_COOLDOWN_CHEAT                                  = 0x1E1,
    SMSG_MODIFY_COOLDOWN                                 = 0x491,

    // Pet
    SMSG_PET_CAST_FAILED                                 = 0x138,
    SMSG_PET_LEARNED_SPELL                               = 0x499,
    SMSG_PET_REMOVED_SPELL                               = 0x49A,

    // Trainer
    SMSG_TRAINER_LIST                                    = 0x1B1,
    SMSG_TRAINER_BUY_SUCCEEDED                           = 0x1B3,
    SMSG_TRAINER_BUY_FAILED                              = 0x1B4,
    SMSG_SEND_UNLEARN_SPELLS                             = 0x41E,

    // Auras
    SMSG_INIT_EXTRA_AURA_INFO_OBSOLETE                   = 0x3A3,
    SMSG_SET_EXTRA_AURA_INFO_OBSOLETE                    = 0x3A4,
    SMSG_SET_EXTRA_AURA_INFO_NEED_UPDATE_OBSOLETE        = 0x3A5,
    SMSG_CLEAR_EXTRA_AURA_INFO_OBSOLETE                  = 0x3A6,
    SMSG_AURA_UPDATE_ALL                                 = 0x495,
    SMSG_AURA_UPDATE                                     = 0x496,
    SMSG_ON_CANCEL_EXPECTED_RIDE_VEHICLE_AURA            = 0x49D,

    /***********************************************************/
    /******************* TRANSPORT OPCODES *********************/
    /***********************************************************/
    // Transport Taxi
    SMSG_SHOWTAXINODES                                   = 0x1A9,
    SMSG_TAXINODE_STATUS                                 = 0x1AB,
    SMSG_ACTIVATETAXIREPLY                               = 0x1AE,
    SMSG_NEW_TAXI_PATH                                   = 0x1AF,
    SMSG_MONSTER_MOVE_TRANSPORT                          = 0x2AE,

    /***********************************************************/
    /****************** TIME / SPEED OPCODES *******************/
    /***********************************************************/
    // Time
    SMSG_LOGIN_SETTIMESPEED                              = 0x042,
    SMSG_GAMETIME_UPDATE                                 = 0x043,
    SMSG_GAMETIME_SET                                    = 0x045,
    SMSG_SERVERTIME                                      = 0x049,
    SMSG_PLAYED_TIME                                     = 0x1CD,
    SMSG_QUERY_TIME_RESPONSE                             = 0x1CF,
    SMSG_TIME_SYNC_REQ                                   = 0x390,
    SMSG_ITEM_TIME_UPDATE                                = 0x1EA,
    SMSG_ITEM_ENCHANT_TIME_UPDATE                        = 0x1EB,
    SMSG_ACCOUNT_DATA_TIMES                              = 0x209,
    SMSG_PLAY_TIME_WARNING                               = 0x2F5,
    SMSG_GAMETIMEBIAS_SET                                = 0x314,

    // Speed
    SMSG_GAMESPEED_SET                                   = 0x047,

    /***********************************************************/
    /****************** UNCATEGORZIED OPCODES ******************/
    /***********************************************************/
    SMSG_DBLOOKUP                                        = 0x003,
    SMSG_QUERY_OBJECT_POSITION                           = 0x005,
    SMSG_QUERY_OBJECT_ROTATION                           = 0x007,
    SMSG_ZONE_MAP                                        = 0x00B,
    SMSG_CHECK_FOR_BOTS                                  = 0x015,
    SMSG_FORCEACTIONSHOW                                 = 0x01B,
    SMSG_PETGODMODE                                      = 0x01D,
    SMSG_REFER_A_FRIEND_EXPIRED                          = 0x01E,
    SMSG_GODMODE                                         = 0x023,
    SMSG_DEBUG_AISTATE                                   = 0x02F,
    SMSG_DESTRUCTIBLE_BUILDING_DAMAGE                    = 0x032,
    SMSG_TRANSFER_PENDING                                = 0x03F,
    SMSG_TRANSFER_ABORTED                                = 0x040,
    SMSG_WHO                                             = 0x063,
    SMSG_WHOIS                                           = 0x065,
    SMSG_CONTACT_LIST                                    = 0x067,
    SMSG_FRIEND_STATUS                                   = 0x068,
    SMSG_MONSTER_MOVE                                    = 0x0DD,
    SMSG_TUTORIAL_FLAGS                                  = 0x0FD,
    SMSG_EMOTE                                           = 0x103,
    SMSG_TEXT_EMOTE                                      = 0x105,
    SMSG_SET_PROFICIENCY                                 = 0x127,
    SMSG_ACTION_BUTTONS                                  = 0x129,
    SMSG_AI_REACTION                                     = 0x13C,
    SMSG_CLIENT_CONTROL_UPDATE                           = 0x159,
    SMSG_FLIGHT_SPLINE_SYNC                              = 0x388,
    SMSG_SHOW_BANK                                       = 0x1B8,
    SMSG_NOTIFICATION                                    = 0x1CB,
    SMSG_LOG_XPGAIN                                      = 0x1D0,
    SMSG_LEVELUP_INFO                                    = 0x1D4,
    SMSG_START_MIRROR_TIMER                              = 0x1D9,
    SMSG_PAUSE_MIRROR_TIMER                              = 0x1DA,
    SMSG_STOP_MIRROR_TIMER                               = 0x1DB,
    SMSG_PONG                                            = 0x1DD,
    SMSG_INVALID_PROMOTION_CODE                          = 0x1E7,
    SMSG_RWHOIS                                          = 0x1FE,
    SMSG_UPDATE_ACCOUNT_DATA                             = 0x20C,
    SMSG_CLEAR_FAR_SIGHT_IMMEDIATE                       = 0x20D,
    SMSG_SPIRIT_HEALER_CONFIRM                           = 0x222,
    SMSG_ZONE_UNDER_ATTACK                               = 0x254,
    SMSG_PROCRESIST                                      = 0x260,
    SMSG_STANDSTATE_CHANGE_FAILURE_OBSOLETE              = 0x261,
    SMSG_PLAY_MUSIC                                      = 0x277,
    SMSG_PLAY_OBJECT_SOUND                               = 0x278,
    SMSG_SERVER_MESSAGE                                  = 0x291,
    SMSG_STANDSTATE_UPDATE                               = 0x29D,
    SMSG_SET_FORCED_REACTIONS                            = 0x2A5,
    SMSG_SCRIPT_MESSAGE                                  = 0x2B6,
    SMSG_AREA_TRIGGER_MESSAGE                            = 0x2B8,
    SMSG_DURABILITY_DAMAGE_DEATH                         = 0x2BD,
    SMSG_PLAY_SOUND                                      = 0x2D2,
    SMSG_AREA_SPIRIT_HEALER_TIME                         = 0x2E4,
    SMSG_WARDEN_DATA                                     = 0x2E6,
    SMSG_INVALIDATE_PLAYER                               = 0x31C,
    SMSG_LOTTERY_QUERY_RESULT_OBSOLETE                   = 0x335,
    SMSG_LOTTERY_RESULT_OBSOLETE                         = 0x337,
    SMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY_RESPONSE            = 0x39B,
    SMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY_RESPONSE_WRITE_FILE = 0x39C,
    SMSG_IGNORE_REQUIREMENTS_CHEAT                       = 0x3A9,
    SMSG_CLEAR_TARGET                                    = 0x3BF,
    SMSG_CROSSED_INEBRIATION_THRESHOLD                   = 0x3C1,
    SMSG_COMPLAIN_RESULT                                 = 0x3C8,
    SMSG_FEATURE_SYSTEM_STATUS                           = 0x3C9,
    SMSG_DEBUG_LIST_TARGETS                              = 0x3D9,
    SMSG_GOGOGO_OBSOLETE                                 = 0x3F5,
    SMSG_MIRRORIMAGE_DATA                                = 0x402,
    SMSG_FORCE_DISPLAY_UPDATE                            = 0x403,
    SMSG_IGNORE_DIMINISHING_RETURNS_CHEAT                = 0x406,
    SMSG_OVERRIDE_LIGHT                                  = 0x412,
    SMSG_SERVER_BUCK_DATA                                = 0x41D,
    SMSG_PROPOSE_LEVEL_GRANT                             = 0x41F,
    SMSG_UPDATE_ACCOUNT_DATA_COMPLETE                    = 0x463,
    SMSG_SERVER_BUCK_DATA_START                          = 0x4A3,
    SMSG_CLIENTCACHE_VERSION                             = 0x4AB,
    SMSG_SET_PROJECTILE_POSITION                         = 0x4BF,
    SMSG_UNKNOWN_1240                                    = 0x4D8,
    SMSG_TOGGLE_XP_GAIN                                  = 0x4ED,
    SMSG_UNKNOWN_1276                                    = 0x4FC,
    SMSG_UNKNOWN_1295                                    = 0x50F,
    SMSG_FORCE_SEND_QUEUED_PACKETS                       = 0x511,
    SMSG_UNKNOWN_1300                                    = 0x514,
    SMSG_UNKNOWN_1301                                    = 0x515,
    SMSG_UNKNOWN_1310                                    = 0x51E,

    // Fishing
    SMSG_FISH_NOT_HOOKED                                 = 0x1C8,
    SMSG_FISH_ESCAPED                                    = 0x1C9,

    // Voice
    SMSG_VOICE_SESSION_ROSTER_UPDATE                     = 0x39E,
    SMSG_VOICE_SESSION_LEAVE                             = 0x39F,
    SMSG_VOICE_SESSION_ADJUST_PRIORITY                   = 0x3A0,
    SMSG_VOICE_SET_TALKER_MUTED                          = 0x3A2,
    SMSG_VOICE_SESSION_ENABLE                            = 0x3B0,
    SMSG_VOICE_PARENTAL_CONTROLS                         = 0x3B1,
    SMSG_VOICE_CHAT_STATUS                               = 0x3E3,
    SMSG_VOICESESSION_FULL                               = 0x3FC,

    // Commentator
    SMSG_COMMENTATOR_STATE_CHANGED                       = 0x3B6,
    SMSG_COMMENTATOR_MAP_INFO                            = 0x3B8,
    SMSG_COMMENTATOR_GET_PLAYER_INFO                     = 0x3BA,
    SMSG_COMMENTATOR_PLAYER_INFO                         = 0x3BB,
    SMSG_UNKNOWN_1308                                    = 0x51C,
    SMSG_UNKNOWN_1309                                    = 0x51D,

    // Comsat
    SMSG_COMSAT_RECONNECT_TRY                            = 0x3E0,
    SMSG_COMSAT_DISCONNECT                               = 0x3E1,
    SMSG_COMSAT_CONNECT_FAIL                             = 0x3E2,

    /***********************************************************/
    /********************** WORLD OPCODES **********************/
    /***********************************************************/
    SMSG_NEW_WORLD                                       = 0x03E,
    SMSG_UPDATE_OBJECT                                   = 0x0A9,
    SMSG_DESTROY_OBJECT                                  = 0x0AA,
    SMSG_COMPRESSED_UPDATE_OBJECT                        = 0x1F6,
    SMSG_LOGIN_VERIFY_WORLD                              = 0x236,
    SMSG_INIT_WORLD_STATES                               = 0x2C2,
    SMSG_UPDATE_WORLD_STATE                              = 0x2C3,
    SMSG_WEATHER                                         = 0x2F4,
    SMSG_SET_PHASE_SHIFT                                 = 0x47C,
    SMSG_WORLD_STATE_UI_TIMER_UPDATE                     = 0x4F7,
};

extern void ServerOpcodeTable();

#endif
