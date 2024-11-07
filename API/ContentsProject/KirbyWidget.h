#pragma once
#include "Widget.h"
// Ό³Έν :
class AKirbyWidget : public Widget
{
public:
	// constrcuter destructer
	AKirbyWidget();
	~AKirbyWidget();

	// delete Function
	AKirbyWidget(const AKirbyWidget& _Other) = delete;
	AKirbyWidget(AKirbyWidget&& _Other) noexcept = delete;
	AKirbyWidget& operator=(const AKirbyWidget& _Other) = delete;
	AKirbyWidget& operator=(AKirbyWidget&& _Other) noexcept = delete;

	void Tick(float _deltaTime) override;
	void BeginPlay() override;
protected:
	
private:
	class USpriteRenderer* Life = nullptr;
	class USpriteRenderer* Icon = nullptr;
	class USpriteRenderer* HpBarCase = nullptr;
	class USpriteRenderer* HpBar = nullptr;
	class USpriteRenderer* NameTag = nullptr;
	FVector2D MapScale;
	FVector2D WinSize;
};

