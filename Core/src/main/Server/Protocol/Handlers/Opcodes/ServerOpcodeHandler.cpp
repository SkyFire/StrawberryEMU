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

#include "ServerOpcodeHandler.h"
#include "WorldSession.h"

void ServerOpcodeTable()
{
    /***********************************************************/
    /********************* ATTACK OPCODES **********************/
    /***********************************************************/

    OPCODE(SMSG_ATTACKSTART,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);     
    OPCODE(SMSG_ATTACKSTOP,                             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_ATTACKSWING_NOTINRANGE,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_ATTACKSWING_BADFACING,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_ATTACKSWING_DEADTARGET,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_ATTACKSWING_CANT_ATTACK,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_ATTACKERSTATEUPDATE,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /******************** AUCTION OPCODES **********************/
    /***********************************************************/

    OPCODE(SMSG_AUCTION_COMMAND_RESULT,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AUCTION_LIST_RESULT,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AUCTION_OWNER_LIST_RESULT,              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AUCTION_BIDDER_NOTIFICATION,            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AUCTION_OWNER_NOTIFICATION,             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AUCTION_BIDDER_LIST_RESULT,             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AUCTION_REMOVED_NOTIFICATION,           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AUCTION_LIST_PENDING_SALES,             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /***************** AUTHENTICATION OPCODES ******************/
    /***********************************************************/

    OPCODE(SMSG_AUTH_SRP6_RESPONSE,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AUTH_CHALLENGE,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AUTH_RESPONSE,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_REALM_SPLIT,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_REDIRECT_CLIENT,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /******************* BATTLEFIELD OPCODES *******************/
    /***********************************************************/

    OPCODE(SMSG_BATTLEFIELD_PORT_DENIED,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_MGR_ENTRY_INVITE,           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_MGR_ENTERED,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_MGR_QUEUE_INVITE,           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_MGR_QUEUE_REQUEST_RESPONSE, STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_MGR_EJECT_PENDING,          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_MGR_EJECTED,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_MGR_STATE_CHANGE,           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_LIST,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_WIN_OBSOLETE,               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_LOSE_OBSOLETE,              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEFIELD_STATUS,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /********************* BINDING OPCODES *********************/
    /***********************************************************/

    OPCODE(SMSG_BINDPOINTUPDATE,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BINDZONEREPLY,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_PLAYERBOUND,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_PLAYERBINDERROR,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BINDER_CONFIRM,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /******************** CALENDAR OPCODES *********************/
    /***********************************************************/

    OPCODE(SMSG_CALENDAR_SEND_CALENDAR,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_SEND_EVENT,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_FILTER_GUILD,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_ARENA_TEAM,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_EVENT_INVITE,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_EVENT_INVITE_REMOVED,          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_EVENT_STATUS,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_COMMAND_RESULT,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_RAID_LOCKOUT_ADDED,            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_RAID_LOCKOUT_REMOVED,          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_EVENT_INVITE_ALERT,            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_EVENT_INVITE_REMOVED_ALERT,    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_EVENT_INVITE_STATUS_ALERT,     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_EVENT_REMOVED_ALERT,           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_EVENT_UPDATED_ALERT,           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_EVENT_MODERATOR_STATUS_ALERT,  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_SEND_NUM_PENDING,              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_UPDATE_INVITE_LIST,            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_NULL);
    OPCODE(SMSG_CALENDAR_UPDATE_INVITE_LIST2,           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_NULL);
    OPCODE(SMSG_CALENDAR_UPDATE_INVITE_LIST3,           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CALENDAR_ACTION_PENDING,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /******************** CHARACTER OPCODES ********************/
    /***********************************************************/

    OPCODE(SMSG_CHAR_CREATE,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CHAR_ENUM,                              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CHAR_DELETE,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CHARACTER_LOGIN_FAILED,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CHAR_RENAME,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CHAR_CUSTOMIZE,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CHAR_FACTION_CHANGE,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CHARACTER_PROFILE,                      STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CHARACTER_PROFILE_REALM_CONNECTED,      STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /********************** CHAT OPCODES ***********************/
    /***********************************************************/

    OPCODE(SMSG_MESSAGECHAT,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CHAT_WRONG_FACTION,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CHAT_PLAYER_NOT_FOUND,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CHAT_RESTRICTED,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CHAT_PLAYER_AMBIGUOUS,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_EXPECTED_SPAM_RECORDS,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_DEFENSE_MESSAGE,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_MOTD,                                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SERVER_INFO_RESPONSE,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    //Channel
    OPCODE(SMSG_CHANNEL_NOTIFY,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CHANNEL_LIST,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_CHANNEL_MEMBER_COUNT,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AVAILABLE_VOICE_CHANNEL,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /********************* COMBAT OPCODES **********************/
    /***********************************************************/

    OPCODE(SMSG_CANCEL_COMBAT,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    // Combat Log
    OPCODE(SMSG_SPELLBREAKLOG,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPELLHEALLOG,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPELLENERGIZELOG,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BREAK_TARGET,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPELLLOGMISS,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPELLLOGEXECUTE,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_DEBUGAURAPROC,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_PERIODICAURALOG,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPELLDAMAGESHIELD,                      STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPELLNONMELEEDAMAGELOG,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPELLDISPELLOG,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_DAMAGE_CALC_LOG,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPELLINSTAKILLLOG,                      STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPELLSTEALLOG,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPELL_CHANCE_PROC_LOG,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_AURACASTLOG,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_RESISTLOG,                              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_ENCHANTMENTLOG,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_PARTYKILLLOG,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_ENVIRONMENTALDAMAGELOG,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /********************** DUEL OPCODES ***********************/
    /***********************************************************/

    OPCODE(SMSG_DUEL_REQUESTED,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_DUEL_OUTOFBOUNDS,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_DUEL_INBOUNDS,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_DUEL_COMPLETE,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_DUEL_WINNER,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_DUEL_COUNTDOWN,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /******************** FACTION OPCODES **********************/
    /***********************************************************/

    OPCODE(SMSG_INITIALIZE_FACTIONS,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SET_FACTION_VISIBLE,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SET_FACTION_STANDING,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SET_FACTION_ATWAR,                      STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /******************* GAMEMASTER OPCODES ********************/
    /***********************************************************/

    OPCODE(SMSG_GM_PLAYER_INFO,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_NULL);
    OPCODE(SMSG_GM_MESSAGECHAT,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GMRESPONSE_DB_ERROR,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GMRESPONSE_RECEIVED,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);    
    OPCODE(SMSG_GMRESPONSE_STATUS_UPDATE,               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    
    //Ticket
    OPCODE(SMSG_GMTICKET_CREATE,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GMTICKET_UPDATETEXT,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GMTICKET_GETTICKET,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GMTICKET_SYSTEMSTATUS,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GMTICKET_DELETETICKET,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /****************** (GAME)OBJECT OPCODES *******************/
    /***********************************************************/

    OPCODE(SMSG_GAMEOBJECT_CUSTOM_ANIM,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GAMEOBJECT_PAGETEXT,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GAMEOBJECT_DESPAWN_ANIM,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GAMEOBJECT_RESET_STATE,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_DUMP_OBJECTS_DATA,                      STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /********************** GOSSIP OPCODES *********************/
    /***********************************************************/

    // Gossip General
    OPCODE(SMSG_GOSSIP_MESSAGE,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GOSSIP_COMPLETE,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_NPC_TEXT_UPDATE,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_NPC_WONT_TALK,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GOSSIP_POI,                             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    // Gossip Questgiver
    OPCODE(SMSG_QUESTGIVER_STATUS_MULTIPLE,             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_QUESTGIVER_QUEST_LIST,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_QUESTGIVER_QUEST_DETAILS,               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_QUESTGIVER_REQUEST_ITEMS,               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_QUESTGIVER_OFFER_REWARD,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_QUESTGIVER_QUEST_INVALID,               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_QUESTGIVER_QUEST_COMPLETE,              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_QUESTGIVER_QUEST_FAILED,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_QUESTGIVER_STATUS_MULTIPLE,             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /********************** GROUP OPCODES **********************/
    /***********************************************************/

    OPCODE(SMSG_GROUP_INVITE,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GROUP_CANCEL,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GROUP_DECLINE,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GROUP_UNINVITE,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GROUP_SET_LEADER,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GROUP_DESTROYED,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GROUP_LIST,                             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_REAL_GROUP_UPDATE,                      STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GROUPACTION_THROTTLED,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /********************** GUILD OPCODES **********************/
    /***********************************************************/

    OPCODE(SMSG_GUILD_INVITE,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GUILD_DECLINE,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GUILD_INFO,                             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GUILD_ROSTER,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GUILD_EVENT,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GUILD_COMMAND_RESULT,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_GUILD_BANK_LIST,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    // Party
    OPCODE(SMSG_PARTY_MEMBER_STATS,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_PARTY_COMMAND_RESULT,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_PARTY_MEMBER_STATS_FULL,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_ECHO_PARTY_SQUELCH,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    // Petition
    OPCODE(SMSG_BUY_BANK_SLOT_RESULT,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_PETITION_SHOWLIST,                      STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_PETITION_SHOW_SIGNATURES,               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_PETITION_SIGN_RESULTS,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_TURN_IN_PETITION_RESULTS,               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_PETITION_QUERY_RESPONSE,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_OFFER_PETITION_ERROR,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /******************** INSTANCE OPCODES *********************/
    /***********************************************************/

    OPCODE(SMSG_INSTANCE_LOCK_WARNING_QUERY,            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_UPDATE_INSTANCE_ENCOUNTER_UNIT,         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_RAID_GROUP_ONLY,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_INSTANCE_SAVE_CREATED,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_RAID_INSTANCE_INFO,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_RAID_INSTANCE_MESSAGE,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_UPDATE_INSTANCE_OWNERSHIP,              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_INSTANCE_DIFFICULTY,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_RESET_FAILED_NOTIFY,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_RAID_READY_CHECK_ERROR,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    // Lfg
    OPCODE(SMSG_LFG_PLAYER_REWARD,                      STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LFG_TELEPORT_DENIED,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LFG_OFFER_CONTINUE,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LFG_ROLE_CHOSEN,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_UPDATE_LFG_LIST,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LFG_PROPOSAL_UPDATE,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LFG_ROLE_CHECK_UPDATE,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LFG_JOIN_RESULT,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LFG_QUEUE_STATUS,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LFG_UPDATE_PLAYER,                      STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LFG_UPDATE_PARTY,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LFG_UPDATE_SEARCH,                      STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LFG_BOOT_PLAYER,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LFG_PLAYER_INFO,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LFG_PARTY_INFO,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LFG_DISABLED,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    
    // Meetingstone
    OPCODE(SMSG_MEETINGSTONE_SETQUEUE,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_MEETINGSTONE_COMPLETE,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_MEETINGSTONE_IN_PROGRESS,               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_MEETINGSTONE_MEMBER_ADDED,              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    // Battleground
    OPCODE(SMSG_GROUP_JOINED_BATTLEGROUND,              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEGROUND_PLAYER_JOINED,             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEGROUND_PLAYER_LEFT,               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_INSTANCE_RESET,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_INSTANCE_RESET_FAILED,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_UPDATE_LAST_INSTANCE,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_JOINED_BATTLEGROUND_QUEUE,              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BATTLEGROUND_INFO_THROTTLED,            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /********************** ITEM OPCODES ***********************/
    /***********************************************************/

    OPCODE(SMSG_READ_ITEM_OK,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_READ_ITEM_FAILED,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_ITEM_COOLDOWN,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_ITEM_PUSH_RESULT,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_ITEM_REFUND_INFO_RESPONSE,               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_ITEM_REFUND_RESULT,                      STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_UPDATE_ITEM_ENCHANTMENTS,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    // Inventory / Trade
    OPCODE(SMSG_INVENTORY_CHANGE_FAILURE,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_OPEN_CONTAINER,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_INSPECT,                                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_TRADE_STATUS,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_TRADE_STATUS_EXTENDED,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LIST_INVENTORY,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_EQUIPMENT_SET_LIST,                      STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    // Equipment
    OPCODE(SMSG_EQUIPMENT_SET_SAVED,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_EQUIPMENT_SET_USE_RESULT,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    // Item Buy / Sell
    OPCODE(SMSG_SELL_ITEM,                               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BUY_ITEM,                                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_BUY_FAILED,                              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /******************* LOGIN / OUT OPCODES *******************/
    /***********************************************************/

    //Login

    //Logout
    OPCODE(SMSG_LOGOUT_RESPONSE,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LOGOUT_COMPLETE,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LOGOUT_CANCEL_ACK,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /********************** LOOT OPCODES ***********************/
    /***********************************************************/

    OPCODE(SMSG_LOOT_RESPONSE,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LOOT_RELEASE_RESPONSE,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LOOT_REMOVED,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LOOT_MONEY_NOTIFY,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LOOT_ITEM_NOTIFY,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LOOT_CLEAR_MONEY,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LOOT_LIST,                               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LOOT_SLOT_CHANGED,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    // Loot Group
    OPCODE(SMSG_LOOT_ALL_PASSED,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LOOT_ROLL_WON,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LOOT_START_ROLL,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LOOT_ROLL,                               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_LOOT_MASTER_LIST,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_DYNAMIC_DROP_ROLL_RESULT,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /********************** MAIL OPCODES ***********************/
    /***********************************************************/

    OPCODE(SMSG_SEND_MAIL_RESULT,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_MAIL_LIST_RESULT,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_RECEIVED_MAIL,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    
    /***********************************************************/
    /******************** MOVEMENT OPCODES *********************/
    /***********************************************************/

    OPCODE(SMSG_MOVE_CHARACTER_CHEAT,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_NULL);
    OPCODE(SMSG_MOVE_WATER_WALK,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_MOVE_LAND_WALK,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_FORCE_SWIM_SPEED_CHANGE,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_MOVE_KNOCK_BACK,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_COMPRESSED_MOVES,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_MOVE_ABANDON_TRANSPORT,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_UNKNOWN_1302,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_UNKNOWN_1304,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    // Movement Force
    OPCODE(SMSG_FORCE_RUN_SPEED_CHANGE,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_FORCE_RUN_BACK_SPEED_CHANGE,             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_FORCE_MOVE_ROOT,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_FORCE_MOVE_UNROOT,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_FORCE_WALK_SPEED_CHANGE,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_FORCE_SWIM_BACK_SPEED_CHANGE,            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_FORCE_TURN_RATE_CHANGE,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_FORCE_FLIGHT_SPEED_CHANGE,               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE,          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_FORCE_UNK1_SPEED_CHANGE,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_FORCE_UNK2_SPEED_CHANGE,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_FORCE_PITCH_RATE_CHANGE,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    
    // Movement Teleport / Fall / Fly / Water
    OPCODE(SMSG_MOVE_FEATHER_FALL,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_MOVE_NORMAL_FALL,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    // Movement Set / Unset
    OPCODE(SMSG_MOVE_SET_HOVER,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_MOVE_UNSET_HOVER,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_MOVE_SET_FLIGHT,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_MOVE_UNSET_FLIGHT,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_MOVE_SET_CAN_FLY,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_MOVE_UNSET_CAN_FLY,                      STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    // Spline
    OPCODE(SMSG_SPLINE_MOVE_UNROOT,                      STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_MOVE_FEATHER_FALL,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_MOVE_NORMAL_FALL,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_MOVE_SET_HOVER,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_MOVE_UNSET_HOVER,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_MOVE_WATER_WALK,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_MOVE_LAND_WALK,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_MOVE_START_SWIM,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_MOVE_STOP_SWIM,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_MOVE_SET_RUN_MODE,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_MOVE_SET_WALK_MODE,               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_MOVE_ROOT,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_MOVE_UNKNOWN_1235,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_MOVE_UNKNOWN_1236,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_SET_PITCH_RATE,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    // Spline Set / Unset
    OPCODE(SMSG_SPLINE_SET_RUN_SPEED,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_SET_RUN_BACK_SPEED,               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_SET_SWIM_SPEED,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_SET_WALK_SPEED,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_SET_SWIM_BACK_SPEED,              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_SET_TURN_RATE,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_SET_FLIGHT_SPEED,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_SET_FLIGHT_BACK_SPEED,            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_MOVE_SET_FLYING,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_SPLINE_MOVE_UNSET_FLYING,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /********************* MOVIE OPCODES ***********************/
    /***********************************************************/

     // Cinematic
    OPCODE(SMSG_TRIGGER_CINEMATIC,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    // Movie
    OPCODE(SMSG_TRIGGER_MOVIE,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);


    /***********************************************************/
    /****************** MOUNT / PET OPCODES ********************/
    /***********************************************************/

    // Mount
    OPCODE(SMSG_MOUNTRESULT,                             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_DISMOUNTRESULT,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_PUREMOUNT_CANCELLED_OBSOLETE,            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_MOUNTSPECIAL_ANIM,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_DISMOUNT,                                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    // Pet
    OPCODE(SMSG_PET_TAME_FAILURE,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_PET_NAME_INVALID,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_PET_SPELLS,                              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_PET_MODE,                                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);
    OPCODE(SMSG_PET_UPDATE_COMBO_POINTS,                 STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /********************** MULTI OPCODES **********************/
    /***********************************************************/

    OPCODE(SMSG_MULTIPLE_PACKETS,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

    /***********************************************************/
    /********************* PLAYER OPCODES **********************/
    /***********************************************************/

    OPCODE(SMSG_PLAYER_DIFFICULTY_CHANGE,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_PLAYER_SKINNED,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_ADDON_INFO,                              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_GHOSTEE_GONE,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_TITLE_EARNED,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_UPDATE_COMBO_POINTS,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_CHEAT_PLAYER_LOOKUP,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_KICK_REASON,                             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_SET_PLAYER_DECLINED_NAMES_RESULT,        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_HIGHEST_THREAT_UPDATE,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_THREAT_UPDATE,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_THREAT_REMOVE,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_THREAT_CLEAR,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );

    // Player Dance
    OPCODE(SMSG_NOTIFY_DANCE,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_PLAY_DANCE,                              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_STOP_DANCE,                              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_DANCE_QUERY_RESPONSE,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_INVALIDATE_DANCE,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_LEARNED_DANCE_MOVES,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );

    // Player Achievement
    OPCODE(SMSG_ACHIEVEMENT_EARNED,                      STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_CRITERIA_UPDATE,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_RESPOND_INSPECT_ACHIEVEMENTS,            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_ALL_ACHIEVEMENT_DATA,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_SERVER_FIRST_ACHIEVEMENT,                STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_CRITERIA_DELETED,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_ACHIEVEMENT_DELETED,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );

    // Player Exploration
    OPCODE(SMSG_EXPLORATION_EXPERIENCE,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );

    // Player Corpse / Resurrect / Death
    OPCODE(SMSG_RESURRECT_REQUEST,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_RESURRECT_FAILED,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_CORPSE_RECLAIM_DELAY,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_FEIGN_DEATH_RESISTED,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_DEATH_RELEASE_LOC,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_FORCED_DEATH_UPDATE,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_PRE_RESURRECT,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_CORPSE_NOT_IN_INSTANCE,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );

    // Player Pet
    OPCODE(SMSG_STABLE_RESULT,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_SUMMON_REQUEST,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_PET_BROKEN,                              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_PET_ACTION_FEEDBACK,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_PET_UNLEARN_CONFIRM,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_PET_RENAMEABLE,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_PET_GUIDS,                               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_PET_ACTION_SOUND,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_PET_DISMISS_SOUND,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );

    // Player PVP / Honor / Arena
    OPCODE(SMSG_PVP_CREDIT,                              STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_ARENA_TEAM_COMMAND_RESULT,               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_ARENA_TEAM_QUERY_RESPONSE,               STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_ARENA_TEAM_ROSTER,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_ARENA_TEAM_INVITE,                       STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_ARENA_TEAM_EVENT,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_ARENA_TEAM_STATS,                        STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_ARENA_ERROR,                             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_REPORT_PVP_AFK_RESULT,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(SMSG_ARENA_OPPONENT_UPDATE,                   STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_ARENA_TEAM_CHANGE_FAILED_QUEUED,         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    
    // Player Minigame
    OPCODE(SMSG_MINIGAME_SETUP,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_MINIGAME_STATE,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_MINIGAME_MOVE_FAILED,                    STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );

    // Friends / Contacts / ...
    OPCODE(SMSG_USERLIST_ADD,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_USERLIST_REMOVE,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_USERLIST_UPDATE,                         STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_REFER_A_FRIEND_FAILURE,                  STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );

    // Talents
    OPCODE(SMSG_INSPECT_TALENT,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_TALENTS_INFO,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_TALENTS_INVOLUNTARILY_RESET,             STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );

    // Totem
    OPCODE(SMSG_TOTEM_CREATED,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );

    // Barber 
    OPCODE(SMSG_ENABLE_BARBER_SHOP,                      STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_BARBER_SHOP_RESULT,                      STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );

    // Player Health / Power / Mana / ...
    OPCODE(SMSG_HEALTH_UPDATE,                           STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_POWER_UPDATE,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_CONVERT_RUNE,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_RESYNC_RUNES,                            STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE(SMSG_ADD_RUNE_POWER,                          STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );

    // Player Vehicle
    OPCODE(SMSG_PLAYER_VEHICLE_DATA,                     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );

    /***********************************************************/
    /********************* QUERY OPCODES ***********************/
    /***********************************************************/



    /***********************************************************/
    /********************* QUEST OPCODES ***********************/
    /***********************************************************/



    /***********************************************************/
    /********************* SPELL OPCODES ***********************/
    /***********************************************************/



    /***********************************************************/
    /******************* TRANSPORT OPCODES *********************/
    /***********************************************************/



    /***********************************************************/
    /****************** TIME / SPEED OPCODES *******************/
    /***********************************************************/



    /***********************************************************/
    /****************** UNCATEGORZIED OPCODES ******************/
    /***********************************************************/



    /***********************************************************/
    /********************** WORLD OPCODES **********************/
    /***********************************************************/



    

};


