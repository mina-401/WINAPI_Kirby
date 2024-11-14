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

	void AttackStart() override;
	void Attack(float _DeltaTime) override;
protected:
	//void Move(float _deltaTime) override;
	//void Chase(float _DeltaTime) override;

	void CollisionEnter(AActor* _ColActor) override;
	void CollisionStay(AActor* _ColActor)override;
	void CollisionEnd(AActor* _ColActor)override;
private:


};

