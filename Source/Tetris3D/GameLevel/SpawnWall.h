// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnWall.generated.h"

UCLASS()
class TETRIS3D_API ASpawnWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnWall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
public:
	/*UFUNCTION(BlueprintCallable)
	FORCEINLINE void GetWallActor(AActor* _wall)
	{
		wall = _wall;
	}*/
	UFUNCTION(BlueprintCallable)
	void CreateWall(FVector mapSize, FVector blockSize, TSubclassOf<AActor> wallObject);

private:
	//AActor* wall;
	//int32 blockSize = 100;
	//FVector blockSize = FVector(100, 100, 100);
};