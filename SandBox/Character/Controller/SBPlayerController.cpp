#include "SBPlayerController.h"

#include "SandBox/Character/SBBaseCharacter.h"


void ASBPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	CurrentCharacter = Cast<ASBBaseCharacter>(InPawn);
}


void ASBPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}

