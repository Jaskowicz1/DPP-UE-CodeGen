#pragma once
 
/************************************************************************************
 *
 * D++, A Lightweight C++ library for Discord
 *
 * SPDX-License-Identifier: Apache-2.0
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
 * @brief Defines types of audit log entry
 */
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

/**
 * @brief Defines audit log changes
 */
USTRUCT(BlueprintType)
struct audit_change {
	GENERATED_BODY()

};

/**
 * @brief Extra information for an audit log entry
 */
USTRUCT(BlueprintType)
struct audit_extra {
	GENERATED_BODY()

};

/**
 * @brief An individual audit log entry
 */
USTRUCT(BlueprintType)
struct audit_entry {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|audit_entry")
	FString			id;		//!< id of the entry

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|audit_entry")
	FString			target_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|audit_entry")
	TArray<audit_change>	changes;	//!< Optional: changes made to the target_id

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|audit_entry")
	audit_type			type;		//!< type of action that occurred

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|audit_entry")
	std::optional<audit_extra>	extra;	//!< Optional: additional info for certain action types

};

/**
 * @brief The auditlog class represents the audit log entries of a guild.
 */
USTRUCT(BlueprintType)
struct auditlog {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|auditlog")
	TArray<audit_entry> entries;	//!< Audit log entries

};

