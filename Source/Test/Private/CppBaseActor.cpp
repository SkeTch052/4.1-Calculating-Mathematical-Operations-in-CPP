#include "CppBaseActor.h"
#include "Engine/Engine.h"

ACppBaseActor::ACppBaseActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

int& ACppBaseActor::GetInstanceCounter()
{
	static int InstanceCounter = 0;
	return InstanceCounter;
}

void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();
}

void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentTime += DeltaTime;
	SinMovement(); // Start the movement. It also can be used in Blueprints
}

void ACppBaseActor::ShowActorInformation()
{
	UE_LOG(LogTemp, Display, TEXT("A_CppBase_C_%d"), GetInstanceCounter());
	GetInstanceCounter()++;
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
}

void ACppBaseActor::SinMovement()
{
	float z = Amplitude * FMath::Sin(Frequency * CurrentTime) + InitialLocation.Z;

	FVector NewLocation = FVector(InitialLocation.X, InitialLocation.Y, z);
	SetActorLocation(NewLocation);
}