#include "PreCompile.h"
#include "WaddleDee.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>

#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"
AWaddleDee::AWaddleDee()
{
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
		SpriteRenderer->ChangeAnimation("Walk_Left");


	}

	{
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, 0 });
		CollisionComponent->SetComponentScale({ 50, 50 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
		CollisionComponent->SetCollisionType(ECollisionType::CirCle);

		DebugOn();
	}
}

AWaddleDee::~AWaddleDee()
{
}

void AWaddleDee::MoveStart()
{
	
	SpriteRenderer->ChangeAnimation("Walk" + DirString);
	
}

