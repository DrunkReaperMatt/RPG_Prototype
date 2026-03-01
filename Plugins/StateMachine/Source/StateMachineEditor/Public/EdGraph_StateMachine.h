// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraph.h"
#include "EdGraph_StateMachine.generated.h"

class UStateMachineBase;
class UStateMachineNodeBase;

class UEdNode_StateMachineNode;
/**
 * 
 */
UCLASS()
class STATEMACHINEEDITOR_API UEdGraph_StateMachine : public UEdGraph
{
	GENERATED_BODY()
	
public:
	UEdGraph_StateMachine();
	
	virtual void RebuildStateMachineGraph();

	UStateMachineBase* GetGraph() const;

	virtual bool Modify(bool bAlwaysMakeDirty = true) override;
	virtual void PostEditUndo() override;

	UPROPERTY(Transient)
	TMap<UStateMachineNodeBase*, UEdNode_StateMachineNode*> NodeMap;

protected:
	void Clear();

	void SortNodes(UStateMachineNodeBase* RootNode);
};
