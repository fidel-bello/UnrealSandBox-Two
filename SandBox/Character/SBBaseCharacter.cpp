#include "SBBaseCharacter.h"
#include "Kismet/KismetMathLibrary.h"


ASBBaseCharacter::ASBBaseCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer){}

void ASBBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ASBBaseCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ASBBaseCharacter::ForwardMovementAction_Implementation(float Value)
{
	
	const FRotator DirRotator(0.0f, AimingRotation.Yaw = 90.0f, 0.0f);
	AddMovementInput(UKismetMathLibrary::GetForwardVector(DirRotator), Value);
}


