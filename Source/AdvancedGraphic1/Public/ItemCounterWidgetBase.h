// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "ItemCounterWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDGRAPHIC1_API UItemCounterWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
	public:
		UPROPERTY(meta=(BindWidgetOptional))
		UImage* ItemPicture;
	
		UFUNCTION(BlueprintCallable)
		void UpdateItemText(int NewCount);
	private:
		UPROPERTY(meta=(BindWidget))
		UTextBlock* ItemTextCount;
};
