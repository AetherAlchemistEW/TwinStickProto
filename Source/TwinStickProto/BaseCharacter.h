// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseAbility.h"
#include "BaseWeapon.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class TWINSTICKPROTO_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	/*UPROPERTY(BlueprintReadOnly)
	float HorizontalAxis;
	UPROPERTY(BlueprintReadOnly)
	float VerticalAxis;*/

	//TSubclassOf<UBaseAbility>
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UBaseAbility> QAbility;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<UBaseAbility> EAbility;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<UBaseAbility> RAbility;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UBaseAbility> StarterWeapon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Health;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool IsDead;
	
	//UBaseAbility*

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* WeaponInst;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UBaseAbility* QInst;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UBaseAbility* EInst;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UBaseAbility* RInst;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FTransform blankTransform;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
private:
	void Forward(float AxisValue);
    void Right(float AxisValue);
	void PrimaryFire();
	void ReleasePrimaryFire();
	void SecondaryFire();
	void ReleaseSecondaryFire();
};
