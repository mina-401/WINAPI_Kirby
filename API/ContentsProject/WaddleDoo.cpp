#include "PreCompile.h"
#include "WaddleDoo.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>

#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"
AWaddleDoo::AWaddleDoo()
{
	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();

		SetName("WaddleDoo");

		SpriteRenderer->SetSprite("WaddleDoo_Left.png");
		SpriteRenderer->SetComponentScale({ 270, 270 });

		SpriteRenderer->SetOrder(ERenderOrder::MONSTER);

		UImageManager::GetInst().CuttingSprite("WaddleDoo_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("WaddleDoo_Right.png", { 128, 128 });

		SpriteRenderer->CreateAnimation("Walk_Left", "WaddleDoo_Left.png", 0, 4, 0.2f);
		SpriteRenderer->CreateAnimation("Walk_Right", "WaddleDoo_Right.png", 0, 4, 0.2f);
		SpriteRenderer->CreateAnimation("Attack_Left", "WaddleDoo_Left.png", { 5,6,5,6,5,6,7,8,8,8,8,8 }, 0.2f, true);
		SpriteRenderer->CreateAnimation("Attack_Right", "WaddleDoo_Right.png", { 5,6,5,6,5,6,7,8,8,8,8,8 }, 0.2f, true);
		SpriteRenderer->CreateAnimation("Inhaled_Left", "WaddleDoo_Left.png", 13, 13, 0.2f, true);
		SpriteRenderer->CreateAnimation("Inhaled_Right", "WaddleDoo_Right.png", 13, 13, 0.2f, true);
		SpriteRenderer->ChangeAnimation("Walk_Left");


	}
	{
		AttackColComponent = CreateDefaultSubObject<U2DCollision>();
		AttackColComponent->SetComponentLocation({ 0, 0 });
		AttackColComponent->SetComponentScale({ 150, 100 });
		AttackColComponent->SetCollisionGroup(ECollisionGroup::MonsterAttack);
		AttackColComponent->SetCollisionType(ECollisionType::CirCle);

		AttackColComponent->SetCollisionEnter(std::bind(&AWaddleDoo::CollisionEnter, this, std::placeholders::_1));
		AttackColComponent->SetCollisionStay(std::bind(&AWaddleDoo::CollisionStay, this, std::placeholders::_1));
		AttackColComponent->SetCollisionEnd(std::bind(&AWaddleDoo::CollisionEnd, this, std::placeholders::_1));
	}
	{
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, 0 });
		CollisionComponent->SetComponentScale({ 50, 50 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
		CollisionComponent->SetCollisionType(ECollisionType::CirCle);

		DebugOn();
	}
}

AWaddleDoo::~AWaddleDoo()
{
}

void AWaddleDoo::AttackStart()
{
	AMonster::AttackStart();
}

void AWaddleDoo::Attack(float _DeltaTime)
{
	AMonster::Attack(_DeltaTime);
}


void AWaddleDoo::CollisionEnter(AActor* _ColActor)
{

	//플레이어에게 공격한다.
	ChangeState(EMonsterState::Attack);

	//플레이어와 충돌
}

void AWaddleDoo::CollisionStay(AActor* _ColActor)
{
}

void AWaddleDoo::CollisionEnd(AActor* _ColActor)
{

}
