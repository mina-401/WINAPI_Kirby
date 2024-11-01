#include "PreCompile.h"
#include "Stage1_1Map.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
AStage1_1Map::AStage1_1Map()
{
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
	SpriteRenderer->SetSprite("foreground1-1.png");

	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	//SpriteRenderer->SetComponentScale(Size);
	//SpriteRenderer->SetComponentLocation(Size.Half());

	FVector2D MapScale = SpriteRenderer->SetSpriteScale(1.5f);

	FVector2D PlayerPos = Size - MapScale.Half();


	//SpriteRenderer->SetComponentLocation({ 590, 440 });
	SpriteRenderer->SetComponentLocation(PlayerPos);
}

AStage1_1Map::~AStage1_1Map()
{
}

