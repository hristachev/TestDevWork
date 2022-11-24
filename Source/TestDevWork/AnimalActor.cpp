// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimalActor.h"
#include "LocationMarkerActor.h"
#include "Components/AudioComponent.h"

AAnimalActor::AAnimalActor()
{
	PrimaryActorTick.bCanEverTick = true;

	AnimalSoundEffect = CreateDefaultSubobject<UAudioComponent>(TEXT("AnimalSound"));
	AnimalSoundEffect->SetAutoActivate(false);
}

void AAnimalActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAnimalActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	FVector CurrentLocation = GetActorLocation();
	FVector forwardVector = GetActorForwardVector();
	FVector rightVector = GetActorRightVector();
	FVector Move = CurrentLocation + (forwardVector * ForwardAxisValue * MoveSpeed) + (rightVector * RightAxisValue * MoveSpeed) * DeltaSeconds;

	CurrentRotateValue = FMath::Lerp(CurrentRotateValue, RotateRightAxisValue, InterpolationSpeed);

	float YawRotation = RotationSpeed * RotateRightAxisValue * DeltaSeconds;
	FRotator CurrentRotation = GetActorRotation();

	YawRotation += CurrentRotation.Yaw;
	FRotator newRotation = FRotator(0.0f, YawRotation, 0.0f);

	SetActorRotation(newRotation);
	SetActorLocation(Move, true);
}


void AAnimalActor::DestroyAnimal()
{
	Destroy();
}

void AAnimalActor::SetFinishTarget(ALocationMarkerActor* Marker)
{
	FinishTarget = Marker;
}

void AAnimalActor::MoveForward(float Value)
{
	ForwardAxisValue = Value;
}

void AAnimalActor::MoveRight(float Value)
{
	RightAxisValue = Value;
}

void AAnimalActor::RotateRight(float Value)
{
	RotateRightAxisValue = Value;
}

FVector AAnimalActor::GetFinishPoint()
{
	FVector PointVector;
	ALocationMarkerActor* point = FinishTarget;
	
	PointVector.AddBounded(point->GetTargetLocation());

	return PointVector;
}

