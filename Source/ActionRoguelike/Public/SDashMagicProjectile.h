// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SMagicProjectile.h"
#include "SDashMagicProjectile.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASDashMagicProjectile : public ASMagicProjectile
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
};
