#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "SBPlayerController.generated.h"

class UInputMappingContext;

UCLASS()
class SANDBOX_API ASBPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void SetPawn(APawn* InPawn) override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SandBox|Input")
	TObjectPtr<UInputMappingContext> DefaultInputMappingContext = nullptr;

protected:
	virtual void SetupInputComponent() override;
	void SetupInputs() const;
	void BindActions(const UInputMappingContext* Context);
	
	void ForwardMovementAction(const FInputActionValue& Value) const;

private:
	TSoftObjectPtr<class ASBBaseCharacter> CurrentCharacter = nullptr;
};
