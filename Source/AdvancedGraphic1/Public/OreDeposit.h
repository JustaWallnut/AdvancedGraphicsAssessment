// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageInterface.h"
#include "AC_HealthComponent.h"
#include "OreType.h"
#include "SpawnedOre.h"
#include "MyBlueprintFunctionLibrary.h"
#include "OreDeposit.generated.h"

UCLASS()
class ADVANCEDGRAPHIC1_API AOreDeposit : public AActor, public IDamageInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOreDeposit();
	
	virtual void TakeDamage_Implementation (float Damage) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float OreHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UOreType* DepositOreType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MinSpawnRadius = 10.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxSpawnRadius = 100.0f;
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	UStaticMeshComponent* OreDepositMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	UAC_HealthComponent* Health;
};
