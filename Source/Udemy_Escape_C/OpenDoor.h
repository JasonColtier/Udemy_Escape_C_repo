// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UDEMY_ESCAPE_C_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);

private:

float initialYaw;
float targetYaw;

UPROPERTY(EditAnywhere)
float openAngle = 90.f;

UPROPERTY(EditAnywhere)
float speed = 0.1f;

UPROPERTY(EditAnywhere)
ATriggerVolume* PressurePlate;

UPROPERTY(EditAnywhere)
AActor* ActorOpener; 

};
