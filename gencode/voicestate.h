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
 * @brief Bit mask flags relating to voice states
 */
UENUM(BlueprintType)
enum voicestate_flags : uint8 {
	vs_deaf		=	0b00000001,	//!< Deafened by the server
	vs_mute		=	0b00000010,	//!< Muted by the server
	vs_self_mute	=	0b00000100,	//!< Locally Muted
	vs_self_deaf	=	0b00001000,	//!< Locally deafened
	vs_self_stream	=	0b00010000,	//!< Whether this user is streaming using "Go Live"
	vs_self_video	=	0b00100000,	//!< Whether this user's camera is enabled
	vs_suppress	=	0b01000000	//!< Whether this user's permission to speak is denied
};

/**
 * @brief Represents the voice state of a user on a guild
 * These are stored in the guild object, and accessible there,
 * or via channel::get_voice_members
 */
USTRUCT(BlueprintType)
struct voicestate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voicestate")
	class discord_client*	shard;             //!< Owning shard

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voicestate")
	FString		guild_id;          //!< Optional: the guild id this voice state is for

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voicestate")
	FString		user_id;           //!< the user id this voice state is for

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voicestate")
	FString		session_id;        //!< the session id for this voice state

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voicestate")
	FDateTime			request_to_speak;  //!< The time at which the user requested to speak, or 0

};

/** A container of voicestates */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voicestate")
TMap<FString, voicestate> voicestate_map;

