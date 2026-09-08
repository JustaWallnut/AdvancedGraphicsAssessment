// Fill out your copyright notice in the Description page of Project Settings.


#include "HurtMaterialComponent.h"

// Sets default values for this component's properties
UHurtMaterialComponent::UHurtMaterialComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHurtMaterialComponent::BeginPlay()
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
				if (EnableHurtEffect)
				{
					if (HurtColorParam != NAME_None)
					{
						DynamicMaterial->SetVectorParameterValue(HurtColorParam, HurtColor);
					}
					if (DurationParam != NAME_None)
					{
						DynamicMaterial->SetScalarParameterValue(DurationParam, FadeDuration);
					}
				}
			}
		}
	}
	// ...
}

void UHurtMaterialComponent::StartHurtLogic()
{
	if (DynamicMaterial)
	{
		float CurrentTime = GetWorld()->GetTimeSeconds();
		DynamicMaterial->SetScalarParameterValue(StartTimeParam, CurrentTime);
		UE_LOG(LogTemp, Warning, TEXT("HurtMaterial Success!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("HurtMaterial fail!"));
	}
}
void UHurtMaterialComponent::StartDamageStateLogic(float FProgress)
{
	if (DynamicMaterial)
	{
		DynamicMaterial->SetScalarParameterValue(ProgressParam, FProgress);
		UE_LOG(LogTemp, Warning, TEXT("Progress: %f!!!"), FProgress)
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Progress fail!"));
	}
}

// Called every frame
void UHurtMaterialComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

