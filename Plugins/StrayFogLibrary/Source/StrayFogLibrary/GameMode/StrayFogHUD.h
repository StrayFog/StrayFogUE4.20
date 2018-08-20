// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UMG/Window/UserWindow.h"
#include "StrayFogHUD.generated.h"

/**
 * HUD class this game uses. 
 */
UCLASS()
class STRAYFOGLIBRARY_API AStrayFogHUD : public AHUD
{
	GENERATED_BODY()
public:
	UUserWindow * CreateUserWindow(UObject* WorldContextObject, TSubclassOf<class UUserWindow> WidgetType, APlayerController* OwningPlayer);	
	UUserWindow* GetUserWindow(TSubclassOf<class UUserWindow> WidgetType);
	bool ExistsUserWindow(TSubclassOf<class UUserWindow> WidgetType);
private:
	TMap<uint32, UUserWindow*> WindowCacheMaping;
};
