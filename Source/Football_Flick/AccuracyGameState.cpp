// Fill out your copyright notice in the Description page of Project Settings.


#include "AccuracyGameState.h"

AAccuracyGameState::AAccuracyGameState() :
	Wind(0)
{

}

int32 AAccuracyGameState::GetWind()
{
	return Wind;
}

void AAccuracyGameState::SetWind(int32 newWind)
{
	Wind = newWind;
}