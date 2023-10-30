#pragma once
 
UENUM(BlueprintType)
enum team_member_status : uint8 {
	tms_invited = 1,
	tms_accepted = 2
};

UENUM(BlueprintType)
enum application_flags : uint32 {
	apf_application_automod_rule_create_badge = (1 << 6),
	apf_gateway_presence = (1 << 12),
	apf_gateway_presence_limited = (1 << 13),
	apf_gateway_guild_members = (1 << 14),
	apf_gateway_guild_members_limited = (1 << 15),
	apf_verification_pending_guild_limit = (1 << 16),
	apf_embedded = (1 << 17),
	apf_gateway_message_content = (1 << 18),
	apf_gateway_message_content_limited = (1 << 19),
	apf_application_command_badge = (1 << 23)
};

UENUM(BlueprintType)
enum team_member_role_t : uint8 {
	tmr_owner,	//!< Team owner
	tmr_admin,	//!< Team admin
	tmr_developer,	//!< Developer
	tmr_readonly,	//!< Read-Only
};

USTRUCT(BlueprintType)
struct team_member {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|team_member")
	team_member_status	membership_state;	//!< the user's membership state on the team

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|team_member")
	FString		permissions;		//!< will always be [""]

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|team_member")
	FString		team_id;		//!< the id of the parent team of which they are a member

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|team_member")
	user			member_user;		//!< the avatar, discriminator, id, and username of the user

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|team_member")
	team_member_role_t	member_role;		//!< the role of the user

};

USTRUCT(BlueprintType)
struct app_team {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|app_team")
	FString			id;		//!< the unique id of the team

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|app_team")
	TArray<team_member>	members;	//!< the members of the team

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|app_team")
	FString			name;		//!< the name of the team

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|app_team")
	FString			owner_user_id;	//!< the user id of the current team owner

};

USTRUCT(BlueprintType)
struct application {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	FString		name;				//!< the name of the app

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	FString		description;			//!< the description of the app

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	TArray<FString> rpc_origins;			//!< Optional: an array of rpc origin urls, if rpc is enabled

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	bool			bot_public;			//!< when false only app owner can join the app's bot to guilds

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	bool			bot_require_code_grant;		//!< when true the app's bot will only join upon completion of the full oauth2 code grant flow

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	user			bot;				//!< Optional: Partial user object for the bot user associated with the app.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	FString		terms_of_service_url;		//!< Optional: the url of the app's terms of service

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	FString		privacy_policy_url;		//!< Optional: the url of the app's privacy policy

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	user			owner;				//!< Optional: partial user object containing info on the owner of the application

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	FString		summary;			//!< if this application is a game sold on Discord, this field will be the summary field for the store page of its primary sku @deprecated Will be removed in v11

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	FString		verify_key;			//!< the hex encoded key for verification in interactions and the GameSDK's GetTicket

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	FString		guild_id;			//!< Optional: if this application is a game sold on Discord, this field will be the guild to which it has been linked

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	guild			guild_obj;			//!< Optional: Partial object of the associated guild

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	FString		primary_sku_id;			//!< Optional: if this application is a game sold on Discord, this field will be the id of the "Game SKU" that is created, if exists

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	FString		slug;				//!< Optional: if this application is a game sold on Discord, this field will be the URL slug that links to the store page

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	FString	cover_image;			//!< Optional: the application's default rich presence invite cover image hash

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	int64		flags;				//!< Optional: the application's public flags

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	int64		approximate_guild_count;	//!< Optional: Approximate count of guilds the app has been added to

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	TArray<FString> redirect_uris;			//!< Optional: Array of redirect URIs for the app

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	FString		interactions_endpoint_url;	//!< Optional: Interactions endpoint URL for the app

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	FString 	role_connections_verification_url;	//!< The application's role connection verification entry point, which when configured will render the app as a verification method in the guild role verification configuration

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	TArray<FString> tags;				//!< Up to 5 tags describing the content and functionality of the application

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	application_install_params install_params;		//!< Settings for the application's default in-app authorization link, if enabled

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	FString 		custom_install_url;		//!< The application's default custom authorization link, if enabled

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	int			discoverability_state;		//!< @warning This variable is not documented by discord, we have no idea what it means and how it works. Use at your own risk.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	int64 		discovery_eligibility_flags;	//!< @warning This variable is not documented by discord, we have no idea what it means and how it works. Use at your own risk.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	int			explicit_content_filter;	//!< @warning This variable is not documented by discord, we have no idea what it means and how it works. Use at your own risk.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	int			creator_monetization_state;	//!< @warning This variable is not documented by discord, we have no idea what it means and how it works. Use at your own risk.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	bool			integration_public;		//!< @warning This variable is not documented by discord, we have no idea what it means and how it works. Use at your own risk.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	bool			integration_require_code_grant;	//!< @warning This variable is not documented by discord, we have no idea what it means and how it works. Use at your own risk.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	TArray<FString> interactions_event_types;	//!< @warning This variable is not documented by discord, we have no idea what it means and how it works. Use at your own risk.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	int			interactions_version;		//!< @warning This variable is not documented by discord, we have no idea what it means and how it works. Use at your own risk.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	bool			is_monetized;			//!< @warning This variable is not documented by discord, we have no idea what it means and how it works. Use at your own risk.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	int64		monetization_eligibility_flags;	//!< @warning This variable is not documented by discord, we have no idea what it means and how it works. Use at your own risk.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	int			monetization_state;		//!< @warning This variable is not documented by discord, we have no idea what it means and how it works. Use at your own risk.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	bool			hook;				//!< @warning This variable is not documented by discord, we have no idea what it means and how it works. Use at your own risk.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	int			rpc_application_state;		//!< @warning This variable is not documented by discord, we have no idea what it means and how it works. Use at your own risk.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	int			store_application_state;	//!< @warning This variable is not documented by discord, we have no idea what it means and how it works. Use at your own risk.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application")
	int			verification_state;		//!< @warning This variable is not documented by discord, we have no idea what it means and how it works. Use at your own risk.

};

