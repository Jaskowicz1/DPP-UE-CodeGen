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
 * @brief Defines types of webhook
 */
UENUM(BlueprintType)
enum webhook_type : uint8 {
	w_incoming = 1,		//!< Incoming webhook
	w_channel_follower = 2,	//!< Channel following webhook
	w_application = 3	//!< Application webhooks for interactions.
};

/**
 * @brief Represents a discord webhook
 */
USTRUCT(BlueprintType)
struct webhook {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	int type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	FString guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	FString channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	user user_obj;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	FString avatar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	FString token;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	FString application_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	guild source_guild;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	channel	source_channel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	FString url;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	FString image_data;

};

/**
 * @brief A group of webhooks
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
TMap<FString, webhook> webhook_map;

