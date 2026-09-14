// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "OreType.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDGRAPHIC1_API UOreType : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FString OreName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMesh* OreMesh;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float BaseValue;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float BaseWeight;
};
