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
		player->SetCurPlayerCopyState(this->GetCopyState());
		player->SetColAnyActor(this);
		player->IsChange = true;
		SetActive(false);
	}
}
void AEatItem::BeginPlay()
{
	Super::BeginPlay();

	SetMainPawn(dynamic_cast<APlayer*>(GetWorld()->GetPawn()));

	Start = GetActorLocation();
	End = Start + FVector2D(0, 5); 
}

void AEatItem::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	CurDeltaTime += _DeltaTime;

	// Lerp 비율 계산
	float t = sinf(CurDeltaTime / LerpTime * 3.14f); // Sin 함수를 사용하여 부드러운 위아래 움직임 생성
	FVector2D NextPos = Lerp(Start, End, t);


	SetActorLocation(NextPos);
}

