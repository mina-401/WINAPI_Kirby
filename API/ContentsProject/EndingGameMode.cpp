#include "PreCompile.h"
#include "EndingGameMode.h"
#include <EnginePlatform/EngineInput.h>
#include <EnginePlatform/EngineSound.h>
#include <EngineCore/EngineAPICore.h>
#include "DanceKirby.h"
#include "EndingMap.h"

AEndingGameMode::AEndingGameMode()
{
}

AEndingGameMode::~AEndingGameMode()
{
}
//ending_background_map

void AEndingGameMode::BeginPlay()
{
	Super::BeginPlay();

	{
		BGMPlayer = UEngineSound::Play("05. Victory Star.mp3");

	}
	ADanceKirby* player = GetWorld()->GetPawn<ADanceKirby>();
	player->SetActorLocation({ 150,150 });

//	player->SetColImage("foregroundKingDedede1-1_col.png");
	AEndingMap* NewActor = GetWorld()->SpawnActor<AEndingMap>();

}

void AEndingGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		BGMPlayer.Off();
		UEngineAPICore::GetCore()->OpenLevel("Title");
	}

}