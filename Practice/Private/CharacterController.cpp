// Copyright: Fidel Bello. All rights reserved

#include "CharacterController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Engine/LocalPlayer.h"

//TODO: DEBUG MESSAGE NOT RESPONDiNG

void ACharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->ClearActionBindings();
		EnhancedInputComponent->ClearActionValueBindings();
		EnhancedInputComponent->ClearDebugKeyBindings();
	}
}

void ACharacterController::BindActions(UInputMappingContext* Context)
{
	if(Context)
	{
		const TArray<FEnhancedActionKeyMapping>& Mappings = Context->GetMappings();
		if(UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
		{
			TSet<const UInputAction*> UniqueActions;
			for(const FEnhancedActionKeyMapping& KeyMapping : Mappings)
			{
				UniqueActions.Add(KeyMapping.Action);
			}
			for(const UInputAction* UniqueAction: UniqueActions)
			{
				EnhancedInputComponent->BindAction(UniqueAction, ETriggerEvent::Triggered, Cast<UObject>(this), UniqueAction->GetFName());
			}
		}
			
	}
}

void ACharacterController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	PossessedCharacter = Cast<ATestCharacter>(InPawn);
	if (PossessedCharacter)
	{
		GEngine->AddOnScreenDebugMessage(0, 1.f, FColor::Cyan, TEXT("Hello this is possessed"));
	}
}

void ACharacterController::ForwardMovementAction(const FInputActionValue& Value) const
{
	if(PossessedCharacter)
	{
		PossessedCharacter->ForwardMovementAction(Value.GetMagnitude());
	}
}
