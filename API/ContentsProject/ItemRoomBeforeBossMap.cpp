#include "PreCompile.h"
#include "ItemRoomBeforeBossMap.h"
#include "Player.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
AItemRoomBeforeBossMap::AItemRoomBeforeBossMap()
{
	
	
		PngSize = { (float)792.5 ,(float)103.5 };

		WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
		USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
		SpriteRenderer->SetSprite("stageBeforeBoss.png");


		MapScale = SpriteRenderer->SetSpriteScale(2.1f);
		SpriteRenderer->SetComponentLocation(MapScale.Half());
	
	
}

AItemRoomBeforeBossMap::~AItemRoomBeforeBossMap()
{
}

void AItemRoomBeforeBossMap::BeginPlay()
{
	APlayer* player = GetWorld()->GetPawn<APlayer>();

	player->SetActorLocation({ 107,337 });
}

void AItemRoomBeforeBossMap::Tick(float _deltaTime)
{
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->BlockCameraPos(MapScale, WinSize);
}

