#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SBBaseCharacter.generated.h"

UCLASS(Abstract, NotBlueprintable)
class SANDBOX_API ASBBaseCharacter: public ACharacter
{

	GENERATED_BODY()
public:
	ASBBaseCharacter(const FObjectInitializer& ObjectInitializer);
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="SandBox|Input")
	void ForwardMovementAction(float Value);

protected:

	FRotator AimingRotation = FRotator::ZeroRotator;
};
