// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "RadarChartSImage.h"
#include "Widgets/SCompoundWidget.h"
#include "RadarChartImage.generated.h"

class SRadarChartSImage;

/**
*
*/
UCLASS()
class STRAYFOGLIBRARY_API URadarChartImage : public UImage
{
	GENERATED_BODY()

private:
	/**
	* 绘制雷达图的组件
	*/
	TSharedPtr<SRadarChartSImage> mSRadarChartSImage;
public:
	/**
	* 雷达图各属性值，值范围0-1.
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Radar)
		TArray<float> VertexRatios;
	/**
	* 设定雷达图指定属性的值，值范围0-1.
	* @Index 属性索引
	* @Value 属性值
	*/
	UFUNCTION(BlueprintCallable, Category = Radar)
		void SetVertexRatios(const int Index, const float Value);
protected:
	//~ Begin UWidget Interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	//~ End UWidget Interface
};
