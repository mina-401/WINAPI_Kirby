#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class AStage1_1Map :public AActor
{
public:
	// constrcuter destructer
	AStage1_1Map();
	~AStage1_1Map();

	// delete Function
	AStage1_1Map(const AStage1_1Map& _Other) = delete;
	AStage1_1Map(AStage1_1Map&& _Other) noexcept = delete;
	AStage1_1Map& operator=(const AStage1_1Map& _Other) = delete;
	AStage1_1Map& operator=(AStage1_1Map&& _Other) noexcept = delete;
	void BeginPlay() override;

protected:

private:
	class USpriteRenderer* SpriteRenderer = nullptr;
};

