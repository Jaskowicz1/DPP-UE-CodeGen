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
#define DISCORD_API_VERSION	"10"
#define API_PATH	        "/api/v" DISCORD_API_VERSION
// Forward declarations
/**
 * @brief This is an opaque class containing zlib library specific structures.
 * We define it this way so that the public facing D++ library doesn't require
 * the zlib headers be available to build against it.
 */
/**
 * @brief Represents a connection to a voice channel.
 * A client can only connect to one voice channel per guild at a time, so these are stored in a map
 * in the discord_client keyed by guild_id.
 */
USTRUCT(BlueprintType)
struct voiceconn {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voiceconn")
	FString channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voiceconn")
	FString websocket_hostname;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voiceconn")
	FString session_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voiceconn")
	FString token;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voiceconn")
	class discord_voice_client* voiceclient;

};

/** @brief Implements a discord client. Each discord_client connects to one shard and derives from a websocket client. */
USTRUCT(BlueprintType)
struct discord_client {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
{

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	class cluster* creator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	int64 heartbeat_interval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	FDateTime last_heartbeat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	int64 shard_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	int64 max_shards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	std::thread::native_handle_type thread_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	int64 last_seq;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	FString token;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	int64 intents;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	FString sessionid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	std::shared_mutex voice_mutex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	int64 resumes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	int64 reconnects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	double websocket_ping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	bool ready;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	FDateTime last_heartbeat_ack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	websocket_protocol_t protocol;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	TMap<FString, std::unique_ptr<voiceconn>> connecting_voice_channels;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	FString resume_gateway_url;

};

