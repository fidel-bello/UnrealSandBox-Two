#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "States/CamPovState.h"  
#include "SBBaseCharacter.generated.h"

class ASBPlayerController;

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

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="SandBox|Input")
	void RightMovementAction(float Value);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="SandBox|Input")
	void IncreaseMovementSpeedAction();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="SandBox|Input")
	void DecreaseMovementSpeedAction();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="SandBox|Input")
	void SwitchPovAction();
	
protected:
	FRotator ReplicatedControlRotation = FRotator::ZeroRotator;
	FVector PreviousVelocity = FVector::ZeroVector;
	FRotator AimingRotation = FRotator::ZeroRotator;

	float PreviousAimYaw = 0.0f;
	
	void SetEssentialValues(float DeltaTime);

public:
	ECamPovState CurrentState = ECamPovState::First_Person;
};
