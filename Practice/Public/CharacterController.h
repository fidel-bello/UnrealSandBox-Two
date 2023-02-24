// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "TestCharacter.h"
#include "Components/ActorComponent.h"
#include "CharacterController.generated.h"

class UInputMappingContext;

UCLASS(Blueprintable, BlueprintType)
class PRACTICE_API ACharacterController final : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void SetupInputComponent() override;
	virtual void OnPossess(APawn* InPawn) override;
	void BindActions(UInputMappingContext* Context);

	UPROPERTY(BlueprintReadOnly, Category="TestCharacter")
	TObjectPtr<ATestCharacter> PossessedCharacter = nullptr;
	
protected:
	void ForwardMovementAction(const FInputActionValue &Value) const;
};
