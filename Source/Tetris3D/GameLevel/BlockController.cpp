// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLevel/BlockController.h"
#include "TetrisGamemode.h"
#include "Kismet/GameplayStatics.h"


void ABlockController::BeginPlay()
{
	Super::BeginPlay();

	// Get Gamemode
	AGameModeBase* GameModePtr = UGameplayStatics::GetGameMode(GetWorld());
	if (nullptr == GameModePtr || false == GameModePtr->IsValidLowLevel())
	{
		return;
	}
	ATetrisGamemode* TetrisGamemode = Cast<ATetrisGamemode>(GameModePtr);
	if (nullptr == TetrisGamemode || false == TetrisGamemode->IsValidLowLevel())
	{
		return;
	}
	// Get currentBlock
	currentBlock = TetrisGamemode->currentBlock;
	// Get BlockSize
	blockSize = TetrisGamemode->blockSize;
}

void ABlockController::XminusA()
{
	currentBlock->AddActorLocalOffset({ -blockSize.X,0,0 });
}

void ABlockController::XplusD()
{
	currentBlock->AddActorLocalOffset({ blockSize.X,0,0 });
}

void ABlockController::YminusW()
{
	currentBlock->AddActorLocalOffset({ 0,-blockSize.Y,0 });
}

void ABlockController::YplusS()
{
	currentBlock->AddActorLocalOffset({ 0,blockSize.Y,0 });
}

void ABlockController::SpeedUp()
{
	currentBlock->AddActorLocalOffset({ 0,0,-blockSize.Z });
}
