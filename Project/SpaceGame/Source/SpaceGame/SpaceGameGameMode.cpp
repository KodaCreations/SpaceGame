// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceGame.h"
#include "SpaceGameGameMode.h"
#include "MouseController.h"

ASpaceGameGameMode::ASpaceGameGameMode()
{
	//this->PlayerControllerClass = AMouseController::StaticClass();
}
void ASpaceGameGameMode::BeginPlay()
{
	Super::BeginPlay();
	for (TActorIterator<AStar> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AStar* newStar = *ActorItr;
		stars.Add(newStar);
		switch (newStar->ownedBy)
		{
		case OwnedBy::Player1:
			playerHomePlanet = *ActorItr;
			break;
		case OwnedBy::Player2:
			aiHomePlanet = *ActorItr;
			CreateEnemyAI();
			break;
		case OwnedBy::Neutral:
			break;
		default:
			break;
		}
	}
	playerShipType = (AShip*)GetWorld()->SpawnActor(playerShipBluePrint, NULL, NULL);
	aiShipType = (AShip*)GetWorld()->SpawnActor(aiShipBluePrint, NULL, NULL);
}
AShip* ASpaceGameGameMode::GetShipType(OwnedBy ownedBy)
{
	switch (ownedBy)
	{
	case OwnedBy::Player1:
		return playerShipType;
	case OwnedBy::Player2:
		return aiShipType;
	case OwnedBy::Neutral:
	default:
		return NULL;
	}
}

void ASpaceGameGameMode::CreateEnemyAI()
{
	//AEnemyAI* newEnemyAI = (AEnemyAI*)GetWorld()->SpawnActor(enemyAI, NULL, NULL);
}
void ASpaceGameGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (playerHomePlanet->ownedBy == OwnedBy::Player2)
		playerWon = OwnedBy::Player2;
	else if (aiHomePlanet->ownedBy == OwnedBy::Player1)
		playerWon = OwnedBy::Player1;
}


