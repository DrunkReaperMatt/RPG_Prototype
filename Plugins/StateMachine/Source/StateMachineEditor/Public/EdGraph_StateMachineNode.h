// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"
#include "EdGraph_StateMachineNode.generated.h"

class UStateMachineNodeBase;
class UEdGraph_StateMachine;
class SEdNode_StateMachineNode;

/**
 * 
 */
UCLASS(MinimalAPI)
class UEdNode_StateMachineNode : public UEdGraphNode
{
	GENERATED_BODY()

public:
	UEdNode_StateMachineNode();

	UPROPERTY(VisibleAnywhere, Instanced, Category="StateMachine")
	UStateMachineNodeBase* GraphNode;

	void SetGraphNode(UStateMachineNodeBase* InGraphNode);

	UEdGraph_StateMachine* GetEdGraph();

	SEdNode_StateMachineNode* SEdNode;

	virtual void AllocateDefaultPins() override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual void PrepareForCopying() override;
	virtual void AutowireNewNode(UEdGraphPin* FromPin) override;

	virtual FLinearColor GetBackgroundColor() const;
	virtual UEdGraphPin* GetInputPin() const;
	virtual UEdGraphPin* GetOutputPin() const;

#if WITH_EDITOR
	virtual void PostEditUndo() override;
#endif
};
