#include "PreCompile.h"
#include "HPItem.h"

#include "Player.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"

AHPItem::AHPItem()
{
	SetName("Item");

	{
		UImageManager::GetInst().CuttingSprite("Item_Life.png", { 20,20 });
		//UImageManager::GetInst().CuttingSprite("Item_SparkCopy.png", { 60, 59 });

		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();

		SpriteRenderer->SetSprite("Item_Life.png");
		SpriteRenderer->SetComponentScale({ 30 ,30 });

		SpriteRenderer->SetOrder(ERenderOrder::MONSTER);


	}

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, 0 });
		CollisionComponent->SetComponentScale({ 50, 50 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::Block);
		CollisionComponent->SetCollisionType(ECollisionType::CirCle);

		CollisionComponent->SetCollisionEnter(std::bind(&AHPItem::CollisionEnter, this, std::placeholders::_1));

		DebugOn();
	}
}

AHPItem::~AHPItem()
{
}
void AHPItem::CollisionEnter(AActor* _ColActor)
{
	APlayer* player = dynamic_cast<APlayer*>(_ColActor);
	if (nullptr != player)
	{
		//player->SetCurPlayerCopyState(this->GetCopyState());
		//player->SetColAnyActor(this);
		player->SetCurLife(player->GetCurLife() + 1);
		SetActive(false);
	}
}
void AHPItem::BeginPlay()
{
	Super::BeginPlay();

}

void AHPItem::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}

