#pragma once
#include "EatItem.h"
// Ό³Έν :
class ASparkItem : public AEatItem
{
public:
	// constrcuter destructer
	ASparkItem();
	~ASparkItem();

	// delete Function
	ASparkItem(const ASparkItem& _Other) = delete;
	ASparkItem(ASparkItem&& _Other) noexcept = delete;
	ASparkItem& operator=(const ASparkItem& _Other) = delete;
	ASparkItem& operator=(ASparkItem&& _Other) noexcept = delete;
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
protected:

private:

};

