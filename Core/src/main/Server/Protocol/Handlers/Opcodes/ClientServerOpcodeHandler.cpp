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

#include "ClientServerOpcodeHandler.h"
#include "WorldSession.h"

ClientServerOpcodeHandler clientServerOpcodeTable[NUM_MSG_TYPES];

static void DefineServerClientOpcode(int opcode, const char* name, SessionStatus status, PacketProcessing packetProcessing, void (WorldSession::*handler)(WorldPacket& recvPacket))
{
    clientServerOpcodeTable[opcode].name = name;
    clientServerOpcodeTable[opcode].status = status;
    clientServerOpcodeTable[opcode].packetProcessing = packetProcessing;
    clientServerOpcodeTable[opcode].handler = handler;
}
#define SERVERCLIENTOPCODE(name, status, packetProcessing, handler) DefineServerClientOpcode(name, #name, status, packetProcessing, handler)

void ClientServerOpcodeTable()
{
    for( int i = 0; i < NUM_MSG_TYPES; ++i )
    {
        DefineServerClientOpcode( i, "UNKNOWN",         STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL );
    }

    /********************************************/
    /************* CHANNEL OPCODES **************/
    /********************************************/
    SERVERCLIENTOPCODE(MSG_CHANNEL_START,         STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);
    SERVERCLIENTOPCODE(MSG_CHANNEL_UPDATE,        STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);

    /********************************************/
    /************ GAMEMASTER OPCODES ************/
    /********************************************/
    SERVERCLIENTOPCODE(MSG_GM_BIND_OTHER,         STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);
    SERVERCLIENTOPCODE(MSG_GM_SUMMON,             STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);
    SERVERCLIENTOPCODE(MSG_GM_SHOWLABEL,          STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);
    SERVERCLIENTOPCODE(MSG_GM_ACCOUNT_ONLINE,     STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);
    SERVERCLIENTOPCODE(MSG_GM_DESTROY_CORPSE,     STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);
    SERVERCLIENTOPCODE(MSG_GM_RESETINSTANCELIMIT, STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);
    SERVERCLIENTOPCODE(MSG_GM_GEARRATING,         STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);
    SERVERCLIENTOPCODE(MSG_GM_CHANGE_ARENA_RATING,STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);

    /********************************************/
    /************** GUILD OPCODES ***************/
    /********************************************/
    SERVERCLIENTOPCODE(MSG_SAVE_GUILD_EMBLEM,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSaveGuildEmblemOpcode     );
    SERVERCLIENTOPCODE(MSG_GUILD_BANK_LOG_QUERY,       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankLogQuery         );
    SERVERCLIENTOPCODE(MSG_GUILD_PERMISSIONS,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildPermissions          );
    SERVERCLIENTOPCODE(MSG_GUILD_BANK_MONEY_WITHDRAWN, STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankMoneyWithdrawn   );
    SERVERCLIENTOPCODE(MSG_GUILD_EVENT_LOG_QUERY,      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildEventLogQueryOpcode  );
    SERVERCLIENTOPCODE(MSG_QUERY_GUILD_BANK_TEXT,      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryGuildBankTabText     );

    /********************************************/
    /************ INSTANCES OPCODES *************/
    /********************************************/
    SERVERCLIENTOPCODE(MSG_BATTLEGROUND_PLAYER_POSITIONS, STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlegroundPlayerPositionsOpcode);
    SERVERCLIENTOPCODE(MSG_RAID_TARGET_UPDATE,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRaidTargetUpdateOpcode           );
    SERVERCLIENTOPCODE(MSG_RAID_READY_CHECK,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRaidReadyCheckOpcode             );
    SERVERCLIENTOPCODE(MSG_SET_DUNGEON_DIFFICULTY,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetDungeonDifficultyOpcode       );
    SERVERCLIENTOPCODE(MSG_PARTY_ASSIGNMENT,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePartyAssignmentOpcode            );
    SERVERCLIENTOPCODE(MSG_RAID_READY_CHECK_CONFIRM,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                             );
    SERVERCLIENTOPCODE(MSG_RAID_READY_CHECK_FINISHED,     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRaidReadyCheckFinishedOpcode     );
    SERVERCLIENTOPCODE(MSG_NOTIFY_PARTY_SQUELCH,          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                             );
    SERVERCLIENTOPCODE(MSG_SET_RAID_DIFFICULTY,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetRaidDifficultyOpcode          );

    /********************************************/
    /************* MOVEMENT OPCODES *************/
    /********************************************/
    // Movement Start
    SERVERCLIENTOPCODE(MSG_MOVE_START_FORWARD,            STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_START_BACKWARD,           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_START_STRAFE_LEFT,        STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_START_STRAFE_RIGHT,       STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_START_TURN_LEFT,          STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_START_TURN_RIGHT,         STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_START_PITCH_UP,           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_START_PITCH_DOWN,         STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_START_SWIM,               STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_START_SWIM_CHEAT,         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_START_ASCEND,             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_START_DESCEND,            STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);

    // Movement Stop
    SERVERCLIENTOPCODE(MSG_MOVE_STOP,                     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_STOP_STRAFE,              STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_STOP_TURN,                STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_STOP_PITCH,               STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_STOP_SWIM,                STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_STOP_SWIM_CHEAT,          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_STOP_ASCEND,              STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);

    // Movement Toggle
    SERVERCLIENTOPCODE(MSG_MOVE_TOGGLE_LOGGING,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_TOGGLE_FALL_LOGGING,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_TOGGLE_COLLISION_CHEAT,   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_TOGGLE_GRAVITY_CHEAT,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );

    // Movement Teleport / Fall / Fly / Water
    SERVERCLIENTOPCODE(MSG_MOVE_TELEPORT,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_TELEPORT_CHEAT,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_TELEPORT_ACK,             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveTeleportAck);
    SERVERCLIENTOPCODE(MSG_MOVE_JUMP,                     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_FALL_LAND,                STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_WORLDPORT_ACK,            STATUS_TRANSFER, PROCESS_THREADUNSAFE, &WorldSession::HandleMoveWorldportAckOpcode);
    SERVERCLIENTOPCODE(MSG_MOVE_FEATHER_FALL,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_WATER_WALK,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_UPDATE_CAN_FLY,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );

    // Movement Set...
    SERVERCLIENTOPCODE(MSG_MOVE_SET_RUN_MODE,             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_SET_WALK_MODE,            STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_SET_RUN_SPEED_CHEAT,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_RUN_SPEED,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_RUN_BACK_SPEED_CHEAT, STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_RUN_BACK_SPEED,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_WALK_SPEED_CHEAT,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_WALK_SPEED,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_SWIM_SPEED_CHEAT,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_SWIM_SPEED,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_SWIM_BACK_SPEED_CHEAT,STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_SWIM_BACK_SPEED,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_ALL_SPEED_CHEAT,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_TURN_RATE_CHEAT,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_TURN_RATE,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_FACING,               STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_SET_PITCH,                STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_SET_RAW_POSITION_ACK,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_FLIGHT_SPEED_CHEAT,   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_FLIGHT_SPEED,         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_FLIGHT_BACK_SPEED_CHEAT, STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL        );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_FLIGHT_BACK_SPEED,    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_PITCH_RATE_CHEAT,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_SET_PITCH_RATE,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );

    // Movement Uncategorized
    SERVERCLIENTOPCODE(MSG_MOVE_ROOT,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_UNROOT,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_HEARTBEAT,                STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    SERVERCLIENTOPCODE(MSG_MOVE_KNOCK_BACK,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_HOVER,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_TIME_SKIPPED,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    SERVERCLIENTOPCODE(MSG_MOVE_UNKNOWN_1234,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );

    /********************************************/
    /************* PETITION OPCODES *************/
    /********************************************/
    SERVERCLIENTOPCODE(MSG_PETITION_DECLINE,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionDeclineOpcode);
    SERVERCLIENTOPCODE(MSG_PETITION_RENAME,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionRenameOpcode );

    /********************************************/
    /*********** UNCATEGORIZED OPCODES **********/
    /********************************************/
    SERVERCLIENTOPCODE(MSG_MINIMAP_PING,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMinimapPingOpcode    );
    SERVERCLIENTOPCODE(MSG_TABARDVENDOR_ACTIVATE,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTabardVendorActivateOpcode);
    SERVERCLIENTOPCODE(MSG_RANDOM_ROLL,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRandomRollOpcode     );
    SERVERCLIENTOPCODE(MSG_CORPSE_QUERY,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCorpseQueryOpcode    );
    SERVERCLIENTOPCODE(MSG_AUCTION_HELLO,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionHelloOpcode   );
    SERVERCLIENTOPCODE(MSG_LIST_STABLED_PETS,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleListStabledPetsOpcode);
    SERVERCLIENTOPCODE(MSG_QUEST_PUSH_RESULT,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestPushResult      );
    SERVERCLIENTOPCODE(MSG_QUERY_NEXT_MAIL_TIME,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryNextMailTime    );
    SERVERCLIENTOPCODE(MSG_TALENT_WIPE_CONFIRM,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTalentWipeConfirmOpcode);
    SERVERCLIENTOPCODE(MSG_DELAY_GHOST_TELEPORT,          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                 );
    
    // PVP / Arena
    SERVERCLIENTOPCODE(MSG_INSPECT_HONOR_STATS,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInspectHonorStatsOpcode);
    SERVERCLIENTOPCODE(MSG_PVP_LOG_DATA,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePVPLogDataOpcode       );
    SERVERCLIENTOPCODE(MSG_INSPECT_ARENA_TEAMS,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInspectArenaTeamsOpcode);
};