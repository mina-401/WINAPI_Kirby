#include "PreCompile.h"
#include "SparkItem.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>

ASparkItem::ASparkItem()
{

	{
		//UImageManager::GetInst().CuttingSprite("Item_FireCopy.png", { 60, 59 });
		UImageManager::GetInst().CuttingSprite("Item_SparkCopy.png", { 60, 59 });

		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();

		SpriteRenderer->SetSprite("Item_SparkCopy.png");
		SpriteRenderer->SetComponentScale({ 60, 60 });

		SpriteRenderer->SetOrder(ERenderOrder::MONSTER);


	}

	SetName("SparkItem");
}

ASparkItem::~ASparkItem()
{
}

void ASparkItem::BeginPlay()
{

	AEatItem::BeginPlay();
	SetCopyState(ECopyAbilityState::Spark);

}

void ASparkItem::Tick(float _DeltaTime)
{
	AEatItem::Tick(_DeltaTime);
}
