// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionComponent.h"
#include "InteractionInterface.h"
#include "Blueprint/UserWidget.h"

void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UInteractionComponent::OnInteractionCompBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this, &UInteractionComponent::OnInteractionCompEndOverlap);
}

void UInteractionComponent::Interact()
{
	if (InteractableActor)
	{
		IInteractionInterface::Execute_Interact(InteractableActor, GetOwner());
	}
}

void UInteractionComponent::OnInteractionCompBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->Implements<UInteractionInterface>())
	{
		InteractableActor = OtherActor;
		if (!InteractMessage)
		{
			if (InteractMessageClass)
			{
				InteractMessage = CreateWidget<UUserWidget>(GetWorld(), InteractMessageClass);
			}
		}
		if (InteractMessage && !InteractMessage->IsInViewport())
		{
			InteractMessage->AddToViewport();
		}
	}
}

void UInteractionComponent::OnInteractionCompEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	InteractableActor = nullptr;

	if (InteractMessage)
	{
		InteractMessage->RemoveFromViewport();
	}
}
