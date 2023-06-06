// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ASBCharacter.generated.h"

UCLASS()
class SANDBOX_API ASBCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASBCharacter();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
