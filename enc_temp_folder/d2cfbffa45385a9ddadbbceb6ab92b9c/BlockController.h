// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BlockController.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS3D_API ABlockController : public APlayerController
{
	GENERATED_BODY()
	
public:
	//UPROPERTY(BlueprintCallable)
	AActor* currentBlock;

	UFUNCTION(BlueprintCallable)
		void XminusA();
	UFUNCTION(BlueprintCallable)
		void XplusD();
	UFUNCTION(BlueprintCallable)
		void YminusW();
	UFUNCTION(BlueprintCallable)
		void YplusS();



protected:
	virtual void BeginPlay() override;
};
