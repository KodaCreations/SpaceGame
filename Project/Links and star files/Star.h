// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Star.generated.h"

UCLASS()
class SPACEGAMEMOVEMENT_API AStar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStar();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
