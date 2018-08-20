// Fill out your copyright notice in the Description page of Project Settings.

#include "RadarChartImage.h"

TSharedRef<SWidget> URadarChartImage::RebuildWidget()
{
	mSRadarChartSImage = SNew(SRadarChartSImage);
	mSRadarChartSImage->VertexRatios = VertexRatios;
	MyImage = mSRadarChartSImage;

	UMaterialInstanceDynamic* mid = GetDynamicMaterial();
	if (mid != NULL)
	{
		mid->SetVectorParameterValue(TEXT("FinalColorAndOpacity"), ColorAndOpacity);
	}
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *mid->GetFName().ToString());
	return MyImage.ToSharedRef();
}

void URadarChartImage::SetVertexRatios(const int Index, const float Value)
{
	if (mSRadarChartSImage->VertexRatios.IsValidIndex(Index))
	{
		mSRadarChartSImage->VertexRatios[Index] = Value;
	}
}


