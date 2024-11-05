#include "PreCompile.h"
#include "StageBackground.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
AStageBackground::AStageBackground()
{
	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
		SpriteRenderer->SetSprite("background1-1.png");

		FVector2D WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
		//792.5 x 103.5 사이즈에 꽉 차야한다.;
		//SpriteRenderer->SetComponentScale({ (int)(WinSize.X*2.5),(int)WinSize.Y });
		//SpriteRenderer->SetComponentLocation({ (int)(WinSize.X) , 0 });

		FVector2D MapScale = SpriteRenderer->SetSpriteScale(2.5f);
		MapScale = MapScale * 2.5f;
		//SpriteRenderer->SetComponentLocation({ (int)(PngSize.X*2.5), 0});
		int b = 792.5 * 2.5;
		SpriteRenderer->SetComponentLocation({ (float)3962.5/2,(float)517.5/2-100 });

		int a = 0;
	}


}

AStageBackground::~AStageBackground()
{
}

