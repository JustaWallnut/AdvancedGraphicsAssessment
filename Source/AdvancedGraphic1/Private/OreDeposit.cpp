// Fill out your copyright notice in the Description page of Project Settings.


#include "OreDeposit.h"

// Sets default values
AOreDeposit::AOreDeposit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	OreDepositMesh = CreateDefaultSubobject<UStaticMeshComponent>("Body");
	SetRootComponent(OreDepositMesh);
	
	Health = CreateDefaultSubobject<UAC_HealthComponent>("Health");
	Health->MaxHealth = OreHealth;
}

// Called when the game starts or when spawned
void AOreDeposit::BeginPlay()
{
	Super::BeginPlay();
	if (!DepositOreType)
	{
		UE_LOG(LogTemp, Error, TEXT("Ore Type is not set on %s!"), *GetName());
	}
}

void AOreDeposit::TakeDamage_Implementation (float Damage)
{
	if (Health->TakeDamage(Damage))
	{
		Destroy();
	}
	
	
	if (Health->EnableDamageStates)
	{
		Health->OnDamageStateCheck.Broadcast(Health->CurrentHealth);
	}
	
	
	// float SpawnRadius = UKismetMathLibrary::RandomFloatInRange(MinSpawnRadius, MaxSpawnRadius);
	// FVector2D SpawnLocation2D = UMyBlueprintFunctionLibrary::GetRandomPosAlongRadius(SpawnRadius, GetActorLocation());
	// FVector SpawnLocation = FVector(SpawnLocation2D.X, SpawnLocation2D.Y, GetActorLocation().Z + 50);
	// FRotator SpawnRotation(FMath::RandRange(-180.0f, 180.0f), FMath::RandRange(-180.0f, 180.0f), FMath::RandRange(-180.0f, 180.0f));
	// FVector SpawnScale(1.0f, 1.0f, 1.0f);
	// FTransform SpawnTransform = FTransform(SpawnRotation, SpawnLocation, SpawnScale);
	//
	//
	// ASpawnedOre* SpawnedOreChild = GetWorld()->SpawnActorDeferred<ASpawnedOre>(
	// 	ASpawnedOre::StaticClass(),
	// 	SpawnTransform,
	// 	this,
	// 	GetInstigator(),
	// 	ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn,
	// 	ESpawnActorScaleMethod::SelectDefaultAtRuntime
	// );
	//
	// SpawnedOreChild->AssignedOreType = DepositOreType;
	// SpawnedOreChild->FinishSpawning(SpawnTransform);
}

// Called every frame
void AOreDeposit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

