// Fill out your copyright notice in the Description page of Project Settings.


#include "SBlackholeProjectile.h"
#include "PhysicsEngine/RadialForceComponent.h"

ASBlackholeProjectile::ASBlackholeProjectile()
{
	RadialForceComp = CreateDefaultSubobject<URadialForceComponent>("RadialForce");
	RadialForceComp->SetupAttachment(RootComponent);
	RadialForceComp->Radius = 1000.f;
	RadialForceComp->ForceStrength = -100000000.f;
	RadialForceComp->bImpulseVelChange = false;
	RadialForceComp->AddCollisionChannelToAffect(ECC_WorldDynamic);
	RadialForceComp->AddCollisionChannelToAffect(ECC_WorldStatic);
	RadialForceComp->AddCollisionChannelToAffect(ECC_PhysicsBody);
}

