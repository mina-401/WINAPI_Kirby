#include "PreCompile.h"
#include "Player.h"
#include "StageBossKingDededeGameMode.h"
#include "StageKingDededeMap.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
#include "KingDedede.h"
AStageBossKingDededeGameMode::AStageBossKingDededeGameMode()
{
	SetName("StageBossKingDedede");

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

	AKingDedede* NewBoss= GetWorld()->SpawnActor<AKingDedede>();
	NewBoss->SetColImage("foregroundKingDedede1-1_col.png");
	NewBoss->SetActorLocation({ 400,365 });
}

void AStageBossKingDededeGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown('O'))
	{
		
		APlayer* player = GetWorld()->GetPawn<APlayer>();

		

		
	}

	if (true == UEngineInput::GetInst().IsDown('P'))
	{
		//UEngineAPICore::GetCore()->OpenLevel("Stage1_2");
	}

}
