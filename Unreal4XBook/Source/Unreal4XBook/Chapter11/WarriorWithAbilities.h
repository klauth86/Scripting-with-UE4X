// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayAbilitySet.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "WarriorWithAbilities.generated.h"

#define FS(x,...) FString::Printf( TEXT( x ), __VA_ARGS__ )

UCLASS()
class UNREAL4XBOOK_API AWarriorWithAbilities :
	public ACharacter,
	public IAbilitySystemInterface,
	public IGameplayTaskOwnerInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarriorWithAbilities();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Lists key triggers for various abilities for the player.
	// Selects an instance of UGameplayAbilitySet (which is a UDataAsset derivative
	// that you construct in the Content Browser).
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	UGameplayAbilitySet* gameplayAbilitySet;
	
	// The AbilitySystemComponent itself
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	UAbilitySystemComponent* AbilitySystemComponent;
	
	// IAbilitySystemInterface implementation:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const { return AbilitySystemComponent; }

	void TestGameplayEffect();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		UGameplayTasksComponent* GameplayTasksComponent;
	// This is the particleSystem that we create with the
	// GameplayTask_CreateParticles object.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		UParticleSystem* particleSystem;

	// <GameplayTaskOwnerInterface>
	virtual UGameplayTasksComponent* GetGameplayTasksComponent(const
		UGameplayTask& Task) const {
		return GameplayTasksComponent;
	}

	// This gets called both when task starts and when task gets
	// resumed.
	// Check Task.GetStatus() if you want to differentiate.
	virtual void OnTaskActivated(UGameplayTask& Task) {}
	
	virtual void OnTaskDeactivated(UGameplayTask& Task) {}
	
	virtual AActor* GetOwnerActor(const UGameplayTask* Task) const {
		return Task->GetOwnerActor(); // This will give us the
		// accurate answer for the Task..
	}
	// </End Gameplay
};
