#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/ImageManager.h>
#include <EnginePlatform/EngineSound.h>

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
    Exhale,
    
};

enum class EPlayerCopyState
{
    Normal,
    Spark,
    Beam,
    Fire,
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
   
public:    
    class U2DCollision* CollisionComponent = nullptr;



protected:

private:
    FVector2D Size = { 0,0 };

    class USpriteRenderer* SpriteRenderer = nullptr;
    class UEngineWinImage* ColImage = nullptr;

    EPlayerState CurPlayerState = EPlayerState::Idle;
    EPlayerEatState CurPlayerEatState = EPlayerEatState::Normal;
    EPlayerCopyState CurPlayerCopyState = EPlayerCopyState::Normal;

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

    void ChangeMoveStateByCopy(int _KeyIndex);

    void FireIdleStart();
    void FireMoveStart();
    void FireDashStart();
    void FireCrouchStart();
    void FireBreakStart();
    void FireJumpStart();
    void ChangeJumpStateByEat(int _KeyIndx, bool _IsFly);
    void FireSlideStart();
    void FireFlyingStart();
    void FireFlyDownStart();


    void IdleStart();
    void Idle(float _DeltaTime);
    void ChangeIdleStateByCopy(int _KeyIndex);
    void CrouchStart();
    void Crouch(float _DeltaTime);
    void MoveStart();
    void Move(float _DeltaTime);
    void DashStart();
    void ChangeDashStateByCopy(int _KeyIndex);
    void BreakStart();
    void Breaking(float _DeltaTime);
    void Dash(float _DeltaTime);
    void AttackStart();
    void Attack(float _DeltaTime);

    void ChangeDashStateByEat(int _KeyIndex);
   
    void JumpStart();
    void Jump(float _DeltaTime);

    void SlideStart();
    void Slide(float _DeltaTime);
    void FlyStart();
    void FireFlyStart();
    void FlyingStart();
    void Fly(float _DeltaTime);
    void FlyStartAnim();
    void FlyDownAnim();
    void FlyDownStart();
    void FlyDown(float _DeltaTime);

    void ExhaleStart();

    void Exhale(float _DeltaTime);

    void InhaleStart();
    void Inhale(float _DeltaTime);

    void PlayerCameraCheck();
    void PlayerGroundCheck(FVector2D _MovePos);
    void PlayerSlideCheck(float _DeltaTime, FVector2D _Vector);
    bool PlayerNextPosCheck(float _DeltaTime, FVector2D _Vector);

    //void Attack(float _DeltaTime);


    void PlayerFlyCheck();
    void Accel(float _DeltaTime, FVector2D Vector);

    void DownHillGravity(float _DeltaTime) {

        if (false == IsGround)
        {
            
            DownHillGravityForce += FVector2D::DOWN* _DeltaTime*500.0f;
            AddActorLocation(DownHillGravityForce);
        }
        else {
            DownHillGravityForce = FVector2D::ZERO;
        }
    }
    void Gravity(float _DeltaTime)
    {
        if (false == IsGround)
        {
            GravityForce += FVector2D::DOWN * _DeltaTime*300.0f;
            AddActorLocation(GravityForce);
        }
        else {
            GravityForce = FVector2D::ZERO;
        }

        // 상시 
    }
    void FlyGravity(float _DeltaTime)
    {
        if (false == IsGround)
        {
            GravityForce += FVector2D::DOWN * _DeltaTime * 0.2f;
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
            GravityForce += FVector2D::DOWN * _DeltaTime * 0.5f;
            AddActorLocation(GravityForce);
        }
        else {
            GravityForce = FVector2D::ZERO;
        }

    }

    void SlideFriction(float _DeltaTime, FVector2D _Vector)
    {
        

        if (false == IsGround)
        {
            FrictionForce += (_Vector*(-1.0f) * _DeltaTime*0.1f);
            AddActorLocation(FrictionForce);
        }
        else
        {
            FrictionForce = FVector2D::ZERO;
        }

        // 상시 
    }
    void InhalingGravity(float _DeltaTime, FVector2D FVector);
    void DamageMonster(float _DeltaTime, FVector2D _Vector);
 
    void DeAccel(float _DeltaTime, FVector2D Vector)
    {
        // 입력 방향으로 가속한다
        Acc += Vector * 50.0f * _DeltaTime;
        AddActorLocation(Acc * _DeltaTime);
    }

    void BlockPlayerPos(FVector2D _MapScale);
private:
    FVector2D WinSize;

    FVector2D FrictionForce = FVector2D::ZERO;
    FVector2D GravityForce = FVector2D::ZERO;
    FVector2D DownHillGravityForce = FVector2D::ZERO;
    FVector2D InhalingForce = FVector2D::ZERO;
    FVector2D DamageForce = FVector2D::ZERO;
    FVector2D DashVector = FVector2D::RIGHT;
    FVector2D JumpPower = FVector2D(0.0f, -300.0f);

    FVector2D SlidePower = FVector2D(300.0f, 0.0f);
    FVector2D CurRSlidePower = FVector2D(300.0f, 0.0f);
    FVector2D CurSlidePower = FVector2D(300.0f, 0.0f);

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

    class U2DCollision* InhaleRightComponent = nullptr;
    class U2DCollision* InhaleLeftComponent = nullptr;
    class AKirbyWidget* PlayerHud = nullptr;

    class AMonster* ColMonster = nullptr;

    USoundPlayer BGMPlayLevelPrismPlayer;
    USoundPlayer BGMVictoryPlayer;
};

