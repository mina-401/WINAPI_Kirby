#include "PreCompile.h"
#include "PlayMap.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"

APlayMap::APlayMap()
{
	// 매번 윈도우 사이즈가 바뀌면
	// 이거 자체도 사실 좋은건 아닙니다.
	{

		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
		SpriteRenderer->SetSprite("foreground1-1.png");

		FVector2D Size= UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
		//SpriteRenderer->SetComponentScale(Size);
		//SpriteRenderer->SetComponentLocation(Size.Half());

		FVector2D MapScale = SpriteRenderer->SetSpriteScale(1.5f);

		//FVector2D PlayerPos = Size - MapScale.Half();


		SpriteRenderer->SetComponentLocation({0.f,0.0f });
		//FTransform tfrom= SpriteRenderer->Sprite->GetSpriteData().Transform;


		/*{
			USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
			SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
			SpriteRenderer->SetSprite("bg-1-1.png");

			FVector2D MapScale = SpriteRenderer->SetSpriteScale(1.0f);
			SpriteRenderer->SetComponentLocation(MapScale.Half());
		}*/


		int a = 0;
	}
}

APlayMap::~APlayMap()
{
}

