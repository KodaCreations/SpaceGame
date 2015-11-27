// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceGame.h"
#include "Star.h"


// Sets default values
AStar::AStar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->AttachTo(RootComponent);

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Trigger->AttachTo(mesh);
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AStar::OnBeginOverlap);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &AStar::OnEndOverlap);

	ownedBy = OwnedBy::Neutral;
	fleet = nullptr;
}


// Called when the game starts or when spawned
void AStar::BeginPlay()
{
	Super::BeginPlay();

	timer = prodTime;
}

// Called every frame
void AStar::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	timer -= DeltaTime;
	if (timer < 0 && ownedBy != OwnedBy::Neutral)
	{
		if (fleet == nullptr)
		{
			FVector location = GetActorLocation();
			FRotator rotation = GetActorRotation();
			//Won't Spawn Correctly
			fleet = Cast<AFleet>(GetWorld()->SpawnActor(fleetBP, &location, &rotation));
			//fleet->GiveShip();
			fleet->ownedBy = ownedBy;
		}
		else
			fleet->AddShip();

		timer = prodTime;

		// Uncomment for logging stationed fleet size.
		//if (fleet != nullptr)
		//	UE_LOG(LogTemp, Log, TEXT("Number of ships in fleet: %d"), fleet->GetSize());
	}
}
void AStar::OnBeginOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	fleet = Cast<AFleet>(OtherActor);
	ownedBy = fleet->ownedBy;
}
void AStar::OnEndOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	fleet = nullptr;
}

