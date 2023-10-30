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
 * @brief Represents the type of a component
 */
UENUM(BlueprintType)
enum component_type : uint8 {
	cot_action_row = 1,
	cot_button = 2,
	cot_selectmenu = 3,
	cot_text = 4,
	cot_user_selectmenu = 5,
	cot_role_selectmenu = 6,
	cot_mentionable_selectmenu = 7,
	cot_channel_selectmenu = 8,
};

/**
 * @brief Types of text input
 */
UENUM(BlueprintType)
enum text_style_type : uint8 {
	text_short = 1,
	text_paragraph = 2,
};

/**
 * @brief Represents the style of a button
 */
UENUM(BlueprintType)
enum component_style : uint8 {
	cos_primary = 1,
	cos_secondary,
	cos_success,
	cos_danger,
	cos_link
};

/**
 * Represents the type of a component_default_value
 *
 * @note They're different to discord's value types
 */
UENUM(BlueprintType)
enum component_default_value_type: : uint8 {
	cdt_user = 0,
	cdt_role = 1,
	cdt_channel = 2,
};

/**
 * @brief A Default value structure for components
 */
USTRUCT(BlueprintType)
struct component_default_value {
	GENERATED_BODY()

};

/**
 * @brief An option for a select component
 */
USTRUCT(BlueprintType)
struct select_option {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|select_option")
	FString label;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|select_option")
	FString value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|select_option")
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|select_option")
	bool is_default;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|select_option")
	struct inner_select_emoji {

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|select_option")
		FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|select_option")
		FString id = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|select_option")
		bool animated = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|select_option")
	} emoji;

};

/**
 * @brief Represents the component object.
 * A component is a clickable button or drop down list
 * within a discord message, where the buttons emit
 * on_button_click events when the user interacts with
 * them.
 *
 * You should generally define one component object and
 * then insert one or more additional components into it
 * using component::add_component(), so that the parent
 * object is an action row and the child objects are buttons.
 */
USTRUCT(BlueprintType)
struct component {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	component_type type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	TArray<component> components;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	FString label;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	component_style style;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	text_style_type text_style;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	FString custom_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	FString url;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	FString placeholder;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	int32_t min_values;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	int32_t max_values;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	int32_t min_length;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	int32_t max_length;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	TArray<select_option> options;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	TArray<int> channel_types;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	TArray<component_default_value> default_values;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	bool disabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	bool required;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	TVariant<FString, int64_t, double> value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	struct inner_emoji {

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
		FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
		FString id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
		bool animated;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
	} emoji;

};

/**
 * @brief A footer in a embed
 */
USTRUCT(BlueprintType)
struct embed_footer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed_footer")
	FString text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed_footer")
	FString icon_url;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed_footer")
	FString proxy_url;

};

/**
 * @brief An video, image or thumbnail in a embed
 */
USTRUCT(BlueprintType)
struct embed_image {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed_image")
	FString url;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed_image")
	FString proxy_url;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed_image")
	FString height;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed_image")
	FString width;

};

/**
 * @brief Embed provider in a embed. Received from discord but cannot be sent
 */
USTRUCT(BlueprintType)
struct embed_provider {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed_provider")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed_provider")
	FString url;

};

/**
 * @brief Author within a embed object
 */
USTRUCT(BlueprintType)
struct embed_author {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed_author")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed_author")
	FString url;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed_author")
	FString icon_url;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed_author")
	FString proxy_icon_url;

};

/**
 * @brief A embed may contain zero or more fields
 */
USTRUCT(BlueprintType)
struct embed_field {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed_field")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed_field")
	FString value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed_field")
	bool is_inline;

};

/**
 * @brief A rich embed for display within a message
 */
USTRUCT(BlueprintType)
struct embed {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed")
	FString			title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed")
	FString			type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed")
	FString			description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed")
	FString			url;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed")
	FDateTime				timestamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed")
	std::optional<int64>			color;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed")
	std::optional<embed_footer>	footer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed")
	std::optional<embed_image>	image;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed")
	std::optional<embed_image>	thumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed")
	std::optional<embed_image>	video;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed")
	std::optional<embed_provider>	provider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed")
	std::optional<embed_author>	author;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|embed")
	TArray<embed_field>	fields;

};

/**
 * @brief Represents a reaction to a message
 */
USTRUCT(BlueprintType)
struct reaction {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|reaction")
	int64 count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|reaction")
	int64 count_burst;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|reaction")
	int64 count_normal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|reaction")
	FString emoji_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|reaction")
	FString emoji_name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|reaction")
	bool me;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|reaction")
	bool me_burst;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|reaction")
	TArray<int64> burst_colors;

};

/**
 * @brief Bitmask flags for a attachment
 */
UENUM(BlueprintType)
enum attachment_flags : uint8 {
	a_is_remix = 1 << 2,
};

/**
 * @brief Represents an attachment in a message
 */
USTRUCT(BlueprintType)
struct attachment {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|attachment")
	FString id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|attachment")
	int64 size;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|attachment")
	FString filename;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|attachment")
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|attachment")
	FString url;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|attachment")
	FString proxy_url;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|attachment")
	int64 width;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|attachment")
	int64 height;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|attachment")
	FString content_type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|attachment")
	bool ephemeral;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|attachment")
	double duration_secs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|attachment")
	FString waveform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|attachment")
	int		flags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|attachment")
	struct message* owner;

};

/**
 * @brief Represents the type of a sticker
 */
UENUM(BlueprintType)
enum sticker_type : uint8 {
	st_standard = 1,
	st_guild = 2
};

/**
 * @brief The file format (png, apng, lottie) of a sticker
 */
UENUM(BlueprintType)
enum sticker_format : uint8 {
	sf_png = 1,
	sf_apng = 2,
	sf_lottie = 3,
	sf_gif = 4,
};

/**
 * @brief Represents stickers received in messages
 */
USTRUCT(BlueprintType)
struct sticker {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker")
	FString	pack_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker")
	FString	name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker")
	FString	 description;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker")
	FString	 tags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker")
	FString	 asset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker")
	sticker_type	type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker")
	sticker_format	format_type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker")
	bool		available;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker")
	FString	guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker")
	user		sticker_user;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker")
	int		sort_value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker")
	FString	filename;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker")
	FString	filecontent;

};

/**
 * @brief Represents a sticker pack (the built in groups of stickers that all nitro users get to use)
 */
USTRUCT(BlueprintType)
struct sticker_pack {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker_pack")
	TMap<FString, sticker> stickers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker_pack")
	FString	 name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker_pack")
	FString	   sku_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker_pack")
	FString	   cover_sticker_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker_pack")
	FString	 description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker_pack")
	FString	   banner_asset_id;

};

/**
 * @brief Bitmask flags for a message
 */
UENUM(BlueprintType)
enum message_flags : uint16 {
	m_crossposted = 1 << 0,
	m_is_crosspost =  1 << 1,
	m_suppress_embeds = 1 << 2,
	m_source_message_deleted = 1 << 3,
	m_urgent = 1 << 4,
	m_has_thread = 1 << 5,
	m_ephemeral = 1 << 6,
	m_loading = 1 << 7,
	m_thread_mention_failed = 1 << 8,
	m_suppress_notifications = 1 << 12,
	m_is_voice_message = 1 << 13,
};

/**
 * @brief Represents possible values for the embed type field.
 * These are loosely defined by the API docs and do not influence how the client renders embeds.
 * The only type a bot can send is embed_type::emt_rich.
 */
/**
 * @brief Message types for message::type
 */
UENUM(BlueprintType)
enum message_type : uint8 {
	mt_default					= 0,
	mt_recipient_add				= 1,
	mt_recipient_remove				= 2,
	mt_call						= 3,
	mt_channel_name_change				= 4,
	mt_channel_icon_change				= 5,
	mt_channel_pinned_message			= 6,
	mt_guild_member_join				= 7,
	mt_user_premium_guild_subscription		= 8,
	mt_user_premium_guild_subscription_tier_1	= 9,
	mt_user_premium_guild_subscription_tier_2	= 10,
	mt_user_premium_guild_subscription_tier_3	= 11,
	mt_channel_follow_add				= 12,
	mt_guild_discovery_disqualified			= 14,
	mt_guild_discovery_requalified			= 15,
	mt_guild_discovery_grace_period_initial_warning	= 16,
	mt_guild_discovery_grace_period_final_warning	= 17,
	mt_thread_created				= 18,
	mt_reply					= 19,
	mt_application_command				= 20,
	mt_thread_starter_message			= 21,
	mt_guild_invite_reminder			= 22,
	mt_context_menu_command 			= 23,
	mt_auto_moderation_action			= 24,
	mt_role_subscription_purchase		= 25,
	mt_interaction_premium_upsell		= 26,
	mt_stage_start						= 27,
	mt_stage_end						= 28,
	mt_stage_speaker					= 29,
	mt_stage_topic						= 31,
	mt_application_premium_subscription	= 32,
};

/**
 * @brief Represents the caching policy of a cache in the library.
 */
UENUM(BlueprintType)
enum cache_policy_setting_t : uint8 {
	cp_aggressive = 0,
	cp_lazy = 1,
	cp_none = 2
};

/**
 * @brief Represents the caching policy of the cluster.
 * 
 * Channels and guilds are always cached as these caches are used
 * internally by the library. The memory usage of these is minimal.
 * 
 * All default to 'aggressive' which means to actively attempt to cache,
 * going out of the way to fill the caches completely. On large bots this
 * can take a LOT of RAM.
 */
USTRUCT(BlueprintType)
struct cache_policy_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|cache_policy_t")
	cache_policy_setting_t user_policy = cp_aggressive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|cache_policy_t")
	cache_policy_setting_t emoji_policy = cp_aggressive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|cache_policy_t")
	cache_policy_setting_t role_policy = cp_aggressive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|cache_policy_t")
	cache_policy_setting_t channel_policy = cp_aggressive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|cache_policy_t")
	cache_policy_setting_t guild_policy = cp_aggressive;

};

/**
 * @brief Contains a set of predefined cache policies for use when constructing a cluster
 */
/**
 * @brief Represents messages sent and received on Discord
 */
USTRUCT(BlueprintType)
struct message {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	FString	   channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	FString	   guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	user		author;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	guild_member	member;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	FString	content;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	TArray<component> components;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	FDateTime		sent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	FDateTime		edited;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	TArray<std::pair<user, guild_member>>	mentions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	TArray<FString> mention_roles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	TArray<channel> mention_channels;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	TArray<attachment> attachments;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	TArray<embed> embeds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	TArray<reaction> reactions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	FString	nonce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	FString	webhook_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	TArray<sticker> stickers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	TArray<FString>	filename;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	TArray<FString>	filecontent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	TArray<FString>	filemimetype;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	struct message_ref {

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
		FString message_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
		FString channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
		FString guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
		bool fail_if_not_exists;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	} message_reference;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	struct message_interaction_struct{

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
		FString id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
		int type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
		FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
		user usr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	} interaction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	struct allowed_ref {

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
		bool parse_users;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
		bool parse_everyone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
		bool parse_roles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
		bool replied_user;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
		TArray<FString> users;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
		TArray<FString> roles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	} allowed_mentions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	class cluster* owner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	message_type type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	int		flags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	bool		pinned;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	bool		tts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message")
	bool   		mention_everyone;

};

/** A group of messages */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|message_map;")
typedef TMap<FString, message> message_map;

/** A group of stickers */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker_map;")
typedef TMap<FString, sticker> sticker_map;

/** A group of sticker packs */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sticker_pack_map;")
typedef TMap<FString, sticker_pack> sticker_pack_map;

