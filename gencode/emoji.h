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
#define MAX_EMOJI_SIZE 256 * 1024
/**
 * @brief Flags for emoji
 */
UENUM(BlueprintType)
enum emoji_flags : uint8 {
	e_require_colons = 0b00000001,
	e_managed =        0b00000010,
	e_animated =       0b00000100,
	e_available =      0b00001000,
};

/**
 * @brief Represents an emoji for a guild
 */
USTRUCT(BlueprintType)
struct emoji {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|emoji")
	FString name{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|emoji")
	TArray<FString> roles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|emoji")
	FString user_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|emoji")
	utility::image_data image_data;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|emoji")
	int flags{0};

};

/**
 * @brief Group of emojis
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|emoji")
TMap<FString, emoji> emoji_map;

