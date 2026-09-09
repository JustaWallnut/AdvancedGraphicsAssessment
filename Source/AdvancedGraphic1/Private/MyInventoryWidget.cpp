// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInventoryWidget.h"

FString UMyInventoryWidget::ConvertFloatToTwoDecimalsString(float Number)
{
	return FString::SanitizeFloat(FMath::TruncToFloat(Number*100)/100);
}

void UMyInventoryWidget::UpdateWeight(float CurrentWeight, float MaxWeight)
{
	FString NewWeightText = ("Weight: " + ConvertFloatToTwoDecimalsString(CurrentWeight) + " / " + ConvertFloatToTwoDecimalsString(MaxWeight) + " lbs"); 
	WeightLimitText->SetText(FText::FromString(NewWeightText));
	WeightLimit->SetPercent(CurrentWeight/MaxWeight);
}

void UMyInventoryWidget::FailWeight()
{
	
}

