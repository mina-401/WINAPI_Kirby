#include "PreCompile.h"
#include "ItemRoomBeforeBossMap.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"
#include "StageBackground.h"
#include "Player.h"
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

		{
			GetWorld()->CollisionGroupLink(ECollisionGroup::Potal, ECollisionGroup::PlayerBody);


			PotalColComponent = CreateDefaultSubObject<U2DCollision>();
			PotalColComponent->SetComponentLocation({ (float)MapScale.Half().X+25,(float)MapScale.Y-140});
			PotalColComponent->SetComponentScale({ 20, 40 });
			PotalColComponent->SetCollisionGroup(ECollisionGroup::Potal);
			PotalColComponent->SetCollisionType(ECollisionType::CirCle);

			PotalColComponent->SetCollisionEnter(std::bind(&AItemRoomBeforeBossMap::CollisionEnter, this, std::placeholders::_1));
			PotalColComponent->SetCollisionStay(std::bind(&AItemRoomBeforeBossMap::CollisionStay, this, std::placeholders::_1));
			PotalColComponent->SetCollisionEnd(std::bind(&AItemRoomBeforeBossMap::CollisionEnd, this, std::placeholders::_1));
			DebugOn();
		}
		{
			StarSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
			StarSpriteRenderer->SetSprite("StarBulletIdle_Left.png");
			StarSpriteRenderer->SetOrder(ERenderOrder::PLAYER);
			FVector2D StarScale = StarSpriteRenderer->SetSpriteScale(1.0f);
			StarSpriteRenderer->SetComponentScale({ 250, 250 });
			StarSpriteRenderer->SetComponentLocation({ 340,300 });

			StarSpriteRenderer->CreateAnimation("StarBulletIdle_Left", "StarBulletIdle_Left.png", 0, 1, 0.1f, true);
			StarSpriteRenderer->CreateAnimation("StarBulletIdle_Right", "StarBulletIdle_Right.png", 0, 1, 0.1f, true);
			StarSpriteRenderer->ChangeAnimation("StarBulletIdle_Left");
		}
}

AItemRoomBeforeBossMap::~AItemRoomBeforeBossMap()
{
}

void AItemRoomBeforeBossMap::BeginPlay()
{
	Super::BeginPlay();
	APlayer* player = GetWorld()->GetPawn<APlayer>();

	player->SetActorLocation({ 50,250 });
}

void AItemRoomBeforeBossMap::Tick(float _deltaTime)
{
	Super::Tick(_deltaTime);	
	if (true == UEngineInput::GetInst().IsPress(VK_UP) && IsPlayerStayPotal) {
		USoundPlayer EffectSound;
		EffectSound = UEngineSound::Play("Potal travel.WAV");
		UEngineAPICore::GetCore()->OpenLevel("StageBossKingDedede");
	}
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->BlockCameraPos(MapScale, WinSize);

	EPlayerState PlayerState = player->GetCurPlayerState();
	if (PlayerState == EPlayerState::Fly || PlayerState == EPlayerState::Jump) {
		player->SetColImage("stageBeforeBoss_noncol.png");

	}
	else {
		player->SetColImage("stageBeforeBoss_col.png");

	}
}

void AItemRoomBeforeBossMap::CollisionEnter(AActor* _ColActor)
{
	//IsPlayerStayPotal = true;
}

void AItemRoomBeforeBossMap::CollisionStay(AActor* _ColActor)
{

	APlayer* Player = dynamic_cast<APlayer*>(_ColActor);
	IsPlayerStayPotal = true;
}

void AItemRoomBeforeBossMap::CollisionEnd(AActor* _ColActor)
{
	IsPlayerStayPotal = false;
}