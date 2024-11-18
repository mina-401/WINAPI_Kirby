#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// 설명 :

enum class EMonsterState
{
	Move,
	Chase,
	Attack,  
	Inhaled, 
	Hurt,
};

enum class ECopyAbilityStatus
{
	AbleCopy,
	UnableCopy,

};
class AMonster : public AActor
{
public:
	// constrcuter destructer

	//typedef AMonster Super;

	AMonster();
	~AMonster();

	// delete Function
	AMonster(const AMonster& _Other) = delete;
	AMonster(AMonster&& _Other) noexcept = delete;
	AMonster& operator=(const AMonster& _Other) = delete;
	AMonster& operator=(AMonster&& _Other) noexcept = delete;



public:
	void BlockMonsterPos(FVector2D _MapScale);
	void SetColImage(std::string_view _ColImageName);

	virtual void MoveStart();
	virtual void Move(float _DeltaTime);
	virtual void ChaseStart();
	virtual void Chase(float _DeltaTime);
	virtual void AttackStart();
	virtual void Attack(float _DeltaTime);
	virtual void InhaledStart();
	virtual void Inhaled(float _DeltaTime);
	virtual void DamagedStart();
	virtual void Damaged(float _DeltaTime);

	void DestroyStart();

	void ChangeState(EMonsterState _CurMonsterState);
	
	class U2DCollision* AttackColComponent = nullptr;

	EMonsterState GetCurMonsterState() const
	{
		return CurMonsterState;
	}
	ECopyAbilityStatus GetCopyAbilityStatus() const
	{
		return CopyAbilityStatus;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void CheckPlayerPos();

	

	virtual void CollisionEnter(AActor* _ColActor) {};
	virtual void CollisionStay(AActor* _ColActor) {};
	virtual void CollisionEnd(AActor* _ColActor) {};

	

	std::string DirString = "_Left";

	class UEngineWinImage* ColImage = nullptr;
	class USpriteRenderer* SpriteRenderer = nullptr;

	bool IsGround = false;
	float Speed = 100.0f;

	FVector2D GravityForce = FVector2D::ZERO;
	float DamageForce = 10.0f;
	FVector2D MoveVector = FVector2D::LEFT;
	FVector2D TargetPosVector = FVector2D::ZERO;

	FVector2D CurrPos = FVector2D::ZERO;
	float MonsterToPlayerRange = 150.0f;

	ECopyAbilityStatus CopyAbilityStatus = ECopyAbilityStatus::UnableCopy;
	EMonsterState CurMonsterState = EMonsterState::Move;
	class U2DCollision* SpawnColComponent = nullptr;


private:
	void MonsterClimbingUphill();
	void ChangeMonsterDir(float _DeltaTime);
	void MonsterGroundCheck(FVector2D _MovePos);
	bool MonsterNextPosCheck(float _DeltaTime, FVector2D _Vector);
	void MonsterDirCheck();
	void DirCheck();
	void MoveDirCheck(FVector2D _Pos);
	void JumpGravity(float _DeltaTime)
	{
		if (false == IsGround)
		{
			AddActorLocation(GravityForce * _DeltaTime);
			GravityForce += FVector2D::DOWN * _DeltaTime * 500.0f;
		}
		else {
			GravityForce = FVector2D::ZERO;
		}
	} 
	void Gravity(float _DeltaTime)
	{
		if (false == IsGround)
		{
			GravityForce += FVector2D::DOWN * _DeltaTime;
			AddActorLocation(GravityForce);
		}
		else {
			GravityForce = FVector2D::ZERO;
		}

		// 상시 
	}

private:

	float DamagedTime = 30.0f;
	float CurDamagedTime = 0.0f;
	

};

