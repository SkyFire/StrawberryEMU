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
};
