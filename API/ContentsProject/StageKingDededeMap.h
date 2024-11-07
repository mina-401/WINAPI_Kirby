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
	void BeginPlay() override;
	void Tick(float _deltaTime) override;
protected:

private:

	FVector2D PngSize;
	FVector2D WinSize;
	FVector2D MapScale;
	class USpriteRenderer* SpriteRenderer = nullptr;
	class USpriteRenderer* ColSpriteRenderer = nullptr;
};

