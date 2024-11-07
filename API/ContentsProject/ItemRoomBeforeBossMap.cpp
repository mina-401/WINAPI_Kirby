#include "PreCompile.h"
#include "ItemRoomBeforeBossMap.h"
#include "Player.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
AItemRoomBeforeBossMap::AItemRoomBeforeBossMap()
{
	
	
		WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
		USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
		SpriteRenderer->SetSprite("stageBeforeBoss.png");
		

		MapScale = SpriteRenderer->SetSpriteScale(1.0f);
		SpriteRenderer->SetComponentLocation(MapScale.Half());
	
		{

			ColSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
			ColSpriteRenderer->SetOrder(ERenderOrder::COLMAP);
			ColSpriteRenderer->SetSprite("stageBeforeBoss_col.png");

			FVector2D MapScale = ColSpriteRenderer->SetSpriteScale(1.0f);
			ColSpriteRenderer->SetComponentLocation(MapScale.Half());

		}
}

AItemRoomBeforeBossMap::~AItemRoomBeforeBossMap()
{
}

void AItemRoomBeforeBossMap::BeginPlay()
{
	APlayer* player = GetWorld()->GetPawn<APlayer>();

	player->SetActorLocation({ 0,0 });
}

void AItemRoomBeforeBossMap::Tick(float _deltaTime)
{
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->BlockCameraPos(MapScale, WinSize);

	FVector2D  CurCameraPos = GetWorld()->GetCameraPos();
	//GetWorld()->SetCameraPos({ CurCameraPos.X,CurCameraPos.Y + 70 });
}

