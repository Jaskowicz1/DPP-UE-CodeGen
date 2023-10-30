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
/** Various flags related to role */
UENUM(BlueprintType)
enum role_flags : uint8 {
	r_hoist =		0b00000001, //!< Hoisted role (if the role is pinned in the user listing)
	r_managed =		0b00000010, //!< Managed role (introduced by a bot or application)
	r_mentionable =		0b00000100, //!< Whether this role is mentionable with a ping
	r_premium_subscriber =	0b00001000, //!< Whether this is the guild's booster role
	r_available_for_purchase = 0b00010000, //!< Whether the role is available for purchase
	r_guild_connections = 0b00100000, //!< Whether the role is a guild's linked role
	r_in_prompt			= 0b01000000, //!< Whether the role can be selected by members in an onboarding prompt
};

/**
 * @brief Represents a role within a guild.
 * Roles are combined via logical OR of the permission bitmasks, then channel-specific overrides
 * can be applied on top, deny types apply a logic NOT to the bit mask, and allows apply a logical OR.
 * @note Every guild has at least one role, called the 'everyone' role, which always has the same role
 * ID as the guild's ID. This is the base permission set applied to all users where no other role or override
 * applies, and is the starting value of the bit mask looped through to calculate channel permissions.
 */
USTRUCT(BlueprintType)
struct role {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
	FString name{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
	FString guild_id{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
	int64 colour{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
	int position{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
	permission permissions{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
	int flags{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
	FString integration_id{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
	FString bot_id{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
	FString subscription_listing_id{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
	FString unicode_emoji{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
	utility::icon icon{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
	{

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
		return lhs.position < rhs.position;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
	{

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
		return lhs.position > rhs.position;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
	{

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
		return this->position == other.position;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
	{

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
		return this->position != other.position;

};

/**
 * @brief Application Role Connection Metadata Type
 *
 * @note Each metadata type offers a comparison operation that allows guilds to configure role requirements based on metadata values stored by the bot. Bots specify a `metadata value` for each user and guilds specify the required `guild's configured value` within the guild role settings.
 */
UENUM(BlueprintType)
enum application_role_connection_metadata_type : uint8 {
	rc_integer_less_than_or_equal = 1, //!< The metadata value (integer) is less than or equal to the guild's configured value (integer)
	rc_integer_greater_than_or_equal = 2, //!< The metadata value (integer) is greater than or equal to the guild's configured value (integer)
	rc_integer_equal = 3, //!< The metadata value (integer) is equal to the guild's configured value (integer)
	rc_integer_not_equal = 4, //!< The metadata value (integer) is not equal to the guild's configured value (integer)
	rc_datetime_less_than_or_equal = 5, //!< The metadata value (ISO8601 string) is less than or equal to the guild's configured value (integer; days before current date)
	rc_datetime_greater_than_or_equal = 6, //!< The metadata value (ISO8601 string) is greater than or equal to the guild's configured value (integer; days before current date)
	rc_boolean_equal = 7, //!< The metadata value (integer) is equal to the guild's configured value (integer; 1)
	rc_boolean_not_equal = 8, //!< The metadata value (integer) is not equal to the guild's configured value (integer; 1)
};

/**
 * @brief Application Role Connection Metadata. Represents a role connection metadata for an application
 */
USTRUCT(BlueprintType)
struct application_role_connection_metadata {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Application_role_connection_metadata")
	application_role_connection_metadata_type type; //!< Type of metadata value

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Application_role_connection_metadata")
	TMap<FString, FString> name_localizations; //!< Translations of the name

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Application_role_connection_metadata")
	TMap<FString, FString> description_localizations; //!< Translations of the description

};

/**
 * @brief The application role connection that an application has attached to a user.
 */
USTRUCT(BlueprintType)
struct application_role_connection {
	GENERATED_BODY()

};

/** A group of roles */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Role")
TMap<FString, role> role_map;

/** A group of application_role_connection_metadata objects */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Application_role_connection_metadata_list")
TArray<application_role_connection_metadata> application_role_connection_metadata_list;

