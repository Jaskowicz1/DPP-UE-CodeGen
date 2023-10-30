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
 * @brief Discord limits the maximum number of replies to an autocomplete interaction to 25.
 * This value represents that maximum. interaction_response::add_autocomplete_choice does not allow
 * adding more than this number of elements to the vector.
 */
#ifndef AUTOCOMPLETE_MAX_CHOICES
	#define AUTOCOMPLETE_MAX_CHOICES 25
#endif
/**
 * @brief Represents command option types.
 * These are the possible parameter value types.
 */
UENUM(BlueprintType)
enum command_option_type : uint8 {
	co_sub_command = 1,
	co_sub_command_group = 2,
	co_string = 3,
	co_integer = 4,
	co_boolean = 5,
	co_user = 6,
	co_channel = 7,
	co_role = 8,
	co_mentionable = 9,
	co_number = 10,
	co_attachment = 11,
};

/**
 * @brief This type is a variant that can hold any of the potential
 * native data types represented by the enum command_option_type.
 * It is used in interactions.
 * 
 * std::monostate indicates an invalid parameter value, e.g. an unfilled optional parameter.
 * std::int64_t will be for all integer options, double for decimal numbers and FString for anything ID related.
 *
 * You can retrieve them with std::get().
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_value")
TVariant<FString, int64_t, bool, FString, double> command_value;

/**
 * @brief This struct represents choices in a multiple choice option
 * for a command parameter.
 * It has both a string name, and a value parameter which is a variant,
 * meaning it can hold different potential types (see command_value)
 * that you can retrieve with std::get().
 */
USTRUCT(BlueprintType)
struct command_option_choice {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_option_choice")
	command_value value;	//!< Option value

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_option_choice")
	TMap<FString, FString> name_localizations; //!< Localisations of command option name

};

/**
 * @brief helper function to serialize a command_option_choice to json
 *
 * @see https://github.com/nlohmann/json#arbitrary-types-conversions
 *
 * @param j output json object
 * @param choice command_option_choice to be serialized
 */
/**
 * @brief A minimum or maximum value/length for co_number, co_integer and co_string types of a command_option.
 * The `int64_t` is for the integer range or string length that can be entered. The `double` is for the decimal range that can be entered
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_option_range")
TVariant<int64_t, double> command_option_range;

/**
 * @brief Each command option is a command line parameter.
 * It can have a type (see command_option_type), a name,
 * a description, can be required or optional, and can have
 * zero or more choices (for multiple choice), plus options.
 * Adding options acts like sub-commands and can contain more
 * options.
 */
USTRUCT(BlueprintType)
struct command_option {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_option")
	bool required;                               //!< True if this is a mandatory parameter

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_option")
	bool focused;                                //!< True if the user is typing in this field, when sent via autocomplete

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_option")
	command_value value;                         //!< Set only by autocomplete went sent as part of an interaction

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_option")
	TArray<command_option_choice> choices;  //!< List of choices for multiple choice command

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_option")
	bool autocomplete;                           //!< True if this option supports auto completion

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_option")
	TArray<command_option> options;         //!< Sub-commands

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_option")
	TArray<channel_type> channel_types;     //!< Allowed channel types for channel FString id options

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_option")
	command_option_range min_value;              //!< Minimum value/length that can be entered, for co_number, co_integer and co_string types only

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_option")
	command_option_range max_value;              //!< Maximum value/length that can be entered, for co_number, co_integer and co_string types only

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_option")
	TMap<FString, FString> name_localizations; //!< Localisations of command name

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_option")
	TMap<FString, FString> description_localizations; //!< Localisations of command description

};

/**
 * @brief helper function to serialize a command_option to json
 *
 * @see https://github.com/nlohmann/json#arbitrary-types-conversions
 *
 * @param j output json object
 * @param opt command_option to be serialized
 */
/**
 * @brief Response types when responding to an interaction within on_interaction_create.
 */
UENUM(BlueprintType)
enum interaction_response_type : uint8 {
	ir_pong = 1,
	ir_channel_message_with_source = 4,
	ir_deferred_channel_message_with_source = 5,

	ir_deferred_update_message = 6,

	ir_update_message = 7,

	ir_autocomplete_reply = 8,

	ir_modal_dialog = 9,

	ir_premium_required = 10,
};

/**
 * @brief A response to an interaction, used to reply to a command and initiate
 * a message, which can be hidden from others (ephemeral) or visible to all.
 *
 * The interaction_response object wraps a message object. To set the
 * message as 'ephemeral' (e.g. only the command issuer can see it) you should
 * add the m_ephemeral flag to the message::flags field. e.g.:
 *
 * `mymessage.flags |= m_ephemeral;`
 */
USTRUCT(BlueprintType)
struct interaction_response {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction_response")
	interaction_response_type type{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction_response")
	message msg{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction_response")
	TArray<command_option_choice> autocomplete_choices{};

};

/**
 * @brief Represents a modal dialog box response to an interaction.
 * 
 * A dialog box is a modal popup which appears to the user instead of a message. One or more
 * components are displayed on a form (the same component structure as within a message).
 * When the user submits the form an on_form_submit event is dispatched to any listeners.
 */
USTRUCT(BlueprintType)
struct interaction_modal_response {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction_modal_response")
	FString custom_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction_modal_response")
	FString title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction_modal_response")
	TArray<TArray<component>> components;

};

/**
 * @brief Resolved FString ids to users, guild members, roles and channels. You can use the `interaction::get_resolved_*` methods to easily get a resolved set
 */
USTRUCT(BlueprintType)
struct command_resolved {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_resolved")
	TMap<FString, user> users;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_resolved")
	TMap<FString, guild_member> members;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_resolved")
	TMap<FString, permission> member_permissions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_resolved")
	TMap<FString, role> roles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_resolved")
	TMap<FString, channel> channels;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_resolved")
	TMap<FString, message> messages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_resolved")
	TMap<FString, attachment> attachments;

};

/**
 * @brief Values in the command interaction.
 * These are the values specified by the user when actually issuing
 * the command on a channel or in DM.
 */
USTRUCT(BlueprintType)
struct command_data_option {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_data_option")
	FString name;                          //!< the name of the parameter

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_data_option")
	command_option_type type;                  //!< value of ApplicationCommandOptionType

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_data_option")
	command_value value;                       //!< Optional: the value of the pair

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_data_option")
	TArray<command_data_option> options;  //!< Optional: present if this option is a group or subcommand

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_data_option")
	bool focused;                              //!< Optional: true if this option is the currently focused option for autocomplete

};

/**
 * @brief helper function to deserialize a command_data_option from json
 *
 * @see https://github.com/nlohmann/json#arbitrary-types-conversions
 *
 * @param j output json object
 * @param cdo command_data_option to be deserialized
 */
/** Types of interaction in the interaction class
 */
UENUM(BlueprintType)
enum interaction_type : uint8 {
	it_ping = 1,			//!< ping
	it_application_command = 2,	//!< application command (slash command)
	it_component_button = 3,	//!< button click or select menu chosen (component interaction)
	it_autocomplete = 4,		//!< Autocomplete interaction
	it_modal_submit = 5,		//!< Modal form submission
};

/**
 * @brief Right-click context menu types
 */
UENUM(BlueprintType)
enum slashcommand_contextmenu_type : uint8 {
    ctxm_none = 0,        //!< Undefined context menu type
    ctxm_chat_input = 1,    //!< DEFAULT, these are the slash commands you're used to
    ctxm_user = 2,        //!< Add command to user context menu
    ctxm_message = 3    //!< Add command to message context menu
};

/**
 * @brief Details of a command within an interaction.
 * This subobject represents the application command associated
 * with the interaction.
 */
USTRUCT(BlueprintType)
struct command_interaction {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_interaction")
	FString id;                              //!< the ID of the invoked command

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_interaction")
	FString name;                          //!< the name of the invoked command

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_interaction")
	TArray<command_data_option> options;  //!< Optional: the params + values from the user

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_interaction")
	slashcommand_contextmenu_type type;        //!< type of the command interaction

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_interaction")
	FString target_id;                  //!< Non-zero target ID for context menu actions. e.g. user id or message id whom clicked or tapped with the context menu https://discord.com/developers/docs/interactions/application-commands#user-commands

};

/**
 * @brief helper function to deserialize a command_interaction from json
 *
 * @see https://github.com/nlohmann/json#arbitrary-types-conversions
 *
 * @param j output json object
 * @param ci command_interaction to be deserialized
 */
/**
 * @brief A button click for a button component
 */
USTRUCT(BlueprintType)
struct component_interaction {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Component_interaction")
	int component_type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Component_interaction")
	FString custom_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Component_interaction")
	TArray<FString> values;

};

/**
 * @brief An auto complete interaction
 */
USTRUCT(BlueprintType)
struct autocomplete_interaction {
	GENERATED_BODY()

};

/**
 * @brief helper function to deserialize a component_interaction from json
 *
 * @see https://github.com/nlohmann/json#arbitrary-types-conversions
 *
 * @param j output json object
 * @param bi button_interaction to be deserialized
 */
/**
 * @brief helper function to deserialize an autocomplete_interaction from json
 *
 * @see https://github.com/nlohmann/json#arbitrary-types-conversions
 *
 * @param j output json object
 * @param ai autocomplete_interaction to be deserialized
 */
/**
 * @brief An interaction represents a user running a command and arrives
 * via the cluster::on_interaction_create event. This is further split
 * into the events on_form_submit, on_slashcommand, on_user_context_menu,
 * on_button_click, on_select_menu, etc.
 */
USTRUCT(BlueprintType)
struct interaction {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction")
	FString application_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction")
	int	type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction")
	TVariant<command_interaction, component_interaction, autocomplete_interaction> data;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction")
	FString guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction")
	FString channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction")
	channel channel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction")
	FString message_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction")
	permission app_permissions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction")
	message msg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction")
	guild_member member;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction")
	user usr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction")
	FString token;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction")
	int version;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction")
	command_resolved resolved;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction")
	FString locale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction")
	FString guild_locale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction")
	cache_policy_t cache_policy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Interaction")
	TArray<entitlement> entitlements;

};

/**
 * @brief helper function to deserialize an interaction from json
 *
 * @see https://github.com/nlohmann/json#arbitrary-types-conversions
 *
 * @param j output json object
 * @param i interaction to be deserialized
 */
/**
 * @brief type of permission in the command_permission class
 */
UENUM(BlueprintType)
enum command_permission_type : uint8 {
	cpt_role = 1,
	cpt_user = 2,
};

/**
 * @brief Application command permissions allow you to enable or
 * disable commands for specific users or roles within a guild
 */
USTRUCT(BlueprintType)
struct command_permission {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_permission")
	FString id;                  //!< the ID of the role or user

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_permission")
	command_permission_type type;  //!< the type of permission

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Command_permission")
	bool permission;               //!< true to allow, false, to disallow

};

/**
 * @brief helper function to serialize a command_permission to json
 *
 * @see https://github.com/nlohmann/json#arbitrary-types-conversions
 *
 * @param j output json object
 * @param cp command_permission to be serialized
 */
/**
 * @brief Returned when fetching the permissions for a command in a guild.
 */
USTRUCT(BlueprintType)
struct guild_command_permissions {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild_command_permissions")
	FString id;                                 //!< the id of the command

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild_command_permissions")
	FString application_id;                     //!< the id of the application the command belongs to

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild_command_permissions")
	FString guild_id;                           //!< the id of the guild

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild_command_permissions")
	TArray<command_permission> permissions;  //!< the permissions for the command in the guild

};

/**
 * @brief helper function to serialize a guild_command_permissions to json
 *
 * @see https://github.com/nlohmann/json#arbitrary-types-conversions
 *
 * @param j output json object
 * @param gcp guild_command_permissions to be serialized
 */
/**
 * @brief Represents an application command, created by your bot
 * either globally, or on a guild.
 */
USTRUCT(BlueprintType)
struct slashcommand {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Slashcommand")
	FString application_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Slashcommand")
	slashcommand_contextmenu_type type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Slashcommand")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Slashcommand")
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Slashcommand")
	TArray<command_option> options;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Slashcommand")
	bool default_permission;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Slashcommand")
	TArray<command_permission> permissions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Slashcommand")
	FString version;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Slashcommand")
	TMap<FString, FString> name_localizations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Slashcommand")
	TMap<FString, FString> description_localizations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Slashcommand")
	permission default_member_permissions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Slashcommand")
	bool dm_permission;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Slashcommand")
	bool nsfw;

};

/**
 * @brief helper function to serialize a slashcommand to json
 *
 * @see https://github.com/nlohmann/json#arbitrary-types-conversions
 *
 * @param j output json object
 * @param cmd slashcommand to be serialized
 */
/**
 * @brief A group of application slash commands
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Slashcommand")
TMap<FString, slashcommand> slashcommand_map;

/**
 * @brief A group of guild command permissions
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Guild_command_permissions")
TMap<FString, guild_command_permissions> guild_command_permissions_map;

