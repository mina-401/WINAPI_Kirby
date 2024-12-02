#include "PreCompile.h"
#include "Stage1_4Map.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"
#include "StageBackground.h"
#include "Player.h"
#include "Stage1_4GameMode.h"
AStage1_4Map::AStage1_4Map()
{
	PngSize = { (float)792.5 ,(float)103.5 };

	WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
		SpriteRenderer->SetSprite("foreground1-4.png");

		MapScale = SpriteRenderer->SetSpriteScale(1.0f);
		SpriteRenderer->SetComponentLocation(MapScale.Half());
	}
	
	{
		
			ColSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
			ColSpriteRenderer->SetOrder(ERenderOrder::COLMAP);
			ColSpriteRenderer->SetSprite("foreground1-4_col.png");

			FVector2D MapScale = ColSpriteRenderer->SetSpriteScale(1.0f);
			ColSpriteRenderer->SetComponentLocation(MapScale.Half());
		
	}
	{
		GetWorld()->CollisionGroupLink(ECollisionGroup::Potal, ECollisionGroup::PlayerBody);


		PotalColComponent = CreateDefaultSubObject<U2DCollision>();
		PotalColComponent->SetComponentLocation({ (float)MapScale.X - 90,(float)50 });
		PotalColComponent->SetComponentScale({ 20, 40 });
		PotalColComponent->SetCollisionGroup(ECollisionGroup::Potal);
		PotalColComponent->SetCollisionType(ECollisionType::CirCle);

		PotalColComponent->SetCollisionEnter(std::bind(&AStage1_4Map::CollisionEnter, this, std::placeholders::_1));
		PotalColComponent->SetCollisionStay(std::bind(&AStage1_4Map::CollisionStay, this, std::placeholders::_1));
		PotalColComponent->SetCollisionEnd(std::bind(&AStage1_4Map::CollisionEnd, this, std::placeholders::_1));
		DebugOn();
	}
}

AStage1_4Map::~AStage1_4Map()
{
}

void AStage1_4Map::BeginPlay()
{
	Super::BeginPlay();
	AStageBackground* BackGroundMap = GetWorld()->SpawnActor<AStageBackground>();
	
	BackGroundMap->SetActorLocation({ (float)BackGroundMap->GetActorLocation().X,(float)BackGroundMap->GetActorLocation().Y -80});
	APlayer* player = GetWorld()->GetPawn<APlayer>();

	player->SetActorLocation({ 100,200 });
}

void AStage1_4Map::Tick(float _deltaTime)
{
	Super::Tick(_deltaTime);
	if (true == UEngineInput::GetInst().IsPress(VK_UP) && IsPlayerStayPotal) {

		
		USoundPlayer EffectSound;
		EffectSound = UEngineSound::Play("Potal travel.WAV");
		UEngineAPICore::GetCore()->ResetLevel<AStage1_4GameMode, APlayer>("Stage1_4");
		UEngineAPICore::GetCore()->OpenLevel("ItemRoomBeforeBoss");
		//UEngineAPICore::GetCore()->OpenLevel("ItemRoomBeforeBoss");
	}
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->BlockCameraPos(MapScale, WinSize);
}
void AStage1_4Map::CollisionEnter(AActor* _ColActor)
{
	//IsPlayerStayPotal = true;
}

void AStage1_4Map::CollisionStay(AActor* _ColActor)
{

	APlayer* Player = dynamic_cast<APlayer*>(_ColActor);
	IsPlayerStayPotal = true;
}

void AStage1_4Map::CollisionEnd(AActor* _ColActor)
{
	IsPlayerStayPotal = false;
}
