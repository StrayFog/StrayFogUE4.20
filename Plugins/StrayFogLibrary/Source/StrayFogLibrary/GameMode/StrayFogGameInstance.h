// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "StrayFogGameInstance.generated.h"

/**
* GameInstance: high-level manager object for an instance of the running game.
* Spawned at game creation and not destroyed until game instance is shut down.
* Running as a standalone game, there will be one of these.
* Running in PIE (play-in-editor) will generate one of these per PIE instance.
*/
UCLASS()
class STRAYFOGLIBRARY_API UStrayFogGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	
	
	
};
