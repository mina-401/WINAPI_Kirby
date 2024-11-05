#include "PreCompile.h"
#include "Stage1_3Map.h"
#include "StageBackground.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
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

		MapScale = SpriteRenderer->SetSpriteScale(2.5f);
		SpriteRenderer->SetComponentLocation(MapScale.Half());
	}
}

AStage1_3Map::~AStage1_3Map()
{
}

void AStage1_3Map::BeginPlay()
{
	
	AStageBackground* BackGroundMap = GetWorld()->SpawnActor<AStageBackground>();
	//BackGroundMap->SetActorLocation({ (float)0,(float)PngSize.Y+70 });
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->SetActorLocation({ 60,663 });
}

void AStage1_3Map::Tick(float _deltaTime)
{

	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->BlockCameraPos(MapScale, WinSize);
}

