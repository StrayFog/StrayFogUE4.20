// Fill out your copyright notice in the Description page of Project Settings.

#include "RadarChartSImage.h"
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SRadarChartSImage::Construct(const FArguments& InArgs)
{
	/*
	ChildSlot
	[
	// Populate the widget
	];
	*/
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

int32 SRadarChartSImage::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	const FSlateBrush* ImageBrush = Image.Get();
	const int NumVertexs = VertexRatios.Num();

	if (NumVertexs > 2 && (ImageBrush != nullptr) && (ImageBrush->DrawAs != ESlateBrushDrawType::NoDrawType))
	{
		const bool bIsEnabled = ShouldBeEnabled(bParentEnabled);
		const ESlateDrawEffect DrawEffects = bIsEnabled ? ESlateDrawEffect::None : ESlateDrawEffect::DisabledEffect;
		const FLinearColor FinalColorAndOpacity(InWidgetStyle.GetColorAndOpacityTint() * ColorAndOpacity.Get().GetColor(InWidgetStyle) * ImageBrush->GetTint(InWidgetStyle));

		FSlateShaderResourceProxy* ResourceProxy = FSlateDataPayload::ResourceManager->GetShaderResource(*ImageBrush);
		FSlateResourceHandle Handle = FSlateApplication::Get().GetRenderer()->GetResourceHandle(*ImageBrush);

		if (ResourceProxy != nullptr && Handle.IsValid())
		{
#pragma region Builder Verts
			FVector2D UVCenter = FVector2D::ZeroVector;
			FVector2D UVRadius = FVector2D(1, 1);
			if (ResourceProxy != nullptr)
			{
				UVRadius = 0.5f * ResourceProxy->SizeUV;
				UVCenter = ResourceProxy->StartUV + UVRadius;
			}
			const FVector2D Center = AllottedGeometry.AbsolutePosition + AllottedGeometry.GetAbsoluteSize() * 0.5f;
			const FVector2D Size = AllottedGeometry.GetLocalSize();
			const float Radius = (Size.X <= Size.Y ? Size.X : Size.Y)* AllottedGeometry.Scale *0.5f;
			FVector startRay = FVector::RightVector;
			float angle = 360.f / NumVertexs;
			if (NumVertexs % 2 == 0)
			{//如果边数是偶数，则起始射线为向左偏移半个平均角度
				startRay = FQuat::MakeFromEuler(FVector::UpVector * -angle * 0.5f) * startRay;
			}
			//UE_LOG(LogTemp, Warning, TEXT("StartRay->%s"), *startRay.ToString());

			// Make a triangle fan in the area allotted
			TArray<FSlateVertex> Verts;
			Verts.Reserve(NumVertexs + 1);
			Verts.AddZeroed();
			{
				FSlateVertex& NewVert = Verts.Last();
				NewVert.Position[0] = Center.X;
				NewVert.Position[1] = Center.Y;
				NewVert.TexCoords[0] = UVCenter.X;
				NewVert.TexCoords[1] = UVCenter.Y;
				NewVert.TexCoords[2] = NewVert.TexCoords[3] = 1.0f;
				NewVert.Color = FColor::White;
			}

			FVector targetPosition = FVector::ZeroVector;
			FVector targetUV = FVector::ZeroVector;
			TArray<SlateIndex> Indexes;
			float ratio = 1.f;
			for (int i = 0; i < NumVertexs; ++i)
			{
				targetUV = FQuat::MakeFromEuler(FVector::UpVector * (i * angle)) * startRay;

				if (VertexRatios.IsValidIndex(i))
				{
					ratio = FMath::Clamp<float>(VertexRatios[i], 0, 1);
				}
				targetPosition = FQuat::MakeFromEuler(FVector::UpVector * (i * angle + 180)) * startRay * Radius * ratio;

				Verts.AddZeroed();
				{
					FSlateVertex& NewVert = Verts.Last();
					NewVert.Position[0] = Center.X + targetPosition.X;
					NewVert.Position[1] = Center.Y + targetPosition.Y;
					NewVert.TexCoords[0] = UVCenter.X + UVRadius.X*FMath::Sin(FMath::DegreesToRadians(0));
					NewVert.TexCoords[1] = UVCenter.Y + UVRadius.Y*FMath::Cos(FMath::DegreesToRadians(0));
					NewVert.TexCoords[2] = NewVert.TexCoords[3] = 1.0f;
					NewVert.Color = FColor::White;
				}

				Indexes.Add(0);
				if (i >= NumVertexs - 1)
				{
					Indexes.Add(i + 1);
					Indexes.Add(1);
				}
				else
				{
					Indexes.Add(i + 1);
					Indexes.Add(i + 2);
				}
				//UE_LOG(LogTemp, Warning, TEXT("CenterPosition->%s ,TargetPosition->%s ,UVCenter->%s, UVRadius->%s,TargetUV->%s,Color->%s"),
				//	*Center.ToString(), *targetPosition.ToString(), *UVCenter.ToString(), *UVRadius.ToString(), *targetUV.ToString(), *FinalColorAndOpacity.ToString());
			}

			/*FSlateDrawElement::MakeBox(OutDrawElements, LayerId, AllottedGeometry.ToPaintGeometry(),
			ImageBrush, DrawEffects, FinalColorAndOpacity);*/

#pragma endregion

			FSlateDrawElement::MakeCustomVerts(
				OutDrawElements,
				LayerId,
				Handle, Verts, Indexes, nullptr, 0, 0, DrawEffects);
		}
	}
	return LayerId;
}
