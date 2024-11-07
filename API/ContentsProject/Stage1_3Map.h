#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class AStage1_3Map :public AActor
{
public:
	// constrcuter destructer
	AStage1_3Map();
	~AStage1_3Map();

	// delete Function
	AStage1_3Map(const AStage1_3Map& _Other) = delete;
	AStage1_3Map(AStage1_3Map&& _Other) noexcept = delete;
	AStage1_3Map& operator=(const AStage1_3Map& _Other) = delete;
	AStage1_3Map& operator=(AStage1_3Map&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _deltaTime) override;
protected:

private:
	FVector2D PngSize;
	FVector2D WinSize;
	FVector2D MapScale;
	class USpriteRenderer* SpriteRenderer = nullptr;
	class USpriteRenderer* ColSpriteRenderer = nullptr;
};

