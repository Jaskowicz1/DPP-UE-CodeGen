#pragma once
 
UENUM(BlueprintType)
enum voiceregion_flags : uint8 {
	v_optimal	= 0x00000001,
	v_deprecated	= 0x00000010,
	v_custom	= 0x00000100,
	v_vip		= 0x00001000
};

USTRUCT(BlueprintType)
struct voiceregion {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voiceregion")
	FString id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voiceregion")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voiceregion")
	int flags;

};

