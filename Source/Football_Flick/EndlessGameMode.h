// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EndlessGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FOOTBALL_FLICK_API AEndlessGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	AEndlessGameMode();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	APlayerController* PC;
	//StartGame Conditions
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 FootballsLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Difficulty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DifficultyFloor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Score;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 HighScore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> SpawnPoints;
	


	UFUNCTION(BlueprintCallable, Category="GameFuctions", DisplayName="EndGame")
		virtual void EndGame();
	UFUNCTION(BlueprintPure, Category = "GameFuctions", DisplayName = "GetScore")
		int32 GetScore();
	UFUNCTION(BlueprintPure, Category = "GameFuctions", DisplayName = "GetHighScore")
		int32 GetHighScore();
	UFUNCTION(BlueprintPure, Category = "GameFuctions", DisplayName = "GetFootballsLeft")
		int32 GetFootballsLeft();
	UFUNCTION(BlueprintPure, Category = "GameFuctions", DisplayName = "GetDifficulty")
		int32 GetDifficulty();
	UFUNCTION(BlueprintPure, Category = "GameFuctions", DisplayName = "GetDifficultyFloor")
		int32 GetDifficultyFloor();
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "IncrementScore")
		int32 IncrementScore(int32 newScore);
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "SetScore")
		void SetScore(int32 newScore);
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "SetHighScore")
		int32 SetHighScore(int32 newHighScore);
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "SetFootballsLeft")
		void SetFootballsLeft(int32 newBalls);
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "SetDifficulty")
		void SetDifficulty(int32 newDifficulty);
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "SetDifficultyFloor")
		void SetDifficultyFloor(int32 newDifficultyFloor);
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "SetSpawnPoints")
		void SetSpawnPoints(const TArray<AActor*>& newSpawnPoints);
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "PauseGame")
		void PauseGame();
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "UnpauseGame")
		void UnpauseGame();
};
