// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RPG_Prototype : ModuleRules
{
	public RPG_Prototype(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"RPG_Prototype",
			"RPG_Prototype/Variant_Platforming",
			"RPG_Prototype/Variant_Platforming/Animation",
			"RPG_Prototype/Variant_Combat",
			"RPG_Prototype/Variant_Combat/AI",
			"RPG_Prototype/Variant_Combat/Animation",
			"RPG_Prototype/Variant_Combat/Gameplay",
			"RPG_Prototype/Variant_Combat/Interfaces",
			"RPG_Prototype/Variant_Combat/UI",
			"RPG_Prototype/Variant_SideScrolling",
			"RPG_Prototype/Variant_SideScrolling/AI",
			"RPG_Prototype/Variant_SideScrolling/Gameplay",
			"RPG_Prototype/Variant_SideScrolling/Interfaces",
			"RPG_Prototype/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
