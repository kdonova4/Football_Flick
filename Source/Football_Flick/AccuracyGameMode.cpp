// Fill out your copyright notice in the Description page of Project Settings.


#include "AccuracyGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "AccuracyGameState.h"

AAccuracyGameMode::AAccuracyGameMode() :
	FootballsLeft(20),
	Accuracy(0),
	RecordAccuracy(0),
	Difficulty(1),
	DIfficultyFloor(0),
	TotalAccuracy(0)
{

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/AccuracyPawn"));
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

int32 AAccuracyGameMode::GetTotalAccuracy()
{
	return TotalAccuracy;
}

void AAccuracyGameMode::SetAccuracy(int32 newAccuracy)
{
	Accuracy = newAccuracy;
}

int32 AAccuracyGameMode::GetFootballsLeft()
{
	return FootballsLeft;
}

int32 AAccuracyGameMode::SetTotalAccuracy(int32 newTotalAccuracy)
{
	TotalAccuracy = newTotalAccuracy;
	return TotalAccuracy;
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

void AAccuracyGameMode::PauseGame()
{
	PC->SetPause(true);
}

void AAccuracyGameMode::UnpauseGame()
{
	PC->SetPause(false);
}