// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLevel/BlockController.h"
#include "TetrisGamemode.h"
#include "Kismet/GameplayStatics.h"


bool ABlockController::CheckWall(FVector nextPos)
{
	// 빈 자리들에서는 locationTag[nextPos]를 가져올 수 없어서 예외 발생하는건가..?
	// -> key값에 해당하는 value의 pointer return하는 Find함수를 이용해 해결
	if (myGamemode->locationTag.Find(nextPos) == nullptr)
	{
		return false;
	}
	else
	{
		if (myGamemode->locationTag[nextPos] == FName("Wall"))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

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
	myGamemode = TetrisGamemode;

	// Get BlockSize
	blockSize = TetrisGamemode->blockSize;
}

void ABlockController::Tick(float DeltaTime)
{
	// Get currentBlock
	currentBlock = myGamemode->currentBlock;
}

void ABlockController::XminusA()
{
	FVector currPos = currentBlock->GetActorLocation();
	// nextPos 계산이 잘못되고 있었다.. 그냥 +(-blockSize.X, 0, 0)로 해주니 연산이 아예 안먹히고 있었음..ㅋ
	// 즉 currPos = nextPos인 상태로 CheckWall하고 있었기에 wall의 위치에 가서야 nextPos가 wall이라 판별하고 있었던 것
	FVector nextPos = currPos + FVector(-blockSize.X, 0, 0); // *********************
	bool checkWall = CheckWall(nextPos);

	if (checkWall == false)
	{
		currentBlock->AddActorLocalOffset({ -blockSize.X, 0, 0 });
	}
	else if(checkWall == true)
	{
		return;
	}
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
