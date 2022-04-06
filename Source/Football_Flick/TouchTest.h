// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Curves/CurveFloat.h"
#include "Components/ActorComponent.h"
#include "TouchTest.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FOOTBALL_FLICK_API UTouchTest : public UActorComponent
{
	GENERATED_BODY()

	DECLARE_DELEGATE_OneParam(FBHit, bool);

public:	
	// Sets default values for this component's properties
	UTouchTest();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:	
	UInputComponent* InputComponent = nullptr;
	void BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void HoldTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void SetVariables();
	void SetupInputComponent();
	void GetFootball();
	void GetArrowComp();
	void FlingBallFromDragVector(float Angle, float size);
	void SendBall();
	bool bPressed;
	FVector2D TempLocation;
	FVector2D TempLocationTwo;
	FVector2D StartLocation;
	FVector2D EndLocation;
	FVector2D previousTouchLocation;
	FVector2D newTouchLocation;
	UStaticMeshComponent* MeshComponenet;
	APlayerController* PC;
	
	float FlickSpeed;
	FVector HoldLocation = FVector(0.f, 0.f, 0.f);
	FBHit FHit;
	UActorComponent* FComp = nullptr;
	

public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UCurveFloat* MyCurve = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UCurveFloat* MyCurvePower = nullptr;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MinStrengthNeeded = -5.f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	float XVeloOld;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	float XVeloNew;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	float YDiff;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	float YVeloNew;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	float YVeloOld;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	float XDiff;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	bool IsHolding;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	AActor* Football;
	UStaticMeshComponent* Point;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	bool FBIsHit = false;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	bool bFlung = false;

};
