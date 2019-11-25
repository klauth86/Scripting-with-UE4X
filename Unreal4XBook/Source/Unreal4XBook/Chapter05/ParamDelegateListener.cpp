// Fill out your copyright notice in the Description page of Project Settings.


#include "ParamDelegateListener.h"
#include "MyGameModeBase_CH5.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AParamDelegateListener::AParamDelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;
}

// Called when the game starts or when spawned
void AParamDelegateListener::BeginPlay()
{
	Super::BeginPlay();

	if (auto world = GetWorld()) {
		auto GameMode = UGameplayStatics::GetGameMode(world);
		auto MyGameMode = Cast<AMyGameModeBase_CH5>(GameMode);
		if (MyGameMode) {
			MyGameMode->MyParameterDelegate.BindUObject(this,
				&AParamDelegateListener::SetLightColor, false);
		}
	}
}

// Called every frame
void AParamDelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AParamDelegateListener::SetLightColor(FLinearColor LightColor, bool enableLight) {
	PointLight->SetLightColor(LightColor);
	PointLight->SetVisibility(enableLight);
}

void AParamDelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);
	if (auto world = GetWorld()) {
		auto GameMode = UGameplayStatics::GetGameMode(world);
		auto MyGameMode = Cast<AMyGameModeBase_CH5>(GameMode);
		if (MyGameMode != nullptr) {
			MyGameMode->MyParameterDelegate.Unbind();
		}
	}
}
