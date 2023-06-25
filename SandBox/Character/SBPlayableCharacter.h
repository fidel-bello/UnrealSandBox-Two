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
	virtual void Tick(float DeltaSeconds) override;
	
	UPROPERTY(EditAnywhere, Category="SandBox|Camera")
	UCurveFloat* SpringArmSprintCurvature;
	
	UPROPERTY(EditAnywhere, Category = "SandBox|Camera", meta = (ClampMin = 0.0f, UIMin = 0.0f))
	float SpringArmLength = 300.f;

	
protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SandBox|Camera")
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SandBox|Camera")
	class UCameraComponent* CameraComponent;


private:
	FTimeline SprintArmTimeline;
	
	float DefaultSpringArmLength;
	
	void HandleSpringArm(float Value) const;
};
