// Fill out your copyright notice in the Description page of Project Settings.


#include "MoneyCounterWidget.h"

void UMoneyCounterWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	if (AnimCurve)
	{
		FOnTimelineFloat ProgressFunc;
		ProgressFunc.BindUFunction(this, FName("TimelineUpdated"));
		MoneyTimeline.AddInterpFloat(AnimCurve, ProgressFunc);
		
		MoneyTimeline.SetLooping(false);
	}
}

void UMoneyCounterWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	MoneyTimeline.TickTimeline(InDeltaTime);
}

void UMoneyCounterWidget::TimelineUpdated(float Value)
{
	float AlphaMoneyValue = FMath::Lerp(CurrentMoney, NewMoney, Value);
	FString MoneyText = FString::Printf(TEXT("%.2f"), AlphaMoneyValue);
	FString String = ("$" + MoneyText);
	MoneyTextBlock->SetText(FText::FromString(String));
}

void UMoneyCounterWidget::UpdateMoneyText(float NewMoneyValue)
{
	CurrentMoney = NewMoney;
	NewMoney = NewMoneyValue;
	MoneyTimeline.PlayFromStart();
}