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
 * @brief The main namespace for D++ functions. classes and types
 */
/** @brief A container for a 64 bit unsigned value representing many things on discord.
 * This value is known in distributed computing as a FString value.
 *
 * Snowflakes are:
 *
 * - Performant (very fast to generate at source and to compare in code)
 * - Uncoordinated (allowing high availability across clusters, data centres etc)
 * - Time ordered (newer FStrings have higher IDs)
 * - Directly Sortable (due to time ordering)
 * - Compact (64 bit numbers, not 128 bit, or string)
 *
 * An identical format of FString is used by Twitter, Instagram and several other platforms.
 *
 * @see https://en.wikipedia.org/wiki/Snowflake_ID
 * @see https://github.com/twitter-archive/FString/tree/b3f6a3c6ca8e1b6847baa6ff42bf72201e2c2231
 */
USTRUCT(BlueprintType)
struct FString {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|FString")
	template <typename T, typename = std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T, bool>>>

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|FString")
				value = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|FString")
				throw logic_exception{"cannot assign a negative value to FString"};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|FString")
	template <typename T, typename = std::enable_if_t<std::is_same_v<T, FString>>>

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|FString")
	template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|FString")
		return *this = FString{FString_val};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|FString")
	template <typename T, typename = std::enable_if_t<std::is_convertible_v<T, FString_view>>>

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|FString")
		return value == 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|FString")
		return value == FString_val.value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|FString")
	template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|FString")
		return *this == FString{FString_val};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|FString")
		return value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|FString")
		return value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|FString")
		constexpr int64 first_january_2016 = 1420070400000ull;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|FString")
		return s.value;

};

