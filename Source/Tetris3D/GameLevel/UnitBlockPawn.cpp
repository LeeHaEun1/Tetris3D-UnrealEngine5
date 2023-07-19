// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLevel/UnitBlockPawn.h"


// ���� �ð��� ���������� �� ĭ�� �Ʒ��� ����������
void AUnitBlockPawn::Tick(float _Delta)
{
	currentTime += _Delta;
	if (currentTime > defaultFallingSpeed)
	{
		// block = self�� �� ĭ ����Ʈ����
		AddActorLocalOffset(-FVector(0, 0, blockSize.Z));

		// currentTime initialize
		currentTime = 0;
	}
}


void AUnitBlockPawn::XminusA()
{
	AddActorLocalOffset(-FVector(blockSize.X, 0, 0));
}

void AUnitBlockPawn::XplusD()
{
	AddActorLocalOffset(FVector(blockSize.X, 0, 0));
}

void AUnitBlockPawn::YminusW()
{
	AddActorLocalOffset(-FVector(0, blockSize.Y, 0));
}

void AUnitBlockPawn::YplusS()
{
	AddActorLocalOffset(FVector(0, blockSize.Y, 0));
}
