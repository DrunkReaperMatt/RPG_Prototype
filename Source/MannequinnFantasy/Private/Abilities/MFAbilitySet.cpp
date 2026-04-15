// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/MFAbilitySet.h"

#include "AssetDefinitionAssetInfo.h"
#include "Net/UnrealNetwork.h"

UMFAbilitySet::UMFAbilitySet()
{
	InitHealth(100);
	InitMaxHealth(100);
}

void UMFAbilitySet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(UMFAbilitySet, Health);
	DOREPLIFETIME(UMFAbilitySet, MaxHealth);
}

void UMFAbilitySet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	UE_LOG(LogTemp, Warning, TEXT("PreChange Attribute: '%s'"), *Attribute.AttributeName);
	
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
	}
	
	Super::PreAttributeChange(Attribute, NewValue);
}

void UMFAbilitySet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);
	
	UE_LOG(LogTemp, Warning, TEXT("PostChange: Attribute '%s' changed %.2f -> %.2f"), *Attribute.AttributeName, OldValue, NewValue);
	
	if (Attribute == GetHealthAttribute())
	{
		OnHealthChange.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetMaxHealthAttribute())
	{
		const float CurrentHealth = GetHealth();
		
		OnHealthChange.Broadcast(this, CurrentHealth, CurrentHealth);
	}
}
