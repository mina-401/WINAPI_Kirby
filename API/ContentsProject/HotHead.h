#pragma once

#include "Monster.h"
// Ό³Έν :
class AHotHead : public AMonster
{
public:
	// constrcuter destructer
	AHotHead();
	~AHotHead();

	// delete Function
	AHotHead(const AHotHead& _Other) = delete;
	AHotHead(AHotHead&& _Other) noexcept = delete;
	AHotHead& operator=(const AHotHead& _Other) = delete;
	AHotHead& operator=(AHotHead&& _Other) noexcept = delete;
	void AttackStart() override;
	void Attack(float _DeltaTime) override;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	//void AttackCollisionEnter(AActor* _ColActor);
	void AttackBoomeCollisionEnter(AActor* _ColActor);
	//void SetIsBoome(bool _Is);
protected:

private:
	bool IsBoome = false;
	bool Attackable = true;

	float CurBulletTime = 0.0f;
	float BulletTime = 50.0f;
};

