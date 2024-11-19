#pragma once

#include "Widget.h"
// Ό³Έν :
class AMonsterWidget : public Widget 
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
protected:

private:
	class USpriteRenderer* MonHpBarCase = nullptr;
	class USpriteRenderer* MonHp = nullptr;
	FVector2D MapScale;
	FVector2D WinSize;
};

