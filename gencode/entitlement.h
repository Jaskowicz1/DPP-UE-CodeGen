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
 * @brief The type of entitlement.
 * */
UENUM(BlueprintType)
enum entitlement_type : uint8 {
	GUILD_SUBSCRIPTION = 1,
	USER_SUBSCRIPTION = 2,
	APPLICATION_SUBSCRIPTION = 8
};

/**
 * @brief Entitlement flags.
 */
UENUM(BlueprintType)
enum entitlement_flags : uint16 {
	ent_deleted =		0b000000000000001,
};

/**
 * @brief A definition of a discord entitlement.
 */
USTRUCT(BlueprintType)
struct entitlement {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|entitlement")
	FString sku_id{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|entitlement")
	FString application_id{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|entitlement")
	FString owner_id{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|entitlement")
	entitlement_type type = entitlement_type::APPLICATION_SUBSCRIPTION;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|entitlement")
	FDateTime starts_at{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|entitlement")
	FDateTime ends_at{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|entitlement")
	int flags{0};

};

/**
 * @brief Group of entitlements.
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|entitlement_map;")
TMap<FString, entitlement> entitlement_map;

