// Fill out your copyright notice in the Description page of Project Settings.


#include "EndlessGameState.h"

AEndlessGameState::AEndlessGameState() :
	Wind(0)
{

}


int32 AEndlessGameState::GetWind()
{
	return Wind;
}

void AEndlessGameState::SetWind(int32 newWind)
{
	Wind = newWind;
}