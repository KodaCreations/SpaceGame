// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceGame.h"
#include "Link.h"


// Sets default values
ALink::ALink()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->AttachTo(RootComponent);
}
void ALink::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (Star1 != nullptr && Star2 != nullptr && mesh != nullptr)
	{
		FVector newPos = FVector((Star1->GetActorLocation() + Star2->GetActorLocation()) / 2);
		SetActorLocation(newPos);
		FVector newRotation = (Star1->GetActorLocation() - Star2->GetActorLocation());
		newRotation.Normalize();
		FRotator rotation = FRotator(newRotation.Rotation().Pitch + 90, newRotation.Rotation().Yaw, 0);
		mesh->SetRelativeRotation(rotation);
		float dist = FVector::Dist(Star1->GetActorLocation(), Star2->GetActorLocation());
		FVector scale = FVector(0.2, 0.2, dist / 100);
		mesh->SetRelativeScale3D(scale);
	}
}

// Called when the game starts or when spawned
void ALink::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ALink::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

