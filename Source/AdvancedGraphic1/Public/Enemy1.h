// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMesh.h"
#include "Components/BoxComponent.h"
#include "AC_HealthComponent.h"
#include "DamageInterface.h"
#include "Enemy1.generated.h"

UCLASS()
class ADVANCEDGRAPHIC1_API AEnemy1 : public AActor, public IDamageInterface
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	AEnemy1();
	
	virtual void TakeDamage_Implementation (float Damage) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StartingHealth = 100.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial;
	
	UPROPERTY(EditDefaultsOnly)
	FName StartTimeParam;
	
	UPROPERTY(EditDefaultsOnly)
	FName HurtColorParam;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector HurtColor;
	
	UPROPERTY(EditDefaultsOnly)
	FName DurationParam;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FadeDuration;
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	UStaticMeshComponent* StaticMeshBody;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	UBoxComponent* BoxCollision;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	UAC_HealthComponent* Health;
};


