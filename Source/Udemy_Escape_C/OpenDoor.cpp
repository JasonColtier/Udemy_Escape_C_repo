// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// FRotator initialRot = GetOwner()->GetActorRotation();
	
	// FRotator newRot = FRotator(initialRot.Roll,initialRot.Pitch,initialRot.Yaw+90.f);

	// GetOwner()->SetActorRotation(newRot);
	UE_LOG(LogTemp, Warning, TEXT("my yaw is %f"),GetOwner()->GetActorRotation().Yaw);

	initialYaw = GetOwner()->GetActorRotation().Yaw;
	targetYaw = initialYaw + openAngle;

	if(!PressurePlate){
		UE_LOG(LogTemp, Error, TEXT("This actor %s doesnt have any pressure plate"),*GetOwner()->GetName());
	}
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(PressurePlate && PressurePlate->IsOverlappingActor(ActorOpener)){
		OpenDoor(DeltaTime);
	}

	// ...
}

void UOpenDoor::OpenDoor(float DeltaTime){
	FRotator DoorRot = GetOwner()->GetActorRotation();

	DoorRot.Yaw = FMath::Lerp(GetOwner()->GetActorRotation().Yaw,targetYaw,speed * DeltaTime);

	GetOwner()->SetActorRotation(DoorRot);
}

