#include "PreCompile.h"
#include "Stage1_3Map.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
AStage1_3Map::AStage1_3Map()
{
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
	SpriteRenderer->SetSprite("foreground1-3.png");

	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();


	FVector2D MapScale = SpriteRenderer->SetSpriteScale(2.5f);
	//SpriteRenderer->SetComponentLocation({ (int)(Size.X * 3.2) - 100, (int)(Size.Y / 2) });
	SpriteRenderer->SetComponentLocation({ (int)(Size.X/2)+45,75 });


}

AStage1_3Map::~AStage1_3Map()
{
}

