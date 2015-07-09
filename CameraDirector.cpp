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
void ACameraDirector::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	const float TimeBetweenCameraChanges = 2.0f;
	const float SmoothBlendTime = 0.75f;
	TimeToNextCameraChange -= DeltaTime;
	int8 sizeOfCameraArray = arrayCameras.Num();
	if (TimeToNextCameraChange <= 0.0f)
	{
		TimeToNextCameraChange += TimeBetweenCameraChanges;

		// Find the actor that handles control for the local player.
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			// Make sure that some cameras have been added to array in-editor
			if (sizeOfCameraArray > 0)
			{
				OurPlayerController->SetViewTargetWithBlend(arrayCameras[camSelector], SmoothBlendTime);
				camSelector++;

				//check against out of bounds for the array, and reset to first camera as needed
				if (camSelector >= sizeOfCameraArray)
				{
					camSelector = 0;
				}
			}
		}
	}
}

