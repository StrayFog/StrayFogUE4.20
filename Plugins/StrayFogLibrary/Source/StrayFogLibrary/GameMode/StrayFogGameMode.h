// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "StrayFogGameMode.generated.h"

/**
* The GameModeBase defines the game being played. It governs the game rules, scoring, what actors
* are allowed to exist in this game type, and who may enter the game.
*
* It is only instanced on the server and will never exist on the client.
*
* A GameModeBase actor is instantiated when the level is initialized for gameplay in
* C++ UGameEngine::LoadMap().
*
* The class of this GameMode actor is determined by (in order) either the URL ?game=xxx,
* the GameMode Override value set in the World Settings, or the DefaultGameMode entry set
* in the game's Project Settings.
*
* @see https://docs.unrealengine.com/latest/INT/Gameplay/Framework/GameMode/index.html
*/
UCLASS()
class STRAYFOGLIBRARY_API AStrayFogGameMode : public AGameMode
{
	GENERATED_BODY()
	
	
	
	
};
