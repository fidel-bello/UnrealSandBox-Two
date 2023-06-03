#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "ActorMesh.generated.h"

UCLASS()
class SANDBOX_API AActorMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	AActorMesh();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere ,Category="Mesh")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	USceneComponent* Root;
};
