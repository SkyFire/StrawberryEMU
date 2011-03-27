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
    MSG_MOVE_JUMP                        = 0x0BB,
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
    MSG_INSPECT_ARENA_TEAMS              = 0x377
};

extern void ClientServerOpcodeTable();

class WorldPacket;

struct ClientServerOpcodeHandler
{
    char const* name;
    SessionStatus status;
    PacketProcessing packetProcessing;
    void (WorldSession::*handler)(WorldPacket& recvPacket);
};

extern ClientServerOpcodeHandler clientServerOpcodeTable[NUM_MSG_TYPES];

inline const char* LookupClientServerOpcodeName(uint32 opcodeValue)
{
    if (opcodeValue >= NUM_MSG_TYPES)
        return "Received to big opcode: " + opcodeValue;

    return clientServerOpcodeTable[opcodeValue].name;
}

#endif
