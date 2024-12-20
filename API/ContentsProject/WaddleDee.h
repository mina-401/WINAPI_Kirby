#pragma once
#include "Monster.h"
// ���� :
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

	void BeginPlay() override;
	
	void AttackStart() override;
	void Attack(float _DeltaTime) override;

	void SpawnCollisionEnter(AActor* _ColActor);
	void CollisionEnter(AActor* _ColActor);
	//void CollisionStay(AActor* _ColActor)override;
	void CollisionEnd(AActor* _ColActor)override;
protected:
	
private:
};

