// Fill out your copyright notice in the Description page of Project Settings.


#include "Jg_Block.h"

// Sets default values
AJg_Block::AJg_Block()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	m_Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	m_Collision->SetBoxExtent(FVector(90, 30, 30));

	m_Collision->SetSimulatePhysics(true);
	m_Collision->SetGenerateOverlapEvents(false);
	m_Collision->SetCollisionProfileName(TEXT("BlockAll"));

	
	m_BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Block"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Block(TEXT("StaticMesh'/Game/Mesh/SM_Block.SM_Block'"));
	if(SM_Block.Succeeded())
		m_BlockMesh->SetStaticMesh(SM_Block.Object);

	m_BlockMesh->SetSimulatePhysics(false);
	m_BlockMesh->SetGenerateOverlapEvents(false);
	m_BlockMesh->SetCollisionProfileName(TEXT("NoCollision"));

	RootComponent = m_Collision;
	m_BlockMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AJg_Block::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void AJg_Block::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
