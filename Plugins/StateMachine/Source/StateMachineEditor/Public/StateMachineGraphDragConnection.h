// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Input/DragAndDrop.h"
#include "Input/Reply.h"
#include "Widgets/SWidget.h"
#include "SGraphPin.h"
#include "GraphEditorDragDropAction.h"

class SGraphPanel;
class UEdGraph;

/**
 * 
 */
class FStateMachineGraphDragConnection : public FGraphEditorDragDropAction
{
public:
	DRAG_DROP_OPERATOR_TYPE(FDragConnection, FGraphEditorDragDropAction)

	typedef TArray<FGraphPinHandle> FDraggedPinTable;
	static TSharedRef<FStateMachineGraphDragConnection> New(const TSharedRef<SGraphPanel>& InGraphPanel, const FDraggedPinTable& InStartingPins);
	
	// FDragDropOperation interface
	virtual void OnDrop(bool bDropWasHandled, const FPointerEvent& MouseEvent) override;
	// End of FDragDropOperation interface

	// FGraphEditorDragDropAction interface
	virtual void HoverTargetChanged() override;
	virtual FReply DroppedOnPin(FVector2D ScreenPosition, FVector2D GraphPosition) override;
	virtual FReply DroppedOnNode(FVector2D ScreenPosition, FVector2D GraphPosition) override;
	virtual FReply DroppedOnPanel(const TSharedRef< SWidget >& Panel, FVector2D ScreenPosition, FVector2D GraphPosition, UEdGraph& Graph) override;
	virtual void OnDragged(const FDragDropEvent& DragDropEvent) override;
	// End of FGraphEditorDragDropAction interface

	virtual void ValidateGraphPins(TArray<UEdGraphPin*>& OutValidPins);

protected:
	FStateMachineGraphDragConnection(const TSharedRef<SGraphPanel>& GraphPanel, const FDraggedPinTable& DraggedPins);

	TSharedPtr<SGraphPanel> GraphPanel;
	FDraggedPinTable DraggedPins;

	FVector2D DecoratorAdjust;
};
