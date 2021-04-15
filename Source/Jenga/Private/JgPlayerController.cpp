// Fill out your copyright notice in the Description page of Project Settings.


#include "JgPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "PickActorComponent.h"

AJgPlayerController::AJgPlayerController()
{
	PickActorComponent = CreateDefaultSubobject<UPickActorComponent>(TEXT("PickActorComponent"));
	PhysicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(TEXT("PhysicsHandle"));
}

void AJgPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PickActorComponent->OnPickTickDelegate.AddUObject(this, &AJgPlayerController::OnPicking);

	if (HUDOverlayAsset)
	{
		HUDOverlay = CreateWidget<UUserWidget>(this, HUDOverlayAsset);
	}
	HUDOverlay->AddToViewport();
	HUDOverlay->SetVisibility(ESlateVisibility::Visible);

}


void AJgPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("MouseLeftClick", IE_Pressed, this, &AJgPlayerController::OnMouseDown);
	InputComponent->BindAction("MouseLeftClick", IE_Released, this, &AJgPlayerController::OnMouseUp);

}

void AJgPlayerController::OnMouseDown()
{
	if (PickActorComponent->StartPick(PhysicsHandle, ECC_GameTraceChannel1))
	{
		m_prevActorRot = GetPawn()->GetActorRotation();
	}
}

void AJgPlayerController::OnMouseUp()
{
	PickActorComponent->EndPick(PhysicsHandle);
}

void AJgPlayerController::OnPicking(float distance)
{
	APawn* Player = GetPawn();
	FVector fixedVec = Player->GetActorLocation() + distance * Player->GetActorForwardVector();
	FVector tempVec;
	FRotator FixedRotation;
	FRotator subActorAndFixObjRot = Player->GetActorRotation() - m_prevActorRot;
	PhysicsHandle->GetTargetLocationAndRotation(tempVec, FixedRotation);
	PhysicsHandle->SetTargetLocationAndRotation(fixedVec, FixedRotation+ subActorAndFixObjRot);
	m_prevActorRot = Player->GetActorRotation();
}


