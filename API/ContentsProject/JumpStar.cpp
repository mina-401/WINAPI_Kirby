#include "PreCompile.h"
#include "JumpStar.h"
#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>
#include "Player.h"
#include <EnginePlatform/EngineSound.h>

AJumpStar::AJumpStar()
{
	UImageManager::GetInst().CuttingSprite("StarBulletIdle_Left.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("StarBulletIdle_Right.png", { 128, 128 });


	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetSprite("StarBulletIdle_Left.png");
		SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
		SpriteRenderer->SetComponentScale({ 300, 300 });
	}
	{
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, 0 });
		CollisionComponent->SetComponentScale({ 50,50 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::Block);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
		//CollisionComponent->SetCollisionEnter(std::bind(&AJumpStar::CollisionEnter, this, std::placeholders::_1));

	}
	{
		SpriteRenderer->CreateAnimation("StarBulletIdle_Left", "StarBulletIdle_Left.png", 0, 1, 0.1f, true);
		SpriteRenderer->CreateAnimation("StarBulletIdle_Right", "StarBulletIdle_Right.png", 0, 1, 0.1f, true);
		SpriteRenderer->ChangeAnimation("StarBulletIdle_Left");
	}
	DebugOn();

	Destroy(10.0f);
}

AJumpStar::~AJumpStar()
{
}

void AJumpStar::SetColImage(std::string_view _ColImageName)
{
	ColImage = UImageManager::GetInst().FindImage(_ColImageName);
}

void AJumpStar::Tick(float _DeltaTime)
{
	if (Ishaling == false) {
		JumpGravity(_DeltaTime);
		AddActorLocation(JumpPower * _DeltaTime);

		FVector2D NextPos = GetActorLocation() + JumpPower * _DeltaTime;
		//AddActorLocation(NextPos);
		//ector2D NextPos = GravityForce ;
		if (false == StarNextPosCheck(_DeltaTime, NextPos))
		{
			GravityForce = FVector2D::ZERO;
		}
	}

}

void AJumpStar::BeginPlay()
{

	SetForegroundColImage();

	if (MainPawn->DirString == "_Left") {
		JumpPower.X = JumpPower.X * -100.0f;
	}
	else {
		JumpPower.X = JumpPower.X * 100.0f;

	}

	BGMPlayer = UEngineSound::Play("JumpStart Pang.WAV");
}
void AJumpStar::SetForegroundColImage()
{
	AGameMode* gm = GetWorld()->GetGameMode<AGameMode>();
	if (gm == nullptr) return;

	if ("Stage1_1" == gm->GetName()) {
		SetColImage("foreground1-1_col.png");
	}
	else if ("Stage1_2" == gm->GetName()) {
		SetColImage("foreground1-2_col.png");

	}
	else if ("Stage1_3" == gm->GetName()) {
		SetColImage("foreground1-3_col.png");

	}
	/*else if ("Stage1_4" == gm->GetName()) {
	Bullet->SetColImage("foreground1-4_col.png");

	}*/
	else if ("ItemRoomBeforeBoss" == gm->GetName()) {
		SetColImage("stageBeforeBoss_col.png");
	}
	else if ("StageBossKingDedede" == gm->GetName()) {
		SetColImage("foregroundKingDedede1-1_col.png");
	}

}
bool AJumpStar::StarNextPosCheck(float _DeltaTime, FVector2D _Vector)
{
	UColor Color = ColImage->GetColor(_Vector, UColor::WHITE);
	if (Color != UColor::WHITE)
	{
		return false;
	}
	else
	{
		return true;
	}

}