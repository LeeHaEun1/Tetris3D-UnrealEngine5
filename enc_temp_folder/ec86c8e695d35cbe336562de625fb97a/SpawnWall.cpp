// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnWall.h"

// Sets default values
ASpawnWall::ASpawnWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

