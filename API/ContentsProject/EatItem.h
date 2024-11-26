#pragma once
#include <EngineCore/Actor.h>

class AEatItem : public AActor
{
public:
	// constrcuter destructer
	AEatItem();
	~AEatItem();

	// delete Function
	AEatItem(const AEatItem& _Other) = delete;
	AEatItem(AEatItem&& _Other) noexcept = delete;
	AEatItem& operator=(const AEatItem& _Other) = delete;
	AEatItem& operator=(AEatItem&& _Other) noexcept = delete;

	//void BeginPlay() override;
	//void Tick(float _DeltaTime) override;

protected:
	class USpriteRenderer* SpriteRenderer = nullptr;
	class U2DCollision* CollisionComponent = nullptr;
private:
	
};

