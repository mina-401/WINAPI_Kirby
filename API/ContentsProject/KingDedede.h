#pragma once
#include "Monster.h"
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
	void AttackStart() override;
	void Attack(float _DeltaTime) override;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void AttackCollisionEnter(AActor* _ColActor);
protected:

private:

};

