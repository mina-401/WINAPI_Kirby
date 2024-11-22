#include "PreCompile.h"
#include "Stage1_3GameMode.h"
#include "Stage1_3Map.h"
#include "Player.h"
#include "StageBackground.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
AStage1_3GameMode::AStage1_3GameMode()
{
	SetName("Stage1_3");
}

AStage1_3GameMode::~AStage1_3GameMode()
{
}
void AStage1_3GameMode::BeginPlay()
{
	Super::BeginPlay();
	
	AStage1_3Map* NewMap = GetWorld()->SpawnActor<AStage1_3Map>();

	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->SetColImage("foreground1-3_col.png");
	// 레벨 카메라 위치 이동
}

void AStage1_3GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown('P'))
	{
		UEngineAPICore::GetCore()->OpenLevel("ItemRoomBeforeBoss");
	}

}

