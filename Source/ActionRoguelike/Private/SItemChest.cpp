// Fill out your copyright notice in the Description page of Project Settings.


#include "SItemChest.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASItemChest::ASItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = BaseMeshComp;

	LidMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("LidMesh");
	LidMeshComp->SetupAttachment(BaseMeshComp);

	TargetPitch = 0.f;

}

// Called when the game starts or when spawned
void ASItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
	if (!bIsOpen)
	{
		//lid is closed, so open it
		bIsOpen = true;
		TargetPitch = 30.f;
	}
	else
	{
		//lid is open, so close it
		bIsOpen = false;
		TargetPitch = 0.f;
	}
	LidMeshComp->SetRelativeRotation(FRotator(TargetPitch, 0.f, 0.f));
}

