// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Star.h"
#include "GameFramework/Actor.h"
#include "Link.generated.h"

UCLASS()
class SPACEGAME_API ALink : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALink();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;


	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh;
	UPROPERTY(EditAnywhere)
		AStar* Star1;
	UPROPERTY(EditAnywhere)
		AStar* Star2;
};
