// Fill out your copyright notice in the Description page of Project Settings.

#include "RadarChartActor.h"

//�״�����
UProceduralMeshComponent * radarMesh;
//�״ﱳ������
UProceduralMeshComponent * radarMeshBg;
// Sets default values
ARadarChartActor::ARadarChartActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	radarMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Radar"));
	RootComponent = radarMesh;
	radarMesh->bUseAsyncCooking = true;


	/*radarMeshBg = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("RadarBg"));
	radarMeshBg->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	UE_LOG(LogTemp, Warning, TEXT("%s"), RootComponent);*/
}

// Called when the game starts or when spawned
void ARadarChartActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ARadarChartActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARadarChartActor::PostActorCreated()
{
	Super::PostActorCreated();
	CreateTriangle();
}

void ARadarChartActor::CreateTriangle()
{
	TArray<FVector> vertices;
	vertices.Add(FVector(0, 0, 0));
	vertices.Add(FVector(0, 100, 0));
	vertices.Add(FVector(0, 0, 100));

	TArray<int32> Triangles;
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);

	TArray<FVector> normals;
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));

	TArray<FVector2D> UV0;
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(10, 0));
	UV0.Add(FVector2D(0, 10));


	TArray<FProcMeshTangent> tangents;
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));

	TArray<FLinearColor> vertexColors;
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));

	radarMesh->CreateMeshSection_LinearColor(0, vertices, Triangles, normals, UV0, vertexColors, tangents, true);

	// Enable collision data
	radarMesh->ContainsPhysicsTriMeshData(true);

}
