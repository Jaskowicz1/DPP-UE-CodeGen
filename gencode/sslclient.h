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
 * @brief This is an opaque class containing openssl library specific structures.
 * We define it this way so that the public facing D++ library doesn't require
 * the openssl headers be available to build against it.
 */
/**
 * @brief A callback for socket status
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|socket_callback_t;")
typedef std::function<socket()> socket_callback_t;

/**
 * @brief A socket notification callback
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|socket_notification_t;")
typedef std::function<void()> socket_notification_t;

/**
 * @brief Close a socket 
 * 
 * @param sfd Socket to close
 * @return false on error, true on success
 */
/**
 * @brief Set a socket to blocking or non-blocking IO
 *
 * @param sockfd socket to act upon
 * @return false on error, true on success
 */
/**
 * @brief Implements a simple non-blocking SSL stream client.
 * 
 * @note although the design is non-blocking the run() method will
 * execute in an infinite loop until the socket disconnects. This is intended
 * to be run within a std::thread.
 */
USTRUCT(BlueprintType)
struct ssl_client {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|ssl_client")
	socket_callback_t custom_readable_fd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|ssl_client")
	socket_callback_t custom_writeable_fd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|ssl_client")
	socket_notification_t custom_readable_ready;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|ssl_client")
	socket_notification_t custom_writeable_ready;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|ssl_client")
	bool keepalive;

};

