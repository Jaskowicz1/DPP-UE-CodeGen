#pragma once
 
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

UENUM(BlueprintType)
enum interaction_type : uint8 {
	it_ping = 1,			//!< ping
	it_application_command = 2,	//!< application command (slash command)
	it_component_button = 3,	//!< button click or select menu chosen (component interaction)
	it_autocomplete = 4,		//!< Autocomplete interaction
	it_modal_submit = 5,		//!< Modal form submission
};

UENUM(BlueprintType)
enum slashcommand_contextmenu_type : uint8 {
	ctxm_none = 0,        //!< Undefined context menu type
	ctxm_chat_input = 1,    //!< DEFAULT, these are the slash commands you're used to
	ctxm_user = 2,        //!< Add command to user context menu
	ctxm_message = 3    //!< Add command to message context menu
};

USTRUCT(BlueprintType)
struct interaction {
	GENERATED_BODY()

};

UENUM(BlueprintType)
enum command_permission_type : uint8 {
	cpt_role = 1,
	cpt_user = 2,
};

USTRUCT(BlueprintType)
struct command_permission {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|command_permission")
	FString id;                  //!< the ID of the role or user

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|command_permission")
	command_permission_type type;  //!< the type of permission

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|command_permission")
	bool permission;               //!< true to allow, false, to disallow

};

USTRUCT(BlueprintType)
struct guild_command_permissions {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild_command_permissions")
	FString id;                                 //!< the id of the command

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild_command_permissions")
	FString application_id;                     //!< the id of the application the command belongs to

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild_command_permissions")
	FString guild_id;                           //!< the id of the guild

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|guild_command_permissions")
	TArray<command_permission> permissions;  //!< the permissions for the command in the guild

};

USTRUCT(BlueprintType)
struct slashcommand {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|slashcommand")
	FString application_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|slashcommand")
	slashcommand_contextmenu_type type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|slashcommand")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|slashcommand")
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|slashcommand")
	TArray<command_option> options;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|slashcommand")
	bool default_permission;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|slashcommand")
	TArray<command_permission> permissions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|slashcommand")
	FString version;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|slashcommand")
	std::map<FString, FString> name_localizations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|slashcommand")
	std::map<FString, FString> description_localizations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|slashcommand")
	permission default_member_permissions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|slashcommand")
	bool dm_permission;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|slashcommand")
	bool nsfw;

};

