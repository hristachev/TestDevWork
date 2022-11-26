// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameStructs.h"
#include "AnimalAIController.generated.h"

class AAnimalSpawner;
class AAnimalActor;
/**
 * 
 */
UCLASS()
class TESTDEVWORK_API AAnimalAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void SetPawn(APawn* InPawn) override;

	void SetBehaviorValue(FVector SpawnPos, FVector FinishPos, EMovementType MovementType);
	
protected:
	UPROPERTY()
	AAnimalActor* AnimalPawn;

	UPROPERTY()
	AAnimalSpawner* Spawner;
	
	void Initialize();
};
