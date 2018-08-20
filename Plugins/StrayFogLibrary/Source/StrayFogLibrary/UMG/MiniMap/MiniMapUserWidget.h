// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UserWidget/StrayFogUserWidget.h"
#include "Blueprint/UserWidget.h"
#include "Image.h"
#include "Components/PanelWidget.h"
#include "UMG/Window/UserWindow.h"
#include "MiniMapUserWidget.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class STRAYFOGLIBRARY_API UMiniMapUserWidget : public UUserWindow
{
	GENERATED_BODY()
private:
	/**
	* 小地图图片
	*/
	UImage * mImageMap;
	/**
	* 鼠标按钮是否按下
	*/
	bool mIsMouseButtonDown;
public:
	/**
	* 设置小地图图片
	*/
	UFUNCTION(BlueprintCallable, Category = MiniMap)
		void SetImageMap(UImage* _imageMap);
	/**
	* 小地图移动速率
	*/
	UPROPERTY(BlueprintReadWrite, Category = MiniMap)
		float MiniMapMoveRatio;
	/**
	* 小地图缩放量
	*/
	UPROPERTY(BlueprintReadWrite, Category = MiniMap)
		float MiniMapScaleDelta;
	/**
	* 小地图最大缩放值
	*/
	UPROPERTY(BlueprintReadWrite, Category = MiniMap)
		float MiniMapMaxScale;
public:
	virtual void NativePreConstruct() override;
	virtual FReply NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseWheel(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	//virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;	
};
