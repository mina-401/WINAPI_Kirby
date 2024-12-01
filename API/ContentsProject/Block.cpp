#include "PreCompile.h"
#include "Block.h"
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
#include <EngineCore/ImageManager.h>
#include <EngineCore/2DCollision.h>

ABlock::ABlock()
{
	//b UImageManager::GetInst().CuttingSprite("BlockNormal.png", { 16, 16 });

	/*{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetSprite("BlockNormal.png");
		SpriteRenderer->SetOrder(ERenderOrder::MONSTER);
		SpriteRenderer->SetComponentScale({ 300, 300 });
	
	}*/


	//{
	//	U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
	//	CollisionComponent->SetComponentLocation({ 0, 0 });
	//	CollisionComponent->SetComponentScale({ 50,50 });
	//	CollisionComponent->SetCollisionGroup(ECollisionGroup::Block);
	//	CollisionComponent->SetCollisionType(ECollisionType::Rect);
	//	//CollisionComponent->SetCollisionStay(std::bind(&AMonsterBullet::CollisionStay, this, std::placeholders::_1));

	//}
	{

	}
}

ABlock::~ABlock()
{
}

void ABlock::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}

void ABlock::BeginPlay()
{
	Super::BeginPlay();
	
}