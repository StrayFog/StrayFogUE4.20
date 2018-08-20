// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UserWidget/StrayFogUserWidget.h"
#include "Components/CanvasPanel.h"
#include "UserWindow.generated.h"

UENUM(BlueprintType)
enum class EStrayFogUserWidgetLayer : uint8
{
	Lowest = MIN_uint8, //UMETA(DisplayName = "��Ͳ�")
	Fixed ,//UMETA(DisplayName = "�̶���")
	HalfFixed ,//UMETA(DisplayName = "��̶���")
	Dynamic ,//UMETA(DisplayName = "��̬��")
	Guide ,//UMETA(DisplayName = "������")
	Highest = MAX_uint8 ,//UMETA(DisplayName = "��߲�")
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
	* ��ô�������
	*/
	UFUNCTION(BlueprintCallable, Category = "Window")
		FString GetWindowName();
	/**
	* ��ô���ID
	*/
	UFUNCTION(BlueprintCallable, Category = "Window")
		FString GetWindowId();
	/**
	* ��ô���ZOrder
	*/
	UFUNCTION(BlueprintCallable, Category = "Window")
		int32 GetWindowZOrder();

	/**
	* ���ô���ZOrder
	* @InZOrder Ҫ���õ�ZOrderֵ
	*/
	UFUNCTION(BlueprintCallable, Category = "Window")
		void SetWindowZOrder(int32 InZOrder);

	/**
	* ��ô��ڵ�CanvasPanel
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
