// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Image.h"
#include "WidgetLayoutLibrary.h"
#include"Components/InputComponent.h"
#include "StrayFogUserWidget.generated.h"

USTRUCT(BlueprintType)
struct STRAYFOGLIBRARY_API FHudInputKey
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputKey)
		FInputChord Key;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputKey)
		TEnumAsByte< EInputEvent > EventType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputKey)
		bool bConsume;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputKey)
		FInputActionHandlerDynamicSignature Callback;
	FHudInputKey()
	{
	}
};
// UGameViewportClient::InputKey 420 FSceneViewport 243 UViewportWorldInteraction::InputKey 557
/**
*
*
*/
UCLASS(NotBlueprintable)
class STRAYFOGLIBRARY_API UStrayFogUserWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	void DynamicDelegateKeyMethod(FKey Key, FInputActionHandlerDynamicSignature Callback);

#pragma region Input|KeyBoard
	/**
	* 侦听指定KeyBoard
	* @Key KeyBoard
	*/
	UFUNCTION(BlueprintCallable, Category = "Input|KeyBoard", meta = (BlueprintProtected = "true"))
		void ListenForInputKeyBoard(FHudInputKey Key);
	/**
	* 停止侦听指定KeyBoard
	* @Key KeyBoard
	* @EventType 按键事件
	*/
	UFUNCTION(BlueprintCallable, Category = "Input|KeyBoard", meta = (BlueprintProtected = "true"))
		void StopListeningForInputKeyBoard(FKey Key, TEnumAsByte< EInputEvent > EventType);
	/**
	* 停止侦听所有KeyBoard
	*/
	UFUNCTION(BlueprintCallable, Category = "Input|KeyBoard", meta = (BlueprintProtected = "true"))
		void StopListeningForAllInputKeyBoards();
	/**
	* 是否侦听指定KeyBoard
	* @Key KeyBoard
	*/
	UFUNCTION(BlueprintCallable, Category = "Input|KeyBoard", meta = (BlueprintProtected = "true"))
		bool IsListeningForInputKeyBoard(FKey Key) const;
	/**
	* 设定要侦听的KeyBoard
	* @Key KeyBoard组
	*/
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category = "Input")
		FEventReply OnListenInputKey(TArray<FHudInputKey>& Keys);
#pragma endregion

#pragma region Native
	virtual void NativePreConstruct() override;
#pragma endregion
};
