// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StateMachineNodeBase.generated.h"

class UStateMachineBase;


/**
 * 
 */
UENUM(BlueprintType)
enum class ENodeLimitw : uint8
{
	Unlimited,
	Limited
};

UCLASS(Blueprintable)
class STATEMACHINE_API UStateMachineNodeBase : public UObject
{
	GENERATED_BODY()

public:
	UStateMachineNodeBase();

	UPROPERTY(VisibleDefaultsOnly, Category = "StateMachineNode")
	UStateMachineBase* Graph;

	UPROPERTY(BlueprintReadOnly, Category = "StateMachineNode")
	TArray<UStateMachineNodeBase*> ParentNodes;

	UPROPERTY(BlueprintReadOnly, Category = "StateMachineNode")
	TArray<UStateMachineNodeBase*> ChildNodes;

	UPROPERTY(BlueprintReadOnly, Category = "StateMachineNode")
	TMap<UStateMachineNodeBase*, UObject*> Edges;

	UFUNCTION(BlueprintCallable, Category = "StateMachineNode")
	virtual UStateMachineBase* GetEdge(UStateMachineNodeBase* ChildNode);

	UFUNCTION(BlueprintCallable, Category = "StateMachineNode")
	bool IsLeafNode() const;

	UFUNCTION(BlueprintCallable, Category = "StateMachineNode")
	UStateMachineBase* GetGraph() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "StateMachineNode")
	FText GetDescription() const;

	virtual FText GetDescription_Implementation() const;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category = "StateMachineNode_Editor")
	FText NodeTitle;

	UPROPERTY(VisibleDefaultsOnly, Category = "StateMachineNode_Editor")
	TSubclassOf<UStateMachineBase> CompatibleGraphType;

	UPROPERTY(EditDefaultsOnly, Category = "StateMachineNode_Editor")
	FLinearColor BackgroundColor;

	UPROPERTY(EditDefaultsOnly, Category = "StateMachineNode_Editor")
	FText ContextMenuName;
	
	UPROPERTY(EditDefaultsOnly, Category = "StateMachineNode_Editor")
	ENodeLimitw ParentLimitType;

	UPROPERTY(EditDefaultsOnly, Category = "StateMachineNode_Editor" ,meta = (ClampMin = "0",EditCondition = "ParentLimitType == ENodeLimitw::Limited", EditConditionHides))
	int32 ParentLimit;

	UPROPERTY(EditDefaultsOnly, Category = "StateMachineNode_Editor")
	ENodeLimitw ChildrenLimitType;

	UPROPERTY(EditDefaultsOnly, Category = "StateMachineNode_Editor" ,meta = (ClampMin = "0",EditCondition = "ChildrenLimitType == ENodeLimitw::Limited", EditConditionHides))
	int32 ChildrenLimit;
#endif

#if WITH_EDITOR
	virtual bool IsNameEditable() const;

	virtual FLinearColor GetBackgroundColor() const;

	virtual FText GetNodeTitle() const;

	virtual void SetNodeTitle(const FText& NewTitle);

	virtual bool CanCreateConnection(UStateMachineNodeBase* Other, FText& ErrorMessage);

	virtual bool CanCreateConnectionTo(UStateMachineNodeBase* Other, int32 NumberOfChildrenNodes, FText& ErrorMessage);
	virtual bool CanCreateConnectionFrom(UStateMachineNodeBase* Other, int32 NumberOfParentNodes, FText& ErrorMessage);
#endif
};
