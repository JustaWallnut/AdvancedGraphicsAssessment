// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDamageStateDelegate, float, NewHealth);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDeathDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ADVANCEDGRAPHIC1_API UAC_HealthComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this component's properties
	UAC_HealthComponent();
	
	UPROPERTY(BlueprintAssignable)
	FDamageStateDelegate OnDamageStateCheck;
	
	UPROPERTY(BlueprintAssignable)
	FDeathDelegate OnDeath;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Health")
	float MaxHealth = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Health")
	float CurrentHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DamageStates")
	bool EnableDamageStates = false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="DamageStates", meta=(EditCondition = "EnableDamageStates"))
	TArray<float> DamageStateThresholds;
	
	UPROPERTY(BlueprintReadWrite, Category="DamageStates", meta=(EditCondition = "EnableDamageStates"))
	TMap<float, bool> DamageThresholdChecks;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void CheckDamageStates();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION(BlueprintCallable, meta=(ReturnDisplayName="isDead"))
    virtual bool TakeDamage(float Damage);
	
	UFUNCTION(BlueprintCallable)
	void ReturnToFullHealth();
};
