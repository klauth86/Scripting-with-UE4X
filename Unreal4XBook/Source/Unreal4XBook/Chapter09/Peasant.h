// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "King.h"
#include "Peasant.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL4XBOOK_API APeasant : public AStaticMeshActor
{
	GENERATED_BODY()

	APeasant();

	UFUNCTION(BlueprintCallable, category = Peasant)
	void Flee(AKing * DeadKing);


};
