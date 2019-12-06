// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal4XBookGameModeBase.h"
#include "Unreal4XBook.h"

void AUnreal4XBookGameModeBase::BeginPlay() {
	Super::BeginPlay();

	// Traditional Logging
	UE_LOG(LogTemp, Warning, TEXT("Message %d"), 1);
	
	// Our custom log type
	UE_LOG(LogCh11, Display, TEXT("A display message, log is working" ) ); // shows in gray
	UE_LOG(LogCh11, Warning, TEXT("A warning message"));
	UE_LOG(LogCh11, Error, TEXT("An error message "));

	// 11-02 - Core/Logging API - FMessageLog to write
	// messages to the Message Log
	CreateLog(LoggerName);
	// Retrieve the Log by using the LoggerName.
	FMessageLog logger(LoggerName);
	logger.Warning(FTEXT("A warning message from gamemode"));
}


