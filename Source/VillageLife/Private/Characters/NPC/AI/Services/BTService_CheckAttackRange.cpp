// Fill out your copyright notice in the Description page of Project Settings.

#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Characters/NPC/AI/Services/BTService_CheckAttackRange.h"

void UBTService_CheckAttackRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	// Check distance between AI Pawn and TargetActor

	UBlackboardComponent* BlackBoardComp{ OwnerComp.GetBlackboardComponent() };

	if (ensure(BlackBoardComp)) 
	{
		// TODO: Go back and undo hardcoding
		AActor* TargetActor{ Cast<AActor>(BlackBoardComp->GetValueAsObject("TargetActor")) };

		if (TargetActor)
		{
			AAIController* MyAIController{ OwnerComp.GetAIOwner() };
			if (ensure(MyAIController))
			{
				APawn* AIPawn{ MyAIController->GetPawn() };
				if (ensure(AIPawn))
				{
					double DistanceTo{ FVector::Distance(TargetActor->GetActorLocation(), AIPawn->GetActorLocation()) };

					bool bWithinRange{ DistanceTo < 2000.f };


					bool bHasLOS{ false };
					if (bWithinRange)
					{
						bHasLOS = MyAIController->LineOfSightTo(TargetActor);
					}




					BlackBoardComp->SetValueAsBool(AttackRangeKey.SelectedKeyName, (bWithinRange && bHasLOS));

				}
			}
		}
	}
}
