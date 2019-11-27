// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyInterface.h"
#include "MyGameModeBase_CH7.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL4XBOOK_API AMyGameModeBase_CH7 : public AGameModeBase
{
	GENERATED_BODY()

public:
	TArray<IMyInterface*> MyInterfaceInstances;

	void BeginPlay();
};
