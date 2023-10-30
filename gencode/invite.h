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
 * @brief Invite target types for invite
 */
UENUM(BlueprintType)
enum invite_target_t : uint8 {
	itt_none = 0, //!< Undefined invite target type
	itt_stream = 1, //!< Stream target type
	itt_embedded_application = 2, //!< Embedded Application target type
};

/**
 * @brief Represents an invite to a discord guild or channel
 */
USTRUCT(BlueprintType)
struct invite {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	FString code;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	FDateTime expires_at;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	FString guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	guild destination_guild;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	FString channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	channel destination_channel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	FString inviter_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	user inviter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	FString target_user_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	invite_target_t target_type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	int64 approximate_presence_count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	int64 approximate_member_count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	int64 max_age;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	int max_uses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	bool temporary;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	bool unique;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	int64 uses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	stage_instance stage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
	FDateTime created_at;

};

/** A container of invites */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Invite")
TMap<FString, invite> invite_map;

