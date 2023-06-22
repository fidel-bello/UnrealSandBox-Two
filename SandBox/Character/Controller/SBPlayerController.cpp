﻿#include "SBPlayerController.h"
#include "Engine/LocalPlayer.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "SandBox/Character/SBBaseCharacter.h"

void ASBPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	CurrentCharacter = Cast<ASBBaseCharacter>(InPawn);

	if (CurrentCharacter.IsValid())
	{
		APawn* MainCharacter = CurrentCharacter.Get();
		OnPossess(MainCharacter);
		BindActions(DefaultInputMappingContext);
	}
}


void ASBPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->ClearActionEventBindings();
		EnhancedInputComponent->ClearActionValueBindings();
		EnhancedInputComponent->ClearDebugKeyBindings();
	}
	else
	{
		UE_LOG(LogTemp, Fatal, TEXT("Sandbox Community requires Enhanced Input System to be activated in project settings to function properly"));
	}
	
}

void ASBPlayerController::SetupInputs() const
{
	if (CurrentCharacter)
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			FModifyContextOptions Options;
			Options.bForceImmediately = 1;
			Subsystem->AddMappingContext(DefaultInputMappingContext, 1, Options);
		}
	}
}

void ASBPlayerController::BindActions(const UInputMappingContext* Context)
{
	if (Context)
	{
		const TArray<FEnhancedActionKeyMapping>& Mappings = Context->GetMappings();
		if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
		{
			// There may be more than one keymapping assigned to one action. So, first filter duplicate action entries to prevent multiple delegate bindings
			TSet<const UInputAction*> UniqueActions;
			for (const FEnhancedActionKeyMapping& Keymapping : Mappings)
			{
				UniqueActions.Add(Keymapping.Action);
			}
			for (const UInputAction* UniqueAction : UniqueActions)
			{
				EnhancedInputComponent->BindAction(UniqueAction, ETriggerEvent::Triggered, Cast<UObject>(this), UniqueAction->GetFName());
			}
		}
	}
}

void ASBPlayerController::ForwardMovementAction(const FInputActionValue& Value) const
{
	if (CurrentCharacter)
	{

		CurrentCharacter->ForwardMovementAction(Value.GetMagnitude());
	}
	
}

