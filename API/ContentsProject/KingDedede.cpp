#include "PreCompile.h"
#include "KingDedede.h"

#include "Player.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>
#include <EngineBase/EngineRandom.h>

#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"
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
		SpriteRenderer->CreateAnimation("JumpAttack1_Left", "KingJumpAttack1_Left.png", 0,3, 0.4f, true);
		SpriteRenderer->CreateAnimation("JumpAttack1_Right", "KingJumpAttack1_Right.png", 0,3, 0.4f, true);
		SpriteRenderer->CreateAnimation("JumpAttack2_Left", "KingJumpAttack2_Left.png", 0, 3, 0.4f, true);
		SpriteRenderer->CreateAnimation("JumpAttack2_Right", "KingJumpAttack2_Right.png", 0, 3, 0.4f, true);
		SpriteRenderer->CreateAnimation("JumpAttack3_Left", "KingJumpAttack3_Left.png", 0, 1, 0.4f, true);
		SpriteRenderer->CreateAnimation("JumpAttack3_Right", "KingJumpAttack3_Right.png", 0, 1, 0.4f, true);
		SpriteRenderer->CreateAnimation("FlyAttack_Left", "KingFlyAttack_Left.png", 0, 8, 0.3f, true);
		SpriteRenderer->CreateAnimation("FlyAttack_Right", "KingFlyAttack_Right.png", 0, 8, 0.3f, true);
		SpriteRenderer->CreateAnimation("Damaged_Left", "KingDamaged_Left.png", 0, 0, 2.0f, false);
		SpriteRenderer->CreateAnimation("Damaged_Right", "KingDamaged_Right.png", 0, 0, 2.0f, false);
		/*SpriteRenderer->CreateAnimation("Die_Left", "KingDie_Left.png", 9, 9, 0.2f, true);
		SpriteRenderer->CreateAnimation("Die_Right", "KingDie_Right.png", 9, 9, 0.2f, true);*/
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
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, -100 });
		CollisionComponent->SetComponentScale({ 180, 180 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
		CollisionComponent->SetCollisionType(ECollisionType::CirCle);

		DebugOn();
	}
}

AKingDedede::~AKingDedede()
{
}

void AKingDedede::Chase(float _DeltaTime)
{
	AMonster::Chase(_DeltaTime);
	CheckPlayerPos();

	if (CurChaseTime > 500.0f)
	{
		CurChaseTime = 0.0f;
		ChangeState(EMonsterState::Attack);
		return;
	}
	CurChaseTime += 0.2f;

	/*AActor* Col= AttackColComponent->CollisionOnce(ECollisionGroup::PlayerBody);
	if (Col != nullptr)
	{
		int a = 0;
	}*/



	/*AActor* Player = GetWorld()->GetPawn();
	Player = dynamic_cast<APlayer*>(Player);

	FVector2D Range = Player->GetActorLocation() - this->GetActorLocation();
	float PlayerRange = Range.Length();*/



	/*if (PlayerRange <= MonsterToPlayerRange)
	{

		TargetPosVector = Player->GetActorLocation() - GetActorLocation();
		ChangeState(EMonsterState::Chase);
		return;
	}*/
	//SetActorLocation(GetActorLocation())
}

void AKingDedede::AttackStart()
{

	DirCheck();
	
	AttackRound = Random.RandomInt(1, 4);
	
	switch (AttackRound)
	{
	case 1:
		SpriteRenderer->ChangeAnimation("JumpAttack1" + DirString);

		break;
	case 2:
		SpriteRenderer->ChangeAnimation("JumpAttack2" + DirString);
		break;
	case 3:
		SpriteRenderer->ChangeAnimation("JumpAttack3" + DirString);
		break;
	case 4:
		SpriteRenderer->ChangeAnimation("FlyAttack" + DirString);
		break;

	default:
		SpriteRenderer->ChangeAnimation("JumpAttack1" + DirString);
		break;
	}

}

void AKingDedede::Attack(float _DeltaTime)
{

	if (1 == SpriteRenderer->GetCurIndex())
	{
		AttackColComponent->SetActive(true);
	}
	if (true == SpriteRenderer->IsCurAnimationEnd()) {

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
	MonsterToPlayerRange = 300.0f;
	int a = 0;
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
	// 아무것도 하지 않음
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
