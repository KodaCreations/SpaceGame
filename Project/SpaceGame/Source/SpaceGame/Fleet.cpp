// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceGame.h"
#include "Fleet.h"
#include "Star.h"
#include "Combat.h"


// Sets default values
AFleet::AFleet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ships = 1;
	maxMorale = 30.0f;
	minMorale = -30.0f;
	InCombat = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->AttachTo(RootComponent);

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Trigger->AttachTo(mesh);
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AFleet::OnBeginOverlap);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &AFleet::OnEndOverlap);

	//ownedBy = OwnedBy::Neutral;

	destinations = TArray<FVector>();
	
}

// Called when the game starts or when spawned
void AFleet::BeginPlay()
{
	Super::BeginPlay();
	if (ship != nullptr)
	{
		UpdateFleetStats();
		currentMorale = ship->Morale();
	}
	destinations = TArray<FVector>();
}

// Called every frame
void AFleet::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (destinations.Num() > 0 && !InCombat)
	{
		FVector temp;
		float speed = 500.f;

		temp = destinations[0] - GetActorLocation();
		temp.Normalize();

		SetActorLocation(GetActorLocation() + temp * speed * DeltaTime);
		if (AtDestination(destinations[0]))
		{
			destinations.RemoveAt(0);
		}
	}
	if (mergable)
	{
		TArray<AActor*> fleets;
		GetOverlappingActors(fleets, AFleet::StaticClass());
		if (destinations.Num() <= 0 && Cast<AFleet>(fleets[0])->GetDestinations().Num() <= 0)
		{
			MergeFleet(Cast<AFleet>(fleets[0]));
			mergable = false;
		}
	}
}


bool AFleet::AtDestination(FVector _destination)
{
	FVector length = _destination - GetActorLocation();
	if (length.Size() < 4)
	{
		return true;
	}
	return false;
}


void AFleet::UpdateFleetStats()
{
	totalHealth = ship->Health() * ships;
	totalDamage = (ship->Damage() * ships) + (ship->Damage() * ships * currentMorale * 0.01);
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

// Increases morale when on a Star
void AFleet::IncreaseMorale(float DeltaTime)
{
	if (currentMorale <= maxMorale)
	{
		currentMorale += DeltaTime;
		if (currentMorale > maxMorale)
			currentMorale = maxMorale;
	}
}

// Decreases morale when in combat
void AFleet::DecreaseMorale(float DeltaTime)
{
	if (currentMorale > minMorale)
	{
		currentMorale -= DeltaTime * 2;
		if (currentMorale < minMorale)
			currentMorale = minMorale;
	}

}

// Called when adding a ship to the fleet
void AFleet::AddShip()
{
	++ships;
	if (ship != nullptr)
	{
		UpdateFleetStats();
	}
}

// Called to find out the number of ships in the floor
float AFleet::GetSize()
{
	return ships;
}

// Called to tell the fleet which type of ship it has
void AFleet::GiveShipType(AShip* shipType)
{
	ship = shipType;
}

// Called when Fleet overlaps with another actor it's set to collide with
void AFleet::OnBeginOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (!InCombat && OtherActor->IsA(AFleet::StaticClass()))
	{
		AFleet* otherFleet = Cast<AFleet>(OtherActor);
		if (ownedBy != otherFleet->ownedBy
			&& ownedBy != OwnedBy::Neutral
			&& otherFleet->ownedBy != OwnedBy::Neutral)
		{
			InCombat = true;
			otherFleet->InCombat = true;
			ACombat* combat = GetWorld()->SpawnActor<ACombat>();
			combat->Inizialize(this, otherFleet);
		}
		else if (ownedBy == otherFleet->ownedBy)
		{
			mergable = true;
		}
	}
	else if (OtherActor->IsA(AStar::StaticClass()))
	{
		lastVisitedStar = OtherActor;
	}
}

// Called when merging two fleets together
void AFleet::MergeFleet(AFleet* _mergeFleet)
{
	currentMorale = ((currentMorale * ships) + (_mergeFleet->CurrentMorale() * _mergeFleet->GetSize())) / (ships + _mergeFleet->GetSize());
	ships += _mergeFleet->GetSize();
	_mergeFleet->Destroy();
	//UpdateFleetStats();
}

// Called when Fleet ends it's overlap with another actor
void AFleet::OnEndOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	mergable = false;
}


void AFleet::SetDestinations(TArray<FVector> destinations)
{
	AFleet::destinations = destinations;
}


TArray<FVector> AFleet::GetDestinations()
{
	return destinations;
}

// Called to find out which Star the Fleet last visited
AActor* AFleet::GetLastVisitedStar()
{
	return lastVisitedStar;
}
void AFleet::SetLastVisitedStar(AActor* star)
{
	lastVisitedStar = star;
}