// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Jg_Block.generated.h"

UCLASS()
class JENGA_API AJg_Block : public AActor
{
	GENERATED_BODY()
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
		class UBoxComponent* m_Collision;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
		class UStaticMeshComponent* m_BlockMesh;
	
public:	
	// Sets default values for this actor's properties
	AJg_Block();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
