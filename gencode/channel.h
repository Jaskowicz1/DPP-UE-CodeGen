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
/** @brief Flag integers as received from and sent to discord */
UENUM(BlueprintType)
enum channel_type : uint8 {
	CHANNEL_TEXT		= 0,	//!< a text channel within a server
	DM			= 1,	//!< a direct message between users
	CHANNEL_VOICE		= 2,	//!< a voice channel within a server
	GROUP_DM		= 3,
	CHANNEL_CATEGORY	= 4,	//!< an organizational category that contains up to 50 channels
	CHANNEL_ANNOUNCEMENT	= 5,	//!< a channel that users can follow and crosspost into their own server
	CHANNEL_STORE		= 6,
	CHANNEL_ANNOUNCEMENT_THREAD	= 10,	//!< a temporary sub-channel within a GUILD_ANNOUNCEMENT channel
	CHANNEL_PUBLIC_THREAD	= 11,	//!< a temporary sub-channel within a GUILD_TEXT or GUILD_FORUM channel
	CHANNEL_PRIVATE_THREAD	= 12,	//!< a temporary sub-channel within a GUILD_TEXT channel that is only viewable by those invited and those with the MANAGE_THREADS permission
	CHANNEL_STAGE		= 13,	//!< a "stage" channel, like a voice channel with one authorised speaker
	CHANNEL_DIRECTORY	= 14,   //!< the channel in a [hub](https://support.discord.com/hc/en-us/articles/4406046651927-Discord-Student-Hubs-FAQ) containing the listed servers
	CHANNEL_FORUM		= 15,	//!< forum channel that can only contain threads
	CHANNEL_MEDIA		= 16,	//!< Media channel that can only contain threads, similar to forum channels
};

/** @brief Our flags as stored in the object
 * @note The bottom four bits of this flag are reserved to contain the channel_type values
 * listed above as provided by Discord. If discord add another value > 15, we will have to
 * shuffle these values upwards by one bit.
 */
UENUM(BlueprintType)
enum channel_flags : uint16 {
	c_nsfw =		0b0000000000010000,
	c_video_quality_720p =	0b0000000000100000,
	c_lock_permissions =	0b0000000001000000,
	c_pinned_thread =	0b0000000010000000,
	c_require_tag =		0b0000000100000000,
	c_hide_media_download_options = 0b0001000000000000,
};

/**
 * @brief Types for sort posts in a forum channel
 */
UENUM(BlueprintType)
enum default_forum_sort_order_t : uint8 {
	so_latest_activity = 0,
	so_creation_date = 1,
};

/**
 * @brief Types of forum layout views that indicates how the threads in a forum channel will be displayed for users by default
 */
UENUM(BlueprintType)
enum forum_layout_type : uint8 {
	fl_not_set = 0, //!< No default has been set for the forum channel
	fl_list_view = 1, //!< Display posts as a list
	fl_gallery_view = 2, //!< Display posts as a collection of tiles
};

/**
 * @brief channel permission overwrite types
 */
UENUM(BlueprintType)
enum overwrite_type : uint8 {
	ot_role = 0,
	ot_member = 1
};

/**
 * @brief Channel permission overwrites
 */
USTRUCT(BlueprintType)
struct permission_overwrite {
	GENERATED_BODY()

};

/**
 * @brief metadata for threads
 */
USTRUCT(BlueprintType)
struct thread_metadata {
	GENERATED_BODY()

};

/**
 * @brief Auto archive duration of threads which will stop showing in the channel list after the specified period of inactivity.
 * Defined as an enum to fit into 1 byte. Internally it'll be translated to minutes to match the API
 */
UENUM(BlueprintType)
enum auto_archive_duration_t : uint8 {
	arc_1_hour = 1,
	arc_1_day = 2,
	arc_3_days = 3,
	arc_1_week = 4,
};

/**
 * @brief represents membership of a user with a thread
 */
USTRUCT(BlueprintType)
struct thread_member {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|thread_member")
	FString thread_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|thread_member")
	FString user_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|thread_member")
	FDateTime joined;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|thread_member")
	int64 flags;

};

/**
 * @brief Represents a tag that is able to be applied to a thread in a forum or media channel
 */
USTRUCT(BlueprintType)
struct forum_tag {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|forum_tag")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|forum_tag")
	TVariant<FString, FString> emoji;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|forum_tag")
	bool moderated;

};

/**
 * @brief A group of thread member objects. the key is the user_id of the thread_member
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|thread_member")
TMap<FString, thread_member> thread_member_map;

/**
 * @brief A definition of a discord channel.
 * There are one of these for every channel type except threads. Threads are
 * special FStrings. Get it? A Discord pun. Hahaha. .... I'll get my coat.
 */ 
USTRUCT(BlueprintType)
struct channel {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	FString topic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	FString rtc_region;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	TArray<FString> recipients;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	TArray<permission_overwrite> permission_overwrites;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	TArray<forum_tag> available_tags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	TVariant<FString, FString> default_reaction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	FString icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	FString owner_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	FString parent_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	FString guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	FString last_message_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	FDateTime last_pin_timestamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	permission permissions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	int position;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	int bitrate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	int rate_limit_per_user;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	int default_thread_rate_limit_per_user;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	auto_archive_duration_t default_auto_archive_duration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	default_forum_sort_order_t default_sort_order;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	int flags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
	int user_limit;

};

/** @brief A definition of a discord thread.
 * A thread is a superset of a channel. Not to be confused with `std::thread`!
 */
USTRUCT(BlueprintType)
struct thread {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|thread")
	thread_member member;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|thread")
	thread_metadata metadata;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|thread")
	message msg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|thread")
	TArray<FString> applied_tags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|thread")
	int64 total_messages_sent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|thread")
	int message_count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|thread")
	int member_count;

};

/**
 * @brief Serialize a thread_metadata object to json
 *
 * @param j JSON object to serialize to
 * @param tmdata object to serialize
 */
/**
 * @brief Serialize a permission_overwrite object to json
 *
 * @param j JSON object to serialize to
 * @param po object to serialize
 */
/**
 * @brief A group of channels
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|channel")
TMap<FString, channel> channel_map;

/**
 * @brief A group of threads
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|thread")
TMap<FString, thread> thread_map;

/**
 * @brief A thread alongside the bot's optional thread_member object tied to it
 */
/**
 * @brief A map of threads alongside optionally the thread_member tied to the bot if it is in the thread. The map's key is the thread id. Returned from the cluster::threads_get_active method
 */
