#include "SBPlayableCharacter.h"
#include  "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/TimelineComponent.h"

#include "GameFramework/CharacterMovementComponent.h"


ASBPlayableCharacter::ASBPlayableCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bUsePawnControlRotation = true;
	DefaultSpringArmLength = SpringArmComponent->TargetArmLength;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->bUsePawnControlRotation = false;
	
	
	GetCharacterMovement()->bOrientRotationToMovement = 1;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
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



