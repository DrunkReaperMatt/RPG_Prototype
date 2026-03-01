// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ClassViewerFilter.h"
#include "Factories/Factory.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "StateMachineFactory.generated.h"

class UStateMachineBase;
/**
 * 
 */


UCLASS()
class STATEMACHINEEDITOR_API UStateMachineFactory : public UFactory
{
	GENERATED_BODY()

public:
	UStateMachineFactory();

	UPROPERTY(EditAnywhere, Category=DataAsset)
	TSubclassOf<UStateMachineBase> StateMachineClass;

	virtual bool ConfigureProperties() override;
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
