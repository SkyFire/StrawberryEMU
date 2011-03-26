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

#include "OpcodeHandler.h"
#include "ClientOpcodeHandler.h"
#include "WorldSession.h"

void ClientOpcodeTable()
{
    /***********************************************************/
    /********************* ATTACK OPCODES **********************/
    /***********************************************************/
    OPCODE(CMSG_ATTACKSWING,  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAttackSwingOpcode);
    OPCODE(CMSG_ATTACKSTOP,   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAttackStopOpcode );

    /***********************************************************/
    /******************** AUCTION OPCODES **********************/
    /***********************************************************/
    OPCODE(CMSG_AUCTION_SELL_ITEM,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionSellItem      );
    OPCODE(CMSG_AUCTION_REMOVE_ITEM,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionRemoveItem    );
    OPCODE(CMSG_AUCTION_LIST_ITEMS,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionListItems     );
    OPCODE(CMSG_AUCTION_LIST_OWNER_ITEMS,   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionListOwnerItems);
    OPCODE(CMSG_AUCTION_PLACE_BID,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionPlaceBid      );
    OPCODE(CMSG_AUCTION_LIST_BIDDER_ITEMS,  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionListBidderItems);
    OPCODE(CMSG_AUCTION_LIST_PENDING_SALES, STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionListPendingSales);

    /***********************************************************/
    /***************** AUTHENTICATION OPCODES ******************/
    /***********************************************************/
    OPCODE(CMSG_AUTH_SESSION,           STATUS_NEVER,  PROCESS_INPLACE, &WorldSession::HandleEarlyProccess        );
    OPCODE(CMSG_REALM_SPLIT,            STATUS_AUTHED, PROCESS_THREADUNSAFE, &WorldSession::HandleRealmSplitOpcode);
    OPCODE(CMSG_REDIRECTION_FAILED,     STATUS_NEVER,  PROCESS_INPLACE,      &WorldSession::HandleNULL            );
    OPCODE(CMSG_UNKNOWN_1296,           STATUS_NEVER,  PROCESS_INPLACE,      &WorldSession::HandleNULL            );
    OPCODE(CMSG_REDIRECTION_AUTH_PROOF, STATUS_NEVER,  PROCESS_INPLACE,      &WorldSession::HandleNULL            );

    // SRP6
    OPCODE(CMSG_AUTH_SRP6_BEGIN,        STATUS_NEVER,  PROCESS_INPLACE,      &WorldSession::HandleNULL            );
    OPCODE(CMSG_AUTH_SRP6_PROOF,        STATUS_NEVER,  PROCESS_INPLACE,      &WorldSession::HandleNULL            );
    OPCODE(CMSG_AUTH_SRP6_RECODE,       STATUS_NEVER,  PROCESS_INPLACE,      &WorldSession::HandleNULL            );

    /***********************************************************/
    /******************* BATTLEFIELD OPCODES *******************/
    /***********************************************************/
    OPCODE(CMSG_BATTLEFIELD_LIST,       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlefieldListOpcode  );
    OPCODE(CMSG_BATTLEFIELD_JOIN,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_BATTLEFIELD_STATUS,     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlefieldStatusOpcode);
    OPCODE(CMSG_BATTLEFIELD_PORT,       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattleFieldPortOpcode  );
    OPCODE(CMSG_BATTLEMASTER_HELLO,     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlemasterHelloOpcode);
    OPCODE(CMSG_LEAVE_BATTLEFIELD,      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLeaveBattlefieldOpcode );
    OPCODE(CMSG_BATTLEMASTER_JOIN_ARENA,STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlemasterJoinArena  );
    OPCODE(CMSG_BATTLEFIELD_MGR_ENTRY_INVITE_RESPONSE, STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL    );
    OPCODE(CMSG_BATTLEFIELD_MGR_QUEUE_INVITE_RESPONSE, STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL    );
    OPCODE(CMSG_BATTLEFIELD_MGR_QUEUE_REQUEST, STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL            );
    OPCODE(CMSG_BATTLEFIELD_MGR_EXIT_REQUEST, STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL             );

    /***********************************************************/
    /******************** CALENDAR OPCODES *********************/
    /***********************************************************/
    OPCODE(CMSG_CALENDAR_GET_CALENDAR,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarGetCalendar         );
    OPCODE(CMSG_CALENDAR_GET_EVENT,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarGetEvent            );
    OPCODE(CMSG_CALENDAR_GUILD_FILTER,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarGuildFilter         );
    OPCODE(CMSG_CALENDAR_ARENA_TEAM,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarArenaTeam           );
    OPCODE(CMSG_CALENDAR_ADD_EVENT,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarAddEvent            );
    OPCODE(CMSG_CALENDAR_UPDATE_EVENT,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarUpdateEvent         );
    OPCODE(CMSG_CALENDAR_REMOVE_EVENT,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarRemoveEvent         );
    OPCODE(CMSG_CALENDAR_COPY_EVENT,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarCopyEvent           );
    OPCODE(CMSG_CALENDAR_EVENT_INVITE,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventInvite         );
    OPCODE(CMSG_CALENDAR_EVENT_RSVP,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventRsvp           );
    OPCODE(CMSG_CALENDAR_EVENT_REMOVE_INVITE,    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventRemoveInvite   );
    OPCODE(CMSG_CALENDAR_EVENT_STATUS,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventStatus         );
    OPCODE(CMSG_CALENDAR_EVENT_MODERATOR_STATUS, STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventModeratorStatus);
    OPCODE(CMSG_CALENDAR_COMPLAIN,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarComplain            );
    OPCODE(CMSG_CALENDAR_GET_NUM_PENDING,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarGetNumPending       );
    OPCODE(CMSG_CALENDAR_CONTEXT_EVENT_SIGNUP,   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                        );

    /***********************************************************/
    /******************** CHARACTER OPCODES ********************/
    /***********************************************************/
    OPCODE(CMSG_MOVE_CHARACTER_CHEAT,  STATUS_NEVER,  PROCESS_INPLACE, &WorldSession::HandleNULL                 );
    OPCODE(CMSG_CHAR_CREATE,           STATUS_AUTHED, PROCESS_THREADUNSAFE, &WorldSession::HandleCharCreateOpcode);
    OPCODE(CMSG_CHAR_ENUM,             STATUS_AUTHED, PROCESS_THREADUNSAFE, &WorldSession::HandleCharEnumOpcode  );
    OPCODE(CMSG_CHAR_DELETE,           STATUS_AUTHED, PROCESS_THREADUNSAFE, &WorldSession::HandleCharDeleteOpcode);
    OPCODE(CMSG_CHARACTER_POINT_CHEAT, STATUS_NEVER,  PROCESS_INPLACE,      &WorldSession::HandleNULL            );
    OPCODE(CMSG_CHAR_RENAME,           STATUS_AUTHED, PROCESS_THREADUNSAFE, &WorldSession::HandleCharRenameOpcode);
    OPCODE(CMSG_CHAR_CUSTOMIZE,        STATUS_AUTHED, PROCESS_THREADUNSAFE, &WorldSession::HandleCharCustomize   );
    OPCODE(CMSG_CHAR_FACTION_CHANGE,   STATUS_AUTHED, PROCESS_THREADUNSAFE, &WorldSession::HandleCharFactionOrRaceChange);
    OPCODE(CMSG_CHAR_RACE_CHANGE,      STATUS_AUTHED, PROCESS_THREADUNSAFE, &WorldSession::HandleCharFactionOrRaceChange);

    // Character World Login / Logout
    OPCODE(CMSG_PLAYER_LOGIN,          STATUS_AUTHED, PROCESS_THREADUNSAFE, &WorldSession::HandlePlayerLoginOpcode);
    OPCODE(CMSG_PLAYER_LOGOUT,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePlayerLogoutOpcode);
    OPCODE(CMSG_LOGOUT_REQUEST,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLogoutRequestOpcode);
    OPCODE(CMSG_LOGOUT_CANCEL,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLogoutCancelOpcode );

    /***********************************************************/
    /********************** CHAT OPCODES ***********************/
    /***********************************************************/
    OPCODE(CMSG_CHAT_IGNORED,    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChatIgnoredOpcode        );
    OPCODE(CMSG_GM_VISION,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                     );
    OPCODE(CMSG_CHAT_FILTERED,   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                     );
    OPCODE(CMSG_GM_WHISPER,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                     );
    OPCODE(CMSG_FORCE_SAY_CHEAT, STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                     );

    // Chat Message
    OPCODE(CMSG_MESSAGECHAT_SAY,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    OPCODE(CMSG_MESSAGECHAT_YELL,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    OPCODE(CMSG_MESSAGECHAT_CHANNEL,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    OPCODE(CMSG_MESSAGECHAT_WHISPER,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);    
    OPCODE(CMSG_MESSAGECHAT_GUILD,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    OPCODE(CMSG_MESSAGECHAT_OFFICER,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    OPCODE(CMSG_MESSAGECHAT_AFK,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    OPCODE(CMSG_MESSAGECHAT_DND,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    OPCODE(CMSG_MESSAGECHAT_EMOTE,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    OPCODE(CMSG_MESSAGECHAT_PARTY,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    OPCODE(CMSG_MESSAGECHAT_PARTY_LEADER,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    OPCODE(CMSG_MESSAGECHAT_RAID,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    OPCODE(CMSG_MESSAGECHAT_RAID_LEADER,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    OPCODE(CMSG_MESSAGECHAT_BATTLEGROUND,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);    
    OPCODE(CMSG_MESSAGECHAT_BATTLEGROUND_LEADER, STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    OPCODE(CMSG_MESSAGECHAT_RAID_WARNING,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);

    // Channel
    OPCODE(CMSG_JOIN_CHANNEL,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleJoinChannel       );
    OPCODE(CMSG_LEAVE_CHANNEL,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLeaveChannel      );
    OPCODE(CMSG_CHANNEL_LIST,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelList       );
    OPCODE(CMSG_CHANNEL_PASSWORD,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelPassword   );
    OPCODE(CMSG_CHANNEL_SET_OWNER,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelSetOwner   );
    OPCODE(CMSG_CHANNEL_OWNER,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelOwner      );
    OPCODE(CMSG_CHANNEL_MODERATOR,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelModerator  );
    OPCODE(CMSG_CHANNEL_UNMODERATOR,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelUnmoderator);
    OPCODE(CMSG_CHANNEL_MUTE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelMute       );
    OPCODE(CMSG_CHANNEL_UNMUTE,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelUnmute     );
    OPCODE(CMSG_CHANNEL_INVITE,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelInvite     );
    OPCODE(CMSG_CHANNEL_KICK,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelKick       );
    OPCODE(CMSG_CHANNEL_UNBAN,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelUnban      );
    OPCODE(CMSG_CHANNEL_ANNOUNCEMENTS,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelAnnouncements);
    OPCODE(CMSG_CHANNEL_MODERATE,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL              );
    OPCODE(CMSG_CHANNEL_SILENCE_VOICE,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL              );
    OPCODE(CMSG_CHANNEL_SILENCE_ALL,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL              );
    OPCODE(CMSG_CHANNEL_UNSILENCE_VOICE,         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL              );
    OPCODE(CMSG_CHANNEL_UNSILENCE_ALL,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL              );
    OPCODE(CMSG_CHANNEL_DISPLAY_LIST,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelDisplayListQuery);
    OPCODE(CMSG_GET_CHANNEL_MEMBER_COUNT,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGetChannelMemberCount);
    OPCODE(CMSG_SET_CHANNEL_WATCH,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetChannelWatch    );
    OPCODE(CMSG_CLEAR_CHANNEL_WATCH,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL               );
    OPCODE(CMSG_DECLINE_CHANNEL_INVITE,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelDeclineInvite);

    // Char Server Message
    OPCODE(CMSG_SERVER_BROADCAST,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL               );
    OPCODE(CMSG_SERVER_INFO_QUERY,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL               );

    /***********************************************************/
    /********************* COMBAT OPCODES **********************/
    /***********************************************************/
    OPCODE(CMSG_ENABLE_DAMAGE_LOG,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL               );

    /***********************************************************/
    /********************** DUEL OPCODES ***********************/
    /***********************************************************/
    OPCODE(CMSG_DUEL_ACCEPTED,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDuelAcceptedOpcode  );
    OPCODE(CMSG_DUEL_CANCELLED,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDuelCancelledOpcode );

    /***********************************************************/
    /******************** FACTION OPCODES **********************/
    /***********************************************************/
    OPCODE(CMSG_SET_FACTION_ATWAR,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetFactionAtWar      );
    OPCODE(CMSG_SET_FACTION_CHEAT,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetFactionCheat      );
    OPCODE(CMSG_SET_ACTION_BUTTON,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetActionButtonOpcode);
    OPCODE(CMSG_RESET_FACTION_CHEAT,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                 );
    OPCODE(CMSG_SET_FACTION_INACTIVE,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetFactionInactiveOpcode);
    OPCODE(CMSG_SET_WATCHED_FACTION,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetWatchedFactionOpcode);

    /***********************************************************/
    /******************* GAMEMASTER OPCODES ********************/
    /***********************************************************/
    OPCODE(CMSG_GM_INVIS,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_SET_SECURITY_GROUP,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_NUKE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_TEACH,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_CREATE_ITEM_TARGET,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_SILENCE,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_REVEALTO,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_RESURRECT,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_SUMMONMOB,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_MOVECORPSE,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_FREEZE,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_UBERINVIS,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_REQUEST_PLAYER_INFO,          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_UNTEACH,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_NUKE_ACCOUNT,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_DESTROY_ONLINE_CORPSE,        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_MAELSTROM_GM_SENT_MAIL,          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_SHOW_COMPLAINTS,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_UNSQUELCH,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_CHARACTER_RESTORE,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_CHARACTER_SAVE,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GMRESPONSE_RESOLVE,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMResponseResolve      );
    OPCODE(CMSG_GM_REPORT_LAG,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleReportLag              );

    // Gamemaster Ticket
    OPCODE(CMSG_GMTICKET_CREATE,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketCreateOpcode   );
    OPCODE(CMSG_GMTICKET_UPDATETEXT,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketUpdateOpcode   );
    OPCODE(CMSG_GMTICKET_GETTICKET,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketGetTicketOpcode);
    OPCODE(CMSG_GMTICKET_DELETETICKET,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketDeleteOpcode   );
    OPCODE(CMSG_GMTICKET_SYSTEMSTATUS,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketSystemStatusOpcode);
    OPCODE(CMSG_GMTICKETSYSTEM_TOGGLE,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GM_UPDATE_TICKET_STATUS,         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GMSURVEY_SUBMIT,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMSurveySubmit         );

    /***********************************************************/
    /****************** (GAME)OBJECT OPCODES *******************/
    /***********************************************************/
    OPCODE(CMSG_QUERY_OBJECT_POSITION,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_QUERY_OBJECT_ROTATION,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_CREATEGAMEOBJECT,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    OPCODE(CMSG_GAMEOBJ_USE,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGameObjectUseOpcode    );
    OPCODE(CMSG_GAMEOBJ_REPORT_USE,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGameobjectReportUse    );
    OPCODE(CMSG_DUMP_OBJECTS,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );

    /***********************************************************/
    /********************** GOSSIP OPCODES *********************/
    /***********************************************************/
    OPCODE(CMSG_GOSSIP_HELLO,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGossipHelloOpcode       );
    OPCODE(CMSG_GOSSIP_SELECT_OPTION,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGossipSelectOptionOpcode);
    OPCODE(CMSG_NPC_TEXT_QUERY,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleNpcTextQueryOpcode      );
    OPCODE(CMSG_BATTLEMASTER_JOIN,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlemasterJoinOpcode  );

    // Gossip Questgiver
    OPCODE(CMSG_QUESTGIVER_STATUS_QUERY,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverStatusQueryOpcode);
    OPCODE(CMSG_QUESTGIVER_HELLO,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverHelloOpcode      );
    OPCODE(CMSG_QUESTGIVER_QUERY_QUEST,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverQueryQuestOpcode );
    OPCODE(CMSG_QUESTGIVER_QUEST_AUTOLAUNCH,     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverQuestAutoLaunch  );
    OPCODE(CMSG_QUESTGIVER_ACCEPT_QUEST,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverAcceptQuestOpcode);
    OPCODE(CMSG_QUESTGIVER_COMPLETE_QUEST,       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverCompleteQuest    );
    OPCODE(CMSG_QUESTGIVER_REQUEST_REWARD,       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverRequestRewardOpcode);
    OPCODE(CMSG_QUESTGIVER_CHOOSE_REWARD,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverChooseRewardOpcode);
    OPCODE(CMSG_QUESTGIVER_CANCEL,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverCancel            );

    // Gossip Trainer
    OPCODE(CMSG_TRAINER_LIST,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTrainerListOpcode           );
    OPCODE(CMSG_TRAINER_BUY_SPELL,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTrainerBuySpellOpcode       );

    /***********************************************************/
    /********************** GROUP OPCODES **********************/
    /***********************************************************/
    OPCODE(CMSG_GROUP_INVITE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupInviteOpcode         );
    OPCODE(CMSG_GROUP_CANCEL,                    STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleNULL                      );
    OPCODE(CMSG_GROUP_ACCEPT,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupAcceptOpcode         );
    OPCODE(CMSG_GROUP_DECLINE,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupDeclineOpcode        );
    OPCODE(CMSG_GROUP_UNINVITE,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupUninviteOpcode       );
    OPCODE(CMSG_GROUP_UNINVITE_GUID,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupUninviteGuidOpcode   );
    OPCODE(CMSG_GROUP_SET_LEADER,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupSetLeaderOpcode      );
    OPCODE(CMSG_GROUP_DISBAND,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupDisbandOpcode        );
    OPCODE(CMSG_GROUP_CHANGE_SUB_GROUP,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupChangeSubGroupOpcode );
    OPCODE(CMSG_GROUP_SWAP_SUB_GROUP,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                      );
    OPCODE(CMSG_GROUP_RAID_CONVERT,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupRaidConvertOpcode    );
    OPCODE(CMSG_GROUP_ASSISTANT_LEADER,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupAssistantLeaderOpcode);
    
    /***********************************************************/
    /********************** GUILD OPCODES **********************/
    /***********************************************************/
    OPCODE(CMSG_GUILD_CREATE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildCreateOpcode );
    OPCODE(CMSG_GUILD_INVITE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildInviteOpcode );
    OPCODE(CMSG_GUILD_ACCEPT,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildAcceptOpcode );
    OPCODE(CMSG_GUILD_DECLINE,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildDeclineOpcode );
    OPCODE(CMSG_GUILD_INFO,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildInfoOpcode );
    OPCODE(CMSG_GUILD_ROSTER,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildRosterOpcode );
    OPCODE(CMSG_GUILD_PROMOTE,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildPromoteOpcode );
    OPCODE(CMSG_GUILD_DEMOTE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildDemoteOpcode );
    OPCODE(CMSG_GUILD_LEAVE,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildLeaveOpcode );
    OPCODE(CMSG_GUILD_REMOVE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildRemoveOpcode );
    OPCODE(CMSG_GUILD_DISBAND,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildDisbandOpcode );
    OPCODE(CMSG_GUILD_LEADER,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildLeaderOpcode );
    OPCODE(CMSG_GUILD_MOTD,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildMOTDOpcode );
    OPCODE(CMSG_GUILD_RANK,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildRankOpcode );
    OPCODE(CMSG_GUILD_ADD_RANK,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildAddRankOpcode );
    OPCODE(CMSG_GUILD_DEL_RANK,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildDelRankOpcode );
    OPCODE(CMSG_GUILD_SET_PUBLIC_NOTE,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildSetPublicNoteOpcode );
    OPCODE(CMSG_GUILD_SET_OFFICER_NOTE,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildSetOfficerNoteOpcode );
    OPCODE(CMSG_GUILD_INFO_TEXT,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildChangeInfoTextOpcode );
    OPCODE(CMSG_MAELSTROM_RENAME_GUILD,          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
     
    // Guild Bank
    OPCODE(CMSG_GUILD_BANKER_ACTIVATE,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankerActivate );
    OPCODE(CMSG_GUILD_BANK_QUERY_TAB,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankQueryTab );
    OPCODE(CMSG_GUILD_BANK_SWAP_ITEMS,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankSwapItems );
    OPCODE(CMSG_GUILD_BANK_BUY_TAB,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankBuyTab );
    OPCODE(CMSG_GUILD_BANK_UPDATE_TAB,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankUpdateTab );
    OPCODE(CMSG_GUILD_BANK_DEPOSIT_MONEY,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankDepositMoney );
    OPCODE(CMSG_GUILD_BANK_WITHDRAW_MONEY,       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankWithdrawMoney );
    OPCODE(CMSG_SET_GUILD_BANK_TEXT,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetGuildBankTabText );
    
    // Guild Petition
    OPCODE(CMSG_PETITION_SHOWLIST,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionShowListOpcode );
    OPCODE(CMSG_PETITION_BUY,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionBuyOpcode );
    OPCODE(CMSG_PETITION_SHOW_SIGNATURES,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionShowSignOpcode );
    OPCODE(CMSG_PETITION_SIGN,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionSignOpcode );
    OPCODE(CMSG_TURN_IN_PETITION,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTurnInPetitionOpcode );
    OPCODE(CMSG_OFFER_PETITION,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleOfferPetitionOpcode );
    OPCODE(CMSG_PETITION_QUERY,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionQueryOpcode );
    
    // Guild Party
    OPCODE(CMSG_REQUEST_PARTY_MEMBER_STATS,      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRequestPartyMemberStatsOpcode);
    OPCODE(CMSG_PARTY_SILENCE,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_PARTY_UNSILENCE,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    
    /***********************************************************/
    /******************** INSTANCE OPCODES *********************/
    /***********************************************************/
    OPCODE(CMSG_INSTANCE_LOCK_WARNING_RESPONSE,  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInstanceLockResponse );
    OPCODE(CMSG_REQUEST_RAID_INFO,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRequestRaidInfoOpcode );
    OPCODE(CMSG_EXPIRE_RAID_INSTANCE,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_SET_ALLOW_LOW_LEVEL_RAID1,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_SET_ALLOW_LOW_LEVEL_RAID2,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    
    // LFG
    OPCODE(CMSG_LFG_JOIN,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgJoinOpcode );
    OPCODE(CMSG_LFG_LEAVE,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgLeaveOpcode );
    OPCODE(CMSG_SEARCH_LFG_JOIN,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfrSearchOpcode );
    OPCODE(CMSG_SEARCH_LFG_LEAVE,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfrLeaveOpcode );
    OPCODE(CMSG_LFG_PROPOSAL_RESULT,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgProposalResultOpcode );
    OPCODE(CMSG_SET_LFG_COMMENT,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgSetCommentOpcode );
    OPCODE(CMSG_LFG_SET_ROLES,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgSetRolesOpcode );
    OPCODE(CMSG_LFG_SET_NEEDS,                   STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_LFG_SET_BOOT_VOTE,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgSetBootVoteOpcode );
    OPCODE(CMSG_LFD_PLAYER_LOCK_INFO_REQUEST,    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgPlayerLockInfoRequestOpcode);
    OPCODE(CMSG_LFG_TELEPORT,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgTeleportOpcode );
    OPCODE(CMSG_LFD_PARTY_LOCK_INFO_REQUEST,     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgPartyLockInfoRequestOpcode);
    
    // Meetingstone
    OPCODE(CMSG_MEETINGSTONE_INFO,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMeetingStoneInfo );
    OPCODE(CMSG_MEETINGSTONE_CHEAT,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    
    /***********************************************************/
    /********************** ITEM OPCODES ***********************/
    /***********************************************************/
    OPCODE(CMSG_CREATEITEM,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_USE_ITEM,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleUseItemOpcode );
    OPCODE(CMSG_OPEN_ITEM,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleOpenItemOpcode );
    OPCODE(CMSG_READ_ITEM,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleReadItem );
    OPCODE(CMSG_DESTROY_ITEMS,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_SWAP_ITEM,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSwapItem );
    OPCODE(CMSG_SWAP_INV_ITEM,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSwapInvItemOpcode );
    OPCODE(CMSG_SPLIT_ITEM,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSplitItemOpcode );
    OPCODE(OBSOLETE_DROP_ITEM,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_DESTROYITEM,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDestroyItemOpcode );
    OPCODE(CMSG_SELL_ITEM,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSellItemOpcode );
    OPCODE(CMSG_BUY_ITEM,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuyItemOpcode );
    OPCODE(CMSG_BUY_ITEM_IN_SLOT,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuyItemInSlotOpcode );
    OPCODE(CMSG_WRAP_ITEM,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWrapItemOpcode );
    OPCODE(CMSG_SET_DURABILITY_CHEAT,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_BUYBACK_ITEM,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuybackItem );
    OPCODE(CMSG_REPAIR_ITEM,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRepairItemOpcode );
    OPCODE(CMSG_SHOWING_HELM,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleShowingHelmOpcode );
    OPCODE(CMSG_SHOWING_CLOAK,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleShowingCloakOpcode );
    OPCODE(CMSG_SOCKET_GEMS,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSocketOpcode );
    OPCODE(CMSG_CANCEL_TEMP_ENCHANTMENT,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelTempEnchantmentOpcode);
    OPCODE(CMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_UPDATE_MISSILE_TRAJECTORY,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_ITEM_REFUND_INFO,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleItemRefundInfoRequest );
    OPCODE(CMSG_ITEM_REFUND,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleItemRefund );
    OPCODE(CMSG_UPDATE_PROJECTILE_POSITION,      STATUS_UNHANDLED,PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    
    // Item Equipment
    OPCODE(CMSG_AUTOEQUIP_GROUND_ITEM,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_AUTOSTORE_GROUND_ITEM,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_AUTOSTORE_LOOT_ITEM,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutostoreLootItemOpcode );
    OPCODE(CMSG_AUTOEQUIP_ITEM,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoEquipItemOpcode );
    OPCODE(CMSG_AUTOSTORE_BAG_ITEM,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoStoreBagItemOpcode );
    OPCODE(CMSG_AUTOEQUIP_ITEM_SLOT,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoEquipItemSlotOpcode );
    OPCODE(CMSG_EQUIPMENT_SET_DELETE,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEquipmentSetDelete );
    OPCODE(CMSG_AUTOSTORE_BANK_ITEM,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoStoreBankItemOpcode );
    OPCODE(CMSG_AUTOBANK_ITEM,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoBankItemOpcode );
    OPCODE(CMSG_EQUIPMENT_SET_SAVE,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEquipmentSetSave );
    OPCODE(CMSG_EQUIPMENT_SET_USE,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEquipmentSetUse );
    
    // Inventory / Trade
    OPCODE(CMSG_INSPECT,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInspectOpcode );
    OPCODE(CMSG_INITIATE_TRADE,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInitiateTradeOpcode );
    OPCODE(CMSG_BEGIN_TRADE,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBeginTradeOpcode );
    OPCODE(CMSG_BUSY_TRADE,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBusyTradeOpcode );
    OPCODE(CMSG_IGNORE_TRADE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleIgnoreTradeOpcode );
    OPCODE(CMSG_ACCEPT_TRADE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAcceptTradeOpcode );
    OPCODE(CMSG_UNACCEPT_TRADE,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleUnacceptTradeOpcode );
    OPCODE(CMSG_CANCEL_TRADE,                    STATUS_LOGGEDIN_OR_RECENTLY_LOGGOUT, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelTradeOpcode);
    OPCODE(CMSG_SET_TRADE_ITEM,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetTradeItemOpcode );
    OPCODE(CMSG_CLEAR_TRADE_ITEM,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleClearTradeItemOpcode );
    OPCODE(CMSG_SET_TRADE_GOLD,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetTradeGoldOpcode );
    OPCODE(CMSG_LIST_INVENTORY,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleListInventoryOpcode );
    
    /***********************************************************/
    /********************** LOOT OPCODES ***********************/
    /***********************************************************/
    OPCODE(CMSG_LOOT_METHOD,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootMethodOpcode );
    OPCODE(CMSG_STORE_LOOT_IN_SLOT,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_LOOT,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootOpcode );
    OPCODE(CMSG_LOOT_MONEY,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootMoneyOpcode );
    OPCODE(CMSG_LOOT_RELEASE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootReleaseOpcode );
    OPCODE(CMSG_OPT_OUT_OF_LOOT,                 STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleOptOutOfLootOpcode );
    
    // Loot Group
    OPCODE(CMSG_LOOT_ROLL,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootRoll );
    OPCODE(CMSG_LOOT_MASTER_GIVE,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootMasterGiveOpcode );
    
    /***********************************************************/
    /******************** MOVEMENT OPCODES *********************/
    /***********************************************************/
    OPCODE(CMSG_MOVE_SET_RAW_POSITION,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_MOVE_KNOCK_BACK_ACK,             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveKnockBackAck );
    OPCODE(CMSG_MOVE_HOVER_ACK,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMoveHoverAck );
    OPCODE(CMSG_MOVE_TIME_SKIPPED,               STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleMoveTimeSkippedOpcode );
    OPCODE(CMSG_MOVE_NOT_ACTIVE_MOVER,           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveNotActiveMover );
    OPCODE(CMSG_MINIGAME_MOVE,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_MOVE_CHNG_TRANSPORT,             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes );
    OPCODE(CMSG_UNKNOWN_1303,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
     
    // Movement Start / Stop
    OPCODE(CMSG_MOVE_START_SWIM_CHEAT,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_MOVE_STOP_SWIM_CHEAT,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );

    // Movement Force
    OPCODE(CMSG_FORCE_RUN_SPEED_CHANGE_ACK,      STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAck );
    OPCODE(CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK, STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAck );
    OPCODE(CMSG_FORCE_SWIM_SPEED_CHANGE_ACK,     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAck );
    OPCODE(CMSG_FORCE_MOVE_ROOT_ACK,             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveRootAck );
    OPCODE(CMSG_FORCE_MOVE_UNROOT_ACK,           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveUnRootAck );
    OPCODE(CMSG_FORCE_WALK_SPEED_CHANGE_ACK,     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAck );
    OPCODE(CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK, STATUS_LOGGEDIN, PROCESS_THREADSAFE,  &WorldSession::HandleForceSpeedChangeAck );
    OPCODE(CMSG_FORCE_TURN_RATE_CHANGE_ACK,      STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAck );
    OPCODE(CMSG_FORCE_FLIGHT_SPEED_CHANGE_ACK,   STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAck );
    OPCODE(CMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK, STATUS_LOGGEDIN, PROCESS_THREADSAFE, &WorldSession::HandleForceSpeedChangeAck );
    OPCODE(CMSG_FORCE_PITCH_RATE_CHANGE_ACK,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_FORCE_UNK1_SPEED_CHANGE_ACK,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_FORCE_UNK2_SPEED_CHANGE_ACK,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );

    // Movement Teleport / Fall / Fly / Water
    OPCODE(CMSG_MOVE_FALL_RESET,                 STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes );
    OPCODE(CMSG_MOVE_FEATHER_FALL_ACK,           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleFeatherFallAck );
    OPCODE(CMSG_MOVE_WATER_WALK_ACK,             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveWaterWalkAck );
    OPCODE(CMSG_MOVE_FLIGHT_ACK,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );

    // Movement Set / Unset
    OPCODE(CMSG_MOVE_SET_CAN_FLY_ACK,            STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveSetCanFlyAckOpcode );
    OPCODE(CMSG_MOVE_SET_FLY,                    STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes );
    OPCODE(CMSG_MOVE_SET_RUN_SPEED,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );

    // Spline
    OPCODE(CMSG_MOVE_SPLINE_DONE,                STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveSplineDoneOpcode );

    // Spline Set / Unset

    /***********************************************************/
    /********************* MOVIE OPCODES ***********************/
    /***********************************************************/

    // Cinematic 
    OPCODE(CMSG_TRIGGER_CINEMATIC_CHEAT,         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_OPENING_CINEMATIC,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_NEXT_CINEMATIC_CAMERA,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleNextCinematicCamera );
    OPCODE(CMSG_COMPLETE_CINEMATIC,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCompleteCinematic );

    // Movie
    OPCODE(CMSG_COMPLETE_MOVIE,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );

    /***********************************************************/ 
    /****************** MOUNT / PET OPCODES ********************/
    /***********************************************************/

    OPCODE(CMSG_MOUNTSPECIAL_ANIM,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMountSpecialAnimOpcode );
    OPCODE(CMSG_CANCEL_MOUNT_AURA,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelMountAuraOpcode );

    // Pet
    OPCODE(CMSG_PET_SET_ACTION,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetSetAction );
    OPCODE(CMSG_PET_ACTION,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetAction );
    OPCODE(CMSG_PET_ABANDON,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetAbandon );
    OPCODE(CMSG_PET_RENAME,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetRename );
    OPCODE(CMSG_PET_STOP_ATTACK,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetStopAttack );
    OPCODE(CMSG_PET_UNLEARN,                     STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_PET_LEARN_TALENT,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetLearnTalent );
    OPCODE(CMSG_PET_UNLEARN_TALENTS,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );

    /***********************************************************/
    /********************* PLAYER OPCODES **********************/
    /***********************************************************/

    OPCODE(CMSG_UNDRESSPLAYER,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_GODMODE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_PLAYER_DIFFICULTY_CHANGE,        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_PLAYER_AI_CHEAT,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_SET_ACTIONBAR_TOGGLES,           STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleSetActionBarToggles );
    OPCODE(CMSG_IGNORE_REQUIREMENTS_CHEAT,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_SET_PLAYER_DECLINED_NAMES,       STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleSetPlayerDeclinedNames );

    // Player Achievement
    OPCODE(CMSG_QUERY_INSPECT_ACHIEVEMENTS,      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryInspectAchievements );
    OPCODE(CMSG_COMPLETE_ACHIEVEMENT_CHEAT,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_SET_CRITERIA_CHEAT,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_CHECK_LOGIN_CRITERIA,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );

    // Player Exploration
    OPCODE(CMSG_SET_EXPLORATION,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_SET_EXPLORATION_ALL,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );

    // Friends / Contacts / ...
    OPCODE(CMSG_WHO,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWhoOpcode );
    OPCODE(CMSG_WHOIS,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWhoisOpcode );
    OPCODE(CMSG_CONTACT_LIST,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleContactListOpcode );
    OPCODE(CMSG_ADD_FRIEND,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAddFriendOpcode );
    OPCODE(CMSG_DEL_FRIEND,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDelFriendOpcode );
    OPCODE(CMSG_SET_CONTACT_NOTES,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetContactNotesOpcode );
    OPCODE(CMSG_SAVE_PLAYER,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_REFER_A_FRIEND,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );

    // Player Dance
    OPCODE(CMSG_SAVE_DANCE,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_PLAY_DANCE,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_LOAD_DANCES,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_STOP_DANCE,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_SYNC_DANCE,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_DANCE_QUERY,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_DELETE_DANCE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_LEARN_DANCE_MOVE,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_UNLEARN_DANCE_MOVE,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );

    // Player Level
    OPCODE(CMSG_LEVEL_CHEAT,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_SET_GRANTABLE_LEVELS,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_GRANT_LEVEL,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_ACCEPT_LEVEL_GRANT,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );

    // Player Pet
    OPCODE(CMSG_PET_LEVEL_CHEAT,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_STABLE_PET,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleStablePet );
    OPCODE(CMSG_UNSTABLE_PET,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleUnstablePet );
    OPCODE(CMSG_BUY_STABLE_SLOT,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuyStableSlot );
    OPCODE(CMSG_STABLE_REVIVE_PET,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleStableRevivePet );
    OPCODE(CMSG_STABLE_SWAP_PET,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleStableSwapPet );
    OPCODE(CMSG_REQUEST_PET_INFO,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRequestPetInfoOpcode );

    // Player PVP / Honor / ...
    OPCODE(CMSG_DISABLE_PVP_CHEAT,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_TOGGLE_PVP,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTogglePvP );
    OPCODE(CMSG_SET_PVP_RANK_CHEAT,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_ADD_PVP_MEDAL_CHEAT,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_DEL_PVP_MEDAL_CHEAT,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_SET_PVP_TITLE,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_SET_TITLE,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetTitleOpcode );
    OPCODE(CMSG_CHEAT_SET_HONOR_CURRENCY,        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_ACTIVE_PVP_CHEAT,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_REPORT_PVP_AFK,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleReportPvPAFK );
    OPCODE(CMSG_SET_TITLE_SUFFIX,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );

    // Player Arena
    OPCODE(CMSG_ARENA_TEAM_CREATE,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_ARENA_TEAM_QUERY,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamQueryOpcode );
    OPCODE(CMSG_ARENA_TEAM_ROSTER,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamRosterOpcode );
    OPCODE(CMSG_ARENA_TEAM_INVITE,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamInviteOpcode );
    OPCODE(CMSG_ARENA_TEAM_ACCEPT,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamAcceptOpcode );
    OPCODE(CMSG_ARENA_TEAM_DECLINE,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamDeclineOpcode );
    OPCODE(CMSG_ARENA_TEAM_LEAVE,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamLeaveOpcode );
    OPCODE(CMSG_ARENA_TEAM_REMOVE,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamRemoveOpcode );
    OPCODE(CMSG_ARENA_TEAM_DISBAND,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamDisbandOpcode );
    OPCODE(CMSG_ARENA_TEAM_LEADER,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamLeaderOpcode );
    OPCODE(CMSG_CHEAT_SET_ARENA_CURRENCY,        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_CHANGE_PERSONAL_ARENA_RATING,    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );

    // Player Tutorial
    OPCODE(CMSG_TUTORIAL_FLAG,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTutorialFlag );
    OPCODE(CMSG_TUTORIAL_CLEAR,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTutorialClear );
    OPCODE(CMSG_TUTORIAL_RESET,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTutorialReset );

    // Player Emote
    OPCODE(CMSG_EMOTE,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEmoteOpcode );
    OPCODE(CMSG_TEXT_EMOTE,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTextEmoteOpcode );

    // Player Corpse / Resurrect / Death
    OPCODE(CMSG_SETDEATHBINDPOINT,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_GETDEATHBINDZONE,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_REPOP_REQUEST,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRepopRequestOpcode );
    OPCODE(CMSG_RESURRECT_RESPONSE,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleResurrectResponseOpcode );
    OPCODE(CMSG_RECLAIM_CORPSE,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleReclaimCorpseOpcode );
    OPCODE(CMSG_GHOST,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_HEARTH_AND_RESURRECT,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleHearthAndResurrect );

    // Player Health / Power / Mana / ...
    OPCODE(CMSG_SET_RUNE_COUNT,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_SET_RUNE_COOLDOWN,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );

    // Player Glyph
    OPCODE(CMSG_SET_GLYPH_SLOT,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_SET_GLYPH,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_REMOVE_GLYPH,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRemoveGlyph );

    // Player Talent / Skill
    OPCODE(CMSG_UNLEARN_TALENTS,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_USE_SKILL_CHEAT,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_SKILL_BUY_STEP,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_SKILL_BUY_RANK,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_LEARN_TALENT,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLearnTalentOpcode );
    OPCODE(CMSG_LEARN_PREVIEW_TALENTS,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLearnPreviewTalents );
    OPCODE(CMSG_LEARN_PREVIEW_TALENTS_PET,       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLearnPreviewTalentsPet );

    // Player Mail
    OPCODE(CMSG_SEND_MAIL,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSendMail );
    OPCODE(CMSG_GET_MAIL_LIST,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGetMailList );
    OPCODE(CMSG_MAIL_TAKE_MONEY,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailTakeMoney );
    OPCODE(CMSG_MAIL_TAKE_ITEM,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailTakeItem );
    OPCODE(CMSG_MAIL_MARK_AS_READ,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailMarkAsRead );
    OPCODE(CMSG_MAIL_RETURN_TO_SENDER,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailReturnToSender );
    OPCODE(CMSG_MAIL_DELETE,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailDelete );
    OPCODE(CMSG_MAIL_CREATE_TEXT_ITEM,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailCreateTextItem );

    // Player Voice
    OPCODE(CMSG_VOICE_SET_TALKER_MUTED_REQUEST,  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_VOICE_SESSION_ENABLE,            STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleVoiceSessionEnableOpcode );
    OPCODE(CMSG_SET_ACTIVE_VOICE_CHANNEL,        STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleSetActiveVoiceChannel );
    OPCODE(CMSG_CHANNEL_VOICE_ON,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelVoiceOnOpcode );
    OPCODE(CMSG_CHANNEL_VOICE_OFF,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(SMSG_DEBUG_LIST_TARGETS,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide );
    OPCODE( CMSG_ADD_VOICE_IGNORE,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_DEL_VOICE_IGNORE,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );

    // Player Totem
    OPCODE(CMSG_TOTEM_DESTROYED,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTotemDestroyed );


    /***********************************************************/
    /********************* QUERY OPCODES ***********************/
    /***********************************************************/

    OPCODE(CMSG_NAME_QUERY,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleNameQueryOpcode );
    OPCODE(CMSG_PET_NAME_QUERY,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetNameQuery );
    OPCODE(CMSG_GUILD_QUERY,                     STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleGuildQueryOpcode );
    OPCODE(CMSG_ITEM_QUERY_SINGLE,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleItemQuerySingleOpcode );
    OPCODE(CMSG_ITEM_QUERY_MULTIPLE,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_PAGE_TEXT_QUERY,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePageTextQueryOpcode );
    OPCODE(CMSG_QUEST_QUERY,                     STATUS_LOGGEDIN_OR_RECENTLY_LOGGOUT, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestQueryOpcode );
    OPCODE(CMSG_GAMEOBJECT_QUERY,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGameObjectQueryOpcode );
    OPCODE(CMSG_CREATURE_QUERY,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCreatureQueryOpcode );
    OPCODE(CMSG_ITEM_TEXT_QUERY,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleItemTextQuery );
    OPCODE(CMSG_ITEM_NAME_QUERY,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleItemNameQueryOpcode );
    OPCODE(CMSG_CORPSE_MAP_POSITION_QUERY,       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCorpseMapPositionQuery );


    /***********************************************************/
    /********************* QUEST OPCODES ***********************/
    /***********************************************************/

    OPCODE(CMSG_FLAG_QUEST,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_FLAG_QUEST_FINISH,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_CLEAR_QUEST,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_QUESTLOG_SWAP_QUEST,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestLogSwapQuest );
    OPCODE(CMSG_QUESTLOG_REMOVE_QUEST,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestLogRemoveQuest );
    OPCODE(CMSG_QUEST_CONFIRM_ACCEPT,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestConfirmAccept );
    OPCODE(CMSG_PUSHQUESTTOPARTY,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePushQuestToParty );
    OPCODE(CMSG_QUEST_POI_QUERY,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestPOIQuery );
    OPCODE(CMSG_START_QUEST,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL );
    OPCODE(CMSG_QUERY_QUESTS_COMPLETED,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryQuestsCompleted );

    // Questgiver
    OPCODE(CMSG_QUESTGIVER_STATUS_MULTIPLE_QUERY, STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverStatusMultipleQuery);

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

    // World Teleport
    OPCODE(CMSG_WORLD_TELEPORT,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWorldTeleportOpcode);
    OPCODE(CMSG_WORLD_LOGIN,                     STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleWorldLoginOpcode   );
    OPCODE(CMSG_TELEPORT_TO_UNIT,                STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleNULL               );
    OPCODE(CMSG_REQUEST_ACCOUNT_DATA,            STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleRequestAccountData );
    OPCODE(CMSG_UPDATE_ACCOUNT_DATA,             STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleUpdateAccountData  );

};



