// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Star.h"
#include "Pathfinder.generated.h"

UCLASS()
class SPACEGAME_API APathfinder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APathfinder();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	TArray<AActor*> FindShortestPath(AStar* start, AStar* target);
	TArray<AStar*> GetSurroundingStars(AStar* middleStar);
	
private:
	TArray<AStar*> stars;
	TArray<float> proximityMatrix;

	void GenerateProximityMatrix();
};
