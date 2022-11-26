// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimalActor.h"
#include "LocationMarkerActor.h"
#include "Components/AudioComponent.h"

AAnimalActor::AAnimalActor()
{
	PrimaryActorTick.bCanEverTick = true;

	FinishSoundEffect = CreateDefaultSubobject<UAudioComponent>(TEXT("FinishSound"));
	FinishSoundEffect->SetAutoActivate(false);
}

UBehaviorTree* AAnimalActor::GetBehaviorTree() const
{
	return BehaviorTree;
}


void AAnimalActor::DestroyAnimal()
{
	K2_DestroyActor();
}

void AAnimalActor::SetPlaySoundAtFinish()
{
	if (bIsAlreadyPlayFinishSound)
		return;

	if (FinishSoundEffect)
	{
		bIsAlreadyPlayFinishSound = true;
		FinishSoundEffect->SetWorldLocation(GetActorLocation());
		FinishSoundEffect->SetWorldRotation(GetActorRotation());
		FinishSoundEffect->Play();
	}
}

void AAnimalActor::SetMoveTypeWhenSpawn(EMovementType MoveType)
{
	if (OnActorSpawn.IsBound())
	{
		OnActorSpawn.Broadcast(MoveType);
	}
}


