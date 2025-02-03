// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/NPC/AI/VillagerAIController.h"

void AVillagerAIController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(BehaviorTree);

}
