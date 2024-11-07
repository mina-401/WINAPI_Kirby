#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class AStage1_2Map :public AActor
{
public:
	// constrcuter destructer
	AStage1_2Map();
	~AStage1_2Map();

	// delete Function
	AStage1_2Map(const AStage1_2Map& _Other) = delete;
	AStage1_2Map(AStage1_2Map&& _Other) noexcept = delete;
	AStage1_2Map& operator=(const AStage1_2Map& _Other) = delete;
	AStage1_2Map& operator=(AStage1_2Map&& _Other) noexcept = delete;

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

