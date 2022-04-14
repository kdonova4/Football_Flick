// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AccuracyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FOOTBALL_FLICK_API AAccuracyGameMode : public AGameModeBase
{
	GENERATED_BODY()


public:

	AAccuracyGameMode();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		APlayerController* PC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 FootballsLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Accuracy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 TotalAccuracy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 DIfficultyFloor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Difficulty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 RecordAccuracy;

	UFUNCTION(BlueprintPure, Category = "GameFuctions", DisplayName = "GetFootballsLeft")
		int32 GetFootballsLeft();
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "SetFootballsLeft")
		void SetFootballsLeft(int32 newFootballs);
	UFUNCTION(BlueprintPure, Category = "GameFuctions", DisplayName = "GetAccuracy")
		int32 GetAccuracy();
	UFUNCTION(BlueprintPure, Category = "GameFuctions", DisplayName = "GetTotalAccuracy")
		int32 GetTotalAccuracy();
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "SetAccuracy")
		void SetAccuracy(int32 newAccuracy);
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "SetTotalAccuracy")
		int32 SetTotalAccuracy(int32 newTotalAccuracy);
	UFUNCTION(BlueprintPure, Category = "GameFuctions", DisplayName = "GetDifficulty")
		int32 GetDifficulty();
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "SetDifficulty")
		void SetDifficulty(int32 newDifficulty);
	UFUNCTION(BlueprintPure, Category = "GameFuctions", DisplayName = "GetDifficultyFloor")
		int32 GetDifficultyFloor();
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "SetDifficultyFloor")
		void SetDifficultyFloor(int32 newDifficultyFloor);
	UFUNCTION(BlueprintPure, Category = "GameFuctions", DisplayName = "GetRecordAccuracy")
		int32 GetRecordAccuracy();
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "SetRecordAccuracy")
		int32 SetRecordAccuracy(int32 newRecord);
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "PauseGame")
		void PauseGame();
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "UnpauseGame")
		void UnpauseGame();
};
