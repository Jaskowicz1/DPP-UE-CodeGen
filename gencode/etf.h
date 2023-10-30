#pragma once
 
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

USTRUCT(BlueprintType)
struct etf_parser {
	GENERATED_BODY()

};

