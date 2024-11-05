#include "PreCompile.h"
#include "StageKingDededeMap.h"
#include "Player.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
AStageKingDededeMap::AStageKingDededeMap()
{
	{
		PngSize = { (float)792.5 ,(float)103.5 };

		WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
		USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
		SpriteRenderer->SetSprite("foregroundKingDedede1-1.png");

		FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

		MapScale = SpriteRenderer->SetSpriteScale(2.35f);
		SpriteRenderer->SetComponentLocation(MapScale.Half());
	}
}

AStageKingDededeMap::~AStageKingDededeMap()
{
}

void AStageKingDededeMap::BeginPlay()
{
	APlayer* player = GetWorld()->GetPawn<APlayer>();

	player->SetActorLocation({ 107,340 });
}

void AStageKingDededeMap::Tick(float _deltaTime)
{
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->BlockCameraPos(MapScale, WinSize);

	FVector2D CamPos = GetWorld()->GetCameraPos();
	GetWorld()->SetCameraPos({ CamPos.X,CamPos.Y+70 });
}