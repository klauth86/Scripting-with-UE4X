// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MyGameModeBase_CH4.h"
#include "Engine/Engine.h"
#include "MyFirstActor.h"

void AMyGameModeBase_CH4::BeginPlay() {
	// Call the parent class version of this function
	Super::BeginPlay();
	// Displays a red message on the screen for 10 seconds
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red,
		TEXT("Actor Spawning"));
	// Spawn an instance of the AMyFirstActor class at the
	//default location.
	FTransform SpawnLocation;
	GetWorld()->SpawnActor<AMyFirstActor>
		(AMyFirstActor::StaticClass(),
			SpawnLocation);

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this,
		&AMyGameModeBase_CH4::onTimer, 10);
}

void AMyGameModeBase_CH4::onTimer() {
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red,
		TEXT("onTimer"));
}


