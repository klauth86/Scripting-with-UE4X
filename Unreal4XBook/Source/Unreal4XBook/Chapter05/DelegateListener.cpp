// Fill out your copyright notice in the Description page of Project Settings.


#include "DelegateListener.h"
#include "MyGameModeBase_CH5.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADelegateListener::ADelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;

	// Turn it off at the beginning so we can turn it on later
	// through code
	PointLight->SetVisibility(false);
	
	// Set the color to blue to make it easier to see
	PointLight->SetLightColor(FLinearColor::Blue);
}

// Called when the game starts or when spawned
void ADelegateListener::BeginPlay()
{
	Super::BeginPlay();

	if (auto world = GetWorld()) {
		auto GameMode = UGameplayStatics::GetGameMode(world);
		auto MyGameMode = Cast<AMyGameModeBase_CH5>(GameMode);
		if (MyGameMode) {
			MyGameMode->MyStandardDelegate.BindUObject(this,
				&ADelegateListener::EnableLight);
		}
	}
}

// Called every frame
void ADelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADelegateListener::EnableLight() {
	PointLight->SetVisibility(true);
}

void ADelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);
	if (auto world = GetWorld()) {
		auto GameMode = UGameplayStatics::GetGameMode(world);
		auto MyGameMode = Cast<AMyGameModeBase_CH5>(GameMode);
		if (MyGameMode != nullptr) {
			MyGameMode->MyStandardDelegate.Unbind();
		}
	}
}

