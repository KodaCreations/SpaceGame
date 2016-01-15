// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceGame.h"
#include "CameraPawn.h"


// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	speed = 300.0f;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->AttachTo(RootComponent);
	SpringArm->SetRelativeRotation(FRotator(-70.0f, 0.0f, 0.0f));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->AttachTo(SpringArm);



}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	SetActorLocation(GetActorLocation() + velocity * DeltaTime);
}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveX", this, &ACameraPawn::MoveX);
	InputComponent->BindAxis("MoveY", this, &ACameraPawn::MoveY);
}


void ACameraPawn::MoveX(float axisValue){
	FMath::Clamp(axisValue, -1.0f, 1.0f);
	velocity.X = axisValue * speed;
}

void ACameraPawn::MoveY(float axisValue){
	FMath::Clamp(axisValue, -1.0f, 1.0f);
	velocity.Y = axisValue * speed;
}

