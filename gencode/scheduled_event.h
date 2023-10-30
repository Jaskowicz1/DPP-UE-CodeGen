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
 * @brief Represents the privacy of an event
 */
UENUM(BlueprintType)
enum event_privacy_level : uint8 {
	ep_guild_only = 2
};

/**
 * @brief Event entity types
 */
UENUM(BlueprintType)
enum event_entity_type : uint8 {
	eet_stage_instance = 1,
	eet_voice = 2,
	eet_external = 3
};

/**
 * @brief Event status types
 */
UENUM(BlueprintType)
enum event_status : uint8 {
	es_scheduled	=	1,
	es_active	=	2,
	es_completed	=	3,
	es_cancelled	=	4
};

/**
 * @brief Entities for the event
 */
USTRUCT(BlueprintType)
struct event_entities {
	GENERATED_BODY()

};

/**
 * @brief Represents a guild member/user who has registered interest in an event
 * 
 */
USTRUCT(BlueprintType)
struct event_member {
	GENERATED_BODY()

};

/**
 * @brief A scheduled event
 */
USTRUCT(BlueprintType)
struct scheduled_event {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|scheduled_event")
	FString		guild_id;		//!< the guild id which the scheduled event belongs to

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|scheduled_event")
	FString		creator_id;		//!< Optional: the id of the user that created the scheduled event

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|scheduled_event")
	FString		name;			//!< the name of the scheduled event

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|scheduled_event")
	FDateTime			scheduled_start_time;	//!< the time the scheduled event will start

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|scheduled_event")
	event_privacy_level	privacy_level;		//!< the privacy level of the scheduled event

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|scheduled_event")
	event_status		status;			//!< the status of the scheduled event

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|scheduled_event")
	event_entity_type	entity_type;		//!< the type of hosting entity associated with a scheduled event, e.g. voice channel or stage channel

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|scheduled_event")
	user			creator;		//!< Optional: the creator of the scheduled event

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|scheduled_event")
	int64		user_count;		//!< Optional: the number of users subscribed to the scheduled event

};

/**
 * @brief A group of scheduled events
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|scheduled_event")
TMap<FString, scheduled_event> scheduled_event_map;

/**
 * @brief A group of scheduled event members
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|event_member")
TMap<FString, event_member> event_member_map;

