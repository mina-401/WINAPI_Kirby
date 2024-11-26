#include "PreCompile.h"
#include "Sparky.h"
#include "Player.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>

#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"
ASparky::ASparky()
{
	//CopyAbilityStatus = ECopyAbilityState::Spark;
	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SetName("Sparky");

		SpriteRenderer->SetSprite("Sparky_Left.png");
		SpriteRenderer->SetComponentScale({ 270, 270 });

		SpriteRenderer->SetOrder(ERenderOrder::MONSTER);

		UImageManager::GetInst().CuttingSprite("Sparky_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Sparky_Right.png", { 128, 128 });

		SpriteRenderer->CreateAnimation("Walk_Left", "Sparky_Left.png", 0, 2, 0.2f);
		SpriteRenderer->CreateAnimation("Walk_Right", "Sparky_Right.png", 0, 2, 0.2f);
		SpriteRenderer->CreateAnimation("Attack_Left", "Sparky_Left.png", {4,5,4,5,4,5,4,5,4,5,6,7}, 0.2f, true);
		SpriteRenderer->CreateAnimation("Attack_Right", "Sparky_Right.png", { 4,5,4,5,4,5,4,5,4,5,6,7 }, 0.2f, true);
		SpriteRenderer->CreateAnimation("Inhaled_Left", "Sparky_Left.png", 7, 7, 0.2f, true);
		SpriteRenderer->CreateAnimation("Inhaled_Right", "Sparky_Right.png", 7, 7, 0.2f, true);
		SpriteRenderer->CreateAnimation("Damaged_Left", "Sparky_Right.png", 7, 7, 0.2f, true);
		SpriteRenderer->CreateAnimation("Damaged_Right", "Sparky_Right.png", 7, 7, 0.2f, true);
		SpriteRenderer->ChangeAnimation("Walk_Left");
	}
	{
		AttackColComponent = CreateDefaultSubObject<U2DCollision>();
		AttackColComponent->SetComponentLocation({ 0, 0 });
		AttackColComponent->SetComponentScale({ 100, 100 });
		AttackColComponent->SetCollisionGroup(ECollisionGroup::MonsterAttack);
		AttackColComponent->SetCollisionType(ECollisionType::CirCle);

		AttackColComponent->SetCollisionEnter(std::bind(&ASparky::AttackCollisionEnter, this, std::placeholders::_1));
		//AttackColComponent->SetCollisionStay(std::bind(&ASparky::AttackCollisionStay, this, std::placeholders::_1));
		//AttackColComponent->SetCollisionEnd(std::bind(&ASparky::AttackCollisionEnd, this, std::placeholders::_1));
	}

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, 0 });
		CollisionComponent->SetComponentScale({ 50, 50 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
		CollisionComponent->SetCollisionType(ECollisionType::CirCle);

		DebugOn();
	}
}

ASparky::~ASparky()
{
}


void ASparky::AttackStart()
{
	AMonster::AttackStart();

	//SpriteRenderer->

	int a = 0;
}
//
void ASparky::Attack(float _DeltaTime)
{
	AMonster::Attack(_DeltaTime);

	if (2 >= SpriteRenderer->GetFrameIndex())
	{
		return;
	}
	if (nullptr != AttackColComponent) {
		AActor* ColActor = AttackColComponent->CollisionOnce(ECollisionGroup::PlayerBody);
		if (nullptr != ColActor)
		{
			APlayer* Target = dynamic_cast<APlayer*>(ColActor);
			if (nullptr != Target) {
				Target->ColKnockBackEnter(this);
			}
		}
	}
	
}

void ASparky::BeginPlay()
{
	AMonster::BeginPlay();
	SetCopyAbilityState(ECopyAbilityState::Spark);
}

void ASparky::Tick(float _DeltaTime)
{
	AMonster::Tick(_DeltaTime);

	if (BulletTime < CurBulletTime)
	{

		Attackable = true;
	}

	CurBulletTime += 0.02f;
}

void ASparky::AttackCollisionEnter(AActor* _ColActor)
{
	
		if (Attackable == false) return;
		if (CurMonsterState != EMonsterState::Inhaled) {
		
			Attackable = false;
			CurBulletTime = 0.0f;
			ChangeState(EMonsterState::Attack);
		}

	
}

//void ASparky::AttackCollisionStay(AActor* _ColActor)
//{
//}
//
//void ASparky::AttackCollisionEnd(AActor* _ColActor)
//{
//
//}

