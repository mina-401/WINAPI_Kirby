#pragma once
#include <EngineCore/GameMode.h>

// Ό³Έν :
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

protected:

private:

};

