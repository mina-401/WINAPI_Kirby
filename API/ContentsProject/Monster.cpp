#include "PreCompile.h"
#include "Monster.h"
#include "Player.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>

#include <EngineCore/2DCollision.h>
#include "ContentsEnum.h"

AMonster::AMonster()
{
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

void AMonster::ChangeState(EMonsterState _CurMonsterState)
{
	DirCheck();
	switch (_CurMonsterState)
	{
	case EMonsterState::Move:
		MoveStart();
		break;
	case EMonsterState::Chase:
		ChaseStart();
		break;
	case EMonsterState::Attack:
		/*switch (CopyAbilityStatus)
		{
		case ECopyAbilityStatus::AbleCopy:
			break;
		case ECopyAbilityStatus::UnableCopy:
			break;
		default:
			break;
		}*/
		this->AttackStart();

		break;
	default:
		break;
	}

	CurMonsterState = _CurMonsterState;
}



void AMonster::ChangeMonsterDir(float _DeltaTime)
{
	if (false == MonsterNextPosCheck(_DeltaTime, MoveVector))
	{
		//방향 바꾸기
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
		else if (Color != UColor::WHITE)
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

	//플레이어와 일정거리에 있으면 따라간다.
	// target - me

	switch (CurMonsterState)
	{
	case EMonsterState::Move:
		Move(_DeltaTime);
		break;
	case EMonsterState::Chase:
		Chase(_DeltaTime);
		break;
	case EMonsterState::Attack:
		this->Attack(_DeltaTime);
		break;
	default:
		break;
	}
}

void AMonster::MoveStart()
{
	DirCheck();
	SpriteRenderer->ChangeAnimation("Walk" + DirString);
}

void AMonster::Move(float _DeltaTime)
{
	CheckPlayerPos();
	
	ChangeMonsterDir(_DeltaTime);
	DirCheck();
	MoveStart();

	Gravity(_DeltaTime);
	MonsterGroundCheck(GravityForce);
	UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
	if (Color == UColor::BLACK)
	{
		//경사면, 그라운드에 서있다.
		UColor NextColor = ColImage->GetColor(GetActorLocation() + FVector2D::UP, UColor::WHITE);
		if (NextColor != UColor::BLACK)
		{
			AddActorLocation(FVector2D::UP);
		}

	}
	else AddActorLocation(MoveVector * Speed * _DeltaTime);


	MonsterClimbingUphill();
}

void AMonster::MonsterClimbingUphill()
{
	while (true)
	{
		UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
		if (Color == UColor::GRAY)
		{
			// 나가 땅위로 올라갈때까지 while 계속 올려준다.
			AddActorLocation(FVector2D::UP);
		}
		else {
			break;
		}
	}
}

void AMonster::ChaseStart()
{

	DirCheck();
	SpriteRenderer->ChangeAnimation("Walk" + DirString);


}

void AMonster::Chase(float _DeltaTime)
{
	ChangeMonsterDir(_DeltaTime);
	DirCheck();
	ChaseStart();

	Gravity(_DeltaTime);
	MonsterGroundCheck(GravityForce);

	UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
	if (Color == UColor::BLACK)
	{
		//경사면, 그라운드에 서있다.
		UColor NextColor = ColImage->GetColor(GetActorLocation() + FVector2D::UP, UColor::WHITE);
		if (NextColor != UColor::BLACK)
		{
			AddActorLocation(FVector2D::UP);
		}

	}
	else {
		//  if(CurrPos)

		//FVector2D Pos = TargetPos;
		TargetPosVector.Normalize();
		MoveDirCheck(TargetPosVector); //현재 가고 있는 단위 벡터 방향

		FVector2D NextPos = MoveVector * _DeltaTime * Speed;
		AddActorLocation(NextPos);
	}

	/*if (TargetPos == GetActorLocation())
	{
		int a = 0;
	}*/
	MonsterClimbingUphill();


	//어딘가에서 플레이어가 안보이면 보통상태로
}
void AMonster::MoveDirCheck(FVector2D _Pos)
{
	if (_Pos.X > 0) {
		MoveVector = FVector2D::RIGHT;

	}
	else if (_Pos.X <= 0) {
		MoveVector = FVector2D::LEFT;
	}
}
void AMonster::AttackStart()
{
	DirCheck();
	SpriteRenderer->ChangeAnimation("Attack" + DirString);
	//SpriteRenderer->
	
}

void AMonster::Attack(float _DeltaTime)
{
	if (true == SpriteRenderer->IsCurAnimationEnd()) {
		ChangeState(EMonsterState::Move);
		return;
	}
}

void AMonster::CheckPlayerPos()
{
	AActor* Player = GetWorld()->GetPawn();
	Player = dynamic_cast<APlayer*>(Player);

	FVector2D Range = Player->GetActorLocation() - this->GetActorLocation();
	float PlayerRange = Range.Length();

	if (PlayerRange <= MonsterToPlayerRange)
	{

		TargetPosVector = Player->GetActorLocation() - GetActorLocation();
		ChangeState(EMonsterState::Chase);
		return;
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

	if (_MapScale.X  < MosterPos.X)
	{
		MosterPos.X = _MapScale.X ;
	}
	SetActorLocation(MosterPos);
}