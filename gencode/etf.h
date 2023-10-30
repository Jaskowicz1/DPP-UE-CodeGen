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
 * Parts of this file inspired by, or outright copied from erlpack:
 * https://github.com/discord/erlpack/
 * 
 * Acknowledgements:
 *
 *   sysdep.h:
 *       Based on work by FURUHASHI Sadayuki in msgpack-python
 *       (https://github.com/msgpack/msgpack-python)
 *
 *       Copyright (C) 2008-2010 FURUHASHI Sadayuki
 *       Licensed under the Apache License, Version 2.0 (the "License").
 *
 ************************************************************************************/
/** Current ETF format version in use */
/**
 * @brief Represents a token which identifies the type of value which follows it
 * in the ETF binary structure.
 */
UENUM(BlueprintType)
enum etf_token_type : uint8 {
	ett_distribution =	'D',
	ett_new_float =		'F',
	ett_bit_binary =	'M',
	ett_compressed =	'P',
	ett_smallint =		'a',
	ett_integer =		'b',
	ett_float =		'c',
	ett_atom =		'd',
	ett_reference =		'e',
	ett_port =		'f',
	ett_pid =		'g',
	ett_small_tuple =	'h',
	ett_large_tuple =	'i',
	ett_nil =		'j',
	ett_string =		'k',
	ett_list =		'l',
	ett_binary =		'm',
	ett_bigint_small =	'n',
	ett_bigint_large =	'o',
	ett_new_function =	'p',
	ett_export =		'q',
	ett_new_reference =	'r',
	ett_atom_small =	's',
	ett_map =	 	't',
	ett_function =		'u',
	ett_atom_utf8 =		'v',
	ett_atom_utf8_small =	'w'
};

/**
 * @brief Represents a buffer of bytes being encoded into ETF
 */
USTRUCT(BlueprintType)
struct etf_buffer {
	GENERATED_BODY()

};

/**
 * @brief The etf_parser class can serialise and deserialise ETF (Erlang Term Format)
 * into and out of an nlohmann::json object, so that layers above the websocket don't
 * have to be any different for handling ETF.
 */
USTRUCT(BlueprintType)
struct etf_parser {
	GENERATED_BODY()

};

