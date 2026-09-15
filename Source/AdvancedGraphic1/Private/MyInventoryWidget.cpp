// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInventoryWidget.h"

void UMyInventoryWidget::UpdateWeight(float CurrentWeight, float MaxWeight)
{
	FString NewWeightText = ("Weight: " + UMyBlueprintFunctionLibrary::ConvertFloatToTwoDecimalsString(CurrentWeight) + " / " + UMyBlueprintFunctionLibrary::ConvertFloatToTwoDecimalsString(MaxWeight) + " lbs"); 
	WeightLimitText->SetText(FText::FromString(NewWeightText));
	WeightLimit->SetPercent(CurrentWeight/MaxWeight);
}

void UMyInventoryWidget::FailWeight()
{
	
}

