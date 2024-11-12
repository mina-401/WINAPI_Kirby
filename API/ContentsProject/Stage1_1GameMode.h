#pragma once
#include <EngineCore/GameMode.h>

class AStage1_1GameMode : public AGameMode
{
public:
	// constrcuter destructer
	AStage1_1GameMode();
	~AStage1_1GameMode();

	// delete Function
	AStage1_1GameMode(const AStage1_1GameMode& _Other) = delete;
	AStage1_1GameMode(AStage1_1GameMode&& _Other) noexcept = delete;
	AStage1_1GameMode& operator=(const AStage1_1GameMode& _Other) = delete;
	AStage1_1GameMode& operator=(AStage1_1GameMode&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
protected:

public:
	class AMonster* MonsterWaddleDee = nullptr;
	class AMonster* MonsterWaddleDoo = nullptr;
	class AMonster* MonsterSparky = nullptr;
};

