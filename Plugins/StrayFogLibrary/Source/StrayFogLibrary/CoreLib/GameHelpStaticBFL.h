// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameMode/StrayFogGameMode.h"
#include "GameHelpStaticBFL.generated.h"

/**
 * UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (WorldContext = "WorldContextObject"),Category="StrayFog|CoreLib")
 */
UCLASS()
class STRAYFOGLIBRARY_API UGameHelpStaticBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
};
