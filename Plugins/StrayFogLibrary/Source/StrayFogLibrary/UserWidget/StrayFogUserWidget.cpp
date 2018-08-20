// Fill out your copyright notice in the Description page of Project Settings.

#include "StrayFogUserWidget.h"
#include "Kismet/KismetSystemLibrary.h"

#pragma region Native
void UStrayFogUserWidget::NativePreConstruct()
{
	TArray<FHudInputKey> keys;
	FEventReply reply = OnListenInputKey(keys);

	for (int i = 0; i < keys.Num(); i++)
	{
		ListenForInputKeyBoard(keys[i]);
	}
	Super::NativePreConstruct();
}
#pragma endregion

void UStrayFogUserWidget::DynamicDelegateKeyMethod(FKey Key, FInputActionHandlerDynamicSignature Callback)
{
	//UKismetSystemLibrary::PrintString(this, Key.GetDisplayName().ToString(), true, false);
	Callback.Execute(Key);
}


#pragma region Input|KeyBoard
void UStrayFogUserWidget::ListenForInputKeyBoard(FHudInputKey Key)
{
	if (!InputComponent)
	{
		InitializeInputComponent();
	}
	if (InputComponent)
	{
		FInputKeyBinding KB(Key.Key, Key.EventType);
		KB.bConsumeInput = Key.bConsume;
		//KB.KeyDelegate.BindDelegate(this, &UStrayFogUserWidget::DelegateKeyMethod);

		KB.KeyDelegate.GetDelegateWithKeyForManualSet().BindUObject(
			this,
			&ThisClass::DynamicDelegateKeyMethod,
			Key.Callback);

		//KB.KeyDelegate.GetDelegateForManualSet().BindUObject(
		//this, &ThisClass::OnInputAction, Key.onInputAction);
		//UKismetSystemLibrary::PrintString(this, Key.onInputAction.GetFunctionName().ToString(), true, false);
		InputComponent->KeyBindings.Add(KB);
	}
}

void UStrayFogUserWidget::StopListeningForInputKeyBoard(FKey Key, TEnumAsByte< EInputEvent > EventType)
{
	if (InputComponent)
	{
		for (int32 ExistingIndex = InputComponent->KeyBindings.Num() - 1; ExistingIndex >= 0; --ExistingIndex)
		{
			const FInputKeyBinding& ExistingBind = InputComponent->KeyBindings[ExistingIndex];
			if (ExistingBind.Chord.Key == Key && ExistingBind.KeyEvent == EventType)
			{
				InputComponent->KeyBindings.RemoveAt(ExistingIndex);
			}
		}
	}
}

void UStrayFogUserWidget::StopListeningForAllInputKeyBoards()
{
	if (InputComponent)
	{
		InputComponent->KeyBindings.Empty();
		UnregisterInputComponent();
		InputComponent->MarkPendingKill();
		InputComponent = nullptr;
	}
}

bool UStrayFogUserWidget::IsListeningForInputKeyBoard(FKey Key) const
{
	bool bResult = false;
	if (InputComponent)
	{
		for (int32 ExistingIndex = InputComponent->GetNumActionBindings() - 1; ExistingIndex >= 0; --ExistingIndex)
		{
			const FInputKeyBinding& ExistingBind = InputComponent->KeyBindings[ExistingIndex];
			if (ExistingBind.Chord.Key == Key)
			{
				bResult = true;
				break;
			}
		}
	}
	return bResult;
}
#pragma endregion