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
	void Tick(float _DeltaTime) override;

	void BeamSetActive(bool _bool);

protected:

private:
	
	void AttackCollisionEnter(AActor* _ColActor) ;
	void DooDirCheck();
	void AttackCollisionStay(AActor* _ColActor);
	void AttackCollisionEnd(AActor* _ColActor);
	void CollisionEnter(AActor* _ColActor) override;
	void BeamCollisionEnter(AActor* _ColActor);
	void BeamCollisionEnd(AActor* _ColActor);
	//void CollisionStay(AActor* _ColActor)override;
	//void CollisionEnd(AActor* _ColActor)override;

	class USpriteRenderer* BeamSpriteRenderer1 = nullptr;
	class USpriteRenderer* BeamSpriteRenderer2 = nullptr;
	class USpriteRenderer* BeamSpriteRenderer3= nullptr;
	class USpriteRenderer* BeamSpriteRenderer4 = nullptr;

	int R = 100;

	bool IsBoome = false;
	bool IsRightBeam = false;
	bool Attackable = true;
	bool IsActive = false;

	float CurBulletTime = 0.0f;
	float BulletTime = 50.0f;
	float Angle = 0.0f;
	float LeftAngle = -120.0f;
	float RightAngle = -60.0f;
	float CurPlusAngle = 0.0f;
};
