#include "PreCompile.h"
#include "HotHead.h"
#include "Player.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>

#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"
#include "MonsterFireBullet.h"

AHotHead::AHotHead()
{
	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SetName("HotHead");

		SpriteRenderer->SetSprite("HotHead_Left.png");
		SpriteRenderer->SetComponentScale({ 270, 270 });

		SpriteRenderer->SetOrder(ERenderOrder::MONSTER);

		UImageManager::GetInst().CuttingSprite("HotHead_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("HotHead_Right.png", { 128, 128 });

		SpriteRenderer->CreateAnimation("Walk_Left", "HotHead_Left.png", {0,1,2,3,4,3,2}, 0.2f);
		SpriteRenderer->CreateAnimation("Walk_Right", "HotHead_Right.png", { 0,1,2,3,4,3,2 }, 0.2f);
		SpriteRenderer->CreateAnimation("Attack_Left", "HotHead_Left.png", 5,7, 0.2f, false);
		SpriteRenderer->CreateAnimation("Attack_Right", "HotHead_Right.png", 5, 7, 0.2f, false);
		SpriteRenderer->CreateAnimation("Inhaled_Left", "HotHead_Left.png", 19, 19, 0.2f, true);
		SpriteRenderer->CreateAnimation("Inhaled_Right", "HotHead_Right.png", 19, 19, 0.2f, true);
		SpriteRenderer->CreateAnimation("Damaged_Left", "HotHead_Left.png",19,19, 1.0f, true);
		SpriteRenderer->CreateAnimation("Damaged_Right", "HotHead_Right.png",19,19, 1.0f, true);
		SpriteRenderer->ChangeAnimation("Walk_Left");
	}
	{
		AttackColComponent = CreateDefaultSubObject<U2DCollision>();
		AttackColComponent->SetComponentLocation({ 0, 0 });
		AttackColComponent->SetComponentScale({ 250, 250   });
		AttackColComponent->SetCollisionGroup(ECollisionGroup::MonsterAttack);
		AttackColComponent->SetCollisionType(ECollisionType::CirCle);

		AttackColComponent->SetCollisionEnter(std::bind(&AHotHead::AttackBoomeCollisionEnter, this, std::placeholders::_1));
		//AttackColComponent->SetCollisionStay(std::bind(&ASparky::AttackCollisionStay, this, std::placeholders::_1));
		//AttackColComponent->SetCollisionEnd(std::bind(&ASparky::AttackCollisionEnd, this, std::placeholders::_1));
	}

	{
		/*AttackColComponent = CreateDefaultSubObject<U2DCollision>();
		AttackColComponent->SetComponentLocation({ 0, 0 });
		AttackColComponent->SetComponentScale({ 200, 200 });
		AttackColComponent->SetCollisionGroup(ECollisionGroup::MonsterAttack);
		AttackColComponent->SetCollisionType(ECollisionType::CirCle);

		AttackColComponent->SetCollisionEnter(std::bind(&AHotHead::AttackCollisionEnter, this, std::placeholders::_1));*/
		//AttackColComponent->SetCollisionStay(std::bind(&ASparky::AttackCollisionStay, this, std::placeholders::_1));
		//AttackColComponent->SetCollisionEnd(std::bind(&ASparky::AttackCollisionEnd, this, std::placeholders::_1));
	}

	
}

AHotHead::~AHotHead()
{
}

void AHotHead::AttackStart()
{
	AMonster::AttackStart();

	AMonsterFireBullet* bullet = GetWorld()->SpawnActor<AMonsterFireBullet>();

	bullet->SetMainPawn(this);
	bullet->SetActorLocation(GetActorLocation());
	bullet->SetIsBoome(IsBoome);
}

void AHotHead::Attack(float _DeltaTime)
{
	AMonster::Attack(_DeltaTime);
	if (true == BGMPlayer.IsPlaying())
	{
		BGMPlayer.Stop();
	}
	BGMPlayer = UEngineSound::Play("AttackFire.WAV");
}

void AHotHead::BeginPlay()
{
	AMonster::BeginPlay();
	SetCopyAbilityState(ECopyAbilityState::Fire);
	SetDamagePower(100.0f);

}

void AHotHead::Tick(float _DeltaTime)
{
	AMonster::Tick(_DeltaTime);

	if (BulletTime < CurBulletTime)
	{

		Attackable = true;
	}
	CurBulletTime += 0.02f;
}

//void AHotHead::AttackCollisionEnter(AActor* _ColActor)
//{
//	IsBoome = false;
//	ChangeState(EMonsterState::Attack);
//}
void AHotHead::AttackBoomeCollisionEnter(AActor* _ColActor)
{
	if (Attackable == false) return;
	if (CurMonsterState != EMonsterState::Inhaled) {
		IsBoome = true;
		Attackable = false;
		CurBulletTime = 0.0f;
		ChangeState(EMonsterState::Attack);
	}
	
}