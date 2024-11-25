#pragma once

#include <EngineCore/GameMode.h>

class AStage1_2GameMode : public AGameMode
{
public:
	// constrcuter destructer
	AStage1_2GameMode();
	~AStage1_2GameMode();
	// delete Function
	AStage1_2GameMode(const AStage1_2GameMode& _Other) = delete;
	AStage1_2GameMode(AStage1_2GameMode&& _Other) noexcept = delete;
	AStage1_2GameMode& operator=(const AStage1_2GameMode& _Other) = delete;
	AStage1_2GameMode& operator=(AStage1_2GameMode&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	class AMonster* MonsterHotHead = nullptr;
protected:

private:
};

