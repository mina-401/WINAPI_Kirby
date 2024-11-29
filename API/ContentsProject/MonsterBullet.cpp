#include "PreCompile.h"
#include "MonsterBullet.h"
#include "Player.h"
#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>
#include "Monster.h"

 
AMonsterBullet::AMonsterBullet()
{
	UImageManager::GetInst().CuttingSprite("StarBulletIdle_Left.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("StarBulletIdle_Right.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("BackGroundStar.png", { 128, 128 });

	{
		BackSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		BackSpriteRenderer->SetSprite("BackGroundStar.png");
		BackSpriteRenderer->SetOrder(ERenderOrder::MONSTER);
		BackSpriteRenderer->SetComponentScale({ 400, 400 });

		//BackSpriteRenderer->CreateAnimation("BackGroundStar", "BackGroundStar.png", 0, 0, 0.06f, true);
		//BackSpriteRenderer->ChangeAnimation("BackGroundStar");

		    
	}
	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		//SpriteRenderer->SetSprite("StarBulletIdle_Left.png");
		SpriteRenderer->SetOrder(ERenderOrder::MONSTER);
		SpriteRenderer->SetComponentScale({ 300, 300 });
		SpriteRenderer->CreateAnimation("StarBulletIdle_Left", "StarBulletIdle_Left.png", 0, 1, 0.06f, true);
		SpriteRenderer->CreateAnimation("StarBulletIdle_Right", "StarBulletIdle_Right.png", 0, 1, 0.06f, true);
		SpriteRenderer->ChangeAnimation("StarBulletIdle_Left");
	}

	
	{
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, 0 });
		CollisionComponent->SetComponentScale({ 50,50 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::Block);
		CollisionComponent->SetCollisionType(ECollisionType::CirCle);
		//CollisionComponent->SetCollisionEnter(std::bind(&AMonsterBullet::CollisionEnter, this, std::placeholders::_1));

	}
	{
		
	}
	DebugOn();
	Destroy(5.0f);

}

AMonsterBullet::~AMonsterBullet()
{
}

void AMonsterBullet::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AlphaTime -= _DeltaTime;
	if (AlphaTime > 0.f)
	{
		BackSpriteRenderer->SetAlphafloat(AlphaValue);
		AlphaValue = 1.f - AlphaValue;
	}
	
}

void AMonsterBullet::BeginPlay()
{
	Super::BeginPlay();
}
