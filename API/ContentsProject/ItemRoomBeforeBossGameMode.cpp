#include "PreCompile.h"
#include "ItemRoomBeforeBossGameMode.h"
#include "ItemRoomBeforeBossMap.h"
#include "Player.h"
#include "EatItem.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

AItemRoomBeforeBossGameMode::AItemRoomBeforeBossGameMode()
{
	SetName("ItemRoomBeforeBoss");
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

	AEatItem* NewEatItem = GetWorld()->SpawnActor<AEatItem>();
	NewEatItem->SetActorLocation({200.0f,190.0f});

}

void AItemRoomBeforeBossGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown('P'))
	{
		UEngineAPICore::GetCore()->OpenLevel("StageBossKingDedede");
	}

}