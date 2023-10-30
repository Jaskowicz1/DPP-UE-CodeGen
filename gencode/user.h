#pragma once
 
UENUM(BlueprintType)
enum user_flags : uint32 {
	u_bot =				0b00000000000000000000000000000001,
	u_system =			0b00000000000000000000000000000010,
	u_mfa_enabled =			0b00000000000000000000000000000100,
	u_verified =			0b00000000000000000000000000001000,
	u_nitro_full =			0b00000000000000000000000000010000,
	u_nitro_classic =		0b00000000000000000000000000100000,
	u_discord_employee =		0b00000000000000000000000001000000,
	u_partnered_owner =		0b00000000000000000000000010000000,
	u_hypesquad_events =		0b00000000000000000000000100000000,
	u_bughunter_1 =			0b00000000000000000000001000000000,
	u_house_bravery =		0b00000000000000000000010000000000,
	u_house_brilliance =		0b00000000000000000000100000000000,
	u_house_balance =		0b00000000000000000001000000000000,
	u_early_supporter =		0b00000000000000000010000000000000,
	u_team_user =			0b00000000000000000100000000000000,
	u_bughunter_2 =			0b00000000000000001000000000000000,
	u_verified_bot =		0b00000000000000010000000000000000,
	u_verified_bot_dev =	 	0b00000000000000100000000000000000,
	u_animated_icon =		0b00000000000001000000000000000000,
	u_certified_moderator =		0b00000000000010000000000000000000,
	u_bot_http_interactions =	0b00000000000100000000000000000000,
	u_nitro_basic = 			0b00000000001000000000000000000000,
	u_active_developer =		0b00000000010000000000000000000000,
	u_animated_banner =			0b00000000100000000000000000000000,
};

USTRUCT(BlueprintType)
struct user {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user")
	FString username;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user")
	FString global_name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user")
	FString avatar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user")
	FString avatar_decoration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user")
	int64 flags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user")
	int discriminator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user")
	int refcount;

};

USTRUCT(BlueprintType)
struct user_identified {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user_identified")
	FString		locale;		//!< Optional: the user's chosen language option identify

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|user_identified")
	bool			verified;	//!< Optional: whether the email on this account has been verified       email

};

