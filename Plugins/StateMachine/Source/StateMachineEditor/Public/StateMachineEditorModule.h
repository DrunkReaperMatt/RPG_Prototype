// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "IAssetTools.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

// This class does not need to be modified.

class FStateMachineEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private :
	void RegisterAssetTypeAction(IAssetTools& AssetTools, const TSharedRef<IAssetTypeActions>& Action);

	TArray<TSharedPtr<IAssetTypeActions>> CreatedAssetTypeActions;
	EAssetTypeCategories::Type StateMachineAssetCategoryBit;
	
};

