#pragma once
 
UENUM(BlueprintType)
enum entitlement_type : uint8 {
	GUILD_SUBSCRIPTION = 1,
	USER_SUBSCRIPTION = 2,
	APPLICATION_SUBSCRIPTION = 8
};

UENUM(BlueprintType)
enum entitlement_flags : uint16 {
	ent_deleted =		0b000000000000001,
};

USTRUCT(BlueprintType)
struct entitlement {
	GENERATED_BODY()

};

