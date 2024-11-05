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

		FVector2D MapScale = SpriteRenderer->SetSpriteScale(3.0f);
		SpriteRenderer->SetComponentLocation(MapScale.Half());
		SpriteRenderer->SetCameraEffect(TRUE);
		SpriteRenderer->SetCameraEffectScale(0.2f);
	}


}

AStageBackground::~AStageBackground()
{
}

void AStageBackground::BeginPlay()
{
	//SetActorLocation({ 0,-70 });
}

