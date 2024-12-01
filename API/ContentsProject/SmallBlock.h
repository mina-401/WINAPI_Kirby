#pragma once
#include "Block.h"
#include <EngineCore/Actor.h>
// Ό³Έν :
class ASmallBlock : public ABlock
{
public:
	// constrcuter destructer
	ASmallBlock();
	~ASmallBlock();

	void Tick(float _DeltaTime) override;
	void BeginPlay() override;

	// delete Function
	ASmallBlock(const ASmallBlock& _Other) = delete;
	ASmallBlock(ASmallBlock&& _Other) noexcept = delete;
	ASmallBlock& operator=(const ASmallBlock& _Other) = delete;
	ASmallBlock& operator=(ASmallBlock&& _Other) noexcept = delete;

	
protected:

private:
	class USpriteRenderer* SpriteRenderer = nullptr;
};

