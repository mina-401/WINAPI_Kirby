#pragma once
#include "EatItem.h"
#include <EnginePlatform/EngineSound.h>
// Ό³Έν :
class AFireItem : public AEatItem
{
public:
	// constrcuter destructer
	AFireItem();
	~AFireItem();

	// delete Function
	AFireItem(const AFireItem& _Other) = delete;
	AFireItem(AFireItem&& _Other) noexcept = delete;
	AFireItem& operator=(const AFireItem& _Other) = delete;
	AFireItem& operator=(AFireItem&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
protected:

private:
	
};

