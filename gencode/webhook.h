UENUM(BlueprintType)
enum class webhook_type : uint8 {
	w_incoming = 1,		//!< Incoming webhook
	w_channel_follower = 2,	//!< Channel following webhook
	w_application = 3	//!< Application webhooks for interactions.
};
