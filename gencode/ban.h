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
 * @brief The ban class represents a ban on a guild.
 * 
 */
USTRUCT(BlueprintType)
struct ban {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|ban")
	FString reason;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|ban")
	FString user_id;

};

/**
 * A group of bans. The key is the user ID
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|ban_map;")
TMap<FString, ban> ban_map;

