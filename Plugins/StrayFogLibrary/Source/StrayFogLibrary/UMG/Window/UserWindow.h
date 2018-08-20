// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UserWidget/StrayFogUserWidget.h"
#include "Components/CanvasPanel.h"
#include "UserWindow.generated.h"

UENUM(BlueprintType)
enum class EStrayFogUserWidgetLayer : uint8
{
	Lowest = MIN_uint8, //UMETA(DisplayName = "最低层")
	Fixed ,//UMETA(DisplayName = "固定层")
	HalfFixed ,//UMETA(DisplayName = "半固定层")
	Dynamic ,//UMETA(DisplayName = "动态层")
	Guide ,//UMETA(DisplayName = "引导层")
	Highest = MAX_uint8 ,//UMETA(DisplayName = "最高层")
};
/**
 * 
 */
UCLASS(Blueprintable)
class STRAYFOGLIBRARY_API UUserWindow : public UStrayFogUserWidget
{
	GENERATED_BODY()
public:
#pragma region Get Or Set
	/**
	* 获得窗口名称
	*/
	UFUNCTION(BlueprintCallable, Category = "Window")
		FString GetWindowName();
	/**
	* 获得窗口ID
	*/
	UFUNCTION(BlueprintCallable, Category = "Window")
		FString GetWindowId();
	/**
	* 获得窗口ZOrder
	*/
	UFUNCTION(BlueprintCallable, Category = "Window")
		int32 GetWindowZOrder();

	/**
	* 设置窗口ZOrder
	* @InZOrder 要设置的ZOrder值
	*/
	UFUNCTION(BlueprintCallable, Category = "Window")
		void SetWindowZOrder(int32 InZOrder);

	/**
	* 获得窗口的CanvasPanel
	*/
	UFUNCTION(BlueprintCallable, Category = "Window")
		UCanvasPanel* GetWindowCanvasPanel();
#pragma endregion

#pragma region Layer
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Window")
		EStrayFogUserWidgetLayer Layer;
#pragma endregion

#pragma region ZOrder
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Window")
		int32 ZOrder;
#pragma endregion	
};
