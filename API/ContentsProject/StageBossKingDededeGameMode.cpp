#include "PreCompile.h"
#include "Player.h"
#include "StageBossKingDededeGameMode.h"
#include "StageKingDededeMap.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
AStageBossKingDededeGameMode::AStageBossKingDededeGameMode()
{
}

AStageBossKingDededeGameMode::~AStageBossKingDededeGameMode()
{
}

void AStageBossKingDededeGameMode::BeginPlay()
{
	Super::BeginPlay();
	APlayer* player = GetWorld()->GetPawn<APlayer>();

	player->SetColImage("foregroundKingDedede1-1_col.png");
	AStageKingDededeMap* NewActor = GetWorld()->SpawnActor<AStageKingDededeMap>();
}

void AStageBossKingDededeGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown('P'))
	{
		//UEngineAPICore::GetCore()->OpenLevel("Stage1_2");
	}

}
