// Fill out your copyright notice in the Description page of Project Settings.


#include "OreSeller.h"

// Sets default values
AOreSeller::AOreSeller()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DetectionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Detection"));
	DetectionBox->SetCollisionProfileName(TEXT("SpawnedOre"));
}

// Called when the game starts or when spawned
void AOreSeller::BeginPlay()
{
	Super::BeginPlay();
	
	DetectionBox->OnComponentBeginOverlap.AddDynamic(this, &AOreSeller::OnOverlapStart);
}

// Called every frame
void AOreSeller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOreSeller::OnOverlapStart(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->GetClass() == UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetClass())
	{
		if (IMoneyInterface::Execute_SellOres(OtherActor))
		{
			
		}
	}
}

