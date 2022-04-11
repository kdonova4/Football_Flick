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
		int32 FootballsLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Accuracy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 DIfficultyFloor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Difficulty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 RecordAccuracy;

	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "GetFootballsLeft")
		int32 GetFootballsLeft();
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "SetFootballsLeft")
		void SetFootballsLeft(int32 newFootballs);
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "GetAccuracy")
		int32 GetAccuracy();
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "SetAccuracy")
		void SetAccuracy(int32 newAccuracy);
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "GetDifficulty")
		int32 GetDifficulty();
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "SetDifficulty")
		void SetDifficulty(int32 newDifficulty);
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "GetDifficultyFloor")
		int32 GetDifficultyFloor();
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "SetDifficultyFloor")
		void SetDifficultyFloor(int32 newDifficultyFloor);
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "GetRecordAccuracy")
		int32 GetRecordAccuracy();
	UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "SetRecordAccuracy")
		void SetRecordAccuracy(int32 newRecord);
};
