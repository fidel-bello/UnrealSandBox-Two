#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "GameFramework/PlayerController.h"
#include "SBPlayerController.generated.h"

class ASBPlayableCharacter;
class UInputMappingContext;

UCLASS(Blueprintable, BlueprintType)
class SANDBOX_API ASBPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void SetupInputComponent() override;
	virtual void BindActions(UInputMappingContext* Context);

protected:
	void SetupInputs();
	
	UFUNCTION()
	void ForwardMovementAction(const FInputActionValue& Value);
	
	UFUNCTION()
	void RightMovementAction(const FInputActionValue& Value);

public:
	UPROPERTY(BlueprintReadOnly, Category="SandBox")
	TSoftObjectPtr<ASBPlayableCharacter> PossessedCharacter;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SandBox|Input")
	TObjectPtr<UInputMappingContext> DefaultInputMappingContext = nullptr;
};
