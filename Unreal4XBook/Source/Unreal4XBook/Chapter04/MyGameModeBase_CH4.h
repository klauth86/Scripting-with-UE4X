// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase_CH4.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL4XBOOK_API AMyGameModeBase_CH4 : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	void onTimer();
};
