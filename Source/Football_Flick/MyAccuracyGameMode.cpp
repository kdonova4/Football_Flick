// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAccuracyGameMode.h"

AMyAccuracyGameMode::AMyAccuracyGameMode()
{

}

void AMyAccuracyGameMode::EndGame()
{
	//Super::EndGame();

	GEngine->AddOnScreenDebugMessage(1, 2, FColor::Red, TEXT("ENDED TOUCHING"));
}