// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameStructs.h"
#include "AnimalSpawner.generated.h"

class ALocationMarkerActor;
class AClickButton;
class AAnimalActor;
class UStaticMeshComponent;
class UArrowComponent;
class UAudioComponent;
class UParticleSystemComponent;

UCLASS()
class TESTDEVWORK_API AAnimalSpawner : public AActor
{
	GENERATED_BODY()

public:
	AAnimalSpawner();

	virtual void BeginPlay() override;

	void SetBehaviorValue(AAnimalActor* Actor);

	void PlayEffects();

	UFUNCTION(BlueprintCallable)
	void SpawnAnimal(EMovementType MoveType);

	UFUNCTION(BlueprintCallable)
	void DestroyAnimal();
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnerMesh")
	UStaticMeshComponent* SpawnerMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MeshInSpawn")
	USkeletalMeshComponent* VisualMesh;

	UPROPERTY(EditAnywhere, Category = "SpawnerMesh")
	UArrowComponent* ArrowSpawnPoint;

	UPROPERTY(EditAnywhere, Category = "SpawnActor")
	TSubclassOf<AAnimalActor> AnimalClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI Movement")
	EMovementType MovementType = EMovementType::Move;

	UPROPERTY(EditAnywhere, Category = "SpawnEffects")
	UAudioComponent* SpawnAudioEffect;

	UPROPERTY(EditAnywhere, Category = "SpawnEffect")
	UParticleSystemComponent* SpawnParticleEffect;

	UPROPERTY(EditAnywhere, Category = "FinishEffect")
	UParticleSystemComponent* FinishParticleEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FinishTarget")
	ALocationMarkerActor* FinishTarget;

	UPROPERTY(VisibleAnywhere, Category = "SpawnValue")
	bool bIsAlreadySpawn = false;
	
	UPROPERTY()
	AAnimalActor* AnimalActor;
};
