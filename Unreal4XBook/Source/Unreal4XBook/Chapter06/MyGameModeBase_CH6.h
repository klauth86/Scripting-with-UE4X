// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase_CH6.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL4XBOOK_API AMyGameModeBase_CH6 : public AGameModeBase
{
	GENERATED_BODY()

		AMyGameModeBase_CH6();
protected:
	void BeginPlay();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
		TSubclassOf<class UUserWidget> Widget;
};
