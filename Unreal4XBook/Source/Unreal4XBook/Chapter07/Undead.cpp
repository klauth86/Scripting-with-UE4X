// Fill out your copyright notice in the Description page of Project Settings.


#include "Undead.h"
#include "Engine/Engine.h"

bool IUndead::IsDead() {
	return true;
}

void IUndead::Die() {
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, 
		"You can't kill what is already dead. Mwahaha");
	UE_LOG(LogTemp, Warning, TEXT("You can't kill what is already dead. Mwahaha"));
}

void IUndead::Turn() {
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red,
		"I'm fleeing!");
}

void IUndead::Banish() {
	if (AActor* Me = Cast<AActor>(this)) {
		Me->Destroy();
	}
}