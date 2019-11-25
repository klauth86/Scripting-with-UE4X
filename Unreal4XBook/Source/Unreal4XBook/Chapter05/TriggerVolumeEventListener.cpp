// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerVolumeEventListener.h"

// Sets default values
ATriggerVolumeEventListener::ATriggerVolumeEventListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;
}

// Called when the game starts or when spawned
void ATriggerVolumeEventListener::BeginPlay()
{
	Super::BeginPlay();

	if (TriggerEventSource != nullptr) {
		TriggerEventSource->OnPlayerEntered.AddUObject(this,
			&ATriggerVolumeEventListener::OnTriggerEvent);
	}
}

// Called every frame
void ATriggerVolumeEventListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATriggerVolumeEventListener::OnTriggerEvent() {
	PointLight->SetLightColor(FLinearColor(0, 1, 0, 1));
}

void ATriggerVolumeEventListener::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);

	if (TriggerEventSource != nullptr) {
		TriggerEventSource->OnPlayerEntered.Clear();
	}
}

