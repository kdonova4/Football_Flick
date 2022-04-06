// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "EndlessGameState.generated.h"

/**
 * 
 */
UCLASS()
class FOOTBALL_FLICK_API AEndlessGameState : public AGameStateBase
{
	GENERATED_BODY()
public:
		AEndlessGameState();

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			float Wind;

		UFUNCTION(BlueprintPure, Category = "GameFuctions", DisplayName = "GetWind")
			int32 GetWind();
		UFUNCTION(BlueprintCallable, Category = "GameFuctions", DisplayName = "SetWind")
			void SetWind(int32 newWind);

};
