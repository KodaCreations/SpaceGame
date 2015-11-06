// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Fleet.h"
#include "GameFramework/Actor.h"
#include "Star.generated.h"

UCLASS()
class SPACEGAME_API AStar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStar();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:
	// Stationed fleet
	AFleet *fleet;

	// Production time
	const float prodTime = 3;

	// Fleet creation timer
	float timer;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh;
};
