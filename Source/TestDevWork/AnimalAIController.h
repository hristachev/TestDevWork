// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AnimalAIController.generated.h"

class AAnimalActor;
/**
 * 
 */
UCLASS()
class TESTDEVWORK_API AAnimalAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
protected:
	UPROPERTY()
	AAnimalActor* AnimalPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Movement", Meta = (MakeEditWidget = true))
	FVector PatrolPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Movement")
	float MoveAccurency;
	
	float RotationValue();
	void Initialize();
};
