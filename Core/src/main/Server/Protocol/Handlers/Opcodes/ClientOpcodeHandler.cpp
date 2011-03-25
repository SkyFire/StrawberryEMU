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
};
