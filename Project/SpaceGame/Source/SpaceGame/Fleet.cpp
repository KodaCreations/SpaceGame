// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceGame.h"
#include "Fleet.h"


// Sets default values
AFleet::AFleet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ships = 1;
}

// Called when the game starts or when spawned
void AFleet::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFleet::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AFleet::AddShip()
{
	++ships;
}

int AFleet::GetSize()
{
	return ships;
}
