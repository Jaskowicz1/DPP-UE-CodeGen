#pragma once
 
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

USTRUCT(BlueprintType)
struct guild_member {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild_member")
	FString guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild_member")
	FString user_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild_member")
	FString avatar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild_member")
	FDateTime communication_disabled_until;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild_member")
	FDateTime joined_at;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild_member")
	FDateTime premium_since;

};

UENUM(BlueprintType)
enum guild_nsfw_level_t : uint8 {
	nsfw_default		=	0,
	nsfw_explicit		=	1,
	nsfw_safe		=	2,
	nsfw_age_restricted	=	3
};

UENUM(BlueprintType)
enum guild_explicit_content_t : uint8 {
	expl_disabled =			0,
	expl_members_without_roles =	1,
	expl_all_members =		2
};

UENUM(BlueprintType)
enum mfa_level_t : uint8 {
	mfa_none = 0,
	mfa_elevated = 1
};

UENUM(BlueprintType)
enum verification_level_t : uint8 {
	ver_none =	0,
	ver_low	= 	1,
	ver_medium =	2,
	ver_high =	3,
	ver_very_high =	4,
};

UENUM(BlueprintType)
enum default_message_notification_t: : uint8 {
	dmn_all = 0,
	dmn_only_mentions = 1,
};

UENUM(BlueprintType)
enum guild_premium_tier_t: : uint8 {
	tier_none = 0,
	tier_1 = 1,
	tier_2 = 2,
	tier_3 = 3,
};

UENUM(BlueprintType)
enum guild_afk_timeout_t: : uint8 {
	afk_off,
	afk_60,
	afk_300,
	afk_900,
	afk_1800,
	afk_3600,
};

USTRUCT(BlueprintType)
struct guild {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	FString vanity_url_code;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	TArray<FString> roles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	TArray<FString> channels;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	TArray<FString> threads;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	TArray<FString> emojis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	std::map<FString, voicestate> voice_members;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	members_container members;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	dpp::welcome_screen welcome_screen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	utility::icon icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	utility::icon splash;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	utility::icon discovery_splash;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	utility::icon banner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	FString owner_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	FString afk_channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	FString application_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	FString system_channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	FString rules_channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	FString public_updates_channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	FString widget_channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	FString safety_alerts_channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	int64 member_count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	int64 flags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	int64 max_presences;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	int64 max_members;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	int flags_extra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	int shard_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	int premium_subscription_count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	guild_afk_timeout_t afk_timeout;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	int max_video_channel_users;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	default_message_notification_t default_message_notifications;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	guild_premium_tier_t premium_tier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	verification_level_t verification_level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	guild_explicit_content_t explicit_content_filter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	mfa_level_t mfa_level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild")
	guild_nsfw_level_t nsfw_level;

};

USTRUCT(BlueprintType)
struct guild_widget {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild_widget")
	FString channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild_widget")
	bool enabled;

};

UENUM(BlueprintType)
enum onboarding_mode: : uint8 {
	gom_default = 	0, //!< Counts only Default Channels towards constraints
	gom_advanced = 	1, //!< Counts Default Channels and Questions towards constraints
};

UENUM(BlueprintType)
enum onboarding_prompt_type: : uint8 {
	opt_multiple_choice = 0, //!< Multiple choice
	opt_dropdown = 1, //!< Dropdown
};

UENUM(BlueprintType)
enum onboarding_prompt_flags: : uint8 {
	opf_single_select = 1 << 0, //!< Indicates whether users are limited to selecting one option for the prompt
	opf_required =		1 << 1, //!< Indicates whether the prompt is required before a user completes the onboarding flow
	opf_in_onboarding = 1 << 2, //!< Indicates whether the prompt is present in the onboarding flow. If set, the prompt will only appear in the Channels & Roles tab
};

