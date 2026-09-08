// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy1.h"
#include "DamageStateComponent.h"
#include "ObjectEnemy1.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDGRAPHIC1_API AObjectEnemy1 : public AEnemy1
{
	GENERATED_BODY()
	
public:
	AObjectEnemy1();
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	UDamageStateComponent* DamageStateComponent;

public:
		
	virtual void TakeDamage_Implementation (float Damage) override;
	
};
