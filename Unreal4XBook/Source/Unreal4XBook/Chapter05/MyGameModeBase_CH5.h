// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase_CH5.generated.h"

/**
 * 
 */

DECLARE_DELEGATE(FStandardDelegateSignature)
DECLARE_DELEGATE_OneParam(FParamDelegateSignature, FLinearColor)
DECLARE_MULTICAST_DELEGATE(FMulticastDelegateSignature)

UCLASS()
class UNREAL4XBOOK_API AMyGameModeBase_CH5 : public AGameModeBase
{
	GENERATED_BODY()

public:
	FStandardDelegateSignature MyStandardDelegate;
	FParamDelegateSignature MyParameterDelegate;
	FMulticastDelegateSignature MyMulticastDelegate;
};