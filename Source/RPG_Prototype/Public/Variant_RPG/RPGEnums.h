// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */

USTRUCT(Blueprintable)
struct FStat
{
	GENERATED_BODY()
	
	float MinValue;
	float MinValueMod;
	float MaxValue;
	float MaxValueMod;
	float CurrentValue;
	float CurrentValueMod;
};

USTRUCT(Blueprintable)
struct FAttribute
{
	GENERATED_BODY()
	
	FName Name;
	FText DisplayName;
	FStat Stat;
};

UENUM(Blueprintable)
enum class EEffectMath : uint8
{
	Add,
	Multiply,
	Divide,
	Override
};

UENUM(Blueprintable)
enum class EEffectType : uint8
{
	Instant,
	ForTurns,
	Infinite,
	Temporary
};

UENUM(Blueprintable)
enum class ETargetStat : uint8
{
	MinValue,
	MinValueMod,
	MaxValue,
	MaxValueMod,
	CurrentValue,
	CurrentValueMod
};
