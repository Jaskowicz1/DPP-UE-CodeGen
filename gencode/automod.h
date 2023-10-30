#pragma once
 
UENUM(BlueprintType)
enum automod_preset_type : uint8 {
	amod_preset_profanity = 1,
	amod_preset_sexual_content = 2,
	amod_preset_slurs = 3,
};

UENUM(BlueprintType)
enum automod_action_type : uint8 {
	amod_action_block_message = 1,
	amod_action_send_alert = 2,
	amod_action_timeout = 3,
};

UENUM(BlueprintType)
enum automod_event_type : uint8 {
	amod_message_send = 1,
};

UENUM(BlueprintType)
enum automod_trigger_type : uint8 {
	amod_type_keyword = 1,
	amod_type_harmful_link = 2,
	amod_type_spam = 3,
	amod_type_keyword_preset = 4,
	amod_type_mention_spam = 5,
};

USTRUCT(BlueprintType)
struct automod_rule {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|automod_rule")
	FString       	id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|automod_rule")
	FString       	guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|automod_rule")
	FString     	name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|automod_rule")
	FString       	creator_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|automod_rule")
	automod_event_type	event_type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|automod_rule")
	automod_trigger_type	trigger_type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|automod_rule")
	automod_metadata	trigger_metadata;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|automod_rule")
	TArray<automod_action> actions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|automod_rule")
	bool			enabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|automod_rule")
	TArray<FString>	exempt_roles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|automod_rule")
	TArray<FString>	exempt_channels;

};

