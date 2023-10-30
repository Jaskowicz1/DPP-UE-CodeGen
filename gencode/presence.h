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
 * @brief Presence flags bitmask
 */
UENUM(BlueprintType)
enum presence_flags : uint8 {
	p_desktop_online	=	0b00000001,
	p_desktop_dnd		=	0b00000010,
	p_desktop_idle		=	0b00000011,
	p_web_online		=	0b00000100,
	p_web_dnd		=	0b00001000,
	p_web_idle		=	0b00001100,
	p_mobile_online		=	0b00010000,
	p_mobile_dnd		=	0b00100000,
	p_mobile_idle		=	0b00110000,
	p_status_online		=	0b01000000,
	p_status_dnd		=	0b10000000,
	p_status_idle		=	0b11000000
};

/**
 * @brief Online presence status values
 */
UENUM(BlueprintType)
enum presence_status : uint8 {
	ps_offline	=	0,
	ps_online	=	1,
	ps_dnd		=	2,
	ps_idle		=	3,
	ps_invisible	=	4,
};

/**
 * @brief Bit shift for desktop status
 */
#define PF_SHIFT_DESKTOP	0
/** Bit shift for web status */
#define PF_SHIFT_WEB		2
/** Bit shift for mobile status */
#define PF_SHIFT_MOBILE		4
/** Bit shift for main status */
#define PF_SHIFT_MAIN		6
/** Bit mask for status */
#define PF_STATUS_MASK		0b00000011
/** Bit mask for clearing desktop status */
#define PF_CLEAR_DESKTOP	0b11111100
/** Bit mask for clearing web status */
#define PF_CLEAR_WEB		0b11110011
/** Bit mask for clearing mobile status */
#define PF_CLEAR_MOBILE		0b11001111
/** Bit mask for clearing main status */
#define PF_CLEAR_STATUS		0b00111111
/**
 * @brief Game types
 */
UENUM(BlueprintType)
enum activity_type : uint8 {
	at_game		=	0,
	at_streaming	=	1,
	at_listening	=	2,
	at_watching	=	3,
	at_custom	=	4,
	at_competing	=	5
};

/**
 * @brief Activity types for rich presence
 */
UENUM(BlueprintType)
enum activity_flags : uint8 {
	af_instance					= 0b000000001,
	af_join						= 0b000000010,
	af_spectate					= 0b000000100,
	af_join_request					= 0b000001000,
	af_sync						= 0b000010000,
	af_play						= 0b000100000,
	af_party_privacy_friends 			= 0b001000000,
	af_party_privacy_voice_channel			= 0b010000000,
	af_embedded 					= 0b100000000
};

/**
 * @brief An activity button is a custom button shown in the rich presence. Can be to join a game or whatever
 */
USTRUCT(BlueprintType)
struct activity_button {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity_button")
	FString label;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity_button")
	FString url;

};

/**
 * @brief An activity asset are the images and the hover text displayed in the rich presence
 */
USTRUCT(BlueprintType)
struct activity_assets {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity_assets")
	FString large_image;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity_assets")
	FString large_text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity_assets")
	FString small_image;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity_assets")
	FString small_text;

};

/**
 * @brief Secrets for Rich Presence joining and spectating
 */
USTRUCT(BlueprintType)
struct activity_secrets {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity_secrets")
	FString join;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity_secrets")
	FString spectate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity_secrets")
	FString match;

};

/**
 * @brief Information for the current party of the player
 */
USTRUCT(BlueprintType)
struct activity_party {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity_party")
	FString id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity_party")
	int32_t current_size;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity_party")
	int32_t maximum_size;

};

/**
 * @brief An activity is a representation of what a user is doing. It might be a game, or a website, or a movie. Whatever.
 */
USTRUCT(BlueprintType)
struct activity {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	FString state;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	FString details;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	activity_assets assets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	FString url;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	TArray<activity_button> buttons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	emoji emoji;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	activity_party party;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	activity_secrets secrets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	activity_type type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	FDateTime created_at;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	FDateTime start;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	FDateTime end;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	FString application_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	int flags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	bool is_instance;

};

/**
 * @brief Represents user presence, e.g. what game they are playing and if they are online
 */
USTRUCT(BlueprintType)
struct presence {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|presence")
	FString	user_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|presence")
	FString       guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|presence")
	int		flags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|presence")
	TArray<activity> activities;

};

/** A container of presences */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|presence_map;")
typedef TMap<FString, presence> presence_map;

