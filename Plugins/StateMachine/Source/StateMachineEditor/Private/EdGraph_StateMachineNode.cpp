// Fill out your copyright notice in the Description page of Project Settings.


#include "EdGraph_StateMachineNode.h"

#include "Editor/StateMachineNodeBase.h"

UEdNode_StateMachineNode::UEdNode_StateMachineNode()
{
	bCanRenameNode = true;
}

void UEdNode_StateMachineNode::SetGraphNode(UStateMachineNodeBase* InGraphNode)
{
	GraphNode = InGraphNode;
}

void UEdNode_StateMachineNode::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, "MultipleNodes", FName(), TEXT("In"));
	CreatePin(EGPD_Output, "MultipleNodes", FName(), TEXT("Out"));
}

FText UEdNode_StateMachineNode::GetNodeTitle(const ENodeTitleType::Type TitleType) const
{
	if (GraphNode == nullptr)
	{
		return Super::GetNodeTitle(TitleType);
	}
	
	return GraphNode->GetNodeTitle();
}

void UEdNode_StateMachineNode::PrepareForCopying()
{
	GraphNode->Rename(nullptr, this, REN_DontCreateRedirectors | REN_DoNotDirty);
}

void UEdNode_StateMachineNode::AutowireNewNode(UEdGraphPin* FromPin)
{
	Super::AutowireNewNode(FromPin);

	if (FromPin != nullptr)
	{
		if (GetSchema()->TryCreateConnection(FromPin, GetInputPin()))
		{
			FromPin->GetOwningNode()->NodeConnectionListChanged();
		}
	}
}

FLinearColor UEdNode_StateMachineNode::GetBackgroundColor() const
{
	return GraphNode == nullptr? FLinearColor::Black : GraphNode->GetBackgroundColor();
}

UEdGraphPin* UEdNode_StateMachineNode::GetInputPin() const
{
	return Pins[0];
}

UEdGraphPin* UEdNode_StateMachineNode::GetOutputPin() const
{
	return Pins[1];
}

void UEdNode_StateMachineNode::PostEditUndo()
{
	UEdGraphNode::PostEditUndo();
}
