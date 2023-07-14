// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameLevel/TetrisPawn.h"
#include "UnitBlockPawn.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS3D_API AUnitBlockPawn : public ATetrisPawn
{
	GENERATED_BODY()

protected:
	void Tick(float _Delta) override;

private:
	UPROPERTY(Category = "[ Unit Block Value ]", EditAnywhere, DisplayName = "Default Falling Speed")
	float defaultFallingSpeed = 1.0f;
	UPROPERTY(Category = "[ Unit Block Value ]", EditAnywhere, DisplayName = "Block Size Z")
	float blockSizeZ = 100.0f;

	float currentTime = 0.0f;
};
