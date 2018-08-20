// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UMG/Window/UserWindow.h"
#include "UserWindowBFL.generated.h"

/**
 * 
 */
UCLASS()
class STRAYFOGLIBRARY_API UUserWindowBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
#pragma region OpenWindow
	/** OpenWindow */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (WorldContext = "WorldContextObject"), Category = "UserWindow")
		static class UUserWindow* OpenWindow(UObject* WorldContextObject, TSubclassOf<class UUserWindow> WidgetType, int32 PlayerIndex);
#pragma endregion

#pragma region CloseWindow

#pragma endregion

#pragma region GetUserWindow
	/** GetUserWindow */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (WorldContext = "WorldContextObject"), Category = "UserWindow")
		class UUserWindow* GetUserWindow(UObject* WorldContextObject, TSubclassOf<class UUserWindow> WidgetType, int32 PlayerIndex);
#pragma endregion

#pragma region ExistsUserWindow
	/** ExistsUserWindow */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (WorldContext = "WorldContextObject"), Category = "UserWindow")
		bool ExistsUserWindow(UObject* WorldContextObject, TSubclassOf<class UUserWindow> WidgetType, int32 PlayerIndex);
#pragma endregion
};
