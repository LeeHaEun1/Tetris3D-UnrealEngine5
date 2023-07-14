// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLevel/UnitBlockPawn.h"

void AUnitBlockPawn::LeftAction()
{

}

// 일정 시간이 지날때마다 한 칸씩 아래로 떨어지도록
void AUnitBlockPawn::Tick(float _Delta)
{
	currentTime += _Delta;
	if (currentTime > defaultFallingSpeed)
	{
		// block = self을 한 칸 떨어트리고
		this->SetActorLocation(this->GetActorLocation()-FVector(0, 0, blockSizeZ));

		// currentTime initialize
		currentTime = 0;
	}
}
