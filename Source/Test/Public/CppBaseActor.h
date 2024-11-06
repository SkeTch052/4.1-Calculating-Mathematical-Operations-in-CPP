#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Mobility,
	Static
};

USTRUCT(BlueprintType)
struct FTransformStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

UCLASS()
class TEST_API ACppBaseActor : public AActor
{
	GENERATED_BODY()

public:
	ACppBaseActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ShowActorInformation();

	UPROPERTY(EditAnywhere)
	int EnemyNum = 20;

	UPROPERTY(EditInstanceOnly)
	bool IsAlive = true;


// Method and variables for movement

	UFUNCTION(BlueprintCallable)
	void SinMovement();

	UPROPERTY(EditAnywhere)
	float CurrentTime;

	UPROPERTY(EditAnywhere)
	float Amplitude = 70.0;

	UPROPERTY(EditAnywhere)
	float Frequency = 4.0;

	UPROPERTY(EditAnywhere)
	FVector InitialLocation = FVector::ZeroVector;

public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	virtual void Tick(float DeltaTime) override;

private:
	static int& GetInstanceCounter();
};