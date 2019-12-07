// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickEventGameMode.h"
#include "Engine/Engine.h"

void AClickEventGameMode::BeginPlay() {
	Super::BeginPlay();
	Widget = SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SButton)
			.OnClicked(FOnClicked::CreateUObject(this,
				&AClickEventGameMode::ButtonClicked))
		.Content()
		[
			SAssignNew(ButtonLabel, STextBlock)
			.Text(FText::FromString(TEXT("Click me!")))
		]
		];
	auto player = GetWorld()->GetFirstLocalPlayerFromController();
	GEngine->GameViewport->AddViewportWidgetForPlayer(player, Widget.ToSharedRef(), 1);
	
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	
	auto pc = GEngine->GetFirstLocalPlayerController(GetWorld());
	EMouseLockMode lockMode = EMouseLockMode::DoNotLock;
	auto inputMode = FInputModeUIOnly().SetLockMouseToViewportBehavior(lockMode).SetWidgetToFocus(Widget);
	pc->SetInputMode(inputMode);
}

FReply AClickEventGameMode::ButtonClicked() {
	ButtonLabel->SetText(FString(TEXT("Clicked!")));
	return FReply::Handled();
}