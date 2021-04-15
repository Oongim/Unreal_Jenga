// Fill out your copyright notice in the Description page of Project Settings.


#include "JengaGameMode.h"
#include "Pawn_CatPlayer.h"
#include "JgPlayerController.h"

AJengaGameMode::AJengaGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn_CatPlayer> CatPlayerClass(TEXT("Blueprint'/Game/BP/BP_CatPlayer.BP_CatPlayer_C'"));
	CatPlayer_C = CatPlayerClass.Class;

	static ConstructorHelpers::FClassFinder<AJgPlayerController> PlayerControllerClass(TEXT("Blueprint'/Game/BP/BP_PlayerController.BP_PlayerController_C'"));
	PlayerController_C = PlayerControllerClass.Class;
}

void AJengaGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	DefaultPawnClass = CatPlayer_C;
	PlayerControllerClass = PlayerController_C;
}
