#include "PreCompile.h"
#include "ItemRoomBeforeBossGameMode.h"
#include "ItemRoomBeforeBossMap.h"

#include "Player.h"
#include "EatItem.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
#include <EnginePlatform/EngineSound.h>
#include "FireItem.h"
#include "SparkItem.h"

AItemRoomBeforeBossGameMode::AItemRoomBeforeBossGameMode()
{
	SetName("ItemRoomBeforeBoss");

	//AEatItem* FireItem = CreateDefaultSubObject<AEatItem>();
	//int a = 0;
}

AItemRoomBeforeBossGameMode::~AItemRoomBeforeBossGameMode()
{
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


	//UEngineSound::AllSoundOff();
	
	int a = 0;
	BGMPlayer = UEngineSound::Play("08. Boss Prelude.mp3");
	BGMPlayer.Loop(1);

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