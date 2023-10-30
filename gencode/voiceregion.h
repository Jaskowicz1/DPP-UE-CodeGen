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
 * @brief Flags related to a voice region
 */
UENUM(BlueprintType)
enum voiceregion_flags : uint8 {
	v_optimal	= 0x00000001,
	v_deprecated	= 0x00000010,
	v_custom	= 0x00000100,
	v_vip		= 0x00001000
};

/**
 * @brief Represents a voice region on discord
 */
USTRUCT(BlueprintType)
struct voiceregion {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voiceregion")
	FString id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voiceregion")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voiceregion")
	int flags;

};

/**
 * @brief A group of voice regions
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voiceregion_map;")
typedef TMap<FString, voiceregion> voiceregion_map;

