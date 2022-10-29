// Fill out your copyright notice in the Description page of Project Settings.


#include "SMagicProjectile.h"
#include <Components/SphereComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
#include <Particles/ParticleSystemComponent.h>
#include "SAttributeComponent.h"

// Sets default values
ASMagicProjectile::ASMagicProjectile()
{
	
}

// Called when the game starts or when spawned
void ASMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASMagicProjectile::onActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!IsValid(OtherActor))
		return;

	AActor* instigator = GetInstigator();
	if (IsValid(instigator) && OtherActor == instigator)
		return;

	USAttributeComponent* AttributeComp = Cast<USAttributeComponent>(OtherActor->GetComponentByClass(USAttributeComponent::StaticClass()));
	if (!IsValid(AttributeComp))
		return;

	AttributeComp->ApplyHealthChange(-5.f);

	Destroy();
}

// Called every frame
void ASMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

