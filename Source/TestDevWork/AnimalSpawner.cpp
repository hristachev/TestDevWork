// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimalSpawner.h"
#include "AnimalActor.h"
#include "AnimalAIController.h"
#include "LocationMarkerActor.h"
#include "Components/ArrowComponent.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"


AAnimalSpawner::AAnimalSpawner()
{
	PrimaryActorTick.bCanEverTick = true;
	
	USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneComponent;

	SpawnerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpawnerMesh"));
	SpawnerMesh->SetupAttachment(SceneComponent);

	VisualMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("VisualMesh"));
	VisualMesh->SetupAttachment(SpawnerMesh);

	ArrowSpawnPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("SpawnPoint"));
	ArrowSpawnPoint->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);

	SpawnAudioEffect = CreateDefaultSubobject<UAudioComponent>(TEXT("SpawnAudioEffect"));
	SpawnAudioEffect->SetAutoActivate(false);
	SpawnAudioEffect->AttachToComponent(ArrowSpawnPoint, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	SpawnParticleEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SpawnParticleEffect"));
	SpawnParticleEffect->SetAutoActivate(false);

	FinishParticleEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FinishParticleEffect"));
	FinishParticleEffect->SetAutoActivate(false);
}

void AAnimalSpawner::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(AnimalActor))
	{
		AnimalActor->OnActorSpawn.AddDynamic(this, &AAnimalSpawner::SpawnAnimal);	
	}
}

void AAnimalSpawner::SetBehaviorValue(AAnimalActor* Actor)
{
	AAnimalAIController* AIController = Cast<AAnimalAIController>(Actor->GetController());
	if (AIController)
	{
		AIController->SetBehaviorValue(ArrowSpawnPoint->GetComponentLocation(), FinishTarget->GetActorLocation(), Actor->MovementType);
	}
}


void AAnimalSpawner::PlayEffects()
{
	if (SpawnParticleEffect)
	{
		
		SpawnParticleEffect->SetWorldLocation(GetActorLocation());
		SpawnParticleEffect->SetWorldRotation(GetActorRotation());
		SpawnParticleEffect->ActivateSystem(true);
	}
	if (FinishParticleEffect)
	{
		FinishParticleEffect->SetWorldLocation(FinishTarget->GetActorLocation());
		FinishParticleEffect->SetWorldRotation(GetActorRotation());
		FinishParticleEffect->ActivateSystem(true);
	}

	if (SpawnAudioEffect)
		SpawnAudioEffect->Play();
}

void AAnimalSpawner::SpawnAnimal(EMovementType MoveType)
{
	if (!IsValid(AnimalClass) && bIsAlreadySpawn && MovementType != MoveType)
	{
		return;
	}
	
	if (!AnimalActor)
	{
		PlayEffects();

		if (VisualMesh)
		{
			VisualMesh->DestroyComponent();
		}
		
		FTransform SpawnTransform(ArrowSpawnPoint->GetComponentRotation(),ArrowSpawnPoint->GetComponentLocation(), FVector(1));
		AnimalActor = GetWorld()->SpawnActorDeferred<AAnimalActor>(AnimalClass, SpawnTransform, this, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
		if (IsValid(AnimalActor))
		{
			if (!IsValid(AnimalActor->GetController()))
			{
				AnimalActor->SpawnDefaultController();
			}
			AnimalActor->MovementType = MovementType;
			SetBehaviorValue(AnimalActor);
		}
		
		
		UGameplayStatics::FinishSpawningActor(AnimalActor, SpawnTransform);

		bIsAlreadySpawn = true;
	}
}

void AAnimalSpawner::DestroyAnimal()
{
	AAnimalActor* Actor = Cast<AAnimalActor>(AnimalClass);
	Actor->DestroyAnimal();

	bIsAlreadySpawn = false;
}
