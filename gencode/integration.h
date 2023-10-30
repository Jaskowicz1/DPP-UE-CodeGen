#pragma once
 
UENUM(BlueprintType)
enum integration_type : uint8 {
	i_twitch,
	i_youtube,
	i_discord,
	i_guild_subscription,
};

UENUM(BlueprintType)
enum integration_flags : uint8 {
	if_enabled 	=	0b00000001,		//!< is this integration enabled
	if_syncing 	=	0b00000010,		//!< is this integration syncing @warning This is not provided for discord bot integrations.
	if_emoticons 	=	0b00000100,		//!< whether emoticons should be synced for this integration (twitch only currently) @warning This is not provided for discord bot integrations.
	if_revoked 	=	0b00001000,		//!< has this integration been revoked @warning This is not provided for discord bot integrations.
	if_expire_kick 	= 	0b00010000,		//!< kick user when their subscription expires, otherwise only remove the role that is specified by `role_id`. @warning This is not provided for discord bot integrations.
};

USTRUCT(BlueprintType)
struct integration {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|integration")
	FString 			name;			//!< integration name

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|integration")
	int 			flags;			//!< integration flags from dpp::integration_flags

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|integration")
	FString 			role_id;		//!< id that this integration uses for "subscribers" @warning This is not provided for discord bot integrations.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|integration")
	user 				user_obj;		//!< user for this integration

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|integration")
	integration_account		account;		//!< integration account information

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|integration")
	FDateTime 				synced_at;		//!< when this integration was last synced @warning This is not provided for discord bot integrations.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|integration")
	int64 			subscriber_count;	//!< how many subscribers this integration has @warning This is not provided for discord bot integrations.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|integration")
	integration_app 		app;			//!< the bot/OAuth2 application for discord integrations

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|integration")
	TArray<FString> 	scopes;			//!< the scopes the application has been authorized for

};

USTRUCT(BlueprintType)
struct connection {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|connection")
	FString			id;		//!< id of the connection account

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|connection")
	FString			name;		//!< the username of the connection account

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|connection")
	bool				revoked;	//!< Optional: whether the connection is revoked

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|connection")
	TArray<integration>	integrations;	//!< Optional: an array of partial server integrations

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|connection")
	bool				verified;	//!< whether the connection is verified

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|connection")
	bool				friend_sync;	//!< whether friend sync is enabled for this connection

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|connection")
	bool				show_activity;	//!< whether activities related to this connection will be shown in presence updates

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|connection")
	bool				two_way_link;	//!< Whether this connection has a corresponding third party OAuth2 token

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|connection")
	bool				visible;	//!< visibility of this connection

};

