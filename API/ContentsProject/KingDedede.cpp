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

		SpriteRenderer->SetSprite("Sparky_Left.png");
		SpriteRenderer->SetComponentScale({ 270, 270 });

		SpriteRenderer->SetOrder(ERenderOrder::MONSTER);

		//UImageManager::GetInst().CuttingSprite("Sparky_Left.png", { 128, 128 });
		//UImageManager::GetInst().CuttingSprite("Sparky_Right.png", { 128, 128 });

		//SpriteRenderer->CreateAnimation("Walk_Left", "Sparky_Left.png", 0, 2, 0.2f);
		//SpriteRenderer->CreateAnimation("Walk_Right", "Sparky_Right.png", 0, 2, 0.2f);

	}
	{
		AttackColComponent = CreateDefaultSubObject<U2DCollision>();
		AttackColComponent->SetComponentLocation({ 0, 0 });
		AttackColComponent->SetComponentScale({ 100, 100 });
		AttackColComponent->SetCollisionGroup(ECollisionGroup::MonsterAttack);
		AttackColComponent->SetCollisionType(ECollisionType::CirCle);

		//AttackColComponent->SetCollisionEnter(std::bind(&ASparky::AttackCollisionEnter, this, std::placeholders::_1));
		//AttackColComponent->SetCollisionStay(std::bind(&ASparky::AttackCollisionStay, this, std::placeholders::_1));
		//AttackColComponent->SetCollisionEnd(std::bind(&ASparky::AttackCollisionEnd, this, std::placeholders::_1));
	}

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, 0 });
		CollisionComponent->SetComponentScale({ 100, 200 });
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
}

void AKingDedede::Attack(float _DeltaTime)
{
}

void AKingDedede::BeginPlay()
{
}

void AKingDedede::Tick(float _DeltaTime)
{
}

void AKingDedede::AttackCollisionEnter(AActor* _ColActor)
{
}
