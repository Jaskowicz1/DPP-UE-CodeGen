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
 * @brief Integration types
 */
UENUM(BlueprintType)
enum integration_type : uint8 {
	i_twitch,
	i_youtube,
	i_discord,
	i_guild_subscription,
};

/**
 * @brief Integration flags
 */
UENUM(BlueprintType)
enum integration_flags : uint8 {
	if_enabled 	=	0b00000001,		//!< is this integration enabled
	if_syncing 	=	0b00000010,		//!< is this integration syncing @warning This is not provided for discord bot integrations.
	if_emoticons 	=	0b00000100,		//!< whether emoticons should be synced for this integration (twitch only currently) @warning This is not provided for discord bot integrations.
	if_revoked 	=	0b00001000,		//!< has this integration been revoked @warning This is not provided for discord bot integrations.
	if_expire_kick 	= 	0b00010000,		//!< kick user when their subscription expires, otherwise only remove the role that is specified by `role_id`. @warning This is not provided for discord bot integrations.
};

/**
 * @brief An application that has been integrated
 */
USTRUCT(BlueprintType)
struct integration_app {
	GENERATED_BODY()

};

/**
 * @brief The account information for an integration.
 */
USTRUCT(BlueprintType)
struct integration_account {
	GENERATED_BODY()

};

/**
 * @brief Represents an integration on a guild, e.g. a connection to twitch.
 */
USTRUCT(BlueprintType)
struct integration {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Integration")
	FString 			name;			//!< integration name

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Integration")
	int 			flags;			//!< integration flags from integration_flags

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Integration")
	FString 			role_id;		//!< id that this integration uses for "subscribers" @warning This is not provided for discord bot integrations.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Integration")
	user 				user_obj;		//!< user for this integration

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Integration")
	integration_account		account;		//!< integration account information

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Integration")
	FDateTime 				synced_at;		//!< when this integration was last synced @warning This is not provided for discord bot integrations.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Integration")
	int64 			subscriber_count;	//!< how many subscribers this integration has @warning This is not provided for discord bot integrations.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Integration")
	integration_app 		app;			//!< the bot/OAuth2 application for discord integrations

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Integration")
	TArray<FString> 	scopes;			//!< the scopes the application has been authorized for

};

/**
 * @brief The connection object that the user has attached.
 */
USTRUCT(BlueprintType)
struct connection {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Connection")
	FString			id;		//!< id of the connection account

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Connection")
	FString			name;		//!< the username of the connection account

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Connection")
	bool				revoked;	//!< Optional: whether the connection is revoked

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Connection")
	TArray<integration>	integrations;	//!< Optional: an array of partial server integrations

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Connection")
	bool				verified;	//!< whether the connection is verified

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Connection")
	bool				friend_sync;	//!< whether friend sync is enabled for this connection

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Connection")
	bool				show_activity;	//!< whether activities related to this connection will be shown in presence updates

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Connection")
	bool				two_way_link;	//!< Whether this connection has a corresponding third party OAuth2 token

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Connection")
	bool				visible;	//!< visibility of this connection

};

/** A group of integrations */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Integration")
TMap<FString, integration> integration_map;

/** A group of connections */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Connection")
TMap<FString, connection> connection_map;

