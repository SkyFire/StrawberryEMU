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

#ifndef CLIENTSERVER_OPCODES
#define CLIENTSERVER_OPCODES

/**
* Declaration of Opcode values.
* Ordered by Category and value.
*/
enum ClientServerOpcodes
{
    /********************************************/
    /************* CHANNEL OPCODES **************/
    /********************************************/
    MSG_CHANNEL_START                    = 0x139,
    MSG_CHANNEL_UPDATE                   = 0x13A,

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
    MSG_SAVE_GUILD_EMBLEM                = 0x1F1,
    MSG_GUILD_BANK_LOG_QUERY             = 0x3EE,
    MSG_GUILD_PERMISSIONS                = 0x3FD,
    MSG_GUILD_BANK_MONEY_WITHDRAWN       = 0x3FE,
    MSG_GUILD_EVENT_LOG_QUERY            = 0x3FF,
    MSG_QUERY_GUILD_BANK_TEXT            = 0x40A,

    /********************************************/
    /************ INSTANCES OPCODES *************/
    /********************************************/
    MSG_BATTLEGROUND_PLAYER_POSITIONS    = 0x2E9,
    MSG_RAID_TARGET_UPDATE               = 0x321,
    MSG_RAID_READY_CHECK                 = 0x322,
    MSG_SET_DUNGEON_DIFFICULTY           = 0x329,
    MSG_PARTY_ASSIGNMENT                 = 0x38E,
    MSG_RAID_READY_CHECK_CONFIRM         = 0x3AE,
    MSG_RAID_READY_CHECK_FINISHED        = 0x3C6,
    MSG_NOTIFY_PARTY_SQUELCH             = 0x3DF,
    MSG_SET_RAID_DIFFICULTY              = 0x4EB,

    /********************************************/
    /************* MOVEMENT OPCODES *************/
    /********************************************/
    // Movement Start
    MSG_MOVE_START_FORWARD               = 0x0B5,
    MSG_MOVE_START_BACKWARD              = 0x0B6,
    MSG_MOVE_START_STRAFE_LEFT           = 0x0B8,
    MSG_MOVE_START_STRAFE_RIGHT          = 0x0B9,
    MSG_MOVE_START_TURN_LEFT             = 0x0BC,
    MSG_MOVE_START_TURN_RIGHT            = 0x0BD,
    MSG_MOVE_START_PITCH_UP              = 0x0BF,
    MSG_MOVE_START_PITCH_DOWN            = 0x0C0,
    MSG_MOVE_START_SWIM                  = 0x0CA,
    MSG_MOVE_START_SWIM_CHEAT            = 0x341,
    MSG_MOVE_START_ASCEND                = 0x359,

    // Movement Stop
    MSG_MOVE_STOP                        = 0x0B7,
    MSG_MOVE_STOP_STRAFE                 = 0x0BA,
    MSG_MOVE_STOP_TURN                   = 0x0BE,
    MSG_MOVE_STOP_PITCH                  = 0x0C1,
    MSG_MOVE_STOP_SWIM                   = 0x0CB,
    MSG_MOVE_STOP_SWIM_CHEAT             = 0x342,
    MSG_MOVE_STOP_ASCEND                 = 0x35A,
    MSG_MOVE_START_DESCEND               = 0x3A7,

    // Movement Toggle
    MSG_MOVE_TOGGLE_LOGGING              = 0x0C4,
    MSG_MOVE_TOGGLE_FALL_LOGGING         = 0x0C8,
    MSG_MOVE_TOGGLE_COLLISION_CHEAT      = 0x0D9,
    MSG_MOVE_TOGGLE_GRAVITY_CHEAT        = 0x2AD,

    // Movement Teleport / Fall / Fly / Water
    MSG_MOVE_TELEPORT                    = 0x0C5,
    MSG_MOVE_TELEPORT_CHEAT              = 0x0C6,
    MSG_MOVE_TELEPORT_ACK                = 0x0C7,
    MSG_MOVE_JUMP                        = 0x0BB,
    MSG_MOVE_FALL_LAND                   = 0x0C9,
    MSG_MOVE_WORLDPORT_ACK               = 0x0DC,
    MSG_MOVE_FEATHER_FALL                = 0x2B0,
    MSG_MOVE_WATER_WALK                  = 0x2B1,
    MSG_MOVE_UPDATE_CAN_FLY              = 0x3AD,

    // Movement Set...
    MSG_MOVE_SET_RUN_MODE                = 0x0C2,
    MSG_MOVE_SET_WALK_MODE               = 0x0C3,
    MSG_MOVE_SET_RUN_SPEED_CHEAT         = 0x0CC,
    MSG_MOVE_SET_RUN_SPEED               = 0x0CD,
    MSG_MOVE_SET_RUN_BACK_SPEED_CHEAT    = 0x0CE,
    MSG_MOVE_SET_RUN_BACK_SPEED          = 0x0CF,
    MSG_MOVE_SET_WALK_SPEED_CHEAT        = 0x0D0,
    MSG_MOVE_SET_WALK_SPEED              = 0x0D1,
    MSG_MOVE_SET_SWIM_SPEED_CHEAT        = 0x0D2,
    MSG_MOVE_SET_SWIM_SPEED              = 0x0D3,
    MSG_MOVE_SET_SWIM_BACK_SPEED_CHEAT   = 0x0D4,
    MSG_MOVE_SET_SWIM_BACK_SPEED         = 0x0D5,
    MSG_MOVE_SET_ALL_SPEED_CHEAT         = 0x0D6,
    MSG_MOVE_SET_TURN_RATE_CHEAT         = 0x0D7,
    MSG_MOVE_SET_TURN_RATE               = 0x0D8,
    MSG_MOVE_SET_FACING                  = 0x0DA,
    MSG_MOVE_SET_PITCH                   = 0x0DB,
    MSG_MOVE_SET_RAW_POSITION_ACK        = 0x0E0,
    MSG_MOVE_SET_FLIGHT_SPEED_CHEAT      = 0x37D,
    MSG_MOVE_SET_FLIGHT_SPEED            = 0x37E,
    MSG_MOVE_SET_FLIGHT_BACK_SPEED_CHEAT = 0x37F,
    MSG_MOVE_SET_FLIGHT_BACK_SPEED       = 0x380,
    MSG_MOVE_SET_PITCH_RATE_CHEAT        = 0x45A,
    MSG_MOVE_SET_PITCH_RATE              = 0x45B,

    // Movement Uncategorized
    MSG_MOVE_ROOT                        = 0x0EC,
    MSG_MOVE_UNROOT                      = 0x0ED,
    MSG_MOVE_HEARTBEAT                   = 0x0EE,
    MSG_MOVE_KNOCK_BACK                  = 0x0F1,
    MSG_MOVE_HOVER                       = 0x0F7,
    MSG_MOVE_TIME_SKIPPED                = 0x319,
    MSG_MOVE_UNKNOWN_1234                = 0x4D2,

    /********************************************/
    /************* PETITION OPCODES *************/
    /********************************************/
    MSG_PETITION_DECLINE                 = 0x1C2,
    MSG_PETITION_RENAME                  = 0x2C1,

    /********************************************/
    /*********** UNCATEGORZIED OPCODES **********/
    /********************************************/
    MSG_NULL_ACTION                      = 0x000,
    MSG_MINIMAP_PING                     = 0x1D5,
    MSG_TABARDVENDOR_ACTIVATE            = 0x1F2,
    MSG_RANDOM_ROLL                      = 0x1FB,
    MSG_CORPSE_QUERY                     = 0x216,
    MSG_AUCTION_HELLO                    = 0x255,
    MSG_LIST_STABLED_PETS                = 0x26F,
    MSG_QUEST_PUSH_RESULT                = 0x276,
    MSG_QUERY_NEXT_MAIL_TIME             = 0x284,
    MSG_TALENT_WIPE_CONFIRM              = 0x2AA,
    MSG_DELAY_GHOST_TELEPORT             = 0x32E,
    
    // PVP / Arena
    MSG_INSPECT_HONOR_STATS              = 0x2D6,
    MSG_PVP_LOG_DATA                     = 0x2E0,
    MSG_INSPECT_ARENA_TEAMS              = 0x377
};

extern void ClientServerOpcodeTable();

#endif
