// Fill out your copyright notice in the Description page of Project Settings.


#include "PickActorComponent.h"
#include "Jg_Block.h"

// Sets default values for this component's properties
UPickActorComponent::UPickActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPickActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPickActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (IsValid(m_PickedActor))
	{
		OnPickTickDelegate.Broadcast(m_FixDistance);
	}
}

bool UPickActorComponent::StartPick(UPhysicsHandleComponent* physicsHandle, ECollisionChannel inChannel)
{
	UWorld* world = GetWorld();
	if (world == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("[PickActorComponent]StartPick - World Null"));
		return false;
	}

	APawn* outer = Cast<APlayerController>(GetOuter())->GetPawn();
	if (!IsValid(outer))
	{
		UE_LOG(LogTemp, Warning, TEXT("[PickActorComponent]StartPick - Outer Null"));
		return false;
	}

	FHitResult outHit;
	FVector StartVec = outer->GetActorLocation();
	FVector EndVec= outer->GetActorLocation()+ outer->GetActorForwardVector()*100;
	if (world->LineTraceSingleByChannel(outHit, StartVec, EndVec, inChannel))
	{
		if (outHit.bBlockingHit)
		{
			m_PickedActor = Cast<AJg_Block>(outHit.GetActor());
			m_PickedComp = outHit.GetComponent();
			if (IsValid(m_PickedActor) && IsValid(m_PickedComp))
			{
				UE_LOG(LogTemp, Warning, TEXT("[PickActorComponent]Pick Success"));
				m_FixDistance =(outer->GetActorLocation() - m_PickedActor->GetActorLocation()).Size();
				physicsHandle->GrabComponentAtLocationWithRotation(m_PickedComp, NAME_None,
					m_PickedComp->GetOwner()->GetActorLocation(),
					m_PickedComp->GetOwner()->GetActorRotation());
				return true;
			}
		}
	}

	return false;
}

void UPickActorComponent::EndPick(UPhysicsHandleComponent* physicsHandle)
{
	if (IsValid(m_PickedActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("[PickActorComponent]PickEnd"));

		m_PickedActor = nullptr;
		m_FixDistance = 0;
		m_PickedComp = nullptr;
		physicsHandle->ReleaseComponent();
	}
}

