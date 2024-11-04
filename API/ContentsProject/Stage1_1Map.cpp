#include "PreCompile.h"
#include "Stage1_1Map.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
AStage1_1Map::AStage1_1Map()
{
	{
		USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
		SpriteRenderer->SetSprite("background1-1.png");

		FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
		//792.5 x 103.5 사이즈에 꽉 차야한다.
		//FVector2D MapScale = SpriteRenderer->SetSpriteScale(1.5f);
		SpriteRenderer->SetComponentScale({ 792,(int)Size.Y});
		//SpriteRenderer->SetComponentLocation({ (int)(Size.X * 3.2), (int)(Size.Y / 2) });
		SpriteRenderer->SetComponentLocation({ (int)(Size.X)/2, (int)Size.Y/2 });


	}
	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
		SpriteRenderer->SetSprite("foreground1-1.png");

		FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

		FVector2D MapScale = SpriteRenderer->SetSpriteScale(2.5f);
		SpriteRenderer->SetComponentLocation({ (int)(Size.X * 3.2), (int)(Size.Y / 2) });
	}

}

AStage1_1Map::~AStage1_1Map()
{
}

