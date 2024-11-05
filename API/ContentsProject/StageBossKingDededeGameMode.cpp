#include "PreCompile.h"
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
