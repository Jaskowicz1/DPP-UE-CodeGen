#pragma once
 
UENUM(BlueprintType)
enum audit_type : uint8 {
	aut_guild_update			=	1,
	aut_channel_create		=	10,
	aut_channel_update		=	11,
	aut_channel_delete		=	12,
	aut_channel_overwrite_create	=	13,
	aut_channel_overwrite_update	=	14,
	aut_channel_overwrite_delete	=	15,
	aut_member_kick			=	20,
	aut_member_prune			=	21,
	aut_member_ban_add		=	22,
	aut_member_ban_remove		=	23,
	aut_member_update		=	24,
	aut_member_role_update		=	25,
	aut_member_move			=	26,
	aut_member_disconnect		=	27,
	aut_bot_add			=	28,
	aut_role_create			=	30,
	aut_role_update			=	31,
	aut_role_delete			=	32,
	aut_invite_create		=	40,
	aut_invite_update		=	41,
	aut_invite_delete		=	42,
	aut_webhook_create		=	50,
	aut_webhook_update		=	51,
	aut_webhook_delete		=	52,
	aut_emoji_create			=	60,
	aut_emoji_update			=	61,
	aut_emoji_delete			=	62,
	aut_message_delete		=	72,
	aut_message_bulk_delete		=	73,
	aut_message_pin			=	74,
	aut_message_unpin		=	75,
	aut_integration_create		=	80,
	aut_integration_update		=	81,
	aut_integration_delete		=	82,
	aut_stage_instance_create	=	83,
	aut_stage_instance_update	=	84,
	aut_stage_instance_delete	=	85,
	aut_sticker_create		=	90,
	aut_sticker_update		=	91,
	aut_sticker_delete		=	92,
	aut_guild_scheduled_event_create	=	100,
	aut_guild_scheduled_event_update	=	101,
	aut_guild_scheduled_event_delete	=	102,
	aut_thread_create		=	110,
	aut_thread_update		=	111,
	aut_thread_delete		=	112,
	aut_appcommand_permission_update	=	121,
	aut_automod_rule_create		=	140,
	aut_automod_rule_update		=	141,
	aut_automod_rule_delete		=	142,
	aut_automod_block_message	=	143,
	aut_automod_flag_to_channel =	144,
	aut_automod_user_communication_disabled =	145,
	aut_creator_monetization_request_created = 150,
	aut_creator_monetization_terms_accepted = 151,
};

USTRUCT(BlueprintType)
struct auditlog {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|auditlog")
	TArray<audit_entry> entries;	//!< Audit log entries

};

