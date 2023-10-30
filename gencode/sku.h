#pragma once
 
UENUM(BlueprintType)
enum sku_type : uint8 {
	SUBSCRIPTION = 5,
	SUBSCRIPTION_GROUP = 6,
};

UENUM(BlueprintType)
enum sku_flags : uint16 {
	sku_available =			0b000000000000100,
	sku_guild_subscription = 	0b000000010000000,
	sku_user_subscription =		0b000000100000000,
};

USTRUCT(BlueprintType)
struct sku {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|sku")
	sku_type type = sku_type::SUBSCRIPTION;

};

