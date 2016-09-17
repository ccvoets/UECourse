// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "Grabber.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	//get the player viewpoint this tick 
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
	 OUT PlayerViewPointLocation,
	 OUT PlayerViewPointRotation
	);
	//log out to test
	//Draw Red Trace in World To Visualize
		FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach ;
	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		50.f
	); 
	/*UE_LOG(LogTemp, Warning, TEXT("SuperCow: %s, RotationMoo: %s"), *PlayerViewPointLocation.ToString(),*PlayerViewPointRotation.ToString());*/

	//setup query params
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner()); //template for starting simple traces 
	///ray cast out to reach distance which is editable with reach, editable from within UE 
	FHitResult Hit;
	
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters

	);
	
	AActor* ActorHit = Hit.GetActor();
	if (ActorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("mooing trace to %s"), *(ActorHit->GetName()));
	}
	//Get hit report

	//moo some too
	
	
}

