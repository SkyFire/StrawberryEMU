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

#ifndef CLIENT_OPCODES
#define CLIENT_OPCODES

/**
* Declaration of Opcode values.
* Ordered by Category and value.
*/
enum ClientOpcodes
{
    /***********************************************************/
    /********************* ATTACK OPCODES **********************/
    /***********************************************************/
    CMSG_ATTACKSWING                                     = 0x74A8,    // 29864 - 4.0.6a 13623
    CMSG_ATTACKSTOP                                      = 0x62C4,    // 25284 - 4.0.6a 13623

    /***********************************************************/
    /******************** AUCTION OPCODES **********************/
    /***********************************************************/
    CMSG_AUCTION_SELL_ITEM                               = 0xEE8C,    // 61068 - 4.0.6a 13623
    CMSG_AUCTION_REMOVE_ITEM                             = 0x9F5D,    // 40797 - 4.0.6a 13623
    CMSG_AUCTION_LIST_ITEMS                              = 0xE48C,    // 58508 - 4.0.6a 13623
    CMSG_AUCTION_LIST_OWNER_ITEMS                        = 0x100BC,   // 65724 - 4.0.6a 13623
    CMSG_AUCTION_PLACE_BID                               = 0x8777,    // 34679 - 4.0.6a 13623
    CMSG_AUCTION_LIST_BIDDER_ITEMS                       = 0x100BE,   // 65726 - 4.0.6a 13623
    CMSG_AUCTION_LIST_PENDING_SALES                      = 0x48F,

    /***********************************************************/
    /***************** AUTHENTICATION OPCODES ******************/
    /***********************************************************/
    CMSG_AUTH_SESSION                                    = 0x0E0E,    // 3598 - 4.0.6a 13623
    CMSG_REALM_SPLIT                                     = 0x38C,
    CMSG_REDIRECTION_FAILED                              = 0x0509,    // - 4.0.6a 13623
    CMSG_UNKNOWN_1296                                    = 0x510,
    CMSG_REDIRECTION_AUTH_PROOF                          = 0x0E4C,    // 3660 - 4.0.6.13529

    // SRP6
    CMSG_AUTH_SRP6_BEGIN                                 = 0x033,
    CMSG_AUTH_SRP6_PROOF                                 = 0x034,
    CMSG_AUTH_SRP6_RECODE                                = 0x035,

    /***********************************************************/
    /******************* BATTLEFIELD OPCODES *******************/
    /***********************************************************/
    CMSG_BATTLEFIELD_LIST                                = 0x23C,
    CMSG_BATTLEFIELD_JOIN                                = 0x23E,
    CMSG_BATTLEFIELD_STATUS                              = 0x2D3,
    CMSG_BATTLEFIELD_PORT                                = 0x2D5,
    CMSG_BATTLEMASTER_HELLO                              = 0x2D7,
    CMSG_LEAVE_BATTLEFIELD                               = 0x2E1,
    CMSG_BATTLEMASTER_JOIN_ARENA                         = 0x358,
    CMSG_BATTLEFIELD_MGR_ENTRY_INVITE_RESPONSE           = 0x4DF,
    CMSG_BATTLEFIELD_MGR_QUEUE_INVITE_RESPONSE           = 0x4E2,
    CMSG_BATTLEFIELD_MGR_QUEUE_REQUEST                   = 0x4E3,
    CMSG_BATTLEFIELD_MGR_EXIT_REQUEST                    = 0x4E7,

    /***********************************************************/
    /******************** CALENDAR OPCODES *********************/
    /***********************************************************/
    CMSG_CALENDAR_GET_CALENDAR                           = 0x101B4,    // 65972 - 4.0.6a 13623
    CMSG_CALENDAR_GET_EVENT                              = 0x101B5,    // 65973 - 4.0.6a 13623
    CMSG_CALENDAR_GUILD_FILTER                           = 0x101B6,    // 65974 - 4.0.6a 13623
    CMSG_CALENDAR_ARENA_TEAM                             = 0x101B7,    // 65975 - 4.0.6a 13623
    CMSG_CALENDAR_ADD_EVENT                              = 0x0F488,    // 62600 - 4.0.6a 13623
    CMSG_CALENDAR_UPDATE_EVENT                           = 0x101B8,    // 65976 - 4.0.6a 13623
    CMSG_CALENDAR_REMOVE_EVENT                           = 0x04C5F,    // 19551 - 4.0.6a 13623
    CMSG_CALENDAR_COPY_EVENT                             = 0x101BA,    // 65978 - 4.0.6a 13623
    CMSG_CALENDAR_EVENT_INVITE                           = 0x0F6C4,    // 63172 - 4.0.6a 13623
    CMSG_CALENDAR_EVENT_RSVP                             = 0x0757F,    // 30079 - 4.0.6a 13623
    CMSG_CALENDAR_EVENT_REMOVE_INVITE                    = 0x101BD,    // 65981 - 4.0.6a 13623
    CMSG_CALENDAR_EVENT_STATUS                           = 0x101BE,    // 65982 - 4.0.6a 13623
    CMSG_CALENDAR_EVENT_MODERATOR_STATUS                 = 0x101BF,    // 65983 - 4.0.6a 13623
    CMSG_CALENDAR_COMPLAIN                               = 0x01E75,    // 7797  - 4.0.6a 13623
    CMSG_CALENDAR_GET_NUM_PENDING                        = 0x0EFAC,    // 61356 - 4.0.6a 13623
    CMSG_CALENDAR_CONTEXT_EVENT_SIGNUP                   = 0xDC74,     // - 4.0.3.13329

    /***********************************************************/
    /******************** CHARACTER OPCODES ********************/
    /***********************************************************/
    CMSG_MOVE_CHARACTER_CHEAT                            = 0x00D,
    CMSG_CHAR_CREATE                                     = 0x036,
    CMSG_CHAR_ENUM                                       = 0x037,
    CMSG_CHAR_DELETE                                     = 0x038,
    CMSG_CHARACTER_POINT_CHEAT                           = 0x223,
    CMSG_CHAR_RENAME                                     = 0x2C7,
    CMSG_CHAR_CUSTOMIZE                                  = 0x473,
    CMSG_CHAR_FACTION_CHANGE                             = 0x4D9,
    CMSG_CHAR_RACE_CHANGE                                = 0x4F8,

    // Character World Login / Logout
    CMSG_PLAYER_LOGIN                                    = 0x03D,
    CMSG_PLAYER_LOGOUT                                   = 0x04A,
    CMSG_LOGOUT_REQUEST                                  = 0x04B,
    CMSG_LOGOUT_CANCEL                                   = 0x04E,

    /***********************************************************/
    /********************** CHAT OPCODES ***********************/
    /***********************************************************/
    CMSG_CHAT_IGNORED                                    = 0x225,
    CMSG_GM_VISION                                       = 0x226,
    CMSG_CHAT_FILTERED                                   = 0x331,
    CMSG_GM_WHISPER                                      = 0x3B2,
    CMSG_FORCE_SAY_CHEAT                                 = 0x47E,

    // Chat Message
    CMSG_MESSAGECHAT_SAY                                 = 0x002A,    // 42    - 4.0.6.13623
    CMSG_MESSAGECHAT_YELL                                = 0x0802,    // 2050  - 4.0.6.13623
    CMSG_MESSAGECHAT_CHANNEL                             = 0x3A88,    // 14984 - 4.0.3.13329
    CMSG_MESSAGECHAT_WHISPER                             = 0x0000,    // 0     - 4.0.6.13623
    CMSG_MESSAGECHAT_GUILD                               = 0x0823,    // 2083  - 4.0.6.13623
    CMSG_MESSAGECHAT_OFFICER                             = 0x0861,    // 2145  - 4.0.6.13623
    CMSG_MESSAGECHAT_AFK                                 = 0x086B,    // 2155  - 4.0.6.13623
    CMSG_MESSAGECHAT_DND                                 = 0x0003,    // 3     - 4.0.6.13623
    CMSG_MESSAGECHAT_EMOTE                               = 0x0042,    // 66    - 4.0.6.13623
    CMSG_MESSAGECHAT_PARTY                               = 0x2A08,    // 10760 - 4.0.3.13329
    CMSG_MESSAGECHAT_PARTY_LEADER                        = 0x6A18,    // 52573 - 4.0.3.13329
    CMSG_MESSAGECHAT_RAID                                = 0x7A90,    // 27160 - 4.0.3.13329
    CMSG_MESSAGECHAT_RAID_LEADER                         = 0x4A80,    // 19072 - 4.0.3.13329
    CMSG_MESSAGECHAT_BATTLEGROUND                        = 0x1A10,    // 6672  - 4.0.3.13329
    CMSG_MESSAGECHAT_BATTLEGROUND_LEADER                 = 0x7A80,    // 31360 - 4.0.3.13329
    CMSG_MESSAGECHAT_RAID_WARNING                        = 0x4A88,    // 19080 - 4.0.3.13329

    // Channel
    CMSG_JOIN_CHANNEL                                    = 0x097,
    CMSG_LEAVE_CHANNEL                                   = 0x098,
    CMSG_CHANNEL_LIST                                    = 0x09A,
    CMSG_CHANNEL_PASSWORD                                = 0x09C,
    CMSG_CHANNEL_SET_OWNER                               = 0x09D,
    CMSG_CHANNEL_OWNER                                   = 0x09E,
    CMSG_CHANNEL_MODERATOR                               = 0x09F,
    CMSG_CHANNEL_UNMODERATOR                             = 0x0A0,
    CMSG_CHANNEL_MUTE                                    = 0x0A1,
    CMSG_CHANNEL_UNMUTE                                  = 0x0A2,
    CMSG_CHANNEL_INVITE                                  = 0x0A3,
    CMSG_CHANNEL_KICK                                    = 0x0A4,
    CMSG_CHANNEL_BAN                                     = 0x0A5,
    CMSG_CHANNEL_UNBAN                                   = 0x0A6,
    CMSG_CHANNEL_ANNOUNCEMENTS                           = 0x0A7,
    CMSG_CHANNEL_MODERATE                                = 0x0A8,
    CMSG_CHANNEL_SILENCE_VOICE                           = 0x3CC,
    CMSG_CHANNEL_SILENCE_ALL                             = 0x3CD,
    CMSG_CHANNEL_UNSILENCE_VOICE                         = 0x3CE,
    CMSG_CHANNEL_UNSILENCE_ALL                           = 0x3CF,
    CMSG_CHANNEL_DISPLAY_LIST                            = 0x3D2,
    CMSG_GET_CHANNEL_MEMBER_COUNT                        = 0x3D4,
    CMSG_SET_CHANNEL_WATCH                               = 0x3EF,
    CMSG_CLEAR_CHANNEL_WATCH                             = 0x3F3,
    CMSG_DECLINE_CHANNEL_INVITE                          = 0x410,

    // Char Server Message
    CMSG_SERVER_BROADCAST                                = 0x2B2,
    CMSG_SERVER_INFO_QUERY                               = 0x4A0,

    /***********************************************************/
    /********************* COMBAT OPCODES **********************/
    /***********************************************************/
    CMSG_ENABLE_DAMAGE_LOG                               = 0x27D,

    /***********************************************************/
    /********************** DUEL OPCODES ***********************/
    /***********************************************************/
    CMSG_DUEL_ACCEPTED                                   = 0x16C,
    CMSG_DUEL_CANCELLED                                  = 0x16D,

    /***********************************************************/
    /******************** FACTION OPCODES **********************/
    /***********************************************************/
    CMSG_SET_FACTION_ATWAR                               = 0x125,
    CMSG_SET_FACTION_CHEAT                               = 0x126,
    CMSG_SET_ACTION_BUTTON                               = 0x128,
    CMSG_RESET_FACTION_CHEAT                             = 0x281,
    CMSG_SET_FACTION_INACTIVE                            = 0x317,
    CMSG_SET_WATCHED_FACTION                             = 0x318,

    /***********************************************************/
    /******************* GAMEMASTER OPCODES ********************/
    /***********************************************************/
    CMSG_GM_INVIS                                        = 0x1E6,
    CMSG_GM_SET_SECURITY_GROUP                           = 0x1F9,
    CMSG_GM_NUKE                                         = 0x1FA,
    CMSG_GM_TEACH                                        = 0x20F,
    CMSG_GM_CREATE_ITEM_TARGET                           = 0x210,
    CMSG_GM_SILENCE                                      = 0x228,
    CMSG_GM_REVEALTO                                     = 0x229,
    CMSG_GM_RESURRECT                                    = 0x22A,
    CMSG_GM_SUMMONMOB                                    = 0x22B,
    CMSG_GM_MOVECORPSE                                   = 0x22C,
    CMSG_GM_FREEZE                                       = 0x22D,
    CMSG_GM_UBERINVIS                                    = 0x22E,
    CMSG_GM_REQUEST_PLAYER_INFO                          = 0x22F,
    CMSG_GM_UNTEACH                                      = 0x2E5,
    CMSG_GM_NUKE_ACCOUNT                                 = 0x30F,
    CMSG_GM_DESTROY_ONLINE_CORPSE                        = 0x311,
    CMSG_MAELSTROM_GM_SENT_MAIL                          = 0x395,
    CMSG_GM_SHOW_COMPLAINTS                              = 0x3CA,
    CMSG_GM_UNSQUELCH                                    = 0x3CB,
    CMSG_GM_CHARACTER_RESTORE                            = 0x3FA,
    CMSG_GM_CHARACTER_SAVE                               = 0x3FB,
    CMSG_GMRESPONSE_RESOLVE                              = 0x4F0,
    CMSG_GM_REPORT_LAG                                   = 0x502,

    // Gamemaster Ticket
    CMSG_GMTICKET_CREATE                                 = 0x205,
    CMSG_GMTICKET_UPDATETEXT                             = 0x207,
    CMSG_GMTICKET_GETTICKET                              = 0x211,
    CMSG_GMTICKET_DELETETICKET                           = 0x217,
    CMSG_GMTICKET_SYSTEMSTATUS                           = 0x21A,
    CMSG_GMTICKETSYSTEM_TOGGLE                           = 0x29A,
    CMSG_GM_UPDATE_TICKET_STATUS                         = 0x327,
    CMSG_GMSURVEY_SUBMIT                                 = 0x32A,

    /***********************************************************/
    /****************** (GAME)OBJECT OPCODES *******************/
    /***********************************************************/
    CMSG_QUERY_OBJECT_POSITION                           = 0x004,
    CMSG_QUERY_OBJECT_ROTATION                           = 0x006,
    CMSG_CREATEGAMEOBJECT                                = 0x014,
    CMSG_GAMEOBJ_USE                                     = 0x0B1,
    CMSG_GAMEOBJ_REPORT_USE                              = 0x481,
    CMSG_DUMP_OBJECTS                                    = 0x48B,

    /***********************************************************/
    /********************** GOSSIP OPCODES *********************/
    /***********************************************************/
    CMSG_GOSSIP_HELLO                                    = 0x17B,
    CMSG_GOSSIP_SELECT_OPTION                            = 0x17C,
    CMSG_NPC_TEXT_QUERY                                  = 0x17F,
    CMSG_BATTLEMASTER_JOIN                               = 0x2EE,

    // Gossip Questgiver
    CMSG_QUESTGIVER_STATUS_QUERY                         = 0x182,
    CMSG_QUESTGIVER_HELLO                                = 0x184,
    CMSG_QUESTGIVER_QUERY_QUEST                          = 0x186,
    CMSG_QUESTGIVER_QUEST_AUTOLAUNCH                     = 0x187,
    CMSG_QUESTGIVER_ACCEPT_QUEST                         = 0x189,
    CMSG_QUESTGIVER_COMPLETE_QUEST                       = 0x18A,
    CMSG_QUESTGIVER_REQUEST_REWARD                       = 0x18C,
    CMSG_QUESTGIVER_CHOOSE_REWARD                        = 0x18E,
    CMSG_QUESTGIVER_CANCEL                               = 0x190,

    // Gossip Trainer
    CMSG_TRAINER_LIST                                    = 0x1B0,
    CMSG_TRAINER_BUY_SPELL                               = 0x1B2,

    /***********************************************************/
    /********************** GROUP OPCODES **********************/
    /***********************************************************/
    CMSG_GROUP_INVITE                                    = 0x06E,
    CMSG_GROUP_CANCEL                                    = 0x070,
    CMSG_GROUP_ACCEPT                                    = 0x072,
    CMSG_GROUP_DECLINE                                   = 0x073,
    CMSG_GROUP_UNINVITE                                  = 0x075,
    CMSG_GROUP_UNINVITE_GUID                             = 0x076,
    CMSG_GROUP_SET_LEADER                                = 0x078,
    CMSG_GROUP_DISBAND                                   = 0x07B,
    CMSG_GROUP_CHANGE_SUB_GROUP                          = 0x27E,
    CMSG_GROUP_SWAP_SUB_GROUP                            = 0x280,
    CMSG_GROUP_RAID_CONVERT                              = 0x28E,
    CMSG_GROUP_ASSISTANT_LEADER                          = 0x28F,

    /***********************************************************/
    /********************** GUILD OPCODES **********************/
    /***********************************************************/
    CMSG_GUILD_CREATE                                    = 0x081,
    CMSG_GUILD_INVITE                                    = 0x082,
    CMSG_GUILD_ACCEPT                                    = 0x084,
    CMSG_GUILD_DECLINE                                   = 0x085,
    CMSG_GUILD_INFO                                      = 0x087,
    CMSG_GUILD_ROSTER                                    = 0x089,
    CMSG_GUILD_PROMOTE                                   = 0x08B,
    CMSG_GUILD_DEMOTE                                    = 0x08C,
    CMSG_GUILD_LEAVE                                     = 0x08D,
    CMSG_GUILD_REMOVE                                    = 0x08E,
    CMSG_GUILD_DISBAND                                   = 0x08F,
    CMSG_GUILD_LEADER                                    = 0x090,
    CMSG_GUILD_MOTD                                      = 0x091,
    CMSG_GUILD_RANK                                      = 0x231,
    CMSG_GUILD_ADD_RANK                                  = 0x232,
    CMSG_GUILD_DEL_RANK                                  = 0x233,
    CMSG_GUILD_SET_PUBLIC_NOTE                           = 0x234,
    CMSG_GUILD_SET_OFFICER_NOTE                          = 0x235,
    CMSG_GUILD_INFO_TEXT                                 = 0x2FC,
    CMSG_MAELSTROM_RENAME_GUILD                          = 0x400,

    // Guild Bank
    CMSG_GUILD_BANKER_ACTIVATE                           = 0x3E6,
    CMSG_GUILD_BANK_QUERY_TAB                            = 0x3E7,
    CMSG_GUILD_BANK_SWAP_ITEMS                           = 0x3E9,
    CMSG_GUILD_BANK_BUY_TAB                              = 0x3EA,
    CMSG_GUILD_BANK_UPDATE_TAB                           = 0x3EB,
    CMSG_GUILD_BANK_DEPOSIT_MONEY                        = 0x3EC,
    CMSG_GUILD_BANK_WITHDRAW_MONEY                       = 0x3ED,
    CMSG_SET_GUILD_BANK_TEXT                             = 0x40B,

    // Guild Petition
    CMSG_PETITION_SHOWLIST                               = 0x1BB,
    CMSG_PETITION_BUY                                    = 0x1BD,
    CMSG_PETITION_SHOW_SIGNATURES                        = 0x1BE,
    CMSG_PETITION_SIGN                                   = 0x1C0,
    CMSG_OFFER_PETITION                                  = 0x1C3,
    CMSG_TURN_IN_PETITION                                = 0x1C4,
    CMSG_PETITION_QUERY                                  = 0x1C6,

    // Guild Party
    CMSG_REQUEST_PARTY_MEMBER_STATS                      = 0x27F,
    CMSG_PARTY_SILENCE                                   = 0x3DD,
    CMSG_PARTY_UNSILENCE                                 = 0x3DE,

    /***********************************************************/
    /******************** INSTANCE OPCODES *********************/
    /***********************************************************/
    CMSG_INSTANCE_LOCK_WARNING_RESPONSE                  = 0x13F,
    CMSG_REQUEST_RAID_INFO                               = 0x2CD,
    CMSG_EXPIRE_RAID_INSTANCE                            = 0x415,
    CMSG_SET_ALLOW_LOW_LEVEL_RAID1                       = 0x508,
    CMSG_SET_ALLOW_LOW_LEVEL_RAID2                       = 0x509,

    // LFG
    CMSG_LFG_JOIN                                        = 0x35C,
    CMSG_LFG_LEAVE                                       = 0x35D,
    CMSG_SEARCH_LFG_JOIN                                 = 0x35E,
    CMSG_SEARCH_LFG_LEAVE                                = 0x35F,
    CMSG_LFG_PROPOSAL_RESULT                             = 0x362,
    CMSG_SET_LFG_COMMENT                                 = 0x366,
    CMSG_LFG_SET_ROLES                                   = 0x36A,
    CMSG_LFG_SET_NEEDS                                   = 0x36B,
    CMSG_LFG_SET_BOOT_VOTE                               = 0x36C,
    CMSG_LFD_PLAYER_LOCK_INFO_REQUEST                    = 0x36E,
    CMSG_LFG_TELEPORT                                    = 0x370,
    CMSG_LFD_PARTY_LOCK_INFO_REQUEST                     = 0x371,

    // Meetingstone
    CMSG_MEETINGSTONE_INFO                               = 0x296,
    CMSG_MEETINGSTONE_CHEAT                              = 0x294,

    /***********************************************************/
    /********************** ITEM OPCODES ***********************/
    /***********************************************************/
    CMSG_CREATEITEM                                      = 0x013,
    CMSG_USE_ITEM                                        = 0x0AB,
    CMSG_OPEN_ITEM                                       = 0x0AC,
    CMSG_READ_ITEM                                       = 0x0AD,
    CMSG_DESTROY_ITEMS                                   = 0x0B2,
    CMSG_SWAP_ITEM                                       = 0x10C,
    CMSG_SWAP_INV_ITEM                                   = 0x10D,
    CMSG_SPLIT_ITEM                                      = 0x10E,
    OBSOLETE_DROP_ITEM                                   = 0x110,
    CMSG_DESTROYITEM                                     = 0x111,
    CMSG_SELL_ITEM                                       = 0x1A0,
    CMSG_BUY_ITEM                                        = 0x1A2,
    CMSG_BUY_ITEM_IN_SLOT                                = 0x1A3,
    CMSG_WRAP_ITEM                                       = 0x1D3,  
    CMSG_SET_DURABILITY_CHEAT                            = 0x287,
    CMSG_BUYBACK_ITEM                                    = 0x290,
    CMSG_REPAIR_ITEM                                     = 0x2A8,
    CMSG_SHOWING_HELM                                    = 0x2B9,
    CMSG_SHOWING_CLOAK                                   = 0x2BA,
    CMSG_SOCKET_GEMS                                     = 0x347,
    CMSG_CANCEL_TEMP_ENCHANTMENT                         = 0x379,
    CMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY                     = 0x39A,
    CMSG_UPDATE_MISSILE_TRAJECTORY                       = 0x462,
    CMSG_ITEM_REFUND_INFO                                = 0x4B3,
    CMSG_ITEM_REFUND                                     = 0x4B4,
    CMSG_UPDATE_PROJECTILE_POSITION                      = 0x4BE,

    // Item Equipment
    CMSG_AUTOEQUIP_GROUND_ITEM                           = 0x106,
    CMSG_AUTOSTORE_GROUND_ITEM                           = 0x107,
    CMSG_AUTOSTORE_LOOT_ITEM                             = 0x108,
    CMSG_AUTOEQUIP_ITEM                                  = 0x10A,
    CMSG_AUTOSTORE_BAG_ITEM                              = 0x10B,
    CMSG_AUTOEQUIP_ITEM_SLOT                             = 0x10F,
    CMSG_EQUIPMENT_SET_DELETE                            = 0x13E,
    CMSG_AUTOSTORE_BANK_ITEM                             = 0x282,
    CMSG_AUTOBANK_ITEM                                   = 0x283,
    CMSG_EQUIPMENT_SET_SAVE                              = 0x4BD,
    CMSG_EQUIPMENT_SET_USE                               = 0x4D5,

    // Inventory / Trade
    CMSG_INSPECT                                         = 0x114,
    CMSG_INITIATE_TRADE                                  = 0x116,
    CMSG_BEGIN_TRADE                                     = 0x117,
    CMSG_BUSY_TRADE                                      = 0x118,
    CMSG_IGNORE_TRADE                                    = 0x119,
    CMSG_ACCEPT_TRADE                                    = 0x11A,
    CMSG_UNACCEPT_TRADE                                  = 0x11B,
    CMSG_CANCEL_TRADE                                    = 0x11C,
    CMSG_SET_TRADE_ITEM                                  = 0x11D,
    CMSG_CLEAR_TRADE_ITEM                                = 0x11E,
    CMSG_SET_TRADE_GOLD                                  = 0x11F,
    CMSG_LIST_INVENTORY                                  = 0x19E,
    

    /***********************************************************/
    /********************** LOOT OPCODES ***********************/
    /***********************************************************/
    CMSG_LOOT_METHOD                                     = 0x07A,
    CMSG_STORE_LOOT_IN_SLOT                              = 0x109,
    CMSG_LOOT                                            = 0x15D,
    CMSG_LOOT_MONEY                                      = 0x15E,
    CMSG_LOOT_RELEASE                                    = 0x15F,
    CMSG_OPT_OUT_OF_LOOT                                 = 0x409,

    // Loot Group
    CMSG_LOOT_ROLL                                       = 0x2A0,
    CMSG_LOOT_MASTER_GIVE                                = 0x2A3,
    /***********************************************************/
    /******************** MOVEMENT OPCODES *********************/
    /***********************************************************/
    CMSG_MOVE_SET_RAW_POSITION                           = 0x0E1,
    CMSG_MOVE_KNOCK_BACK_ACK                             = 0x0F0,
    CMSG_MOVE_HOVER_ACK                                  = 0x0F6,
    CMSG_MOVE_TIME_SKIPPED                               = 0x2CE,
    CMSG_MOVE_NOT_ACTIVE_MOVER                           = 0x2D1,
    CMSG_MINIGAME_MOVE                                   = 0x2F8,
    CMSG_MOVE_CHNG_TRANSPORT                             = 0x38D,
    CMSG_UNKNOWN_1303                                    = 0x517,

    // Movement Start / Stop
    CMSG_MOVE_START_SWIM_CHEAT                           = 0x2D8,
    CMSG_MOVE_STOP_SWIM_CHEAT                            = 0x2D9,

    // Movement Force
    CMSG_FORCE_RUN_SPEED_CHANGE_ACK                      = 0x0E3,
    CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK                 = 0x0E5,
    CMSG_FORCE_SWIM_SPEED_CHANGE_ACK                     = 0x0E7,
    CMSG_FORCE_MOVE_ROOT_ACK                             = 0x0E9,
    CMSG_FORCE_MOVE_UNROOT_ACK                           = 0x0EB,
    CMSG_FORCE_WALK_SPEED_CHANGE_ACK                     = 0x2DB,
    CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK                = 0x2DD,
    CMSG_FORCE_TURN_RATE_CHANGE_ACK                      = 0x2DF,
    CMSG_FORCE_FLIGHT_SPEED_CHANGE_ACK                   = 0x382,
    CMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK              = 0x384,
    CMSG_FORCE_PITCH_RATE_CHANGE_ACK                     = 0x45D,
    CMSG_FORCE_UNK1_SPEED_CHANGE_ACK                     = 0x4CF,
    CMSG_FORCE_UNK2_SPEED_CHANGE_ACK                     = 0x4D1,

    // Movement Teleport / Fall / Fly / Water
    CMSG_MOVE_FALL_RESET                                 = 0x2CA,
    CMSG_MOVE_FEATHER_FALL_ACK                           = 0x2CF,
    CMSG_MOVE_WATER_WALK_ACK                             = 0x2D0,
    CMSG_MOVE_FLIGHT_ACK                                 = 0x340,

    // Movement Set / Unset
    CMSG_MOVE_SET_CAN_FLY_ACK                            = 0x345,
    CMSG_MOVE_SET_FLY                                    = 0x346,
    CMSG_MOVE_SET_RUN_SPEED                              = 0x3AB,

    // Spline
    CMSG_MOVE_SPLINE_DONE                                = 0x2C9,

    // Spline Set / Unset

    /***********************************************************/
    /********************* MOVIE OPCODES ***********************/
    /***********************************************************/
    // Cinematic
    CMSG_TRIGGER_CINEMATIC_CHEAT                         = 0x0F8,
    CMSG_OPENING_CINEMATIC                               = 0x0F9,
    CMSG_NEXT_CINEMATIC_CAMERA                           = 0x0FB,
    CMSG_COMPLETE_CINEMATIC                              = 0x0FC,

    // Movie
    CMSG_COMPLETE_MOVIE                                  = 0x465,

    /***********************************************************/
    /****************** MOUNT / PET OPCODES ********************/
    /***********************************************************/
    CMSG_MOUNTSPECIAL_ANIM                               = 0x171,
    CMSG_CANCEL_MOUNT_AURA                               = 0x375,    

    // Pet
    CMSG_PET_SET_ACTION                                  = 0x174,
    CMSG_PET_ACTION                                      = 0x175,
    CMSG_PET_ABANDON                                     = 0x176,
    CMSG_PET_RENAME                                      = 0x177,
    CMSG_PET_STOP_ATTACK                                 = 0x2EA,
    CMSG_PET_UNLEARN                                     = 0x2F0,
    CMSG_PET_LEARN_TALENT                                = 0x47A,
    CMSG_PET_UNLEARN_TALENTS                             = 0x47B,

    /***********************************************************/
    /********************* PLAYER OPCODES **********************/
    /***********************************************************/
    CMSG_UNDRESSPLAYER                                   = 0x020,
    CMSG_GODMODE                                         = 0x022,
    CMSG_PLAYER_DIFFICULTY_CHANGE                        = 0x1FD,
    CMSG_PLAYER_AI_CHEAT                                 = 0x26C,
    CMSG_SET_ACTIONBAR_TOGGLES                           = 0x2BF,
    CMSG_IGNORE_REQUIREMENTS_CHEAT                       = 0x3A8,
    CMSG_SET_PLAYER_DECLINED_NAMES                       = 0x419,

    // Player Achievement
    CMSG_QUERY_INSPECT_ACHIEVEMENTS                      = 0x46B,
    CMSG_COMPLETE_ACHIEVEMENT_CHEAT                      = 0x46E,
    CMSG_SET_CRITERIA_CHEAT                              = 0x470,
    CMSG_CHECK_LOGIN_CRITERIA                            = 0x4A2,

    // Player Exploration
    CMSG_SET_EXPLORATION                                 = 0x2BE,
    CMSG_SET_EXPLORATION_ALL                             = 0x31B,

    // Friends / Contacts / ...
    CMSG_WHO                                             = 0x062,
    CMSG_WHOIS                                           = 0x064,
    CMSG_CONTACT_LIST                                    = 0x066,
    CMSG_ADD_FRIEND                                      = 0x069,
    CMSG_DEL_FRIEND                                      = 0x06A,
    CMSG_SET_CONTACT_NOTES                               = 0x06B,
    CMSG_ADD_IGNORE                                      = 0x06C,
    CMSG_DEL_IGNORE                                      = 0x06D,
    CMSG_SAVE_PLAYER                                     = 0x153,
    CMSG_REFER_A_FRIEND                                  = 0x40E,

    // Player Dance
    CMSG_SAVE_DANCE                                      = 0x449,
    CMSG_PLAY_DANCE                                      = 0x44B,
    CMSG_LOAD_DANCES                                     = 0x44D,
    CMSG_STOP_DANCE                                      = 0x44E,
    CMSG_SYNC_DANCE                                      = 0x450,
    CMSG_DANCE_QUERY                                     = 0x451,
    CMSG_DELETE_DANCE                                    = 0x454,
    CMSG_LEARN_DANCE_MOVE                                = 0x456,
    CMSG_UNLEARN_DANCE_MOVE                              = 0x457,

    // Player Level
    CMSG_LEVEL_CHEAT                                     = 0x025,
    CMSG_SET_GRANTABLE_LEVELS                            = 0x40C,
    CMSG_GRANT_LEVEL                                     = 0x40D,
    CMSG_ACCEPT_LEVEL_GRANT                              = 0x420,

    // Player Pet
    CMSG_PET_LEVEL_CHEAT                                 = 0x026,
    CMSG_STABLE_PET                                      = 0x270,
    CMSG_UNSTABLE_PET                                    = 0x271,
    CMSG_BUY_STABLE_SLOT                                 = 0x272,
    CMSG_STABLE_REVIVE_PET                               = 0x274,
    CMSG_STABLE_SWAP_PET                                 = 0x275,
    CMSG_REQUEST_PET_INFO                                = 0x279,

    // Player PVP / Honor / ...
    CMSG_DISABLE_PVP_CHEAT                               = 0x030,
    CMSG_TOGGLE_PVP                                      = 0x253,
    CMSG_SET_PVP_RANK_CHEAT                              = 0x288,
    CMSG_ADD_PVP_MEDAL_CHEAT                             = 0x289,
    CMSG_DEL_PVP_MEDAL_CHEAT                             = 0x28A,
    CMSG_SET_PVP_TITLE                                   = 0x28B,
    CMSG_SET_TITLE                                       = 0x374,
    CMSG_CHEAT_SET_HONOR_CURRENCY                        = 0x37B,
    CMSG_ACTIVE_PVP_CHEAT                                = 0x399,
    CMSG_REPORT_PVP_AFK                                  = 0x3E4,
    CMSG_SET_TITLE_SUFFIX                                = 0x3F7,

    // Player Arena
    CMSG_ARENA_TEAM_CREATE                               = 0x348,
    CMSG_ARENA_TEAM_QUERY                                = 0x34B,
    CMSG_ARENA_TEAM_ROSTER                               = 0x34D,
    CMSG_ARENA_TEAM_INVITE                               = 0x34F,
    CMSG_ARENA_TEAM_ACCEPT                               = 0x351,
    CMSG_ARENA_TEAM_DECLINE                              = 0x352,
    CMSG_ARENA_TEAM_LEAVE                                = 0x353,
    CMSG_ARENA_TEAM_REMOVE                               = 0x354,
    CMSG_ARENA_TEAM_DISBAND                              = 0x355,
    CMSG_ARENA_TEAM_LEADER                               = 0x356,
    CMSG_CHEAT_SET_ARENA_CURRENCY                        = 0x37C,
    CMSG_CHANGE_PERSONAL_ARENA_RATING                    = 0x425,

    // Player Tutorial
    CMSG_TUTORIAL_FLAG                                   = 0x0FE,
    CMSG_TUTORIAL_CLEAR                                  = 0x0FF,
    CMSG_TUTORIAL_RESET                                  = 0x100,

    // Player Emote
    CMSG_EMOTE                                           = 0x102,
    CMSG_TEXT_EMOTE                                      = 0x104,

    // Player Corpse / Resurrect / Death
    CMSG_SETDEATHBINDPOINT                               = 0x154,
    CMSG_GETDEATHBINDZONE                                = 0x156,
    CMSG_REPOP_REQUEST                                   = 0x15A,
    CMSG_RESURRECT_RESPONSE                              = 0x15C,
    CMSG_RECLAIM_CORPSE                                  = 0x1D2,
    CMSG_GHOST                                           = 0x1E5,
    CMSG_HEARTH_AND_RESURRECT                            = 0x49C,

    // Player Health / Power / Mana / ...
    CMSG_SET_RUNE_COUNT                                  = 0x458,
    CMSG_SET_RUNE_COOLDOWN                               = 0x459,

    // Player Glyph
    CMSG_SET_GLYPH_SLOT                                  = 0x466,
    CMSG_SET_GLYPH                                       = 0x467,
    CMSG_REMOVE_GLYPH                                    = 0x48A,

    // Player Talent / Skill
    CMSG_UNLEARN_TALENTS                                 = 0x213,
    CMSG_USE_SKILL_CHEAT                                 = 0x029,
    CMSG_SKILL_BUY_STEP                                  = 0x21F,
    CMSG_SKILL_BUY_RANK                                  = 0x220,
    CMSG_LEARN_TALENT                                    = 0x251,
    CMSG_LEARN_PREVIEW_TALENTS                           = 0x4C1,
    CMSG_LEARN_PREVIEW_TALENTS_PET                       = 0x4C2,

    // Player Mail
    CMSG_SEND_MAIL                                       = 0x238,
    CMSG_GET_MAIL_LIST                                   = 0x23A,
    CMSG_MAIL_TAKE_MONEY                                 = 0x245,
    CMSG_MAIL_TAKE_ITEM                                  = 0x246,
    CMSG_MAIL_MARK_AS_READ                               = 0x247,
    CMSG_MAIL_RETURN_TO_SENDER                           = 0x248,
    CMSG_MAIL_DELETE                                     = 0x249,
    CMSG_MAIL_CREATE_TEXT_ITEM                           = 0x24A,

    // Player Voice
    CMSG_VOICE_SET_TALKER_MUTED_REQUEST                  = 0x3A1,
    CMSG_VOICE_SESSION_ENABLE                            = 0x3AF,
    CMSG_SET_ACTIVE_VOICE_CHANNEL                        = 0x3D3,
    CMSG_CHANNEL_VOICE_ON                                = 0x3D6,
    CMSG_CHANNEL_VOICE_OFF                               = 0x3D7,
    CMSG_DEBUG_LIST_TARGETS                              = 0x3D8,
    CMSG_ADD_VOICE_IGNORE                                = 0x3DB,
    CMSG_DEL_VOICE_IGNORE                                = 0x3DC,

    // Player Totem
    CMSG_TOTEM_DESTROYED                                 = 0x414,

    /***********************************************************/
    /********************* QUERY OPCODES ***********************/
    /***********************************************************/
    CMSG_NAME_QUERY                                      = 0x050,
    CMSG_PET_NAME_QUERY                                  = 0x052,
    CMSG_GUILD_QUERY                                     = 0x054,
    CMSG_ITEM_QUERY_SINGLE                               = 0x056,
    CMSG_ITEM_QUERY_MULTIPLE                             = 0x057,
    CMSG_PAGE_TEXT_QUERY                                 = 0x05A,
    CMSG_QUEST_QUERY                                     = 0x05C,
    CMSG_GAMEOBJECT_QUERY                                = 0x05E,
    CMSG_CREATURE_QUERY                                  = 0x060,
    CMSG_ITEM_TEXT_QUERY                                 = 0x243,
    CMSG_ITEM_NAME_QUERY                                 = 0x2C4,
    CMSG_CORPSE_MAP_POSITION_QUERY                       = 0x4B6,

    /***********************************************************/
    /********************* QUEST OPCODES ***********************/
    /***********************************************************/
    CMSG_FLAG_QUEST                                      = 0x02A,
    CMSG_FLAG_QUEST_FINISH                               = 0x02B,
    CMSG_CLEAR_QUEST                                     = 0x02C,
    CMSG_QUESTLOG_SWAP_QUEST                             = 0x193,
    CMSG_QUESTLOG_REMOVE_QUEST                           = 0x194,
    CMSG_QUEST_CONFIRM_ACCEPT                            = 0x19B,
    CMSG_PUSHQUESTTOPARTY                                = 0x19D,
    CMSG_QUEST_POI_QUERY                                 = 0x1E3,
    CMSG_START_QUEST                                     = 0x489,
    CMSG_QUERY_QUESTS_COMPLETED                          = 0x500,

    // Questgiver
    CMSG_QUESTGIVER_STATUS_MULTIPLE_QUERY                = 0x417,

    /***********************************************************/
    /********************* SPELL OPCODES ***********************/
    /***********************************************************/
    CMSG_RECHARGE                                        = 0x00F,
    CMSG_LEARN_SPELL                                     = 0x010,
    CMSG_NEW_SPELL_SLOT                                  = 0x12D,
    CMSG_CAST_SPELL                                      = 0x12E,
    CMSG_CANCEL_CAST                                     = 0x12F,
    CMSG_CANCEL_CHANNELLING                              = 0x13B,
    CMSG_UNLEARN_SPELL                                   = 0x201,
    CMSG_DECHARGE                                        = 0x204,
    CMSG_CANCEL_AUTO_REPEAT_SPELL                        = 0x26D,
    CMSG_SUMMON_RESPONSE                                 = 0x2AC,
    CMSG_SEND_GENERAL_TRIGGER                            = 0x393,
    CMSG_SEND_COMBAT_TRIGGER                             = 0x394,
    CMSG_TARGET_CAST                                     = 0x3D0,
    CMSG_TARGET_SCRIPT_CAST                              = 0x3D1,
    CMSG_SPELLCLICK                                      = 0x3F8,
    CMSG_NO_SPELL_VARIANCE                               = 0x416,

    // Spell Aura
    CMSG_CANCEL_AURA                                     = 0x136,
    CMSG_PET_CANCEL_AURA                                 = 0x26B,
    CMSG_CANCEL_GROWTH_AURA                              = 0x29B,

    // Spell Cooldown
    CMSG_COOLDOWN_CHEAT                                  = 0x028,

    // Spell Pet
    CMSG_PET_CAST_SPELL                                  = 0x1F0,
    CMSG_PET_SPELL_AUTOCAST                              = 0x2F3,

    /***********************************************************/
    /******************* TRANSPORT OPCODES *********************/
    /***********************************************************/
    // Transport Taxi
    CMSG_TAXICLEARALLNODES                               = 0x1A6,
    CMSG_TAXIENABLEALLNODES                              = 0x1A7,
    CMSG_TAXISHOWNODES                                   = 0x1A8,
    CMSG_TAXINODE_STATUS_QUERY                           = 0x1AA,
    CMSG_TAXIQUERYAVAILABLENODES                         = 0x1AC,
    CMSG_ACTIVATETAXI                                    = 0x1AD,
    CMSG_TAXICLEARNODE                                   = 0x241,
    CMSG_TAXIENABLENODE                                  = 0x242,
    CMSG_ACTIVATETAXIEXPRESS                             = 0x312,
    CMSG_SET_TAXI_BENCHMARK_MODE                         = 0x389,
    CMSG_ENABLETAXI                                      = 0x493,

    /***********************************************************/
    /****************** TIME / SPEED OPCODES *******************/
    /***********************************************************/
    // Time
    CMSG_GAMETIME_SET                                    = 0x044,
    CMSG_SERVERTIME                                      = 0x048,
    CMSG_PLAYED_TIME                                     = 0x1CC,
    CMSG_QUERY_TIME                                      = 0x1CE,
    CMSG_TIME_SYNC_RESP                                  = 0x391,
    CMSG_KEEP_ALIVE                                      = 0x407,
    CMSG_WORLD_STATE_UI_TIMER_UPDATE                     = 0x4F6,
    CMSG_READY_FOR_ACCOUNT_DATA_TIMES                    = 0x4FF,

    // Speed
    CMSG_GAMESPEED_SET                                   = 0x046,

    /***********************************************************/
    /****************** UNCATEGORZIED OPCODES ******************/
    /***********************************************************/
    CMSG_BOOTME                                          = 0x001,
    CMSG_DBLOOKUP                                        = 0x002,
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
    CMSG_AREATRIGGER                                     = 0x0B4,
    CMSG_STANDSTATECHANGE                                = 0x101,
    CMSG_SET_SELECTION                                   = 0x13D,
    CMSG_UNUSED2                                         = 0x140,
    CMSG_BINDER_ACTIVATE                                 = 0x1B5,
    CMSG_BANKER_ACTIVATE                                 = 0x1B7,
    CMSG_BUY_BANK_SLOT                                   = 0x1B9,
    CMSG_BUG                                             = 0x1CA,
    CMSG_SET_SKILL_CHEAT                                 = 0x1D8,
    CMSG_PING                                            = 0x1DC,
    CMSG_SETSHEATHED                                     = 0x1E0,
    CMSG_ZONEUPDATE                                      = 0x1F4,
    CMSG_UNLEARN_SKILL                                   = 0x202,
    CMSG_SPIRIT_HEALER_ACTIVATE                          = 0x21C,
    CMSG_SET_STAT_CHEAT                                  = 0x21D,
    CMSG_XP_CHEAT                                        = 0x221,
    CMSG_SERVER_COMMAND                                  = 0x227,
    CMSG_CLEAR_EXPLORATION                               = 0x237,
    CMSG_SET_AMMO                                        = 0x268,
    CMSG_SET_ACTIVE_MOVER                                = 0x26A,
    CMSG_FAR_SIGHT                                       = 0x27A,
    CMSG_SELF_RES                                        = 0x2B3,
    CMSG_RUN_SCRIPT                                      = 0x2B5,
    CMSG_AREA_SPIRIT_HEALER_QUERY                        = 0x2E2,
    CMSG_AREA_SPIRIT_HEALER_QUEUE                        = 0x2E3,
    CMSG_WARDEN_DATA                                     = 0x2E7,
    CMSG_DEBUG_ACTIONS_START                             = 0x315,
    CMSG_DEBUG_ACTIONS_STOP                              = 0x316,
    CMSG_LUA_USAGE                                       = 0x323,
    CMSG_IGNORE_KNOCKBACK_CHEAT                          = 0x32C,
    CMSG_MAELSTROM_INVALIDATE_CACHE                      = 0x387,
    CMSG_SEND_LOCAL_EVENT                                = 0x392,
    CMSG_BOT_DETECTED                                    = 0x3C0,
    CMSG_CHEAT_PLAYER_LOGIN                              = 0x3C2,
    CMSG_CHEAT_PLAYER_LOOKUP                             = 0x3C3,
    CMSG_COMPLAIN                                        = 0x3C7,
    CMSG_GET_MIRRORIMAGE_DATA                            = 0x401,
    CMSG_IGNORE_DIMINISHING_RETURNS_CHEAT                = 0x405,
    CMSG_QUERY_SERVER_BUCK_DATA                          = 0x41B,
    CMSG_CLEAR_SERVER_BUCK_DATA                          = 0x41C,
    CMSG_ALTER_APPEARANCE                                = 0x426,
    CMSG_UNITANIMTIER_CHEAT                              = 0x472,
    CMSG_DISMISS_CRITTER                                 = 0x48D,
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
    CMSG_DISMISS_CONTROLLED_VEHICLE                      = 0x46D,
    CMSG_REQUEST_VEHICLE_EXIT                            = 0x476,
    CMSG_REQUEST_VEHICLE_PREV_SEAT                       = 0x477,
    CMSG_REQUEST_VEHICLE_NEXT_SEAT                       = 0x478,
    CMSG_REQUEST_VEHICLE_SWITCH_SEAT                     = 0x479,
    CMSG_CHANGE_SEATS_ON_CONTROLLED_VEHICLE              = 0x49B,
    CMSG_QUERY_VEHICLE_STATUS                            = 0x4A4,
    CMSG_PLAYER_VEHICLE_ENTER                            = 0x4A8,
    CMSG_EJECT_PASSENGER                                 = 0x4A9,

    /***********************************************************/
    /********************** WORLD OPCODES **********************/
    /***********************************************************/
    // World Teleport
    CMSG_WORLD_TELEPORT                                  = 0x008,
    CMSG_TELEPORT_TO_UNIT                                = 0x009,
    CMSG_REQUEST_ACCOUNT_DATA                            = 0x20A,
    CMSG_UPDATE_ACCOUNT_DATA                             = 0x20B,
};

extern void ClientOpcodeTable();

#endif
