#include "SBBaseCharacter.h"

#include "InputActionValue.h"
#include "Kismet/KismetMathLibrary.h"
#include "SandBox/Components/Movement/SBCharacterMovementComponent.h"

ASBBaseCharacter::ASBBaseCharacter(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer.SetDefaultSubobjectClass<USBCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	SBCharacterMovementComponent = StaticCast<USBCharacterMovementComponent*>(GetCharacterMovement());
}

void ASBBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}



void ASBBaseCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ASBBaseCharacter::ForwardMovementAction_Implementation(const FInputActionValue& Value)
{
	const FRotator DirRotator(0.0f, AimingRotation.Yaw, 0.0f);
	AddMovementInput(UKismetMathLibrary::GetForwardVector(DirRotator), Value.GetMagnitude());
}
