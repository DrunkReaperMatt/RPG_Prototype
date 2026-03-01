// Fill out your copyright notice in the Description page of Project Settings.


#include "Editor/StateMachineNodeBase.h"

#include "MovieSceneTimeHelpers.h"
#include "Editor/StateMachineBase.h"

UStateMachineNodeBase::UStateMachineNodeBase()
{
#if WITH_EDITORONLY_DATA
	CompatibleGraphType = UStateMachineBase::StaticClass();

	BackgroundColor = FLinearColor::Yellow;
#endif
}

UStateMachineBase* UStateMachineNodeBase::GetEdge(UStateMachineNodeBase* ChildNode)
{
	return nullptr;
}

bool UStateMachineNodeBase::IsLeafNode() const
{
	return ChildNodes.Num() == 0;
}

UStateMachineBase* UStateMachineNodeBase::GetGraph() const
{
	return Graph;
}

FText UStateMachineNodeBase::GetDescription_Implementation() const
{
	return FText::FromString("State Machine Graph Node");
}

bool UStateMachineNodeBase::IsNameEditable() const
{
	return true;
}

FLinearColor UStateMachineNodeBase::GetBackgroundColor() const
{
	return BackgroundColor;
}

FText UStateMachineNodeBase::GetNodeTitle() const
{
	return NodeTitle.IsEmpty() ? GetDescription() : NodeTitle;
}

void UStateMachineNodeBase::SetNodeTitle(const FText& NewTitle)
{
	NodeTitle = NewTitle;
}

bool UStateMachineNodeBase::CanCreateConnection(UStateMachineNodeBase* Other, FText& ErrorMessage)
{
	return true;
}

bool UStateMachineNodeBase::CanCreateConnectionTo(UStateMachineNodeBase* Other, int32 NumberOfChildrenNodes,
	FText& ErrorMessage)
{
	if (ChildrenLimitType == ENodeLimitw::Limited && NumberOfChildrenNodes >= ChildrenLimit)
	{
		ErrorMessage = FText::FromString("Children limit exceeded");
		return false;
	}

	return CanCreateConnection(Other, ErrorMessage);
}

bool UStateMachineNodeBase::CanCreateConnectionFrom(UStateMachineNodeBase* Other, int32 NumberOfParentNodes,
	FText& ErrorMessage)
{
	if (ParentLimitType == ENodeLimitw::Limited && NumberOfParentNodes >= ParentLimit)
	{
		ErrorMessage = FText::FromString("Parent limit exceeded");
		return false;
	}

	return true;	
}
