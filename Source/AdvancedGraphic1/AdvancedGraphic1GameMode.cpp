// Copyright Epic Games, Inc. All Rights Reserved.

#include "AdvancedGraphic1GameMode.h"
#include "AdvancedGraphic1Character.h"
#include "UObject/ConstructorHelpers.h"

AAdvancedGraphic1GameMode::AAdvancedGraphic1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
