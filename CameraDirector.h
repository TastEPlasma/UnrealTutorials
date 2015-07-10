// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CameraDirector.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(cameraDebug, Log, All);


USTRUCT()
struct FCameraShot
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
		AActor* CameraPtr;

	UPROPERTY(EditAnywhere)
		float fLifeTime;

	UPROPERTY(EditAnywhere)
		float fBlendTime;

	//For GC
	void Destroy()
	{
		CameraPtr = nullptr;
	}

	//Constructor
	FCameraShot()
	{
		CameraPtr = NULL;
		fLifeTime = 1.00f;
		fBlendTime = 0.75f;
	}
};


UCLASS()
class MYPROJECT_API ACameraDirector : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACameraDirector();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere)
		TArray<FCameraShot> arrayCameras;

	float TimeToNextCameraChange;
	int8 camSelector = 0;
};