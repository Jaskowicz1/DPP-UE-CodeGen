#pragma once
 
UENUM(BlueprintType)
enum event_privacy_level : uint8 {
	ep_guild_only = 2
};

UENUM(BlueprintType)
enum event_entity_type : uint8 {
	eet_stage_instance = 1,
	eet_voice = 2,
	eet_external = 3
};

UENUM(BlueprintType)
enum event_status : uint8 {
	es_scheduled	=	1,
	es_active	=	2,
	es_completed	=	3,
	es_cancelled	=	4
};

