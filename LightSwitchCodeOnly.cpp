// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "LightSwitchCodeOnly.h"


// Sets default values
ALightSwitchCodeOnly::ALightSwitchCodeOnly(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DesiredIntensity = 3000.0f;

	PointLight1 = ObjectInitializer.CreateDefaultSubobject<UPointLightComponent>(this, "PointLight1");
	PointLight1->Intensity = DesiredIntensity;
	PointLight1->bVisible = true;
	RootComponent = PointLight1;

	Sphere1 = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("Sphere1"));
	Sphere1->InitSphereRadius(250.0f);
	Sphere1->AttachParent = RootComponent;

	Sphere1->OnComponentBeginOverlap.AddDynamic(this, &ALightSwitchCodeOnly::OnOverlapBegin);        // set up a notification for when this component overlaps something
	Sphere1->OnComponentEndOverlap.AddDynamic(this, &ALightSwitchCodeOnly::OnOverlapEnd);      // set up a notification for when this component overlaps something


}

void ALightSwitchCodeOnly::OnOverlapBegin_Implementation(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

void ALightSwitchCodeOnly::OnOverlapEnd_Implementation(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

void ALightSwitchCodeOnly::ToggleLight()
{
	PointLight1->ToggleVisibility();
}
