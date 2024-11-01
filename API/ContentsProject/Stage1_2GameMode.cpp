#include "PreCompile.h"
#include "Stage1_2GameMode.h"
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
}

void AStage1_2GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_LBUTTON))
	{
		//UEngineAPICore::GetCore()->OpenLevel("Stage1_3");
	}

}
