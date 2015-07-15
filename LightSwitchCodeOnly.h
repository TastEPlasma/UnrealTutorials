// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "LightSwitchCodeOnly.generated.h"

UCLASS()
class MYPROJECT_API ALightSwitchCodeOnly : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALightSwitchCodeOnly(const FObjectInitializer& ObjectInitializer);

	/** point light component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Switch Components")
	class UPointLightComponent* PointLight1;

	/** sphere component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Switch Components")
	class USphereComponent* Sphere1;

	/** called when something enters the sphere component */
	UFUNCTION(BlueprintNativeEvent)
		void OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/** called when something leaves the sphere component */
	UFUNCTION(BlueprintNativeEvent)
		void OnOverlapEnd(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	/** Toggles the light component's visibility*/
	UFUNCTION()
		void ToggleLight();

	/** the desired intensity for the light */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Switch Variables")
		float DesiredIntensity;

};
