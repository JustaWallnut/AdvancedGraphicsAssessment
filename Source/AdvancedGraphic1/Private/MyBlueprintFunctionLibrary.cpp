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