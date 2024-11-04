#pragma once
#include <EngineCore/Actor.h>

class AStageKingDededeMap :public AActor
{
public:
	// constrcuter destructer
	AStageKingDededeMap();
	~AStageKingDededeMap();

	// delete Function
	AStageKingDededeMap(const AStageKingDededeMap& _Other) = delete;
	AStageKingDededeMap(AStageKingDededeMap&& _Other) noexcept = delete;
	AStageKingDededeMap& operator=(const AStageKingDededeMap& _Other) = delete;
	AStageKingDededeMap& operator=(AStageKingDededeMap&& _Other) noexcept = delete;

protected:

private:
	class USpriteRenderer* SpriteRenderer = nullptr;
};

