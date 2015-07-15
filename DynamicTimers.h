// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DynamicTimers.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(timerDebug, Log, All);


UCLASS()
class MYPROJECT_API ADynamicTimers : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADynamicTimers();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//Duration of count down
	UPROPERTY(EditAnywhere)
		int32 TimeToCountdown = 3;

	//Being count down when play starts
	UPROPERTY(EditAnywhere)
		bool bStartOnCreation = true;

	int32 currentCountDown;

	bool bDoInitialFunction = true;

	FTimerHandle CountdownTimerHandle;

	void AdvanceTimer();

	UFUNCTION(BlueprintNativeEvent)
		void CountdownHasFinished1();
	virtual void CountdownHasFinished1_Implementation();

	UFUNCTION(BlueprintNativeEvent)
		void CountdownHasFinished2();
	virtual void CountdownHasFinished2_Implementation();

	UFUNCTION(BlueprintNativeEvent)
		void ToggleCountDownStatus();
	virtual void ToggleCountDownStatus_Implementation();

	UFUNCTION(BlueprintNativeEvent)
		void StopCountDownStatus();
	virtual void StopCountDownStatus_Implementation();

	UFUNCTION(BlueprintCallable, Category = "TestBed")
		void StartCountDownStatus();
	
	UFUNCTION(BlueprintCallable, Category = "TestBed")
		void SwitchFunctionForFinishedCountdown();
};
