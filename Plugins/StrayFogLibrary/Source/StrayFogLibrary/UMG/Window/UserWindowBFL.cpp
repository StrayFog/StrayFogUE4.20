// Fill out your copyright notice in the Description page of Project Settings.
#include "UserWindowBFL.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WidgetBlueprintLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/HUD.h"
#include "GameMode/StrayFogHUD.h"

/*
* 窗口映射
*/
class UUserWindow* UUserWindowBFL::OpenWindow(UObject* WorldContextObject, TSubclassOf<class UUserWindow> WidgetType, int32 PlayerIndex)
{
	/*UKismetSystemLibrary::PrintString(WorldContextObject,
		mode->GetFName().ToString() + " " + hud->GetFName().ToString(), true, true);*/
	//AGameModeBase* mode = UGameplayStatics::GetGameMode(WorldContextObject);	
	APlayerController* OwningPlayer = UGameplayStatics::GetPlayerController(WorldContextObject, PlayerIndex);
	AStrayFogHUD* hud = Cast<AStrayFogHUD>(OwningPlayer->GetHUD());
	UUserWindow* window = nullptr;
	if (hud != nullptr)
	{
		if (hud->ExistsUserWindow(WidgetType))
		{
			window = hud->GetUserWindow(WidgetType);		
		}
		else
		{
			window = hud->CreateUserWindow(WorldContextObject, WidgetType, OwningPlayer);
		}
		uint8 layer = (uint8)window->Layer;
		int32 layerZOrder = layer << 12;
		int32 zOrder = layerZOrder;
		window->SetWindowZOrder(zOrder);
		//window->SetWindowZOrder(ZOrder);
		////FString str (WidgetType->GetName() +"["+ FString::FromInt(WidgetType->GetUniqueID()) + 
		////	"]=>" + window->GetWindowName() + "[" + window->GetWindowId() + "]");
		////UKismetSystemLibrary::PrintString(WorldContextObject, str, true, true);
	}
	else
	{
		UKismetSystemLibrary::PrintString(WorldContextObject,"OwningPlayer->GetHUD() is not SubclassOf AStrayFogHUD.", true, true);
	}
	return window;
}

class UUserWindow* UUserWindowBFL::GetUserWindow(UObject* WorldContextObject, TSubclassOf<class UUserWindow> WidgetType, int32 PlayerIndex)
{
	APlayerController* OwningPlayer = UGameplayStatics::GetPlayerController(WorldContextObject, PlayerIndex);
	AStrayFogHUD* hud = Cast<AStrayFogHUD>(OwningPlayer->GetHUD());
	return hud->GetUserWindow(WidgetType);
}

bool UUserWindowBFL::ExistsUserWindow(UObject* WorldContextObject, TSubclassOf<class UUserWindow> WidgetType, int32 PlayerIndex)
{
	APlayerController* OwningPlayer = UGameplayStatics::GetPlayerController(WorldContextObject, PlayerIndex);
	AStrayFogHUD* hud = Cast<AStrayFogHUD>(OwningPlayer->GetHUD());
	return hud->ExistsUserWindow(WidgetType);
}



