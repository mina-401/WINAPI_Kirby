#pragma once

#include <EngineCore/GameMode.h>
// Ό³Έν :
class AStage1_4GameMode : public AGameMode
{
public:
	// constrcuter destructer
	AStage1_4GameMode();
	~AStage1_4GameMode();

	// delete Function
	AStage1_4GameMode(const AStage1_4GameMode& _Other) = delete;
	AStage1_4GameMode(AStage1_4GameMode&& _Other) noexcept = delete;
	AStage1_4GameMode& operator=(const AStage1_4GameMode& _Other) = delete;
	AStage1_4GameMode& operator=(AStage1_4GameMode&& _Other) noexcept = delete;
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
protected:

private:

};

