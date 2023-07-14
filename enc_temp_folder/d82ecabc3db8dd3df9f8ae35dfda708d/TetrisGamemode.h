// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TetrisGamemode.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS3D_API ATetrisGamemode : public AGameMode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CreateWall(FVector mapSize, FVector blockSize, TSubclassOf<AActor> wallObject);

protected:
	void Tick(float _Delta) override;
};
