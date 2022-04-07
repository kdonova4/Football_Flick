// Fill out your copyright notice in the Description page of Project Settings.


#include "EndlessGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "EndlessGameState.h"


AEndlessGameMode::AEndlessGameMode() :
	FootballsLeft(3),
	Difficulty(1),
	DifficultyFloor(0),
	Score(0),
	HighScore(0)
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

	GameStateClass = AEndlessGameState::StaticClass();
	
	
	
}

void AEndlessGameMode::EndGame()
{
	PC->Pause();
}

int32 AEndlessGameMode::GetScore()
{
	return Score;
}

int32 AEndlessGameMode::GetHighScore()
{
	return HighScore;
}


int32 AEndlessGameMode::GetFootballsLeft()
{
	return FootballsLeft;
}

int32 AEndlessGameMode::GetDifficulty()
{
	return Difficulty;
}

int32 AEndlessGameMode::GetDifficultyFloor()
{
	return DifficultyFloor;
}

int32 AEndlessGameMode::IncrementScore(int32 newScore)
{
	return Score + newScore;
}

void AEndlessGameMode::SetScore(int32 newScore)
{
	Score = newScore;
}

int32 AEndlessGameMode::SetHighScore(int32 newHighScore)
{
	return HighScore = newHighScore;
}

void AEndlessGameMode::SetFootballsLeft(int32 newBalls)
{
	FootballsLeft = newBalls;
}

void AEndlessGameMode::SetDifficulty(int32 newDifficulty)
{
	Difficulty = newDifficulty;
}

void AEndlessGameMode::SetDifficultyFloor(int32 newDifficultyFloor)
{
	DifficultyFloor = newDifficultyFloor;
}

void AEndlessGameMode::SetSpawnPoints(const TArray<AActor*>& newSpawnPoints)
{
	SpawnPoints = newSpawnPoints;
}

void AEndlessGameMode::PauseGame()
{
	PC->SetPause(true);
}

void AEndlessGameMode::UnpauseGame()
{
	PC->SetPause(false);
}
