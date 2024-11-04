#include "PreCompile.h"
#include "ItemRoomBeforeBossMap.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
AItemRoomBeforeBossMap::AItemRoomBeforeBossMap()
{
	{
		USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
		SpriteRenderer->SetSprite("stageBeforeBoss.png");
	


		FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

		FVector2D MapScale = SpriteRenderer->SetSpriteScale(2.55f);
		SpriteRenderer->SetComponentLocation({ (int)Size.X/2,(int)Size.Y/2});
	}
}

AItemRoomBeforeBossMap::~AItemRoomBeforeBossMap()
{
}

