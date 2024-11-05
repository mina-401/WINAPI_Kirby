#include "PreCompile.h"
#include "Stage1_2GameMode.h"
#include "StageBackground.h"
#include "Stage1_2Map.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>


AStage1_2GameMode::AStage1_2GameMode()
{
}

AStage1_2GameMode::~AStage1_2GameMode()
{
}

void AStage1_2GameMode::BeginPlay()
{
	Super::BeginPlay();
	AStageBackground* NewActor = GetWorld()->SpawnActor<AStageBackground>();

	AStage1_2Map* NewMap = GetWorld()->SpawnActor<AStage1_2Map>();
}

void AStage1_2GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown('P'))
	{
		UEngineAPICore::GetCore()->OpenLevel("Stage1_3");
	}

}
