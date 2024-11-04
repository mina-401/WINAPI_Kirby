#include "PreCompile.h"
#include "StageBossKingDededeGameMode.h"
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

	//AStage1_1Map* NewActor = GetWorld()->SpawnActor<AStage1_1Map>();
}

void AStageBossKingDededeGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_LBUTTON))
	{
		//UEngineAPICore::GetCore()->OpenLevel("Stage1_2");
	}

}
