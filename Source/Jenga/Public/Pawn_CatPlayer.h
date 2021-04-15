// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Pawn.h"
#include "Pawn_CatPlayer.generated.h"

//�𸮾� ������Ʈ�� INI ���Ͽ��� ���� ���� �о�� �� �ֵ���
UCLASS(config=Game)
class JENGA_API APawn_CatPlayer : public APawn
{
	GENERATED_BODY()
private:
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* m_SpringArm;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* m_Camera;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Character, meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* m_Body;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = Character, meta = (AllowPrivateAccess = "true"))
		class USkeletalMeshComponent* m_Mesh;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Helper", meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* m_Arrow;

	/*
	����Ʈ ���۷��� ����� ����Ϸ��� �ּ��� ������ ������ ������ FStringAssetReference ����ü��, 
	�ּ��� Ŭ���� ������ ������ ������ FStringClassReference ����ü�� ��� ������ �������ָ� �˴ϴ�.
	*/
	UPROPERTY(config)
		TArray<FStringAssetReference> CatAssets;

public:
	UPROPERTY(config, BlueprintReadWrite, EditDefaultsOnly, Category = "Stat")
		float MaxHP;
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Stat")
		float CurrentHP;

public:
	// Sets default values for this pawn's properties
	APawn_CatPlayer();

	void InitCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MouseLeftDown();

	void MoveForward(float Value);
	void MoveRight(float Value);
	void MoveUpDown(float Value);
	void AddControllerYawInput(float Value);
	void AddControllerPitchInput(float Value);
};
