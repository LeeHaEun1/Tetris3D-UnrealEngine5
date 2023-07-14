// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLevel/UnitBlockPawn.h"

void AUnitBlockPawn::LeftAction()
{

}

// ���� �ð��� ���������� �� ĭ�� �Ʒ��� ����������
void AUnitBlockPawn::Tick(float _Delta)
{
	currentTime += _Delta;
	if (currentTime > defaultFallingSpeed)
	{
		// block = self�� �� ĭ ����Ʈ����
		this->SetActorLocation(this->GetActorLocation()-FVector(0, 0, blockSizeZ));

		// currentTime initialize
		currentTime = 0;
	}
}
