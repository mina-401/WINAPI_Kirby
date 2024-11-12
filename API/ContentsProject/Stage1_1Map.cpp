#include "PreCompile.h"
#include "ContentsEnum.h"
#include "Player.h"
#include "Stage1_1Map.h"
#include "StageBackground.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include "Stage1_1GameMode.h"
#include "Monster.h"
#include "WaddleDee.h"
AStage1_1Map::AStage1_1Map()
{
	PngSize = {(float) 792.5 ,(float)103.5 };
	WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
		SpriteRenderer->SetSprite("foreground1-1.png");

		FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

		MapScale = SpriteRenderer->SetSpriteScale(1.0f);
		SpriteRenderer->SetComponentLocation(MapScale.Half());
	}
	{
		ColSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		ColSpriteRenderer->SetOrder(ERenderOrder::COLMAP);
		ColSpriteRenderer->SetSprite("foreground1-1_col.png");

		FVector2D MapScale = ColSpriteRenderer->SetSpriteScale(1.0f);
		ColSpriteRenderer->SetComponentLocation(MapScale.Half());
	}
}

AStage1_1Map::~AStage1_1Map()
{
}

void AStage1_1Map::BeginPlay()
{
	
	GetWorld()->GetPawn()->SetActorLocation({ 256,300 });

}

void AStage1_1Map::Tick(float _deltaTime)
{
	Super::Tick(_deltaTime);

	if (true == UEngineInput::GetInst().IsDown('Y'))
	{
		ColSpriteRenderer->SetActiveSwitch();
	}
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->BlockCameraPos(MapScale, WinSize);

	AStage1_1GameMode* GameMode = GetWorld()->GetGameMode<AStage1_1GameMode>();
	AMonster* Dee = GameMode->MonsterWaddleDee;
	//AMonster* Doo = GameMode->MonsterWaddleDoo;
	//AMonster* Sparky = GameMode->MonsterSparky;
	Dee->BlockMonsterPos(MapScale);
	//Doo->BlockMonsterPos(MapScale);
	//Sparky->BlockMonsterPos(MapScale);
}

