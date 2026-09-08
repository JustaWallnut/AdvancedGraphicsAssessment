// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "DamageStateComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ADVANCEDGRAPHIC1_API UDamageStateComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDamageStateComponent();
	
	UPROPERTY()
	TWeakObjectPtr<UMeshComponent> TargetMeshComponent;
	
	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial;
	
	UPROPERTY(EditDefaultsOnly)
	FName ProgressParam;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TargetMaterialIndex;
	
	UFUNCTION()
	void UpdateDamageState(float FProgress);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
