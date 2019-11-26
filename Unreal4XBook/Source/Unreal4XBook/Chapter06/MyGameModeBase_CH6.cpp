// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase_CH6.h"
#include "Blueprint/UserWidget.h"
#include "Warrior_CH6.h"

AMyGameModeBase_CH6::AMyGameModeBase_CH6() {
	DefaultPawnClass = AWarrior_CH6::StaticClass();
}

void AMyGameModeBase_CH6::BeginPlay() {
	Super::BeginPlay();
	if (Widget) {
		UUserWidget* Menu = CreateWidget<UUserWidget>(GetWorld(), Widget);
		if (Menu) {
			Menu->AddToViewport();
			GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
		}
	}
}
