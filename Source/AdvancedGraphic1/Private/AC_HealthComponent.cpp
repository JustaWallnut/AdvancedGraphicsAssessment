// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_HealthComponent.h"

// Sets default values for this component's properties
UAC_HealthComponent::UAC_HealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_HealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
	// ...
	
}

bool UAC_HealthComponent::TakeDamage(float Damage)
{
	float RemainingHealth = CurrentHealth - Damage;
	if (RemainingHealth <= 0.0f)
	{
		CurrentHealth = 0.0f;
		return true;
	}
	else
	{
		CurrentHealth = RemainingHealth;
		return false;
	}
}

// Called every frame
void UAC_HealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

