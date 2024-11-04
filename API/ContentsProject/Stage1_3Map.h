#pragma once
#include <EngineCore/Actor.h>

// ���� :
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

protected:

private:
	class USpriteRenderer* SpriteRenderer = nullptr;
};
