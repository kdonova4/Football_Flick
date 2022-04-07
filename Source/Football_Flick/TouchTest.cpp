// Fill out your copyright notice in the Description page of Project Settings.



#include "TouchTest.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "Engine/Engine.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/Vector.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"
#include "Curves/CurveFloat.h"
#include "Components/PrimitiveComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SceneComponent.h"
#include "Math/UnrealMathUtility.h"
#include "FootballComp.h"
// Sets default values for this component's properties
UTouchTest::UTouchTest()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTouchTest::BeginPlay()
{
	Super::BeginPlay();

	

	GetArrowComp();

	SetupInputComponent();
	
	

	PC = GetWorld()->GetFirstPlayerController();
	

	
	
	 
	//TArray<UActorComponent*> ComponentArray;
	//Football->GetComponents<UActorComponent>(ComponentArray);
	//for (int32 i = 0; i < ComponentArray.Num(); i++)
	//{
		//if (ComponentArray[i]->GetName() == "FootballComp")
		//{
			//FComp = ComponentArray[i];
		//}
	//}
	
	//UE_LOG(LogTemp, Error, TEXT("%s"), *FComp->GetName());
}

void UTouchTest::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if(InputComponent)
	{
		InputComponent->BindTouch(IE_Pressed, this, &UTouchTest::BeginTouch);
		InputComponent->BindTouch(IE_Repeat, this, &UTouchTest::HoldTouch);
		InputComponent->BindTouch(IE_Released, this, &UTouchTest::EndTouch);
	}
}

void UTouchTest::GetFootball()
{	
	//Getting The football actor in the scene
	TArray<AActor*> ActorsArray;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Football", ActorsArray);
	Football = ActorsArray.Pop(true);

}

void UTouchTest::GetArrowComp()
{
	//Getting THe Arrow point component
	TArray<UStaticMeshComponent*> ComponentsArray;
	GetOwner()->GetComponents<UStaticMeshComponent>(ComponentsArray);
	for( int32 i=0; i<ComponentsArray.Num(); i++ )
	{
    	if(ComponentsArray[i]->GetName() == "Point")
		{
			Point = ComponentsArray[i];
		}
	}
	
}

void UTouchTest::BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StartLocation = FVector2D(Location.X, Location.Y);
	//GEngine->AddOnScreenDebugMessage(0, 2, FColor::Black, TEXT("TOUCHING"));
	
	//UE_LOG(LogTemp, Error, TEXT("LOGGING"));
	// if(PC)
	// {
	// 	bool bIsCurrentlyPressed;
	// 	PC->GetInputTouchState(ETouchIndex::Touch1, TempLocationTwo.X, TempLocationTwo.Y, bIsCurrentlyPressed);
	// }
	//UE_LOG(LogTemp, Error, TEXT("%i"), TempLocationTwo.X);

	if(PC)
	{
		bool bIsCurrentlyPressed;
		PC->GetInputTouchState(ETouchIndex::Touch1, previousTouchLocation.X, previousTouchLocation.Y, bIsCurrentlyPressed);
	}
	
}

void UTouchTest::EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	GEngine->AddOnScreenDebugMessage(14, 2.f, FColor::Yellow, FString::Printf(TEXT("%f"), YDiff));

	EndLocation = FVector2D(Location.X, Location.Y);
	//GEngine->AddOnScreenDebugMessage(1, 2, FColor::Red, TEXT("ENDED TOUCHING"));
	
	
}

void UTouchTest::HoldTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	
	IsHolding = true;
	GEngine->AddOnScreenDebugMessage(3, 2, FColor::Orange, TEXT("TOUCHING"));
	
	//TODO
	//- Implement system to flick ball once the the flick strength is met, Only store start and end(the point where the flick is strongest) 
	//- test whether it can get bigger than min
	
	HoldLocation = Location;
	


	
	// ======TEST IDEAS=======
	//- test whether you can hold certain length of vector and maybe clear it after a short time - ths is to solve the draw and flick "bug"
	
	//This idea is to protect agaianst the drag or draw bug when someone doesnt just flick like normal - not urgently needed
	//- HOLD TOUCH POINT LOCATION IN THIS FUNCTION USE START TO GET DIRECTION, after short time clear and start again and use current touch position as start, once flick strong enough, use that as end instad of touch position
}	

void UTouchTest::FlingBallFromDragVector(float Angle, float size)
{
	//Getting Direction based on drag start and end location
	FVector2D Direction = (StartLocation - EndLocation);
	FVector PointF = Point->GetForwardVector() + Point->GetComponentLocation();
	FVector PointF2 = PointF + FVector(Direction.X,Direction.Y, 0.f);
	GetFootball();
	

	//Rotating the arrow to the direction of drag
	FRotator Rot = UKismetMathLibrary::FindLookAtRotation(Point->GetComponentLocation(), PointF2);
	
	//fixing angle for now  -  WILL CHANGE LATER BASED ON STRENGTH OF FLICK
	FMath::ClampAngle(Rot.Pitch, Angle, Angle);
	Rot.Pitch = Angle;
	Rot.Yaw = FMath::ClampAngle(Rot.Yaw, 65.f, 115.f);
	Point->SetWorldRotation(Rot);
	
	MeshComponenet = Cast<UStaticMeshComponent>(Football->GetRootComponent());
	//GEngine->AddOnScreenDebugMessage(-14, 10.f, FColor::Black, FString::Printf(TEXT("%f"), Rot.Yaw));
	//setting sim physics to true and pushing the ball off of the arrows forward vector
	MeshComponenet->SetSimulatePhysics(true);
	float power = MyCurvePower->GetFloatValue(size);
	MeshComponenet->AddImpulse(Point->GetForwardVector() * power);

}


// Called every frame
void UTouchTest::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	bool bIsCurrentlyPressed;
	PC->GetInputTouchState(ETouchIndex::Touch1, newTouchLocation.X, newTouchLocation.Y, bIsCurrentlyPressed);

	
	if (FBIsHit)
	{
		GEngine->AddOnScreenDebugMessage(-121, 10.f, FColor::Black, FString::Printf(TEXT("TRUE")));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-14, 10.f, FColor::Blue, FString::Printf(TEXT("False")));
	}
	
	
	//GEngine->AddOnScreenDebugMessage(-10, 1.f, FColor::Yellow, FString::Printf(TEXT("Rotation: %f - %f"), TempLocation.X, TempLocation.Y));
	
	//GEngine->AddOnScreenDebugMessage(-6, 1.f, FColor::Green, FString::Printf(TEXT("YDiff: %f"), YDiff));

	if(YDiff <= MinStrengthNeeded)
	{
		//GEngine->AddOnScreenDebugMessage(-16, 2.f, FColor::Purple, FString::Printf(TEXT("%f"), YDiff));
	}
	FVector LineTraceEnd = HoldLocation + GetOwner()->GetActorForwardVector() * 100;
	FHitResult Hit;
	if(bIsCurrentlyPressed)
	{
		// Raycast out to a certain distance (reach)
		FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
		PC->GetHitResultUnderFinger(
			ETouchIndex::Touch1,
			ECollisionChannel::ECC_Visibility,
			false,
			Hit
		);
	}
	

	AActor* ActorHit = Hit.GetActor();
	
	if(ActorHit)
	{
		GEngine->AddOnScreenDebugMessage(-19, 2.f, FColor::Orange, FString::Printf(TEXT("%s"), *ActorHit->GetName()));
		
	}
	
	if(bIsCurrentlyPressed)
	{
		float size = FVector2D(newTouchLocation - previousTouchLocation).Size();
		size *= -1.f;
		float delta = newTouchLocation.Y - previousTouchLocation.Y;
		GEngine->AddOnScreenDebugMessage(-18, 2.f, FColor::Red, FString::Printf(TEXT("%f"), size));
		if (FBIsHit && !bFlung)
		{
			
			if (size <= MinStrengthNeeded)
			{
				
				EndLocation.X = HoldLocation.X;
				EndLocation.Y = HoldLocation.Y;
				GEngine->AddOnScreenDebugMessage(-20, 2.f, FColor::Orange, FString::Printf(TEXT("%f"), size));
				float Angle = MyCurve->GetFloatValue(size);
				GEngine->AddOnScreenDebugMessage(13, 2.f, FColor::Green, FString::Printf(TEXT("%f"), Angle));
				FlingBallFromDragVector(Angle, size);
				GEngine->AddOnScreenDebugMessage(-16, 2.f, FColor::Purple, FString::Printf(TEXT("%f"), delta));
				
				bFlung = true;
				
			}
			
		}
		
		
		
		previousTouchLocation = newTouchLocation;
		

	}

}

void UTouchTest::SendBall()
{

}
	
	// if(!bFlung)
	// {
	// 	if(YDiff <= MinStrengthNeeded)
	// 	{
	// 		float speed = YDiff;
	// 		GEngine->AddOnScreenDebugMessage(0, 2.f, FColor::Black, FString::Printf(TEXT("%f"), speed));
	// 		EndLocation.X = HoldLocation.X;
	// 		EndLocation.Y = HoldLocation.Y;
			
			
			
	// 		 if(MyCurve)
	// 		 {
	// 		 	float Angle = MyCurve->GetFloatValue(speed);
	// 		 	GEngine->AddOnScreenDebugMessage(13, 2.f, FColor::Green, FString::Printf(TEXT("%f"), Angle));
	// 			FlingBallFromDragVector(Angle);
	// 		 }

	// 		bFlung = true;
			
	// 	}
	// }
	


