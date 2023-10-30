#pragma once
 
UENUM(BlueprintType)
enum voicestate_flags : uint8 {
	vs_deaf		=	0b00000001,	//!< Deafened by the server
	vs_mute		=	0b00000010,	//!< Muted by the server
	vs_self_mute	=	0b00000100,	//!< Locally Muted
	vs_self_deaf	=	0b00001000,	//!< Locally deafened
	vs_self_stream	=	0b00010000,	//!< Whether this user is streaming using "Go Live"
	vs_self_video	=	0b00100000,	//!< Whether this user's camera is enabled
	vs_suppress	=	0b01000000	//!< Whether this user's permission to speak is denied
};

USTRUCT(BlueprintType)
struct voicestate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voicestate")
	class discord_client*	shard;             //!< Owning shard

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voicestate")
	FString		guild_id;          //!< Optional: the guild id this voice state is for

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voicestate")
	FString		user_id;           //!< the user id this voice state is for

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voicestate")
	FString		session_id;        //!< the session id for this voice state

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|voicestate")
	FDateTime			request_to_speak;  //!< The time at which the user requested to speak, or 0

};

