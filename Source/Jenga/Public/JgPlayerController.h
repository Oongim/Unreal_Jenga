// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "JgPlayerController.generated.h"

/**
 * �÷��̾� ��Ʈ�ѷ��� �⺻������ �����ϴ� ��� �߿��� ���콺 �������̽��� ���õ� ����� �ִ�.
��ó: https://wergia.tistory.com/139 [������ ���α׷��� ��Ʈ]
 */
UCLASS()
class JENGA_API AJgPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	/* UMG ���� ���۷���*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> HUDOverlayAsset;

	/*������ ���� �� �����ϴ� ����*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		UUserWidget* HUDOverlay;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Picking")
		class UPickActorComponent* PickActorComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Physics")
		class UPhysicsHandleComponent* PhysicsHandle;

	FRotator m_prevActorRot;

protected:
	virtual void BeginPlay() override;

public:
	AJgPlayerController();

public:
	virtual void SetupInputComponent() override;

	void OnMouseDown();
	void OnMouseUp();

	UFUNCTION()
	void OnPicking(float distance);

};
