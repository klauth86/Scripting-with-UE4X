#pragma once

#include "ObjectMacros.h"
#include "Engine/Texture.h"
#include "ColoredTexture.generated.h"

USTRUCT(Blueprintable)
struct UNREAL4XBOOK_API FColoredTexture {
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
		UTexture* Texture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
		FLinearColor Color;
};