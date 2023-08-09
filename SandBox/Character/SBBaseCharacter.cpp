#include "SBBaseCharacter.h"
#include "SBPlayableCharacter.h"
#include "Camera/CameraComponent.h"
#include "Templates/UniquePtr.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"


ASBBaseCharacter::ASBBaseCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer){}

void ASBBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = 0;
	bReplicates = true;
	
	GetCharacterMovement()->MaxWalkSpeed = 150.f;
	SetReplicatingMovement(true);
}


void ASBBaseCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	SetEssentialValues(DeltaSeconds);
	
	PreviousVelocity = GetVelocity();
	PreviousAimYaw = AimingRotation.Yaw;
}


void ASBBaseCharacter::SwitchPovAction_Implementation()
{
	// Accessing data from derived class through pointer
	if (const ASBPlayableCharacter* PlayableCharacterPointer = Cast<ASBPlayableCharacter>(this))
	{
		
		if (PlayableCharacterPointer->FpCamera->IsActive())
		{
			CurrentState = ECamPovState::First_Person;
		}
		else if (PlayableCharacterPointer->TpCamera->IsActive())
		{
			CurrentState = ECamPovState::Third_Person;
		}
		else if (PlayableCharacterPointer->HCamera->IsActive())
		{
			CurrentState = ECamPovState::Helmet_Camera;
		}

		switch (CurrentState)
		{
		case ECamPovState::First_Person:
			PlayableCharacterPointer->FpCamera->Deactivate();
			PlayableCharacterPointer->HCamera->Deactivate();
			PlayableCharacterPointer->TpCamera->Activate();
			break;

		case ECamPovState::Third_Person:
			PlayableCharacterPointer->TpCamera->Deactivate();
			PlayableCharacterPointer->FpCamera->Deactivate();
			PlayableCharacterPointer->HCamera->Activate();
			break;

		case ECamPovState::Helmet_Camera:
			PlayableCharacterPointer->HCamera->Deactivate();
			PlayableCharacterPointer->TpCamera->Deactivate();
			PlayableCharacterPointer->FpCamera->Activate();
			break;
		default:
			break;
		}
	}

}


void ASBBaseCharacter::IncreaseMovementSpeedAction_Implementation()
{
	if (GetCharacterMovement()->GetMaxSpeed() <= 160.f)
	{
		const float Add = GetCharacterMovement()->MaxCustomMovementSpeed = 10.f;
		const float Speed = GetCharacterMovement()->GetMaxSpeed();

		GetCharacterMovement()->MaxWalkSpeed = Speed + Add;
	}
}

void ASBBaseCharacter::DecreaseMovementSpeedAction_Implementation()
{
	if (GetCharacterMovement()->GetMaxSpeed() >= 10.f)
	{
		const float Subtract = GetCharacterMovement()->MaxCustomMovementSpeed = 5.f;
		const float Speed = GetCharacterMovement()->GetMaxSpeed();
		GetCharacterMovement()->MaxWalkSpeed  = Speed - Subtract;
	}
}


void ASBBaseCharacter::ForwardMovementAction_Implementation(float Value)
{
	
	const FRotator DirRotator(0.0f, AimingRotation.Yaw = 0.0f, 0.0f);
	AddMovementInput(UKismetMathLibrary::GetForwardVector(DirRotator), Value);
}

void ASBBaseCharacter::RightMovementAction_Implementation(float Value)
{
	const FRotator DirRotator(0.0f, AimingRotation.Yaw, 0.0f);
	AddMovementInput(UKismetMathLibrary::GetRightVector(DirRotator), Value);
}


void ASBBaseCharacter::SetEssentialValues(float DeltaTime)
{
	AimingRotation = FMath::RInterpTo(AimingRotation, ReplicatedControlRotation, DeltaTime, 30);
}







