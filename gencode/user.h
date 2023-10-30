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
 * @brief Various bitmask flags used to represent information about a user
 */
UENUM(BlueprintType)
enum user_flags : uint32 {
	u_bot =				0b00000000000000000000000000000001,
	u_system =			0b00000000000000000000000000000010,
	u_mfa_enabled =			0b00000000000000000000000000000100,
	u_verified =			0b00000000000000000000000000001000,
	u_nitro_full =			0b00000000000000000000000000010000,
	u_nitro_classic =		0b00000000000000000000000000100000,
	u_discord_employee =		0b00000000000000000000000001000000,
	u_partnered_owner =		0b00000000000000000000000010000000,
	u_hypesquad_events =		0b00000000000000000000000100000000,
	u_bughunter_1 =			0b00000000000000000000001000000000,
	u_house_bravery =		0b00000000000000000000010000000000,
	u_house_brilliance =		0b00000000000000000000100000000000,
	u_house_balance =		0b00000000000000000001000000000000,
	u_early_supporter =		0b00000000000000000010000000000000,
	u_team_user =			0b00000000000000000100000000000000,
	u_bughunter_2 =			0b00000000000000001000000000000000,
	u_verified_bot =		0b00000000000000010000000000000000,
	u_verified_bot_dev =	 	0b00000000000000100000000000000000,
	u_animated_icon =		0b00000000000001000000000000000000,
	u_certified_moderator =		0b00000000000010000000000000000000,
	u_bot_http_interactions =	0b00000000000100000000000000000000,
	u_nitro_basic = 			0b00000000001000000000000000000000,
	u_active_developer =		0b00000000010000000000000000000000,
	u_animated_banner =			0b00000000100000000000000000000000,
};

/**
 * @brief Represents a user on discord. May or may not be a member of a guild.
 */
USTRUCT(BlueprintType)
struct user {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user")
	FString username;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user")
	FString global_name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user")
	FString avatar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user")
	FString avatar_decoration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user")
	int64 flags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user")
	int discriminator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user")
	int refcount;

};

/**
 * @brief A user with additional fields only available via the oauth2 identify scope.
 * These are not included in user as additional scopes are needed to fetch them
 * which bots do not normally have.
 */
USTRUCT(BlueprintType)
struct user_identified {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user_identified")
	FString		locale;		//!< Optional: the user's chosen language option identify

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user_identified")
	bool			verified;	//!< Optional: whether the email on this account has been verified       email

};

/**
 * @brief helper function to deserialize a user from json
 *
 * @see https://github.com/nlohmann/json#arbitrary-types-conversions
 *
 * @param j output json object
 * @param u user to be deserialized
 */
/**
 * @brief helper function to deserialize a user_identified from json
 *
 * @see https://github.com/nlohmann/json#arbitrary-types-conversions
 *
 * @param j output json object
 * @param u user to be deserialized
 */
/** A group of users */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user")
TMap<FString, user> user_map;

