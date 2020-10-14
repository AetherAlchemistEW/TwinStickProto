// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAbility.h"

// Sets default values for this component's properties
UBaseAbility::UBaseAbility()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBaseAbility::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBaseAbility::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBaseAbility::Cast_Implementation()
{
	//UE_LOG(LogTemp, Warning, TEXT("Base implementation called"));
}

/*void UBaseAbility::Cast_Implementation()
{
}*/


