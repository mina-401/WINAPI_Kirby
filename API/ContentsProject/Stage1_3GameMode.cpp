#include "PreCompile.h"
#include "Stage1_3GameMode.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
AStage1_3GameMode::AStage1_3GameMode()
{
}

AStage1_3GameMode::~AStage1_3GameMode()
{
}
void AStage1_3GameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AStage1_3GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_LBUTTON))
	{
		//UEngineAPICore::GetCore()->OpenLevel("Stage1_4");
	}

}

