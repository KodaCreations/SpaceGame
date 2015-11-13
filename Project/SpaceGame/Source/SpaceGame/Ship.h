// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Ship.generated.h"

UCLASS()
class SPACEGAME_API AShip : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShip();
	float Damage() const { return damage; }
	float Health() const{ return health; }
	float Defence() const{ return defence; }
	float Morale() const{ return morale; }

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
private:
	UPROPERTY(EditAnywhere)
		float damage;
	UPROPERTY(EditAnywhere)
		float health;
	UPROPERTY(EditAnywhere)
		float defence;
	UPROPERTY(EditAnywhere)
		float morale;
};
