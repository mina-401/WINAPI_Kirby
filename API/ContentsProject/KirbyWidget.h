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

protected:
	
private:

};

