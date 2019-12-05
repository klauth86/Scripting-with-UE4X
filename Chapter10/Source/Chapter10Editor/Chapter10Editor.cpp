// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter10Editor.h"
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"
#include "LevelEditor.h"
#include "SlateBasics.h"
#include "MultiBoxExtender.h"
#include "CookbookCommands.h"
#include "Developer/AssetTools/Public/IAssetTools.h"
#include "Developer/AssetTools/Public/AssetToolsModule.h"
#include "MyCustomAssetActions.h"

IMPLEMENT_GAME_MODULE(FChapter10EditorModule, Chapter10Editor)

void FChapter10EditorModule::StartupModule() {
	FCookbookCommands::Register();
	TSharedPtr<FUICommandList> CommandList = MakeShareable(new FUICommandList());
	CommandList->MapAction(FCookbookCommands::Get().MyButton,
		FExecuteAction::CreateRaw(this, &FChapter10EditorModule::MyButton_Clicked),
		FCanExecuteAction());

	ToolbarExtender = MakeShareable(new FExtender());

	FLevelEditorModule& LevelEditorModule =
		FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");

	//Extension =
	//	ToolbarExtender->AddToolBarExtension("Compile",
	//		EExtensionHook::Before, CommandList,
	//		FToolBarExtensionDelegate::CreateRaw(this,
	//			&FChapter10EditorModule::AddToolbarExtension));
	//LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);

	Extension = ToolbarExtender->AddMenuExtension("LevelEditor",
		EExtensionHook::Before, CommandList,
		FMenuExtensionDelegate::CreateRaw(this, &FChapter10EditorModule::AddMenuExtension));
	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(ToolbarExtender);

	IAssetTools& AssetTools =
		FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	auto Actions = MakeShareable(new FMyCustomAssetActions);
	AssetTools.RegisterAssetTypeActions(Actions);
	CreatedAssetTypeActions.Add(Actions);

	DisplayTestCommand = IConsoleManager::Get().
		RegisterConsoleCommand(TEXT("DisplayTestCommandWindow"), TEXT("test"),
			FConsoleCommandDelegate::CreateRaw(this,
				&FChapter10EditorModule::DisplayWindow,
				FString(TEXT("TestCommand Window"))), ECVF_Default);
	DisplayUserSpecifiedWindow = IConsoleManager::Get().
		RegisterConsoleCommand(TEXT("DisplayWindow"), TEXT("test"),
			FConsoleCommandWithArgsDelegate::CreateLambda(
				[&](const TArray< FString >& Args) {
		FString WindowTitle;
		for (FString Arg : Args) {
			WindowTitle += Arg;
			WindowTitle.AppendChar(' ');
		}
		this->DisplayWindow(WindowTitle);
	}
	), ECVF_Default);


	PinFactory = MakeShareable(new FMyCustomAssetPinFactory());
	FEdGraphUtilities::RegisterVisualPinFactory(PinFactory);
}

void FChapter10EditorModule::ShutdownModule() {
	ToolbarExtender->RemoveExtension(Extension.ToSharedRef());
	Extension.Reset();
	ToolbarExtender.Reset();

	IAssetTools& AssetTools =
		FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	for (auto Action : CreatedAssetTypeActions) {
		AssetTools.UnregisterAssetTypeActions(Action.ToSharedRef());

	}


	if (DisplayTestCommand) {
		IConsoleManager::Get().UnregisterConsoleObject(DisplayTestCommand);
		DisplayTestCommand = nullptr;
	}
	if (DisplayUserSpecifiedWindow) {
		IConsoleManager::Get().UnregisterConsoleObject(DisplayUserSpecifiedWindow);
		DisplayUserSpecifiedWindow = nullptr;
	}

	FEdGraphUtilities::UnregisterVisualPinFactory(PinFactory);
	PinFactory.Reset();
}
