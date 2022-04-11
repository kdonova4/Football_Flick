// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EndlessGameMode.h"
#include "MyAccuracyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FOOTBALL_FLICK_API AMyAccuracyGameMode : public AEndlessGameMode
{
	GENERATED_BODY()

public:

	AMyAccuracyGameMode();
	
	
	virtual void EndGame() override;

};
