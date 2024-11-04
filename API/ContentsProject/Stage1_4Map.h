#pragma once

// Ό³Έν :
class AStage1_4Map : public AActor
{
public:
	// constrcuter destructer
	AStage1_4Map();
	~AStage1_4Map();

	// delete Function
	AStage1_4Map(const AStage1_4Map& _Other) = delete;
	AStage1_4Map(AStage1_4Map&& _Other) noexcept = delete;
	AStage1_4Map& operator=(const AStage1_4Map& _Other) = delete;
	AStage1_4Map& operator=(AStage1_4Map&& _Other) noexcept = delete;

protected:

private:
	class USpriteRenderer* SpriteRenderer = nullptr;
};

