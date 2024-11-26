#include "PreCompile.h"

#include "EatItem.h"
#include "Player.h"
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

	}


	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, 0 });
		CollisionComponent->SetComponentScale({ 50, 50 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::Block);
		CollisionComponent->SetCollisionType(ECollisionType::CirCle);

		CollisionComponent->SetCollisionEnter(std::bind(&AEatItem::CollisionEnter, this, std::placeholders::_1));

		DebugOn();
	}
}

AEatItem::~AEatItem()
{
}
void AEatItem::CollisionEnter(AActor* _ColActor)
{
	APlayer* player = dynamic_cast<APlayer*>(_ColActor);
	if (nullptr != player)
	{
		player->SetCurPlayerCopyState(ECopyAbilityState::Fire);
		
		SetActive(false);
	}
}
void AEatItem::BeginPlay()
{
	Super::BeginPlay();

	SetMainPawn(dynamic_cast<APlayer*>(GetWorld()->GetPawn()));

	Start = GetActorLocation();
	End = Start + FVector2D(0, 5); // 위로 20만큼 이동
}

void AEatItem::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	CurDeltaTime += _DeltaTime;

	// Lerp 비율 계산
	float t = sinf(CurDeltaTime / LerpTime * 3.14); // Sin 함수를 사용하여 부드러운 위아래 움직임 생성
	FVector2D NextPos = Lerp(Start, End, t);


	SetActorLocation(NextPos);
}

