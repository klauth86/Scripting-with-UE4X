// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Chapter10Editor : ModuleRules
{
	public Chapter10Editor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] {
			"Core", "CoreUObject", "Engine", "InputCore", "RHI", "RenderCore", "MainFrame", "AssetTools",
			"AppFramework", "PropertyEditor" });

		PublicDependencyModuleNames.AddRange(new string[] { "Chapter10" });

		PrivateDependencyModuleNames.AddRange(new string[] { "UnrealEd", "Slate", "SlateCore", "EditorStyle",
		"GraphEditor", "BlueprintGraph" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
