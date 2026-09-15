// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OreType.h"
#include "Kismet/KismetMathLibrary.h"
#include "DamageInterface.h"
#include "Components/ShapeComponent.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDGRAPHIC1_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable)
	static void DealDamageHitbox(UShapeComponent* TargetCollision, float Damage);
	
	UFUNCTION(BlueprintCallable)
	static FVector2D GetRandomPosAlongRadius(float Radius, FVector Origin);
	
	UFUNCTION(BlueprintCallable)
	static float CalculateTotalFromOres (TArray<UOreType*> Ores);
	
	UFUNCTION(BlueprintCallable)
	static FString ConvertFloatToTwoDecimalsString(float Number);
};
