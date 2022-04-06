// Fill out your copyright notice in the Description page of Project Settings.


#include "Engine/World.h"
#include "FootballComp.h"
#include "TouchTest.h"

// Sets default values for this component's properties
UFootballComp::UFootballComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFootballComp::BeginPlay()
{
	Super::BeginPlay();

	
	MainChar = GetWorld()->GetFirstPlayerController()->GetOwner();
	
	
	
}


// Called every frame
void UFootballComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UFootballComp::GetHit()
{
	return bHit;
}