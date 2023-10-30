#pragma once
 
USTRUCT(BlueprintType)
struct voiceconn {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voiceconn")
	FString channel_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voiceconn")
	FString websocket_hostname;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voiceconn")
	FString session_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voiceconn")
	FString token;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voiceconn")
	class discord_voice_client* voiceclient;

};

USTRUCT(BlueprintType)
struct discord_client {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
{

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	class dpp::cluster* creator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	int64 heartbeat_interval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	FDateTime last_heartbeat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	int64 shard_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	int64 max_shards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	std::thread::native_handle_type thread_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	int64 last_seq;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	FString token;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	int64 intents;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	FString sessionid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	std::shared_mutex voice_mutex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	int64 resumes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	int64 reconnects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	double websocket_ping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	bool ready;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	FDateTime last_heartbeat_ack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	websocket_protocol_t protocol;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	std::unordered_map<FString, std::unique_ptr<voiceconn>> connecting_voice_channels;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|discord_client")
	FString resume_gateway_url;

};

