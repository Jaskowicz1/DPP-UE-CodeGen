#pragma once
 
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

UENUM(BlueprintType)
enum text_style_type : uint8 {
	text_short = 1,
	text_paragraph = 2,
};

UENUM(BlueprintType)
enum component_style : uint8 {
	cos_primary = 1,
	cos_secondary,
	cos_success,
	cos_danger,
	cos_link
};

UENUM(BlueprintType)
enum component_default_value_type: : uint8 {
	cdt_user = 0,
	cdt_role = 1,
	cdt_channel = 2,
};

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
		dpp::FString id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|component")
		bool animated;

};

UENUM(BlueprintType)
enum attachment_flags : uint8 {
	a_is_remix = 1 << 2,
};

UENUM(BlueprintType)
enum sticker_type : uint8 {
	st_standard = 1,
	st_guild = 2
};

UENUM(BlueprintType)
enum sticker_format : uint8 {
	sf_png = 1,
	sf_apng = 2,
	sf_lottie = 3,
	sf_gif = 4,
};

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

UENUM(BlueprintType)
enum cache_policy_setting_t : uint8 {
	cp_aggressive = 0,
	cp_lazy = 1,
	cp_none = 2
};
