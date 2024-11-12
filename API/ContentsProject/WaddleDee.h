#pragma once
#include "Monster.h"
// Ό³Έν :
class AWaddleDee : public AMonster
{
public:
	// constrcuter destructer
	AWaddleDee();
	~AWaddleDee();

	// delete Function
	AWaddleDee(const AWaddleDee& _Other) = delete;
	AWaddleDee(AWaddleDee&& _Other) noexcept = delete;
	AWaddleDee& operator=(const AWaddleDee& _Other) = delete;
	AWaddleDee& operator=(AWaddleDee&& _Other) noexcept = delete;

protected:
	void MoveStart() override;
private:

	class USpriteRenderer* SpriteRenderer = nullptr;
};

