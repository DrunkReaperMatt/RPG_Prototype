// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Variant_RPG/RPGEnums.h"
#include "TurnEffect.generated.h"

class UAbilitySystemComponent;

/**
 * 
 */
DECLARE_MULTICAST_DELEGATE_OneParam(FUpdateAttribute, FAttribute&);

UCLASS()
class RPG_PROTOTYPE_API UTurnEffect : public UObject
{
	GENERATED_BODY()

	FUpdateAttribute UpdateAttribute;

public:
	UFUNCTION(BlueprintCallable, Category = "TurnEffect")
	void DoEffect();

	UFUNCTION(BlueprintCallable, Category = "TurnEffect")
	float CalculateNewValue(float CurrentValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "TurnEffect")
	void ApplyEffect();

	UFUNCTION(BlueprintImplementableEvent, Category = "TurnEffect")
	void EndEffect();

	void Initialize(UAbilitySystemComponent* TargetComponent, FName AttributeToEffect, EEffectType EffectType, ETargetStat TargetStat, EEffectMath EffectMath, int EffectTurnCounter = 0);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TurnEffect", meta=(AllowPrivateAccess=true))
	float AbsoluteChange;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TurnEffect")
	UAbilitySystemComponent* TargetComponent;

	UPROPERTY(editAnywhere, BlueprintReadWrite, Category = "TurnEffect")
	FName AttributeToEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TurnEffect")
	float Magnitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TurnEffect")
	int EffectTurnCounter;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TurnEffect")
	EEffectType EffectType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TurnEffect")
	ETargetStat TargetStat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TurnEffect")
	EEffectMath EffectMath;
};
