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
/* Forward declaration */
/**
 * @brief A function used as a callback for any REST based command
 */
/** @brief Base event parameter struct.
 * Each event you receive from the library will have its parameter derived from this class.
 * The class contains the raw event data, and a pointer to the current shard's discord_client object.
 * You can also use this object to cancel the current event, meaning that any listeners after yours do
 * not get notified of the current event if you call it.
 */
USTRUCT(BlueprintType)
struct event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString raw_event = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	discord_client* from = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	mutable bool cancelled = false;

};

/** @brief Log messages */
USTRUCT(BlueprintType)
struct log_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	loglevel severity = ll_info;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString message = {};

};

/** @brief Add user to scheduled event */
USTRUCT(BlueprintType)
struct guild_scheduled_event_user_add_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString event_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString user_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString guild_id = {};

};

/** @brief Delete user from scheduled event */
USTRUCT(BlueprintType)
struct guild_scheduled_event_user_remove_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString event_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString user_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString guild_id = {};

};

/** @brief Create scheduled event */
USTRUCT(BlueprintType)
struct guild_scheduled_event_create_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	scheduled_event created = {};

};

/** @brief Create scheduled event */
USTRUCT(BlueprintType)
struct guild_scheduled_event_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	scheduled_event updated = {};

};

/** @brief Delete scheduled event */
USTRUCT(BlueprintType)
struct guild_scheduled_event_delete_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	scheduled_event deleted = {};

};

/** @brief Create automod rule */
USTRUCT(BlueprintType)
struct automod_rule_create_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	automod_rule created = {};

};

/** @brief Update automod rule */
USTRUCT(BlueprintType)
struct automod_rule_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	automod_rule updated = {};

};

/** @brief Delete automod rule */
USTRUCT(BlueprintType)
struct automod_rule_delete_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	automod_rule deleted = {};

};

/** @brief Execute/trigger automod rule */
USTRUCT(BlueprintType)
struct automod_rule_execute_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString guild_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	automod_action action = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString rule_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	automod_trigger_type rule_trigger_type = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString user_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString channel_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString message_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString alert_system_message_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString content = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString matched_keyword = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString matched_content = {};

};

/** @brief Create stage instance */
USTRUCT(BlueprintType)
struct stage_instance_create_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	stage_instance created = {};

};

/** @brief Update stage instance */
USTRUCT(BlueprintType)
struct stage_instance_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	stage_instance updated = {};

};

/** @brief Delete stage instance */
USTRUCT(BlueprintType)
struct stage_instance_delete_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	stage_instance deleted = {};

};

/** @brief Voice state update */
USTRUCT(BlueprintType)
struct voice_state_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	voicestate state = {};

};

/**
 * @brief Create interaction
 */
USTRUCT(BlueprintType)
struct interaction_create_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	interaction command = {};

};

/**
 * @brief User has issued a slash command
 */
USTRUCT(BlueprintType)
struct slashcommand_t : public interaction_create_t {
	GENERATED_BODY()

};

/**
 * @brief Click on button
 */
USTRUCT(BlueprintType)
struct button_click_t : public interaction_create_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString custom_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	int component_type = {};

};

USTRUCT(BlueprintType)
struct form_submit_t : public interaction_create_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString custom_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	TArray<component> components = {};

};

/**
 * @brief Discord requests that we fill a list of auto completion choices for a command option
 */
USTRUCT(BlueprintType)
struct autocomplete_t : public interaction_create_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString name = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	TArray<command_option> options = {};

};

/**
 * @brief Base class for context menu interactions, e.g. right click on
 * user or message.
 */
USTRUCT(BlueprintType)
struct context_menu_t : public interaction_create_t {
	GENERATED_BODY()

};

/**
 * @brief Event parameter for context menu interactions for messages
 */
USTRUCT(BlueprintType)
struct message_context_menu_t : public context_menu_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	message ctx_message = {};

};

/**
 * @brief Event parameter for context menu interactions for users
 */
USTRUCT(BlueprintType)
struct user_context_menu_t : public context_menu_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	user ctx_user = {};

};

/**
 * @brief Click on select
 */
USTRUCT(BlueprintType)
struct select_click_t : public interaction_create_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString custom_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	TArray<FString> values = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	int component_type = {};

};

/** @brief Delete guild */
USTRUCT(BlueprintType)
struct guild_delete_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild deleted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString guild_id{0};

};

/** @brief Update guild stickers */
USTRUCT(BlueprintType)
struct guild_stickers_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* updating_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	TArray<sticker> stickers = {};

};

/** @brief Guild join request delete (user declined membership screening) */
USTRUCT(BlueprintType)
struct guild_join_request_delete_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString guild_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString user_id = {};

};

/** @brief Delete channel */
USTRUCT(BlueprintType)
struct channel_delete_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* deleting_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	channel deleted;

};

/** @brief Update channel */
USTRUCT(BlueprintType)
struct channel_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* updating_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	channel* updated = nullptr;

};

/** @brief Session ready */
USTRUCT(BlueprintType)
struct ready_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString session_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	int64 shard_id = {};

};

/** @brief Message Deleted */
USTRUCT(BlueprintType)
struct message_delete_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString id{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString channel_id{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString guild_id{0};

};

/** @brief Guild member remove */
USTRUCT(BlueprintType)
struct guild_member_remove_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* removing_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString guild_id{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	user removed;

};

/** @brief Session resumed */
USTRUCT(BlueprintType)
struct resumed_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString session_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	int64 shard_id = 0;

};

/** @brief Guild role create */
USTRUCT(BlueprintType)
struct guild_role_create_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* creating_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	role* created = nullptr;

};

/** @brief Typing start */
USTRUCT(BlueprintType)
struct typing_start_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* typing_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	channel* typing_channel = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	user* typing_user = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString user_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FDateTime timestamp = 0;

};

/** @brief Voice state update */
USTRUCT(BlueprintType)
struct voice_track_marker_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	discord_voice_client* voice_client = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString track_meta = {};

};

/** @brief Message reaction add */
USTRUCT(BlueprintType)
struct message_reaction_add_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* reacting_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	user reacting_user = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild_member reacting_member = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString channel_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	channel* reacting_channel = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	emoji reacting_emoji = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString message_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString message_author_id = {};

};

/** @brief Guild members chunk */
USTRUCT(BlueprintType)
struct guild_members_chunk_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* adding = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild_member_map* members = nullptr;

};

/** @brief Message reaction remove */
USTRUCT(BlueprintType)
struct message_reaction_remove_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* reacting_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString reacting_user_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString channel_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	channel* reacting_channel = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	emoji reacting_emoji = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString message_id = {};

};

/** @brief Create guild */
USTRUCT(BlueprintType)
struct guild_create_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* created = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	presence_map presences = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	scheduled_event_map scheduled_events = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	stage_instance_map stage_instances = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	thread_map threads = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	sticker_map stickers = {};

};

/** @brief Create channel */
USTRUCT(BlueprintType)
struct channel_create_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* creating_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	channel* created = nullptr;

};

/** @brief Message remove emoji */
USTRUCT(BlueprintType)
struct message_reaction_remove_emoji_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* reacting_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString channel_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	channel* reacting_channel = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	emoji reacting_emoji = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString message_id = {};

};

/** @brief Message delete bulk */
USTRUCT(BlueprintType)
struct message_delete_bulk_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* deleting_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	user* deleting_user = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	channel* deleting_channel = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	TArray<FString> deleted = {};

};

/** @brief Guild role update */
USTRUCT(BlueprintType)
struct guild_role_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* updating_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	role* updated = nullptr;

};

/** @brief Guild role delete */
USTRUCT(BlueprintType)
struct guild_role_delete_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* deleting_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	role* deleted = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString role_id = {};

};

/** @brief Channel pins update */
USTRUCT(BlueprintType)
struct channel_pins_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* pin_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	channel* pin_channel = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FDateTime timestamp = 0;

};

/** @brief Message remove all reactions */
USTRUCT(BlueprintType)
struct message_reaction_remove_all_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* reacting_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString channel_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	channel* reacting_channel = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString message_id = {};

};

/** @brief Voice server update */
USTRUCT(BlueprintType)
struct voice_server_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString guild_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString token = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString endpoint = {};

};

/** @brief Guild emojis update */
USTRUCT(BlueprintType)
struct guild_emojis_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	TArray<FString> emojis = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* updating_guild = nullptr;

};

/**
 * @brief Presence update
 * 
 */
USTRUCT(BlueprintType)
struct presence_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	presence rich_presence = {};

};

/** @brief Webhooks update */
USTRUCT(BlueprintType)
struct webhooks_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* webhook_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	channel* webhook_channel = nullptr;

};

/** @brief Guild member add */
USTRUCT(BlueprintType)
struct guild_member_add_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* adding_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild_member added = {};

};

/** @brief Invite delete */
USTRUCT(BlueprintType)
struct invite_delete_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	invite deleted_invite = {};

};

/** @brief Guild update */
USTRUCT(BlueprintType)
struct guild_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* updated = nullptr;

};

/** @brief Guild integrations update */
USTRUCT(BlueprintType)
struct guild_integrations_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* updating_guild = nullptr;

};

/** @brief Guild member update */
USTRUCT(BlueprintType)
struct guild_member_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* updating_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild_member updated = {};

};

/** @brief Invite create */
USTRUCT(BlueprintType)
struct invite_create_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	invite created_invite = {};

};

/** @brief Message update */
USTRUCT(BlueprintType)
struct message_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	message msg = {};

};

/** @brief User update */
USTRUCT(BlueprintType)
struct user_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	user updated = {};

};

/** @brief Create message */
USTRUCT(BlueprintType)
struct message_create_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	message msg = {};

};

/** @brief Guild audit log entry create */
USTRUCT(BlueprintType)
struct guild_audit_log_entry_create_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	audit_entry entry = {};

};

/** @brief Guild ban add */
USTRUCT(BlueprintType)
struct guild_ban_add_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* banning_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	user banned = {};

};

/** @brief Guild ban remove */
USTRUCT(BlueprintType)
struct guild_ban_remove_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* unbanning_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	user unbanned = {};

};

/** @brief Integration create */
USTRUCT(BlueprintType)
struct integration_create_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	integration created_integration = {};

};

/** @brief Integration update */
USTRUCT(BlueprintType)
struct integration_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	integration updated_integration = {};

};

/** @brief Integration delete */
USTRUCT(BlueprintType)
struct integration_delete_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	integration deleted_integration = {};

};

/** @brief Thread Create*/
USTRUCT(BlueprintType)
struct thread_create_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* creating_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	thread created = {};

};

/** @brief Thread Update
*/
USTRUCT(BlueprintType)
struct thread_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* updating_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	thread updated = {};

};

/** @brief Thread Delete
 */
USTRUCT(BlueprintType)
struct thread_delete_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* deleting_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	thread deleted = {};

};

/** @brief Thread List Sync
 */
USTRUCT(BlueprintType)
struct thread_list_sync_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* updating_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	TArray<thread> threads = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	TArray<thread_member> members = {};

};

/** @brief Thread Member Update
 */
USTRUCT(BlueprintType)
struct thread_member_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	thread_member updated = {};

};

/** @brief Thread Members Update
 */
USTRUCT(BlueprintType)
struct thread_members_update_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString thread_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	guild* updating_guild = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	int member_count = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	TArray<thread_member> added = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	TArray<FString> removed_ids = {};

};

/**
 * @brief voice buffer send
 * @warning The shard in `from` will ALWAYS be null.
 */
USTRUCT(BlueprintType)
struct voice_buffer_send_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	class discord_voice_client* voice_client = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	int buffer_size = 0;

};

/** @brief voice user talking */
USTRUCT(BlueprintType)
struct voice_user_talking_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	class discord_voice_client* voice_client = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString user_id = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	int talking_flags = 0;

};

/** @brief voice user talking */
USTRUCT(BlueprintType)
struct voice_ready_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	discord_voice_client* voice_client = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString voice_channel_id = {};

};

/** @brief voice receive packet */
USTRUCT(BlueprintType)
struct voice_receive_t : public event_dispatch_t {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	friend class discord_voice_client;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	discord_voice_client* voice_client = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	int* audio = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	size_t audio_size = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	std::basic_string<int> audio_data = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Events")
	FString user_id = {};

};

/** @brief voice client speaking event */
USTRUCT(BlueprintType)
struct voice_client_speaking_t : public event_dispatch_t {
	GENERATED_BODY()

};

/** @brief voice client disconnect event */
USTRUCT(BlueprintType)
struct voice_client_disconnect_t : public event_dispatch_t {
	GENERATED_BODY()

};

/** @brief Delete stage instance */
USTRUCT(BlueprintType)
struct entitlement_create_t : public event_dispatch_t {
	GENERATED_BODY()

};

/** @brief Delete stage instance */
USTRUCT(BlueprintType)
struct entitlement_update_t : public event_dispatch_t {
	GENERATED_BODY()

};

/** @brief Delete stage instance */
USTRUCT(BlueprintType)
struct entitlement_delete_t : public event_dispatch_t {
	GENERATED_BODY()

};

