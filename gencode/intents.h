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
 * @brief intents are a bitmask of allowed events on your websocket.
 * 
 * Some of these are known as Privileged intents (GUILD_MEMBERS and GUILD_PRESENCES)
 * and require verification of a bot over 100 servers by discord via submission of
 * your real life ID.
 */
UENUM(BlueprintType)
enum intents : uint8 {
	i_guilds			= (1 << 0),
	i_guild_members			= (1 << 1),
	i_guild_bans			= (1 << 2),
	i_guild_emojis			= (1 << 3),
	i_guild_integrations		= (1 << 4),
	i_guild_webhooks		= (1 << 5),
	i_guild_invites			= (1 << 6),
	i_guild_voice_states		= (1 << 7),
	i_guild_presences		= (1 << 8),
	i_guild_messages		= (1 << 9),
	i_guild_message_reactions	= (1 << 10),
	i_guild_message_typing		= (1 << 11),
	i_direct_messages		= (1 << 12),
	i_direct_message_reactions	= (1 << 13),
	i_direct_message_typing		= (1 << 14),
	i_message_content		= (1 << 15),
	i_guild_scheduled_events	= (1 << 16),
	i_auto_moderation_configuration	= (1 << 20),
	i_auto_moderation_execution	= (1 << 21),
	i_default_intents		= i_guilds | i_guild_bans | i_guild_emojis | i_guild_integrations |
					i_guild_webhooks | i_guild_invites | i_guild_voice_states |
					i_guild_messages | i_guild_message_reactions | i_guild_message_typing |
					i_direct_messages | i_direct_message_typing | i_direct_message_reactions |
					i_guild_scheduled_events | i_auto_moderation_configuration |
					i_auto_moderation_execution, 
	i_privileged_intents		= i_guild_members | i_guild_presences | i_message_content,
	i_all_intents			= i_default_intents | i_privileged_intents,
        i_unverified_default_intents    = i_default_intents | i_message_content
};

