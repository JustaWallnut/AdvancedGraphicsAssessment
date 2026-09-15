// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "MoneyInterface.h"
#include "Components/BoxComponent.h"
#include "OreSeller.generated.h"

UCLASS()
class ADVANCEDGRAPHIC1_API AOreSeller : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOreSeller();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION() void OnOverlapStart(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	UBoxComponent* DetectionBox;
};
