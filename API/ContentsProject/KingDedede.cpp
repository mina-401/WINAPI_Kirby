#include "PreCompile.h"
#include "KingDedede.h"

#include "Player.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>

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
		UImageManager::GetInst().CuttingSprite("KingWalk_Left.png", { 150, 150 });
		UImageManager::GetInst().CuttingSprite("KingWalk_Right.png", { 150, 150 });
		/*UImageManager::GetInst().CuttingSprite("KingJumpAttack1_Left.png", { 200, 200 });
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
		UImageManager::GetInst().CuttingSprite("KingDie_Right.png", { 200, 200 });*/

		//UImageManager::GetInst().CuttingSprite("Sparky_Right.png", { 128, 128 });

		SpriteRenderer->CreateAnimation("Idle_Left", "KingIdle_Left.png", 0,3, 0.5f, false);
		SpriteRenderer->CreateAnimation("Idle_Right", "KingIdle_Right.png", 0,3, 0.5f, false);
		SpriteRenderer->CreateAnimation("Walk_Left", "KingWalk_Left.png", 0,4, 0.2f);
		SpriteRenderer->CreateAnimation("Walk_Right", "KingWalk_Right.png",0,4, 0.2f);
		/*SpriteRenderer->CreateAnimation("JumpAttack1_Left", "KingJumpAttack1_Left.png", 0,0, 0.2f, true);
		SpriteRenderer->CreateAnimation("JumpAttack1_Right", "KingJumpAttack1_Right.png", 0,0, 0.2f, true);
		SpriteRenderer->CreateAnimation("JumpAttack2_Left", "KingJumpAttack2_Left.png", 0, 0, 0.2f, true);
		SpriteRenderer->CreateAnimation("JumpAttack2_Right", "KingJumpAttack2_Right.png", 0, 0, 0.2f, true);
		SpriteRenderer->CreateAnimation("JumpAttack3_Left", "KingJumpAttack3_Left.png", 0, 0, 0.2f, true);
		SpriteRenderer->CreateAnimation("JumpAttack3_Right", "KingJumpAttack3_Right.png", 0, 0, 0.2f, true);
		SpriteRenderer->CreateAnimation("FlyAttack_Left", "KingFlyAttack_Left.png", 0, 0, 0.2f, true);
		SpriteRenderer->CreateAnimation("FlyAttack_Right", "KingFlyAttack_Right.png", 0, 0, 0.2f, true);
		SpriteRenderer->CreateAnimation("Damaged_Left", "KingDamaged_Left.png", 9, 9, 0.2f, true);
		SpriteRenderer->CreateAnimation("Damaged_Right", "KingDamaged_Right.png", 9, 9, 0.2f, true);
		SpriteRenderer->CreateAnimation("Die_Left", "KingDie_Left.png", 9, 9, 0.2f, true);
		SpriteRenderer->CreateAnimation("Die_Right", "KingDie_Right.png", 9, 9, 0.2f, true);*/
		SpriteRenderer->ChangeAnimation("Idle_Left");

		//SpriteRenderer->SetAnimationEvent("Idle_Left", 3, std::bind(&AKingDedede::AKingDedede, this, FVector2D::RIGHT));

	}
	{
		/*AttackColComponent = CreateDefaultSubObject<U2DCollision>();
		AttackColComponent->SetComponentLocation({ 0, 0 });
		AttackColComponent->SetComponentScale({ 100, 200 });
		AttackColComponent->SetCollisionGroup(ECollisionGroup::MonsterAttack);
		AttackColComponent->SetCollisionType(ECollisionType::Rect);*/

		//AttackColComponent->SetCollisionEnter(std::bind(&ASparky::AttackCollisionEnter, this, std::placeholders::_1));
		//AttackColComponent->SetCollisionStay(std::bind(&ASparky::AttackCollisionStay, this, std::placeholders::_1));
		//AttackColComponent->SetCollisionEnd(std::bind(&ASparky::AttackCollisionEnd, this, std::placeholders::_1));
	}

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, 0 });
		CollisionComponent->SetComponentScale({ 100, -200 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);

		DebugOn();
	}
}

AKingDedede::~AKingDedede()
{
}

void AKingDedede::AttackStart()
{
	AMonster::AttackStart();
}

void AKingDedede::Attack(float _DeltaTime)
{
	AMonster::Attack(_DeltaTime);
}

void AKingDedede::MoveStart()
{
	AMonster::MoveStart();
}

void AKingDedede::Move(float _DeltaTime)
{
	AMonster::Move(_DeltaTime);
}

void AKingDedede::BeginPlay()
{
	AMonster::BeginPlay();
}

void AKingDedede::Tick(float _DeltaTime)
{
	AMonster::Tick(_DeltaTime);
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

void AKingDedede::AttackCollisionEnter(AActor* _ColActor)
{
}
