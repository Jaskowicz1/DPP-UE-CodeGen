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
 * @brief Represents a guild template
 */
USTRUCT(BlueprintType)
struct dtemplate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Dtemplate")
	FString code;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Dtemplate")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Dtemplate")
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Dtemplate")
	int64 usage_count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Dtemplate")
	FString creator_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Dtemplate")
	FDateTime created_at;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Dtemplate")
	FDateTime updated_at;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Dtemplate")
	FString source_guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Dtemplate")
	bool is_dirty;

};

/** A container of invites */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Dtemplate")
TMap<FString, dtemplate> dtemplate_map;

