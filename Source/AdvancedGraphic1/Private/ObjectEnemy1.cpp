// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectEnemy1.h"

AObjectEnemy1::AObjectEnemy1()
{
	DamageStateComponent = CreateDefaultSubobject<UDamageStateComponent>(TEXT("DamageStateComponent"));
	DamageStateComponent->SetupAttachment(RootComponent);
}


void AObjectEnemy1::TakeDamage_Implementation(const float Damage)
{
	if (Health->TakeDamage(Damage))
	{
		this->Destroy();
		UE_LOG(LogTemp, Warning, TEXT("I HAVE DIED!!!"));
	}
	else
	{
		HurtMaterialComponent->StartHurtLogic();
		DamageStateComponent->UpdateDamageState(Health->CurrentHealth / Health->MaxHealth);
		UE_LOG(LogTemp, Warning, TEXT("Current my health is: %f!!!"), Health->CurrentHealth)
	}
}