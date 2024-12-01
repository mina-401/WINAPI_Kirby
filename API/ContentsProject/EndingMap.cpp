#include "PreCompile.h"
#include "EndingMap.h"
#include "DanceKirby.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/2DCollision.h>
#include <EnginePlatform/EngineSound.h>

#include "ContentsEnum.h"
AEndingMap::AEndingMap()
{
	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
		SpriteRenderer->SetSprite("ending_background_map.png");

		MapScale = SpriteRenderer->SetSpriteScale(1.05f);
		SpriteRenderer->SetComponentLocation(MapScale.Half());
	}
	/*{
		ColSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		ColSpriteRenderer->SetOrder(ERenderOrder::COLMAP);
		ColSpriteRenderer->SetSprite("foreground1-1_col.png");

		FVector2D MapScale = ColSpriteRenderer->SetSpriteScale(1.0f);
		ColSpriteRenderer->SetComponentLocation(MapScale.Half());
		}
	*/
}

AEndingMap::~AEndingMap()
{
}
void AEndingMap::BeginPlay()
{
	Super::BeginPlay();

	ADanceKirby* player = GetWorld()->GetPawn<ADanceKirby>();
	player->SetActorLocation({ MapScale.Half().X,MapScale.Half().Y+76});
	

}

void AEndingMap::Tick(float _deltaTime)
{
	Super::Tick(_deltaTime);


}
