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

#include "ClientOpcodeHandler.h"
#include "WorldSession.h"

ClientOpcodeHandler clientOpcodeTable[NUM_MSG_TYPES];

static void DefineClientOpcode(int opcode, const char* name, SessionStatus status, PacketProcessing packetProcessing, void (WorldSession::*handler)(WorldPacket& recvPacket))
{
    clientOpcodeTable[opcode].name = name;
    clientOpcodeTable[opcode].status = status;
    clientOpcodeTable[opcode].packetProcessing = packetProcessing;
    clientOpcodeTable[opcode].handler = handler;
}
#define CLIENTOPCODE(name, status, packetProcessing, handler) DefineClientOpcode(name, #name, status, packetProcessing, handler)

void ClientOpcodeTable()
{
    for( int i = 0; i < NUM_MSG_TYPES; ++i )
    {
        DefineClientOpcode( i, "UNKNOWN",         STATUS_NEVER, PROCESS_INPLACE, &WorldSession::HandleNULL );
    }

    /***********************************************************/
    /********************* ATTACK OPCODES **********************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_ATTACKSWING,  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAttackSwingOpcode);
    CLIENTOPCODE(CMSG_ATTACKSTOP,   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAttackStopOpcode );

    /***********************************************************/
    /******************** AUCTION OPCODES **********************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_AUCTION_SELL_ITEM,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionSellItem      );
    CLIENTOPCODE(CMSG_AUCTION_REMOVE_ITEM,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionRemoveItem    );
    CLIENTOPCODE(CMSG_AUCTION_LIST_ITEMS,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionListItems     );
    CLIENTOPCODE(CMSG_AUCTION_LIST_OWNER_ITEMS,   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionListOwnerItems);
    CLIENTOPCODE(CMSG_AUCTION_PLACE_BID,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionPlaceBid      );
    CLIENTOPCODE(CMSG_AUCTION_LIST_BIDDER_ITEMS,  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionListBidderItems);
    CLIENTOPCODE(CMSG_AUCTION_LIST_PENDING_SALES, STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionListPendingSales);

    /***********************************************************/
    /***************** AUTHENTICATION OPCODES ******************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_AUTH_SESSION,           STATUS_NEVER,  PROCESS_INPLACE,      &WorldSession::HandleEarlyProccess   );
    CLIENTOPCODE(CMSG_REALM_SPLIT,            STATUS_AUTHED, PROCESS_THREADUNSAFE, &WorldSession::HandleRealmSplitOpcode);
    CLIENTOPCODE(CMSG_REDIRECTION_FAILED,     STATUS_NEVER,  PROCESS_INPLACE,      &WorldSession::HandleNULL            );
    CLIENTOPCODE(CMSG_UNKNOWN_1296,           STATUS_NEVER,  PROCESS_INPLACE,      &WorldSession::HandleNULL            );
    CLIENTOPCODE(CMSG_REDIRECTION_AUTH_PROOF, STATUS_NEVER,  PROCESS_INPLACE,      &WorldSession::HandleNULL            );

    // SRP6
    CLIENTOPCODE(CMSG_AUTH_SRP6_BEGIN,        STATUS_NEVER,  PROCESS_INPLACE,      &WorldSession::HandleNULL            );
    CLIENTOPCODE(CMSG_AUTH_SRP6_PROOF,        STATUS_NEVER,  PROCESS_INPLACE,      &WorldSession::HandleNULL            );
    CLIENTOPCODE(CMSG_AUTH_SRP6_RECODE,       STATUS_NEVER,  PROCESS_INPLACE,      &WorldSession::HandleNULL            );

    /***********************************************************/
    /******************* BATTLEFIELD OPCODES *******************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_BATTLEFIELD_LIST,       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlefieldListOpcode  );
    CLIENTOPCODE(CMSG_BATTLEFIELD_JOIN,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_BATTLEFIELD_STATUS,     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlefieldStatusOpcode);
    CLIENTOPCODE(CMSG_BATTLEFIELD_PORT,       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattleFieldPortOpcode  );
    CLIENTOPCODE(CMSG_BATTLEMASTER_HELLO,     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlemasterHelloOpcode);
    CLIENTOPCODE(CMSG_LEAVE_BATTLEFIELD,      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLeaveBattlefieldOpcode );
    CLIENTOPCODE(CMSG_BATTLEMASTER_JOIN_ARENA,STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlemasterJoinArena  );
    CLIENTOPCODE(CMSG_BATTLEFIELD_MGR_ENTRY_INVITE_RESPONSE, STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL    );
    CLIENTOPCODE(CMSG_BATTLEFIELD_MGR_QUEUE_INVITE_RESPONSE, STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL    );
    CLIENTOPCODE(CMSG_BATTLEFIELD_MGR_QUEUE_REQUEST, STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL            );
    CLIENTOPCODE(CMSG_BATTLEFIELD_MGR_EXIT_REQUEST, STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL             );

    /***********************************************************/
    /******************** CALENDAR OPCODES *********************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_CALENDAR_GET_CALENDAR,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarGetCalendar         );
    CLIENTOPCODE(CMSG_CALENDAR_GET_EVENT,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarGetEvent            );
    CLIENTOPCODE(CMSG_CALENDAR_GUILD_FILTER,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarGuildFilter         );
    CLIENTOPCODE(CMSG_CALENDAR_ARENA_TEAM,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarArenaTeam           );
    CLIENTOPCODE(CMSG_CALENDAR_ADD_EVENT,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarAddEvent            );
    CLIENTOPCODE(CMSG_CALENDAR_UPDATE_EVENT,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarUpdateEvent         );
    CLIENTOPCODE(CMSG_CALENDAR_REMOVE_EVENT,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarRemoveEvent         );
    CLIENTOPCODE(CMSG_CALENDAR_COPY_EVENT,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarCopyEvent           );
    CLIENTOPCODE(CMSG_CALENDAR_EVENT_INVITE,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventInvite         );
    CLIENTOPCODE(CMSG_CALENDAR_EVENT_RSVP,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventRsvp           );
    CLIENTOPCODE(CMSG_CALENDAR_EVENT_REMOVE_INVITE,    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventRemoveInvite   );
    CLIENTOPCODE(CMSG_CALENDAR_EVENT_STATUS,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventStatus         );
    CLIENTOPCODE(CMSG_CALENDAR_EVENT_MODERATOR_STATUS, STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventModeratorStatus);
    CLIENTOPCODE(CMSG_CALENDAR_COMPLAIN,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarComplain            );
    CLIENTOPCODE(CMSG_CALENDAR_GET_NUM_PENDING,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarGetNumPending       );
    CLIENTOPCODE(CMSG_CALENDAR_CONTEXT_EVENT_SIGNUP,   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                        );

    /***********************************************************/
    /******************** CHARACTER OPCODES ********************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_MOVE_CHARACTER_CHEAT,  STATUS_NEVER,  PROCESS_INPLACE, &WorldSession::HandleNULL                 );
    CLIENTOPCODE(CMSG_CHAR_CREATE,           STATUS_AUTHED, PROCESS_THREADUNSAFE, &WorldSession::HandleCharCreateOpcode);
    CLIENTOPCODE(CMSG_CHAR_ENUM,             STATUS_AUTHED, PROCESS_THREADUNSAFE, &WorldSession::HandleCharEnumOpcode  );
    CLIENTOPCODE(CMSG_CHAR_DELETE,           STATUS_AUTHED, PROCESS_THREADUNSAFE, &WorldSession::HandleCharDeleteOpcode);
    CLIENTOPCODE(CMSG_CHARACTER_POINT_CHEAT, STATUS_NEVER,  PROCESS_INPLACE,      &WorldSession::HandleNULL            );
    CLIENTOPCODE(CMSG_CHAR_RENAME,           STATUS_AUTHED, PROCESS_THREADUNSAFE, &WorldSession::HandleCharRenameOpcode);
    CLIENTOPCODE(CMSG_CHAR_CUSTOMIZE,        STATUS_AUTHED, PROCESS_THREADUNSAFE, &WorldSession::HandleCharCustomize   );
    CLIENTOPCODE(CMSG_CHAR_FACTION_CHANGE,   STATUS_AUTHED, PROCESS_THREADUNSAFE, &WorldSession::HandleCharFactionOrRaceChange);
    CLIENTOPCODE(CMSG_CHAR_RACE_CHANGE,      STATUS_AUTHED, PROCESS_THREADUNSAFE, &WorldSession::HandleCharFactionOrRaceChange);

    // Character World Login / Logout
    CLIENTOPCODE(CMSG_PLAYER_LOGIN,          STATUS_AUTHED, PROCESS_THREADUNSAFE, &WorldSession::HandlePlayerLoginOpcode);
    CLIENTOPCODE(CMSG_PLAYER_LOGOUT,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePlayerLogoutOpcode);
    CLIENTOPCODE(CMSG_LOGOUT_REQUEST,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLogoutRequestOpcode);
    CLIENTOPCODE(CMSG_LOGOUT_CANCEL,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLogoutCancelOpcode );

    /***********************************************************/
    /********************** CHAT OPCODES ***********************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_CHAT_IGNORED,    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChatIgnoredOpcode        );
    CLIENTOPCODE(CMSG_GM_VISION,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                     );
    CLIENTOPCODE(CMSG_CHAT_FILTERED,   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                     );
    CLIENTOPCODE(CMSG_GM_WHISPER,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                     );
    CLIENTOPCODE(CMSG_FORCE_SAY_CHEAT, STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                     );

    // Chat Message
    CLIENTOPCODE(CMSG_MESSAGECHAT_SAY,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    CLIENTOPCODE(CMSG_MESSAGECHAT_YELL,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    CLIENTOPCODE(CMSG_MESSAGECHAT_CHANNEL,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    CLIENTOPCODE(CMSG_MESSAGECHAT_WHISPER,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);    
    CLIENTOPCODE(CMSG_MESSAGECHAT_GUILD,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    CLIENTOPCODE(CMSG_MESSAGECHAT_OFFICER,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    CLIENTOPCODE(CMSG_MESSAGECHAT_AFK,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    CLIENTOPCODE(CMSG_MESSAGECHAT_DND,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    CLIENTOPCODE(CMSG_MESSAGECHAT_EMOTE,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    CLIENTOPCODE(CMSG_MESSAGECHAT_PARTY,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    CLIENTOPCODE(CMSG_MESSAGECHAT_PARTY_LEADER,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    CLIENTOPCODE(CMSG_MESSAGECHAT_RAID,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    CLIENTOPCODE(CMSG_MESSAGECHAT_RAID_LEADER,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    CLIENTOPCODE(CMSG_MESSAGECHAT_BATTLEGROUND,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);    
    CLIENTOPCODE(CMSG_MESSAGECHAT_BATTLEGROUND_LEADER, STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);
    CLIENTOPCODE(CMSG_MESSAGECHAT_RAID_WARNING,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode);

    // Channel
    CLIENTOPCODE(CMSG_JOIN_CHANNEL,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleJoinChannel       );
    CLIENTOPCODE(CMSG_LEAVE_CHANNEL,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLeaveChannel      );
    CLIENTOPCODE(CMSG_CHANNEL_LIST,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelList       );
    CLIENTOPCODE(CMSG_CHANNEL_PASSWORD,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelPassword   );
    CLIENTOPCODE(CMSG_CHANNEL_SET_OWNER,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelSetOwner   );
    CLIENTOPCODE(CMSG_CHANNEL_OWNER,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelOwner      );
    CLIENTOPCODE(CMSG_CHANNEL_MODERATOR,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelModerator  );
    CLIENTOPCODE(CMSG_CHANNEL_UNMODERATOR,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelUnmoderator);
    CLIENTOPCODE(CMSG_CHANNEL_MUTE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelMute       );
    CLIENTOPCODE(CMSG_CHANNEL_UNMUTE,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelUnmute     );
    CLIENTOPCODE(CMSG_CHANNEL_INVITE,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelInvite     );
    CLIENTOPCODE(CMSG_CHANNEL_KICK,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelKick       );
    CLIENTOPCODE(CMSG_CHANNEL_UNBAN,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelUnban      );
    CLIENTOPCODE(CMSG_CHANNEL_ANNOUNCEMENTS,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelAnnouncements);
    CLIENTOPCODE(CMSG_CHANNEL_MODERATE,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL              );
    CLIENTOPCODE(CMSG_CHANNEL_SILENCE_VOICE,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL              );
    CLIENTOPCODE(CMSG_CHANNEL_SILENCE_ALL,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL              );
    CLIENTOPCODE(CMSG_CHANNEL_UNSILENCE_VOICE,         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL              );
    CLIENTOPCODE(CMSG_CHANNEL_UNSILENCE_ALL,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL              );
    CLIENTOPCODE(CMSG_CHANNEL_DISPLAY_LIST,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelDisplayListQuery);
    CLIENTOPCODE(CMSG_GET_CHANNEL_MEMBER_COUNT,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGetChannelMemberCount);
    CLIENTOPCODE(CMSG_SET_CHANNEL_WATCH,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetChannelWatch    );
    CLIENTOPCODE(CMSG_CLEAR_CHANNEL_WATCH,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL               );
    CLIENTOPCODE(CMSG_DECLINE_CHANNEL_INVITE,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelDeclineInvite);

    // Char Server Message
    CLIENTOPCODE(CMSG_SERVER_BROADCAST,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL               );
    CLIENTOPCODE(CMSG_SERVER_INFO_QUERY,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL               );

    /***********************************************************/
    /********************* COMBAT OPCODES **********************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_ENABLE_DAMAGE_LOG,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL               );

    /***********************************************************/
    /********************** DUEL OPCODES ***********************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_DUEL_ACCEPTED,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDuelAcceptedOpcode  );
    CLIENTOPCODE(CMSG_DUEL_CANCELLED,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDuelCancelledOpcode );

    /***********************************************************/
    /******************** FACTION OPCODES **********************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_SET_FACTION_ATWAR,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetFactionAtWar      );
    CLIENTOPCODE(CMSG_SET_FACTION_CHEAT,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetFactionCheat      );
    CLIENTOPCODE(CMSG_SET_ACTION_BUTTON,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetActionButtonOpcode);
    CLIENTOPCODE(CMSG_RESET_FACTION_CHEAT,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                 );
    CLIENTOPCODE(CMSG_SET_FACTION_INACTIVE,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetFactionInactiveOpcode);
    CLIENTOPCODE(CMSG_SET_WATCHED_FACTION,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetWatchedFactionOpcode);

    /***********************************************************/
    /******************* GAMEMASTER OPCODES ********************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_GM_INVIS,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_SET_SECURITY_GROUP,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_NUKE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_TEACH,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_CREATE_ITEM_TARGET,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_SILENCE,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_REVEALTO,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_RESURRECT,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_SUMMONMOB,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_MOVECORPSE,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_FREEZE,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_UBERINVIS,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_REQUEST_PLAYER_INFO,          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_UNTEACH,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_NUKE_ACCOUNT,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_DESTROY_ONLINE_CORPSE,        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_MAELSTROM_GM_SENT_MAIL,          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_SHOW_COMPLAINTS,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_UNSQUELCH,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_CHARACTER_RESTORE,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_CHARACTER_SAVE,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GMRESPONSE_RESOLVE,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMResponseResolve      );
    CLIENTOPCODE(CMSG_GM_REPORT_LAG,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleReportLag              );

    // Gamemaster Ticket
    CLIENTOPCODE(CMSG_GMTICKET_CREATE,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketCreateOpcode   );
    CLIENTOPCODE(CMSG_GMTICKET_UPDATETEXT,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketUpdateOpcode   );
    CLIENTOPCODE(CMSG_GMTICKET_GETTICKET,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketGetTicketOpcode);
    CLIENTOPCODE(CMSG_GMTICKET_DELETETICKET,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketDeleteOpcode   );
    CLIENTOPCODE(CMSG_GMTICKET_SYSTEMSTATUS,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketSystemStatusOpcode);
    CLIENTOPCODE(CMSG_GMTICKETSYSTEM_TOGGLE,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GM_UPDATE_TICKET_STATUS,         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GMSURVEY_SUBMIT,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMSurveySubmit         );

    /***********************************************************/
    /****************** (GAME)OBJECT OPCODES *******************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_QUERY_OBJECT_POSITION,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_QUERY_OBJECT_ROTATION,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_CREATEGAMEOBJECT,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );
    CLIENTOPCODE(CMSG_GAMEOBJ_USE,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGameObjectUseOpcode    );
    CLIENTOPCODE(CMSG_GAMEOBJ_REPORT_USE,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGameobjectReportUse    );
    CLIENTOPCODE(CMSG_DUMP_OBJECTS,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                   );

    /***********************************************************/
    /********************** GOSSIP OPCODES *********************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_GOSSIP_HELLO,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGossipHelloOpcode       );
    CLIENTOPCODE(CMSG_GOSSIP_SELECT_OPTION,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGossipSelectOptionOpcode);
    CLIENTOPCODE(CMSG_NPC_TEXT_QUERY,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleNpcTextQueryOpcode      );
    CLIENTOPCODE(CMSG_BATTLEMASTER_JOIN,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlemasterJoinOpcode  );

    // Gossip Questgiver
    CLIENTOPCODE(CMSG_QUESTGIVER_STATUS_QUERY,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverStatusQueryOpcode);
    CLIENTOPCODE(CMSG_QUESTGIVER_HELLO,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverHelloOpcode      );
    CLIENTOPCODE(CMSG_QUESTGIVER_QUERY_QUEST,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverQueryQuestOpcode );
    CLIENTOPCODE(CMSG_QUESTGIVER_QUEST_AUTOLAUNCH,     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverQuestAutoLaunch  );
    CLIENTOPCODE(CMSG_QUESTGIVER_ACCEPT_QUEST,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverAcceptQuestOpcode);
    CLIENTOPCODE(CMSG_QUESTGIVER_COMPLETE_QUEST,       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverCompleteQuest    );
    CLIENTOPCODE(CMSG_QUESTGIVER_REQUEST_REWARD,       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverRequestRewardOpcode);
    CLIENTOPCODE(CMSG_QUESTGIVER_CHOOSE_REWARD,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverChooseRewardOpcode);
    CLIENTOPCODE(CMSG_QUESTGIVER_CANCEL,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverCancel            );

    // Gossip Trainer
    CLIENTOPCODE(CMSG_TRAINER_LIST,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTrainerListOpcode           );
    CLIENTOPCODE(CMSG_TRAINER_BUY_SPELL,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTrainerBuySpellOpcode       );

    /***********************************************************/
    /********************** GROUP OPCODES **********************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_GROUP_INVITE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupInviteOpcode         );
    CLIENTOPCODE(CMSG_GROUP_CANCEL,                    STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleNULL                      );
    CLIENTOPCODE(CMSG_GROUP_ACCEPT,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupAcceptOpcode         );
    CLIENTOPCODE(CMSG_GROUP_DECLINE,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupDeclineOpcode        );
    CLIENTOPCODE(CMSG_GROUP_UNINVITE,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupUninviteOpcode       );
    CLIENTOPCODE(CMSG_GROUP_UNINVITE_GUID,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupUninviteGuidOpcode   );
    CLIENTOPCODE(CMSG_GROUP_SET_LEADER,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupSetLeaderOpcode      );
    CLIENTOPCODE(CMSG_GROUP_DISBAND,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupDisbandOpcode        );
    CLIENTOPCODE(CMSG_GROUP_CHANGE_SUB_GROUP,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupChangeSubGroupOpcode );
    CLIENTOPCODE(CMSG_GROUP_SWAP_SUB_GROUP,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                      );
    CLIENTOPCODE(CMSG_GROUP_RAID_CONVERT,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupRaidConvertOpcode    );
    CLIENTOPCODE(CMSG_GROUP_ASSISTANT_LEADER,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupAssistantLeaderOpcode);
    
    /***********************************************************/
    /********************** GUILD OPCODES **********************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_GUILD_CREATE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildCreateOpcode );
    CLIENTOPCODE(CMSG_GUILD_INVITE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildInviteOpcode );
    CLIENTOPCODE(CMSG_GUILD_ACCEPT,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildAcceptOpcode );
    CLIENTOPCODE(CMSG_GUILD_DECLINE,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildDeclineOpcode );
    CLIENTOPCODE(CMSG_GUILD_INFO,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildInfoOpcode );
    CLIENTOPCODE(CMSG_GUILD_ROSTER,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildRosterOpcode );
    CLIENTOPCODE(CMSG_GUILD_PROMOTE,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildPromoteOpcode );
    CLIENTOPCODE(CMSG_GUILD_DEMOTE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildDemoteOpcode );
    CLIENTOPCODE(CMSG_GUILD_LEAVE,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildLeaveOpcode );
    CLIENTOPCODE(CMSG_GUILD_REMOVE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildRemoveOpcode );
    CLIENTOPCODE(CMSG_GUILD_DISBAND,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildDisbandOpcode );
    CLIENTOPCODE(CMSG_GUILD_LEADER,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildLeaderOpcode );
    CLIENTOPCODE(CMSG_GUILD_MOTD,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildMOTDOpcode );
    CLIENTOPCODE(CMSG_GUILD_RANK,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildRankOpcode );
    CLIENTOPCODE(CMSG_GUILD_ADD_RANK,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildAddRankOpcode );
    CLIENTOPCODE(CMSG_GUILD_DEL_RANK,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildDelRankOpcode );
    CLIENTOPCODE(CMSG_GUILD_SET_PUBLIC_NOTE,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildSetPublicNoteOpcode );
    CLIENTOPCODE(CMSG_GUILD_SET_OFFICER_NOTE,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildSetOfficerNoteOpcode );
    CLIENTOPCODE(CMSG_GUILD_INFO_TEXT,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildChangeInfoTextOpcode );
    CLIENTOPCODE(CMSG_MAELSTROM_RENAME_GUILD,          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
     
    // Guild Bank
    CLIENTOPCODE(CMSG_GUILD_BANKER_ACTIVATE,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankerActivate );
    CLIENTOPCODE(CMSG_GUILD_BANK_QUERY_TAB,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankQueryTab );
    CLIENTOPCODE(CMSG_GUILD_BANK_SWAP_ITEMS,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankSwapItems );
    CLIENTOPCODE(CMSG_GUILD_BANK_BUY_TAB,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankBuyTab );
    CLIENTOPCODE(CMSG_GUILD_BANK_UPDATE_TAB,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankUpdateTab );
    CLIENTOPCODE(CMSG_GUILD_BANK_DEPOSIT_MONEY,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankDepositMoney );
    CLIENTOPCODE(CMSG_GUILD_BANK_WITHDRAW_MONEY,       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankWithdrawMoney );
    CLIENTOPCODE(CMSG_SET_GUILD_BANK_TEXT,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetGuildBankTabText );
    
    // Guild Petition
    CLIENTOPCODE(CMSG_PETITION_SHOWLIST,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionShowListOpcode );
    CLIENTOPCODE(CMSG_PETITION_BUY,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionBuyOpcode );
    CLIENTOPCODE(CMSG_PETITION_SHOW_SIGNATURES,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionShowSignOpcode );
    CLIENTOPCODE(CMSG_PETITION_SIGN,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionSignOpcode );
    CLIENTOPCODE(CMSG_TURN_IN_PETITION,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTurnInPetitionOpcode );
    CLIENTOPCODE(CMSG_OFFER_PETITION,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleOfferPetitionOpcode );
    CLIENTOPCODE(CMSG_PETITION_QUERY,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionQueryOpcode );
    
    // Guild Party
    CLIENTOPCODE(CMSG_REQUEST_PARTY_MEMBER_STATS,      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRequestPartyMemberStatsOpcode);
    CLIENTOPCODE(CMSG_PARTY_SILENCE,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_PARTY_UNSILENCE,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    
    /***********************************************************/
    /******************** INSTANCE OPCODES *********************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_INSTANCE_LOCK_WARNING_RESPONSE,  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInstanceLockResponse );
    CLIENTOPCODE(CMSG_REQUEST_RAID_INFO,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRequestRaidInfoOpcode );
    CLIENTOPCODE(CMSG_EXPIRE_RAID_INSTANCE,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SET_ALLOW_LOW_LEVEL_RAID1,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SET_ALLOW_LOW_LEVEL_RAID2,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    
    // LFG
    CLIENTOPCODE(CMSG_LFG_JOIN,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgJoinOpcode );
    CLIENTOPCODE(CMSG_LFG_LEAVE,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgLeaveOpcode );
    CLIENTOPCODE(CMSG_SEARCH_LFG_JOIN,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfrSearchOpcode );
    CLIENTOPCODE(CMSG_SEARCH_LFG_LEAVE,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfrLeaveOpcode );
    CLIENTOPCODE(CMSG_LFG_PROPOSAL_RESULT,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgProposalResultOpcode );
    CLIENTOPCODE(CMSG_SET_LFG_COMMENT,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgSetCommentOpcode );
    CLIENTOPCODE(CMSG_LFG_SET_ROLES,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgSetRolesOpcode );
    CLIENTOPCODE(CMSG_LFG_SET_NEEDS,                   STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_LFG_SET_BOOT_VOTE,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgSetBootVoteOpcode );
    CLIENTOPCODE(CMSG_LFD_PLAYER_LOCK_INFO_REQUEST,    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgPlayerLockInfoRequestOpcode);
    CLIENTOPCODE(CMSG_LFG_TELEPORT,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgTeleportOpcode );
    CLIENTOPCODE(CMSG_LFD_PARTY_LOCK_INFO_REQUEST,     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgPartyLockInfoRequestOpcode);
    
    // Meetingstone
    CLIENTOPCODE(CMSG_MEETINGSTONE_INFO,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMeetingStoneInfo );
    CLIENTOPCODE(CMSG_MEETINGSTONE_CHEAT,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    
    /***********************************************************/
    /********************** ITEM OPCODES ***********************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_CREATEITEM,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_USE_ITEM,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleUseItemOpcode );
    CLIENTOPCODE(CMSG_OPEN_ITEM,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleOpenItemOpcode );
    CLIENTOPCODE(CMSG_READ_ITEM,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleReadItem );
    CLIENTOPCODE(CMSG_DESTROY_ITEMS,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SWAP_ITEM,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSwapItem );
    CLIENTOPCODE(CMSG_SWAP_INV_ITEM,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSwapInvItemOpcode );
    CLIENTOPCODE(CMSG_SPLIT_ITEM,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSplitItemOpcode );
    CLIENTOPCODE(OBSOLETE_DROP_ITEM,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_DESTROYITEM,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDestroyItemOpcode );
    CLIENTOPCODE(CMSG_SELL_ITEM,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSellItemOpcode );
    CLIENTOPCODE(CMSG_BUY_ITEM,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuyItemOpcode );
    CLIENTOPCODE(CMSG_BUY_ITEM_IN_SLOT,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuyItemInSlotOpcode );
    CLIENTOPCODE(CMSG_WRAP_ITEM,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWrapItemOpcode );
    CLIENTOPCODE(CMSG_SET_DURABILITY_CHEAT,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_BUYBACK_ITEM,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuybackItem );
    CLIENTOPCODE(CMSG_REPAIR_ITEM,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRepairItemOpcode );
    CLIENTOPCODE(CMSG_SHOWING_HELM,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleShowingHelmOpcode );
    CLIENTOPCODE(CMSG_SHOWING_CLOAK,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleShowingCloakOpcode );
    CLIENTOPCODE(CMSG_SOCKET_GEMS,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSocketOpcode );
    CLIENTOPCODE(CMSG_CANCEL_TEMP_ENCHANTMENT,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelTempEnchantmentOpcode);
    CLIENTOPCODE(CMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_UPDATE_MISSILE_TRAJECTORY,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_ITEM_REFUND_INFO,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleItemRefundInfoRequest );
    CLIENTOPCODE(CMSG_ITEM_REFUND,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleItemRefund );
    CLIENTOPCODE(CMSG_UPDATE_PROJECTILE_POSITION,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    
    // Item Equipment
    CLIENTOPCODE(CMSG_AUTOEQUIP_GROUND_ITEM,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_AUTOSTORE_GROUND_ITEM,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_AUTOSTORE_LOOT_ITEM,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutostoreLootItemOpcode );
    CLIENTOPCODE(CMSG_AUTOEQUIP_ITEM,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoEquipItemOpcode );
    CLIENTOPCODE(CMSG_AUTOSTORE_BAG_ITEM,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoStoreBagItemOpcode );
    CLIENTOPCODE(CMSG_AUTOEQUIP_ITEM_SLOT,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoEquipItemSlotOpcode );
    CLIENTOPCODE(CMSG_EQUIPMENT_SET_DELETE,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEquipmentSetDelete );
    CLIENTOPCODE(CMSG_AUTOSTORE_BANK_ITEM,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoStoreBankItemOpcode );
    CLIENTOPCODE(CMSG_AUTOBANK_ITEM,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoBankItemOpcode );
    CLIENTOPCODE(CMSG_EQUIPMENT_SET_SAVE,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEquipmentSetSave );
    CLIENTOPCODE(CMSG_EQUIPMENT_SET_USE,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEquipmentSetUse );
    
    // Inventory / Trade
    CLIENTOPCODE(CMSG_INSPECT,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInspectOpcode );
    CLIENTOPCODE(CMSG_INITIATE_TRADE,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInitiateTradeOpcode );
    CLIENTOPCODE(CMSG_BEGIN_TRADE,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBeginTradeOpcode );
    CLIENTOPCODE(CMSG_BUSY_TRADE,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBusyTradeOpcode );
    CLIENTOPCODE(CMSG_IGNORE_TRADE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleIgnoreTradeOpcode );
    CLIENTOPCODE(CMSG_ACCEPT_TRADE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAcceptTradeOpcode );
    CLIENTOPCODE(CMSG_UNACCEPT_TRADE,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleUnacceptTradeOpcode );
    CLIENTOPCODE(CMSG_CANCEL_TRADE,                    STATUS_LOGGEDIN_OR_RECENTLY_LOGGOUT, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelTradeOpcode);
    CLIENTOPCODE(CMSG_SET_TRADE_ITEM,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetTradeItemOpcode );
    CLIENTOPCODE(CMSG_CLEAR_TRADE_ITEM,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleClearTradeItemOpcode );
    CLIENTOPCODE(CMSG_SET_TRADE_GOLD,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetTradeGoldOpcode );
    CLIENTOPCODE(CMSG_LIST_INVENTORY,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleListInventoryOpcode );
    
    /***********************************************************/
    /********************** LOOT OPCODES ***********************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_LOOT_METHOD,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootMethodOpcode );
    CLIENTOPCODE(CMSG_STORE_LOOT_IN_SLOT,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_LOOT,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootOpcode );
    CLIENTOPCODE(CMSG_LOOT_MONEY,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootMoneyOpcode );
    CLIENTOPCODE(CMSG_LOOT_RELEASE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootReleaseOpcode );
    CLIENTOPCODE(CMSG_OPT_OUT_OF_LOOT,                 STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleOptOutOfLootOpcode );
    
    // Loot Group
    CLIENTOPCODE(CMSG_LOOT_ROLL,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootRoll );
    CLIENTOPCODE(CMSG_LOOT_MASTER_GIVE,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootMasterGiveOpcode );
    
    /***********************************************************/
    /******************** MOVEMENT OPCODES *********************/
    /***********************************************************/
    CLIENTOPCODE(CMSG_MOVE_SET_RAW_POSITION,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_MOVE_KNOCK_BACK_ACK,             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveKnockBackAck );
    CLIENTOPCODE(CMSG_MOVE_HOVER_ACK,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMoveHoverAck );
    CLIENTOPCODE(CMSG_MOVE_TIME_SKIPPED,               STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleMoveTimeSkippedOpcode );
    CLIENTOPCODE(CMSG_MOVE_NOT_ACTIVE_MOVER,           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveNotActiveMover );
    CLIENTOPCODE(CMSG_MINIGAME_MOVE,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_MOVE_CHNG_TRANSPORT,             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes );
    CLIENTOPCODE(CMSG_UNKNOWN_1303,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
     
    // Movement Start / Stop
    CLIENTOPCODE(CMSG_MOVE_START_SWIM_CHEAT,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_MOVE_STOP_SWIM_CHEAT,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );

    // Movement Force
    CLIENTOPCODE(CMSG_FORCE_RUN_SPEED_CHANGE_ACK,      STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAck );
    CLIENTOPCODE(CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK, STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAck );
    CLIENTOPCODE(CMSG_FORCE_SWIM_SPEED_CHANGE_ACK,     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAck );
    CLIENTOPCODE(CMSG_FORCE_MOVE_ROOT_ACK,             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveRootAck );
    CLIENTOPCODE(CMSG_FORCE_MOVE_UNROOT_ACK,           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveUnRootAck );
    CLIENTOPCODE(CMSG_FORCE_WALK_SPEED_CHANGE_ACK,     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAck );
    CLIENTOPCODE(CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK, STATUS_LOGGEDIN, PROCESS_THREADSAFE,  &WorldSession::HandleForceSpeedChangeAck );
    CLIENTOPCODE(CMSG_FORCE_TURN_RATE_CHANGE_ACK,      STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAck );
    CLIENTOPCODE(CMSG_FORCE_FLIGHT_SPEED_CHANGE_ACK,   STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAck );
    CLIENTOPCODE(CMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK, STATUS_LOGGEDIN, PROCESS_THREADSAFE, &WorldSession::HandleForceSpeedChangeAck );
    CLIENTOPCODE(CMSG_FORCE_PITCH_RATE_CHANGE_ACK,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_FORCE_UNK1_SPEED_CHANGE_ACK,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_FORCE_UNK2_SPEED_CHANGE_ACK,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );

    // Movement Teleport / Fall / Fly / Water
    CLIENTOPCODE(CMSG_MOVE_FALL_RESET,                 STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes );
    CLIENTOPCODE(CMSG_MOVE_FEATHER_FALL_ACK,           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleFeatherFallAck );
    CLIENTOPCODE(CMSG_MOVE_WATER_WALK_ACK,             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveWaterWalkAck );
    CLIENTOPCODE(CMSG_MOVE_FLIGHT_ACK,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );

    // Movement Set / Unset
    CLIENTOPCODE(CMSG_MOVE_SET_CAN_FLY_ACK,            STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveSetCanFlyAckOpcode );
    CLIENTOPCODE(CMSG_MOVE_SET_FLY,                    STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes );
    CLIENTOPCODE(CMSG_MOVE_SET_RUN_SPEED,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );

    // Spline
    CLIENTOPCODE(CMSG_MOVE_SPLINE_DONE,                STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveSplineDoneOpcode );

    // Spline Set / Unset

    /***********************************************************/
    /********************* MOVIE OPCODES ***********************/
    /***********************************************************/

    // Cinematic 
    CLIENTOPCODE(CMSG_TRIGGER_CINEMATIC_CHEAT,         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_OPENING_CINEMATIC,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_NEXT_CINEMATIC_CAMERA,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleNextCinematicCamera );
    CLIENTOPCODE(CMSG_COMPLETE_CINEMATIC,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCompleteCinematic );

    // Movie
    CLIENTOPCODE(CMSG_COMPLETE_MOVIE,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );

    /***********************************************************/ 
    /****************** MOUNT / PET OPCODES ********************/
    /***********************************************************/

    CLIENTOPCODE(CMSG_MOUNTSPECIAL_ANIM,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMountSpecialAnimOpcode );
    CLIENTOPCODE(CMSG_CANCEL_MOUNT_AURA,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelMountAuraOpcode );

    // Pet
    CLIENTOPCODE(CMSG_PET_SET_ACTION,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetSetAction );
    CLIENTOPCODE(CMSG_PET_ACTION,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetAction );
    CLIENTOPCODE(CMSG_PET_ABANDON,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetAbandon );
    CLIENTOPCODE(CMSG_PET_RENAME,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetRename );
    CLIENTOPCODE(CMSG_PET_STOP_ATTACK,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetStopAttack );
    CLIENTOPCODE(CMSG_PET_UNLEARN,                     STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_PET_LEARN_TALENT,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetLearnTalent );
    CLIENTOPCODE(CMSG_PET_UNLEARN_TALENTS,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );

    /***********************************************************/
    /********************* PLAYER OPCODES **********************/
    /***********************************************************/

    CLIENTOPCODE(CMSG_UNDRESSPLAYER,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_GODMODE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_PLAYER_DIFFICULTY_CHANGE,        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_PLAYER_AI_CHEAT,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SET_ACTIONBAR_TOGGLES,           STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleSetActionBarToggles );
    CLIENTOPCODE(CMSG_IGNORE_REQUIREMENTS_CHEAT,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SET_PLAYER_DECLINED_NAMES,       STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleSetPlayerDeclinedNames );

    // Player Achievement
    CLIENTOPCODE(CMSG_QUERY_INSPECT_ACHIEVEMENTS,      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryInspectAchievements );
    CLIENTOPCODE(CMSG_COMPLETE_ACHIEVEMENT_CHEAT,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SET_CRITERIA_CHEAT,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_CHECK_LOGIN_CRITERIA,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );

    // Player Exploration
    CLIENTOPCODE(CMSG_SET_EXPLORATION,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SET_EXPLORATION_ALL,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );

    // Friends / Contacts / ...
    CLIENTOPCODE(CMSG_WHO,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWhoOpcode );
    CLIENTOPCODE(CMSG_WHOIS,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWhoisOpcode );
    CLIENTOPCODE(CMSG_CONTACT_LIST,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleContactListOpcode );
    CLIENTOPCODE(CMSG_ADD_FRIEND,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAddFriendOpcode );
    CLIENTOPCODE(CMSG_DEL_FRIEND,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDelFriendOpcode );
    CLIENTOPCODE(CMSG_SET_CONTACT_NOTES,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetContactNotesOpcode );
    CLIENTOPCODE(CMSG_SAVE_PLAYER,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_REFER_A_FRIEND,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );

    // Player Dance
    CLIENTOPCODE(CMSG_SAVE_DANCE,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_PLAY_DANCE,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_LOAD_DANCES,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_STOP_DANCE,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SYNC_DANCE,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_DANCE_QUERY,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_DELETE_DANCE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_LEARN_DANCE_MOVE,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_UNLEARN_DANCE_MOVE,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );

    // Player Level
    CLIENTOPCODE(CMSG_LEVEL_CHEAT,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SET_GRANTABLE_LEVELS,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_GRANT_LEVEL,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_ACCEPT_LEVEL_GRANT,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );

    // Player Pet
    CLIENTOPCODE(CMSG_PET_LEVEL_CHEAT,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_STABLE_PET,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleStablePet );
    CLIENTOPCODE(CMSG_UNSTABLE_PET,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleUnstablePet );
    CLIENTOPCODE(CMSG_BUY_STABLE_SLOT,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuyStableSlot );
    CLIENTOPCODE(CMSG_STABLE_REVIVE_PET,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleStableRevivePet );
    CLIENTOPCODE(CMSG_STABLE_SWAP_PET,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleStableSwapPet );
    CLIENTOPCODE(CMSG_REQUEST_PET_INFO,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRequestPetInfoOpcode );

    // Player PVP / Honor / ...
    CLIENTOPCODE(CMSG_DISABLE_PVP_CHEAT,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_TOGGLE_PVP,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTogglePvP );
    CLIENTOPCODE(CMSG_SET_PVP_RANK_CHEAT,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_ADD_PVP_MEDAL_CHEAT,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_DEL_PVP_MEDAL_CHEAT,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SET_PVP_TITLE,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SET_TITLE,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetTitleOpcode );
    CLIENTOPCODE(CMSG_CHEAT_SET_HONOR_CURRENCY,        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_ACTIVE_PVP_CHEAT,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_REPORT_PVP_AFK,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleReportPvPAFK );
    CLIENTOPCODE(CMSG_SET_TITLE_SUFFIX,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );

    // Player Arena
    CLIENTOPCODE(CMSG_ARENA_TEAM_CREATE,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_ARENA_TEAM_QUERY,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamQueryOpcode );
    CLIENTOPCODE(CMSG_ARENA_TEAM_ROSTER,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamRosterOpcode );
    CLIENTOPCODE(CMSG_ARENA_TEAM_INVITE,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamInviteOpcode );
    CLIENTOPCODE(CMSG_ARENA_TEAM_ACCEPT,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamAcceptOpcode );
    CLIENTOPCODE(CMSG_ARENA_TEAM_DECLINE,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamDeclineOpcode );
    CLIENTOPCODE(CMSG_ARENA_TEAM_LEAVE,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamLeaveOpcode );
    CLIENTOPCODE(CMSG_ARENA_TEAM_REMOVE,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamRemoveOpcode );
    CLIENTOPCODE(CMSG_ARENA_TEAM_DISBAND,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamDisbandOpcode );
    CLIENTOPCODE(CMSG_ARENA_TEAM_LEADER,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamLeaderOpcode );
    CLIENTOPCODE(CMSG_CHEAT_SET_ARENA_CURRENCY,        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_CHANGE_PERSONAL_ARENA_RATING,    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );

    // Player Tutorial
    CLIENTOPCODE(CMSG_TUTORIAL_FLAG,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTutorialFlag );
    CLIENTOPCODE(CMSG_TUTORIAL_CLEAR,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTutorialClear );
    CLIENTOPCODE(CMSG_TUTORIAL_RESET,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTutorialReset );

    // Player Emote
    CLIENTOPCODE(CMSG_EMOTE,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEmoteOpcode );
    CLIENTOPCODE(CMSG_TEXT_EMOTE,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTextEmoteOpcode );

    // Player Corpse / Resurrect / Death
    CLIENTOPCODE(CMSG_SETDEATHBINDPOINT,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_GETDEATHBINDZONE,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_REPOP_REQUEST,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRepopRequestOpcode );
    CLIENTOPCODE(CMSG_RESURRECT_RESPONSE,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleResurrectResponseOpcode );
    CLIENTOPCODE(CMSG_RECLAIM_CORPSE,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleReclaimCorpseOpcode );
    CLIENTOPCODE(CMSG_GHOST,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_HEARTH_AND_RESURRECT,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleHearthAndResurrect );

    // Player Health / Power / Mana / ...
    CLIENTOPCODE(CMSG_SET_RUNE_COUNT,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SET_RUNE_COOLDOWN,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );

    // Player Glyph
    CLIENTOPCODE(CMSG_SET_GLYPH_SLOT,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SET_GLYPH,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_REMOVE_GLYPH,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRemoveGlyph );

    // Player Talent / Skill
    CLIENTOPCODE(CMSG_UNLEARN_TALENTS,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_USE_SKILL_CHEAT,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SKILL_BUY_STEP,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SKILL_BUY_RANK,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_LEARN_TALENT,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLearnTalentOpcode );
    CLIENTOPCODE(CMSG_LEARN_PREVIEW_TALENTS,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLearnPreviewTalents );
    CLIENTOPCODE(CMSG_LEARN_PREVIEW_TALENTS_PET,       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLearnPreviewTalentsPet );

    // Player Mail
    CLIENTOPCODE(CMSG_SEND_MAIL,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSendMail );
    CLIENTOPCODE(CMSG_GET_MAIL_LIST,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGetMailList );
    CLIENTOPCODE(CMSG_MAIL_TAKE_MONEY,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailTakeMoney );
    CLIENTOPCODE(CMSG_MAIL_TAKE_ITEM,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailTakeItem );
    CLIENTOPCODE(CMSG_MAIL_MARK_AS_READ,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailMarkAsRead );
    CLIENTOPCODE(CMSG_MAIL_RETURN_TO_SENDER,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailReturnToSender );
    CLIENTOPCODE(CMSG_MAIL_DELETE,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailDelete );
    CLIENTOPCODE(CMSG_MAIL_CREATE_TEXT_ITEM,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailCreateTextItem );

    // Player Voice
    CLIENTOPCODE(CMSG_VOICE_SET_TALKER_MUTED_REQUEST,  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_VOICE_SESSION_ENABLE,            STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleVoiceSessionEnableOpcode );
    CLIENTOPCODE(CMSG_SET_ACTIVE_VOICE_CHANNEL,        STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleSetActiveVoiceChannel );
    CLIENTOPCODE(CMSG_CHANNEL_VOICE_ON,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelVoiceOnOpcode );
    CLIENTOPCODE(CMSG_CHANNEL_VOICE_OFF,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(SMSG_DEBUG_LIST_TARGETS,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleServerSide );
    CLIENTOPCODE( CMSG_ADD_VOICE_IGNORE,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_DEL_VOICE_IGNORE,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );

    // Player Totem
    CLIENTOPCODE(CMSG_TOTEM_DESTROYED,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTotemDestroyed );


    /***********************************************************/
    /********************* QUERY OPCODES ***********************/
    /***********************************************************/

    CLIENTOPCODE(CMSG_NAME_QUERY,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleNameQueryOpcode );
    CLIENTOPCODE(CMSG_PET_NAME_QUERY,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetNameQuery );
    CLIENTOPCODE(CMSG_GUILD_QUERY,                     STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleGuildQueryOpcode );
    CLIENTOPCODE(CMSG_ITEM_QUERY_SINGLE,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleItemQuerySingleOpcode );
    CLIENTOPCODE(CMSG_ITEM_QUERY_MULTIPLE,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_PAGE_TEXT_QUERY,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePageTextQueryOpcode );
    CLIENTOPCODE(CMSG_QUEST_QUERY,                     STATUS_LOGGEDIN_OR_RECENTLY_LOGGOUT, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestQueryOpcode );
    CLIENTOPCODE(CMSG_GAMEOBJECT_QUERY,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGameObjectQueryOpcode );
    CLIENTOPCODE(CMSG_CREATURE_QUERY,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCreatureQueryOpcode );
    CLIENTOPCODE(CMSG_ITEM_TEXT_QUERY,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleItemTextQuery );
    CLIENTOPCODE(CMSG_ITEM_NAME_QUERY,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleItemNameQueryOpcode );
    CLIENTOPCODE(CMSG_CORPSE_MAP_POSITION_QUERY,       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCorpseMapPositionQuery );


    /***********************************************************/
    /********************* QUEST OPCODES ***********************/
    /***********************************************************/

    CLIENTOPCODE(CMSG_FLAG_QUEST,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_FLAG_QUEST_FINISH,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_CLEAR_QUEST,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_QUESTLOG_SWAP_QUEST,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestLogSwapQuest );
    CLIENTOPCODE(CMSG_QUESTLOG_REMOVE_QUEST,           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestLogRemoveQuest );
    CLIENTOPCODE(CMSG_QUEST_CONFIRM_ACCEPT,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestConfirmAccept );
    CLIENTOPCODE(CMSG_PUSHQUESTTOPARTY,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePushQuestToParty );
    CLIENTOPCODE(CMSG_QUEST_POI_QUERY,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestPOIQuery );
    CLIENTOPCODE(CMSG_START_QUEST,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_QUERY_QUESTS_COMPLETED,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryQuestsCompleted );

    // Questgiver
    CLIENTOPCODE(CMSG_QUESTGIVER_STATUS_MULTIPLE_QUERY, STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverStatusMultipleQuery);

    /***********************************************************/
    /********************* SPELL OPCODES ***********************/
    /***********************************************************/

    CLIENTOPCODE(CMSG_RECHARGE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL            );
    CLIENTOPCODE(CMSG_LEARN_SPELL,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL            );
    CLIENTOPCODE(CMSG_NEW_SPELL_SLOT,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL            );
    CLIENTOPCODE(CMSG_CAST_SPELL,                       STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleCastSpellOpcode );
    CLIENTOPCODE(CMSG_CANCEL_CAST,                      STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleCancelCastOpcode);
    CLIENTOPCODE(CMSG_CANCEL_CHANNELLING,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelChanneling);
    CLIENTOPCODE(CMSG_UNLEARN_SPELL,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL            );
    CLIENTOPCODE(CMSG_DECHARGE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL            );
    CLIENTOPCODE(CMSG_CANCEL_AUTO_REPEAT_SPELL,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelAutoRepeatSpellOpcode);
    CLIENTOPCODE(CMSG_SUMMON_RESPONSE,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSummonResponseOpcode       );
    CLIENTOPCODE(CMSG_SEND_GENERAL_TRIGGER,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                       );
    CLIENTOPCODE(CMSG_SEND_COMBAT_TRIGGER,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                       );
    CLIENTOPCODE(CMSG_TARGET_CAST,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                       );
    CLIENTOPCODE(CMSG_TARGET_SCRIPT_CAST,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                       );
    CLIENTOPCODE(CMSG_SPELLCLICK,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSpellClick                 );
    CLIENTOPCODE(CMSG_NO_SPELL_VARIANCE,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                       );

    // Spell Aura
    CLIENTOPCODE(CMSG_CANCEL_AURA,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelAuraOpcode           );
    CLIENTOPCODE(CMSG_PET_CANCEL_AURA,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetCancelAuraOpcode        );
    CLIENTOPCODE(CMSG_CANCEL_GROWTH_AURA,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelGrowthAuraOpcode     );

    // Spell Cooldown
    CLIENTOPCODE(CMSG_COOLDOWN_CHEAT,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                       );

    // Spell Pet
    CLIENTOPCODE(CMSG_PET_CAST_SPELL,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetCastSpellOpcode         );
    CLIENTOPCODE(CMSG_PET_SPELL_AUTOCAST,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetSpellAutocastOpcode     );

    /***********************************************************/
    /******************* TRANSPORT OPCODES *********************/
    /***********************************************************/

    // Transport Taxi
    CLIENTOPCODE(CMSG_TAXICLEARALLNODES,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                      );
    CLIENTOPCODE(CMSG_TAXIENABLEALLNODES,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                      );
    CLIENTOPCODE(CMSG_TAXISHOWNODES,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                      );
    CLIENTOPCODE(CMSG_TAXINODE_STATUS_QUERY,             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleTaxiNodeStatusQueryOpcode );
    CLIENTOPCODE(CMSG_TAXIQUERYAVAILABLENODES,           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleTaxiQueryAvailableNodes   );
    CLIENTOPCODE(CMSG_ACTIVATETAXI,                      STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleActivateTaxiOpcode        );
    CLIENTOPCODE(CMSG_TAXICLEARNODE,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                      );
    CLIENTOPCODE(CMSG_TAXIENABLENODE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                      );
    CLIENTOPCODE(CMSG_ACTIVATETAXIEXPRESS,               STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleActivateTaxiExpressOpcode );
    CLIENTOPCODE(CMSG_SET_TAXI_BENCHMARK_MODE,           STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleSetTaxiBenchmarkOpcode    );
    CLIENTOPCODE(CMSG_ENABLETAXI,                        STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleTaxiQueryAvailableNodes   );

    /***********************************************************/
    /****************** TIME / SPEED OPCODES *******************/
    /***********************************************************/

    // Time
    CLIENTOPCODE(CMSG_GAMETIME_SET,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                      );
    CLIENTOPCODE(CMSG_SERVERTIME,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                      );
    CLIENTOPCODE(CMSG_PLAYED_TIME,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePlayedTime                );
    CLIENTOPCODE(CMSG_QUERY_TIME,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryTimeOpcode           );
    CLIENTOPCODE(CMSG_TIME_SYNC_RESP,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTimeSyncResp              );
    CLIENTOPCODE(CMSG_KEEP_ALIVE,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleEarlyProccess             );
    CLIENTOPCODE(CMSG_WORLD_STATE_UI_TIMER_UPDATE,       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWorldStateUITimerUpdate   );
    CLIENTOPCODE(CMSG_READY_FOR_ACCOUNT_DATA_TIMES,      STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleReadyForAccountDataTimes  );

    // Speed
    CLIENTOPCODE(CMSG_GAMESPEED_SET,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL                      );

    /***********************************************************/
    /****************** UNCATEGORZIED OPCODES ******************/
    /***********************************************************/

    CLIENTOPCODE(CMSG_BOOTME,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_DBLOOKUP,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_ZONE_MAP,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_DEBUG_CHANGECELLZONE,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_CREATEMONSTER,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_DESTROYMONSTER,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_WEATHER_SPEED_CHEAT,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_MAKEMONSTERATTACKGUID,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_BOT_DETECTED2,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_PETGODMODE,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_BEASTMASTER,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_CHEAT_SETMONEY,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SET_WORLDSTATE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_ADVANCE_SPAWN_TIME,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_AREATRIGGER,                       STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleAreaTriggerOpcode );
    CLIENTOPCODE(CMSG_STANDSTATECHANGE,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleStandStateChangeOpcode );
    CLIENTOPCODE(CMSG_SET_SELECTION,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetSelectionOpcode );
    CLIENTOPCODE(CMSG_UNUSED2,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_BINDER_ACTIVATE,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBinderActivateOpcode );
    CLIENTOPCODE(CMSG_BANKER_ACTIVATE,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBankerActivateOpcode );
    CLIENTOPCODE(CMSG_BUY_BANK_SLOT,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuyBankSlotOpcode );
    CLIENTOPCODE(CMSG_BUG,                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBugOpcode );
    CLIENTOPCODE(CMSG_SET_SKILL_CHEAT,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_PING,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleEarlyProccess );
    CLIENTOPCODE(CMSG_SETSHEATHED,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetSheathedOpcode );
    CLIENTOPCODE(CMSG_ZONEUPDATE,                        STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleZoneUpdateOpcode );
    CLIENTOPCODE(CMSG_UNLEARN_SKILL,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleUnlearnSkillOpcode );
    CLIENTOPCODE(CMSG_SPIRIT_HEALER_ACTIVATE,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSpiritHealerActivateOpcode);
    CLIENTOPCODE(CMSG_SET_STAT_CHEAT,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_XP_CHEAT,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SERVER_COMMAND,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_CLEAR_EXPLORATION,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SET_AMMO,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetAmmoOpcode );
    CLIENTOPCODE(CMSG_SET_ACTIVE_MOVER,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetActiveMoverOpcode );
    CLIENTOPCODE(CMSG_FAR_SIGHT,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleFarSightOpcode );
    CLIENTOPCODE(CMSG_SELF_RES,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSelfResOpcode );
    CLIENTOPCODE(CMSG_RUN_SCRIPT,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_AREA_SPIRIT_HEALER_QUERY,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAreaSpiritHealerQueryOpcode);
    CLIENTOPCODE(CMSG_AREA_SPIRIT_HEALER_QUEUE,          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAreaSpiritHealerQueueOpcode);
    CLIENTOPCODE(CMSG_WARDEN_DATA,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWardenDataOpcode );
    CLIENTOPCODE(CMSG_DEBUG_ACTIONS_START,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_DEBUG_ACTIONS_STOP,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_LUA_USAGE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_IGNORE_KNOCKBACK_CHEAT,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_MAELSTROM_INVALIDATE_CACHE,        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_SEND_LOCAL_EVENT,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_BOT_DETECTED,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_CHEAT_PLAYER_LOGIN,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_CHEAT_PLAYER_LOOKUP,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_COMPLAIN,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleComplainOpcode );
    CLIENTOPCODE(CMSG_GET_MIRRORIMAGE_DATA,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMirrrorImageDataRequest );
    CLIENTOPCODE(CMSG_IGNORE_DIMINISHING_RETURNS_CHEAT,  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_QUERY_SERVER_BUCK_DATA,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_CLEAR_SERVER_BUCK_DATA,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_ALTER_APPEARANCE,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAlterAppearance );
    CLIENTOPCODE(CMSG_UNITANIMTIER_CHEAT,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_DISMISS_CRITTER,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDismissCritter );
    CLIENTOPCODE(CMSG_FLOOD_GRACE_CHEAT,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );

    // Lottery
    CLIENTOPCODE(CMSG_LOTTERY_QUERY_OBSOLETE,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );    
    CLIENTOPCODE(CMSG_BUY_LOTTERY_TICKET_OBSOLETE,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );

    // Action
    CLIENTOPCODE(CMSG_FORCEACTION,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_FORCEACTIONONOTHER,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_FORCEACTIONSHOW,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
     
    // Event
    CLIENTOPCODE(CMSG_SEND_EVENT,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_DEBUG_AISTATE,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );

    // Commentator
    CLIENTOPCODE(CMSG_COMMENTATOR_ENABLE,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_COMMENTATOR_GET_MAP_INFO,          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_COMMENTATOR_GET_PLAYER_INFO,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_COMMENTATOR_ENTER_INSTANCE,        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_COMMENTATOR_EXIT_INSTANCE,         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_COMMENTATOR_INSTANCE_COMMAND,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_COMMENTATOR_SKIRMISH_QUEUE_COMMAND, STATUS_NEVER,   PROCESS_INPLACE,      &WorldSession::HandleNULL );

    // Vehicle
    CLIENTOPCODE(CMSG_DISMISS_CONTROLLED_VEHICLE,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDismissControlledVehicle );
    CLIENTOPCODE(CMSG_REQUEST_VEHICLE_EXIT,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRequestVehicleExit );
    CLIENTOPCODE(CMSG_REQUEST_VEHICLE_PREV_SEAT,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChangeSeatsOnControlledVehicle);
    CLIENTOPCODE(CMSG_REQUEST_VEHICLE_NEXT_SEAT,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChangeSeatsOnControlledVehicle);
    CLIENTOPCODE(CMSG_REQUEST_VEHICLE_SWITCH_SEAT,       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChangeSeatsOnControlledVehicle);
    CLIENTOPCODE(CMSG_CHANGE_SEATS_ON_CONTROLLED_VEHICLE, STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChangeSeatsOnControlledVehicle);
    CLIENTOPCODE(CMSG_QUERY_VEHICLE_STATUS,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::HandleNULL );
    CLIENTOPCODE(CMSG_PLAYER_VEHICLE_ENTER,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEnterPlayerVehicle );
    CLIENTOPCODE(CMSG_EJECT_PASSENGER,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEjectPassenger );

    /***********************************************************/
    /********************** WORLD OPCODES **********************/
    /***********************************************************/

    // World Teleport
    CLIENTOPCODE(CMSG_WORLD_TELEPORT,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWorldTeleportOpcode);
    CLIENTOPCODE(CMSG_WORLD_LOGIN,                     STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleWorldLoginOpcode   );
    CLIENTOPCODE(CMSG_TELEPORT_TO_UNIT,                STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleNULL               );
    CLIENTOPCODE(CMSG_REQUEST_ACCOUNT_DATA,            STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleRequestAccountData );
    CLIENTOPCODE(CMSG_UPDATE_ACCOUNT_DATA,             STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleUpdateAccountData  );
};
