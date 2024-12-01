#include "PreCompile.h"
#include "DownBrokeBlock.h"

#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
#include <EngineCore/ImageManager.h>
#include <EngineCore/2DCollision.h>

ADownBrokeBlock::ADownBrokeBlock()
{
	UImageManager::GetInst().CuttingSprite("BlockNormal.png", { 16, 16 });

	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetSprite("BlockNormal.png");
		SpriteRenderer->SetOrder(ERenderOrder::MONSTER);
		SpriteRenderer->SetComponentScale({ 35, 35 });

	}


	{
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, 0 });
		CollisionComponent->SetComponentScale({ 40,40 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::Block);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
		//CollisionComponent->SetCollisionStay(std::bind(&AMonsterBullet::CollisionStay, this, std::placeholders::_1));

	}
	{
		DebugOn();
	}
}

ADownBrokeBlock::~ADownBrokeBlock()
{
}

void ADownBrokeBlock::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}

void ADownBrokeBlock::BeginPlay()
{
	Super::BeginPlay();
	//Speed = 80.0f;
	//SetActorLocation({ 2960,363 - 45 });
}