// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Library/TestCharacterEnumLibrary.h"
#include "BaseTestCharacter.generated.h"

UCLASS(BlueprintType)
class PRACTICE_API ABaseTestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseTestCharacter();

	UFUNCTION(BlueprintCallable, Category = "TestCharacterEssential Information")
	FRotator GetAimingRotation() const { return AimingRotation; }

	UPROPERTY(BlueprintReadOnly, Category = "TestCharacterState Values")
	EMovementState MovementState = EMovementState::None;

	UPROPERTY(BlueprintReadOnly, Category = "TestCharacterState Values")
	EMovementState PrevMovementState = EMovementState::None;

	UFUNCTION(BlueprintCallable, Category = "TestCharacter States")
	void SetMovementState(EMovementState NewState, bool bForce = false);
	
	UFUNCTION(BlueprintGetter, Category = "TestCharacter States")
	EMovementState GetMovementState() const { return MovementState; }

	UFUNCTION(BlueprintGetter, Category = "ALS|Character States")
	EMovementState GetPrevMovementState() const { return PrevMovementState; }
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inputs")
	void ForwardMovementAction(float Value);

protected:
	virtual void BeginPlay() override;
	
	FRotator AimingRotation = FRotator::ZeroRotator;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
