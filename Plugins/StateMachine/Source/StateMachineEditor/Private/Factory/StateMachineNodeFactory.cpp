 // Fill out your copyright notice in the Description page of Project Settings.


#include "Factory/StateMachineNodeFactory.h"

#include "EdGraph_StateMachineNode.h"

 TSharedPtr<SGraphNode> FStateMachineNodeFactory::CreateNode(UEdGraphNode* Node) const
 {
	if (UEdNode_StateMachineNode* SM_Node = Cast<UEdNode_StateMachineNode>(Node))
	{
		return SNew(SEdNode_StateMachineNode, SM_Node);
	}

 	return nullptr;
 }
