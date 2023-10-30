#pragma once
 
USTRUCT(BlueprintType)
struct ssl_client {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|ssl_client")
	socket_callback_t custom_readable_fd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|ssl_client")
	socket_callback_t custom_writeable_fd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|ssl_client")
	socket_notification_t custom_readable_ready;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|ssl_client")
	socket_notification_t custom_writeable_ready;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|ssl_client")
	bool keepalive;

};

