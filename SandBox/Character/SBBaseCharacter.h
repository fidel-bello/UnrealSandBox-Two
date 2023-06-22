#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SandBox/Components/Movement/SBCharacterMovementComponent.h"
#include "SBBaseCharacter.generated.h"

class USBCharacterMovementComponent;

UCLASS(Abstract, NotBlueprintable)
class SANDBOX_API ASBBaseCharacter: public ACharacter
{

	GENERATED_BODY()
public:
	ASBBaseCharacter(const FObjectInitializer& Initializer);
	virtual void BeginPlay() override;
	void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SandBox|Input")
	void ForwardMovementAction(const FInputActionValue& Value);
	
	FORCEINLINE USBCharacterMovementComponent* GetBaseCharacterMovementComponent() const { return SBCharacterMovementComponent; }
	
protected:

	
	// ReSharper disable once CppUE4ProbableMemoryIssuesWithUObject
	USBCharacterMovementComponent* SBCharacterMovementComponent;

	
	FRotator AimingRotation = FRotator::ZeroRotator;
};
