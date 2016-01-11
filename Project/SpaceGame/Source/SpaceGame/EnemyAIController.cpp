// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceGame.h"
#include "EnemyAIController.h"

AEnemyAIController::AEnemyAIController()
{

}
void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	for (TActorIterator<AStar> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AStar* newStar = *ActorItr;
		stars.Add(newStar);
		starValues.Add(0);
	}
	for (TActorIterator<APathfinder> ActorItr(GetWorld()); ActorItr; ++ActorItr) // Find The Pathfinder if already created in the Game
	{
		pathfinder = *ActorItr;
		return;
	}
	pathfinder = (APathfinder*)GetWorld()->SpawnActor(APathfinder::StaticClass(), NULL, NULL);
}

TArray<AStar*> AEnemyAIController::GetStars()
{
	return stars;
}
TArray<AStar*> AEnemyAIController::GetMyStars()
{
	return myStars;
}
TArray<AStar*> AEnemyAIController::GetSurroundingStars()
{
	return surroundingStars;
}

TArray<AStar*> AEnemyAIController::GetSurroundingStarsAt(AStar* star)
{
	return pathfinder->GetSurroundingStars(star);
}

void AEnemyAIController::SendFleetTo(AStar* fromStar, AStar* toStar)
{
	if (pathfinder && fromStar && fromStar->GetFleet())
	{
		TArray<FVector> destinations = pathfinder->FindShortestPath(fromStar, toStar);

		fromStar->GetFleet()->SetDestinations(destinations);
	}
}

TArray<float> AEnemyAIController::GetStarValue()
{
	return starValues;
}
float AEnemyAIController::GetValueOfStar(AStar* star)
{
	float value = 0;
	for (int i = 0; i < stars.Num(); ++i)
	{
		if (stars[i] == star)
		{
			value = starValues[i];
		}
	}
	return value;
}
void AEnemyAIController::ResetValues()
{
	myStars = TArray<AStar*>();
	surroundingStars = TArray<AStar*>();
}

float AEnemyAIController::CalculateValueOfStar(AStar* star, int32 index)
{
	float value = 0;
	switch (star->ownedBy)
	{
	case OwnedBy::Player1:
		CalculateEnemyStar(star);
		break;
	case OwnedBy::Player2:
		return CalculateMyStar(star);
	case OwnedBy::Neutral:
		CalculateNeutralStar(star);
		break;
	default:
		break;
	}
	return 0;
}
void AEnemyAIController::CalculateNeutralStar(AStar* star)
{
	for (int i = 0; i < stars.Num(); ++i)
	{
		if (stars[i] == star)
		{
			TArray<AStar*> testSurroundingStars = pathfinder->GetSurroundingStars(star);
			starValues[i] = 0;

			if (star->GetFleet())
				starValues[i] -= star->GetFleet()->GetSize() * 20;

			for (int j = 0; j < testSurroundingStars.Num(); ++j)
			{
				switch (testSurroundingStars[j]->ownedBy)
				{
				case OwnedBy::Player1:
					starValues[i] -= 20;
					if (testSurroundingStars[j]->GetFleet())
						starValues[i] -= testSurroundingStars[j]->GetFleet()->GetSize();
					break;
				case OwnedBy::Player2:
					starValues[i] += 20;
					if (testSurroundingStars[j]->GetFleet())
						starValues[i] += testSurroundingStars[j]->GetFleet()->GetSize();
					break;
				case OwnedBy::Neutral:
					starValues[i] += 0;
					break;
				default:
					break;
				}
			}
			break;
		}
	}
}
void AEnemyAIController::CalculateEnemyStar(AStar* star)
{
	for (int i = 0; i < stars.Num(); ++i)
	{
		if (stars[i] == star)
		{
			TArray<AStar*> testSurroundingStars = pathfinder->GetSurroundingStars(star);
			starValues[i] = -50;
			for (int j = 0; j < testSurroundingStars.Num(); ++j)
			{
				switch (testSurroundingStars[j]->ownedBy)
				{
				case OwnedBy::Player1:
					starValues[i] -= 20;
					if (testSurroundingStars[j]->GetFleet())
						starValues[i] -= testSurroundingStars[j]->GetFleet()->GetSize();
					break;
				case OwnedBy::Player2:
					starValues[i] += 20;
					if (testSurroundingStars[j]->GetFleet())
						starValues[i] += testSurroundingStars[j]->GetFleet()->GetSize();
					break;
				case OwnedBy::Neutral:
					starValues[i] += 0;
					break;
				default:
					break;
				}
			}
			break;
		}
	}
}
float AEnemyAIController::CalculateMyStar(AStar* star)
{
	float value = 0;
	if (!myStars.Contains(star))
	{
		myStars.Add(star);
	}

	for (int i = 0; i < stars.Num(); ++i)
	{
		if (stars[i] == star)
		{
			TArray<AStar*> testSurroundingStars = pathfinder->GetSurroundingStars(star);
			starValues[i] = 0;
			if (star->GetFleet())
				starValues[i] += star->GetFleet()->GetSize();

			for (int j = 0; j < testSurroundingStars.Num(); ++j)
			{
				switch (testSurroundingStars[j]->ownedBy)
				{
				case OwnedBy::Player1:
					starValues[i] -= 100;
					if (!surroundingStars.Contains(testSurroundingStars[j]))
						surroundingStars.Add(testSurroundingStars[j]);
					if (testSurroundingStars[j]->GetFleet())
						starValues[i] -= testSurroundingStars[j]->GetFleet()->GetSize();
					break;
				case OwnedBy::Player2:
					starValues[i] += 20;
					break;
				case OwnedBy::Neutral:
					starValues[i] += 0;
					if (!surroundingStars.Contains(testSurroundingStars[j]))
						surroundingStars.Add(testSurroundingStars[j]);
					break;
				default:
					break;
				}
			}
			value += starValues[i];
			break;
		}
	}
	return value;
}