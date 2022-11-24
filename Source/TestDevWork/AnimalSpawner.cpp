// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimalSpawner.h"
#include "AnimalActor.h"
#include "ClickButton.h"
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

	ArrowSpawnPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("SpawnPoint"));
	ArrowSpawnPoint->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);

	/*FinishTarget = CreateDefaultSubobject<ALocationMarkerActor>(TEXT("FinishTarget"));
	FinishTarget->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);*/

	SpawnAudioEffect = CreateDefaultSubobject<UAudioComponent>(TEXT("SpawnAudioEffect"));
	SpawnAudioEffect->SetAutoActivate(false);

	SpawnParticleEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SpawnParticleEffect"));
	SpawnParticleEffect->SetAutoActivate(false);
	SpawnParticleEffect->SetupAttachment(ArrowSpawnPoint);
	
}

void AAnimalSpawner::BeginPlay()
{
	Super::BeginPlay();

	/*ButtonSpawn(ButtonClass);*/
}

void AAnimalSpawner::SpawnAnimal()
{
	if (bIsAlreadySpawn)
	{
		return;
	}

	if (AnimalClass)
	{
		FTransform SpawnTransform(ArrowSpawnPoint->GetComponentRotation(),ArrowSpawnPoint->GetComponentLocation(), FVector(1));
		Animal = GetWorld()->SpawnActorDeferred<AAnimalActor>(AnimalClass, SpawnTransform, this, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

		Animal->SetFinishTarget(FinishTarget);
		
		SpawnAudioEffect->Play();
		SpawnParticleEffect->ActivateSystem();
		
		UGameplayStatics::FinishSpawningActor(Animal, SpawnTransform);

		bIsAlreadySpawn = true;
	}
}

void AAnimalSpawner::DestroyAnimal()
{
	AAnimalActor* AnimalActor = Cast<AAnimalActor>(AnimalClass);
	AnimalActor->DestroyAnimal();

	bIsAlreadySpawn = false;
}

/*
void AAnimalSpawner::ButtonSpawn(TSubclassOf<AClickButton> ButtonActor)
{
	if (!ButtonActor)
		return;
	
	FActorSpawnParameters params;
	params.Owner = this;

	Button = GetWorld()->SpawnActor<AClickButton>(ButtonActor, params);
	Button->AttachToComponent(ArrowButtonPoint, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}
*/
