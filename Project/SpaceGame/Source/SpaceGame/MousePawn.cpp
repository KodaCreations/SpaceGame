// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceGame.h"
#include "MousePawn.h"

// Sets default values
AMousePawn::AMousePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	selectedActor = nullptr;
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
	if (AStar* selectedStar = Cast<AStar, AActor>(selectedActor))
	{
		if (pathfinder && selectedActor && selectedStar->GetFleet())
		{
			TArray<FVector> destinations = pathfinder->FindShortestPath(selectedStar, clickedStar);

			selectedStar->GetFleet()->SetDestinations(destinations);
		}
	}
}