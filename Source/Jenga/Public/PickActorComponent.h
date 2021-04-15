// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Components/ActorComponent.h"
#include "PickActorComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FPickTickSignature,float);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class JENGA_API UPickActorComponent : public UActorComponent
{
	GENERATED_BODY()
private:
	class AActor* m_PickedActor;
	class UPrimitiveComponent* m_PickedComp;
	float m_FixDistance;

public:	
	// Sets default values for this component's properties
	UPickActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FPickTickSignature OnPickTickDelegate;

	bool StartPick(class UPhysicsHandleComponent* physicsHandle, ECollisionChannel inChannel = ECC_Visibility);
	void EndPick(class UPhysicsHandleComponent* physicsHandle);
		
};
