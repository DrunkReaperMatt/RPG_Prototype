// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Variant_RPG/RPGEnums.h"
#include "AbilitySystemComponent.generated.h"


class UTurnEffect;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPG_PROTOTYPE_API UAbilitySystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbilitySystemComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


	UFUNCTION(BlueprintCallable, Category="Ability")
	virtual void ApplyEffectToTarget_CPP(FName AttributeToEffect, float Magnitude, EEffectType EffectType, ETargetStat TargetStat, EEffectMath EffectMath, int EffectTurnCounter = 0);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


public:
	TArray<FAttribute> Attributes;
	TArray<UTurnEffect> ActiveEffects;
};
