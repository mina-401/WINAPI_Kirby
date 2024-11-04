#include "PreCompile.h"
#include "Stage1_4Map.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
AStage1_4Map::AStage1_4Map()
{
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
	SpriteRenderer->SetSprite("foreground1-4.png");

	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();


	FVector2D MapScale = SpriteRenderer->SetSpriteScale(2.5f);
	SpriteRenderer->SetComponentLocation({ (int)(Size.X * 3.2), (int)(Size.Y / 2)+50 });
}

AStage1_4Map::~AStage1_4Map()
{
}

