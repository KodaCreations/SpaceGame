// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceGame.h"
#include "Fleet.h"
#include "Combat.h"


// Sets default values
AFleet::AFleet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ships = 1;
	moraleCap = 30;
	InCombat = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->AttachTo(RootComponent);

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Trigger->AttachTo(mesh);
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AFleet::OnBeginOverlap);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &AFleet::OnEndOverlap);

	ownedBy = OwnedBy::Neutral;
}

// Called when the game starts or when spawned
void AFleet::BeginPlay()
{
	Super::BeginPlay();
	if (ship != nullptr)
	{
		UpdateFleetStats();
		totalMorale = ship->Morale();
	}
}

// Called every frame
void AFleet::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	//sBuildMorale(DeltaTime);

}
void AFleet::UpdateFleetStats()
{
	totalHealth = ship->Health() * ships;
	totalDamage = (ship->Damage() * ships) + (ship->Damage() * ships * totalMorale * 0.01);
	totalDefence = ship->Defence();
}
void AFleet::TakeFleetDamage(float damage)
{
	if (ship != nullptr)
	{
		totalHealth -= damage;
		if ((ships * ship->Health() - totalHealth) > ship->Health())
		{
			--ships;
			UpdateFleetStats();
		}
	}
}
void AFleet::BuildMorale(float DeltaTime)
{
	if (true) //Fleet is on a star
	{
		if (totalMorale <= moraleCap)
		{
			totalMorale += DeltaTime; // ggr stars moralebuilder
		}
	}
}

void AFleet::AddShip()
{
	++ships;
}

int AFleet::GetSize()
{
	return ships;
}
void AFleet::GiveShipType(AShip* shipType)
{
	ship = shipType;
}
void AFleet::OnBeginOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (!InCombat && OtherActor->IsA(AFleet::StaticClass()))
	{
		InCombat = true;
		Cast<AFleet>(OtherActor)->InCombat = true;
		ACombat* combat = GetWorld()->SpawnActor<ACombat>();
		combat->Inizialize(this, Cast<AFleet>(OtherActor));
	}
}
void AFleet::OnEndOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}
