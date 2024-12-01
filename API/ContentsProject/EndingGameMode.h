#pragma once
#include <EngineCore/GameMode.h>
#include <EnginePlatform/EngineSound.h>

class AEndingGameMode : public AGameMode
{
public:
	// constrcuter destructer
	AEndingGameMode();
	~AEndingGameMode();

	// delete Function
	AEndingGameMode(const AEndingGameMode& _Other) = delete;
	AEndingGameMode(AEndingGameMode&& _Other) noexcept = delete;
	AEndingGameMode& operator=(const AEndingGameMode& _Other) = delete;
	AEndingGameMode& operator=(AEndingGameMode&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
protected:

private:
	USoundPlayer BGMPlayer;
	class AFade* Actor = nullptr;
};

