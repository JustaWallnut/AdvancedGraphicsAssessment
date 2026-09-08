// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy1.h"

// Sets default values
AEnemy1::AEnemy1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshBody"));
	StaticMeshBody->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	SetRootComponent(StaticMeshBody);
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	BoxCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	BoxCollision->SetGenerateOverlapEvents(true);
	BoxCollision->SetupAttachment(RootComponent);
	
	Health = CreateDefaultSubobject<UAC_HealthComponent>(TEXT("Health"));
	Health->MaxHealth = StartingHealth;
	
	HurtMaterialComponent = CreateDefaultSubobject<UHurtMaterialComponent>(TEXT("HurtMaterialComponent"));
	HurtMaterialComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemy1::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemy1::TakeDamage_Implementation(const float Damage)
{
	if (Health->TakeDamage(Damage))
	{
		this->Destroy();
		UE_LOG(LogTemp, Warning, TEXT("I HAVE DIED!!!"));
	}
	else
	{
		if (HurtMaterialComponent->EnableHurtEffect)
		{
			HurtMaterialComponent->StartHurtLogic();
		}
		if (HurtMaterialComponent->EnableDamageStates)
		{
			HurtMaterialComponent->StartDamageStateLogic(Health->CurrentHealth / Health->MaxHealth);
		}
		UE_LOG(LogTemp, Warning, TEXT("Current my health is: %f!!!"), Health->CurrentHealth)
	}
}

// Called every frame
void AEnemy1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

