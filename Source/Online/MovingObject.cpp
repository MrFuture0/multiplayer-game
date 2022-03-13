// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingObject.h"

AMovingObject::AMovingObject()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingObject::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority()) //Eger bu sahibinin ekrani ise   
	{
		SetReplicates(true); // bu aktor ag istemcilerine eslenip kopyalansin
		SetReplicateMovement(true); // bu aktorun hareketleri ag istemcilerine kopyalansin
	}
	GlobalStartLocation  = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector CubeLocation = GetActorLocation(); //Kubun lokasyonunu al
		float journeyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
		float journeyTravelled = (CubeLocation - GlobalStartLocation).Size();

		if (journeyTravelled >= journeyLength)
		{
			FVector Swap = GlobalStartLocation;
			GlobalStartLocation = GlobalTargetLocation;
			GlobalTargetLocation = Swap;
		}
		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		CubeLocation += CubeSpeed * Direction * DeltaTime;
		SetActorLocation(CubeLocation);
	}

}
