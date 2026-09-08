// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "MyStaminaBar.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class ADVANCEDGRAPHIC1_API UMyStaminaBar : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UProgressBar> StaminaBar;
	
protected:
	virtual void NativeConstruct() override;
	
};
