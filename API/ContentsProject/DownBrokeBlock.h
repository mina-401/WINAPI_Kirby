#pragma once
#include <EngineCore/Actor.h>
#include "DownBrokeBlock.h"
// Ό³Έν :
class ADownBrokeBlock : public AActor
{
public:
	// constrcuter destructer
	ADownBrokeBlock();
	~ADownBrokeBlock();

	void Tick(float _DeltaTime) override;
	void BeginPlay() override;

	// delete Function
	ADownBrokeBlock(const ADownBrokeBlock& _Other) = delete;
	ADownBrokeBlock(ADownBrokeBlock&& _Other) noexcept = delete;
	ADownBrokeBlock& operator=(const ADownBrokeBlock& _Other) = delete;
	ADownBrokeBlock& operator=(ADownBrokeBlock&& _Other) noexcept = delete;


protected:

private:
	class USpriteRenderer* SpriteRenderer = nullptr;
};

