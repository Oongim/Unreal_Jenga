// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/GameMode.h"
#include "JengaGameMode.generated.h"

/**

 * �����ϴ� �÷��̾�� �������� ���� ����, ���� �÷��̾�� ������ �ִ� ��

 * �÷��̾ ���ӿ� ������ ���, ���� ��ġ ���� ��Ģ�� ��Ÿ ����/������ ���� ���� ����

 * ���� �Ͻ����� ���� ����, ���� �Ͻ����� ó�� ���

 * �������� ��ȯ, ������ �ó׸�ƽ ��� ���� ���� ����
 
 * AGameMode �� AGameModeBase �� ����Ŭ������, ��Ƽ�÷��̾� ��� �� ���� �۵���� ������ ���� �ΰ� �Լ��� �� ���� ����ֽ��ϴ�. 
   ���Ӱ� �����Ǵ� ������Ʈ�� ��� AGameModeBase �� �⺻ ���������, �� �ΰ� �Լ��� �ʿ��� ��� AGameMode �� ����ϵ��� ��ȯ�� �� �ֽ��ϴ�. 
   AGameMode �� ����ϴ� ���, ��� ������Ʈ �ӽŵ� �����ϴ� AGameState ���� ���� ������Ʈ�� ����ϱ⵵ �ؾ��մϴ�.

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
	
	//	(PreInitializeComponents �� ������) �ٸ� ��ũ��Ʈ ���� ȣ��Ǿ�, �Ķ���͸� �ʱ�ȭ��Ű�� �� ���� Ŭ������ ������ŵ�ϴ�.
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
};
