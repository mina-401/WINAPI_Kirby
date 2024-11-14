#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/ImageManager.h>

// 명확히 하라.
// 점프내부에서는 점프와 관련된 코드만 실행하라.
enum class EPlayerState
{
    Idle,
    Crouch,
    Move,
    Dash,
    Break,
    Jump,
    Fly,
    FlyDown,
    Slide,
    Attack,
    Inhale,
    
};
enum class EPlayerEatState
{
    Normal,
    Eating,

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


     void InhaleCollisionEnter(AActor* _ColActor);
     void InhaleCollisionStay(AActor* _ColActor);
     void InhaleCollisionEnd(AActor* _ColActor);

    void CollisionEnter(AActor* _ColActor);
    void CollisionStay(AActor* _ColActor);
    void CollisionEnd(AActor* _ColActor);
protected:

private:
    FVector2D Size = { 0,0 };

    class USpriteRenderer* SpriteRenderer = nullptr;
    class UEngineWinImage* ColImage = nullptr;

    EPlayerState CurPlayerState = EPlayerState::Idle;
    EPlayerEatState CurPlayerEatState = EPlayerEatState::Normal;

    std::string DirString = "_Right";

    // 점프
    // 공격
    // 점프공격
    // 

    void DirCheck();
    void ChangeState(EPlayerState CurPlayerState);
    void EatingIdleStart();
    void EatingMoveStart();
    void EatingDashStart();
    void EatingJumpStart();
    void EatingAttackStart();

    void IdleStart();
    void Idle(float _DeltaTime);
    void CrouchStart();
    void Crouch(float _DeltaTime);
    void MoveStart();
    void Move(float _DeltaTime);
    void DashStart();
    void BreakStart();
    void Breaking(float _DeltaTime);
    void Dash(float _DeltaTime);
   
    void JumpStart();
    void Jump(float _DeltaTime);

    void SlideStart();
    void Slide(float _DeltaTime);
    void FlyStart();
    void FlyingStart();
    void Fly(float _DeltaTime);
    void FlyDownStart();
    void FlyDown(float _DeltaTime);

    void InhaleStart();
    void Inhale(float _DeltaTime);

    void CheckInhaleMonster();

    void PlayerCameraCheck();
    void PlayerGroundCheck(FVector2D _MovePos);
    void PlayerSlideCheck(float _DeltaTime, FVector2D _Vector);
    bool PlayerNextPosCheck(float _DeltaTime, FVector2D _Vector);

    //void Attack(float _DeltaTime);


    void PlayerFlyCheck();
    void Accel(float _DeltaTime, FVector2D Vector);

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
    void JumpGravity(float _DeltaTime)
    {
        if (false == IsGround)
        {
            AddActorLocation(GravityForce * _DeltaTime );
            GravityForce += FVector2D::DOWN * _DeltaTime * 500.0f;
        }
        else {
            GravityForce = FVector2D::ZERO;
        }

    }

    void InhalingGravity(float _DeltaTime);
    void FlyGravity(float _DeltaTime)
    {
        if (false == IsGround)
        {
            GravityForce += FVector2D::DOWN * _DeltaTime*100.0f;
            AddActorLocation(GravityForce* _DeltaTime);
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
    FVector2D InhalingForce = FVector2D::ZERO;
    FVector2D InhalingVector = FVector2D::LEFT;
    FVector2D DashVector = FVector2D::RIGHT;
    FVector2D JumpPower = FVector2D(0.0f, -300.0f);

    float BreakTime = 100.0f;

    float DashTime = 70.0f;
    float CurrDashTime = 0;

    float CurrSlideTime = 0;
    float SlideTime = 80.0f;

    float Speed = 300.0f;
    float MaxAcc = 1000.0f;

    bool IsDebug = true;

    bool IsGround = false;

    bool IsAcc = false;

    bool IsJump = false;
    bool IsDash = false;
    bool IsFly = false;

    FVector2D Acc = FVector2D::ZERO;

    class U2DCollision* CollisionComponent = nullptr;
    class U2DCollision* InhaleComponent = nullptr;
    class AKirbyWidget* PlayerHud = nullptr;

    class AMonster* ColMonster = nullptr;
};

