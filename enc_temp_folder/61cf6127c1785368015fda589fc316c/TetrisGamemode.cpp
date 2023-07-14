// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLevel/TetrisGamemode.h"

void ATetrisGamemode::CreateWall(FVector mapSize, FVector blockSize, TSubclassOf<AActor> wallObject)
{
	// ø¯¡°: (-100, -100, -100)
	FTransform Trans0;
	Trans0.SetLocation({ -1 * blockSize.X, -1 * blockSize.Y, -1 * blockSize.Z });
	AActor* Wall0 = GetWorld()->SpawnActor<AActor>(wallObject, Trans0);

	// X, Y, Z√‡
	for (int i = 0; i < mapSize.X; i++)
	{
		FTransform Trans;
		Trans.SetLocation({ i * blockSize.X, -1 * blockSize.Y, -1 * blockSize.Z });
		AActor* WallX = GetWorld()->SpawnActor<AActor>(wallObject, Trans);
	}
	for (int i = 0; i < mapSize.Y; i++)
	{
		FTransform Trans;
		Trans.SetLocation({ -1 * blockSize.X, i * blockSize.Y, -1 * blockSize.Z });
		AActor* WallY = GetWorld()->SpawnActor<AActor>(wallObject, Trans);
	}
	for (int i = 0; i < mapSize.Z; i++)
	{
		FTransform Trans;
		Trans.SetLocation({ -1 * blockSize.X, -1 * blockSize.Y, i * blockSize.Z });
		AActor* WallZ = GetWorld()->SpawnActor<AActor>(wallObject, Trans);
	}
}
