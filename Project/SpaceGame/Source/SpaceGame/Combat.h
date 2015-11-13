// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fleet.h"
#include "GameFramework/Actor.h"
#include "Combat.generated.h"

UCLASS()
class SPACEGAME_API ACombat : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACombat();
	void Inizialize(AFleet* fleet1, AFleet* fleet2);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere)
		AFleet* playerFleet;
	UPROPERTY(EditAnywhere)
		AFleet* aiFleet;
private:
	void FleetCombat(float DeltaTime);
	void CheckIfDead();
};
