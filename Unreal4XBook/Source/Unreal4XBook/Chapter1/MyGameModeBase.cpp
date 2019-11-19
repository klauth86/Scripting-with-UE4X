// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameModeBase.h"

void AMyGameModeBase::BeginPlay() {
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Some warning message"));

	FString name = "Tim";
	int32 mana = 450;
	TArray<FStringFormatArg> args;
	args.Add(FStringFormatArg(name));
	args.Add(FStringFormatArg(mana));
	FString string = FString::Format(TEXT("Name = {0} Mana = {1}" ), args );
	UE_LOG(LogTemp, Warning, TEXT("Your string: %s"), *string);
}


