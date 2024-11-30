#include "PreCompile.h"
#include "ItemRoomBeforeBossGameMode.h"
#include "ItemRoomBeforeBossMap.h"

#include "Player.h"
#include "EatItem.h"

#include "Stage1_1GameMode.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
#include <EnginePlatform/EngineSound.h>
#include "FireItem.h"
#include "SparkItem.h"
#include "SoundManager.h"


USoundPlayer AItemRoomBeforeBossGameMode::BGMPlayer;
AItemRoomBeforeBossGameMode::AItemRoomBeforeBossGameMode()
{
	SetName("ItemRoomBeforeBoss");

	//AEatItem* FireItem = CreateDefaultSubObject<AEatItem>();
	//int a = 0;
}

AItemRoomBeforeBossGameMode::~AItemRoomBeforeBossGameMode()
{
	BGMPlayer.Off();
}

void AItemRoomBeforeBossGameMode::BeginPlay()
{
	Super::BeginPlay();
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->SetColImage("stageBeforeBoss_col.png");
	AItemRoomBeforeBossMap* NewMap = GetWorld()->SpawnActor<AItemRoomBeforeBossMap>();

	AEatItem* NewEatItem = GetWorld()->SpawnActor<AFireItem>();
	NewEatItem->SetActorLocation({ 200.0f,190.0f });


	ASparkItem* NewSparkItem = GetWorld()->SpawnActor<ASparkItem>();
	NewSparkItem->SetActorLocation({ 450.0f,190.0f });



	{

		SoundManager& SoundManager = SoundManager::GetInst();
		USoundPlayer& BGMPlayer = SoundManager.GetSoundPlayer(); // ���۷��� ���

		if (true == BGMPlayer.IsPlaying())
		{
			BGMPlayer.Stop();
		}
		BGMPlayer = UEngineSound::Play("08. Boss Prelude.mp3");
		BGMPlayer.Loop(1);

		SoundManager.SetSoundPlayer(BGMPlayer);


	}

	////int a = 0;
	
	//BGMPlayer.Loop(1);

}

void AItemRoomBeforeBossGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown('P'))
	{
		BGMPlayer.Off();
		UEngineAPICore::GetCore()->OpenLevel("StageBossKingDedede");
	}

}