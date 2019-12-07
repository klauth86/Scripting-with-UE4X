// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomHUDPlayerController.h"
#include "SlateBasics.h"
#include "Engine/Engine.h"

void ACustomHUDPlayerController::BeginPlay() {
	Super::BeginPlay();
	TSharedRef<SVerticalBox> widget = SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SButton)
			.Content()
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Test button")))
		]
		]
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		[
			SNew(SButton)
			.Content()
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Test button")))
		]
		];
	GEngine->GameViewport->AddViewportWidgetForPlayer(GetLocalPlayer(), widget, 1);
}