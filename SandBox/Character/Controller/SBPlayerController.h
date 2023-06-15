#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SBPlayerController.generated.h"

UCLASS()
class SANDBOX_API ASBPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void SetPawn(APawn* InPawn) override;
protected:
	virtual void SetupInputComponent() override;
private:
	TSoftObjectPtr<class ASBBaseCharacter> CurrentCharacter;
};
