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
	* С��ͼͼƬ
	*/
	UImage * mImageMap;
	/**
	* ��갴ť�Ƿ���
	*/
	bool mIsMouseButtonDown;
public:
	/**
	* ����С��ͼͼƬ
	*/
	UFUNCTION(BlueprintCallable, Category = MiniMap)
		void SetImageMap(UImage* _imageMap);
	/**
	* С��ͼ�ƶ�����
	*/
	UPROPERTY(BlueprintReadWrite, Category = MiniMap)
		float MiniMapMoveRatio;
	/**
	* С��ͼ������
	*/
	UPROPERTY(BlueprintReadWrite, Category = MiniMap)
		float MiniMapScaleDelta;
	/**
	* С��ͼ�������ֵ
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
