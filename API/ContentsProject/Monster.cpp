#include "PreCompile.h"
#include "Monster.h"
#include "Player.h"
#include "MonsterWidget.h"

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
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, -20 });
		CollisionComponent->SetComponentScale({ 50, 50 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
		CollisionComponent->SetCollisionType(ECollisionType::CirCle);

		CollisionComponent->SetCollisionEnter(std::bind(&AMonster::CollisionEnter, this, std::placeholders::_1));
		//CollisionComponent->SetCollisionEnter(std::bind(&AMonster::CollisionEnd, this, std::placeholders::_1));

		DebugOn();

	}
}

AMonster::~AMonster()
{
}
void AMonster::InhalingGravity(float _DeltaTime, FVector2D _Vector)
{

	InhalingForce = _Vector * _DeltaTime * 150.0f;
	AddActorLocation(InhalingForce);
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
	case EMonsterState::Idle:
		IdleStart();
		break;
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
	case EMonsterState::Inhaled:
		InhaledStart();
		break;
	//case EMonsterState::Hurt:
		//DamagedStart();
		//break;
	case EMonsterState::Die:
		DieStart();
		break;
	case EMonsterState::KnockBack:
		KnockBackStart();
		break;
	default:
		break;
	}

	CurMonsterState = _CurMonsterState;
}


void AMonster::InhaledStart()
{
	DirCheck();
	SpriteRenderer->ChangeAnimation("Inhaled" + DirString);
}
void AMonster::Inhaled(float _DeltaTime)
{
}
void AMonster::DieStart()
{
	SetActive(false);
	MonWidget->SetActive(false);
}

void AMonster::Die(float _DeltaTime)
{
	int a = 0;
}


void AMonster::KnockBackStart()
{
	DirCheck();
	//AddActorLocation({ 0,-100 });
	SpriteRenderer->ChangeAnimation("Damaged" + DirString);
	//Destroy(1.0);

}

void AMonster::KnockBack(float _DeltaTime)
{
	if (true == MonsterKnockBackNextPosCheck(_DeltaTime, KnockBackVec))
	{
		AddActorLocation(KnockBackVec  * _DeltaTime);

	}

	if (GetCurHp() <= 0)
	{
		ChangeState(EMonsterState::Die);
	}
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
	UColor Color = ColImage->GetColor(GetActorLocation() + _Vector * _DeltaTime * Speed, UColor::WHITE);
	if (Color == UColor::BLACK)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool AMonster::MonsterKnockBackNextPosCheck(float _DeltaTime, FVector2D _Vector)
{
	UColor Color = ColImage->GetColor(GetActorLocation() + _Vector * _DeltaTime, UColor::WHITE);
	if (Color == UColor::BLACK)
	{
		return false;
	}
	else
	{
		return true;
	}
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
	MonWidget = GetWorld()->SpawnActor<AMonsterWidget>();
	MonWidget->SetOwner(this);
	MonWidget->SetActive(false);
}

void AMonster::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	//플레이어와 일정거리에 있으면 따라간다.
	// target - me
	/*if (true == IsColEnd)
	{
		if (CurHpbarTime >= 100.0f)
		{
			CurHpbarTime = 0.0f;
			IsColEnd = false;
			MonWidget->SetActive(false);

		}
		else {
			CurHpbarTime += 0.2f;
		}
	}*/

	switch (CurMonsterState)
	{
	case EMonsterState::Idle:
		Idle(_DeltaTime);
		break;
	case EMonsterState::Move:
		Move(_DeltaTime);
		break;
	case EMonsterState::Chase:
		Chase(_DeltaTime);
		break;
	case EMonsterState::Attack:
		this->Attack(_DeltaTime);
		break;
	case EMonsterState::Inhaled:
		Inhaled(_DeltaTime);
		break;

	//case EMonsterState::Hurt:
		//Damaged(_DeltaTime);
		//break;
	case EMonsterState::Die:
		Die(_DeltaTime);
		break;
	case EMonsterState::KnockBack:
		KnockBack(_DeltaTime);
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
void AMonster::IdleStart()
{
	DirCheck();
	SpriteRenderer->ChangeAnimation("Idle" + DirString);
}
void AMonster::Idle(float _DeltaTime)
{
	int a = 0;
}


void AMonster::Move(float _DeltaTime)
{
	CheckPlayerPos();
	
	ChangeMonsterDir(_DeltaTime);
	DirCheck();
	MoveStart();

	Gravity(_DeltaTime);
	MonsterGroundCheck(GravityForce);
	if (true == MonsterNextPosCheck(_DeltaTime, MoveVector))
	{
		AddActorLocation(MoveVector * Speed * _DeltaTime);
	}
	else {
		UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
		if (Color == UColor::BLACK)
		{
			FVector2D UPVector = { 0.0f,-4.5f };
			UColor NextColor = ColImage->GetColor(GetActorLocation() + UPVector, UColor::WHITE);
			if (NextColor != UColor::BLACK)
			{
				AddActorLocation(FVector2D::UP);
			}

		}
		else AddActorLocation(MoveVector * Speed * _DeltaTime);
	}

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
	//CheckPlayerPos();
	ChangeMonsterDir(_DeltaTime);
	ChaseStart();

	Gravity(_DeltaTime);
	MonsterGroundCheck(GravityForce);

	UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
	if (Color == UColor::BLACK)
	{
		//경사면, 그라운드에 서있다.
		FVector2D UPVector = { 0.0f,-4.5f };
		UColor NextColor = ColImage->GetColor(GetActorLocation() + UPVector, UColor::WHITE);
		if (NextColor != UColor::BLACK)
		{
			AddActorLocation(FVector2D::UP);
		}

	}
	else {

		//TargetPosVector.Normalize();
		MoveDirCheck(TargetPosVector); 

		FVector2D NextPos = MoveVector * _DeltaTime * Speed;
		AddActorLocation(NextPos);
	}

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
void AMonster::CollisionEnter(AActor* _ColActor)
{

	int a = 0;


}
void AMonster::ColKnockBackEnter(AActor* _ColActor)
{
	// 밀려나갈 방향
	FVector2D Vector = GetActorLocation()- _ColActor->GetActorLocation() ;
	Vector.Normalize();
	SetKnockBackForce(Vector*150.0f);

	MonWidget->SetActive(true);
	
	//데미지 받았다 
	SetIsDamagedState(true);
	
	//넉백 상태로
	ChangeState(EMonsterState::KnockBack);
}
void AMonster::CollisionStay(AActor* _ColActor)
{
	//IsColEnd = true;
}
void AMonster::CollisionEnd(AActor* _ColActor)
{
	

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