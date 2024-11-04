#include "PreCompile.h"
#include "StageKingDededeMap.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
AStageKingDededeMap::AStageKingDededeMap()
{
	{
		USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
		SpriteRenderer->SetSprite("foregroundKingDedede1-1.png");

		FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

		FVector2D MapScale = SpriteRenderer->SetSpriteScale(2.3f);
		SpriteRenderer->SetComponentLocation({ (int)Size.X / 2+1,(int)Size.Y / 2 });
	}
}

AStageKingDededeMap::~AStageKingDededeMap()
{
}

