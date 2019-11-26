// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Warrior_CH6.generated.h"

UCLASS()
class UNREAL4XBOOK_API AWarrior_CH6 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarrior_CH6();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// The movement from the previous frame
	FVector2D lastInput;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Movement functions
	void Forward(float amount);
	void Back(float amount);
	void Right(float amount);
	void Left(float amount);

public:
	UFUNCTION(BlueprintCallable, Category = UIFuncs)
		void ButtonClicked() {
		UE_LOG(LogTemp, Warning, TEXT("UI Button Clicked"));
	}

	UFUNCTION(BlueprintNativeEvent, Category = Collision)
		void OnOverlapsBegin1(UPrimitiveComponent* Comp,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult&SweepResult);

	UFUNCTION(BlueprintNativeEvent, Category = Collision)
		void OnOverlapsEnd1(UPrimitiveComponent* Comp,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

	virtual void PostInitializeComponents() override;
};
