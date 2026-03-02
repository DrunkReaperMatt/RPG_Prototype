// Fill out your copyright notice in the Description page of Project Settings.


#include "Editor/StateMachineBase.h"

//#include "GenericGraphEdge.h"

UStateMachineBase::UStateMachineBase()
{
	// TODO change types to node and edge type
	NodeType = UObject::StaticClass();
	EdgeType = UObject::StaticClass();
	
	bEdgeEnabled = true;
	
#if WITH_EDITORONLY_DATA
	EdGraph = nullptr;
	bCanRenameNode = true;
#endif
}

void UStateMachineBase::Print(bool ToConsole, bool ToScreen)
{
}

int UStateMachineBase::GetLevelNum() const
{
	return 0;
}

void UStateMachineBase::GetNodesByLevel(int Level, TArray<UObject*>& Nodes)
{
}

void UStateMachineBase::ClearGraph()
{

	AllNodes.Empty();
	RootNodes.Empty();
}
