// Fill out your copyright notice in the Description page of Project Settings.


#include "AccuracyGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "AccuracyGameState.h"

AAccuracyGameMode::AAccuracyGameMode()
{

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/DefaultPawn_BP"));
	{
		if (PlayerPawnBPClass.Class != NULL)
		{
			DefaultPawnClass = PlayerPawnBPClass.Class;

		}
		else
		{
			GEngine->AddOnScreenDebugMessage(0, 2, FColor::Red, TEXT("NOT WORKING"));
		}
	}

	GameStateClass = AAccuracyGameState::StaticClass();

}

int32 AAccuracyGameMode::GetAccuracy()
{
	return Accuracy;
}

void AAccuracyGameMode::SetAccuracy(int32 newAccuracy)
{
	Accuracy = newAccuracy;
}

int32 AAccuracyGameMode::GetFootballsLeft()
{
	return FootballsLeft;
}

void AAccuracyGameMode::SetFootballsLeft(int32 newFootballs)
{
	FootballsLeft = newFootballs;
}

int32 AAccuracyGameMode::GetDifficulty()
{
	return Difficulty;
}

void AAccuracyGameMode::SetDifficulty(int32 newDifficulty)
{
	Difficulty = newDifficulty;
}

int32 AAccuracyGameMode::GetDifficultyFloor()
{
	return DIfficultyFloor;
}

void AAccuracyGameMode::SetDifficultyFloor(int32 newDIfficultyFloor)
{
	DIfficultyFloor = newDIfficultyFloor;
}

int32 AAccuracyGameMode::GetRecordAccuracy()
{
	return RecordAccuracy;
}

void AAccuracyGameMode::SetRecordAccuracy(int32 newRecord)
{
	RecordAccuracy = newRecord;
}