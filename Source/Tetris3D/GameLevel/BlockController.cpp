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
	currentBlock = TetrisGamemode->currentBlock;
}
