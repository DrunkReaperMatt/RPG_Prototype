// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_RPG/Public/AbilitySystemComponent.h"

#include "TurnEffect.h"

// Sets default values for this component's properties
UAbilitySystemComponent::UAbilitySystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UAbilitySystemComponent::ApplyEffectToTarget_CPP(FName AttributeToEffect,
	float Magnitude, EEffectType EffectType, ETargetStat TargetStat, EEffectMath EffectMath, int EffectTurnCounter)
{
	UTurnEffect* TurnEffect = NewObject<UTurnEffect>(this, UTurnEffect::StaticClass());
	TurnEffect->Initialize(this, AttributeToEffect, EffectType, TargetStat, EffectMath, EffectTurnCounter);

	// Bind Event

	switch (EffectType)
	{
	case EEffectType::Instant:
	case EEffectType::ForTurns:
		TurnEffect->ApplyEffect();
		break;
	case EEffectType::Infinite:
	case EEffectType::Temporary:
		ActiveEffects.AddUnique(*TurnEffect);
		TurnEffect->ApplyEffect();
		break;
	}

	
}

// Called every frame
void UAbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

