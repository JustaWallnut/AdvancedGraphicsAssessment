// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemCounterWidgetBase.h"

#include "EditorCategoryUtils.h"

void UItemCounterWidgetBase::UpdateItemText(int NewCount)
{
	FString String = FString::FromInt(NewCount);
	ItemTextCount->SetText(FText::FromString(String));
}
