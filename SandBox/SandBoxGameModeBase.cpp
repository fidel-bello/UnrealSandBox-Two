// Copyright Epic Games, Inc. All Rights Reserved.


#include "SandBoxGameModeBase.h"
#include "Characters/ASBCharacter.h"
#include "GameFramework/PlayerController.h"

ASandBoxGameModeBase::ASandBoxGameModeBase()
{
	DefaultPawnClass = ASBCharacter::StaticClass();
	PlayerControllerClass = ASBCharacter::StaticClass();
}
