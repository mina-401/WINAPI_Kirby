#include "PreCompile.h"
#include "Stage1_3GameMode.h"
#include "Stage1_3Map.h"
#include "StageBackground.h"
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
	
	AStage1_3Map* NewMap = GetWorld()->SpawnActor<AStage1_3Map>();
	// ���� ī�޶� ��ġ �̵�
}

void AStage1_3GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown('P'))
	{
		UEngineAPICore::GetCore()->OpenLevel("Stage1_4");
	}

}

