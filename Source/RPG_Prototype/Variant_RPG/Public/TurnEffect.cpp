// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_RPG/Public/TurnEffect.h"

#include "AbilitySystemComponent.h"

void UTurnEffect::DoEffect()
{
	check(TargetComponent)

	for (int i = 0; i < TargetComponent->Attributes.Num(); ++i)
	{
		if (auto& Attribute = TargetComponent->Attributes[i]; Attribute.Name == AttributeToEffect)
		{
			switch (TargetStat)
			{
			case ETargetStat::MinValue:
				Attribute.Stat.MinValue = CalculateNewValue(Attribute.Stat.MinValue);
				break;
			case ETargetStat::MinValueMod:
				Attribute.Stat.MinValueMod = CalculateNewValue(Attribute.Stat.MinValueMod);
				break;
			case ETargetStat::MaxValue:
				Attribute.Stat.MaxValue = CalculateNewValue(Attribute.Stat.MaxValue);
				break;
			case ETargetStat::MaxValueMod:
				Attribute.Stat.MaxValueMod = CalculateNewValue(Attribute.Stat.MaxValueMod);
				break;
			case ETargetStat::CurrentValue:
				Attribute.Stat.CurrentValue = CalculateNewValue(Attribute.Stat.CurrentValue);
				break;
			case ETargetStat::CurrentValueMod:
				Attribute.Stat.CurrentValueMod = CalculateNewValue(Attribute.Stat.CurrentValueMod);
				break;
			}

			UpdateAttribute.Broadcast(Attribute);

			return;
		}
	}
}

float UTurnEffect::CalculateNewValue(const float CurrentValue)
{
	float NewValue = 0.f;
	switch (EffectMath)
	{
	case EEffectMath::Add:
		NewValue = Magnitude + CurrentValue;
		break;
	case EEffectMath::Multiply:
		NewValue = Magnitude * CurrentValue;
		break;
	case EEffectMath::Divide:
		NewValue = CurrentValue / Magnitude;
		break;
	case EEffectMath::Override:
		NewValue = CurrentValue;
		break;
	}
	
	AbsoluteChange = Magnitude - CurrentValue;
	
	return NewValue;	
}

void UTurnEffect::Initialize(UAbilitySystemComponent* TargetComponent, FName AttributeToEffect, EEffectType EffectType,
	ETargetStat TargetStat, EEffectMath EffectMath, int EffectTurnCounter):(TargetComponent, AttributeToEffect, EffectType,
		TargetStat, EffectMath, EffectTurnCounter)
{}


