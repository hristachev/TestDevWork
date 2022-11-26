// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimalAIController.h"
#include "AnimalSpawner.h"
#include "AnimalActor.h"
#include "BehaviorTree/BlackboardComponent.h"

void AAnimalAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (IsValid(InPawn))
	{
		Initialize();
	}
}

void AAnimalAIController::SetBehaviorValue(FVector SpawnPos, FVector FinishPos, EMovementType MovementType)
{
	if (Blackboard)
	{
		Blackboard->SetValueAsVector(SpawnPosition, SpawnPos);
		Blackboard->SetValueAsVector(FinishPosition, FinishPos);
		Blackboard->SetValueAsEnum(AIMovement, uint8(MovementType));
	}
}

void AAnimalAIController::Initialize()
{
	AnimalPawn = Cast<AAnimalActor>(GetPawn());

	if (!AnimalPawn)
		return;

	RunBehaviorTree(AnimalPawn->GetBehaviorTree());
}
