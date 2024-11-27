#include "PreCompile.h"
#include <EngineCore/SpriteRenderer.h>
#include "FireItem.h"
#include <EngineCore/ImageManager.h>

AFireItem::AFireItem()
{

	{
		UImageManager::GetInst().CuttingSprite("Item_FireCopy.png", { 60, 59 });
		//UImageManager::GetInst().CuttingSprite("Item_SparkCopy.png", { 60, 59 });

		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();

		SpriteRenderer->SetSprite("Item_FireCopy.png");
		SpriteRenderer->SetComponentScale({ 60, 60 });

		SpriteRenderer->SetOrder(ERenderOrder::MONSTER);


	}

	SetName("FireItem");
}

AFireItem::~AFireItem()
{
}

void AFireItem::BeginPlay()
{

	AEatItem::BeginPlay();
	SetCopyState(ECopyAbilityState::Fire);

}

void AFireItem::Tick(float _DeltaTime)
{
	AEatItem::Tick(_DeltaTime);
}

