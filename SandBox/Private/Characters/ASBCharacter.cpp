// Fill out your copyright notice in the Description page of Project Settings
#include "../../Public/Characters/ASBCharacter.h"
#include "GameFramework/Controller.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ASBCharacter::ASBCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->InitCapsuleSize(30.48f, 68.58f);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void ASBCharacter::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void ASBCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASBCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

