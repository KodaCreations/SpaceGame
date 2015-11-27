// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "MouseController.generated.h"

/**
 * 
 */
UCLASS()
class SPACEGAME_API AMouseController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMouseController();
	virtual void SetupInputComponent() override;
	//virtual void Tick(float DeltaTime) override;
	
};
