// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionInterface.h"
#include "GameFramework/Actor.h"
#include "InteractableActor.generated.h"

UCLASS()
class TESTDEVWORK_API AInteractableActor : public AActor, public IInteractionInterface
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	void OnInteractionFinished(AActor* InteractedActor)
	{
		InteractionFinished(this, InteractedActor);
	}
};
