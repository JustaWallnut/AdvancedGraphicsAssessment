// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UpgradesInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UUpgradesInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ADVANCEDGRAPHIC1_API IUpgradesInterface
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, meta=(ReturnDisplayName="Success"))
	bool UpgradeTool(float Strength, float Cost);
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, meta=(ReturnDisplayName="Success"))
	bool UpgradeInventory(float Strength, float Cost);
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, meta=(ReturnDisplayName="Success"))
	bool UpgradeSpeed(float Strength, float Cost);
	
	
};
