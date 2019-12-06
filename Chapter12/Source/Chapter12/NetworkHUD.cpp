// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "Chapter12Character.h"

void ANetworkHUD::DrawHUD() {
	Super::DrawHUD();
	AChapter12Character* PlayerCharacter = Cast<AChapter12Character>(GetOwningPawn());
	if (PlayerCharacter) {
		Canvas->DrawText(GEngine->GetMediumFont(),
			FString::Printf(TEXT("Called Jump %d times!"),
				PlayerCharacter->JumpCount), 10, 10);
	}
}
