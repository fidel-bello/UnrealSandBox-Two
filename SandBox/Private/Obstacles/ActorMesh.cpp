// Fill out your copyright notice in the Description page of Project Settings.
#include "../../Public/Obstacles/ActorMesh.h"

// Sets default values
AActorMesh::AActorMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AActorMesh::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

