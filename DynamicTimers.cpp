// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "DynamicTimers.h"

DEFINE_LOG_CATEGORY(timerDebug);

// Sets default values
ADynamicTimers::ADynamicTimers()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	currentCountDown = TimeToCountdown;

}

// Called when the game starts or when spawned
void ADynamicTimers::BeginPlay()
{
	Super::BeginPlay();
	
	if (bStartOnCreation == true)
	{
		StartCountDownStatus();
	}
}

// Called every frame
void ADynamicTimers::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ADynamicTimers::AdvanceTimer()
{
	currentCountDown--;
	if (currentCountDown < 1)
	{
		//We're done counting down, so stop running the timer
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		if (bDoInitialFunction == true)
		{
			CountdownHasFinished1();
		}
		else
		{
			CountdownHasFinished2();
		}
	}
}

//executed when bDoInitialFunction == true
void ADynamicTimers::CountdownHasFinished1_Implementation()
{
	//Change to a special readout
	UE_LOG(timerDebug, Warning, TEXT("NO ACTION ASSIGNED THIS 1 TIMER"));
}

//executed when bDoInitialFunction == false
void ADynamicTimers::CountdownHasFinished2_Implementation()
{
	//Change to a special readout
	UE_LOG(timerDebug, Warning, TEXT("NO ACTION ASSIGNED THIS 2 TIMER"));
}

void ADynamicTimers::ToggleCountDownStatus_Implementation()
{
	if (GetWorldTimerManager().IsTimerActive(this, &ADynamicTimers::AdvanceTimer))
	{
		GetWorldTimerManager().PauseTimer(this, &ADynamicTimers::AdvanceTimer);
	}
	else
	{
		GetWorldTimerManager().UnPauseTimer(this, &ADynamicTimers::AdvanceTimer);
	}
}

void ADynamicTimers::StartCountDownStatus()
{
	currentCountDown = TimeToCountdown;

	//sets the timer to advance and update once per second
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ADynamicTimers::AdvanceTimer, 1.0f, true);
}

void ADynamicTimers::StopCountDownStatus_Implementation()
{
	GetWorldTimerManager().ClearTimer(this, &ADynamicTimers::AdvanceTimer);
}

void ADynamicTimers::SwitchFunctionForFinishedCountdown()
{
	bDoInitialFunction = !bDoInitialFunction;
}