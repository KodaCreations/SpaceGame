// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "Ship.h"
#include "GameFramework/Actor.h"
#include "Fleet.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class OwnedBy : uint8
{
	Neutral 	UMETA(DisplayName = "Neutral"),
	Player1 	UMETA(DisplayName = "Player1"),
	Player2 	UMETA(DisplayName = "Player2")
};

UENUM(BlueprintType)
enum class FleetState : uint8
{
	Stationary,
	Moving, 
	Returning
};

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
	float CurrentMorale() const{ return currentMorale; }
	float StarDefence() const{ return starDefence; }
	void StarDefence(float defence) { starDefence = defence; }


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	void UpdateFleetStats();
	void AddShip();
	void GiveShipType(AShip* shipType);

	// Called to increase or decrease morale
	void IncreaseMorale(float DeltaTime);
	void DecreaseMorale(float DeltaTime);

	void TakeFleetDamage(float damage);
	bool AtDestination(FVector _destination);
	void SetDestinations(TArray<AActor*> destinations);
	TArray<AActor*> GetDestinations();
	void MergeFleet(AFleet* _mergeWith);
	bool InCombat;
	bool mergable;
	AActor* GetLastVisitedStar();
	void SetLastVisitedStar(AActor* star);

	UFUNCTION(BlueprintCallable, Category = "Fleet")
		float GetSize();
	UFUNCTION(BlueprintCallable, Category = "Fleet")
		void SetFleetColor();
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
		FVector direction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		OwnedBy ownedBy;
	UPROPERTY(VisibleAnywhere, Category = "Triggers")
		UBoxComponent* Trigger;
	UPROPERTY(EditAnywhere)
		AShip* ship;
	UFUNCTION()
		void OnBeginOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
		void OnEndOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION(BlueprintImplementableEvent, category = "Events")
		void ChangeDirection();
private:
	UPROPERTY(EditAnywhere)
		int32 ships;
	UPROPERTY(EditAnywhere)
		float currentMorale;
	UPROPERTY(VisibleAnywhere)
		float totalDamage;
	UPROPERTY(VisibleAnywhere)
		float totalHealth;
	UPROPERTY(VisibleAnywhere)
		float totalDefence;
	UPROPERTY(VisibleAnywhere)
		float starDefence;
	float maxMorale;
	float minMorale;
	UPROPERTY(VisibleAnywhere)
		AActor* lastVisitedStar;

	UPROPERTY(VisibleAnywhere)
		TArray<AActor*> destinations;
};
