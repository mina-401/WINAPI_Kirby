#include "PreCompile.h"
#include "ItemRoomBeforeBossGameMode.h"

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
}

void AItemRoomBeforeBossGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_LBUTTON))
	{
		//UEngineAPICore::GetCore()->OpenLevel("ItemRoomBeforeBossGameMode");
	}

}