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
}

// Called every frame
void AUnitBlockActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CheckFloor() == false)
	{
		currentTime += DeltaTime;
		if (currentTime > defaultFallingSpeed)
		{
			AddActorLocalOffset(-FVector(0, 0, myGamemode->blockSize.Z));

			// currentTime initialize
			currentTime = 0;
		}
	}
}

bool AUnitBlockActor::CheckFloor()
{
	FVector nextPos = GetActorLocation() - FVector(0, 0, myGamemode->blockSize.Z);
	
	// 블록 교체되면 코드 수정 필요
	// CheckUnitBlock 추가하면 이거로 다음블록이 안나오겠구나.. 각 (x,y)별 min z를 계산하고 이를 기준으로 해줘야하나??
	if (this->GetActorLocation().Z == 0)
	{
		//myGamemode->currentBlock = nullptr; // 이걸 계속 보내는 듯...
		//myGamemode->SpawnBlock(unitBlock);
		
		myGamemode->locationTag.Add(this->GetActorLocation(), this->Tags[0]);
		
		return true;
	}
	else
	{
		return false;
	}
}
