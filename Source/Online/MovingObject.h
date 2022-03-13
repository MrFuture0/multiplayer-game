// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingObject.generated.h"

/**
 * 
 */
UCLASS()
class ONLINE_API AMovingObject : public AStaticMeshActor
{
	GENERATED_BODY()
	AMovingObject();
private:
	virtual void BeginPlay() override; 
	virtual void Tick(float DeltaTime) override; 

public:
	UPROPERTY(EditAnyWhere)
	float CubeSpeed = 5.0f;

	UPROPERTY(EditAnyWhere, META = (MakeEditWidget = true))
	FVector TargetLocation;

private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;

	
};
