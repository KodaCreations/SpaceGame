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
		totalMorale = ship->Morale();
	}
	destinations = TArray<FVector>();
}

// Called every frame
void AFleet::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	//sBuildMorale(DeltaTime);
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
	if (ship != nullptr)
	{
		UpdateFleetStats();
	}
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
}
void AFleet::MergeFleet(AFleet* _mergeFleet)
{
	//totalMorale = ((totalMorale * ships) + (_mergeFleet->TotalMorale() * _mergeFleet->GetSize())) / (ships + _mergeFleet->GetSize());
	ships += _mergeFleet->GetSize();
	_mergeFleet->Destroy();
	//UpdateFleetStats();
}
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