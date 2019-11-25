// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerVolume.h"
#include "Engine/Engine.h"
#include "MyGameModeBase_CH5.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyTriggerVolume::AMyTriggerVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerZone = CreateDefaultSubobject<UBoxComponent>("TriggerZone");
	TriggerZone->SetBoxExtent(FVector(200, 200, 100));
}

// Called when the game starts or when spawned
void AMyTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTriggerVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTriggerVolume::NotifyActorBeginOverlap(AActor* OtherActor) {
	auto Message = FString::Printf(TEXT("%s entered me"), *(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);

	// Call our delegate
	if (auto world = GetWorld()) {
		auto GameMode = UGameplayStatics::GetGameMode(world);
		auto MyGameMode = Cast<AMyGameModeBase_CH5>(GameMode);
		if (MyGameMode != nullptr) {
			MyGameMode->MyStandardDelegate.ExecuteIfBound();

			// Call the function using a parameter
			auto Color = FLinearColor(1, 0, 0, 1);
			MyGameMode->MyParameterDelegate.ExecuteIfBound(Color);

			MyGameMode->MyMulticastDelegate.Broadcast();
		}
	}

	OnPlayerEntered.Broadcast();
}

void AMyTriggerVolume::NotifyActorEndOverlap(AActor* OtherActor) {
	auto Message = FString::Printf(TEXT("%s left me"), *(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);
}

