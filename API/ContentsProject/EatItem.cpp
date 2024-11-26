#include "PreCompile.h"

#include "EatItem.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"

AEatItem::AEatItem()
{
	SetName("Item");
	{

		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();

		SpriteRenderer->SetSprite("Item_FireCopy.png");
		SpriteRenderer->SetComponentScale({ 60, 60 });

		SpriteRenderer->SetOrder(ERenderOrder::MONSTER);

		UImageManager::GetInst().CuttingSprite("Item_FireCopy.png", { 60, 59 });

		//SpriteRenderer->CreateAnimation("Move", "Item_FireCopy_ani.png", { 3, 4 }, 0.5f);
		//SpriteRenderer->ChangeAnimation("Move");
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

AEatItem::~AEatItem()
{
}

