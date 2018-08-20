// Fill out your copyright notice in the Description page of Project Settings.

#include "UserWindow.h"

FString UUserWindow::GetWindowName() { return GetClass()->GetFName().ToString(); }

FString UUserWindow::GetWindowId() { return FString::FromInt(GetClass()->GetUniqueID()); }

int32 UUserWindow::GetWindowZOrder() { return ZOrder; }

void UUserWindow::SetWindowZOrder(int32 InZOrder)
{
	RemoveFromViewport();
	ZOrder = InZOrder;
	AddToViewport(InZOrder);
}

UCanvasPanel* UUserWindow::GetWindowCanvasPanel()
{
	return Cast<UCanvasPanel>(GetRootWidget());
}



