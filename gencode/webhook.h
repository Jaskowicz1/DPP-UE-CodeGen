#pragma once
 
UENUM(BlueprintType)
enum class webhook_type : uint8 {
	w_incoming = 1,		//!< Incoming webhook
	w_channel_follower = 2,	//!< Channel following webhook
	w_application = 3	//!< Application webhooks for interactions.
};

USTRUCT(BlueprintType)
struct webhook {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord")
	uint8_t type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord")
	snowflake guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord")
	snowflake channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord")
	user user_obj;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord")
	std::string name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord")
	utility::iconhash avatar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord")
	std::string token;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord")
	snowflake application_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord")
	guild source_guild;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord")
	channel	source_channel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord")
	std::string url;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord")
	std::string image_data;

};

