// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnedOre.h"

#include "Misc/MapErrors.h"

// Sets default values
ASpawnedOre::ASpawnedOre()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	StaticMeshBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	StaticMeshBody->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	SetRootComponent(StaticMeshBody);
	
	CollectionHitbox = CreateDefaultSubobject<USphereComponent>(TEXT("CollectSphere"));
	CollectionHitbox->SetCollisionProfileName(TEXT("SpawnedOre"));
	CollectionHitbox->SetupAttachment(RootComponent);
	CollectionHitbox->SetSphereRadius(CollectionRadius);
	
	StaticMeshBody->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	StaticMeshBody->SetMobility(EComponentMobility::Movable);
}

// Called when the game starts or when spawned
void ASpawnedOre::BeginPlay()
{
	Super::BeginPlay();
	StaticMeshBody->SetSimulatePhysics(true);
	if (AssignedOreType)
	{
		if (AssignedOreType->OreMesh)
		{
			StaticMeshBody->SetStaticMesh(AssignedOreType->OreMesh);
		}
	}
	
	CollectionHitbox->OnComponentBeginOverlap.AddDynamic(this, &ASpawnedOre::OnOverlapStart);
}

// Called every frame
void ASpawnedOre::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASpawnedOre::OnOverlapStart(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->Implements<UPickupInterface>())
	{
		if (IPickupInterface::Execute_CollectOre(OtherActor, AssignedOreType))
		{
			Destroy();
		}
		
	}
}

