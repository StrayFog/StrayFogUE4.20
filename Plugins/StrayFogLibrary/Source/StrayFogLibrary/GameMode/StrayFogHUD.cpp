// Fill out your copyright notice in the Description page of Project Settings.
#include "StrayFogHUD.h"
#include "WidgetBlueprintLibrary.h"


UUserWindow*  AStrayFogHUD::CreateUserWindow(UObject* WorldContextObject, TSubclassOf<class UUserWindow> WidgetType, APlayerController* OwningPlayer)
{
	uint32 key = WidgetType->GetUniqueID();
	if (!WindowCacheMaping.Contains(key))
	{
		WindowCacheMaping.Add(key, Cast<UUserWindow>(UWidgetBlueprintLibrary::Create(WorldContextObject, WidgetType, OwningPlayer)));
	}
	return WindowCacheMaping[key];
}

UUserWindow* AStrayFogHUD::GetUserWindow(TSubclassOf<class UUserWindow> WidgetType)
{
	uint32 key = WidgetType->GetUniqueID();
	return WindowCacheMaping.Contains(key) ? WindowCacheMaping[key] : nullptr;
}

bool AStrayFogHUD::ExistsUserWindow(TSubclassOf<class UUserWindow> WidgetType)
{
	uint32 key = WidgetType->GetUniqueID();
	return WindowCacheMaping.Contains(key);
}


