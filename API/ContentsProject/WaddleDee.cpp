#include "PreCompile.h"
#include "WaddleDee.h"
#include "Player.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>
#include <EnginePlatform/EngineSound.h>

#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"
AWaddleDee::AWaddleDee()
{
	//CopyAbilityStatus = ECopyAbilityState::Normal;
	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();

		SetName("WaddleDee");

		SpriteRenderer->SetSprite("WaddleDee_Left.png");
		SpriteRenderer->SetComponentScale({ 270, 270 });

		SpriteRenderer->SetOrder(ERenderOrder::MONSTER);

		UImageManager::GetInst().CuttingSprite("WaddleDee_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("WaddleDee_Right.png", { 128, 128 });

		SpriteRenderer->CreateAnimation("Walk_Left", "WaddleDee_Left.png", 0, 4, 0.2f);
		SpriteRenderer->CreateAnimation("Walk_Right", "WaddleDee_Right.png", 0, 4, 0.2f);
		SpriteRenderer->CreateAnimation("Attack_Left", "WaddleDee_Left.png", 0, 4, 0.2f);
		SpriteRenderer->CreateAnimation("Attack_Right", "WaddleDee_Right.png", 0, 4, 0.2f);
		SpriteRenderer->CreateAnimation("Inhaled_Left", "WaddleDee_Left.png", 9, 9, 0.2f,true);
		SpriteRenderer->CreateAnimation("Inhaled_Right", "WaddleDee_Right.png", 9, 9, 0.2f,true);
		SpriteRenderer->CreateAnimation("Damaged_Left", "WaddleDee_Left.png", 9, 9, 1.5f,false);
		SpriteRenderer->CreateAnimation("Damaged_Right", "WaddleDee_Right.png", 9, 9, 1.5f, false);
		SpriteRenderer->ChangeAnimation("Walk_Left");


	}
	/*{

		SpawnColComponent = CreateDefaultSubObject<U2DCollision>();
		SpawnColComponent->SetComponentLocation({ 740,360});
		SpawnColComponent->SetComponentScale({ 20, 40 });
		SpawnColComponent->SetCollisionGroup(ECollisionGroup::Potal);
		SpawnColComponent->SetCollisionType(ECollisionType::Rect);

		SpawnColComponent->SetCollisionEnter(std::bind(&AWaddleDee::SpawnCollisionEnter, this, std::placeholders::_1));
	}*/
	
}

AWaddleDee::~AWaddleDee()
{
}

void AWaddleDee::BeginPlay()
{
	AMonster::BeginPlay();
	SetCopyAbilityState(ECopyAbilityState::Fire);
	SetDamagePower(100.0f);

}

void AWaddleDee::AttackStart()
{
	int a = 0;
	
}

void AWaddleDee::Attack(float _DeltaTime)
{
	
}

void AWaddleDee::SpawnCollisionEnter(AActor* _ColActor)
{
	int a = 0;
}

void AWaddleDee::CollisionEnter(AActor* _ColActor)
{
	AMonster::CollisionEnter(_ColActor);

	int a = 0;
}

void AWaddleDee::CollisionEnd(AActor* _ColActor)
{
	int a = 0;
}
