#include "Editor/LevelEditor/Public/LevelEditor.h"
#include "../../../Public/Obstacles/Triangle/ATriangleMesh.h"


ATriangleMesh::ATriangleMesh()
{
	PrimaryActorTick.bCanEverTick = true;
	ProceduralMeshComponent = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMeshComponent"));
	SetRootComponent(ProceduralMeshComponent);
	
	Material = nullptr;
}

void ATriangleMesh::BeginPlay()
{
	Super::BeginPlay();
}

void ATriangleMesh::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	UpdateTriangle();

	if (ProceduralMeshComponent && Material)
	{
		ProceduralMeshComponent->SetMaterial(0, Material);
	}
#if WITH_EDITOR

	SetActorHiddenInGame(false);

#endif
}




void ATriangleMesh::UpdateTriangle()
{
	TArray<FVector> Vertices;
	Vertices.Add(Vertex0);         // Vertex 0
	Vertices.Add(Vertex1);       // Vertex 1
	Vertices.Add(Vertex2);       // Vertex 2
	Vertices.Add(Vertex3);     // Vertex 3
	// Define the pyramid indices
	TArray<int32> Triangles;
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);

	Triangles.Add(0);
	Triangles.Add(2);
	Triangles.Add(3);

	Triangles.Add(0);
	Triangles.Add(3);
	Triangles.Add(1);

	Triangles.Add(1);
	Triangles.Add(3);
	Triangles.Add(2);

	// Calculate Pyramid Normals
	TArray<FVector> Normals;
	for (int32 i = 0; i < 4; i++)
	{
		Normals.Add(FVector(0, 0, 1));
	}
	// Calculate the UV coordinates
	TArray<FVector2D> UVs;
	UVs.Add(FVector2D(0, 0));
	UVs.Add(FVector2D(1, 0));
	UVs.Add(FVector2D(0, 1));
	UVs.Add(FVector2D(0.5, 0.5));
	
	ProceduralMeshComponent->CreateMeshSection(0, Vertices, Triangles, Normals, UVs, TArray<FColor>(), TArray<FProcMeshTangent>(), true);
}


