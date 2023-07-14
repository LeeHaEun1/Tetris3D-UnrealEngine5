// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLevel/TetrisGamemode.h"

void ATetrisGamemode::CreateWall(FVector mapSize, FVector blockSize, TSubclassOf<AActor> wallObject)
{
	FTransform Trans;
	Trans.SetLocation({ -1 * blockSize.X, -1 * blockSize.Y, -1 * blockSize.Z });
	AActor* SpawnedActor0 = GetWorld()->SpawnActor<AActor>(wallObject, Trans);
}
