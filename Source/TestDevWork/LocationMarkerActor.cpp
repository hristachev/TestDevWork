// Fill out your copyright notice in the Description page of Project Settings.


#include "LocationMarkerActor.h"

ALocationMarkerActor::ALocationMarkerActor()
{
	USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneComponent;
	
	LocationMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LocationMesh"));
	LocationMesh->SetupAttachment(SceneComponent);
}
