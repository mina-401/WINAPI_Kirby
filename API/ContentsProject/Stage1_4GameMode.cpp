#include "PreCompile.h"
#include "Stage1_4GameMode.h"
#include "Stage1_4Map.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
AStage1_4GameMode::AStage1_4GameMode()
{
}

AStage1_4GameMode::~AStage1_4GameMode()
{
}

void AStage1_4GameMode::BeginPlay()
{
	Super::BeginPlay();


	AStage1_4Map* NewMap = GetWorld()->SpawnActor<AStage1_4Map>();

}

void AStage1_4GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_LBUTTON))
	{
		//UEngineAPICore::GetCore()->OpenLevel("Stage1_5");
	}

}