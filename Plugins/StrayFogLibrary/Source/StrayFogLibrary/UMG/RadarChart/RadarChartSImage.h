// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Images/SImage.h"
#include "SlateOptMacros.h"
#include "Rendering/DrawElements.h"

/**
*
*/
class STRAYFOGLIBRARY_API SRadarChartSImage : public SImage
{
public:
	SLATE_BEGIN_ARGS(SRadarChartSImage)
	{}
	SLATE_END_ARGS()

		/** Constructs this widget with InArgs */
		void Construct(const FArguments& InArgs);
public:
	/**
	* 雷达图属性值组
	*/
	TArray<float> VertexRatios;
	/**
	* 绘制雷达图
	*/
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
};
