#include "PreCompile.h"
#include "Stage1_1Map.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
AStage1_1Map::AStage1_1Map()
{
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
	SpriteRenderer->SetSprite("foreground1-1.png");

	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

	FVector2D MapScale = SpriteRenderer->SetSpriteScale(1.5f);
	SpriteRenderer->SetComponentLocation({(int)(Size.X*2),(int)(MapScale.Y)-24});
}

AStage1_1Map::~AStage1_1Map()
{
}

