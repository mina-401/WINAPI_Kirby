#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/ImageManager.h>

// ��Ȯ�� �϶�.
// �������ο����� ������ ���õ� �ڵ常 �����϶�.
enum class PlayerState
{
	Idle,
	Move,
	Jump,
	Slide,
	Attack,
};

class APlayer : public AActor
{
public:
	// constrcuter destructer
	APlayer();
	~APlayer();

	// delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;



	/*void LeftMove();
	void RightMove();
	void UpMove();
	void DownMove();*/

	//void RunSoundPlay();

	void LevelChangeStart() override;
	void LevelChangeEnd() override;
	void SetColImage(std::string_view _ColImageName);

	void BlockCameraPos(FVector2D _MapScale, FVector2D _WinSize);
	//void SetDebug(bool _debug);


protected:

private:
	FVector2D Size = { 0,0 };
	float Speed = 1000.0f;

	class USpriteRenderer* SpriteRenderer = nullptr;
	class UEngineWinImage* ColImage = nullptr;

	PlayerState CurPlayerState = PlayerState::Idle;

	// ����
	// ����
	// ��������
	// 

	void ChangeState(PlayerState CurPlayerState);

	void IdleStart();
	void Idle(float _DeltaTime);
	void MoveStart();
	void JumpStart();
	void Jump(float _DeltaTime);
	void JumpUp(float _DeltaTime);
	void JumpDown(float _DeltaTime);
	void Move(float _DeltaTime);
	void SlideStart();
	void BreakRunning();
	void Slide(float _DeltaTime);
	void PlayerCameraCheck();
	void PlayerGroundCheck(FVector2D _MovePos);
	//void Attack(float _DeltaTime);

	
	// ���´� �ƴ����� �����̳� üũ�� ó���Ǵ� �Լ�
	//void Gravity(float _DeltaTime);



	void Accel(float _DeltaTime, FVector2D Vector)
	{
		 Acc += Vector * _DeltaTime * 2.0f;

		// ��� 
		AddActorLocation(Acc);
	}
private:
	double CurrTime = 0;
	double CurrJumpTime = 0;

	bool IsDebug = true;

	int IsGround = false;
	bool IsMove = false;
	bool IsAcc = false;

	bool isJump = false;
	bool isJumpLanding = false;

	//FVector2D GravityForce = FVector2D::ZERO;
	FVector2D Acc = FVector2D::ZERO;

	class U2DCollision* CollisionComponent=nullptr;
	class AKirbyWidget* PlayerHud=nullptr;
};

