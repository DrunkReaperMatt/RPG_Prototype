// Fill out your copyright notice in the Description page of Project Settings.


#include "Factory/StateMachineFactory.h"
#include "Editor/StateMachineBase.h"

#include "ClassViewerModule.h"
#include "ClassViewerFilter.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Kismet2/SClassPickerDialog.h"

class FAssetClassParentFilters : public IClassViewerFilter
{
public:
	FAssetClassParentFilters()
		: DisallowedClassFlags(CLASS_None), bDisallowBlueprintBase(false)
	{}

	/** All children of these classes will be included unless filtered out by another setting. */
	TSet< const UClass* > AllowedChildrenOfClasses;

	/** Disallowed class flags. */
	EClassFlags DisallowedClassFlags;

	/** Disallow blueprint base classes. */
	bool bDisallowBlueprintBase;

	virtual bool IsClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const UClass* InClass, TSharedRef< FClassViewerFilterFuncs > InFilterFuncs) override
	{
		bool bAllowed= !InClass->HasAnyClassFlags(DisallowedClassFlags)
			&& InFilterFuncs->IfInChildOfClassesSet(AllowedChildrenOfClasses, InClass) != EFilterReturn::Failed;

		if (bAllowed && bDisallowBlueprintBase)
		{
			if (FKismetEditorUtilities::CanCreateBlueprintOfClass(InClass))
			{
				return false;
			}
		}

		return bAllowed;
	}

	virtual bool IsUnloadedClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const TSharedRef< const IUnloadedBlueprintData > InUnloadedClassData, TSharedRef< FClassViewerFilterFuncs > InFilterFuncs) override
	{
		if (bDisallowBlueprintBase)
		{
			return false;
		}

		return !InUnloadedClassData->HasAnyClassFlags(DisallowedClassFlags)
			&& InFilterFuncs->IfInChildOfClassesSet(AllowedChildrenOfClasses, InUnloadedClassData) != EFilterReturn::Failed;
	}	
};


UStateMachineFactory::UStateMachineFactory()
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UStateMachineBase::StaticClass();
}

bool UStateMachineFactory::ConfigureProperties()
{
	StateMachineClass = nullptr;

	FClassViewerModule& ClassViewerModule = FModuleManager::LoadModuleChecked<FClassViewerModule>("ClassViewer");

	FClassViewerInitializationOptions Options;
	Options.Mode = EClassViewerMode::ClassPicker;

#if ENGINE_MAJOR_VERSION < 5
	TSharedPtr<FAssetClassParentFilters> Filter = MakeShareable(new FAssetClassParentFilters);
	Options.ClassFilter = Filter;
#else // #if ENGINE_MAJOR_VERSION < 5
	const TSharedRef<FAssetClassParentFilters> Filter = MakeShared<FAssetClassParentFilters>();
	Options.ClassFilters.Add(Filter);
#endif // #else // #if ENGINE_MAJOR_VERSION < 5

	Filter->DisallowedClassFlags = CLASS_Abstract | CLASS_Deprecated | CLASS_NewerVersionExists | CLASS_HideDropDown;
	Filter->AllowedChildrenOfClasses.Add(UStateMachineBase::StaticClass());

	const FText TitleText = FText::FromString("StateMachine");
	UClass* SelectedClass = nullptr;

	const bool bPressedOk = SClassPickerDialog::PickClass(TitleText, Options, SelectedClass, UStateMachineBase::StaticClass());

	if (bPressedOk)
	{
		StateMachineClass = SelectedClass;
	}

	return bPressedOk;
}

UObject* UStateMachineFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn)
{
	if (StateMachineClass)
	{
		return NewObject<UStateMachineBase>(InParent, StateMachineClass, InName, Flags | RF_Transactional);
	}

	check (InClass->IsChildOf(UStateMachineBase::StaticClass()));
	return NewObject<UObject>(InParent, InClass, InName, Flags | RF_Transactional);
}
