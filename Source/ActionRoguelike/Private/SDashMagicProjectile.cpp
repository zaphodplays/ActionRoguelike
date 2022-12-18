// Fill out your copyright notice in the Description page of Project Settings.


#include "SDashMagicProjectile.h"
#include <GameFramework/ProjectileMovementComponent.h>
#include <Particles/ParticleSystemComponent.h>
#include <Kismet/GameplayStatics.h>

ASDashMagicProjectile::ASDashMagicProjectile()
{
	TeleportDelay = 0.2f;
	DetonateDelay = 0.2f;
	MovementComp->InitialSpeed = 6000.f;
}

// Called when the game starts or when spawned
void ASDashMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_DelayedDetonate, this, &ASDashMagicProjectile::Explode, DetonateDelay);

}

void ASDashMagicProjectile::TeleportInstigator()
{
	AActor* ActorToTeleport = GetInstigator();
	if (ensure(IsValid(ActorToTeleport)))
	{
		ActorToTeleport->TeleportTo(GetActorLocation(), GetActorRotation(), false, false);
	}
}

void ASDashMagicProjectile::Explode_Implementation()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle_DelayedDetonate);
	UGameplayStatics::SpawnEmitterAtLocation(this, ImpactVFX, GetActorLocation(), GetActorRotation());

	EffectComp->DeactivateSystem();
	MovementComp->StopMovementImmediately();
	SetActorEnableCollision(false);

	FTimerHandle TimerHandle_TelportDelay;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_TelportDelay, this, &ASDashMagicProjectile::TeleportInstigator, TeleportDelay);
}