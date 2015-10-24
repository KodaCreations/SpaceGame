// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Star.h"
#include "GameFramework/Actor.h"
#include "Links.generated.h"
UCLASS()
class SPACEGAMEMOVEMENT_API ALinks : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	ALinks();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	void AddLink(AStar* s1, AStar* s2);

private:
	AStar** stars;
	bool** links;
	int nbrOfStars;

	bool StarInMatrix(AStar* star);
	void AddStarToMatrix(AStar* star);
};
