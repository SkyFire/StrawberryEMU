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

void ClientServerOpcodeTable()
{
    /********************************************/
    /************* CHANNEL OPCODES **************/
    /********************************************/
    OPCODE(MSG_CHANNEL_START,         STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);
    OPCODE(MSG_CHANNEL_UPDATE,        STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);

    /********************************************/
    /************ GAMEMASTER OPCODES ************/
    /********************************************/
    OPCODE(MSG_GM_BIND_OTHER,         STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);
    OPCODE(MSG_GM_SUMMON,             STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);
    OPCODE(MSG_GM_SHOWLABEL,          STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);
    OPCODE(MSG_GM_ACCOUNT_ONLINE,     STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);
    OPCODE(MSG_GM_DESTROY_CORPSE,     STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);
    OPCODE(MSG_GM_RESETINSTANCELIMIT, STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);
    OPCODE(MSG_GM_GEARRATING,         STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);
    OPCODE(MSG_GM_CHANGE_ARENA_RATING,STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL);

    /********************************************/
    /************** GUILD OPCODES ***************/
    /********************************************/
    OPCODE(MSG_SAVE_GUILD_EMBLEM,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSaveGuildEmblemOpcode     );
    OPCODE(MSG_GUILD_BANK_LOG_QUERY,       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankLogQuery         );
    OPCODE(MSG_GUILD_PERMISSIONS,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildPermissions          );
    OPCODE(MSG_GUILD_BANK_MONEY_WITHDRAWN, STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankMoneyWithdrawn   );
    OPCODE(MSG_GUILD_EVENT_LOG_QUERY,      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildEventLogQueryOpcode  );
    OPCODE(MSG_QUERY_GUILD_BANK_TEXT,      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryGuildBankTabText     );

    /********************************************/
    /************ INSTANCES OPCODES *************/
    /********************************************/
    OPCODE(MSG_BATTLEGROUND_PLAYER_POSITIONS, STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlegroundPlayerPositionsOpcode);
    OPCODE(MSG_RAID_TARGET_UPDATE,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRaidTargetUpdateOpcode           );
    OPCODE(MSG_RAID_READY_CHECK,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRaidReadyCheckOpcode             );
    OPCODE(MSG_SET_DUNGEON_DIFFICULTY,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetDungeonDifficultyOpcode       );
    OPCODE(MSG_PARTY_ASSIGNMENT,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePartyAssignmentOpcode            );
    OPCODE(MSG_RAID_READY_CHECK_CONFIRM,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                             );
    OPCODE(MSG_RAID_READY_CHECK_FINISHED,     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRaidReadyCheckFinishedOpcode     );
    OPCODE(MSG_NOTIFY_PARTY_SQUELCH,          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                             );
    OPCODE(MSG_SET_RAID_DIFFICULTY,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetRaidDifficultyOpcode          );

    /********************************************/
    /************* MOVEMENT OPCODES *************/
    /********************************************/
    // Movement Start
    OPCODE(MSG_MOVE_START_FORWARD,            STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_START_BACKWARD,           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_START_STRAFE_LEFT,        STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_START_STRAFE_RIGHT,       STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_START_TURN_LEFT,          STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_START_TURN_RIGHT,         STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_START_PITCH_UP,           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_START_PITCH_DOWN,         STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_START_SWIM,               STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_START_SWIM_CHEAT,         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_START_ASCEND,             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_START_DESCEND,            STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);

    // Movement Stop
    OPCODE(MSG_MOVE_STOP,                     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_STOP_STRAFE,              STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_STOP_TURN,                STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_STOP_PITCH,               STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_STOP_SWIM,                STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_STOP_SWIM_CHEAT,          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_STOP_ASCEND,              STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);

    // Movement Toggle
    OPCODE(MSG_MOVE_TOGGLE_LOGGING,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_TOGGLE_FALL_LOGGING,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_TOGGLE_COLLISION_CHEAT,   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_TOGGLE_GRAVITY_CHEAT,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );

    // Movement Teleport / Fall / Fly / Water
    OPCODE(MSG_MOVE_TELEPORT,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_TELEPORT_CHEAT,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_TELEPORT_ACK,             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveTeleportAck);
    OPCODE(MSG_MOVE_JUMP,                     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_FALL_LAND,                STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_WORLDPORT_ACK,            STATUS_TRANSFER, PROCESS_THREADUNSAFE, &WorldSession::HandleMoveWorldportAckOpcode);
    OPCODE(MSG_MOVE_FEATHER_FALL,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_WATER_WALK,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_UPDATE_CAN_FLY,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );

    // Movement Set...
    OPCODE(MSG_MOVE_SET_RUN_MODE,             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_SET_WALK_MODE,            STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_SET_RUN_SPEED_CHEAT,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_SET_RUN_SPEED,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_SET_RUN_BACK_SPEED_CHEAT, STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_SET_RUN_BACK_SPEED,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_SET_WALK_SPEED_CHEAT,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_SET_WALK_SPEED,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_SET_SWIM_SPEED_CHEAT,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_SET_SWIM_SPEED,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_SET_SWIM_BACK_SPEED_CHEAT,STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_SET_SWIM_BACK_SPEED,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_SET_ALL_SPEED_CHEAT,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_SET_TURN_RATE_CHEAT,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_SET_TURN_RATE,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_SET_FACING,               STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_SET_PITCH,                STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_SET_RAW_POSITION_ACK,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_SET_FLIGHT_SPEED_CHEAT,   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_SET_FLIGHT_SPEED,         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_SET_FLIGHT_BACK_SPEED_CHEAT, STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL        );
    OPCODE(MSG_MOVE_SET_FLIGHT_BACK_SPEED,    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_SET_PITCH_RATE_CHEAT,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_SET_PITCH_RATE,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );

    // Movement Uncategorized
    OPCODE(MSG_MOVE_ROOT,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_UNROOT,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_HEARTBEAT,                STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes);
    OPCODE(MSG_MOVE_KNOCK_BACK,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_HOVER,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_TIME_SKIPPED,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );
    OPCODE(MSG_MOVE_UNKNOWN_1234,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL           );

    /********************************************/
    /************* PETITION OPCODES *************/
    /********************************************/
    OPCODE(MSG_PETITION_DECLINE,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionDeclineOpcode);
    OPCODE(MSG_PETITION_RENAME,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionRenameOpcode );

    /********************************************/
    /*********** UNCATEGORIZED OPCODES **********/
    /********************************************/
    OPCODE(MSG_MINIMAP_PING,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMinimapPingOpcode    );
    OPCODE(MSG_TABARDVENDOR_ACTIVATE,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTabardVendorActivateOpcode);
    OPCODE(MSG_RANDOM_ROLL,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRandomRollOpcode     );
    OPCODE(MSG_CORPSE_QUERY,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCorpseQueryOpcode    );
    OPCODE(MSG_AUCTION_HELLO,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionHelloOpcode   );
    OPCODE(MSG_LIST_STABLED_PETS,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleListStabledPetsOpcode);
    OPCODE(MSG_QUEST_PUSH_RESULT,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestPushResult      );
    OPCODE(MSG_QUERY_NEXT_MAIL_TIME,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryNextMailTime    );
    OPCODE(MSG_TALENT_WIPE_CONFIRM,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTalentWipeConfirmOpcode);
    OPCODE(MSG_DELAY_GHOST_TELEPORT,          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                 );
    
    // PVP / Arena
    OPCODE(MSG_INSPECT_HONOR_STATS,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInspectHonorStatsOpcode);
    OPCODE(MSG_PVP_LOG_DATA,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePVPLogDataOpcode       );
    OPCODE(MSG_INSPECT_ARENA_TEAMS,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInspectArenaTeamsOpcode);
};