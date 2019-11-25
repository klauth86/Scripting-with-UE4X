// Fill out your copyright notice in the Description page of Project Settings.


#include "MulticastDelegateListener.h"
#include "Components/PointLightComponent.h"
#include "MyGameModeBase_CH5.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMulticastDelegateListener::AMulticastDelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;
}

// Called when the game starts or when spawned
void AMulticastDelegateListener::BeginPlay()
{
	Super::BeginPlay();

	if (auto world = GetWorld()) {
		auto GameMode = UGameplayStatics::GetGameMode(world);
		auto MyGameMode = Cast<AMyGameModeBase_CH5>(GameMode);
		if (MyGameMode) {
			MyDelegateHandle = MyGameMode->MyMulticastDelegate.AddUObject(this,
				&AMulticastDelegateListener::ToggleLight);
		}
	}
}

// Called every frame
void AMulticastDelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMulticastDelegateListener::ToggleLight() {
	PointLight->ToggleVisibility();
}

void AMulticastDelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);
	if (auto world = GetWorld()) {
		auto GameMode = UGameplayStatics::GetGameMode(world);
		auto MyGameMode = Cast<AMyGameModeBase_CH5>(GameMode);
		if (MyGameMode != nullptr) {
			MyGameMode->MyMulticastDelegate.Remove(MyDelegateHandle);
		}
	}
}