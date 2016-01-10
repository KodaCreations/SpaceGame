// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "Fleet.h"
#include "GameFramework/Actor.h"
#include "Star.generated.h"

UCLASS()
class SPACEGAME_API AStar : public AActor
{

	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStar();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AFleet> fleetBP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		OwnedBy ownedBy;
	UPROPERTY(VisibleAnywhere, Category = "Triggers")
		UBoxComponent* Trigger;
	UFUNCTION()
		void OnBeginOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
		void OnEndOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION(BlueprintCallable, Category = "Star")
		AFleet* GetFleet();

private:
	float takeoverTimer;
	float maxTakeoverTime;
	bool takingOver;
	// Stationed fleet
	UPROPERTY(VisibleAnywhere)
	AFleet *fleet;

	// Production time
	const float prodTime = 3;

	// Fleet creation timer
	float shipBuildTimer;
	UPROPERTY(EditAnywhere)
		float starDefence;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh;
};
