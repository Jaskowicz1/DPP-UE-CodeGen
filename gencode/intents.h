#pragma once
 
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
	i_default_intents		= dpp::i_guilds | dpp::i_guild_bans | dpp::i_guild_emojis | dpp::i_guild_integrations |
					dpp::i_guild_webhooks | dpp::i_guild_invites | dpp::i_guild_voice_states |
					dpp::i_guild_messages | dpp::i_guild_message_reactions | dpp::i_guild_message_typing |
					dpp::i_direct_messages | dpp::i_direct_message_typing | dpp::i_direct_message_reactions |
					dpp::i_guild_scheduled_events | dpp::i_auto_moderation_configuration |
					dpp::i_auto_moderation_execution, 
	i_privileged_intents		= dpp::i_guild_members | dpp::i_guild_presences | dpp::i_message_content,
	i_all_intents			= dpp::i_default_intents | dpp::i_privileged_intents,
        i_unverified_default_intents    = dpp::i_default_intents | dpp::i_message_content
};

