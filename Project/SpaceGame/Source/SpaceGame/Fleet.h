// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Ship.h"
#include "GameFramework/Actor.h"
#include "Fleet.generated.h"

UCLASS()
class SPACEGAME_API AFleet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFleet();
	float TotalDamage() const { return totalDamage; }
	float TotalHealth() const{ return totalHealth; }
	float TotalDefence() const{ return totalDefence; }
	float TotalMorale() const{ return totalMorale; }

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	void UpdateFleetStats();
	void AddShip();
	void BuildMorale(float DeltaTime);
	void TakeFleetDamage(float damage);
	bool InCombat;
	int GetSize();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		Star::OwnedBy ownedBy;*/
	UPROPERTY(VisibleAnywhere, Category = "Triggers")
		UBoxComponent* Trigger;
	UPROPERTY(EditAnywhere)
		AShip* ship;
	UFUNCTION()
		void OnBeginOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
		void OnEndOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
private:
	UPROPERTY(EditAnywhere)
		int32 ships;
	UPROPERTY(VisibleAnywhere)
		float totalMorale;
	UPROPERTY(VisibleAnywhere)
		float totalDamage;
	UPROPERTY(VisibleAnywhere)
		float totalHealth;
	UPROPERTY(VisibleAnywhere)
		float totalDefence;
	float moraleCap;
};
