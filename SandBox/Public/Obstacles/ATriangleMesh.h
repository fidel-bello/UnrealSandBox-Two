#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "ATriangleMesh.generated.h"

UCLASS()
class SANDBOX_API ATriangleMesh :public AActor
{
	GENERATED_BODY()

public:
	ATriangleMesh();

protected:
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

	UPROPERTY()
	UProceduralMeshComponent* ProceduralMeshComponent;
	
	UPROPERTY(EditAnywhere, Category = "Triangle")
	FVector Vertex0;

	UPROPERTY(EditAnywhere, Category = "Triangle")
	FVector Vertex1;

	UPROPERTY(EditAnywhere, Category = "Triangle")
	FVector Vertex2;

	UPROPERTY(EditAnywhere, Category = "Triangle")
	FVector Vertex3;
	
	UPROPERTY(EditAnywhere, Category="Triangle")
	UMaterialInterface* Material;

	void UpdateTriangle() const;
};