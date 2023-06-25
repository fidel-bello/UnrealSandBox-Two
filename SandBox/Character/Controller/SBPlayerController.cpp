﻿// ReSharper disable CppMemberFunctionMayBeConst

#include "SBPlayerController.h"
#include "Engine/LocalPlayer.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Engine/LocalPlayer.h"
#include "Logging/LogMacros.h"
#include "SandBox/Character/SBPlayableCharacter.h"


void ASBPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	PossessedCharacter = Cast<ASBPlayableCharacter>(InPawn);
	if (PossessedCharacter->GetController()->IsLocalController())
	{
		UE_LOG(LogTemp, Warning, TEXT("Possessed!"));
	}
	
	SetupInputs();
}

void ASBPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->ClearActionEventBindings();
		EnhancedInputComponent->ClearActionValueBindings();
		EnhancedInputComponent->ClearDebugKeyBindings();
		
		BindActions(DefaultInputMappingContext);
	}
}

void ASBPlayerController::SetupInputs()
{
	if (PossessedCharacter)
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			FModifyContextOptions Options;
			Options.bForceImmediately = 1;
			Subsystem->AddMappingContext(DefaultInputMappingContext, 1, Options);
		}
	}
}

void ASBPlayerController::BindActions(UInputMappingContext* Context)
{
	if (Context)
	{
		const TArray<FEnhancedActionKeyMapping>& Mappings = Context->GetMappings();
		if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
		{
			TSet<const UInputAction*> UniqueActions;
			for (const FEnhancedActionKeyMapping& Keymapping : Mappings)
			{
				UniqueActions.Add(Keymapping.Action);
			}
			for (const UInputAction* UniqueAction : UniqueActions)
			{
				FString Action = UniqueAction ? UniqueAction->GetName(): "Action is Empty";
				UE_LOG(LogTemp, Warning, TEXT("Unique Action: %s"), *Action);
				EnhancedInputComponent->BindAction(UniqueAction, ETriggerEvent::Triggered, Cast<UObject>(this), UniqueAction->GetFName());
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Context"));
	}
}


void ASBPlayerController::ForwardMovementAction(const FInputActionValue& Value)
{
	if (PossessedCharacter)
	{
		PossessedCharacter->ForwardMovementAction(Value.GetMagnitude());
	}
}

