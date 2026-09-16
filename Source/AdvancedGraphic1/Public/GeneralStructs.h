// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GeneralEnums.h"
#include "GeneralStructs.generated.h"

USTRUCT(BlueprintType)
struct FUpgradeItem
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EUpgradeType UpgradeType = EUpgradeType::Tool;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText UpgradeName = FText::FromString("None");
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UTexture2D* UpgradeIcon;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UMaterialInterface* ShopUpgradeBackground;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float StrengthValue = 1.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Cost = 0.0f;
};


