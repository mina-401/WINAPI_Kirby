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

		MapScale = SpriteRenderer->SetSpriteScale(1.f);
		SpriteRenderer->SetComponentLocation(MapScale.Half());
	} {

		ColSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		ColSpriteRenderer->SetOrder(ERenderOrder::COLMAP);
		ColSpriteRenderer->SetSprite("foregroundKingDedede1-1_col.png");

		FVector2D MapScale = ColSpriteRenderer->SetSpriteScale(1.0f);
		ColSpriteRenderer->SetComponentLocation(MapScale.Half());

	}
}

AStageKingDededeMap::~AStageKingDededeMap()
{
}

void AStageKingDededeMap::BeginPlay()
{
	APlayer* player = GetWorld()->GetPawn<APlayer>();


	player->SetActorLocation({ 10,300 });
}

void AStageKingDededeMap::Tick(float _deltaTime)
{
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->BlockCameraPos(MapScale, WinSize);
	FVector2D  CurCameraPos = GetWorld()->GetCameraPos();
	//GetWorld()->SetCameraPos({ CurCameraPos.X,CurCameraPos.Y + 70 });
}