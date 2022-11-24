// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimalAIController.h"

#include "AnimalActor.h"

void AAnimalAIController::BeginPlay()
{
	Super::BeginPlay();

	Initialize();
}

void AAnimalAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!AnimalPawn)
		Initialize();
	if (!AnimalPawn)
		return;
	
	AnimalPawn->MoveForward(1);

	float RotateValue = RotationValue();
	AnimalPawn->RotateRight(RotateValue);
	
}

float AAnimalAIController::RotationValue()
{
	FVector point = PatrolPoint;
	FVector pawnLocation = AnimalPawn->GetActorLocation();

	FVector moveDirection = point - pawnLocation;
	moveDirection.Normalize();
	FVector forwardDirection = AnimalPawn->GetActorForwardVector();
	FVector rightDirection = AnimalPawn->GetActorRightVector();

	float forwardAngle = FMath::RadiansToDegrees(acosf(FVector::DotProduct(forwardDirection, moveDirection)));
	float rightAngle = FMath::RadiansToDegrees(acosf(FVector::DotProduct(rightDirection, moveDirection)));

	float RotationValue = 1;

	if(rightAngle > 90)
	{
		RotationValue = -RotationValue;
	}

	return RotationValue;
}

void AAnimalAIController::Initialize()
{
	AnimalPawn = Cast<AAnimalActor>(GetPawn());

	if (!AnimalPawn)
		return;

	FVector pawnLocation = AnimalPawn->GetActorLocation();
	MoveAccurency = AnimalPawn->GetAccurency();
	FVector finishPoint = AnimalPawn->GetFinishPoint();
	
	
	UE_LOG(LogTemp, Warning, TEXT("FinishPoint = x: %f , y: %f,z: %f"), finishPoint.X, finishPoint.Y, finishPoint.Z);
	
	PatrolPoint.AddBounded(finishPoint);
}
