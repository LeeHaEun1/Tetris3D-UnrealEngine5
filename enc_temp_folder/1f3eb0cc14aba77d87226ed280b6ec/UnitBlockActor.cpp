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

	currentTime += DeltaTime;
	if (currentTime > defaultFallingSpeed)
	{
		AddActorLocalOffset(-FVector(0, 0, myGamemode->blockSize.Z));

		// currentTime initialize
		currentTime = 0;
	}
}

//void AUnitBlockActor::XminusA()
//{
//	AddActorLocalOffset(-FVector(myGamemode->blockSize.X, 0, 0));
//}
//void AUnitBlockActor::XplusD()
//{
//	AddActorLocalOffset(FVector(myGamemode->blockSize.X, 0, 0));
//}
//void AUnitBlockActor::YminusW()
//{
//	AddActorLocalOffset(-FVector(0, myGamemode->blockSize.Y, 0));
//}
//void AUnitBlockActor::YplusS()
//{
//	AddActorLocalOffset(FVector(0, myGamemode->blockSize.Y, 0));
//}
