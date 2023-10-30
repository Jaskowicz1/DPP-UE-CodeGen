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
 * @brief Represents the privacy of a stage instance
 */
UENUM(BlueprintType)
enum stage_privacy_level : uint8 {
	sp_public = 1,
	sp_guild_only = 2
};

/**
 * @brief A stage instance.
 * Stage instances are like a conference facility, with moderators/speakers and listeners.
 */
USTRUCT(BlueprintType)
struct stage_instance {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Stage_instance")
	FString guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Stage_instance")
	FString channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Stage_instance")
	FString topic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Stage_instance")
	stage_privacy_level privacy_level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Stage_instance")
	bool discoverable_disabled;

};

/** A group of stage instances */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Stage_instance")
TMap<FString, stage_instance> stage_instance_map;

