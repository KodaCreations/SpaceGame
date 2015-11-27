// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceGame.h"
#include "MouseController.h"


AMouseController::AMouseController()
{
	// set mouse visible
	bShowMouseCursor = true;
	bEnableClickEvents = true;
}

void AMouseController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// bind mouse click event
}

//void MouseController::Tick(float DeltaTime)
//{
	//Super::Tick(DeltaTime);

	//APawn* pawn = GetPawn();
	//pawn->SetActorLocation(pawn->GetActorLocation() + velocity * DeltaTime);
//}