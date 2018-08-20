// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "Components/SceneComponent.h"
#include "RadarChartActor.generated.h"

UCLASS()
class STRAYFOGLIBRARY_API ARadarChartActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARadarChartActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostActorCreated() override;

	void CreateTriangle();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Category = Radar, EditAnywhere)
		int PropertyNumber;

};
