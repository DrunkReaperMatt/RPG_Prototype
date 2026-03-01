// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachineEditor/Public/StateMachineEditorModule.h"

#include "AssetToolsModule.h"

IMPLEMENT_GAME_MODULE(FStateMachineEditorModule, StateMachineEditor);

void FStateMachineEditorModule::StartupModule()
{

	IAssetTools & AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	StateMachineAssetCategoryBit = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("StateMachine")), FText::FromString("StateMachine"));
	//RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_GenericGraph(StateMachineAssetCategoryBit)));
}

void FStateMachineEditorModule::ShutdownModule()
{
}

void FStateMachineEditorModule::RegisterAssetTypeAction(IAssetTools& AssetTools, const TSharedRef<IAssetTypeActions>& Action)
{
	AssetTools.RegisterAssetTypeActions(Action);
	CreatedAssetTypeActions.Add(Action);
}
