// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

#include <stdbool.h>

#include "Weapon.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	//QInst = CreateDefaultSubobject<UBaseAbility>(TEXT("EquippedQ"));
	//QInst = Create
	//QInst = ConstructItems<UBaseAbility>(UStaticMesh::StaticClass(), this, TEXT(""));
	//QInst = Cast<UBaseAbility>(CreateDefaultSubobject(TEXT("Equipped"), *QAbility, *QAbility, true, false, false));
	//QInst->AddToRoot();
	//QInst = AddComponent(TEXT("QAbility"), false, blankTransform, QAbility);
	//QInst->RegisterComponent();
	QInst = NewObject<UBaseAbility>(QAbility,TEXT("EquppiedQ"));
	QInst->RegisterComponent();
	QInst->Cast();
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Firing"));
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &ABaseCharacter::Forward);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &ABaseCharacter::Right);
	PlayerInputComponent->BindAction(TEXT("PrimaryFire"), EInputEvent::IE_Pressed, this, &ABaseCharacter::PrimaryFire);
	PlayerInputComponent->BindAction(TEXT("PrimaryFire"), EInputEvent::IE_Released, this, &ABaseCharacter::ReleasePrimaryFire);
	PlayerInputComponent->BindAction(TEXT("SecondaryFire"), EInputEvent::IE_Pressed, this, &ABaseCharacter::SecondaryFire);
	PlayerInputComponent->BindAction(TEXT("SecondaryFire"), EInputEvent::IE_Released, this, &ABaseCharacter::ReleaseSecondaryFire);
}

void ABaseCharacter::Forward(float AxisValue)
{
	//UE_LOG(LogTemp, Warning, TEXT("Forward"));
	//VerticalAxis = AxisValue;
	GetCharacterMovement()->AddInputVector(FVector(1,0,0) * AxisValue);
}

void ABaseCharacter::Right(float AxisValue)
{
	//HorizontalAxis = AxisValue;
	GetCharacterMovement()->AddInputVector(FVector(0,1,0) * AxisValue);
}

void ABaseCharacter::PrimaryFire()
{
	//UE_LOG(LogTemp, Warning, TEXT("Firing"));
	//Weapon
	if(WeaponInst!=nullptr)
	{
		if(WeaponInst->GetClass()->ImplementsInterface(UWeapon::StaticClass()))
		{
			//WeaponInst->PrimaryFire();
			Cast<IWeapon>(WeaponInst)->Execute_PrimaryFire(WeaponInst);
		}
	}
}

void ABaseCharacter::ReleasePrimaryFire()
{
	Cast<IWeapon>(WeaponInst)->Execute_ReleasePrimaryFire(WeaponInst);
}

void ABaseCharacter::SecondaryFire()
{
	if(WeaponInst!=nullptr)
	{
		if (WeaponInst->GetClass()->ImplementsInterface(UWeapon::StaticClass()))
		{
			Cast<IWeapon>(WeaponInst)->Execute_SecondaryFire(WeaponInst);
		}
	}
}

void ABaseCharacter::ReleaseSecondaryFire()
{
	Cast<IWeapon>(WeaponInst)->Execute_ReleaseSecondaryFire(WeaponInst);
}

