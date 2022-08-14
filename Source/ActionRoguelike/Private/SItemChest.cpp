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

void ASItemChest::interact_Implementation(APawn* InstigatorPawn)
{
	throw std::logic_error("The method or operation is not implemented.");
}

