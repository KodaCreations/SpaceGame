// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceGame.h"
#include "MousePawn.h"

// Sets default values
AMousePawn::AMousePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	selectedActor = nullptr;
	waypoints = TArray<AStar*>();
}

// Called when the game starts or when spawned
void AMousePawn::BeginPlay()
{
	Super::BeginPlay();

	for (TActorIterator<APathfinder> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		pathfinder = *ActorItr;
		break;
	}
}

// Called every frame
void AMousePawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AMousePawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AMousePawn::SelectActor(AActor* clickedActor)
{
	if (Cast<AFleet, AActor>(clickedActor) || Cast<AStar, AActor>(clickedActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("MyCharacter's Name is %s"), *clickedActor->GetName());
		selectedActor = clickedActor;
	}
	else
		Deselect();
}

void AMousePawn::Deselect()
{
	selectedActor = nullptr;
}

void AMousePawn::SendFleetTo(AStar* clickedStar)
{
	AStar* selectedStar =nullptr;
	AFleet* selectedFleet = nullptr;

	selectedStar = Cast<AStar, AActor>(selectedActor);
	selectedFleet = Cast<AFleet, AActor>(selectedActor);
	
	if (pathfinder && selectedActor)
	{
		AStar* lastVisitedStar = Cast<AStar, AActor>(selectedFleet->GetLastVisitedStar());
		if (selectedStar && selectedStar->GetFleet())
		{
			TArray<FVector> destinations = pathfinder->FindShortestPath(selectedStar, clickedStar);
			selectedStar->GetFleet()->SetDestinations(destinations);
		}
		else if (selectedFleet && lastVisitedStar)
		{
			TArray<FVector> destinations = pathfinder->FindShortestPath(lastVisitedStar, clickedStar);
			destinations.Insert(lastVisitedStar->GetActorLocation(), 0);
			selectedFleet->SetDestinations(destinations);
		}
	}
}

void AMousePawn::AddWaypoint(AStar* clickedStar)
{
	waypoints.Add(clickedStar);
}

void AMousePawn::SendFleetByWaypoints()
{
	AStar* selectedStar = Cast<AStar, AActor>(selectedActor);
	AFleet* selectedFleet = Cast<AFleet, AActor>(selectedActor);

	if (pathfinder && selectedActor)
	{
		TArray<FVector> destinations;
		AStar* start = nullptr;
		AStar* lastVisitedStar = Cast<AStar, AActor>(selectedFleet->GetLastVisitedStar());

		if (selectedStar && selectedStar->GetFleet())
			start = selectedStar;
		else if (selectedFleet && lastVisitedStar)
			start = lastVisitedStar;

		for (int i = 0; i < waypoints.Num(); ++i)
			UE_LOG(LogTemp, Warning, TEXT("Waypoint %d is: %s"), i, *waypoints[i]->GetName());

		while (waypoints.Num() != 0 && start)
		{
			destinations += pathfinder->FindShortestPath(start, waypoints[0]);

			start = waypoints[0];
			waypoints.RemoveAt(0);
		}
		if (selectedStar && selectedStar->GetFleet())
		{
			selectedStar->GetFleet()->SetDestinations(destinations);
		}
		else if (selectedFleet && lastVisitedStar)
		{
			destinations.Insert(lastVisitedStar->GetActorLocation(), 0);
			selectedFleet->SetDestinations(destinations);
		}
	}
}