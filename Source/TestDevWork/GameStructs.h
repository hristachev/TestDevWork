// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

const FName SpawnPosition = "Start";
const FName FinishPosition = "Finish";
const FName AIMovement = "MovementType";

UENUM(BlueprintType)
enum class EMovementType : uint8
{
	Move,
	MoveWait,
	MoveBackMove,
};





