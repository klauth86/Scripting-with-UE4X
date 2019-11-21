// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MemoryAllocator.generated.h"

UCLASS(Blueprintable)
class UNREAL4XBOOK_API AMemoryAllocator : public AActor
{
	GENERATED_BODY()

public:
	void BeginPlay();

	void CAllocateExample();	

	void CPPAllocateExample();
};
