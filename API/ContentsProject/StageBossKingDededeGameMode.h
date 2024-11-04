#pragma once
#include <EngineCore/GameMode.h>

class AStageBossKingDededeGameMode : public AGameMode
{
public:
	// constrcuter destructer
	AStageBossKingDededeGameMode();
	~AStageBossKingDededeGameMode();

	// delete Function
	AStageBossKingDededeGameMode(const AStageBossKingDededeGameMode& _Other) = delete;
	AStageBossKingDededeGameMode(AStageBossKingDededeGameMode&& _Other) noexcept = delete;
	AStageBossKingDededeGameMode& operator=(const AStageBossKingDededeGameMode& _Other) = delete;
	AStageBossKingDededeGameMode& operator=(AStageBossKingDededeGameMode&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
protected:

private:

};
