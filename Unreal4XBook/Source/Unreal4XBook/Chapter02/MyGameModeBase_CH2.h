// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UserProfile.h"
#include "MyGameModeBase_CH2.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL4XBOOK_API AMyGameModeBase_CH2 : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UClassNames)
		TSubclassOf<UUserProfile> UPBlueprintClassName;	

	UFUNCTION(BlueprintCallable)
		void CreateObject() {
		UUserProfile* newobject = NewObject<UUserProfile>(
			(UObject*)GetTransientPackage(),
			UPBlueprintClassName->GetClass());

		// delay

		// Destroy object
		if (newobject) {
			newobject->ConditionalBeginDestroy();
			newobject = nullptr;
		}

		//newobject = construct(
		//	UPBlueprintClassName->GetClass());

		//// delay

		//// Destroy object
		//if (newobject) {
		//	newobject->ConditionalBeginDestroy();
		//	newobject = nullptr;
		//}

		/*
		C:\Program Files (x86)\Epic
Games\Launcher\Engine\Config\BaseEngine.ini, and defaults to one collection
every 61.1 seconds:
gc.TimeBetweenPurgingPendingKillObjects=61.1
		*/

		GetWorld()->ForceGarbageCollection(true);
	}
};
