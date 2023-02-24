// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTestCharacter.h"

#include "Kismet/KismetMathLibrary.h"
#include "Library/TestCharacterEnumLibrary.h"


ABaseTestCharacter::ABaseTestCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
}

void ABaseTestCharacter::SetMovementState(const EMovementState NewState, const bool bForce)
{
	if(bForce || MovementState != NewState)
	{
		PrevMovementState = MovementState;
		MovementState = NewState;
	}
}

void ABaseTestCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}
void ABaseTestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void ABaseTestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABaseTestCharacter::ForwardMovementAction_Implementation(const float Value)
{
	if(MovementState == EMovementState::Grounded)
	{
		const FRotator DirRotation(0.0f, AimingRotation.Yaw, 0.0f);
		AddMovementInput(UKismetMathLibrary::GetRightVector(DirRotation), Value);
	}
}


