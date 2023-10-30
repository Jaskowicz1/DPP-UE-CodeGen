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
 * @brief Possible types of preset filter lists
 */
UENUM(BlueprintType)
enum automod_preset_type : uint8 {
	amod_preset_profanity = 1,
	amod_preset_sexual_content = 2,
	amod_preset_slurs = 3,
};

/**
 * @brief Action types to perform on filtering
 */
UENUM(BlueprintType)
enum automod_action_type : uint8 {
	amod_action_block_message = 1,
	amod_action_send_alert = 2,
	amod_action_timeout = 3,
};

/**
 * @brief Event types, only message send is currently supported
 */
UENUM(BlueprintType)
enum automod_event_type : uint8 {
	amod_message_send = 1,
};

/**
 * @brief Types of moderation to trigger
 */
UENUM(BlueprintType)
enum automod_trigger_type : uint8 {
	amod_type_keyword = 1,
	amod_type_harmful_link = 2,
	amod_type_spam = 3,
	amod_type_keyword_preset = 4,
	amod_type_mention_spam = 5,
};

/**
 * @brief Metadata associated with an automod action. Different fields are relevant based on the value of automod_rule::trigger_type.
 */
USTRUCT(BlueprintType)
struct automod_metadata {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_metadata")
	TArray<FString> keywords;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_metadata")
	TArray<FString> regex_patterns;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_metadata")
	TArray<automod_preset_type> presets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_metadata")
	TArray<FString> allow_list;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_metadata")
	int mention_total_limit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_metadata")
	bool mention_raid_protection_enabled;

};

/**
 * @brief Represents an automod action
 */
USTRUCT(BlueprintType)
struct automod_action {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_action")
	automod_action_type type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_action")
	FString channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_action")
	FString custom_message;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_action")
	int64 duration_seconds;

};

/**
 * @brief Represents an automod rule
 */
USTRUCT(BlueprintType)
struct automod_rule {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_rule")
	FString       	id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_rule")
	FString       	guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_rule")
	FString     	name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_rule")
	FString       	creator_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_rule")
	automod_event_type	event_type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_rule")
	automod_trigger_type	trigger_type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_rule")
	automod_metadata	trigger_metadata;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_rule")
	TArray<automod_action> actions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_rule")
	bool			enabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_rule")
	TArray<FString>	exempt_roles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_rule")
	TArray<FString>	exempt_channels;

};

/** A group of automod rules.
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Automod_rule")
TMap<FString, automod_rule> automod_rule_map;

