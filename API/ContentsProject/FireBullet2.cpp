#include "PreCompile.h"
#include "FireBullet2.h"
#include "Player.h"
#include "ContentsEnum.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>

AFireBullet2::AFireBullet2()
{
	UImageManager::GetInst().CuttingSprite("2FireBulletIdle_Left.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("2FireBulletIdle_Right.png", { 128, 128 });


	{
		SpriteRenderer1 = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer1->SetOrder(ERenderOrder::PLAYER);
		SpriteRenderer1->SetComponentScale({ 300, 300 });

		SpriteRenderer1->CreateAnimation("2FireBulletIdle1_Left", "2FireBulletIdle_Left.png", 0,7, 0.1f,true);
		SpriteRenderer1->CreateAnimation("2FireBulletIdle1_Right", "2FireBulletIdle_Right.png", 0,7, 0.1f,true);
		SpriteRenderer1->ChangeAnimation("2FireBulletIdle1_Right");
	}
	{
		SpriteRenderer2 = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer2->SetOrder(ERenderOrder::PLAYER);
		SpriteRenderer2->SetComponentScale({ 300, 300 });

		SpriteRenderer2->CreateAnimation("2FireBulletIdle2_Left", "2FireBulletIdle_Left.png", 8, 15, 0.1f, true);
		SpriteRenderer2->CreateAnimation("2FireBulletIdle2_Right", "2FireBulletIdle_Right.png", 8, 15, 0.1f, true);
		SpriteRenderer2->ChangeAnimation("2FireBulletIdle2_Right");
	}
	{
		SpriteRenderer3 = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer3->SetOrder(ERenderOrder::PLAYER);
		SpriteRenderer3->SetComponentScale({ 300, 300 });
					
		SpriteRenderer3->CreateAnimation("2FireBulletIdle3_Left", "2FireBulletIdle_Left.png", 16, 23, 0.1f, true);
		SpriteRenderer3->CreateAnimation("2FireBulletIdle3_Right", "2FireBulletIdle_Right.png", 16, 23, 0.1f, true);
		SpriteRenderer3->ChangeAnimation("2FireBulletIdle3_Right");
	}													 
	DebugOn();

	Destroy(5.0f);
}

AFireBullet2::~AFireBullet2()
{
}

void AFireBullet2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);



	if (true == SpriteRenderer3->IsCurAnimationEnd())
	{
		Destroy(0);
	}

	FVector2D CurPos = SpriteRenderer1->GetComponentLocation();
	if (Vector == FVector2D::LEFT)
	{
		FVector2D NextPos = CurPos + Vector * _DeltaTime * 80.0f;
		SpriteRenderer1->SetComponentLocation(NextPos);
		SpriteRenderer2->SetComponentLocation(NextPos);
		SpriteRenderer3->SetComponentLocation(NextPos);

	}
	else
	{
		FVector2D NextPos = CurPos + Vector * _DeltaTime * 80.0f;
		SpriteRenderer1->SetComponentLocation(NextPos);
		SpriteRenderer2->SetComponentLocation(NextPos);
		SpriteRenderer3->SetComponentLocation(NextPos);

	}
}

void AFireBullet2::BeginPlay()
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

void AFireBullet2::DirCheck()
{

	if (Vector == FVector2D::LEFT)
	{
		DirString = "_Left";
		SpriteRenderer1->SetComponentLocation({ -60,10 });
		SpriteRenderer2->SetComponentLocation({ -70,10 });
		SpriteRenderer3->SetComponentLocation({ -80,10 });

	}
	else
	{
		DirString = "_Right";
		SpriteRenderer1->SetComponentLocation({ 60,10 });
		SpriteRenderer2->SetComponentLocation({ 70,10 });
		SpriteRenderer3->SetComponentLocation({ 80,10 });

	}
}

void AFireBullet2::FireBulletStart() {
	DirCheck();

	SpriteRenderer1->ChangeAnimation("2FireBulletIdle1" + DirString);
	SpriteRenderer2->ChangeAnimation("2FireBulletIdle2" + DirString);
	SpriteRenderer3->ChangeAnimation("2FireBulletIdle3" + DirString);


}