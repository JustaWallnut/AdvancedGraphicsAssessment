// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

void UMyBlueprintFunctionLibrary::DealDamageHitbox(UShapeComponent* TargetCollision, const float Damage)
{
	if (TargetCollision)
	{
		TArray<AActor*> OverlapActors;
		TargetCollision->GetOverlappingActors(OverlapActors);
	
		for (AActor* Actor : OverlapActors)
		{
			if (Actor->Implements<UDamageInterface>())
			{
				IDamageInterface::Execute_TakeDamage(Actor, Damage);
			}
		}
	}
}

FVector2D UMyBlueprintFunctionLibrary::GetRandomPosAlongRadius(float Radius, FVector Origin)
{
	float Location2DX = (UKismetMathLibrary::DegCos(UKismetMathLibrary::RandomFloatInRange(0.0f, 360.0f)) * Radius) + Origin.X;
	float Location2DY = (UKismetMathLibrary::DegSin(UKismetMathLibrary::RandomFloatInRange(0.0f, 360.0f)) * Radius) + Origin.Y;
	return FVector2D(Location2DX, Location2DY);
}