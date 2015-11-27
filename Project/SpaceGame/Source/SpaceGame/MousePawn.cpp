// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceGame.h"
#include "MousePawn.h"


// Sets default values
AMousePawn::AMousePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	selectedStar = nullptr;
}

// Called when the game starts or when spawned
void AMousePawn::BeginPlay()
{
	Super::BeginPlay();
	
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

void AMousePawn::SelectStar(AStar* clickedStar)
{
	selectedStar = clickedStar;
}

void AMousePawn::Deselect()
{
	selectedStar = nullptr;
}

void AMousePawn::SendFleetTo(AStar* clickedStar)
{
	if (selectedStar && selectedStar->GetFleet())
	{
		TArray<FVector> temp = TArray<FVector>();
		temp.Add(clickedStar->GetActorLocation());
		selectedStar->GetFleet()->SetDestinations(temp);
	}
}