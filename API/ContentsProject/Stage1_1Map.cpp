#include "PreCompile.h"
#include "ContentsEnum.h"
#include "Player.h"
#include "Stage1_1Map.h"
#include "StageBackground.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/2DCollision.h>
#include <EnginePlatform/EngineSound.h>

#include "Stage1_1GameMode.h"
#include "Monster.h"
#include "WaddleDee.h"
AStage1_1Map::AStage1_1Map()
{
	PngSize = {(float) 792.5 ,(float)103.5 };
	WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
		SpriteRenderer->SetSprite("foreground1-1.png");

		MapScale = SpriteRenderer->SetSpriteScale(1.0f);
		SpriteRenderer->SetComponentLocation(MapScale.Half());
	}
	{
		ColSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		ColSpriteRenderer->SetOrder(ERenderOrder::COLMAP);
		ColSpriteRenderer->SetSprite("foreground1-1_col.png");

		FVector2D MapScale = ColSpriteRenderer->SetSpriteScale(1.0f);
		ColSpriteRenderer->SetComponentLocation(MapScale.Half());
	}
	{



		PotalColComponent = CreateDefaultSubObject<U2DCollision>();
		PotalColComponent->SetComponentLocation({(float)MapScale.X-80,(float) WinSize.Half().Y +70});
		PotalColComponent->SetComponentScale({ 20, 40 });
		PotalColComponent->SetCollisionGroup(ECollisionGroup::Potal);
		PotalColComponent->SetCollisionType(ECollisionType::CirCle);

		PotalColComponent->SetCollisionEnter(std::bind(&AStage1_1Map::CollisionEnter, this, std::placeholders::_1));
		PotalColComponent->SetCollisionStay(std::bind(&AStage1_1Map::CollisionStay, this, std::placeholders::_1));
		PotalColComponent->SetCollisionEnd(std::bind(&AStage1_1Map::CollisionEnd, this, std::placeholders::_1));



		DebugOn();
	}
}

AStage1_1Map::~AStage1_1Map()
{
}
void AStage1_1Map::CollisionEnter(AActor* _ColActor)
{
	
	IsPlayerStayPotal = true;

}

void AStage1_1Map::CollisionStay(AActor* _ColActor)
{

	APlayer* Player = dynamic_cast<APlayer*>(_ColActor);
	IsPlayerStayPotal = true;
}

void AStage1_1Map::CollisionEnd(AActor* _ColActor)
{
	IsPlayerStayPotal = false;
}
void AStage1_1Map::BeginPlay()
{
	
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->SetActorLocation({250,300});

}

void AStage1_1Map::Tick(float _deltaTime)
{
	Super::Tick(_deltaTime);

	/*if (true == UEngineInput::GetInst().IsDown('Y'))
	{
		ColSpriteRenderer->SetActiveSwitch();
	}*/

	if (true == UEngineInput::GetInst().IsPress(VK_UP) && IsPlayerStayPotal) {

		USoundPlayer EffectSound;
		EffectSound = UEngineSound::Play("Potal travel.WAV");
		UEngineAPICore::GetCore()->OpenLevel("Stage1_2");
	}

	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->BlockCameraPos(MapScale, WinSize);

	AStage1_1GameMode* GameMode = GetWorld()->GetGameMode<AStage1_1GameMode>();
	AMonster* Dee = GameMode->MonsterWaddleDee;
	AMonster* Doo = GameMode->MonsterWaddleDoo;
	AMonster* Sparky = GameMode->MonsterSparky;
	Dee->BlockMonsterPos(MapScale);
	Doo->BlockMonsterPos(MapScale);
	Sparky->BlockMonsterPos(MapScale);
}

