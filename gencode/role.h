#pragma once
 
UENUM(BlueprintType)
enum role_flags : uint8 {
	r_hoist =		0b00000001, //!< Hoisted role (if the role is pinned in the user listing)
	r_managed =		0b00000010, //!< Managed role (introduced by a bot or application)
	r_mentionable =		0b00000100, //!< Whether this role is mentionable with a ping
	r_premium_subscriber =	0b00001000, //!< Whether this is the guild's booster role
	r_available_for_purchase = 0b00010000, //!< Whether the role is available for purchase
	r_guild_connections = 0b00100000, //!< Whether the role is a guild's linked role
	r_in_prompt			= 0b01000000, //!< Whether the role can be selected by members in an onboarding prompt
};

USTRUCT(BlueprintType)
struct role {
	GENERATED_BODY()

};

UENUM(BlueprintType)
enum application_role_connection_metadata_type : uint8 {
	rc_integer_less_than_or_equal = 1, //!< The metadata value (integer) is less than or equal to the guild's configured value (integer)
	rc_integer_greater_than_or_equal = 2, //!< The metadata value (integer) is greater than or equal to the guild's configured value (integer)
	rc_integer_equal = 3, //!< The metadata value (integer) is equal to the guild's configured value (integer)
	rc_integer_not_equal = 4, //!< The metadata value (integer) is not equal to the guild's configured value (integer)
	rc_datetime_less_than_or_equal = 5, //!< The metadata value (ISO8601 string) is less than or equal to the guild's configured value (integer; days before current date)
	rc_datetime_greater_than_or_equal = 6, //!< The metadata value (ISO8601 string) is greater than or equal to the guild's configured value (integer; days before current date)
	rc_boolean_equal = 7, //!< The metadata value (integer) is equal to the guild's configured value (integer; 1)
	rc_boolean_not_equal = 8, //!< The metadata value (integer) is not equal to the guild's configured value (integer; 1)
};

USTRUCT(BlueprintType)
struct application_role_connection_metadata {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application_role_connection_metadata")
	application_role_connection_metadata_type type; //!< Type of metadata value

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application_role_connection_metadata")
	std::map<FString, FString> name_localizations; //!< Translations of the name

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|application_role_connection_metadata")
	std::map<FString, FString> description_localizations; //!< Translations of the description

};

USTRUCT(BlueprintType)
struct application_role_connection {
	GENERATED_BODY()

};

