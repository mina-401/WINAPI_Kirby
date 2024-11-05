#include "PreCompile.h"
#include "Stage1_2Map.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
#include "Player.h"
AStage1_2Map::AStage1_2Map()
{

	PngSize = { (float)728 ,(float)104 };
	WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
	SpriteRenderer->SetSprite("foreground1-2.png");

	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();


	MapScale = SpriteRenderer->SetSpriteScale(2.5f);
	SpriteRenderer->SetComponentLocation(MapScale.Half());
}

AStage1_2Map::~AStage1_2Map()
{
}

void AStage1_2Map::BeginPlay()
{
	GetWorld()->GetPawn()->SetActorLocation({ 85,366 });
}

void AStage1_2Map::Tick(float _deltaTime)
{
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->BlockCameraPos(MapScale, WinSize);
}

