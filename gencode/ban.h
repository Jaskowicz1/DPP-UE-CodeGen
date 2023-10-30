#pragma once
 
USTRUCT(BlueprintType)
struct ban {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|ban")
	FString reason;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|ban")
	FString user_id;

};

