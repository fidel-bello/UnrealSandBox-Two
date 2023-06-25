#include "SBBaseCharacter.h"
#include "Kismet/KismetMathLibrary.h"


ASBBaseCharacter::ASBBaseCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer){}

void ASBBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = 0;
	bReplicates = true;
	SetReplicatingMovement(true);
}

void ASBBaseCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	SetEssentialValues(DeltaSeconds);
	
	PreviousVelocity = GetVelocity();
	PreviousAimYaw = AimingRotation.Yaw;
}

void ASBBaseCharacter::SetEssentialValues(float DeltaTime)
{
	AimingRotation = FMath::RInterpTo(AimingRotation, ReplicatedControlRotation, DeltaTime, 30);
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


