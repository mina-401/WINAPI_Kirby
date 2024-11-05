#include "PreCompile.h"
#include "Stage1_1Map.h"
#include "StageBackground.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
#include "Player.h"
AStage1_1Map::AStage1_1Map()
{
	PngSize = {(float) 792.5 ,(float)103.5 };
	WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
		SpriteRenderer->SetSprite("foreground1-1.png");

		FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

		MapScale = SpriteRenderer->SetSpriteScale(2.5f);
		SpriteRenderer->SetComponentLocation(MapScale.Half());

	
	}

}

AStage1_1Map::~AStage1_1Map()
{
}

void AStage1_1Map::BeginPlay()
{
	
	GetWorld()->GetPawn()->SetActorLocation({ 256,362 });

}

void AStage1_1Map::Tick(float _deltaTime)
{
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->BlockCameraPos(MapScale, WinSize);
}

