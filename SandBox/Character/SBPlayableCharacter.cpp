#include "SBPlayableCharacter.h"
#include  "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/TimelineComponent.h"


ASBPlayableCharacter::ASBPlayableCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bUsePawnControlRotation = true;
	DefaultSpringArmLength = SpringArmComponent->TargetArmLength;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->bUsePawnControlRotation = false;
}

void ASBPlayableCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (SpringArmSprintCurvature)
	{
		FOnTimelineFloatStatic SprintProgressFunction;
		SprintProgressFunction.BindUObject(this, &ASBPlayableCharacter::HandleSpringArm);
		SprintArmTimeline.AddInterpFloat(SpringArmSprintCurvature, SprintProgressFunction);
	}
}

void ASBPlayableCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	SprintArmTimeline.TickTimeline(DeltaSeconds);
}


void ASBPlayableCharacter::HandleSpringArm(float Value) const
{
	const float Result = FMath::Lerp<float>(DefaultSpringArmLength, SpringArmLength, Value);
	SpringArmComponent->TargetArmLength = Result;
}



