// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameUnitAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL4XBOOK_API UGameUnitAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameUnitAttributes)
		float Hp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameUnitAttributes)
		float Mana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameUnitAttributes)
		float Speed;
};
