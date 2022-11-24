// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AnimalActor.generated.h"

class ALocationMarkerActor;
class USkeletalMeshComponent;
class UAudioComponent;

UCLASS()
class TESTDEVWORK_API AAnimalActor : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAnimalActor();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
	void DestroyAnimal();

	void SetFinishTarget(ALocationMarkerActor* Marker);

	void MoveForward(float Value);
	void MoveRight(float Value);
	void RotateRight(float Value);

	UFUNCTION()
	float GetAccurency() { return MovementAccurency; }
	UFUNCTION()
	FVector GetFinishPoint();
	
protected:
	UPROPERTY(EditAnywhere, Category = "AnimalEffects")
	UAudioComponent* AnimalSoundEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FinishTarget", Meta = (MakeEditWidget = true))
	ALocationMarkerActor* FinishTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Components")
	float MovementAccurency = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Components")
	float MoveSpeed = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Components")
	float InterpolationSpeed = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Components")
	float RotationSpeed = 5.0f;

private:
	float ForwardAxisValue = 0.0f;
	float RightAxisValue = 0.0f;
	float RotateRightAxisValue = 0.0f;
	float CurrentRotateValue = 0.0f;
};
