#pragma once
#include "Monster.h"
// Ό³Έν :
class AWaddleDoo : public AMonster
{
public:
	// constrcuter destructer
	AWaddleDoo();
	~AWaddleDoo();

	// delete Function
	AWaddleDoo(const AWaddleDoo& _Other) = delete;
	AWaddleDoo(AWaddleDoo&& _Other) noexcept = delete;
	AWaddleDoo& operator=(const AWaddleDoo& _Other) = delete;
	AWaddleDoo& operator=(AWaddleDoo&& _Other) noexcept = delete;

	void AttackStart() override;
	void Attack(float _DeltaTime) override;

	void BeginPlay() override;

protected:

private:
	

	void CollisionEnter(AActor* _ColActor) override;
	void CollisionStay(AActor* _ColActor)override;
	void CollisionEnd(AActor* _ColActor)override;

	//class USpriteRenderer* SpriteRenderer = nullptr;
};
