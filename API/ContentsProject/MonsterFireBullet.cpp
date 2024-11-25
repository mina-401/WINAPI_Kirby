#include "PreCompile.h"
#include "MonsterFireBullet.h"

#include "Player.h"
#include "HotHead.h"
#include "ContentsEnum.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>
AMonsterFireBullet::AMonsterFireBullet()
{
	UImageManager::GetInst().CuttingSprite("FireBulletIdle_Left.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("FireBulletIdle_Right.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("HotHead_Left.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("HotHead_Right.png", { 128, 128 });

	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetSprite("FireBulletIdle_Right.png");
		SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
		SpriteRenderer->SetComponentScale({ 300, 300 });
		SpriteRenderer->SetComponentLocation({0,0 });


		SpriteRenderer->CreateAnimation("FireBulletIdle_Left", "FireBulletIdle_Left.png", 0, 6, 0.08f, false);
		SpriteRenderer->CreateAnimation("FireBulletIdle_Right", "FireBulletIdle_Right.png", 0, 6, 0.08f, false);
		SpriteRenderer->CreateAnimation("FireboomerangIdle_Left", "HotHead_Left.png", 8,13, 0.05f, true);
		SpriteRenderer->CreateAnimation("FireboomerangIdle_Right", "HotHead_Right.png", 8,13, 0.05f,true);
		SpriteRenderer->ChangeAnimation("FireboomerangIdle_Right");
	}

	DebugOn();

	Destroy(10.0f);
}

AMonsterFireBullet::~AMonsterFireBullet()
{
}

void AMonsterFireBullet::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == IsBoome)
	{
		FVector2D CurPos = GetActorLocation();

		FVector2D NextPos = CurPos + PlayerDir * _DeltaTime * 200.0f;
		SetActorLocation(NextPos);



	}
	else
	{

	}
	
}

void AMonsterFireBullet::BeginPlay()
{
	Super::BeginPlay();
	//SetMainPawn();
	APlayer* Player = GetWorld()->GetPawn<APlayer>();

	PlayerDir = Player->GetActorLocation() - MainPawn->GetActorLocation();
	PlayerDir.Normalize();

	if (0 <= PlayerDir.X)
	{
		Vector = FVector2D::RIGHT;

	}
	else
	{
		Vector = FVector2D::LEFT;

	}

	if (true == IsBoome)
	{
		FireboomerangStart();
	}
	else {
		FireBulletStart();
	}
	
}

void AMonsterFireBullet::DirCheck()
{
	if (Vector == FVector2D::LEFT)
	{
		DirString = "_Left";

	}
	else
	{
		DirString = "_Right";

	}
}

void AMonsterFireBullet::FireBulletStart()
{
	DirCheck();
	SpriteRenderer->ChangeAnimation("FireBulletIdle" + DirString);

}
void AMonsterFireBullet::FireboomerangStart()
{
	DirCheck();
	SpriteRenderer->ChangeAnimation("FireboomerangIdle" + DirString);
}