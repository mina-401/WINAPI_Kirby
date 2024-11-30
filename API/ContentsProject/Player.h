#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/ImageManager.h>
#include <EnginePlatform/EngineSound.h>
#include <EngineBase/EngineString.h>    

#include "ContentsEnum.h"
#include "ActorVector.h"

class PlayerStats
{
public:


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




    //void RunSoundPlay();



    void LevelChangeStart() override;
    void LevelChangeEnd() override;
    void SetColImage(std::string_view _ColImageName);

    void BlockCameraPos(FVector2D _MapScale, FVector2D _WinSize);
    //void SetDebug(bool _debug);


     void InhaleCollisionEnter(AActor* _ColActor);
     void InhaleCollisionStay(AActor* _ColActor);
     void InhaleCollisionEnd(AActor* _ColActor);

    void ColKnockBackEnter(AActor* _ColActor);
    void CollisionEnter(AActor* _ColActor);
    void CollisionStay(AActor* _ColActor);
    void CollisionEnd(AActor* _ColActor);
   
public:    
    class U2DCollision* CollisionComponent = nullptr;

    float GetMaxHp() const
    {
        return MaxHp;
    }

    
    float GetCurHp() const
    {
        return CurHp;
    }
    void SetCurHP(float _Hp)
    {
        CurHp = _Hp;
    }

    int GetCurLife() const
    {
        return Life;
    }
    void SetCurLife(int _Life)
    {
        Life = _Life;
    }

    AActor* GetColAnyActor() const
    {
        return ColAnyActor;
    }
    void SetColAnyActor(AActor* _col)
    {
        ColAnyActor = _col;
    }

    bool GetIsDamagedState()
    {
        return IsDamage;
    }
    void SetIsDamagedState(bool _IsDamage)
    {
        IsDamage = _IsDamage;
    }
    void SetPlayerColl(ECollisionGroup  _CurPlayerColl)
    {
        CurPlayerColl = _CurPlayerColl;
    }
    EPlayerState GetCurPlayerState() const
    {
        return CurPlayerState;
    }
    void SetCurPlayerCopyState(ECopyAbilityState _copy)
    {
        CurPlayerCopyState = _copy;
    }
    void SetKnockBackForce(FVector2D _Vector) {
        KnockBackVec = _Vector;

    }
    const ActorVector& GetBulletVector()
    {
        return BulletVector;
    }

    ECopyAbilityState GetCurPlayerCopyState() const
    {
        return CurPlayerCopyState;
    }

   /*static USoundPlayer GetPlaySound()
    {
        return BGMPlayer;
    }*/

    float GetDamagePower() const
    {
        return DamagePower;
    }
    void SetDamagePower(float _Power)
    {
        DamagePower = _Power;
    }

public:
    
    std::string DirString = "_Right";
   

protected:

private:
    //static USoundPlayer BGMPlayer;

    USoundPlayer BGMPlayer;
    FVector2D Size = { 0,0 };
    FVector2D KnockBackVec = FVector2D::ZERO;
    const float MaxHp = 100.0f;
    float CurHp = 0;
    int Life = 0;

    class USpriteRenderer* SpriteRenderer = nullptr;
    class UEngineWinImage* ColImage = nullptr;

    EPlayerState CurPlayerState = EPlayerState::Idle;
    EPlayerEatState CurPlayerEatState = EPlayerEatState::Normal;
    ECopyAbilityState CurPlayerCopyState = ECopyAbilityState::Normal;
    ECollisionGroup CurPlayerColl = ECollisionGroup::PlayerBody;

    float CurColTime = 0.0f;
    float ColTime = 50.0f;

    float ChangeTime = 50.0f;
    float CurChangeTime = 0.0f;

    // ����
    // ����
    // ��������
    // 

    


    void EatingIdleStart();
    void EatingMoveStart();
    void EatingDashStart();
    void EatingJumpStart();
    void EatingCrouchStart();

    
    void CheckSlideDir();

    void FireIdleStart();
    void FireMoveStart();
    void FireDashStart();
    void FireCrouchStart();
    void FireBreakStart();
    void FireJumpStart();
    void FireSlideStart();
    void FireFlyingStart();
    void FireFlyDownStart();
    void FireAttackStart();
    void FireKnockBackStart();
    void FireChangeStart();

    void SparkChangeStart();

    void SparkIdleStart();
    void SparkSlideStart();
    void SparkAttackStart();
    void SparkMoveStart();
    void SparkDashStart();
    void SparkCrouchStart();
    void SparkFlyingStart();
    void SparkFlyDownStart();
    void SparkJumpStart();  
    //void SparkKnockBackStart();

    void DirCheck();
    void ChangeState(EPlayerState CurPlayerState);
    void ChangeMoveStateByCopy(int _KeyIndex);
    void CreateJumpStar();
    void ChangeJumpStateByEat(int _KeyIndx, bool _IsFly);
    void ChangeIdleStateByCopy(int _KeyIndex);
    void ChangeDashStateByEat(int _KeyIndex);
    void ChangeDashStateByCopy(int _KeyIndex);

    void IdleStart();
    void Idle(float _DeltaTime);
    void CrouchStart();
    void Crouch(float _DeltaTime);
    void CrouchStartAnim();
    void MoveStart();
    void Move(float _DeltaTime);
    void DashStart();
    void BreakStart();
    void Breaking(float _DeltaTime);
    void Dash(float _DeltaTime);
    void PlayerKnockBack();
    void CheckFireDashState(float _DeltaTime, const FVector2D& Vector);
    void ColKnockBackEnter(FVector2D _Vector);
    void Attack(float _DeltaTime);
    void KnockBackStart();
    void KnockBack(float _DeltaTime);
    void DieStart();
    void Die(float _DeltaTime);
    void ChangeStart();
    void Change(float _DeltaTime);

    void AttackStartAnim();

   
    void JumpStart();
    void Jump(float _DeltaTime);

    void SlideStart();
    void Slide(float _DeltaTime);
    void FlyStart();
    void FireFlyStart();
    void SparkFlyStart();
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

    bool PlayerKnockBackNextPosCheck(float _DeltaTime, FVector2D _Vector);


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

        // ��� 
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

        // ��� 
    }
    void JumpGravity(float _DeltaTime)
    {
        if (false == IsGround)
        {
            GravityForce += FVector2D::DOWN * _DeltaTime * 0.4f;
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

        // ��� 
    }


 
    void DeAccel(float _DeltaTime, FVector2D Vector)
    {
        // �Է� �������� �����Ѵ�
        Acc += Vector * 50.0f * _DeltaTime;
        AddActorLocation(Acc * _DeltaTime);
    }

    void BlockPlayerPos(FVector2D _MapScale);

  
private:
    FVector2D WinSize;

    FVector2D FrictionForce = FVector2D::ZERO;
    FVector2D GravityForce = FVector2D::ZERO;
    FVector2D DownHillGravityForce = FVector2D::ZERO;
    FVector2D DamageForce = FVector2D::ZERO;
    FVector2D DashVector = FVector2D::RIGHT;
    FVector2D JumpPower = FVector2D(0.0f, -300.0f);

    FVector2D SlidePower = FVector2D(300.0f, 0.0f);
    FVector2D CurRSlidePower = FVector2D(300.0f, 0.0f);
    FVector2D CurSlidePower = FVector2D(300.0f, 0.0f);

    float DamagePower = 25.0f;

    float BreakTime = 100.0f;

    float CurDieTime = 0.0f;
    float DieTime = 100.0f;

    float DashTime = 70.0f;
    float CurrDashTime = 0;

    float CurrSlideTime = 0;
    float SlideTime = 80.0f;

    float Speed = 300.0f;
    float MaxAcc = 1000.0f;

    float AlphaTime = 1.f;
    float AlphaVar = 1.f;

    bool IsDebug = true;

    bool IsGround = false;

    bool IsAcc = false;

    bool IsJump = false;
    bool IsDash = false;
    bool IsFly = false;

    bool IsDamage = false;
    bool IsFireDashState = false;

    bool IsChange = false;
    bool IsCurPlayerStateChange = false;

    FVector2D Acc = FVector2D::ZERO;

    FVector2D Force = FVector2D::ZERO;

    class U2DCollision* InhaleRightComponent = nullptr;
    class U2DCollision* InhaleLeftComponent = nullptr;
    class AKirbyWidget* PlayerHud = nullptr;

    class AMonster* ColMonster = nullptr;
    class AMonsterFireBullet* ColBullet = nullptr;

    static USoundPlayer BGMPlayLevelPrismPlayer;
    USoundPlayer BGMVictoryPlayer;

    ActorVector BulletVector;
  
    class AActor* ColAnyActor = nullptr;
    class AJumpStar* star = nullptr;
    class AMonsterBullet* MonsterBullet = nullptr;
};

