// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "PostEditChangePropertyActor.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL4XBOOK_API APostEditChangePropertyActor : public AStaticMeshActor
{
	GENERATED_BODY()

	APostEditChangePropertyActor();

	UPROPERTY(EditAnywhere)
		bool ShowStaticMesh = true;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};
