#pragma once
 
UENUM(BlueprintType)
enum invite_target_t : uint8 {
	itt_none = 0, //!< Undefined invite target type
	itt_stream = 1, //!< Stream target type
	itt_embedded_application = 2, //!< Embedded Application target type
};

USTRUCT(BlueprintType)
struct invite {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	FString code;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	FDateTime expires_at;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	FString guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	guild destination_guild;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	FString channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	channel destination_channel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	FString inviter_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	user inviter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	FString target_user_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	invite_target_t target_type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	int64 approximate_presence_count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	int64 approximate_member_count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	int64 max_age;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	int max_uses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	bool temporary;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	bool unique;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	int64 uses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	stage_instance stage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|invite")
	FDateTime created_at;

};

