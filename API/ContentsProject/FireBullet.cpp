#include "PreCompile.h"
#include "FireBullet.h"
#include "Player.h"
#include "ContentsEnum.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/2DCollision.h>

AFireBullet::AFireBullet()
{
	UImageManager::GetInst().CuttingSprite("FireBulletIdle_Left.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("FireBulletIdle_Right.png", { 128, 128 });


	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetSprite("FireBulletIdle_Right.png");
		SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
		SpriteRenderer->SetComponentScale({ 300, 300 });

		SpriteRenderer->CreateAnimation("FireBulletIdle_Left", "FireBulletIdle_Left.png", 0,6, 0.08f, true);
		SpriteRenderer->CreateAnimation("FireBulletIdle_Right", "FireBulletIdle_Right.png", 0,6, 0.08f, true);
		SpriteRenderer->ChangeAnimation("FireBulletIdle_Right");
	} 
	{
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, 0 });
		CollisionComponent->SetComponentScale({ 50, 50 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
		CollisionComponent->SetCollisionType(ECollisionType::CirCle);

	
	}
	DebugOn();

	Destroy(5.0f);
}

AFireBullet::~AFireBullet()
{
}

void AFireBullet::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	


	if (true == SpriteRenderer->IsCurAnimationEnd())
	{
		Destroy(0);
	}

	FVector2D CurPos = SpriteRenderer->GetComponentLocation();
	if (Vector == FVector2D::LEFT)
	{
		FVector2D NextPos = CurPos + Vector * _DeltaTime * 80.0f;
		SpriteRenderer->SetComponentLocation(NextPos);

	}
	else
	{
		FVector2D NextPos = CurPos + Vector * _DeltaTime * 80.0f;
		SpriteRenderer->SetComponentLocation(NextPos);

	}
}

void AFireBullet::BeginPlay()
{
	Super::BeginPlay();
	if (MainPawn->DirString == "_Left")
	{
		Vector = FVector2D::LEFT;

	}
	else {
		Vector = FVector2D::RIGHT;

	}

	FireBulletStart(); 
}

void AFireBullet::DirCheck()
{

	if (Vector == FVector2D::LEFT)
	{
		DirString = "_Left";
		SpriteRenderer->SetComponentLocation({ -70,10 });

	}
	else
	{
		DirString = "_Right";
		SpriteRenderer->SetComponentLocation({70,10});

	}
}

void AFireBullet::FireBulletStart() {
	DirCheck();

	SpriteRenderer->ChangeAnimation("FireBulletIdle" + DirString);

	
}