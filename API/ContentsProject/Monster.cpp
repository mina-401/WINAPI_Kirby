#include "PreCompile.h"
#include "Monster.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>

#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"

AMonster::AMonster()
{
	{
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		
		SetName("Monster");

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

AMonster::~AMonster()
{
}

void AMonster::DirCheck()
{
	if (MoveVector == FVector2D::RIGHT) {
		DirString = "_Right";
	}
	else {
		DirString = "_Left";
	}
	

}

void AMonster::ChangeState(MonsterState _CurMonsterState)
{
	switch (_CurMonsterState)
	{
	case MonsterState::Move:
		MoveStart();
		break;
	default:
		break;
	}
}

void AMonster::MoveStart()
{
	SpriteRenderer->ChangeAnimation("Walk" + DirString);
}

void AMonster::Move(float _DeltaTime)
{
	DirCheck();
	MoveStart();

	Gravity(_DeltaTime);
	MonsterGroundCheck(GravityForce);

	

	UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
	if (Color == UColor::BLACK)
	{
		UColor NextColor = ColImage->GetColor(GetActorLocation() + FVector2D::UP, UColor::WHITE);
		if (NextColor != UColor::BLACK)
		{
			AddActorLocation(FVector2D::UP);

			//갈수없는곳이다.
			
		}
		
	}
	else { AddActorLocation(MoveVector * Speed * _DeltaTime); }

	ChangeMonsterDir(_DeltaTime);
}
void AMonster::ChangeMonsterDir(float _DeltaTime)
{
	if (false == MonsterNextPosCheck(_DeltaTime, MoveVector))
	{
		//방향 바꾸기
		int a = 0;
		if (MoveVector == FVector2D::RIGHT) {
			MoveVector = FVector2D::LEFT;
		}
		else {
			MoveVector = FVector2D::RIGHT;
		}

	}
}
void AMonster::MonsterGroundCheck(FVector2D _MovePos)
{
	IsGround = false;

	if (nullptr != ColImage)
	{
		FVector2D NextPos = GetActorLocation() + _MovePos;

		UColor Color = ColImage->GetColor(NextPos, UColor::WHITE);
		if (Color == UColor::WHITE)
		{
			IsGround = false;
		}
		else if (Color == UColor::BLACK)
		{
			IsGround = true;
		}
	}
}
bool AMonster::MonsterNextPosCheck(float _DeltaTime, FVector2D _Vector)
{
	FVector2D NextPos = GetActorLocation()+ _Vector* _DeltaTime*Speed;
	UColor Color = ColImage->GetColor(NextPos, UColor::WHITE);
	if (Color == UColor::WHITE)
	{

		return true;

	}
	return false;
}
void AMonster::MonsterDirCheck()
{
	/*FVector2D NextPos = GetActorLocation() + _Vector;
	UColor Color = ColImage->GetColor(NextPos, UColor::WHITE);
	if (Color == UColor::WHITE)
	{
		AddActorLocation(_Vector * _DeltaTime * Speed);

	}*/
}
void AMonster::SetColImage(std::string_view _ColImageName)
{
	ColImage = UImageManager::GetInst().FindImage(_ColImageName);
}
void AMonster::BeginPlay()
{
	Super::BeginPlay();
}

void AMonster::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	switch (CurMonsterState)
	{
	case MonsterState::Move:
		Move(_DeltaTime);
		break;
	default:
		break;
	}
}
void AMonster::BlockMonsterPos(FVector2D _MapScale)
{
	FVector2D MosterPos = GetActorLocation();

	if (0.0f > MosterPos.X)
	{
		MosterPos.X = 0.0f;
	}
	if (0.0f > MosterPos.Y)
	{
		MosterPos.Y = 0.0f;
	}

	if (_MapScale.X - 10 < MosterPos.X)
	{
		MosterPos.X = _MapScale.X - 10;
	}
	SetActorLocation(MosterPos);
}