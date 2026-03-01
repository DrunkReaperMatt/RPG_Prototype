// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "StateMachineBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class STATEMACHINE_API UStateMachineBase : public UObject
{
	GENERATED_BODY()

public:
	UStateMachineBase();

	UPROPERTY(EditDefaultsOnly, Category = "State Machine")
	FString Name;

	// TODO Change subclass to actual node and edge
	UPROPERTY(EditDefaultsOnly, Category= "State Machine")
	TSubclassOf<UObject> NodeType;

	UPROPERTY(EditDefaultsOnly, Category= "State Machine")
	TSubclassOf<UObject> EdgeType;
	//TODO End

	// TODO Add Root Nodes
	UPROPERTY(BlueprintReadOnly, Category = "State Machine")
	TArray<UGenericGraphNode*> RootNodes;

	UPROPERTY(BlueprintReadOnly, Category = "State Machine")
	TArray<UGenericGraphNode*> AllNodes; 
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "State Machine")
	FGameplayTagContainer GraphTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "State Machine")
	bool bEdgeEnabled;

	UFUNCTION(BlueprintCallable, Category = "State Machine")
	void Print(bool ToConsole = true, bool ToScreen = true);

	UFUNCTION(BlueprintCallable, Category = "State Machine")
	int GetLevelNum() const;

	UFUNCTION(BlueprintCallable, Category = "State Machine")
	void GetNodesByLevel(int Level, TArray<UGenericGraphNode*>& Nodes);

	void ClearGraph();

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	UEdGraph* EdGraph;

	UPROPERTY(EditDefaultsOnly, Category= "State Machine Editor")
	bool bCanRenameNode;
	UPROPERTY(EditDefaultsOnly, Category = "State Machine Editor")
	bool bCanBeCyclical;
#endif
	
};
