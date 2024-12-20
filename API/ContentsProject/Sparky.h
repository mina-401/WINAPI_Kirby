#pragma once
#include "Monster.h"
// ���� :
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

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void AttackCollisionEnter(AActor* _ColActor);
//	void AttackCollisionStay(AActor* _ColActor);
	//void AttackCollisionEnd(AActor* _ColActor);
protected:
	//void Move(float _deltaTime) override;
	//void Chase(float _DeltaTime) override;

	//void CollisionEnter(AActor* _ColActor) override;
	//void CollisionStay(AActor* _ColActor)override;
	//void CollisionEnd(AActor* _ColActor)override;
private:
	bool IsBoome = false;
	bool Attackable = true;

	float CurBulletTime = 0.0f;
	float BulletTime = 50.0f;

};

