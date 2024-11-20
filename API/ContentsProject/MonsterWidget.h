#pragma once

#include "Widget.h"
// Ό³Έν :
class AMonsterWidget : public AWidget 
{
public:
	// constrcuter destructer
	AMonsterWidget();
	~AMonsterWidget();

	// delete Function
	AMonsterWidget(const AMonsterWidget& _Other) = delete;
	AMonsterWidget(AMonsterWidget&& _Other) noexcept = delete;
	AMonsterWidget& operator=(const AMonsterWidget& _Other) = delete;
	AMonsterWidget& operator=(AMonsterWidget&& _Other) noexcept = delete;

	void Tick(float _deltaTime) override;
	void BeginPlay() override;

	void SetOwner(class AMonster* _Monster)
	{
		Owner = _Monster;
	}
protected:

private:
	class USpriteRenderer* MonHpBarCase = nullptr;
	class USpriteRenderer* MonHp = nullptr;
	FVector2D MapScale;
	FVector2D WinSize;
	FVector2D HpBarScale = { 183, 17 };

	class AMonster* Owner = nullptr;
};

