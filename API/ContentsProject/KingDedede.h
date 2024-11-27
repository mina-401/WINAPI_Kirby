#pragma once
#include "Monster.h"
#include <EngineBase/EngineRandom.h>
// Ό³Έν :
class AKingDedede : public AMonster
{
public:
	// constrcuter destructer
	AKingDedede();
	~AKingDedede();

	// delete Function
	AKingDedede(const AKingDedede& _Other) = delete;
	AKingDedede(AKingDedede&& _Other) noexcept = delete;
	AKingDedede& operator=(const AKingDedede& _Other) = delete;
	AKingDedede& operator=(AKingDedede&& _Other) noexcept = delete;
	




	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void IdleStart() override;
	void Idle(float _DeltaTime) override;
	void MoveStart() override;
	void Move(float _DeltaTime) override;
	//void ChaseStart() override;
	void Chase(float _DeltaTime) override;
	void AttackStart() override;
	void Attack(float _DeltaTime) override;
	//void InhaledStart() override;
	//void Inhaled(float _DeltaTime) override;
	//void DieStart() override;
	 void ColKnockBackEnter(AActor* _ColActor) override;

	 //void CheckPlayerPos() override;
	void AttackCollisionEnter(AActor* _ColActor);
protected:

private:
	 UEngineRandom Random;


	int AttackRound = 3;

};

