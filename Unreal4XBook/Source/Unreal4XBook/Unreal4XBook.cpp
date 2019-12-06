// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal4XBook.h"
#include "Modules/ModuleManager.h"
#include "MessageLog/Public/MessageLogModule.h"
#include "MessageLog.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, Unreal4XBook, "Unreal4XBook" );

DEFINE_LOG_CATEGORY(LogCh11);

FName LoggerName("MessageLogChapter11");

void CreateLog(FName logName) {
	FMessageLogModule& MessageLogModule =
		FModuleManager::LoadModuleChecked<FMessageLogModule>("MessageLog");
	FMessageLogInitializationOptions InitOptions;
	
	InitOptions.bShowPages = true;
	InitOptions.bShowFilters = true;
	
	FText LogListingName = FTEXT("Chapter 11's Log Listing");
	MessageLogModule.RegisterLogListing(logName, LogListingName, InitOptions);
}