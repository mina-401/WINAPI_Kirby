#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/ImageManager.h>

// 명확히 하라.
// 점프내부에서는 점프와 관련된 코드만 실행하라.
enum class PlayerState
{
	Idle,
	Move,
	Jump,
	Slide,
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
	void SetDebug(bool _debug);


protected:

private:
	FVector2D Size;
	float Speed = 1000.0f;

	class USpriteRenderer* SpriteRenderer;
	class UEngineWinImage* ColImage = nullptr;

	PlayerState CurPlayerState = PlayerState::Idle;

	// 점프
	// 공격
	// 점프공격
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
	//void Fly(float _DeltaTime);

	
	// 상태는 아니지만 도움이나 체크에 처리되는 함수
	void Gravity(float _DeltaTime);

private:
	double CurrTime = 0;
	double CurrJumpTime = 0;

	bool IsDebug = true;

	int IsGround = false;
	bool IsMove = false;

	bool isJump = false;
	bool isJumpLanding = false;

	FVector2D GravityForce = FVector2D::ZERO;
};

