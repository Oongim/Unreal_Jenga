// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn_CatPlayer.h"
#include "JengaGameInstance.h"

// Sets default values
APawn_CatPlayer::APawn_CatPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));

	m_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	m_Body = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));

	m_Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));

	m_Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));

	m_Body->SetBoxExtent(FVector(23.f, 6.f, 15.f));
	m_Mesh->SetRelativeLocationAndRotation(FVector(13.f, 0.f, -20.f), FRotator(0.f, -90.f, -40.f));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_Mesh(TEXT("SkeletalMesh'/Game/LowPoly_Cat/Meshes/Mesh_Cat_Abyss.Mesh_Cat_Abyss'"));
	if (SK_Mesh.Succeeded()) m_Mesh->SetSkeletalMesh(SK_Mesh.Object);

	InitCamera();

	RootComponent = m_Body;
	m_Mesh->SetupAttachment(m_Body);
	m_SpringArm->SetupAttachment(m_Body);
	m_Arrow->SetupAttachment(m_Body);
	m_Camera->SetupAttachment(m_SpringArm);
	CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");
}

void APawn_CatPlayer::InitCamera()
{
	m_SpringArm->SetRelativeRotation(FRotator(-30.f, 0.f, 0.f));
	m_SpringArm->TargetArmLength = 200.f;
	m_Camera->SetRelativeRotation(FRotator(10.f, 0.f, 0.f));

	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;
}

// Called when the game starts or when spawned
void APawn_CatPlayer::BeginPlay()
{
	Super::BeginPlay();

	CurrentHP = MaxHP;
	
	int32 NewIndex = FMath::RandRange(0, CatAssets.Num() - 1);
	
	UJengaGameInstance* JgGameInstance = Cast<UJengaGameInstance>(GetGameInstance());
	if (JgGameInstance)
	{
		TAssetPtr<USkeletalMesh> NewCharacter = Cast<USkeletalMesh>(JgGameInstance->AssetLoader.LoadSynchronous(CatAssets[NewIndex]));
		if (NewCharacter)
		{
			m_Mesh->SetSkeletalMesh(NewCharacter.Get());
		}
	}
}

// Called every frame
void APawn_CatPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawn_CatPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &APawn_CatPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APawn_CatPlayer::MoveRight);
	PlayerInputComponent->BindAxis("MoveUpDown", this, &APawn_CatPlayer::MoveUpDown);

	PlayerInputComponent->BindAxis("Turn", this, &APawn_CatPlayer::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn_CatPlayer::AddControllerPitchInput);
}

void APawn_CatPlayer::MouseLeftDown()
{
	
}

void APawn_CatPlayer::MoveForward(float Value)
{
	//GEngine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("MoveForward %d"), Value));
	//UE_LOG(LogTemp, Log, TEXT("%d"), Value);

	AddMovementInput(GetActorForwardVector(), Value);
}

void APawn_CatPlayer::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}
void APawn_CatPlayer::MoveUpDown(float Value)
{
	AddMovementInput(GetActorUpVector(), Value);
}

void APawn_CatPlayer::AddControllerYawInput(float Value)
{
	Super::AddControllerYawInput(Value);
}

void APawn_CatPlayer::AddControllerPitchInput(float Value)
{
	Super::AddControllerPitchInput(Value);
}
