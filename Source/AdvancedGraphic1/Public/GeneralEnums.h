// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GeneralEnums.generated.h"

UENUM(BlueprintType)
enum class EUpgradeType : uint8
{
	Tool         UMETA (DisplayName="Pickaxe"),
	Inventory    UMETA (DisplayName="WeightLimit"),
	Speed        UMETA (DisplayName="Speed")
};
