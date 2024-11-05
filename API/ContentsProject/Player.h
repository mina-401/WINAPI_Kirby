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
protected:

private:
	FVector2D Size;
	float Speed = 1000.0f;
	int MySpriteIndex = 0;

	class USpriteRenderer* SpriteRenderer;
	class UEngineWinImage* ColImage = nullptr;
	// class std::vector< USpriteRenderer* LeftRenderer;
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
	void Slide(float _DeltaTime);
	void SlideRight(float _DeltaTime);
	void SlideLeft(float _DeltaTime);
	//void Fly(float _DeltaTime);

	bool isJump = false;
	bool isJumpLanding = false;
	// 상태는 아니지만 도움이나 체크에 처리되는 함수
	void Gravity()
	{

	}

};

