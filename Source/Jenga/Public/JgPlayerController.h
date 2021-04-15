// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "JgPlayerController.generated.h"

/**
 * 플레이어 컨트롤러가 기본적으로 제공하는 기능 중에는 마우스 인터페이스에 관련된 기능이 있다.
출처: https://wergia.tistory.com/139 [베르의 프로그래밍 노트]
 */
UCLASS()
class JENGA_API AJgPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	/* UMG 에셋 레퍼런스*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> HUDOverlayAsset;

	/*위젯을 만든 후 유지하는 변수*/
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
