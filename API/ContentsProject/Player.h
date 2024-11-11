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

    class USpriteRenderer* SpriteRenderer = nullptr;
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
    void PlayerSlideCheck(float _DeltaTime, FVector2D _Vector);

    //void Attack(float _DeltaTime);

    void Accel(float _DeltaTime, FVector2D Vector)
    {
        //if (false == IsMove) return;

        // 입력 방향으로 가속한다
        Acc += Vector * Speed * _DeltaTime;

        // 최대 속도 제한한다
        float AccSize = (Acc.X * Acc.X) + (Acc.Y * Acc.Y);
        if (AccSize > MaxAcc * MaxAcc)
        {
            Acc = Vector * MaxAcc;
        }

        if (FVector2D::ZERO == Vector)
        {
            Acc = Acc * 0.9f;
        }

        AddActorLocation(Acc * _DeltaTime);
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
    void DeAccel(float _DeltaTime, FVector2D Vector)
    {
        // 입력 방향으로 가속한다
        Acc += Vector * 50.0f * _DeltaTime;
        AddActorLocation(Acc * _DeltaTime);
    }

    void BlockPlayerPos(FVector2D _MapScale);
private:
    FVector2D WinSize;

    FVector2D GravityForce = FVector2D::ZERO;

    float JumpTime = 70.0f;
    float CurrJumpTime = 0;

    float CurrSlideTime = 0;
    float SlideTime = 80.0f;

    float Speed = 300.0f;
    float MaxAcc = 1000.0f;

    bool IsDebug = true;

    bool IsGround = false;

    bool IsAcc = false;

    bool IsJump = false;

    FVector2D Acc = FVector2D::ZERO;

    class U2DCollision* CollisionComponent = nullptr;
    class AKirbyWidget* PlayerHud = nullptr;
};

