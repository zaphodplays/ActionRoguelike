// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SProjectile.h"
#include "CoreMinimal.h"
#include "SDashMagicProjectile.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASDashMagicProjectile : public ASProjectile
{
	GENERATED_BODY()

public:
	ASDashMagicProjectile();

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Teleport")
	float TeleportDelay;

	UPROPERTY(EditDefaultsOnly, Category = "Detonate")
	float DetonateDelay;

	//handle to cancel timer if already hit something
	FTimerHandle TimerHandle_DelayedDetonate;

	virtual void BeginPlay() override;

	virtual void Explode_Implementation() override;

	void TeleportInstigator();
	
};
