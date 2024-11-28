#include "PreCompile.h"
#include "Stage1_2GameMode.h"
#include "StageBackground.h"
#include "Stage1_2Map.h"
#include "Player.h"
#include "HotHead.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
#include <EnginePlatform/EngineSound.h>

AStage1_2GameMode::AStage1_2GameMode()
{
	SetName("Stage1_2");
}

AStage1_2GameMode::~AStage1_2GameMode()
{
}

void AStage1_2GameMode::BeginPlay()
{
	//DebugOn();
	Super::BeginPlay();
	AStageBackground* NewActor = GetWorld()->SpawnActor<AStageBackground>();

	AStage1_2Map* NewMap = GetWorld()->SpawnActor<AStage1_2Map>();
	APlayer* Player = GetWorld()->GetPawn<APlayer>();
	Player->SetColImage("foreground1-2_col.png");


	MonsterHotHead = GetWorld()->SpawnActor<AHotHead>();

	MonsterHotHead->SetActorLocation({ 500, 100 });

	MonsterHotHead->SetColImage("foreground1-1_col.png");

	{
		//BGMPlayLevelPrismPlayer = UEngineSound::Play("04. Prism Plains.mp3");
		//BGMPlayLevelPrismPlayer.Loop(1);

		//BGMPlayer = UEngineSound::Play("05. Victory Star.mp3");

	}
}

void AStage1_2GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown('P'))
	{
		UEngineAPICore::GetCore()->OpenLevel("Stage1_3");
	}

}
