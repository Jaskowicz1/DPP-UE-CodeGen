#pragma once
 
/************************************************************************************
 *
 * D++, A Lightweight C++ library for Discord
 *
 * Copyright 2021 Craig Edwards and D++ contributors
 * (https://github.com/brainboxdotcc/DPP/graphs/contributors)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ************************************************************************************/
/**
 * @brief Represents voice regions for guilds and channels.
 * @deprecated Deprecated in favour of per-channel regions.
 * Please use channel::rtc_region instead.
 */
UENUM(BlueprintType)
enum region : uint8 {
	r_brazil,		//!< Brazil
	r_central_europe,	//!< Central Europe
	r_hong_kong,		//!< Hong Kong
	r_india,		//!< India
	r_japan,		//!< Japan
	r_russia,		//!< Russia
	r_singapore,		//!< Singapore
	r_south_africa,		//!< South Africa
	r_sydney,		//!< Sydney
	r_us_central,		//!< US Central
	r_us_east,		//!< US East Coast
	r_us_south,		//!< US South
	r_us_west,		//!< US West Coast
	r_western_europe	//!< Western Europe
};

/**
 * @brief The various flags that represent the status of a guild object
 */
UENUM(BlueprintType)
enum guild_flags : uint32 {
	g_large =				0b00000000000000000000000000000001,
	g_unavailable = 			0b00000000000000000000000000000010,
	g_widget_enabled =			0b00000000000000000000000000000100,
	g_invite_splash =			0b00000000000000000000000000001000,
	g_vip_regions =				0b00000000000000000000000000010000,
	g_vanity_url =				0b00000000000000000000000000100000,
	g_verified =				0b00000000000000000000000001000000,
	g_partnered =				0b00000000000000000000000010000000,
	g_community =				0b00000000000000000000000100000000,
	g_role_subscription_enabled = 	0b00000000000000000000001000000000,
	g_news =				0b00000000000000000000010000000000,
	g_discoverable =			0b00000000000000000000100000000000,
	g_featureable =				0b00000000000000000001000000000000,
	g_animated_icon =			0b00000000000000000010000000000000,
	g_banner =				0b00000000000000000100000000000000,
	g_welcome_screen_enabled =		0b00000000000000001000000000000000,
	g_member_verification_gate =		0b00000000000000010000000000000000,
	g_preview_enabled =			0b00000000000000100000000000000000,
	g_no_join_notifications =		0b00000000000001000000000000000000,
	g_no_boost_notifications =		0b00000000000010000000000000000000,
	g_has_animated_icon =			0b00000000000100000000000000000000,
	g_has_animated_banner =			0b00000000001000000000000000000000,
	g_no_setup_tips =			0b00000000010000000000000000000000,
	g_no_sticker_greeting =			0b00000000100000000000000000000000,
	g_monetization_enabled =		0b00000001000000000000000000000000,
	g_more_stickers =			0b00000010000000000000000000000000,
	g_creator_store_page_enabled =	0b00000100000000000000000000000000,
	g_role_icons =				0b00001000000000000000000000000000,
	g_seven_day_thread_archive =		0b00010000000000000000000000000000,
	g_three_day_thread_archive =		0b00100000000000000000000000000000,
	g_ticketed_events =			0b01000000000000000000000000000000,
	g_channel_banners =			0b10000000000000000000000000000000,
};

/**
 * @brief Additional boolean flag values for guild, as guild_flags is full
 */
UENUM(BlueprintType)
enum guild_flags_extra : uint16 {
	g_premium_progress_bar_enabled =	0b0000000000000001,
	g_animated_banner =			0b0000000000000010,
	g_auto_moderation =			0b0000000000000100,
	g_invites_disabled =		0b0000000000001000,
	g_developer_support_server =	0b0000000000010000,
	g_no_role_subscription_notifications = 0b0000000000100000,
	g_no_role_subscription_notification_replies = 0b0000000001000000,
	g_role_subscriptions_available_for_purchase = 0b0000000010000000,
	g_raid_alerts_disabled = 0b0000000100000000,
};

/**
 * @brief Various flags that can be used to indicate the status of a guild member.
 * @note Use the setter functions in guild_member and do not toggle the bits yourself.
 */
UENUM(BlueprintType)
enum guild_member_flags : uint16 {
	gm_deaf =		0b0000000000000001,
	gm_mute =		0b0000000000000010,
	gm_pending =		0b0000000000000100,
	gm_animated_avatar = 	0b0000000000001000,
	gm_voice_action = 		0b0000000000010000,
	gm_did_rejoin = 0b0000000000100000,
	gm_completed_onboarding = 0b0000000001000000,
	gm_bypasses_verification = 0b0000000010000000,
	gm_started_onboarding = 0b0000000100000000,
	gm_roles_action    = 0b0000001000000000,
	gm_nickname_action = 0b0000010000000000,
};

/**
 * @brief Represents user membership upon a guild.
 * This contains the user's nickname, guild roles, and any other guild-specific flags.
 */
USTRUCT(BlueprintType)
struct guild_member {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild_member")
	FString guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild_member")
	FString user_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild_member")
	FString avatar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild_member")
	FDateTime communication_disabled_until;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild_member")
	FDateTime joined_at;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild_member")
	FDateTime premium_since;

};

/**
 * @brief Defines a channel on a server's welcome screen
 */
USTRUCT(BlueprintType)
struct welcome_channel: {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Welcome_channel:")
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Welcome_channel:")
	FString emoji_name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Welcome_channel:")
	FString channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Welcome_channel:")
	FString emoji_id;

};

/**
 * @brief Defines a server's welcome screen
 */
USTRUCT(BlueprintType)
struct welcome_screen: {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Welcome_screen:")
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Welcome_screen:")
	TArray<welcome_channel> welcome_channels;

};

/**
 * @brief Guild NSFW level.
 * Used to represent just how naughty this guild is. Naughty  guild, go sit in the corner.
 * @note This is set by Discord, and cannot be set by any bot or user on the guild.
 */
UENUM(BlueprintType)
enum guild_nsfw_level_t : uint8 {
	nsfw_default		=	0,
	nsfw_explicit		=	1,
	nsfw_safe		=	2,
	nsfw_age_restricted	=	3
};

/**
 * @brief explicit content filter level.
 * This is set by a guild admin, but can be forced to a setting if the server is verified,
 * partnered, official etc.
 */
UENUM(BlueprintType)
enum guild_explicit_content_t : uint8 {
	expl_disabled =			0,
	expl_members_without_roles =	1,
	expl_all_members =		2
};

/**
 * @brief MFA level for server. If set to elevated all moderators need MFA to perform specific
 * actions such as kick or ban.
 */
UENUM(BlueprintType)
enum mfa_level_t : uint8 {
	mfa_none = 0,
	mfa_elevated = 1
};

/**
 * @brief Guild verification level
 */
UENUM(BlueprintType)
enum verification_level_t : uint8 {
	ver_none =	0,
	ver_low	= 	1,
	ver_medium =	2,
	ver_high =	3,
	ver_very_high =	4,
};

/**
 * @brief Default message notification level
 */
UENUM(BlueprintType)
enum default_message_notification_t: : uint8 {
	dmn_all = 0,
	dmn_only_mentions = 1,
};

/**
 * @brief Premium tier
 */
UENUM(BlueprintType)
enum guild_premium_tier_t: : uint8 {
	tier_none = 0,
	tier_1 = 1,
	tier_2 = 2,
	tier_3 = 3,
};

/**
 * @brief Voice AFK timeout values for guild::afk_timeout
 */
UENUM(BlueprintType)
enum guild_afk_timeout_t: : uint8 {
	afk_off,
	afk_60,
	afk_300,
	afk_900,
	afk_1800,
	afk_3600,
};

/** @brief Guild members container
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Members_container")
TMap<FString, guild_member> members_container;

/**
 * @brief Represents a guild on Discord (AKA a server)
 */
USTRUCT(BlueprintType)
struct guild {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	FString vanity_url_code;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	TArray<FString> roles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	TArray<FString> channels;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	TArray<FString> threads;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	TArray<FString> emojis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	TMap<FString, voicestate> voice_members;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	members_container members;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	welcome_screen welcome_screen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	utility::icon icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	utility::icon splash;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	utility::icon discovery_splash;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	utility::icon banner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	FString owner_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	FString afk_channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	FString application_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	FString system_channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	FString rules_channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	FString public_updates_channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	FString widget_channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	FString safety_alerts_channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	int64 member_count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	int64 flags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	int64 max_presences;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	int64 max_members;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	int flags_extra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	int shard_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	int premium_subscription_count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	guild_afk_timeout_t afk_timeout;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	int max_video_channel_users;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	default_message_notification_t default_message_notifications;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	guild_premium_tier_t premium_tier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	verification_level_t verification_level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	guild_explicit_content_t explicit_content_filter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	mfa_level_t mfa_level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
	guild_nsfw_level_t nsfw_level;

};

/** A container of guilds */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild")
TMap<FString, guild> guild_map;

/**
 * @brief Represents a guild widget, simple web widget of member list
 */
USTRUCT(BlueprintType)
struct guild_widget {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild_widget")
	FString channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild_widget")
	bool enabled;

};

/**
 * @brief The onboarding mode for the onboarding object. Defines the criteria used to satisfy Onboarding constraints that are required for enabling.
 */
UENUM(BlueprintType)
enum onboarding_mode: : uint8 {
	gom_default = 	0, //!< Counts only Default Channels towards constraints
	gom_advanced = 	1, //!< Counts Default Channels and Questions towards constraints
};

/**
 * @brief The various types of onboarding_prompt
 */
UENUM(BlueprintType)
enum onboarding_prompt_type: : uint8 {
	opt_multiple_choice = 0, //!< Multiple choice
	opt_dropdown = 1, //!< Dropdown
};

/**
 * @brief Various flags for onboarding_prompt
 */
UENUM(BlueprintType)
enum onboarding_prompt_flags: : uint8 {
	opf_single_select = 1 << 0, //!< Indicates whether users are limited to selecting one option for the prompt
	opf_required =		1 << 1, //!< Indicates whether the prompt is required before a user completes the onboarding flow
	opf_in_onboarding = 1 << 2, //!< Indicates whether the prompt is present in the onboarding flow. If set, the prompt will only appear in the Channels & Roles tab
};

/**
 * @brief Represents an onboarding prompt option
 */
USTRUCT(BlueprintType)
struct onboarding_prompt_option: {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Onboarding_prompt_option:")
	TArray<FString> channel_ids; //!< IDs for channels a member is added to when the option is selected

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Onboarding_prompt_option:")
	TArray<FString> role_ids; //!< IDs for roles assigned to a member when the option is selected

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Onboarding_prompt_option:")
	emoji emoji; //!< Emoji of the option

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Onboarding_prompt_option:")
	FString title; //!< Title of the option

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Onboarding_prompt_option:")
	FString description; //!< Description of the option

};

/**
 * @brief Represents an onboarding prompt
 */
USTRUCT(BlueprintType)
struct onboarding_prompt: {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Onboarding_prompt:")
	TArray<onboarding_prompt_option> options; //!< Options available within the prompt

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Onboarding_prompt:")
	FString title; //!< Title of the prompt

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Onboarding_prompt:")
	int flags; //!< A set of flags built from the bitmask defined by onboarding_prompt_flags

};

/**
 * @brief Represents a guild's onboarding flow
 */
USTRUCT(BlueprintType)
struct onboarding: {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Onboarding:")
	FString guild_id; //!< ID of the guild this onboarding is part of

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Onboarding:")
	TArray<onboarding_prompt> prompts; //!< Prompts shown during onboarding and in customize community

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Onboarding:")
	TArray<FString> default_channel_ids; //!< Channel IDs that members get opted into automatically

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Onboarding:")
	bool enabled; //!< Whether onboarding is enabled in the guild

};

/**
 * @brief helper function to deserialize a guild_member from json
 *
 * @see https://github.com/nlohmann/json#arbitrary-types-conversions
 *
 * @param j output json object
 * @param gm guild_member to be deserialized
 */
/** A container of guild members */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild_member")
TMap<FString, guild_member> guild_member_map;

/**
 * @brief Get the guild_member from cache of given IDs
 *
 * @param guild_id ID of the guild to find guild_member for
 * @param user_id ID of the user to find guild_member for
 *
 * @throw cache_exception if the guild or guild_member is not found in the cache
 * @return guild_member the cached object, if found
 */
