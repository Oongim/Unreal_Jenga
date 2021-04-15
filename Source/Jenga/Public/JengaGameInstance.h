// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Engine/GameInstance.h"
#include "JengaGameInstance.generated.h"

/**
 *
 */
UCLASS()
class JENGA_API UJengaGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UJengaGameInstance();

	virtual void init();

	FStreamableManager AssetLoader;
};
