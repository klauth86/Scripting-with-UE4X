// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Chapter12GameMode.h"
#include "Chapter12Character.h"
#include "UObject/ConstructorHelpers.h"
#include "NetworkHUD.h"

AChapter12GameMode::AChapter12GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	HUDClass = ANetworkHUD::StaticClass();
}
