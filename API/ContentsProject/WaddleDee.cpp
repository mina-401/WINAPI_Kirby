#include "PreCompile.h"
#include "WaddleDee.h"
#include "Player.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>

#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"
AWaddleDee::AWaddleDee()
{
	CopyAbilityStatus = ECopyAbilityStatus::UnableCopy;
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
		SpriteRenderer->ChangeAnimation("Walk_Left");


	}
	{

		SpawnColComponent = CreateDefaultSubObject<U2DCollision>();
		SpawnColComponent->SetComponentLocation({ 740,360});
		SpawnColComponent->SetComponentScale({ 20, 40 });
		SpawnColComponent->SetCollisionGroup(ECollisionGroup::Potal);
		SpawnColComponent->SetCollisionType(ECollisionType::Rect);

		SpawnColComponent->SetCollisionEnter(std::bind(&AWaddleDee::SpawnCollisionEnter, this, std::placeholders::_1));
	}
	{
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, -20 });
		CollisionComponent->SetComponentScale({ 50, 50 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
		CollisionComponent->SetCollisionType(ECollisionType::CirCle);

		DebugOn();

		//SpriteRenderer->SetActive(false);
		//CollisionComponent->SetActive(false);
	}
}

AWaddleDee::~AWaddleDee()
{
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
