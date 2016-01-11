// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceGame.h"
#include "MousePawn.h"

// Sets default values
AMousePawn::AMousePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	speed = 700.0f;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->AttachTo(RootComponent);
	SpringArm->SetRelativeRotation(FRotator(-70.0f, 0.0f, 0.0f));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->AttachTo(SpringArm);

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
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("Created a PathFinder"));
	pathfinder = (APathfinder*)GetWorld()->SpawnActor(APathfinder::StaticClass(), NULL, NULL);
}

// Called every frame
void AMousePawn::Tick( float DeltaTime )
{
	Super::Tick(DeltaTime);
	SetActorLocation(GetActorLocation() + velocity * DeltaTime);
}

// Called to bind functionality to input
void AMousePawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveX", this, &AMousePawn::MoveX);
	InputComponent->BindAxis("MoveY", this, &AMousePawn::MoveY);
}


void AMousePawn::MoveX(float axisValue)
{
	FMath::Clamp(axisValue, -1.0f, 1.0f);
	velocity.X = axisValue * speed;
}

void AMousePawn::MoveY(float axisValue)
{
	FMath::Clamp(axisValue, -1.0f, 1.0f);
	velocity.Y = axisValue * speed;
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
		if (selectedStar && selectedStar->GetFleet())
		{
			TArray<AActor*> destinations = pathfinder->FindShortestPath(selectedStar, clickedStar);
			selectedStar->GetFleet()->SetDestinations(destinations);
			return;
		}
		if (selectedFleet)
		{
			AStar* nextStar;
			if (selectedFleet->GetDestinations().Num() > 0)
				nextStar = Cast<AStar, AActor>(selectedFleet->GetDestinations()[0]);
			else
				nextStar = Cast<AStar, AActor>(selectedFleet->GetLastVisitedStar());
			TArray<AActor*> destinations = pathfinder->FindShortestPath(nextStar, clickedStar);
			destinations.Insert(nextStar, 0);
			selectedFleet->SetDestinations(destinations);
			return;
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
		TArray<AActor*> destinations;
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
			destinations.Insert(lastVisitedStar, 0);
			selectedFleet->SetDestinations(destinations);
		}
	}
}

AActor* AMousePawn::GetSelectedActor()
{
	return selectedActor;
}