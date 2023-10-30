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
 * @brief The type of SKU.
 * */
UENUM(BlueprintType)
enum sku_type : uint8 {
	SUBSCRIPTION = 5,
	SUBSCRIPTION_GROUP = 6,
};

/**
 * @brief SKU flags.
 */
UENUM(BlueprintType)
enum sku_flags : uint16 {
	sku_available =			0b000000000000100,
	sku_guild_subscription = 	0b000000010000000,
	sku_user_subscription =		0b000000100000000,
};

/**
 * @brief A definition of a discord SKU.
 */
USTRUCT(BlueprintType)
struct sku {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Sku")
	sku_type type = sku_type::SUBSCRIPTION;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Sku")
	FString application_id{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Sku")
	FString name{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Sku")
	FString slug{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Sku")
	int flags{0};

};

/**
 * @brief Group of SKUs.
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Sku")
TMap<FString, sku> sku_map;

