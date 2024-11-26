#pragma once
#include <EngineCore/Actor.h>

class EatItem : public AActor
{
public:
	// constrcuter destructer
	EatItem();
	~EatItem();

	// delete Function
	EatItem(const EatItem& _Other) = delete;
	EatItem(EatItem&& _Other) noexcept = delete;
	EatItem& operator=(const EatItem& _Other) = delete;
	EatItem& operator=(EatItem&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:
	class USpriteRenderer* SpriteRenderer = nullptr;
	class U2DCollision* CollisionComponent = nullptr;
private:
	
};

