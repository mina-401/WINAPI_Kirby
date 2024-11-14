#include "PreCompile.h"
#include "Sparky.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>

#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"
ASparky::ASparky()
{
	CopyAbilityStatus = ECopyAbilityStatus::AbleCopy;
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
		SpriteRenderer->ChangeAnimation("Walk_Left");
	}
	{
		AttackColComponent = CreateDefaultSubObject<U2DCollision>();
		AttackColComponent->SetComponentLocation({ 0, 0 });
		AttackColComponent->SetComponentScale({ 100, 100 });
		AttackColComponent->SetCollisionGroup(ECollisionGroup::MonsterAttack);
		AttackColComponent->SetCollisionType(ECollisionType::CirCle);

		AttackColComponent->SetCollisionEnter(std::bind(&ASparky::CollisionEnter, this, std::placeholders::_1));
		AttackColComponent->SetCollisionStay(std::bind(&ASparky::CollisionStay, this, std::placeholders::_1));
		AttackColComponent->SetCollisionEnd(std::bind(&ASparky::CollisionEnd, this, std::placeholders::_1));
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

ASparky::~ASparky()
{
}


void ASparky::AttackStart()
{
	AMonster::AttackStart();
	int a = 0;
}
//
void ASparky::Attack(float _DeltaTime)
{
	AMonster::Attack(_DeltaTime);
}

void ASparky::CollisionEnter(AActor* _ColActor)
{
	//플레이어에게 공격한다.
	ChangeState(EMonsterState::Attack);
}

void ASparky::CollisionStay(AActor* _ColActor)
{
}

void ASparky::CollisionEnd(AActor* _ColActor)
{

}

