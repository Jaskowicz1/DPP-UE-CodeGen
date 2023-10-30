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
 * @brief Types of startup for cluster::start()
 */
UENUM(BlueprintType)
enum start_type : bool {
	st_wait = false,

	st_return = true,
};

/** @brief The cluster class represents a group of shards and a command queue for sending and
 * receiving commands from discord via HTTP. You should usually instantiate a cluster object
 * at the very least to make use of the library.
 */
USTRUCT(BlueprintType)
struct cluster {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	FString token;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	FDateTime last_identify;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	int64 intents;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	int64 numshards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	int64 cluster_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	int64 maxclusters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	double rest_ping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	user me;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	cache_policy_t cache_policy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	websocket_protocol_t ws_mode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	std::condition_variable terminating;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<voice_state_update_t> on_voice_state_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<voice_client_disconnect_t> on_voice_client_disconnect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<voice_client_speaking_t> on_voice_client_speaking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<log_t> on_log;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_join_request_delete_t> on_guild_join_request_delete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<interaction_create_t> on_interaction_create;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<slashcommand_t> on_slashcommand;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<button_click_t> on_button_click;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<autocomplete_t> on_autocomplete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<select_click_t> on_select_click;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<message_context_menu_t> on_message_context_menu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<user_context_menu_t> on_user_context_menu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<form_submit_t> on_form_submit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_delete_t> on_guild_delete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<channel_delete_t> on_channel_delete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<channel_update_t> on_channel_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<ready_t> on_ready;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<message_delete_t> on_message_delete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_member_remove_t> on_guild_member_remove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<resumed_t> on_resumed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_role_create_t> on_guild_role_create;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<typing_start_t> on_typing_start;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<message_reaction_add_t> on_message_reaction_add;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_members_chunk_t> on_guild_members_chunk;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<message_reaction_remove_t> on_message_reaction_remove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_create_t> on_guild_create;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<channel_create_t> on_channel_create;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<message_reaction_remove_emoji_t> on_message_reaction_remove_emoji;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<message_delete_bulk_t> on_message_delete_bulk;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_role_update_t> on_guild_role_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_role_delete_t> on_guild_role_delete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<channel_pins_update_t> on_channel_pins_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<message_reaction_remove_all_t> on_message_reaction_remove_all;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<voice_server_update_t> on_voice_server_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_emojis_update_t> on_guild_emojis_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_stickers_update_t> on_guild_stickers_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<presence_update_t> on_presence_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<webhooks_update_t> on_webhooks_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<automod_rule_create_t> on_automod_rule_create;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<automod_rule_update_t> on_automod_rule_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<automod_rule_delete_t> on_automod_rule_delete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<automod_rule_execute_t> on_automod_rule_execute;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_member_add_t> on_guild_member_add;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<invite_delete_t> on_invite_delete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_update_t> on_guild_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_integrations_update_t> on_guild_integrations_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_member_update_t> on_guild_member_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<invite_create_t> on_invite_create;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<message_update_t> on_message_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<user_update_t> on_user_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<message_create_t> on_message_create;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_audit_log_entry_create_t> on_guild_audit_log_entry_create;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_ban_add_t> on_guild_ban_add;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_ban_remove_t> on_guild_ban_remove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<integration_create_t> on_integration_create;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<integration_update_t> on_integration_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<integration_delete_t> on_integration_delete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<thread_create_t> on_thread_create;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<thread_update_t> on_thread_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<thread_delete_t> on_thread_delete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<thread_list_sync_t> on_thread_list_sync;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<thread_member_update_t> on_thread_member_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<thread_members_update_t> on_thread_members_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_scheduled_event_create_t> on_guild_scheduled_event_create;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_scheduled_event_update_t> on_guild_scheduled_event_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_scheduled_event_delete_t> on_guild_scheduled_event_delete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_scheduled_event_user_add_t> on_guild_scheduled_event_user_add;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<guild_scheduled_event_user_remove_t> on_guild_scheduled_event_user_remove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<voice_buffer_send_t> on_voice_buffer_send;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<voice_user_talking_t> on_voice_user_talking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<voice_ready_t> on_voice_ready;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<voice_receive_t> on_voice_receive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<voice_receive_t> on_voice_receive_combined;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<voice_track_marker_t> on_voice_track_marker;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<stage_instance_create_t> on_stage_instance_create;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<stage_instance_update_t> on_stage_instance_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<stage_instance_delete_t> on_stage_instance_delete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<entitlement_create_t> on_entitlement_create;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<entitlement_update_t> on_entitlement_update;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Cluster")
	event_router_t<entitlement_delete_t> on_entitlement_delete;

};

