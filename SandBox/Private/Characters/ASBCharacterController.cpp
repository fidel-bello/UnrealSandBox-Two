// Fill out your copyright notice in the Description page of Project Settings.
#include "../../Public/Characters/ASBCharacterController.h"

#include "Characters/ASBCharacter.h"

void ASBCharacterController::BeginPlay()
{
	Super::BeginPlay();
	if (IsLocalPlayerController())
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Owner = this;
		SpawnParameters.Instigator = GetInstigator();

		if (ASBCharacter* LocalCharacter = GetWorld()->SpawnActor<ASBCharacter>(ASBCharacter::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParameters))
		{
			SetPawn(LocalCharacter);
		}
	}
}






