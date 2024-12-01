#include "PreCompile.h"
#include "BigBlock.h"



#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
#include <EngineCore/ImageManager.h>
#include <EngineCore/2DCollision.h>

ABigBlock::ABigBlock()
{
	UImageManager::GetInst().CuttingSprite("BlockBig.png", { 32, 32 });

	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetSprite("BlockBig.png");
		SpriteRenderer->SetOrder(ERenderOrder::MONSTER);
		SpriteRenderer->SetComponentScale({ 90, 90 });

	}


	{
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, 0 });
		CollisionComponent->SetComponentScale({ 90,90 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::Block);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
		//CollisionComponent->SetCollisionStay(std::bind(&AMonsterBullet::CollisionStay, this, std::placeholders::_1));

	}
	{
		DebugOn();
	}
}

ABigBlock::~ABigBlock()
{
}

void ABigBlock::Tick(float _DeltaTime)
{
	ABlock::Tick(_DeltaTime);


}

void ABigBlock::BeginPlay()
{
	ABlock::BeginPlay();
	Speed = 80.0f;
	SetActorLocation({ 2960,363-45 });
}