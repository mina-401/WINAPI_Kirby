#include "PreCompile.h"
#include "Stage1_3Map.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"
#include "StageBackground.h"
#include "Player.h"

AStage1_3Map::AStage1_3Map()
{
	PngSize = { (float)136 ,(float)164.5 };
	WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
		SpriteRenderer->SetSprite("foreground1-3.png");

		FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

		MapScale = SpriteRenderer->SetSpriteScale(1.0f);
		SpriteRenderer->SetComponentLocation(MapScale.Half());
	}
	{
		ColSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		ColSpriteRenderer->SetOrder(ERenderOrder::COLMAP);
		ColSpriteRenderer->SetSprite("foreground1-3_col.png");

		FVector2D MapScale = ColSpriteRenderer->SetSpriteScale(1.0f);
		ColSpriteRenderer->SetComponentLocation(MapScale.Half());
	} 
	{
		GetWorld()->CollisionGroupLink(ECollisionGroup::Potal, ECollisionGroup::PlayerBody);


		PotalColComponent = CreateDefaultSubObject<U2DCollision>();
		PotalColComponent->SetComponentLocation({ (float)MapScale.X - 100,(float)50});
		PotalColComponent->SetComponentScale({ 20, 40 });
		PotalColComponent->SetCollisionGroup(ECollisionGroup::Potal);
		PotalColComponent->SetCollisionType(ECollisionType::CirCle);

		PotalColComponent->SetCollisionEnter(std::bind(&AStage1_3Map::CollisionEnter, this, std::placeholders::_1));
		PotalColComponent->SetCollisionStay(std::bind(&AStage1_3Map::CollisionStay, this, std::placeholders::_1));
		PotalColComponent->SetCollisionEnd(std::bind(&AStage1_3Map::CollisionEnd, this, std::placeholders::_1));
		DebugOn();
	}
}

AStage1_3Map::~AStage1_3Map()
{
}
void AStage1_3Map::CollisionEnter(AActor* _ColActor)
{
	//IsPlayerStayPotal = true;
}

void AStage1_3Map::CollisionStay(AActor* _ColActor)
{

	APlayer* Player = dynamic_cast<APlayer*>(_ColActor);
	IsPlayerStayPotal = true;
}

void AStage1_3Map::CollisionEnd(AActor* _ColActor)
{
	IsPlayerStayPotal = false;
}
void AStage1_3Map::BeginPlay()
{
	Super::BeginPlay();
	AStageBackground* BackGroundMap = GetWorld()->SpawnActor<AStageBackground>();

	BackGroundMap->SetActorLocation({ (float)BackGroundMap->GetActorLocation().X,(float)BackGroundMap->GetActorLocation().Y  });
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->SetActorLocation({ 60,500 });
}

void AStage1_3Map::Tick(float _deltaTime)
{
	Super::Tick(_deltaTime);
	if (true == UEngineInput::GetInst().IsPress(VK_UP) && IsPlayerStayPotal) {
		UEngineAPICore::GetCore()->OpenLevel("Stage1_4");
	}
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->BlockCameraPos(MapScale, WinSize);
}

