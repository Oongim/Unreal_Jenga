// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/GameMode.h"
#include "JengaGameMode.generated.h"

/**

 * 존재하는 플레이어와 관람자의 수는 물론, 허용된 플레이어와 관람자 최대 수

 * 플레이어가 게임에 들어오는 방식, 스폰 위치 선택 규칙과 기타 스폰/리스폰 동작 포함 가능

 * 게임 일시정지 가능 여부, 게임 일시정지 처리 방식

 * 레벨간의 전환, 게임의 시네마틱 모드 시작 여부 포함
 
 * AGameMode 는 AGameModeBase 의 서브클래스로, 멀티플레이어 경기 및 기존 작동방식 지원을 위한 부가 함수가 몇 가지 들어있습니다. 
   새롭게 생성되는 프로젝트는 모두 AGameModeBase 를 기본 사용하지만, 그 부가 함수가 필요한 경우 AGameMode 를 상속하도록 전환할 수 있습니다. 
   AGameMode 를 상속하는 경우, 경기 스테이트 머신도 지원하는 AGameState 에서 게임 스테이트를 상속하기도 해야합니다.

 */
UCLASS()
class JENGA_API AJengaGameMode : public AGameMode
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Class, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class APawn_CatPlayer> CatPlayer_C;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Class, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class AJgPlayerController> PlayerController_C;

public:
	AJengaGameMode();
	
	//	(PreInitializeComponents 를 포함한) 다른 스크립트 전에 호출되어, 파라미터를 초기화시키고 그 헬퍼 클래스를 스폰시킵니다.
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
};
