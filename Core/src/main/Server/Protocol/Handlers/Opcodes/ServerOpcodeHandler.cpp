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
    OPCODE( SMSG_CHARACTER_PROFILE_REALM_CONNECTED,     STATUS_NEVER,     PROCESS_INPLACE,      &WorldSession::Handle_ServerSide);

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



    /***********************************************************/
    /********************** ITEM OPCODES ***********************/
    /***********************************************************/



    /***********************************************************/
    /******************* LOGIN / OUT OPCODES *******************/
    /***********************************************************/



    /***********************************************************/
    /********************** LOOT OPCODES ***********************/
    /***********************************************************/



    /***********************************************************/
    /******************** MOVEMENT OPCODES *********************/
    /***********************************************************/



    /***********************************************************/
    /********************* MOVIE OPCODES ***********************/
    /***********************************************************/



    /***********************************************************/
    /****************** MOUNT / PET OPCODES ********************/
    /***********************************************************/



    /***********************************************************/
    /********************** MULTI OPCODES **********************/
    /***********************************************************/



    /***********************************************************/
    /********************* PLAYER OPCODES **********************/
    /***********************************************************/



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


