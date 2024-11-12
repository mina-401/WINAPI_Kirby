#pragma once
#include <EngineCore/Actor.h>

// 설명 :

enum class MonsterState
{
	Move,
	Attack,  
};
class AMonster : public AActor
{
public:
	// constrcuter destructer
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
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:
	MonsterState CurMonsterState = MonsterState::Move;

	class USpriteRenderer* SpriteRenderer = nullptr;
	class UEngineWinImage* ColImage = nullptr;

	std::string DirString = "_Left";

	bool IsGround = false;

	float Speed = 100.0f;

	FVector2D GravityForce = FVector2D::ZERO;
	FVector2D MoveVector = FVector2D::LEFT;

private:

	void DirCheck();

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
	void ChangeState(MonsterState _CurMonsterState);
	void MoveStart();
	void Move(float _DeltaTime);

	void ChangeMonsterDir(float _DeltaTime);

	void MonsterGroundCheck(FVector2D _MovePos);
	bool MonsterNextPosCheck(float _DeltaTime, FVector2D _Vector);
	void MonsterDirCheck();
};

