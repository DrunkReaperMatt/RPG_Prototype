// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachineGraphDragConnection.h"
#include "Widgets/SBoxPanel.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/Images/SImage.h"
#include "EdGraph/EdGraph.h"
#include "SGraphPanel.h"
#include "ScopedTransaction.h"
#include "EdGraph_StateMachineNode.h"

TSharedRef<FStateMachineGraphDragConnection> FStateMachineGraphDragConnection::New(
	const TSharedRef<SGraphPanel>& InGraphPanel, const FDraggedPinTable& InStartingPins)
{
	TSharedRef<FStateMachineGraphDragConnection> Operation = MakeShareable(new FStateMachineGraphDragConnection(InGraphPanel, InStartingPins));
	Operation->Construct();

	return Operation;
}

void FStateMachineGraphDragConnection::OnDrop(bool bDropWasHandled, const FPointerEvent& MouseEvent)
{
	GraphPanel.Get()->OnStopMakingConnection();
	
	FGraphEditorDragDropAction::OnDrop(bDropWasHandled, MouseEvent);
}

void FStateMachineGraphDragConnection::HoverTargetChanged()
{
	FGraphEditorDragDropAction::HoverTargetChanged();
}

FReply FStateMachineGraphDragConnection::DroppedOnPin(FVector2D ScreenPosition, FVector2D GraphPosition)
{
	return FGraphEditorDragDropAction::DroppedOnPin(ScreenPosition, GraphPosition);
}

FReply FStateMachineGraphDragConnection::DroppedOnNode(FVector2D ScreenPosition, FVector2D GraphPosition)
{
	return FGraphEditorDragDropAction::DroppedOnNode(ScreenPosition, GraphPosition);
}

FReply FStateMachineGraphDragConnection::DroppedOnPanel(const TSharedRef<SWidget>& Panel, FVector2D ScreenPosition,
	FVector2D GraphPosition, UEdGraph& Graph)
{
	return FGraphEditorDragDropAction::DroppedOnPanel(Panel, ScreenPosition, GraphPosition, Graph);
}

void FStateMachineGraphDragConnection::OnDragged(const class FDragDropEvent& DragDropEvent)
{
	GraphPanel.Get()->OnStopMakingConnection();
	
	FGraphEditorDragDropAction::OnDragged(DragDropEvent);
}

void FStateMachineGraphDragConnection::ValidateGraphPins(TArray<UEdGraphPin*>& OutValidPins)
{
	OutValidPins.Empty(DraggedPins.Num());

	for (const FGraphPinHandle& PinHandle : DraggedPins)
	{
		if (UEdGraphPin* Pin = PinHandle.GetPinObj(*GraphPanel))
		{
			OutValidPins.Add(Pin);
		}
	}
}

FStateMachineGraphDragConnection::FStateMachineGraphDragConnection(const TSharedRef<SGraphPanel>& GraphPanel,
	const FDraggedPinTable& DraggedPins) : GraphPanel(GraphPanel), DraggedPins(DraggedPins), DecoratorAdjust(FSlateApplication::Get().GetCursorSize())
{
	if (DraggedPins.Num() > 0)
	{
		const UEdGraphPin* Pin = FDraggedPinTable::TConstIterator(DraggedPins)->GetPinObj(*GraphPanel);

		if (Pin && Pin->Direction == EGPD_Input)
		{
			DecoratorAdjust *= FVector2D(-1.f, 1.f);
		}
	}

	for (const FGraphPinHandle& DraggedPin : DraggedPins)
	{
		GraphPanel->OnBeginMakingConnection(DraggedPin);
	}
}
