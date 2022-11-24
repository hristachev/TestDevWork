// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickButton.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/AudioComponent.h"
#include "Components/BoxComponent.h"


// Sets default values
AClickButton::AClickButton()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneComponent;
	
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("ButtonCollider"));
	BoxCollider->SetupAttachment(SceneComponent);

	ButtonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Button"));
	ButtonMesh->SetupAttachment(BoxCollider);

	AudioButtonEffect = CreateDefaultSubobject<UAudioComponent>(TEXT("ButtonClickSound"));
	AudioButtonEffect->SetAutoActivate(false);
	
}

