#pragma once
#include "CoreMinimal.h"
#include "SBBaseCharacter.h"
#include "Components/TimelineComponent.h"
#include "SBPlayableCharacter.generated.h"

UCLASS(Blueprintable)
class SANDBOX_API ASBPlayableCharacter: public ASBBaseCharacter
{
	GENERATED_BODY()
public:
	ASBPlayableCharacter(const FObjectInitializer& ObjectInitializer);
	virtual void BeginPlay() override;
	void Tick(float DeltaSeconds) override;
	
	UPROPERTY(EditAnywhere, Category="Character | Camera")
	UCurveFloat* SpringArmSprintCurvature;
	
	UPROPERTY(EditAnywhere, Category = "Character | Camera", meta = (ClampMin = 0.0f, UIMin = 0.0f))
	float SpringArmLength = 400.0f;;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Character | Camera")
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Character | Camera")
	class UCameraComponent* CameraComponent;

private:
	FTimeline SprintArmTimeline;
	
	float DefaultSpringArmLength;
	
	void HandleSpringArm(float Value);
};
