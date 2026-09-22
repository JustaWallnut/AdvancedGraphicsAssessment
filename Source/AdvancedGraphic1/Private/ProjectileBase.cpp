// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileBase.h"

// Sets default values
AProjectileBase::AProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ProjectileCollision = CreateDefaultSubobject<USphereComponent>("ProjectileCollision");
	ProjectileCollision->SetCollisionProfileName("DynamicBlockAll");
	SetRootComponent(ProjectileCollision);
	
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>("ProjectileMesh");
	ProjectileMesh->SetCollisionProfileName("DynamicBlockAll");
	ProjectileMesh->SetupAttachment(RootComponent);
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	ProjectileMovement->SetUpdatedComponent(RootComponent);
	ProjectileMovement->InitialSpeed = 1000.0f;
	ProjectileMovement->MaxSpeed = 1000.0f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->Bounciness = 0.0f;
	ProjectileMovement->ProjectileGravityScale = 0.0f;
}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProjectileBase::FireProjectile(FVector Direction)
{
	ProjectileMovement->Velocity = Direction * ProjectileMovement->InitialSpeed;
}


// Called every frame
void AProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

