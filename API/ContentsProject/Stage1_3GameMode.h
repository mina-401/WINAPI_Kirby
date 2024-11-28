#pragma once
#include <EngineCore/GameMode.h>
#include <EnginePlatform/EngineSound.h>
// Ό³Έν :
class AStage1_3GameMode : public AGameMode
{
public:
	// constrcuter destructer
	AStage1_3GameMode();
	~AStage1_3GameMode();

	// delete Function
	AStage1_3GameMode(const AStage1_3GameMode& _Other) = delete;
	AStage1_3GameMode(AStage1_3GameMode&& _Other) noexcept = delete;
	AStage1_3GameMode& operator=(const AStage1_3GameMode& _Other) = delete;
	AStage1_3GameMode& operator=(AStage1_3GameMode&& _Other) noexcept = delete;
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
protected:

private:
	USoundPlayer BGMPlayLevelPrismPlayer;
};

