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
    CMSG_ATTACKSWING                                = 0x141,
    CMSG_ATTACKSTOP                                 = 0x142,

    /***********************************************************/
    /******************** AUCTION OPCODES **********************/
    /***********************************************************/
    CMSG_AUCTION_SELL_ITEM                          = 0x256,
    CMSG_AUCTION_REMOVE_ITEM                        = 0x257,
    CMSG_AUCTION_LIST_ITEMS                         = 0x258,
    CMSG_AUCTION_LIST_OWNER_ITEMS                   = 0x259,
    CMSG_AUCTION_PLACE_BID                          = 0x25A,
    CMSG_AUCTION_LIST_BIDDER_ITEMS                  = 0x264,

    /***********************************************************/
    /***************** AUTHENTICATION OPCODES ******************/
    /***********************************************************/
    CMSG_AUTH_SESSION                               = 0x1ED,

    // SRP6
    CMSG_AUTH_SRP6_BEGIN                            = 0x033,
    CMSG_AUTH_SRP6_PROOF                            = 0x034,
    CMSG_AUTH_SRP6_RECODE                           = 0x035,

    /***********************************************************/
    /******************* BATTLEFIELD OPCODES *******************/
    /***********************************************************/
    CMSG_BATTLEFIELD_LIST                           = 0x23C,
    CMSG_BATTLEFIELD_JOIN                           = 0x23E,

    /***********************************************************/
    /******************** CALENDAR OPCODES *********************/
    /***********************************************************/
    CMSG_CALENDAR_GET_CALENDAR                      = 0x429,
    CMSG_CALENDAR_GET_EVENT                         = 0x42A,
    CMSG_CALENDAR_GUILD_FILTER                      = 0x42B,
    CMSG_CALENDAR_ARENA_TEAM                        = 0x42C,
    CMSG_CALENDAR_ADD_EVENT                         = 0x42D,
    CMSG_CALENDAR_UPDATE_EVENT                      = 0x42E,
    CMSG_CALENDAR_REMOVE_EVENT                      = 0x42F,
    CMSG_CALENDAR_COPY_EVENT                        = 0x430,
    CMSG_CALENDAR_EVENT_INVITE                      = 0x431,
    CMSG_CALENDAR_EVENT_RSVP                        = 0x432,
    CMSG_CALENDAR_EVENT_REMOVE_INVITE               = 0x433,
    CMSG_CALENDAR_EVENT_STATUS                      = 0x434,
    CMSG_CALENDAR_EVENT_MODERATOR_STATUS            = 0x435,
    CMSG_CALENDAR_COMPLAIN                          = 0x446,
    CMSG_CALENDAR_GET_NUM_PENDING                   = 0x447,

    /***********************************************************/
    /******************** CHARACTER OPCODES ********************/
    /***********************************************************/
    CMSG_MOVE_CHARACTER_CHEAT                       = 0x00D,
    CMSG_CHAR_CREATE                                = 0x036,
    CMSG_CHAR_ENUM                                  = 0x037,
    CMSG_CHAR_DELETE                                = 0x038,
    CMSG_CHARACTER_POINT_CHEAT                      = 0x223,

    // Character World Login / Logout
    CMSG_PLAYER_LOGIN                               = 0x03D,
    CMSG_PLAYER_LOGOUT                              = 0x04A,
    CMSG_LOGOUT_REQUEST                             = 0x04B,
    CMSG_LOGOUT_CANCEL                              = 0x04E,

    /***********************************************************/
    /********************** CHAT OPCODES ***********************/
    /***********************************************************/
    CMSG_MESSAGECHAT                                = 0x095,
    CMSG_CHAT_IGNORED                               = 0x225,
    CMSG_GM_VISION                                  = 0x226,

    // Channel
    CMSG_JOIN_CHANNEL                               = 0x097,
    CMSG_LEAVE_CHANNEL                              = 0x098,
    CMSG_CHANNEL_LIST                               = 0x09A,
    CMSG_CHANNEL_PASSWORD                           = 0x09C,
    CMSG_CHANNEL_SET_OWNER                          = 0x09D,
    CMSG_CHANNEL_OWNER                              = 0x09E,
    CMSG_CHANNEL_MODERATOR                          = 0x09F,
    CMSG_CHANNEL_UNMODERATOR                        = 0x0A0,
    CMSG_CHANNEL_MUTE                               = 0x0A1,
    CMSG_CHANNEL_UNMUTE                             = 0x0A2,
    CMSG_CHANNEL_INVITE                             = 0x0A3,
    CMSG_CHANNEL_KICK                               = 0x0A4,
    CMSG_CHANNEL_BAN                                = 0x0A5,
    CMSG_CHANNEL_UNBAN                              = 0x0A6,
    CMSG_CHANNEL_ANNOUNCEMENTS                      = 0x0A7,
    CMSG_CHANNEL_MODERATE                           = 0x0A8,

    /***********************************************************/
    /********************* COMBAT OPCODES **********************/
    /***********************************************************/
    CMSG_ENABLE_DAMAGE_LOG                          = 0x27D,

    /***********************************************************/
    /********************** DUEL OPCODES ***********************/
    /***********************************************************/
    CMSG_DUEL_ACCEPTED                              = 0x16C,
    CMSG_DUEL_CANCELLED                             = 0x16D,

    /***********************************************************/
    /******************** FACTION OPCODES **********************/
    /***********************************************************/
    CMSG_SET_FACTION_ATWAR                          = 0x125,
    CMSG_SET_FACTION_CHEAT                          = 0x126,
    CMSG_SET_ACTION_BUTTON                          = 0x128,
    CMSG_RESET_FACTION_CHEAT                        = 0x281,

    /***********************************************************/
    /******************* GAMEMASTER OPCODES ********************/
    /***********************************************************/
    CMSG_GM_INVIS                                   = 0x1E6,
    CMSG_GM_SET_SECURITY_GROUP                      = 0x1F9,
    CMSG_GM_NUKE                                    = 0x1FA,
    CMSG_GM_TEACH                                   = 0x20F,
    CMSG_GM_CREATE_ITEM_TARGET                      = 0x210,
    CMSG_GM_SILENCE                                 = 0x228,
    CMSG_GM_REVEALTO                                = 0x229,
    CMSG_GM_RESURRECT                               = 0x22A,
    CMSG_GM_SUMMONMOB                               = 0x22B,
    CMSG_GM_MOVECORPSE                              = 0x22C,
    CMSG_GM_FREEZE                                  = 0x22D,
    CMSG_GM_UBERINVIS                               = 0x22E,
    CMSG_GM_REQUEST_PLAYER_INFO                     = 0x22F,

    // Gamemaster Ticket
    CMSG_GMTICKET_CREATE                            = 0x205,
    CMSG_GMTICKET_UPDATETEXT                        = 0x207,
    CMSG_GMTICKET_GETTICKET                         = 0x211,
    CMSG_GMTICKET_DELETETICKET                      = 0x217,
    CMSG_GMTICKET_SYSTEMSTATUS                      = 0x21A,

    /***********************************************************/
    /****************** (GAME)OBJECT OPCODES *******************/
    /***********************************************************/
    CMSG_QUERY_OBJECT_POSITION                      = 0x004,
    CMSG_QUERY_OBJECT_ROTATION                      = 0x006,
    CMSG_CREATEGAMEOBJECT                           = 0x014,
    CMSG_GAMEOBJ_USE                                = 0x0B1,

    /***********************************************************/
    /********************** GOSSIP OPCODES *********************/
    /***********************************************************/
    CMSG_GOSSIP_HELLO                               = 0x17B,
    CMSG_GOSSIP_SELECT_OPTION                       = 0x17C,
    CMSG_NPC_TEXT_QUERY                             = 0x17F,

    // Gossip Questgiver
    CMSG_QUESTGIVER_STATUS_QUERY                    = 0x182,
    CMSG_QUESTGIVER_HELLO                           = 0x184,
    CMSG_QUESTGIVER_QUERY_QUEST                     = 0x186,
    CMSG_QUESTGIVER_QUEST_AUTOLAUNCH                = 0x187,
    CMSG_QUESTGIVER_ACCEPT_QUEST                    = 0x189,
    CMSG_QUESTGIVER_COMPLETE_QUEST                  = 0x18A,
    CMSG_QUESTGIVER_REQUEST_REWARD                  = 0x18C,
    CMSG_QUESTGIVER_CHOOSE_REWARD                   = 0x18E,
    CMSG_QUESTGIVER_CANCEL                          = 0x190,

    // Gossip Trainer
    CMSG_TRAINER_LIST                               = 0x1B0,
    CMSG_TRAINER_BUY_SPELL                          = 0x1B2,

    /***********************************************************/
    /********************** GROUP OPCODES **********************/
    /***********************************************************/
    CMSG_GROUP_INVITE                               = 0x06E,
    CMSG_GROUP_CANCEL                               = 0x070,
    CMSG_GROUP_ACCEPT                               = 0x072,
    CMSG_GROUP_DECLINE                              = 0x073,
    CMSG_GROUP_UNINVITE                             = 0x075,
    CMSG_GROUP_UNINVITE_GUID                        = 0x076,
    CMSG_GROUP_SET_LEADER                           = 0x078,
    CMSG_GROUP_DISBAND                              = 0x07B,
    CMSG_GROUP_CHANGE_SUB_GROUP                     = 0x27E,
    CMSG_GROUP_SWAP_SUB_GROUP                       = 0x280,
    CMSG_GROUP_RAID_CONVERT                         = 0x28E,
    CMSG_GROUP_ASSISTANT_LEADER                     = 0x28F,

    /***********************************************************/
    /********************** GUILD OPCODES **********************/
    /***********************************************************/
    CMSG_GUILD_CREATE                               = 0x081,
    CMSG_GUILD_INVITE                               = 0x082,
    CMSG_GUILD_ACCEPT                               = 0x084,
    CMSG_GUILD_DECLINE                              = 0x085,
    CMSG_GUILD_INFO                                 = 0x087,
    CMSG_GUILD_ROSTER                               = 0x089,
    CMSG_GUILD_PROMOTE                              = 0x08B,
    CMSG_GUILD_DEMOTE                               = 0x08C,
    CMSG_GUILD_LEAVE                                = 0x08D,
    CMSG_GUILD_REMOVE                               = 0x08E,
    CMSG_GUILD_DISBAND                              = 0x08F,
    CMSG_GUILD_LEADER                               = 0x090,
    CMSG_GUILD_MOTD                                 = 0x091,
    CMSG_GUILD_RANK                                 = 0x231,
    CMSG_GUILD_ADD_RANK                             = 0x232,
    CMSG_GUILD_DEL_RANK                             = 0x233,
    CMSG_GUILD_SET_PUBLIC_NOTE                      = 0x234,
    CMSG_GUILD_SET_OFFICER_NOTE                     = 0x235,

    // Petition
    CMSG_PETITION_SHOWLIST                          = 0x1BB,
    CMSG_PETITION_BUY                               = 0x1BD,
    CMSG_PETITION_SHOW_SIGNATURES                   = 0x1BE,
    CMSG_PETITION_SIGN                              = 0x1C0,
    CMSG_OFFER_PETITION                             = 0x1C3,
    CMSG_TURN_IN_PETITION                           = 0x1C4,
    CMSG_PETITION_QUERY                             = 0x1C6,

    // Party
    CMSG_REQUEST_PARTY_MEMBER_STATS                 = 0x27F,

    /***********************************************************/
    /******************** INSTANCE OPCODES *********************/
    /***********************************************************/
    CMSG_INSTANCE_LOCK_WARNING_RESPONSE             = 0x13F,

    /***********************************************************/
    /********************** ITEM OPCODES ***********************/
    /***********************************************************/
    CMSG_CREATEITEM                                 = 0x013,
    CMSG_USE_ITEM                                   = 0x0AB,
    CMSG_OPEN_ITEM                                  = 0x0AC,
    CMSG_READ_ITEM                                  = 0x0AD,
    CMSG_DESTROY_ITEMS                              = 0x0B2,
    CMSG_SWAP_ITEM                                  = 0x10C,
    CMSG_SWAP_INV_ITEM                              = 0x10D,
    CMSG_SPLIT_ITEM                                 = 0x10E,
    OBSOLETE_DROP_ITEM                              = 0x110,
    CMSG_DESTROYITEM                                = 0x111,
    CMSG_SELL_ITEM                                  = 0x1A0,
    CMSG_BUY_ITEM                                   = 0x1A2,
    CMSG_BUY_ITEM_IN_SLOT                           = 0x1A3,
    CMSG_WRAP_ITEM                                  = 0x1D3,  
    CMSG_SET_DURABILITY_CHEAT                       = 0x287,
    CMSG_BUYBACK_ITEM                               = 0x290,

    // Item Equipment
    CMSG_AUTOEQUIP_GROUND_ITEM                      = 0x106,
    CMSG_AUTOSTORE_GROUND_ITEM                      = 0x107,
    CMSG_AUTOSTORE_LOOT_ITEM                        = 0x108,
    CMSG_AUTOEQUIP_ITEM                             = 0x10A,
    CMSG_AUTOSTORE_BAG_ITEM                         = 0x10B,
    CMSG_AUTOEQUIP_ITEM_SLOT                        = 0x10F,
    CMSG_EQUIPMENT_SET_DELETE                       = 0x13E,
    CMSG_AUTOSTORE_BANK_ITEM                        = 0x282,
    CMSG_AUTOBANK_ITEM                              = 0x283,

    // Inventory / Trade
    CMSG_INSPECT                                    = 0x114,
    CMSG_INITIATE_TRADE                             = 0x116,
    CMSG_BEGIN_TRADE                                = 0x117,
    CMSG_BUSY_TRADE                                 = 0x118,
    CMSG_IGNORE_TRADE                               = 0x119,
    CMSG_ACCEPT_TRADE                               = 0x11A,
    CMSG_UNACCEPT_TRADE                             = 0x11B,
    CMSG_CANCEL_TRADE                               = 0x11C,
    CMSG_SET_TRADE_ITEM                             = 0x11D,
    CMSG_CLEAR_TRADE_ITEM                           = 0x11E,
    CMSG_SET_TRADE_GOLD                             = 0x11F,
    CMSG_LIST_INVENTORY                             = 0x19E,
    

    /***********************************************************/
    /********************** LOOT OPCODES ***********************/
    /***********************************************************/
    CMSG_LOOT_METHOD                                = 0x07A,
    CMSG_STORE_LOOT_IN_SLOT                         = 0x109,
    CMSG_LOOT                                       = 0x15D,
    CMSG_LOOT_MONEY                                 = 0x15E,
    CMSG_LOOT_RELEASE                               = 0x15F,

    /***********************************************************/
    /******************** MOVEMENT OPCODES *********************/
    /***********************************************************/
    CMSG_MOVE_SET_RAW_POSITION                      = 0x0E1,
    CMSG_MOVE_KNOCK_BACK_ACK                        = 0x0F0,
    CMSG_MOVE_HOVER_ACK                             = 0x0F6,

    // Movement Force
    CMSG_FORCE_RUN_SPEED_CHANGE_ACK                 = 0x0E3,
    CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK            = 0x0E5,
    CMSG_FORCE_SWIM_SPEED_CHANGE_ACK                = 0x0E7,
    CMSG_FORCE_MOVE_ROOT_ACK                        = 0x0E9,
    CMSG_FORCE_MOVE_UNROOT_ACK                      = 0x0EB,
    // Movement Teleport / Fall / Fly / Water
    // Movement Set / Unset
    // Spline
    // Spline Set / Unset

    /***********************************************************/
    /********************* MOVIE OPCODES ***********************/
    /***********************************************************/
    // Cinematic
    CMSG_TRIGGER_CINEMATIC_CHEAT                    = 0x0F8,
    CMSG_OPENING_CINEMATIC                          = 0x0F9,
    CMSG_NEXT_CINEMATIC_CAMERA                      = 0x0FB,
    CMSG_COMPLETE_CINEMATIC                         = 0x0FC,

    /***********************************************************/
    /****************** MOUNT / PET OPCODES ********************/
    /***********************************************************/
    CMSG_MOUNTSPECIAL_ANIM                          = 0x171,
    CMSG_PET_SET_ACTION                             = 0x174,
    CMSG_PET_ACTION                                 = 0x175,
    CMSG_PET_ABANDON                                = 0x176,
    CMSG_PET_RENAME                                 = 0x177,

    /***********************************************************/
    /********************* PLAYER OPCODES **********************/
    /***********************************************************/
    CMSG_UNDRESSPLAYER                              = 0x020,
    CMSG_GODMODE                                    = 0x022,
    CMSG_PLAYER_DIFFICULTY_CHANGE                   = 0x1FD,
    CMSG_PLAYER_AI_CHEAT                            = 0x26C,

    // Friends / Contacts / ...
    CMSG_WHO                                        = 0x062,
    CMSG_WHOIS                                      = 0x064,
    CMSG_CONTACT_LIST                               = 0x066,
    CMSG_ADD_FRIEND                                 = 0x069,
    CMSG_DEL_FRIEND                                 = 0x06A,
    CMSG_SET_CONTACT_NOTES                          = 0x06B,
    CMSG_ADD_IGNORE                                 = 0x06C,
    CMSG_DEL_IGNORE                                 = 0x06D,
    CMSG_SAVE_PLAYER                                = 0x153,

    // Player Level
    CMSG_LEVEL_CHEAT                                = 0x025,

    // Player Pet
    CMSG_PET_LEVEL_CHEAT                            = 0x026,
    CMSG_STABLE_PET                                 = 0x270,
    CMSG_UNSTABLE_PET                               = 0x271,
    CMSG_BUY_STABLE_SLOT                            = 0x272,
    CMSG_STABLE_REVIVE_PET                          = 0x274,
    CMSG_STABLE_SWAP_PET                            = 0x275,
    CMSG_REQUEST_PET_INFO                           = 0x279,

    // Player PVP / Arena / Honor / ...
    CMSG_DISABLE_PVP_CHEAT                          = 0x030,
    CMSG_TOGGLE_PVP                                 = 0x253,
    CMSG_SET_PVP_RANK_CHEAT                         = 0x288,
    CMSG_ADD_PVP_MEDAL_CHEAT                        = 0x289,
    CMSG_DEL_PVP_MEDAL_CHEAT                        = 0x28A,
    CMSG_SET_PVP_TITLE                              = 0x28B,

    // Player Tutorial
    CMSG_TUTORIAL_FLAG                              = 0x0FE,
    CMSG_TUTORIAL_CLEAR                             = 0x0FF,
    CMSG_TUTORIAL_RESET                             = 0x100,

    // Player Emote
    CMSG_EMOTE                                      = 0x102,
    CMSG_TEXT_EMOTE                                 = 0x104,

    // Player Corpse / Resurrect / Death
    CMSG_SETDEATHBINDPOINT                          = 0x154,
    CMSG_GETDEATHBINDZONE                           = 0x156,
    CMSG_REPOP_REQUEST                              = 0x15A,
    CMSG_RESURRECT_RESPONSE                         = 0x15C,
    CMSG_RECLAIM_CORPSE                             = 0x1D2,
    CMSG_GHOST                                      = 0x1E5,

    // Player Talent / Skill
    CMSG_UNLEARN_TALENTS                            = 0x213,
    CMSG_USE_SKILL_CHEAT                            = 0x029,
    CMSG_SKILL_BUY_STEP                             = 0x21F,
    CMSG_SKILL_BUY_RANK                             = 0x220,
    CMSG_LEARN_TALENT                               = 0x251,

    // Player Mail
    CMSG_SEND_MAIL                                  = 0x238,
    CMSG_GET_MAIL_LIST                              = 0x23A,
    CMSG_MAIL_TAKE_MONEY                            = 0x245,
    CMSG_MAIL_TAKE_ITEM                             = 0x246,
    CMSG_MAIL_MARK_AS_READ                          = 0x247,
    CMSG_MAIL_RETURN_TO_SENDER                      = 0x248,
    CMSG_MAIL_DELETE                                = 0x249,
    CMSG_MAIL_CREATE_TEXT_ITEM                      = 0x24A,

    /***********************************************************/
    /********************* QUERY OPCODES ***********************/
    /***********************************************************/
    CMSG_NAME_QUERY                                 = 0x050,
    CMSG_PET_NAME_QUERY                             = 0x052,
    CMSG_GUILD_QUERY                                = 0x054,
    CMSG_ITEM_QUERY_SINGLE                          = 0x056,
    CMSG_ITEM_QUERY_MULTIPLE                        = 0x057,
    CMSG_PAGE_TEXT_QUERY                            = 0x05A,
    CMSG_QUEST_QUERY                                = 0x05C,
    CMSG_GAMEOBJECT_QUERY                           = 0x05E,
    CMSG_CREATURE_QUERY                             = 0x060,
    CMSG_ITEM_TEXT_QUERY                            = 0x243,

    /***********************************************************/
    /********************* QUEST OPCODES ***********************/
    /***********************************************************/
    CMSG_FLAG_QUEST                                 = 0x02A,
    CMSG_FLAG_QUEST_FINISH                          = 0x02B,
    CMSG_CLEAR_QUEST                                = 0x02C,
    CMSG_QUESTLOG_SWAP_QUEST                        = 0x193,
    CMSG_QUESTLOG_REMOVE_QUEST                      = 0x194,
    CMSG_QUEST_CONFIRM_ACCEPT                       = 0x19B,
    CMSG_PUSHQUESTTOPARTY                           = 0x19D,
    CMSG_QUEST_POI_QUERY                            = 0x1E3,

    /***********************************************************/
    /********************* SPELL OPCODES ***********************/
    /***********************************************************/
    CMSG_RECHARGE                                   = 0x00F,
    CMSG_LEARN_SPELL                                = 0x010,
    CMSG_NEW_SPELL_SLOT                             = 0x12D,
    CMSG_CAST_SPELL                                 = 0x12E,
    CMSG_CANCEL_CAST                                = 0x12F,
    CMSG_CANCEL_CHANNELLING                         = 0x13B,
    CMSG_UNLEARN_SPELL                              = 0x201,
    CMSG_DECHARGE                                   = 0x204,
    CMSG_CANCEL_AUTO_REPEAT_SPELL                   = 0x26D,

    // Spell Auras
    CMSG_CANCEL_AURA                                = 0x136,
    CMSG_PET_CANCEL_AURA                            = 0x26B,

    // Spell Cooldown
    CMSG_COOLDOWN_CHEAT                             = 0x028,

    // Spell Pet
    CMSG_PET_CAST_SPELL                             = 0x1F0,

    /***********************************************************/
    /******************* TRANSPORT OPCODES *********************/
    /***********************************************************/
    // Transport Taxi
    CMSG_TAXICLEARALLNODES                          = 0x1A6,
    CMSG_TAXIENABLEALLNODES                         = 0x1A7,
    CMSG_TAXISHOWNODES                              = 0x1A8,
    CMSG_TAXINODE_STATUS_QUERY                      = 0x1AA,
    CMSG_TAXIQUERYAVAILABLENODES                    = 0x1AC,
    CMSG_ACTIVATETAXI                               = 0x1AD,
    CMSG_TAXICLEARNODE                              = 0x241,
    CMSG_TAXIENABLENODE                             = 0x242,

    /***********************************************************/
    /****************** TIME / SPEED OPCODES *******************/
    /***********************************************************/
    // Time
    CMSG_GAMETIME_SET                               = 0x044,
    CMSG_SERVERTIME                                 = 0x048,
    CMSG_PLAYED_TIME                                = 0x1CC,
    CMSG_QUERY_TIME                                 = 0x1CE,

    // Speed
    CMSG_GAMESPEED_SET                              = 0x046,

    /***********************************************************/
    /****************** UNCATEGORZIED OPCODES ******************/
    /***********************************************************/
    CMSG_BOOTME                                     = 0x001,
    CMSG_DBLOOKUP                                   = 0x002,
    CMSG_ZONE_MAP                                   = 0x00A,
    CMSG_DEBUG_CHANGECELLZONE                       = 0x00C,
    CMSG_CREATEMONSTER                              = 0x011,
    CMSG_DESTROYMONSTER                             = 0x012,
    CMSG_MAKEMONSTERATTACKGUID                      = 0x016,
    CMSG_BOT_DETECTED2                              = 0x017,
    CMSG_PETGODMODE                                 = 0x01C,
    CMSG_WEATHER_SPEED_CHEAT                        = 0x01F,
    CMSG_BEASTMASTER                                = 0x021,
    CMSG_CHEAT_SETMONEY                             = 0x024,
    CMSG_SET_WORLDSTATE                             = 0x027,
    CMSG_ADVANCE_SPAWN_TIME                         = 0x031,
    CMSG_AREATRIGGER                                = 0x0B4,
    CMSG_STANDSTATECHANGE                           = 0x101,
    CMSG_SET_SELECTION                              = 0x13D,
    CMSG_UNUSED2                                    = 0x140,
    CMSG_BINDER_ACTIVATE                            = 0x1B5,
    CMSG_BANKER_ACTIVATE                            = 0x1B7,
    CMSG_BUY_BANK_SLOT                              = 0x1B9,
    CMSG_BUG                                        = 0x1CA,
    CMSG_SET_SKILL_CHEAT                            = 0x1D8,
    CMSG_PING                                       = 0x1DC,
    CMSG_SETSHEATHED                                = 0x1E0,
    CMSG_ZONEUPDATE                                 = 0x1F4,
    CMSG_UNLEARN_SKILL                              = 0x202,
    CMSG_SPIRIT_HEALER_ACTIVATE                     = 0x21C,
    CMSG_SET_STAT_CHEAT                             = 0x21D,
    CMSG_XP_CHEAT                                   = 0x221,
    CMSG_SERVER_COMMAND                             = 0x227,
    CMSG_CLEAR_EXPLORATION                          = 0x237,
    CMSG_SET_AMMO                                   = 0x268,
    CMSG_SET_ACTIVE_MOVER                           = 0x26A,
    CMSG_FAR_SIGHT                                  = 0x27A,

    // Action
    CMSG_FORCEACTION                                = 0x018,
    CMSG_FORCEACTIONONOTHER                         = 0x019,
    CMSG_FORCEACTIONSHOW                            = 0x01A,

    // Event
    CMSG_SEND_EVENT                                 = 0x02D,
    CMSG_DEBUG_AISTATE                              = 0x02E,

    // Commentator
    CMSG_COMMENTATOR_ENABLE                         = 0x3B5,
    CMSG_COMMENTATOR_GET_MAP_INFO                   = 0x3B7,
    CMSG_COMMENTATOR_GET_PLAYER_INFO                = 0x3B9,
    CMSG_COMMENTATOR_ENTER_INSTANCE                 = 0x3BC,
    CMSG_COMMENTATOR_EXIT_INSTANCE                  = 0x3BD,
    CMSG_COMMENTATOR_INSTANCE_COMMAND               = 0x3BE,

    /***********************************************************/
    /********************** WORLD OPCODES **********************/
    /***********************************************************/
    // World Teleport
    CMSG_WORLD_TELEPORT                             = 0x008,
    CMSG_TELEPORT_TO_UNIT                           = 0x009,
    CMSG_REQUEST_ACCOUNT_DATA                       = 0x20A,
    CMSG_UPDATE_ACCOUNT_DATA                        = 0x20B,
};

extern void ClientOpcodeTable();

#endif
