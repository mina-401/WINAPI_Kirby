#include "PreCompile.h"
#include "Stage1_1Map.h"
#include "StageBackground.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
AStage1_1Map::AStage1_1Map()
{
	PngSize = {(float) 792.5 ,(float)103.5 };
	WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
		SpriteRenderer->SetSprite("foreground1-1.png");

		FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

		MapScale = SpriteRenderer->SetSpriteScale(2.5f);
		//MapScale = MapScale * 2.5f;
		//SpriteRenderer->SetComponentLocation({ (int)(PngSize.X*2.5), 0});
		SpriteRenderer->SetComponentLocation(MapScale.Half());

		int a = 0;
	}

}

AStage1_1Map::~AStage1_1Map()
{
}

void AStage1_1Map::BeginPlay()
{
	AStageBackground* NewActor = GetWorld()->SpawnActor<AStageBackground>();

	//GetWorld()->SetCameraPivot

}

void AStage1_1Map::Tick(float _deltaTime)
{

	FVector2D CamPos = GetWorld()->GetCameraPos();

	if (MapScale.X-WinSize.X < CamPos.X)
	{
		CamPos.X = MapScale.X - WinSize.X;
	}
	GetWorld()->SetCameraPos(CamPos);
}

