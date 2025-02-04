// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/NPC/AI/Tasks/BTTask_RangeAttack.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/BlackBoardComponent.h"

EBTNodeResult::Type UBTTask_RangeAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* MyController{ OwnerComp.GetAIOwner() };
	if (ensure(MyController))
	{
		ACharacter* MyPawn{ Cast<ACharacter>(MyController->GetPawn()) };
		if (MyPawn == nullptr)
		{
			return EBTNodeResult::Failed;
		}

		// replace socket location string with something better
		// Doesn't exist for us, just following the tutorial for now.
		FVector HornLocation { MyPawn->GetMesh()->GetSocketLocation("HornMagic_Socket") };

		AActor* TargetActor{ Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("TargetActor")) };
		if (TargetActor == nullptr)
		{
			return EBTNodeResult::Failed;
		}

		FVector Direction{ TargetActor->GetActorLocation() - HornLocation };
		FRotator HornRotation{ Direction.Rotation() };


		FActorSpawnParameters Params;
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		AActor* NewProjectile{ GetWorld()->SpawnActor<AActor>(ProjectileClass, HornLocation, HornRotation, Params) };

		return NewProjectile ? EBTNodeResult::Succeeded : EBTNodeResult::Failed;
	}

	return EBTNodeResult::Failed;
}
