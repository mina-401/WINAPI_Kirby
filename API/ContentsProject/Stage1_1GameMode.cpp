#include "PreCompile.h"
#include "Stage1_1GameMode.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "Stage1_1Map.h"
AStage1_1GameMode::AStage1_1GameMode()
{
}

AStage1_1GameMode::~AStage1_1GameMode()
{
}
void AStage1_1GameMode::BeginPlay()
{
	Super::BeginPlay();

	AStage1_1Map* NewActor = GetWorld()->SpawnActor<AStage1_1Map>();
}

void AStage1_1GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_LBUTTON))
	{
		UEngineAPICore::GetCore()->OpenLevel("Stage1_2");
	}

}

