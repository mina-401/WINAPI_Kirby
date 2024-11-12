#pragma once
#include "Monster.h"
// Ό³Έν :
class ASparky : public AMonster
{
public:
	// constrcuter destructer
	ASparky();
	~ASparky(); 

	// delete Function
	ASparky(const ASparky& _Other) = delete;
	ASparky(ASparky&& _Other) noexcept = delete;
	ASparky& operator=(const ASparky& _Other) = delete;
	ASparky& operator=(ASparky&& _Other) noexcept = delete;

protected:

private:

};

