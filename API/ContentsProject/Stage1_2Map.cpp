#include "PreCompile.h"
#include "Stage1_2Map.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
#include "Player.h"
AStage1_2Map::AStage1_2Map()
{

	WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
		SpriteRenderer->SetSprite("foreground1-2.png");

		MapScale = SpriteRenderer->SetSpriteScale(1.0f);
		SpriteRenderer->SetComponentLocation(MapScale.Half());
	}
	{
		ColSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		ColSpriteRenderer->SetOrder(ERenderOrder::COLMAP);
		ColSpriteRenderer->SetSprite("foreground1-2_col.png");

		FVector2D MapScale = ColSpriteRenderer->SetSpriteScale(1.0f);
		ColSpriteRenderer->SetComponentLocation(MapScale.Half());
	}
}

AStage1_2Map::~AStage1_2Map()
{
}

void AStage1_2Map::BeginPlay()
{
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->SetActorLocation({ 85,350 });

}

void AStage1_2Map::Tick(float _deltaTime)
{
	
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->BlockCameraPos(MapScale, WinSize);
}

