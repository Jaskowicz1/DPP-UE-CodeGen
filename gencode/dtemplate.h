#pragma once
 
USTRUCT(BlueprintType)
struct dtemplate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|dtemplate")
	FString code;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|dtemplate")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|dtemplate")
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|dtemplate")
	int64 usage_count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|dtemplate")
	FString creator_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|dtemplate")
	FDateTime created_at;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|dtemplate")
	FDateTime updated_at;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|dtemplate")
	FString source_guild_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|dtemplate")
	bool is_dirty;

};

