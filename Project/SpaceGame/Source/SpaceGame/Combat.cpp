// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceGame.h"
#include "Combat.h"


// Sets default values
ACombat::ACombat()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void ACombat::Inizialize(AFleet* fleet1, AFleet* fleet2)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	playerFleet = fleet1;
	aiFleet = fleet2;
}

// Called when the game starts or when spawned
void ACombat::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ACombat::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FleetCombat(DeltaTime);
	CheckIfDead();
}


void ACombat::CheckIfDead()
{
	if (playerFleet->TotalHealth() < 0)
	{
		playerFleet->Destroy();
		aiFleet->UpdateFleetStats();
		aiFleet->InCombat = false;
		Destroy();
	}
	else if (aiFleet->TotalHealth() < 0)
	{
		aiFleet->Destroy();
		playerFleet->UpdateFleetStats();
		playerFleet->InCombat = false;
		Destroy();
	}
}


void ACombat::FleetCombat(float DeltaTime)
{
	aiFleet->DecreaseMorale(DeltaTime);
	playerFleet->DecreaseMorale(DeltaTime);
	float playerTakeDamage = (aiFleet->TotalDamage()) * DeltaTime;
	float aiTakeDamage = playerFleet->TotalDamage() * DeltaTime;
	aiFleet->TakeFleetDamage(aiTakeDamage);
	playerFleet->TakeFleetDamage(playerTakeDamage);
}

