// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Object_BlueprintType.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class UNREAL4XBOOK_API UObject_BlueprintType : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	FString Name;	
};
