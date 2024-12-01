#pragma once

#include <EngineCore/Actor.h>
#include "ContentsEnum.h"  

class AEatItem : public AActor
{
public:
	// constrcuter destructer
	AEatItem();
	~AEatItem();

	void CollisionEnter(AActor* _ColActor);

	// delete Function
	AEatItem(const AEatItem& _Other) = delete;
	AEatItem(AEatItem&& _Other) noexcept = delete;
	AEatItem& operator=(const AEatItem& _Other) = delete;
	AEatItem& operator=(AEatItem&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	FVector2D Lerp(const FVector2D& A, const FVector2D& B, float t)
	{
		return A + (B - A) * t;
	}

	void SetMainPawn(class APlayer* _MainPawn)
	{
		MainPawn = _MainPawn;
	}

	ECopyAbilityState GetCopyState() const
	{
		return CopyState;
	}

	void SetCopyState(ECopyAbilityState _CopyState)
	{
		CopyState = _CopyState;
	}
protected:
	class USpriteRenderer* SpriteRenderer = nullptr;
	class U2DCollision* CollisionComponent = nullptr;
private:

	float CurDeltaTime = 0.0f;
	float LerpTime = 0.9f;

	FVector2D Start = FVector2D::ZERO;
	FVector2D End = FVector2D::ZERO;

	class APlayer* MainPawn = nullptr;

	ECopyAbilityState CopyState = ECopyAbilityState::Normal;
};
