#pragma once
 
UENUM(BlueprintType)
enum emoji_flags : uint8 {
	e_require_colons = 0b00000001,
	e_managed =        0b00000010,
	e_animated =       0b00000100,
	e_available =      0b00001000,
};

USTRUCT(BlueprintType)
struct emoji {
	GENERATED_BODY()

};

