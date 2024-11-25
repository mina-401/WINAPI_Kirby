#include "PreCompile.h"
#include "WaddleDoo.h"
#include "Player.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>

#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"
AWaddleDoo::AWaddleDoo()
{
	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();

		SetName("WaddleDoo");

		SpriteRenderer->SetSprite("WaddleDoo_Left.png");
		SpriteRenderer->SetComponentScale({ 270, 270 });

		SpriteRenderer->SetOrder(ERenderOrder::MONSTER);

		UImageManager::GetInst().CuttingSprite("WaddleDoo_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("WaddleDoo_Right.png", { 128, 128 });

		SpriteRenderer->CreateAnimation("Walk_Left", "WaddleDoo_Left.png", 0, 4, 0.2f);
		SpriteRenderer->CreateAnimation("Walk_Right", "WaddleDoo_Right.png", 0, 4, 0.2f);
		SpriteRenderer->CreateAnimation("Attack_Left", "WaddleDoo_Left.png", { 5,6,5,6,5,6,7,8,8,8,8,8 }, 0.2f, true);
		SpriteRenderer->CreateAnimation("Attack_Right", "WaddleDoo_Right.png", { 5,6,5,6,5,6,7,8,8,8,8,8 }, 0.2f, true);
		SpriteRenderer->CreateAnimation("Inhaled_Left", "WaddleDoo_Left.png", 13, 13, 0.2f, true);
		SpriteRenderer->CreateAnimation("Inhaled_Right", "WaddleDoo_Right.png", 13, 13, 0.2f, true);
		SpriteRenderer->CreateAnimation("Damaged_Left", "WaddleDoo_Right.png", 13, 13, 0.2f, true);
		SpriteRenderer->CreateAnimation("Damaged_Right", "WaddleDoo_Right.png", 13, 13, 0.2f, true);
		SpriteRenderer->ChangeAnimation("Walk_Left");


	}
	{
		UImageManager::GetInst().CuttingSprite("WaddleDoo_Beam.png", { 128, 128 });
		BeamSpriteRenderer1 = CreateDefaultSubObject<USpriteRenderer>();

		BeamSpriteRenderer1->SetComponentScale({ 250, 250 });
		BeamSpriteRenderer1->SetComponentLocation({ 0, 0 });
		BeamSpriteRenderer1->SetOrder(ERenderOrder::MONSTER);

		BeamSpriteRenderer1->CreateAnimation("WaddleDoo_Beam", "WaddleDoo_Beam.png", 0, 1, 0.2f, true);
		BeamSpriteRenderer1->ChangeAnimation("WaddleDoo_Beam");  


	}
	{
		BeamSpriteRenderer2 = CreateDefaultSubObject<USpriteRenderer>();

		BeamSpriteRenderer2->SetComponentScale({ 250, 250 });
		BeamSpriteRenderer2->SetComponentLocation({ 0, 0 });
		BeamSpriteRenderer2->SetOrder(ERenderOrder::MONSTER);
						 
		BeamSpriteRenderer2->CreateAnimation("WaddleDoo_Beam", "WaddleDoo_Beam.png", 0, 1, 0.2f, true);
		BeamSpriteRenderer2->ChangeAnimation("WaddleDoo_Beam");


	}
	{
		BeamSpriteRenderer3 = CreateDefaultSubObject<USpriteRenderer>();
						 
		BeamSpriteRenderer3->SetComponentScale({ 250, 250 });
		BeamSpriteRenderer3->SetComponentLocation({ 0, 0 });
		BeamSpriteRenderer3->SetOrder(ERenderOrder::MONSTER);
						  
		BeamSpriteRenderer3->CreateAnimation("WaddleDoo_Beam", "WaddleDoo_Beam.png", 0, 1, 0.2f, true);
		BeamSpriteRenderer3->ChangeAnimation("WaddleDoo_Beam");


	}
	{
		BeamSpriteRenderer4 = CreateDefaultSubObject<USpriteRenderer>();
						  
		BeamSpriteRenderer4->SetComponentScale({ 250, 250 });
		BeamSpriteRenderer4->SetComponentLocation({ 0, 0 });
		BeamSpriteRenderer4->SetOrder(ERenderOrder::MONSTER);
						  
		BeamSpriteRenderer4->CreateAnimation("WaddleDoo_Beam", "WaddleDoo_Beam.png", 0, 1, 0.2f, true);
		BeamSpriteRenderer4->ChangeAnimation("WaddleDoo_Beam");


	}
	{
		AttackColComponent = CreateDefaultSubObject<U2DCollision>();
		AttackColComponent->SetComponentLocation({ 0, 0 });
		AttackColComponent->SetComponentScale({ 30, 30 });
		AttackColComponent->SetCollisionGroup(ECollisionGroup::MonsterAttack);
		AttackColComponent->SetCollisionType(ECollisionType::CirCle);

		AttackColComponent->SetCollisionEnter(std::bind(&AWaddleDoo::AttackCollisionEnter, this, std::placeholders::_1));
	}
	/*{
		AttackColComponent = CreateDefaultSubObject<U2DCollision>();
		AttackColComponent->SetComponentLocation({ 0, 0 });
		AttackColComponent->SetComponentScale({ 50, 50 });
		AttackColComponent->SetCollisionGroup(ECollisionGroup::MonsterAttack);
		AttackColComponent->SetCollisionType(ECollisionType::CirCle);

		AttackColComponent->SetCollisionEnter(std::bind(&AWaddleDoo::AttackCollisionEnter, this, std::placeholders::_1));
	}*/

	{
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, 0 });
		CollisionComponent->SetComponentScale({ 50, 50 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
		CollisionComponent->SetCollisionType(ECollisionType::CirCle);

	}
		DebugOn();
}

AWaddleDoo::~AWaddleDoo()
{
}

void AWaddleDoo::AttackStart()
{
	AMonster::AttackStart();
	//SpriteRenderer->
	if (nullptr != AttackColComponent) {
		AActor* ColActor = AttackColComponent->CollisionOnce(ECollisionGroup::PlayerBody);
		if (nullptr != ColActor)
		{
			APlayer* Target = dynamic_cast<APlayer*>(ColActor);
			if (nullptr != Target) {
				Target->ColKnockBackEnter(this);
			}
		}
	}
}

void AWaddleDoo::Attack(float _DeltaTime)
{
	AMonster::Attack(_DeltaTime);
}

void AWaddleDoo::BeginPlay()
{
	AMonster::BeginPlay();
	SetCopyAbilityState(ECopyAbilityState::Normal);
	SetMainPawn(dynamic_cast<APlayer*>(GetWorld()->GetPawn()));

}

void AWaddleDoo::Tick(float _DeltaTime)
{
	AMonster::Tick(_DeltaTime);

	FVector2D Pos;

	Angle -= _DeltaTime * 90;

	Pos.X = cosf(Angle *  3.14f / 180);
	Pos.Y = sinf(Angle * 3.14f / 180);


	Pos.Normalize();
	FVector2D StarPos1 =  Pos * 100;
	FVector2D StarPos2 =  Pos * 80;
	FVector2D StarPos3 =  Pos * 70;
	FVector2D StarPos4 =  Pos * 50;
	//if( Pos.Length())
	BeamSpriteRenderer1->SetComponentLocation(StarPos1);
	BeamSpriteRenderer2->SetComponentLocation(StarPos2);
	BeamSpriteRenderer3->SetComponentLocation(StarPos3);
	BeamSpriteRenderer3->SetComponentLocation(StarPos4);

	//TimeEventer

	AttackColComponent->SetComponentLocation(StarPos1);



		if (BulletTime < CurBulletTime)
		{

			Attackable = true;
		}
		CurBulletTime += 0.02f;
	
}


void AWaddleDoo::AttackCollisionEnter(AActor* _ColActor)
{
	if (Attackable == false) return;
	if (CurMonsterState != EMonsterState::Inhaled) {

		Attackable = false;
		CurBulletTime = 0.0f;
		ChangeState(EMonsterState::Attack);
	}

}

void AWaddleDoo::AttackCollisionStay(AActor* _ColActor)
{
}

void AWaddleDoo::AttackCollisionEnd(AActor* _ColActor)
{

}

void AWaddleDoo::CollisionEnter(AActor* _ColActor)
{
	AMonster::CollisionEnter(_ColActor);

	int a = 0;
}
