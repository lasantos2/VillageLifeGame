// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/NPC/VillagerCharacter.h"

// Sets default values
AVillagerCharacter::AVillagerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVillagerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVillagerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}