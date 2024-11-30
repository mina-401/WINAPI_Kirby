#include "PreCompile.h"
#include "Player.h"
#include "StageBossKingDededeGameMode.h"
#include "StageKingDededeMap.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
#include "KingDedede.h"
#include "ItemRoomBeforeBossGameMode.h"
#include "Stage1_1GameMode.h"
#include "SoundManager.h"
AStageBossKingDededeGameMode::AStageBossKingDededeGameMode()
{
	SetName("StageBossKingDedede");

}

AStageBossKingDededeGameMode::~AStageBossKingDededeGameMode()
{
}

void AStageBossKingDededeGameMode::BeginPlay()
{
	Super::BeginPlay();
	APlayer* player = GetWorld()->GetPawn<APlayer>();

	player->SetColImage("foregroundKingDedede1-1_col.png");
	AStageKingDededeMap* NewActor = GetWorld()->SpawnActor<AStageKingDededeMap>();

	AKingDedede* NewBoss= GetWorld()->SpawnActor<AKingDedede>();
	NewBoss->SetColImage("foregroundKingDedede1-1_col.png");
	NewBoss->SetActorLocation({ 400,365 });

	{

		SoundManager& SoundManager = SoundManager::GetInst();
		USoundPlayer& BGMPlayer = SoundManager.GetSoundPlayer(); // ���۷��� ���

		if (true == BGMPlayer.IsPlaying())
		{
			BGMPlayer.Stop();
		}
		BGMPlayer = UEngineSound::Play("09. King Dedede.mp3");
		BGMPlayer.Loop(1);

		SoundManager.SetSoundPlayer(BGMPlayer);


	}


}

void AStageBossKingDededeGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


	if (true == UEngineInput::GetInst().IsDown('P'))
	{
		UEngineAPICore::GetCore()->OpenLevel("Stage_DanceEnding");
	}

}

void AStageBossKingDededeGameMode::PlayerEndingCutStage()
{
	{

		SoundManager& SoundManager = SoundManager::GetInst();
		USoundPlayer& BGMPlayer = SoundManager.GetSoundPlayer(); // ���۷��� ���

		if (true == BGMPlayer.IsPlaying())
		{
			BGMPlayer.Stop();
		}

		SoundManager.SetSoundPlayer(BGMPlayer);


	}
}
