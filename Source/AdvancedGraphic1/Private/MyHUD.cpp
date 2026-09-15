// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"

void AMyHUD::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* PC = Cast<APlayerController>(GetOwner());
	InventoryUI = CreateWidget<UUserWidget>(PC, InventoryWidgetClass);
	MoneyCounterUI = CreateWidget<UUserWidget>(PC, MoneyCounterWidgetClass);
	
	InventoryUI->AddToPlayerScreen();
	MoneyCounterUI->AddToPlayerScreen();
}

