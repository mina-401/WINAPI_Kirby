#include "PreCompile.h"
#include "Bullet.h"
#include "Player.h"
#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>
#include "Monster.h"
ABullet::ABullet()
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
		CollisionComponent->SetCollisionType(ECollisionType::CirCle);
		CollisionComponent->SetCollisionEnter(std::bind(&ABullet::CollisionEnter, this, std::placeholders::_1));

	}
	{
		SpriteRenderer->CreateAnimation("StarBulletIdle_Left", "StarBulletIdle_Left.png", 0, 1, 0.1f,true);
		SpriteRenderer->CreateAnimation("StarBulletIdle_Right", "StarBulletIdle_Right.png", 0, 1, 0.1f,true);
		SpriteRenderer->ChangeAnimation("StarBulletIdle_Left");
	}
	DebugOn();
	Destroy(3.0f);

}

ABullet::~ABullet()
{
}
void ABullet::SetColImage(std::string_view _ColImageName)
{
	ColImage = UImageManager::GetInst().FindImage(_ColImageName);
}

void ABullet::DirCheck()
{

	if (Vector==FVector2D::LEFT)
	{
		DirString = "_Left";
	}
	else
	{
		DirString = "_Right";
	}
}
void ABullet::CollisionEnter(AActor* _ColActor)
{
	AMonster* Target = dynamic_cast<AMonster*>(_ColActor);
	if (nullptr != Target)
	{
		Target->ColKnockBackEnter(this);
		SetActive(false);

	}
}
bool ABullet::BulletNextPosCheck(float _DeltaTime, FVector2D _Vector)
{
	UColor Color = ColImage->GetColor(GetActorLocation() + _Vector * _DeltaTime * Speed, UColor::WHITE);
	if (Color != UColor::WHITE)
	{
		return false;
	}
	else
	{
		return true;
	}

}

void ABullet::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if(false == BulletNextPosCheck(_DeltaTime, Vector))
	{
		// 
		SetActive(false);
		return;
	}
	AddActorLocation(Vector *_DeltaTime * Speed );
}

void ABullet::BeginPlay()
{
	Super::BeginPlay();
	if (MainPawn-> DirString == "_Left")
	{
		Vector = FVector2D::LEFT;

	}
	else {
		Vector = FVector2D::RIGHT;

	}
	BulletStart();

}
void ABullet::BulletStart() {
	DirCheck();

	SpriteRenderer->ChangeAnimation("StarBulletIdle"+DirString);
}
