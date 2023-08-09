#include "SBPlayableCharacter.h"
#include  "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/TimelineComponent.h"

ASBPlayableCharacter::ASBPlayableCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	const FVector CurrentSize = GetActorScale3D();
	
	CurrentHeight = GetCapsuleComponent()->GetScaledCapsuleHalfHeight() * 2;
	Height = 187.0f;
	EyeHeight = 172.0f;
	
	const float ScaleFactor = Height / CurrentHeight;
	
	SetActorScale3D(FVector(UE::Math::TVector2<double>(CurrentSize.X * ScaleFactor), CurrentSize.Z * ScaleFactor));
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bUsePawnControlRotation = true;
	DefaultSpringArmLength = SpringArmComponent->TargetArmLength;
	
	FpCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person"));
	FpCamera->SetupAttachment(GetCapsuleComponent());
	FpCamera->SetRelativeLocation(FVector(0.0f, 0.0f, 83));
	FpCamera->bUsePawnControlRotation = false;

	TpCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Third Person"));
	TpCamera->SetupAttachment(SpringArmComponent);
	TpCamera->bUsePawnControlRotation = false;

	HCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Helmet Camera"));
	HCamera->SetupAttachment(RootComponent);
	HCamera->SetRelativeLocation(FVector(-8.56f, 18.52,  18.0f + BaseEyeHeight));
	HCamera->bUsePawnControlRotation = false;
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







