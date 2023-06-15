#include "SBBaseCharacter.h"
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
