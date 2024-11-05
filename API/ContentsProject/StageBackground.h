#pragma once
#include <EngineCore/Actor.h>
// Ό³Έν :
class AStageBackground :public AActor
{
public:
	// constrcuter destructer
	AStageBackground();
	~AStageBackground();

	// delete Function
	AStageBackground(const AStageBackground& _Other) = delete;
	AStageBackground(AStageBackground&& _Other) noexcept = delete;
	AStageBackground& operator=(const AStageBackground& _Other) = delete;
	AStageBackground& operator=(AStageBackground&& _Other) noexcept = delete;

	void BeginPlay() override;
protected:

private:
	class USpriteRenderer* SpriteRenderer = nullptr;
};

