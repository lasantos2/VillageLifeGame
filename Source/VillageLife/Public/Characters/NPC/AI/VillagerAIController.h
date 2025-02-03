// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "VillagerAIController.generated.h"

class UBehaviorTree;

/**
 * 
 */
UCLASS()
class VILLAGELIFE_API AVillagerAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	

public:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;

};
