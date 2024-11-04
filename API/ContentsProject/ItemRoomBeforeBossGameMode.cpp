#include "PreCompile.h"
#include "ItemRoomBeforeBossGameMode.h"
#include "ItemRoomBeforeBossMap.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

AItemRoomBeforeBossGameMode::AItemRoomBeforeBossGameMode()
{
}

AItemRoomBeforeBossGameMode::~AItemRoomBeforeBossGameMode()
{
}

void AItemRoomBeforeBossGameMode::BeginPlay()
{
	Super::BeginPlay();
	AItemRoomBeforeBossMap* NewMap = GetWorld()->SpawnActor<AItemRoomBeforeBossMap>();

}

void AItemRoomBeforeBossGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_LBUTTON))
	{
		UEngineAPICore::GetCore()->OpenLevel("StageBossKingDedede");
	}

}