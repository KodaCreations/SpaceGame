// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceGame.h"
#include "Pathfinder.h"
#include "Link.h"
#include "MinHeap.h"


// Sets default values
APathfinder::APathfinder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APathfinder::BeginPlay()
{
	Super::BeginPlay();

	GenerateProximityMatrix();
}

// Called every frame
void APathfinder::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void APathfinder::GenerateProximityMatrix()
{
	stars = TArray<AStar*>();

	for (TActorIterator<AStar> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		stars.Add(*ActorItr);
	}

	proximityMatrix.Init(0, stars.Num() * stars.Num());

	for (TActorIterator<ALink> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AStar* temp = ActorItr->Star1;
		for (int i = 0; i < stars.Num(); ++i)
		{
			if (temp == stars[i])
			{
				temp = ActorItr->Star2;
				for (int j = 0; j < stars.Num(); ++j)
				{
					if (temp == stars[j])
					{
						proximityMatrix[i + j * stars.Num()] = (stars[i]->GetActorLocation() - stars[j]->GetActorLocation()).Size();
						UE_LOG(LogTemp, Warning, TEXT("%s' length is %f"), *ActorItr->GetName(), proximityMatrix[i + j * stars.Num()]);
						proximityMatrix[j + i * stars.Num()] = (stars[i]->GetActorLocation() - stars[j]->GetActorLocation()).Size();
						break;
					}
				}
				break;
			}
		}
	}
}

// Uses the a* algorithm in order to find the shortest path between two stars.
// AStar* start is the star where the fleet is currently stationed.
// AStar* target is the target star.
TArray<FVector> APathfinder::FindShortestPath(AStar* start, AStar* target)
{
	TArray<FVector> path = TArray<FVector>();                        //Shortest path; to be returned.
	MinHeap<float, AStar*> minHeap = MinHeap<float, AStar*>();       //Min heap which is used by the a* algorithm.

	TMap<AStar*, AStar*> cameFrom = TMap<AStar*, AStar*>();          //Key-value pair, which star (value) the star (key) came from (shortest path)
	TMap<AStar*, int32> costSoFar = TMap<AStar*, int32>();           //Key-value pair, star (key) and currently shortest distance (value) to star.

	minHeap.Enqueue(0, start);

	cameFrom.Add(start, start);
	costSoFar.Add(start, 0);

	// Loop through all stars in the heap (priority queue).
	while (minHeap.Count() > 0)
	{
		// Current star is the star with highest priority.
		AStar* current = minHeap.Dequeue();

		// Loop through proximity matrix keys.
		for (int i = 0; i < stars.Num(); i++)
		{
			if (current == stars[i])
			{
				// Loop through proximity matrix values (distance to neighbouring stars).
				for (int j = 0; j < stars.Num(); ++j)
				{
					// If the distance is not 0 (0 indicates no link)
					if (proximityMatrix[j + i * stars.Num()] != 0)
					{
						// Calcualte new cost (distance); cost so far + this link's size.
						float newCost = costSoFar[current] + proximityMatrix[j + i * stars.Num()];
						// If costSoFar does not contain the star or the new cost is smaller than the old cost, add the star with it's new cost,
						// calculate priority (distance to target star), enqueue the star and set which neigbouring star it came from.
						if (!costSoFar.Contains(stars[j]) || newCost < costSoFar[stars[j]])
						{
							costSoFar.Add(stars[j], newCost);
							float priority = (stars[j]->GetActorLocation() - target->GetActorLocation()).Size();
							minHeap.Enqueue(priority, stars[j]);
							cameFrom.Add(stars[j], current);
						}
					}
				}
				// Break in order to avoid calculating duplicate values (see proximity matrix)
				break;
			}
		}
	}

	// Array of pointer to stars, will be the path from target to start.
	TArray<AStar*> temp = TArray<AStar*>();
	// If cameFrom does not contain the target star, return an empty path; no path from start to target available.
	if (!cameFrom.Contains(target))
		return path;
	temp.Add(target);

	TArray<AStar*> keys;
	cameFrom.GetKeys(keys);

	// Searches each star in cameFrom in order to find which star is connected to the last star in the temp array.
	// Produces the path backwards.
	for (int i = cameFrom.Num() - 1; i >= 1; --i)
	{
		if (keys[i] == temp[temp.Num() - 1]) 
		{
			temp.Add(*cameFrom.Find(keys[i]));
			i = cameFrom.Num() - 1;
		}
	}

	// Rearrange path from start to target and get the path node locations.
	for (int i = temp.Num() - 1; i >= 0; --i)
	{
		path.Add(temp[i]->GetActorLocation());
	}
	return path;
}