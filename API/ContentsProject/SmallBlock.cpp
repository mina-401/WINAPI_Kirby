#include "PreCompile.h"

#include "SmallBlock.h"
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
#include <EngineCore/ImageManager.h>
#include <EngineCore/2DCollision.h>

ASmallBlock::ASmallBlock()
{
	UImageManager::GetInst().CuttingSprite("BlockNormal.png", { 16, 16 });

	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetSprite("BlockNormal.png");
		SpriteRenderer->SetOrder(ERenderOrder::MONSTER);
		SpriteRenderer->SetComponentScale({ 50, 50 });

	}


	{
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, 0 });
		CollisionComponent->SetComponentScale({ 50,50 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::Block);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
		//CollisionComponent->SetCollisionStay(std::bind(&AMonsterBullet::CollisionStay, this, std::placeholders::_1));

	}
	{
		DebugOn();
	}
}

ASmallBlock::~ASmallBlock()
{
}

void ASmallBlock::Tick(float _DeltaTime)
{
	ABlock::Tick(_DeltaTime);


}

void ASmallBlock::BeginPlay()
{
	ABlock::BeginPlay();

	SetActorLocation({ 817,287-25 });
}