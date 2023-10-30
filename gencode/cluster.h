#pragma once
 
UENUM(BlueprintType)
enum start_type : bool {
	st_wait = false,

	st_return = true,
};

USTRUCT(BlueprintType)
struct cluster {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|cluster")
	FString token;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|cluster")
	FDateTime last_identify;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|cluster")
	int64 intents;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|cluster")
	int64 numshards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|cluster")
	int64 cluster_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|cluster")
	int64 maxclusters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|cluster")
	double rest_ping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|cluster")
	dpp::user me;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|cluster")
	cache_policy_t cache_policy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|cluster")
	websocket_protocol_t ws_mode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|cluster")
	std::condition_variable terminating;

};

