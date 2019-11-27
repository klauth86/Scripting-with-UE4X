// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase_CH7.h"
#include "Engine/Engine.h"
#include "SingleInterfaceActor.h"
#include "EngineUtils.h" 

void AMyGameModeBase_CH7::BeginPlay() {
	Super::BeginPlay();
	// Spawn a new actor using the ASingleInterfaceActor class at
	//the default location

	FTransform SpawnLocation;
	ASingleInterfaceActor* SpawnedActor =
		GetWorld()->SpawnActor<ASingleInterfaceActor>(
			ASingleInterfaceActor::StaticClass(),
			SpawnLocation);
	// Get a reference to the class the actor has
	UClass* ActorClass = SpawnedActor->GetClass();

	if (ActorClass->ImplementsInterface(UMyInterface::StaticClass())) {
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red,
			TEXT("Spawned actor implements interface!"));
	}

	for (TActorIterator<AActor> It(GetWorld(), AActor::StaticClass()); It; ++It) {
		AActor* Actor = *It;
		IMyInterface* MyInterfaceInstance = Cast<IMyInterface>(Actor);
		// If the pointer is valid, add it to the list
		if (MyInterfaceInstance) {
			MyInterfaceInstances.Add(MyInterfaceInstance);
		}
	}
	// Print out how many objects implement the interface
	FString Message = FString::Printf(TEXT("%d actors implement the interface"), MyInterfaceInstances.Num());
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, Message);
}