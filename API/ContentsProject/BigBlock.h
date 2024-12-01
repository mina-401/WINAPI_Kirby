#pragma once

#include "Block.h"
// Ό³Έν :
class ABigBlock : public ABlock
{
public:
	// constrcuter destructer
	ABigBlock();
	~ABigBlock();

	void Tick(float _DeltaTime) override;
	void BeginPlay() override;

	// delete Function
	ABigBlock(const ABigBlock& _Other) = delete;
	ABigBlock(ABigBlock&& _Other) noexcept = delete;
	ABigBlock& operator=(const ABigBlock& _Other) = delete;
	ABigBlock& operator=(ABigBlock&& _Other) noexcept = delete;


protected:
	
private:
	class USpriteRenderer* SpriteRenderer = nullptr;
};

