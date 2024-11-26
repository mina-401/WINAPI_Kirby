#include "PreCompile.h"

#include "EatItem.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"

EatItem::EatItem()
{
	SetName("Item");
	{

		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();

		//SpriteRenderer->SetSprite("Sparky_Left.png");
		SpriteRenderer->SetComponentScale({ 270, 270 });

		SpriteRenderer->SetOrder(ERenderOrder::MONSTER);

		UImageManager::GetInst().CuttingSprite("Item_FireCopy_ani.png", { 128, 128 });

		SpriteRenderer->CreateAnimation("Move", "Item_FireCopy_ani.png", 0,4, 0.2f);
		SpriteRenderer->ChangeAnimation("Move");
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

EatItem::~EatItem()
{
}

