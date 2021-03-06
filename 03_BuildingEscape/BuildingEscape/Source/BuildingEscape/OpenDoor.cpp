// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	Owner = GetOwner();
	// ...
	
}

void UOpenDoor::OpenDoor()
{


	//Create rotator 
	FRotator NewRotation = FRotator(0.f, OpenAngle, 0.f);
	//Set Rotation
	Owner->SetActorRotation(NewRotation);

}

void UOpenDoor::CloseDoor()
{
	
	//Create rotator 
	FRotator NewRotation = FRotator(0.f, 0.f, 0.f);
	//Set Rotation
	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))//Poll trigger volume if the actorthatopens is in the volume then open the door
		{
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	//check if its time to close door 
	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay )
	{
		
		CloseDoor();
		
	}
	
	}

