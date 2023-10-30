#pragma once
 
UENUM(BlueprintType)
enum webhook_type : uint8 {
	w_incoming = 1,		//!< Incoming webhook
	w_channel_follower = 2,	//!< Channel following webhook
	w_application = 3	//!< Application webhooks for interactions.
};

USTRUCT(BlueprintType)
struct webhook {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	int type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	FString guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	FString channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	user user_obj;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	FString avatar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	FString token;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	FString application_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	guild source_guild;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	channel	source_channel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	FString url;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|webhook")
	FString image_data;

};

