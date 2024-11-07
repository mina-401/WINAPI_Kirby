#pragma once

#include <EngineCore/Actor.h>
// Ό³Έν :
class Widget : public AActor
{
public:
	// constrcuter destructer
	Widget();
	~Widget();

	// delete Function
	Widget(const Widget& _Other) = delete;
	Widget(Widget&& _Other) noexcept = delete;
	Widget& operator=(const Widget& _Other) = delete;
	Widget& operator=(Widget&& _Other) noexcept = delete;

protected:

private:

};

