#include "PreCompile.h"
#include "Stage1_4GameMode.h"
#include "Stage1_4Map.h"
#include "Player.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
AStage1_4GameMode::AStage1_4GameMode()
{
	SetName("Stage1_4");

}

AStage1_4GameMode::~AStage1_4GameMode()
{
}

void AStage1_4GameMode::BeginPlay()
{
	Super::BeginPlay();

	
	AStage1_4Map* NewMap = GetWorld()->SpawnActor<AStage1_4Map>();
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->SetColImage("foreground1-4_col.png");

}

void AStage1_4GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown('P'))
	{
		UEngineAPICore::GetCore()->OpenLevel("ItemRoomBeforeBoss");
	}

}