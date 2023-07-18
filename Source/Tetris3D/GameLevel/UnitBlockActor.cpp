// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLevel/UnitBlockActor.h"
#include "TetrisGamemode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AUnitBlockActor::AUnitBlockActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUnitBlockActor::BeginPlay()
{
	Super::BeginPlay();
	
	// Get Gamemode
	AGameModeBase* GameModePtr = UGameplayStatics::GetGameMode(GetWorld());
	if (nullptr == GameModePtr && false == GameModePtr->IsValidLowLevel())
	{
		return;
	}
	ATetrisGamemode* TetrisGamemode = Cast<ATetrisGamemode>(GameModePtr);
	if (nullptr == TetrisGamemode && false == TetrisGamemode->IsValidLowLevel())
	{
		return;
	}
	tetrisGamemode = TetrisGamemode;
}

// Called every frame
void AUnitBlockActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime += DeltaTime;
	if (currentTime > defaultFallingSpeed)
	{
		// block = self�� �� ĭ ����Ʈ����
		AddActorLocalOffset(-FVector(0, 0, tetrisGamemode->blockSize.Z));

		// currentTime initialize
		currentTime = 0;
	}
}

