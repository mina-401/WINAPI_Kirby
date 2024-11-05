#include "PreCompile.h"
#include "Stage1_4Map.h"
#include "StageBackground.h"
#include "Player.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
AStage1_4Map::AStage1_4Map()
{
	PngSize = { (float)792.5 ,(float)103.5 };

	WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
	SpriteRenderer->SetSprite("foreground1-4.png");

	MapScale = SpriteRenderer->SetSpriteScale(2.5f);
	SpriteRenderer->SetComponentLocation(MapScale.Half());
}

AStage1_4Map::~AStage1_4Map()
{
}

void AStage1_4Map::BeginPlay()
{
	AStageBackground* BackGroundMap = GetWorld()->SpawnActor<AStageBackground>();
	
	BackGroundMap->SetActorLocation({ (float)BackGroundMap->GetActorLocation().X,(float)BackGroundMap->GetActorLocation().Y -80});
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	
	player->SetActorLocation({ 107,275 });
}

void AStage1_4Map::Tick(float _deltaTime)
{
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->BlockCameraPos(MapScale, WinSize);
}

