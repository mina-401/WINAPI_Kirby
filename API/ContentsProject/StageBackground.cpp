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

		FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
		//792.5 x 103.5 사이즈에 꽉 차야한다.;
		SpriteRenderer->SetComponentScale({ (int)(Size.X*2.5),(int)Size.Y });
		SpriteRenderer->SetComponentLocation({ (int)(Size.X) , (int)Size.Y / 2 });


	}


}

AStageBackground::~AStageBackground()
{
}

