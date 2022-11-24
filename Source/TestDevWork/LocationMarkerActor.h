// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LocationMarkerInterface.h"
#include "GameFramework/Actor.h"
#include "LocationMarkerActor.generated.h"

UCLASS()
class TESTDEVWORK_API ALocationMarkerActor : public AActor, public ILocationMarkerInterface
{
	GENERATED_BODY()


public:

	ALocationMarkerActor();
	
	UFUNCTION(BlueprintCallable)
		void OnOverlappedByActor(AActor* OverlappingActor)
	{
		OverlapWithActor(this, OverlappingActor);
	}
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LocationMesh")
	UStaticMeshComponent* LocationMesh;
};