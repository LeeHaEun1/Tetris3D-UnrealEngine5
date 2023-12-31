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
	void CreateWall(TSubclassOf<AActor> wallObject);

	UFUNCTION(BlueprintCallable)
	void SpawnFirstBlock(TSubclassOf<AActor> blockObject);

	UFUNCTION(BlueprintCallable)
	void SpawnBlock(TSubclassOf<AActor> blockObject);

	UPROPERTY(Category = "[ Map Value ]", EditAnywhere, DisplayName = "Map Size")
	FVector mapSize = { 5,5,10 };

	UPROPERTY(Category = "[ Unit Block Value ]", EditAnywhere, DisplayName = "Block Size")
	FVector blockSize = { 100,100,100 };

	AActor* currentBlock = nullptr;

	// FVector, 해당 Fvector에 위치한 Actor의 Tag를 담는 map
	TMap<FVector, FName> locationTag;


protected:
	//void Tick(float _Delta) override;
};
