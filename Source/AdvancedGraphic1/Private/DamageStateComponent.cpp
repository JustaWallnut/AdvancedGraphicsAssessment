// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageStateComponent.h"

// Sets default values for this component's properties
UDamageStateComponent::UDamageStateComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDamageStateComponent::BeginPlay()
{
	Super::BeginPlay();
	if (UMeshComponent* ParentComponent = Cast<UMeshComponent>(GetAttachParent()))
	{
		TargetMeshComponent = ParentComponent;
		if (UMaterialInterface* TargetMaterial = TargetMeshComponent->GetMaterial(TargetMaterialIndex))
		{
			if (!DynamicMaterial)
			{
				UMaterialInstanceDynamic* NewMID = UMaterialInstanceDynamic::Create(TargetMaterial, this);
				TargetMeshComponent->SetMaterial(TargetMaterialIndex, NewMID);
				DynamicMaterial = NewMID;
			}
		}
	}
	// ...
	
}

void UDamageStateComponent::UpdateDamageState(float FProgress)
{
	if (DynamicMaterial && ProgressParam != NAME_None)
	{
		DynamicMaterial->SetScalarParameterValue(ProgressParam, FProgress);
	}
}

// Called every frame
void UDamageStateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

