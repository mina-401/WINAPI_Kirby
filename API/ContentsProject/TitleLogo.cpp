#include "PreCompile.h"
#include "TitleLogo.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
TitleLogo::TitleLogo()
{
	USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
	SpriteRenderer->SetSprite("Title.png");

	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	SpriteRenderer->SetComponentScale(Size * 0.7);

	SpriteRenderer->SetComponentLocation(Size.Half());
}

TitleLogo::~TitleLogo()
{
}

