// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CustomHUDPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER14_API ACustomHUDPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;
};
