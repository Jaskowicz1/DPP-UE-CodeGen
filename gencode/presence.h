#pragma once
 
UENUM(BlueprintType)
enum presence_flags : uint8 {
	p_desktop_online	=	0b00000001,
	p_desktop_dnd		=	0b00000010,
	p_desktop_idle		=	0b00000011,
	p_web_online		=	0b00000100,
	p_web_dnd		=	0b00001000,
	p_web_idle		=	0b00001100,
	p_mobile_online		=	0b00010000,
	p_mobile_dnd		=	0b00100000,
	p_mobile_idle		=	0b00110000,
	p_status_online		=	0b01000000,
	p_status_dnd		=	0b10000000,
	p_status_idle		=	0b11000000
};

UENUM(BlueprintType)
enum presence_status : uint8 {
	ps_offline	=	0,
	ps_online	=	1,
	ps_dnd		=	2,
	ps_idle		=	3,
	ps_invisible	=	4,
};

UENUM(BlueprintType)
enum activity_type : uint8 {
	at_game		=	0,
	at_streaming	=	1,
	at_listening	=	2,
	at_watching	=	3,
	at_custom	=	4,
	at_competing	=	5
};

UENUM(BlueprintType)
enum activity_flags : uint8 {
	af_instance					= 0b000000001,
	af_join						= 0b000000010,
	af_spectate					= 0b000000100,
	af_join_request					= 0b000001000,
	af_sync						= 0b000010000,
	af_play						= 0b000100000,
	af_party_privacy_friends 			= 0b001000000,
	af_party_privacy_voice_channel			= 0b010000000,
	af_embedded 					= 0b100000000
};

USTRUCT(BlueprintType)
struct activity {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	FString state;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	FString details;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	activity_assets assets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	FString url;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	TArray<activity_button> buttons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	dpp::emoji emoji;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	activity_party party;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	activity_secrets secrets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	activity_type type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	FDateTime created_at;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	FDateTime start;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	FDateTime end;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	FString application_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	int flags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|activity")
	bool is_instance;

};

USTRUCT(BlueprintType)
struct presence {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|presence")
	FString	user_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|presence")
	FString       guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|presence")
	int		flags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|presence")
	TArray<activity> activities;

};

