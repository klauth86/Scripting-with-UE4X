// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "SlidingDoor.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL4XBOOK_API ASlidingDoor : public AStaticMeshActor
{
	GENERATED_BODY()
public:

	ASlidingDoor();

protected:
	void BeginPlay();

public:
	void Tick(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = Door)
		void Open();

	UPROPERTY()
		bool IsOpen;

	UPROPERTY()
		FVector TargetLocation;
};
