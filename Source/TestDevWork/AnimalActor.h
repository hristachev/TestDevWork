// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameStructs.h"
#include "GameFramework/Character.h"
#include "AnimalActor.generated.h"

class UBehaviorTree;
class ALocationMarkerActor;
class USkeletalMeshComponent;
class UAudioComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorSpawn, EMovementType, MovementType);

UCLASS()
class TESTDEVWORK_API AAnimalActor : public ACharacter
{
	GENERATED_BODY()

public:
	AAnimalActor();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI|Components")
	EMovementType MovementType = EMovementType::Move;

	UBehaviorTree* GetBehaviorTree() const;
	
	void DestroyAnimal();

	UFUNCTION(BlueprintCallable, Category = "FinishEffect")
	void SetPlaySoundAtFinish();

	UFUNCTION(BlueprintCallable, Category = "AI|Spawn")
	void SetMoveTypeWhenSpawn(EMovementType MoveType);
	
	FOnActorSpawn OnActorSpawn;

protected:
	UPROPERTY(EditAnywhere, Category = "AnimalEffects")
	UAudioComponent* FinishSoundEffect;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI|Components")
	UBehaviorTree* BehaviorTree;

private:
	bool bIsAlreadyPlayFinishSound = false;
};
