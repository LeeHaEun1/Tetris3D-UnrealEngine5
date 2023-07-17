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

public:
	UFUNCTION(BlueprintCallable)
	void XminusA();
	UFUNCTION(BlueprintCallable)
	void XplusD();
	UFUNCTION(BlueprintCallable)
	void YminusW();
	UFUNCTION(BlueprintCallable)
	void YplusS();

protected:
	void Tick(float _Delta) override;

private:
	UPROPERTY(Category = "[ Unit Block Value ]", EditAnywhere, DisplayName = "Default Falling Speed")
	float defaultFallingSpeed = 1.0f;
	UPROPERTY(Category = "[ Unit Block Value ]", EditAnywhere, DisplayName = "Block Size")
	FVector blockSize = {100,100,100};

	float currentTime = 0.0f;
};
