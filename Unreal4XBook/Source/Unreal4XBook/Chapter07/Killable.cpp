// Fill out your copyright notice in the Description page of Project Settings.


#include "Killable.h"
#include "Engine/Engine.h"

// Add default functionality here for any IKillable functions that are not pure virtual.
// not pure virtual.
bool IKillable::IsDead() {
	return false;
}

void IKillable::Die() {
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Arrrgh");
	UE_LOG(LogTemp, Warning, TEXT("Arrrgh"));
	if (AActor* Me = Cast<AActor>(this)) {
		Me->Destroy();
	}
}