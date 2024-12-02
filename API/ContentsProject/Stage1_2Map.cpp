#include "PreCompile.h"
#include "Stage1_2Map.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"
#include "Player.h"
#include "Stage1_2GameMode.h"
#include "Monster.h"
#include "Block.h"
#include "SmallBlock.h"
#include "BigBlock.h"
#include "DownBrokeBlock.h"
AStage1_2Map::AStage1_2Map()
{

	WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	UImageManager::GetInst().CuttingSprite("StarBulletIdle_Left.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("StarBulletIdle_Right.png", { 128, 128 });

	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::FOREGROUND);
		SpriteRenderer->SetSprite("foreground1-2.png");

		MapScale = SpriteRenderer->SetSpriteScale(1.0f);
		SpriteRenderer->SetComponentLocation(MapScale.Half());
	}
	{
		ColSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		ColSpriteRenderer->SetOrder(ERenderOrder::COLMAP);
		ColSpriteRenderer->SetSprite("foreground1-2_col.png");

		FVector2D MapScale = ColSpriteRenderer->SetSpriteScale(1.0f);
		ColSpriteRenderer->SetComponentLocation(MapScale.Half());
	}
	{
		GetWorld()->CollisionGroupLink(ECollisionGroup::Potal, ECollisionGroup::PlayerBody);


		PotalColComponent = CreateDefaultSubObject<U2DCollision>();
		PotalColComponent->SetComponentLocation({ (float)MapScale.X - 100,(float)WinSize.Half().Y + 40 });
		PotalColComponent->SetComponentScale({ 20, 40 });
		PotalColComponent->SetCollisionGroup(ECollisionGroup::Potal);
		PotalColComponent->SetCollisionType(ECollisionType::CirCle);

		PotalColComponent->SetCollisionEnter(std::bind(&AStage1_2Map::CollisionEnter, this, std::placeholders::_1));
		PotalColComponent->SetCollisionStay(std::bind(&AStage1_2Map::CollisionStay, this, std::placeholders::_1));
		PotalColComponent->SetCollisionEnd(std::bind(&AStage1_2Map::CollisionEnd, this, std::placeholders::_1));
		DebugOn();
	}
	{
		StarSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		StarSpriteRenderer->SetSprite("StarBulletIdle_Left.png");
		StarSpriteRenderer->SetOrder(ERenderOrder::PLAYER);
		FVector2D StarScale = StarSpriteRenderer->SetSpriteScale(1.0f);
		StarSpriteRenderer->SetComponentScale({ 250, 250 });
		StarSpriteRenderer->SetComponentLocation({ 3540,220 });

		StarSpriteRenderer->CreateAnimation("StarBulletIdle_Left", "StarBulletIdle_Left.png", 0, 1, 0.1f, true);
		StarSpriteRenderer->CreateAnimation("StarBulletIdle_Right", "StarBulletIdle_Right.png", 0, 1, 0.1f, true);
		StarSpriteRenderer->ChangeAnimation("StarBulletIdle_Right");
	}
}

AStage1_2Map::~AStage1_2Map()
{
}
void AStage1_2Map::CollisionEnter(AActor* _ColActor)
{
	IsPlayerStayPotal = true;
}

void AStage1_2Map::CollisionStay(AActor* _ColActor)
{

	APlayer* Player = dynamic_cast<APlayer*>(_ColActor);
	IsPlayerStayPotal = true;
}

void AStage1_2Map::CollisionEnd(AActor* _ColActor)
{
	IsPlayerStayPotal = false;
}
void AStage1_2Map::BeginPlay()
{
	Super::BeginPlay();
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->SetActorLocation({ 100,300});
	//player->SetActorLocation({ (float)MapScale.X - 80,(float)WinSize.Half().Y });
	ASmallBlock* NewBlock = GetWorld()->SpawnActor<ASmallBlock>();
	ABigBlock* NewBigBlock = GetWorld()->SpawnActor<ABigBlock>();
	/*ADownBrokeBlock* Block1 = GetWorld()->SpawnActor<ADownBrokeBlock>();
	ADownBrokeBlock* Block2 = GetWorld()->SpawnActor<ADownBrokeBlock>();
	ADownBrokeBlock* Block3 = GetWorld()->SpawnActor<ADownBrokeBlock>();
	ADownBrokeBlock* Block4 = GetWorld()->SpawnActor<ADownBrokeBlock>();
	ADownBrokeBlock* Block5 = GetWorld()->SpawnActor<ADownBrokeBlock>();
	ADownBrokeBlock* Block6 = GetWorld()->SpawnActor<ADownBrokeBlock>();
	ADownBrokeBlock* Block7 = GetWorld()->SpawnActor<ADownBrokeBlock>();
	Block1->SetActorLocation({ 1950+20,200+15 });
	Block2->SetActorLocation({ 1950+60,200+15 });
	Block3->SetActorLocation({ 1950+100,200+15 });
	Block4->SetActorLocation({ 1950+140,200+15 });
	Block5->SetActorLocation({ 1950+180,200+15 });
	Block6->SetActorLocation({ 1950+220,200+15 });
	Block7->SetActorLocation({ 1950+260,200+15 });*/

	

}

void AStage1_2Map::Tick(float _deltaTime)
{
	Super::Tick(_deltaTime);
	if (true == UEngineInput::GetInst().IsPress(VK_UP) && IsPlayerStayPotal) {
		UEngineAPICore::GetCore()->ResetLevel<AStage1_2GameMode, APlayer>("Stage1_2");
		UEngineAPICore::GetCore()->OpenLevel("Stage1_3");
	}
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->BlockCameraPos(MapScale, WinSize);

	if (true == UEngineInput::GetInst().IsPress(VK_UP) && IsPlayerStayPotal) {
		USoundPlayer EffectSound;
		EffectSound = UEngineSound::Play("Potal travel.WAV");
		UEngineAPICore::GetCore()->OpenLevel("Stage1_3");
	}
	AStage1_2GameMode* GameMode = GetWorld()->GetGameMode<AStage1_2GameMode>();
	AMonster* HotHead = GameMode->MonsterHotHead;
	//HotHead->SetMainPawn(this);
	HotHead->BlockMonsterPos(MapScale);
}



