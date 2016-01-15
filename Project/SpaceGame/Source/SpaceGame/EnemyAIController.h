// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "Star.h"
#include "Pathfinder.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class SPACEGAME_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()


public:
	AEnemyAIController();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TArray<float> starValues;			// saved values given to the stars
	TArray<AStar*> stars;				// all the stars in the game
	TArray<AStar*> myStars;				// stars that are owned by the AI
	TArray<AStar*> surroundingStars;	// stars that are linked with stars that the player ownes

	UFUNCTION(BlueprintCallable, Category = "Enemy AI")
		TArray<AStar*> GetStars();
	UFUNCTION(BlueprintCallable, Category = "Enemy AI")
		TArray<float> GetStarValue();
	UFUNCTION(BlueprintCallable, Category = "Enemy AI")
		TArray<AStar*> GetMyStars();
	UFUNCTION(BlueprintCallable, Category = "Enemy AI")
		TArray<AStar*> GetSurroundingStars();
	UFUNCTION(BlueprintCallable, Category = "Enemy AI")
		TArray<AStar*> GetSurroundingStarsAt(AStar* star);
	UFUNCTION(BlueprintCallable, Category = "Enemy AI")
		float CalculateValueOfStar(AStar* star, int32 index); // Gives the star a value based on who ownes it and what stars linked with it
	UFUNCTION(BlueprintCallable, Category = "Enemy AI")
		float GetValueOfStar(AStar* star);
	UFUNCTION(BlueprintCallable, Category = "Enemy AI")
		void ResetValues();

	UFUNCTION(BlueprintCallable, Category = "Enemy AI")
		void SendFleetTo(AStar* fromStar, AStar* toStar);

private:
	APathfinder* pathfinder;
	float CalculateMyStar(AStar* star);
	void CalculateEnemyStar(AStar* star);
	void CalculateNeutralStar(AStar* star);
};
