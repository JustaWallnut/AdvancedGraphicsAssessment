// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyInventoryWidget.h"
#include "MoneyCounterWidget.h"
#include "ItemCounterWidgetBase.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDGRAPHIC1_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UMyInventoryWidget> InventoryWidgetClass;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UUserWidget> InventoryUI;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UMoneyCounterWidget> MoneyCounterWidgetClass;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UUserWidget> MoneyCounterUI;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UItemCounterWidgetBase> ItemCounterWidgetClass;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UUserWidget> DynamiteCounterUI;
	
protected:
	virtual void BeginPlay() override;
};
