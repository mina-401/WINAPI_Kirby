#include "PreCompile.h"
//#include "HPItem.h"
//
//#include "Player.h"
//#include <EngineCore/SpriteRenderer.h>
//#include <EngineCore/ImageManager.h>
//#include <EngineCore/2DCollision.h>
//#include "ContentsEnum.h"
//
//HPItem::HPItem()
//{
//	SetName("Item");
//
//
//
//	{
//		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
//		CollisionComponent->SetComponentLocation({ 0, 0 });
//		CollisionComponent->SetComponentScale({ 50, 50 });
//		CollisionComponent->SetCollisionGroup(ECollisionGroup::Block);
//		CollisionComponent->SetCollisionType(ECollisionType::CirCle);
//
//		CollisionComponent->SetCollisionEnter(std::bind(&HPItem::CollisionEnter, this, std::placeholders::_1));
//
//		DebugOn();
//	}
//}
//
//HPItem::~AEatItem()
//{
//}
//void HPItem::CollisionEnter(AActor* _ColActor)
//{
//	APlayer* player = dynamic_cast<APlayer*>(_ColActor);
//	if (nullptr != player)
//	{
//		//player->SetCurPlayerCopyState(this->GetCopyState());
//		//player->SetColAnyActor(this);
//
//		SetActive(false);
//	}
//}
//void HPItem::BeginPlay()
//{
//	Super::BeginPlay();
//
//}
//
//void HPItem::Tick(float _DeltaTime)
//{
//	Super::Tick(_DeltaTime);
//
//
//}
//
