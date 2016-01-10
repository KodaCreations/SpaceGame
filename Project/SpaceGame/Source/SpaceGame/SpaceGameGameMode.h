// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "Star.h"
#include "EnemyAI.h"
#include "SpaceGameGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SPACEGAME_API ASpaceGameGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	ASpaceGameGameMode();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AEnemyAI> enemyAI;

	UPROPERTY(VisibleAnywhere)
		TArray<AStar*> stars;
	UPROPERTY(VisibleAnywhere)
		AStar* playerHomePlanet;
	UPROPERTY(VisibleAnywhere)
		AStar* aiHomePlanet;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AShip> playerShipBluePrint;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AShip> aiShipBluePrint;
	


	AShip* GetShipType(OwnedBy ownedBy);
private:
	void CreateEnemyAI();
	AShip* playerShipType;
	AShip* aiShipType;
};
