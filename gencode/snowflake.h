#pragma once
 
USTRUCT(BlueprintType)
struct FString {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|FString")
	template <typename T, typename = std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T, bool>>>

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|FString")
				value = 0;

};

