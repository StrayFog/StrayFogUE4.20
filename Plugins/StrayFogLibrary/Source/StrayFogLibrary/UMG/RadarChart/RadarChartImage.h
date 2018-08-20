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
	* �����״�ͼ�����
	*/
	TSharedPtr<SRadarChartSImage> mSRadarChartSImage;
public:
	/**
	* �״�ͼ������ֵ��ֵ��Χ0-1.
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Radar)
		TArray<float> VertexRatios;
	/**
	* �趨�״�ͼָ�����Ե�ֵ��ֵ��Χ0-1.
	* @Index ��������
	* @Value ����ֵ
	*/
	UFUNCTION(BlueprintCallable, Category = Radar)
		void SetVertexRatios(const int Index, const float Value);
protected:
	//~ Begin UWidget Interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	//~ End UWidget Interface
};
