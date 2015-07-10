// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "CameraDirector.h"

#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY(cameraDebug);


// Sets default values
ACameraDirector::ACameraDirector()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float TimeBetweenCameraChanges = arrayCameras[camSelector].fLifeTime;
	const float SmoothBlendTime = arrayCameras[camSelector].fBlendTime;
	int8 sizeOfCameraArray = arrayCameras.Num();

	TimeToNextCameraChange -= DeltaTime;
	if (TimeToNextCameraChange <= 0.0f)
	{
		//adjust the time to next change, based on the setting for the next camera
		TimeToNextCameraChange += TimeBetweenCameraChanges;

		// Find the actor that handles control for the local player.
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			//check that a camera actor has been assigned in the editor
			if (arrayCameras[camSelector].CameraPtr != NULL)
			{
				//if so, blend to new camera
				OurPlayerController->SetViewTargetWithBlend(arrayCameras[camSelector].CameraPtr, SmoothBlendTime);
			}
			camSelector++;
			if (camSelector >= sizeOfCameraArray)
			{
				//when array of cameras is finished, return to first camera
				camSelector = 0;
			}
		}
	}
}
