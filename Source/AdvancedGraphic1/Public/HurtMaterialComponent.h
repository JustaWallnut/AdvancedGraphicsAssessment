// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "HurtMaterialComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ADVANCEDGRAPHIC1_API UHurtMaterialComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHurtMaterialComponent();
		
	UPROPERTY()
	TWeakObjectPtr<UMeshComponent> TargetMeshComponent;
	
	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Hurt Effect")
	bool EnableHurtEffect;
	
	UPROPERTY(EditDefaultsOnly, Category="Hurt Effect", meta=(EditCondition = "EnableHurtEffect"))
	FName HurtColorParam;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Hurt Effect", meta=(EditCondition = "EnableHurtEffect"))
	FVector HurtColor;
	
	UPROPERTY(EditDefaultsOnly, Category="Hurt Effect", meta=(EditCondition = "EnableHurtEffect"))
	FName StartTimeParam;
	
	UPROPERTY(EditDefaultsOnly, Category="Hurt Effect", meta=(EditCondition = "EnableHurtEffect"))
	FName DurationParam;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Hurt Effect", meta=(EditCondition = "EnableHurtEffect"))
	float FadeDuration;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DamageState Effect")
	bool EnableDamageStates;
	
	UPROPERTY(EditDefaultsOnly, Category="DamageState Effect", meta=(EditCondition = "EnableDamageStates"))
	FName ProgressParam;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TargetMaterialIndex;
	
	UFUNCTION()
	void StartHurtLogic();
	
	UFUNCTION()
	void StartDamageStateLogic(float FProgress);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
