// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "GameFramework/Pawn.h"
#include "Star.h"
#include "Pathfinder.h"
#include "MousePawn.generated.h"

UCLASS()
class SPACEGAME_API AMousePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMousePawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void SelectActor(AActor* clickedActor);

	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void Deselect();

	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void SendFleetTo(AStar* clickedStar);

	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void AddWaypoint(AStar* clickedStar);

	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void SendFleetByWaypoints();

private:
	AActor* selectedActor;
	APathfinder* pathfinder;
	TArray<AStar*> waypoints;
};
