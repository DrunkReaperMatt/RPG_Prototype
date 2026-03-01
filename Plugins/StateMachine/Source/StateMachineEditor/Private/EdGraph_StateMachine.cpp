// Fill out your copyright notice in the Description page of Project Settings.


#include "EdGraph_StateMachine.h"

#include "Editor/StateMachineBase.h"

UEdGraph_StateMachine::UEdGraph_StateMachine()
{
}

void UEdGraph_StateMachine::RebuildStateMachineGraph()
{
}

UStateMachineBase* UEdGraph_StateMachine::GetGraph() const
{
	return CastChecked<UStateMachineBase>(GetOuter());
}

bool UEdGraph_StateMachine::Modify(bool bAlwaysMakeDirty)
{
	return Super::Modify(bAlwaysMakeDirty);
}

void UEdGraph_StateMachine::PostEditUndo()
{
	Super::PostEditUndo();

	NotifyGraphChanged();
}

void UEdGraph_StateMachine::Clear()
{
}

void UEdGraph_StateMachine::SortNodes(UStateMachineNodeBase* RootNode)
{
}
