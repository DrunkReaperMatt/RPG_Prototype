// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MannequinnFantasy : ModuleRules
{
	public MannequinnFantasy(ReadOnlyTargetRules Target) : base(Target)
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
			"Slate",
			"GameplayAbilities",
            "GameplayTags",
            "GameplayTasks"            
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"MannequinnFantasy",
			"MannequinnFantasy/Variant_Platforming",
			"MannequinnFantasy/Variant_Platforming/Animation",
			"MannequinnFantasy/Variant_Combat",
			"MannequinnFantasy/Variant_Combat/AI",
			"MannequinnFantasy/Variant_Combat/Animation",
			"MannequinnFantasy/Variant_Combat/Gameplay",
			"MannequinnFantasy/Variant_Combat/Interfaces",
			"MannequinnFantasy/Variant_Combat/UI",
			"MannequinnFantasy/Variant_SideScrolling",
			"MannequinnFantasy/Variant_SideScrolling/AI",
			"MannequinnFantasy/Variant_SideScrolling/Gameplay",
			"MannequinnFantasy/Variant_SideScrolling/Interfaces",
			"MannequinnFantasy/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
