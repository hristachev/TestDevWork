// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "ClickButton.generated.h"

class AAnimalSpawner;
class USkeletalMeshComponent;
class UBoxComponent;
class UAudioComponent;
class UAnimMontage;

UCLASS()
class TESTDEVWORK_API AClickButton : public AInteractableActor
{
	GENERATED_BODY()

public:
	AClickButton();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MeshComponent")
	USkeletalMeshComponent* ButtonMesh;

	UPROPERTY(EditAnywhere, Category = "MeshComponent")
	UBoxComponent* BoxCollider;

	UPROPERTY(EditAnywhere, Category = "ButtonEffects")
	UAudioComponent* AudioButtonEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimalSpawn")
	TSubclassOf<AAnimalSpawner> Spawner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimalSpawn")
	AAnimalSpawner* SpawnerActor;

};
