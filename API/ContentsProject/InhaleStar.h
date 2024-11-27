#pragma once
#include <EngineCore/Actor.h>
// Ό³Έν :
class AInhaleStar : public AActor
{
public:
	// constrcuter destructer
	AInhaleStar();
	~AInhaleStar();

	// delete Function
	AInhaleStar(const AInhaleStar& _Other) = delete;
	AInhaleStar(AInhaleStar&& _Other) noexcept = delete;
	AInhaleStar& operator=(const AInhaleStar& _Other) = delete;
	AInhaleStar& operator=(AInhaleStar&& _Other) noexcept = delete;

protected:

private:

};

