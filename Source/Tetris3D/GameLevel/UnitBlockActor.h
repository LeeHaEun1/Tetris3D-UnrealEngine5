// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnitBlockActor.generated.h"

UCLASS()
class TETRIS3D_API AUnitBlockActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUnitBlockActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

public:
	UPROPERTY(Category = "[ Unit Block Value ]", EditAnywhere, DisplayName = "Default Falling Speed")
	float defaultFallingSpeed = 1.0f;

	bool CheckFloor();
	
	//UPROPERTY(BlueprintReadWrite)
	//AActor unitBlock;
	//TSubclassOf<AActor> unitBlock;

private:
	float currentTime = 0.0f;
	class ATetrisGamemode* myGamemode;
};
