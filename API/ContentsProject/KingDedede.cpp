#include "PreCompile.h"
#include "KingDedede.h"

#include "Player.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>
#include <EngineBase/EngineRandom.h>
#include "MonsterWidget.h"

#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"
#include "MonsterBullet.h"
#include "SoundManager.h"
AKingDedede::AKingDedede()
{
	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SetName("KingDedede");

		
		//SpriteRenderer->SetSprite("KingDedede_Left.png");
		SpriteRenderer->SetComponentScale({ 500, 500 });

		SpriteRenderer->SetOrder(ERenderOrder::MONSTER);

		UImageManager::GetInst().CuttingSprite("KingIdle_Left.png", { 200, 200 });
		UImageManager::GetInst().CuttingSprite("KingIdle_Right.png", { 200, 200 });
		UImageManager::GetInst().CuttingSprite("KingWalk_Left.png", { 200, 200 });
		UImageManager::GetInst().CuttingSprite("KingWalk_Right.png", { 200, 200 });
		UImageManager::GetInst().CuttingSprite("KingJumpAttack1_Left.png", { 200, 200 });
		UImageManager::GetInst().CuttingSprite("KingJumpAttack1_Right.png", { 200, 200 });
		UImageManager::GetInst().CuttingSprite("KingJumpAttack2_Left.png", { 200, 200 });
		UImageManager::GetInst().CuttingSprite("KingJumpAttack2_Right.png", { 200, 200 });
		UImageManager::GetInst().CuttingSprite("KingJumpAttack3_Left.png", { 200, 200 });
		UImageManager::GetInst().CuttingSprite("KingJumpAttack3_Right.png", { 200, 200 });
		UImageManager::GetInst().CuttingSprite("KingFlyAttack_Left.png", { 200, 200 });
		UImageManager::GetInst().CuttingSprite("KingFlyAttack_Right.png", { 200, 200 });
		UImageManager::GetInst().CuttingSprite("KingDamaged_Left.png", { 200, 200 });
		UImageManager::GetInst().CuttingSprite("KingDamaged_Right.png", { 200, 200 });
		UImageManager::GetInst().CuttingSprite("KingDie_Left.png", { 200, 200 });
		UImageManager::GetInst().CuttingSprite("KingDie_Right.png", { 200, 200 });


		SpriteRenderer->CreateAnimation("Idle_Left", "KingIdle_Left.png", 0,3, 0.5f, false);
		SpriteRenderer->CreateAnimation("Idle_Right", "KingIdle_Right.png", 0,3, 0.5f, false);
		SpriteRenderer->CreateAnimation("Walk_Left", "KingWalk_Left.png", 0,4, 0.2f);
		SpriteRenderer->CreateAnimation("Walk_Right", "KingWalk_Right.png",0,4, 0.2f);
		SpriteRenderer->CreateAnimation("JumpAttack1_Left", "KingJumpAttack1_Left.png", 0,3, 0.4f, false);
		SpriteRenderer->CreateAnimation("JumpAttack1_Right", "KingJumpAttack1_Right.png", 0,3, 0.4f, false);
		SpriteRenderer->CreateAnimation("JumpAttack2_Left", "KingJumpAttack2_Left.png", 0, 3, 0.4f, false);
		SpriteRenderer->CreateAnimation("JumpAttack2_Right", "KingJumpAttack2_Right.png", 0, 3, 0.4f, false);
		SpriteRenderer->CreateAnimation("JumpAttack3_Left", "KingJumpAttack3_Left.png", 0, 1, 0.4f, false);
		SpriteRenderer->CreateAnimation("JumpAttack3_Right", "KingJumpAttack3_Right.png", 0, 1, 0.4f, false);
		SpriteRenderer->CreateAnimation("FlyAttack_Left", "KingFlyAttack_Left.png", 0, 8, 0.3f, true);
		SpriteRenderer->CreateAnimation("FlyAttack_Right", "KingFlyAttack_Right.png", 0, 8, 0.3f, true);
		SpriteRenderer->CreateAnimation("Damaged_Left", "KingDamaged_Left.png", 0, 0, 1.5f, false);
		SpriteRenderer->CreateAnimation("Damaged_Right", "KingDamaged_Right.png", 0, 0, 1.5f, false);
		SpriteRenderer->CreateAnimation("Die_Left", "KingDie_Left.png", {0,1,2,2,2,2}, 0.5f, false);
		SpriteRenderer->CreateAnimation("Die_Right", "KingDie_Right.png", { 0,1,2,2,2,2 }, 0.5f, false);
		SpriteRenderer->ChangeAnimation("Idle_Left");

		//SpriteRenderer->SetAnimationEvent("Idle_Left", 3, std::bind(&AKingDedede::AKingDedede, this, FVector2D::RIGHT));

	}
	{
		AttackColComponent = CreateDefaultSubObject<U2DCollision>();
		AttackColComponent->SetComponentLocation({0,0});
		AttackColComponent->SetComponentScale({ 50, 50 });
		AttackColComponent->SetCollisionGroup(ECollisionGroup::MonsterAttack);
		AttackColComponent->SetCollisionType(ECollisionType::CirCle);

		AttackColComponent->SetCollisionEnter(std::bind(&AKingDedede::AttackCollisionEnter, this, std::placeholders::_1));
		//AttackColComponent->SetCollisionStay(std::bind(&ASparky::AttackCollisionStay, this, std::placeholders::_1));
		//AttackColComponent->SetCollisionEnd(std::bind(&ASparky::AttackCollisionEnd, this, std::placeholders::_1));

		AttackColComponent->SetActive(false);
	}

	{
		//CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, -100 });
		CollisionComponent->SetComponentScale({ 180, 180 });
		//CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
		//CollisionComponent->SetCollisionType(ECollisionType::CirCle);

		DebugOn();
	}
}

AKingDedede::~AKingDedede()
{
}
void AKingDedede::DieStart()
{
	BGMPlayer = UEngineSound::Play("MonsterDie.WAV");
	//
	CollisionComponent->SetActive(false);
	SpriteRenderer->ChangeAnimation("Die" + DirString);
	MonWidget->SetActive(false);

	{

		SoundManager& SoundManager = SoundManager::GetInst();
		USoundPlayer& BGMPlayer = SoundManager.GetSoundPlayer(); // 레퍼런스 사용


		if (true == BGMPlayer.IsPlaying())
		{
			BGMPlayer.Stop();

		}

	}

	BGMPlayer = UEngineSound::Play("Boss Clear.WAV");
	BGMPlayer.Loop(0);
}

void AKingDedede::Die(float _DeltaTime)
{
	if (true == SpriteRenderer->IsCurAnimationEnd())
	{
		IsActive = false;
		CollisionComponent->SetActive(false);
		//SetActive(false);
		
	}
	
}
void AKingDedede::Chase(float _DeltaTime)
{
	ChangeMonsterDir(_DeltaTime);
	ChaseStart();

	Gravity(_DeltaTime);
	MonsterGroundCheck(GravityForce);

	UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
	if (Color == UColor::BLACK)
	{
		//FVector2D Pos = { MoveVector.X, MoveVector.Y - 4.5f };
		FVector2D Pos = { 0.0f,-4.5f };
		//FVector2D NextPos = Pos *_DeltaTime * Speed;
		UColor NextColor = ColImage->GetColor(GetActorLocation() + Pos, UColor::WHITE);
		if (NextColor != UColor::BLACK)
		{
			AddActorLocation(FVector2D::UP);
		}

	}
	else {

		TargetPosVector.Normalize();
		MoveDirCheck(TargetPosVector);

		FVector2D NextPos = MoveVector * _DeltaTime * Speed;
		AddActorLocation(NextPos);
	}

	MonsterClimbingUphill();

	if (CurChaseTime > 500.0f)
	{
		CurChaseTime = 0.0f;
		ChangeState(EMonsterState::Attack);
		return;
	}
	CurChaseTime += 0.2f;
}

void AKingDedede::AttackStart()
{

	DirCheck();
	
	//AttackRound = Random.RandomInt(1, 4);
	AttackRound = 3;
	
	switch (AttackRound)
	{
	case 1:
		SpriteRenderer->ChangeAnimation("JumpAttack1" + DirString);
		AttackPointIndex = 3;

		break;
	case 2:
		SpriteRenderer->ChangeAnimation("JumpAttack2" + DirString);
		break;
	case 3:
		SpriteRenderer->ChangeAnimation("JumpAttack3" + DirString);
		AttackPointIndex = 1;
		break;
	case 4:
		SpriteRenderer->ChangeAnimation("FlyAttack" + DirString);
		break;

	default:
		SpriteRenderer->ChangeAnimation("JumpAttack3" + DirString);
		AttackPointIndex = 1;
		break;
	}

}

void AKingDedede::Attack(float _DeltaTime)
{

	if (AttackPointIndex == SpriteRenderer->GetCurIndex())
	{
		if (Bullet == nullptr) {
			AttackColComponent->SetActive(true);
			Bullet = GetWorld()->SpawnActor<AMonsterBullet>();
			Bullet->SetMainPawn(this);

			FVector2D Pos = { AttackColComponent->GetComponentLocation().X * 2,  AttackColComponent->GetComponentLocation().Y };
			Bullet->SetActorLocation(GetActorLocation() + Pos);
		}
		}
		
	if (true == SpriteRenderer->IsCurAnimationEnd()) {

		Bullet = nullptr;
		AttackColComponent->SetActive(false);
		ChangeState(EMonsterState::Idle);
		return;
	}
	
}

void AKingDedede::InhaledStart()
{
	return;
}

void AKingDedede::Inhaled(float _DeltaTime)
{
	ChangeState(EMonsterState::Idle);
	return;
}
void AKingDedede::InhalingGravity(float _DeltaTime, FVector2D _Vector)
{
	return;
}
void AKingDedede::MoveStart()
{
	AMonster::MoveStart();
}

void AKingDedede::Move(float _DeltaTime)
{
	AMonster::Move(_DeltaTime);
	if (CurChaseTime > ChaseTime)
	{
		CurChaseTime = 0.0f;
		ChangeState(EMonsterState::Chase);
		return;
	}
	CurChaseTime += 0.2f;

}

void AKingDedede::BeginPlay()
{
	AMonster::BeginPlay();

	//AttackRound = Random.RandomInt(1, 3);
	MonsterToPlayerRange = 150.0f;
	SetDamagePower(50.0f);

}

void AKingDedede::Tick(float _DeltaTime)
{
	AMonster::Tick(_DeltaTime);

	DirHammerCollision();

}

void AKingDedede::DirHammerCollision()
{
	if (DirString == "_Right")
	{
		AttackColComponent->SetComponentLocation(HammerRightPosition);

	}
	else {
		AttackColComponent->SetComponentLocation(HammerLeftPosition);

	}
}

void AKingDedede::IdleStart()
{
	AMonster::IdleStart();
}

void AKingDedede::Idle(float _DeltaTime)
{
	AMonster::Idle(_DeltaTime);

	if (true == SpriteRenderer->IsCurAnimationEnd())
	{
		ChangeState(EMonsterState::Move);
	}
	
}

void AKingDedede::ColKnockBackEnter(AActor* _ColActor)
{
	AMonster::ColKnockBackEnter(_ColActor);





}

void AKingDedede::CheckPlayerPos()
{
	AActor* Player = GetWorld()->GetPawn();
	Player = dynamic_cast<APlayer*>(Player);

	TargetPosVector = Player->GetActorLocation() - GetActorLocation();


}

void AKingDedede::AttackCollisionEnter(AActor* _ColActor)
{
	//int a = 0;
}
