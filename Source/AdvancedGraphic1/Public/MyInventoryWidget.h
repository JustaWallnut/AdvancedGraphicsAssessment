// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "MyInventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDGRAPHIC1_API UMyInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta=(BindWidget))
	UProgressBar* WeightLimit;
	
	UPROPERTY(meta=(BindWidget))
	UTextBlock* WeightLimitText;
	
	static FString ConvertFloatToTwoDecimalsString(float Number);
	
	UFUNCTION(BlueprintCallable)
	void UpdateWeight(float CurrentWeight, float MaxWeight);
	
	UFUNCTION(BlueprintCallable)
	void FailWeight();
};
