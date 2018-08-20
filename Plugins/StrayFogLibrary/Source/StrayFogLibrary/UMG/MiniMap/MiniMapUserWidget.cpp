// Fill out your copyright notice in the Description page of Project Settings.

#include "MiniMapUserWidget.h"
#include "Kismet/KismetSystemLibrary.h"

void UMiniMapUserWidget::NativePreConstruct()
{
	if (MiniMapMoveRatio <= 0)
	{
		MiniMapMoveRatio = 1.f;
	}
	if (MiniMapScaleDelta <= 0)
	{
		MiniMapScaleDelta = 0.1f;
	}
	if (MiniMapMaxScale < 1)
	{
		MiniMapMaxScale = 5.f;
	}
	Super::NativePreConstruct();
}

void UMiniMapUserWidget::SetImageMap(UImage* _imageMap)
{
	mImageMap = _imageMap;
}

FReply UMiniMapUserWidget::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (mIsMouseButtonDown)
	{
		FVector2D pos = mImageMap->RenderTransform.Translation;
		pos += InMouseEvent.GetCursorDelta()*MiniMapMoveRatio;
		FVector2D maxSize = (mImageMap->RenderTransform.Scale - 1)*0.5f*mImageMap->GetCachedGeometry().GetLocalSize();
		pos.X = FMath::Clamp(pos.X, -maxSize.X, maxSize.X);
		pos.Y = FMath::Clamp(pos.Y, -maxSize.Y, maxSize.Y);
		mImageMap->SetRenderTranslation(pos);
	}
	return Super::NativeOnMouseMove(InGeometry, InMouseEvent);
}

FReply UMiniMapUserWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	mIsMouseButtonDown = InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton);
	return FReply::Handled();
}

FReply UMiniMapUserWidget::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	mIsMouseButtonDown = InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton);
	return FReply::Handled();
}

FReply UMiniMapUserWidget::NativeOnMouseWheel(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	const FVector2D mouseImageLocal = mImageMap->GetCachedGeometry().AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
	const FVector2D mouseMaskLocal = mImageMap->GetParent()->GetCachedGeometry().AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());

	const FVector2D fromScale = mImageMap->RenderTransform.Scale;
	FVector2D toScale = mImageMap->RenderTransform.Scale;

	const bool isZoomIn = InMouseEvent.GetWheelDelta() > 0;
	float ratio = isZoomIn ? (1 + MiniMapScaleDelta) : (1 - MiniMapScaleDelta);
	toScale.X = FMath::Clamp(toScale.X * ratio, 1.f, MiniMapMaxScale);
	toScale.Y = FMath::Clamp(toScale.Y * ratio, 1.f, MiniMapMaxScale);


	const FVector2D offset = (toScale != mImageMap->RenderTransform.Scale) ? mouseImageLocal - mouseMaskLocal : FVector2D::ZeroVector;
	mImageMap->SetRenderScale(toScale);

	FVector2D position = (mImageMap->RenderTransform.Translation + offset) / fromScale * toScale;
	FVector2D maxSize = (mImageMap->RenderTransform.Scale - 1)*0.5f*mImageMap->GetCachedGeometry().GetLocalSize();
	position.X = FMath::Clamp(position.X, -maxSize.X, maxSize.X);
	position.Y = FMath::Clamp(position.Y, -maxSize.Y, maxSize.Y);

	mImageMap->SetRenderTranslation(position);

	/*UE_LOG(LogTemp, Warning, TEXT("I->%s M->%s O->%s S->%s"),
	*mouseImageLocal.ToString(), *mouseMaskLocal.ToString(), *offset.ToString(), *toScale.ToString());*/
	return Super::NativeOnMouseWheel(InGeometry, InMouseEvent);
}

void UMiniMapUserWidget::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	mIsMouseButtonDown = InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton);
}