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
    SMSG_AUTH_CHALLENGE                                  = 0x6019,    // 24601 - 4.0.6.13623
    SMSG_AUTH_RESPONSE                                   = 0xB28C,    // 45708 - 4.0.6.13623
    SMSG_REALM_SPLIT                                     = 0x25EC,    // 9708  - 4.0.6.13623
    SMSG_REDIRECT_CLIENT                                 = 0x201B,    // 8219  - 4.0.6.13623

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
    SMSG_CALENDAR_SEND_CALENDAR                          = 0x436,
    SMSG_CALENDAR_SEND_EVENT                             = 0x437,
    SMSG_CALENDAR_FILTER_GUILD                           = 0x438,
    SMSG_CALENDAR_ARENA_TEAM                             = 0x439,
    SMSG_CALENDAR_EVENT_INVITE                           = 0x43A,
    SMSG_CALENDAR_EVENT_INVITE_REMOVED                   = 0x43B,
    SMSG_CALENDAR_EVENT_STATUS                           = 0x43C,
    SMSG_CALENDAR_COMMAND_RESULT                         = 0xAD80,    // 44416 - 4.0.6.13623
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
    SMSG_CHAR_CREATE                                     = 0xF7EC,    // 63468 - 4.0.6.13623
    SMSG_CHAR_ENUM                                       = 0xECCC,    // 60620 - 4.0.6.13623
    SMSG_CHAR_DELETE                                     = 0xBC80,    // 48256 - 4.0.6.13623
    SMSG_CHARACTER_LOGIN_FAILED                          = 0x7ACC,    // 31436 - 4.0.6.13623
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
    SMSG_MOTD                                            = 0x33D,
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
    SMSG_BREAK_TARGET                                    = 0x152,
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
    // Login
    // Logout
    SMSG_LOGOUT_RESPONSE                                 = 0xF788,    // 63368 - 4.0.6.13623
    SMSG_LOGOUT_COMPLETE                                 = 0xA0A4,    // 41124 - 4.0.6.13623
    SMSG_LOGOUT_CANCEL_ACK                               = 0xEE88,    // 61064 - 4.0.6.13623

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
    SMSG_COMPRESSED_MOVES                                = 0x6FE4,    // 28644 - 4.0.6.13623
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
    SMSG_ADDON_INFO                                      = 0xEA80,    // 60032 - 4.0.6.13623
    SMSG_GHOSTEE_GONE                                    = 0x326,
    SMSG_TITLE_EARNED                                    = 0x6C8C,    // 27788 - 4.0.6.13623
    SMSG_UPDATE_COMBO_POINTS                             = 0x39D,
    SMSG_CHEAT_PLAYER_LOOKUP                             = 0x3C4,
    SMSG_KICK_REASON                                     = 0xEAC8,    // 60104 - 4.0.6.13623
    SMSG_SET_PLAYER_DECLINED_NAMES_RESULT                = 0xBAAC,    // 47788 - 4.0.6.13623
    SMSG_HIGHEST_THREAT_UPDATE                           = 0x482,
    SMSG_THREAT_UPDATE                                   = 0xB480,    // 46208 - 4.0.6.13623
    SMSG_THREAT_REMOVE                                   = 0x29E0,    // 10720 - 4.0.6.13623
    SMSG_THREAT_CLEAR                                    = 0xFFC8,    // 65480 - 4.0.6.13623

    // Player Dance
    SMSG_NOTIFY_DANCE                                    = 0x44A,
    SMSG_PLAY_DANCE                                      = 0x44C,
    SMSG_STOP_DANCE                                      = 0x44F,
    SMSG_DANCE_QUERY_RESPONSE                            = 0x452,
    SMSG_INVALIDATE_DANCE                                = 0x453,
    SMSG_LEARNED_DANCE_MOVES                             = 0x455,

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
    SMSG_PET_ACTION_SOUND                                = 0x30E4,    // 12516 - 4.0.6.13623
    SMSG_PET_DISMISS_SOUND                               = 0xB7E0,    // 47072 - 4.0.6.13623

    // Player PVP / Honor / Arena
    SMSG_PVP_CREDIT                                      = 0xA68C,    // 46636 - 4.0.6.13623
    SMSG_ARENA_TEAM_COMMAND_RESULT                       = 0x349,
    SMSG_ARENA_TEAM_QUERY_RESPONSE                       = 0x34C,
    SMSG_ARENA_TEAM_ROSTER                               = 0xB4A8,    // 46248 - 4.0.6.13623
    SMSG_ARENA_TEAM_INVITE                               = 0x63A0,    // 25504 - 4.0.6.13623
    SMSG_ARENA_TEAM_EVENT                                = 0x74C4,    // 29892 - 4.0.6.13623
    SMSG_ARENA_TEAM_STATS                                = 0xAFAC,    // 44971 - 4.0.6.13623
    SMSG_ARENA_ERROR                                     = 0x2FEC,    // 12268 - 4.0.6.13623
    SMSG_REPORT_PVP_AFK_RESULT                           = 0x78E8,    // 30952 - 4.0.6.13623
    SMSG_ARENA_OPPONENT_UPDATE                           = 0x28CC,    // 10444 - 4.0.6.13623
    SMSG_ARENA_TEAM_CHANGE_FAILED_QUEUED                 = 0xBFA0,    // 49056 - 4.0.6.13623

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
    SMSG_HEALTH_UPDATE                                   = 0x2AA8,    // 10920 - 4.0.6.13623
    SMSG_POWER_UPDATE                                    = 0x65E8,    // 26088 - 4.0.6.13623
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
    SMSG_QUEST_POI_QUERY_RESPONSE                        = 0x6AEC,    // 27372 - 4.0.6.13623
    SMSG_CORPSE_MAP_POSITION_QUERY_RESPONSE              = 0x4B7,
    SMSG_QUERY_QUESTS_COMPLETED_RESPONSE                 = 0xF1E8,    // 61928 - 4.0.6.13623

    /***********************************************************/
    /********************* QUEST OPCODES ***********************/
    /***********************************************************/
    SMSG_QUESTLOG_FULL                                   = 0x618C,    // 24972 - 4.0.6.13623
    SMSG_QUEST_FORCE_REMOVED                             = 0x34E8,    // 13544 - 4.0.6.13623
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
    SMSG_CANCEL_AUTO_REPEAT                              = 0x3DE0,    // 15840 - 4.0.6.13623
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
    SMSG_AI_REACTION                                     = 0x31CC,    // 12748 - 4.0.6.13623
    SMSG_CLIENT_CONTROL_UPDATE                           = 0x3C84,    // 15492 - 4.0.6.13623
    SMSG_FLIGHT_SPLINE_SYNC                              = 0xBFAC,    // 49068 - 4.0.6.13623
    SMSG_SHOW_BANK                                       = 0x1B8,
    SMSG_NOTIFICATION                                    = 0xBC88,    // 48264 - 4.0.6.13623
    SMSG_LOG_XPGAIN                                      = 0xB880,    // 47232 - 4.0.6.13623
    SMSG_LEVELUP_INFO                                    = 0xB9C4,    // 47556 - 4.0.6.13623
    SMSG_START_MIRROR_TIMER                              = 0xA68C,    // 42636 - 4.0.6.13623
    SMSG_PAUSE_MIRROR_TIMER                              = 0x21EC,    // 8684  - 4.0.6.13623
    SMSG_STOP_MIRROR_TIMER                               = 0xB4A8,    // 46248 - 4.0.6.13623
    SMSG_PONG                                            = 0xB880,    // 47232 - 4.0.6.13623
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
    SMSG_WARDEN_DATA                                     = 0x2E6,
    SMSG_INVALIDATE_PLAYER                               = 0x31C,
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
    SMSG_MIRRORIMAGE_DATA                                = 0xE2A4,    // 58020 - 4.0.6.13623
    SMSG_FORCE_DISPLAY_UPDATE                            = 0x6788,    // 26504 - 4.0.6.13623
    SMSG_IGNORE_DIMINISHING_RETURNS_CHEAT                = 0x78E8,    // 30952 - 4.0.6.13623
    SMSG_OVERRIDE_LIGHT                                  = 0x2388,    // 9096  - 4.0.6.13623
    SMSG_SERVER_BUCK_DATA                                = 0x41D,
    SMSG_PROPOSE_LEVEL_GRANT                             = 0xB8C8,    // 47304 - 4.0.6.13623
    SMSG_UPDATE_ACCOUNT_DATA_COMPLETE                    = 0xB1CC,    // 45516 - 4.0.6.13623
    SMSG_SERVER_BUCK_DATA_START                          = 0x4A3,
    SMSG_CLIENTCACHE_VERSION                             = 0x2EC4,    // 11972 - 4.0.6.13623
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
    SMSG_NEW_WORLD                                       = 0x451E,    // 17694 - 4.0.6.13623
    SMSG_UPDATE_OBJECT                                   = 0x3780,    // 14208 - 4.0.6.13623
    SMSG_DESTROY_OBJECT                                  = 0x2AA0,    // 10912 - 4.0.6.13623
    SMSG_COMPRESSED_UPDATE_OBJECT                        = 0xEAC0,    // 60096 - 4.0.6.13623
    SMSG_LOGIN_VERIFY_WORLD                              = 0x28C0,    // 10432 - 4.0.6.13623
    SMSG_INIT_WORLD_STATES                               = 0xF6E8,    // 63208 - 4.0.6.13623
    SMSG_UPDATE_WORLD_STATE                              = 0xF784,    // 63364 - 4.0.6.13623
    SMSG_WEATHER                                         = 0x00,
    SMSG_SET_PHASE_SHIFT                                 = 0x22ED,    // 8941 -  4.0.6.13623
    SMSG_WORLD_STATE_UI_TIMER_UPDATE                     = 0x698C,    // 27020 - 4.0.6.13623
};

extern void ServerOpcodeTable();

class WorldPacket;

struct ServerOpcodeHandler
{
    char const* name;
    SessionStatus status;
    PacketProcessing packetProcessing;
    void (WorldSession::*handler)(WorldPacket& recvPacket);
};

extern ServerOpcodeHandler serverOpcodeTable[NUM_MSG_TYPES];

inline const char* LookupServerOpcodeName(uint32 opcodeValue)
{
    if (opcodeValue >= NUM_MSG_TYPES)
        return "Received to big opcode: " + opcodeValue;

    return serverOpcodeTable[opcodeValue].name;
}

#endif
