// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ColoredTexture.h"
#include "EnumStatus.h"
#include "Object_Blueprintable.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class UNREAL4XBOOK_API UObject_Blueprintable : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float Armor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float HpMax;

	// Displays any UClasses deriving from UObject in a dropdown
	// menu in Blueprints
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit)
		TSubclassOf<UObject> UClassOfPlayer;
	// Displays string names of UCLASSes that derive from
	// the GameMode C++ base class
	UPROPERTY(EditAnywhere, meta = (MetaClass = "GameMode"), Category = Unit)
		FStringClassReference UClassGameMode;

	// Custom struct example
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
		FColoredTexture Texture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
		TEnumAsByte<Status> Status;
};
