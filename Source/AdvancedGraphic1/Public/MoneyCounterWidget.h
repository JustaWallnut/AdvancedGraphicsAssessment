// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/TimelineComponent.h"
#include "Curves/CurveFloat.h"
#include "MyBlueprintFunctionLibrary.h"
#include "MoneyCounterWidget.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDGRAPHIC1_API UMoneyCounterWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	float CurrentMoney = 0.0f;
	float NewMoney = 0.0f;
	
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	void UpdateMoneyText(float NewMoneyValue);
	
	UPROPERTY(meta=(BindWidget))
	UTextBlock* MoneyTextBlock;
	
protected:
	FTimeline MoneyTimeline;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCurveFloat* AnimCurve;
	
	UFUNCTION()
	void TimelineUpdated(float Value);
};
