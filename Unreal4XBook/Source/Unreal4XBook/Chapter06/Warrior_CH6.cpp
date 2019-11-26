// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior_CH6.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AWarrior_CH6::AWarrior_CH6()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	lastInput = FVector2D::ZeroVector;
}

// Called when the game starts or when spawned
void AWarrior_CH6::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWarrior_CH6::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float len = lastInput.Size();
	
	// If the player's input is greater than 1, normalize it
	if (len > 1.f) {
		lastInput /= len;
	}

	AddMovementInput(GetActorForwardVector(), lastInput.Y);
	AddMovementInput(GetActorRightVector(), lastInput.X);

	// Zero off last input values
	lastInput = FVector2D::ZeroVector;
}

// Called to bind functionality to input
void AWarrior_CH6::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &AWarrior_CH6::Forward);
	PlayerInputComponent->BindAxis("Back", this, &AWarrior_CH6::Back);
	PlayerInputComponent->BindAxis("Right", this, &AWarrior_CH6::Right);
	PlayerInputComponent->BindAxis("Left", this, &AWarrior_CH6::Left);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AWarrior_CH6::Jump);

	// Calling function for HotKey
	PlayerInputComponent->BindAction("HotKey_UIButton_Spell", IE_Pressed, this, &AWarrior_CH6::ButtonClicked);
}

void AWarrior_CH6::Forward(float amount) {
	lastInput.Y += amount;
}

void AWarrior_CH6::Back(float amount) {
	lastInput.Y -= amount;
}

void AWarrior_CH6::Right(float amount) {
	lastInput.X += amount;
}

void AWarrior_CH6::Left(float amount) {
	lastInput.X -= amount;
}

void AWarrior_CH6::OnOverlapsBegin1_Implementation(UPrimitiveComponent* Comp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,	int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult&SweepResult) {

	UE_LOG(LogTemp, Warning, TEXT("Overlaps warrior	began"));
}

void AWarrior_CH6::OnOverlapsEnd1_Implementation(UPrimitiveComponent* Comp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex) {

	UE_LOG(LogTemp, Warning, TEXT("Overlaps warrior	ended"));
}

void AWarrior_CH6::PostInitializeComponents() {
	Super::PostInitializeComponents();
	if (RootComponent) {
		// Attach contact function to all bounding components.
		GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AWarrior_CH6::OnOverlapsBegin1);
		GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &AWarrior_CH6::OnOverlapsEnd1);
	}
}