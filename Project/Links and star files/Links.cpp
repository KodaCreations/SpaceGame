// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceGameMovement.h"
#include "Links.h"


// Sets default values
ALinks::ALinks()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	stars = nullptr;
	links = nullptr;
	nbrOfStars = 0;
}

// Called when the game starts or when spawned
void ALinks::BeginPlay()
{
	Super::BeginPlay();

	/*DrawDebugLine(GetWorld(), FVector(0, 0, 0), FVector(200, 200, 0), FColor(255, 0, 0), true, -1, 0, 12.333);
	DrawDebugLine(GetWorld(), FVector(200, 200, 0), FVector(700, 500, 0), FColor(255, 0, 0), true, -1, 0, 12.333);
	DrawDebugLine(GetWorld(), FVector(700, 500, 0), FVector(0, 0, 0), FColor(255, 0, 0), true, -1, 0, 12.333);
	DrawDebugLine(GetWorld(), FVector(0, 0, 0), FVector(250, 360, 0), FColor(255, 0, 0), true, -1, 0, 12.333);*/
}

// Called every frame
void ALinks::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Adds a link to the matrix
void ALinks::AddLink(AStar* s1, AStar* s2)
{
	int s1Pos, s2Pos;
	s1Pos = s2Pos = -1;
	
	if (!StarInMatrix(s1))
		AddStarToMatrix(s1);
	if (!StarInMatrix(s2))
		AddStarToMatrix(s2);
	for (int i = 0; i < nbrOfStars; ++i) {
		if (stars[i] == s1)
			s1Pos = i;
		else if (stars[i] == s2)
			s2Pos = i;
		if (s1Pos > 0 && s2Pos > 0)
			break;
	}
	links[s1Pos][s2Pos] = true;
	links[s2Pos][s1Pos] = true;
}

// Checks to make sure the star att position 'star' exists in the matrix
bool ALinks::StarInMatrix(AStar* star)
{
	for (int i = 0; i < nbrOfStars; ++i)
	if (stars[i] == star)
		return true;
	return false;
}

// Adds a star to the matrix
void ALinks::AddStarToMatrix(AStar* star)
{
	AStar** temp = stars;
	bool** tempMatrix = links;

	stars = new AStar*[++nbrOfStars];
	if (temp != nullptr) {
		for (int i = 0; i < nbrOfStars - 1; ++i) {
			stars[i] = temp[i];
		}
	}
	stars[nbrOfStars - 1] = star;
	delete temp;

	links = new bool*[nbrOfStars];
	for (int i = 0; i < nbrOfStars; ++i) {
		links[i] = new bool[nbrOfStars];
	}

	if (tempMatrix != nullptr) {
		for (int i = 0; i < nbrOfStars - 1; ++i) {
			for (int j = 0; j < nbrOfStars - 1; ++j) {
				links[i][j] = tempMatrix[i][j];
			}
		}
	}
	for (int i = 0; i < nbrOfStars; ++i) {
		links[i][nbrOfStars - 1] = false;
		links[nbrOfStars - 1][i] = false;
	}
	for (int i = 0; i < nbrOfStars - 1; ++i) {
		delete tempMatrix[i];
	}
	delete tempMatrix;
}

