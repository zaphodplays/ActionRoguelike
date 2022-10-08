// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class USInteractionComponent;

UCLASS()
class ACTIONROGUELIKE_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
	UAnimMontage* AnimMontage;

	UPROPERTY(EditAnywhere, Category = "Attack");
	float Attack_TimeDelay = 0.2f;

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> WarpProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> DashProjectileClass;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, Category = "Debug")
	bool bDebugOn;

	USInteractionComponent* InteractionComp;

	FTimerHandle TimerHandle_PrimaryAttack;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);

	void MoveRight(float Value);

	void PrimaryAttack();

	void WarpAttack();

	void DashProjectileAttack();

	void Jump();

	void PrimaryAttack_TimeElapsed();

	void PrimaryInteract();

	UFUNCTION(BlueprintCallable)
	void TeleportPlayer(const FVector& Location);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void SetupAttack(FActorSpawnParameters& SpawnParams, FTransform& SpawnTM);

	

	void TeleportToLocationAndRotation(FVector Location, FRotator Rotation);

};
