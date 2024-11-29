#include "PreCompile.h"
#include "Player.h"
#include "Monster.h"

#include "KirbyWidget.h"
#include "ContentsEnum.h"
#include <EngineCore/2DCollision.h>

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/ImageManager.h>
#include <EnginePlatform/EngineSound.h>
#include <EngineBase/EngineDirectory.h>
#include <EngineBase/EngineFile.h>
#include "Stage1_1GameMode.h"
#include "Stage1_2GameMode.h"
#include "Stage1_4GameMode.h"
#include "Stage1_3GameMode.h"
#include "ItemRoomBeforeBossGameMode.h"
#include "StageBossKingDededeGameMode.h"

#include "PlayerStatsManager.h"
#include "Bullet.h"
#include "FireBullet.h"
#include "FireBullet2.h"
#include "JumpStar.h"
#include "MonsterFireBullet.h"
#include "EatItem.h"
#include "KingDedede.h"
#include "MonsterBullet.h"


//전역 BGM Player
//USoundPlayer APlayer::BGMPlayer; 
APlayer::APlayer()
{

	{	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetSprite("Idle_Right.png");
		SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
		SpriteRenderer->SetComponentScale({ 270, 270 });

		SetName("Kirby");


		UImageManager::GetInst().CuttingSprite("Die.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Idle_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Idle_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Crouch_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Crouch_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Walk_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Walk_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Run_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Run_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Jump_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Jump_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("EatingJump_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("EatingJump_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Fly_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Fly_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Flying_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Flying_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FlyingDown_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FlyingDown_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Slide_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Slide_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Break_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Break_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Inhale_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Inhale_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Damaged_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Damaged_Right.png", { 128, 128 });

		UImageManager::GetInst().CuttingSprite("Eating_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Eating_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("EatingMove_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("EatingMove_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("EatingCrouch_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("EatingCrouch_Left.png", { 128, 128 });

		UImageManager::GetInst().CuttingSprite("FireIdle_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireIdle_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireRun_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireRun_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireMove_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireMove_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireCrouch_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireCrouch_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireJump_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireJump_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireFlying_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireFlying_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireSlide_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireSlide_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireBreak_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireBreak_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireAttack_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireAttack_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireExhale_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireExhale_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireDash_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireDash_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireDamaged_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireDamaged_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("FireChange.png", { 128, 128 });


		UImageManager::GetInst().CuttingSprite("AllSparkKirby_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("AllSparkKirby_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("AttackKirby_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("AttackKirby_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("SparkChange.png", { 128, 128 });




		SpriteRenderer->CreateAnimation("Idle_Left", "Idle_Left.png", 0, 2, 3.f);
		SpriteRenderer->CreateAnimation("Idle_Right", "Idle_Right.png", 0, 2, 3.f);
		SpriteRenderer->CreateAnimation("Crouch_Left", "Crouch_Left.png", 0, 1, 0.2f, false);
		SpriteRenderer->CreateAnimation("Crouch_Right", "Crouch_Right.png", 0, 1, 0.2f, false);
		SpriteRenderer->CreateAnimation("Walk_Left", "Walk_Left.png", 0, 3, 0.25f);
		SpriteRenderer->CreateAnimation("Walk_Right", "Walk_Right.png", 0, 3, 0.25f);	
		SpriteRenderer->CreateAnimation("Run_Left", "Run_Left.png", 0, 6, 0.1f);
		SpriteRenderer->CreateAnimation("Run_Right", "Run_Right.png", 0, 6, 0.1f);
		SpriteRenderer->CreateAnimation("Jump_Left", "Jump_Left.png", 0, 8, 0.1f, false);
		SpriteRenderer->CreateAnimation("Jump_Right", "Jump_Right.png", 0, 8, 0.1f, false);
		SpriteRenderer->CreateAnimation("Damaged_Left", "Damaged_Left.png", 0, 7, 0.1f, false);
		SpriteRenderer->CreateAnimation("Damaged_Right", "Damaged_Right.png", 0, 7, 0.1f, false);
		SpriteRenderer->CreateAnimation("Fly_Left", "Fly_Left.png", 0, 9, 0.1f, false);
		SpriteRenderer->CreateAnimation("Fly_Right", "Fly_Right.png", 0, 9, 0.1f, false);
		SpriteRenderer->CreateAnimation("Flying_Right", "Flying_Right.png", 0, 0, 0.1f);
		SpriteRenderer->CreateAnimation("Flying_Left", "Flying_Left.png", 0, 0, 0.1f);
		SpriteRenderer->CreateAnimation("FlyingDown_Left", "FlyingDown_Left.png", 0, 2, 0.1f, false);
		SpriteRenderer->CreateAnimation("FlyingDown_Right", "FlyingDown_Right.png", 0, 2, 0.1f, false);
		SpriteRenderer->CreateAnimation("Slide_Left", "Slide_Left.png", 0, 0, 0.5f, false);
		SpriteRenderer->CreateAnimation("Slide_Right", "Slide_Right.png", 0, 0, 0.5f, false);
		SpriteRenderer->CreateAnimation("Break_Left", "Break_Left.png", 0, 0, 0.1f, false);
		SpriteRenderer->CreateAnimation("Break_Right", "Break_Right.png", 0, 0, 0.1f, false);
		SpriteRenderer->CreateAnimation("Exhale_Left", "Inhale_Left.png", 5, 5, 0.1f, false);
		SpriteRenderer->CreateAnimation("Exhale_Right", "Inhale_Right.png", 5, 5, 0.1f, false);
		SpriteRenderer->CreateAnimation("Inhale_Left", "Inhale_Left.png", { 4,5,6,7,8,7,8,7,8,7,8,7,8,7,8,7,6,9,10,11,12 }, 0.1f,false);
		SpriteRenderer->CreateAnimation("Inhale_Right", "Inhale_Right.png", { 4,5,6,7,8,7,8,7,8,7,8,7,8,7,8,7,6,9,10,11,12 }, 0.1f,false);
		SpriteRenderer->CreateAnimation("Die", "Die.png", 0,15, 0.1f,false);


		//Eating 
		SpriteRenderer->CreateAnimation("Eating_Left", "Eating_Left.png", 5, 6, 0.1f,false);
		SpriteRenderer->CreateAnimation("Eating_Right", "Eating_Right.png", 5, 6, 0.1f);
		SpriteRenderer->CreateAnimation("EatingRun_Left", "EatingMove_Left.png", 0, 14, 0.1f);
		SpriteRenderer->CreateAnimation("EatingRun_Right", "EatingMove_Right.png", 0, 14, 0.1f);
		SpriteRenderer->CreateAnimation("EatingWalk_Left", "EatingMove_Left.png", 0, 14, 0.1f);
		SpriteRenderer->CreateAnimation("EatingWalk_Right", "EatingMove_Right.png", 0, 14, 0.1f);
		SpriteRenderer->CreateAnimation("EatingJump_Left", "EatingJump_Left.png", 0, 8, 0.1f, false);
		SpriteRenderer->CreateAnimation("EatingJump_Right", "EatingJump_Right.png", 0, 8, 0.1f, false);
		SpriteRenderer->CreateAnimation("EatingCrouch_Left", "EatingCrouch_Left.png", 0, 4, 0.2f, false);
		SpriteRenderer->CreateAnimation("EatingCrouch_Right", "EatingCrouch_Right.png", 0, 4, 0.2f, false);

		//Fire
		SpriteRenderer->CreateAnimation("FireChange", "FireChange.png", 0,0, 0.0f);
		SpriteRenderer->CreateAnimation("FireIdle_Left", "FireIdle_Left.png", 0, 7, 0.2f);
		SpriteRenderer->CreateAnimation("FireIdle_Right", "FireIdle_Right.png", 0, 2, 0.2f);
		SpriteRenderer->CreateAnimation("FireRun_Left", "FireDash_Left.png", 0, 8, 0.1f);
		SpriteRenderer->CreateAnimation("FireRun_Right", "FireDash_Right.png", 0, 8, 0.1f);
		SpriteRenderer->CreateAnimation("FireWalk_Left", "FireMove_Left.png", 0, 19, 0.05f);
		SpriteRenderer->CreateAnimation("FireWalk_Right", "FireMove_Right.png", 0, 19, 0.05f);
		SpriteRenderer->CreateAnimation("FireCrouch_Left", "FireCrouch_Left.png", 0, 7, 0.2f, false);
		SpriteRenderer->CreateAnimation("FireCrouch_Right", "FireCrouch_Right.png", 0, 7, 0.2f, false);
		SpriteRenderer->CreateAnimation("FireJump_Left", "FireJump_Left.png", 0, 9, 0.1f, false);
		SpriteRenderer->CreateAnimation("FireJump_Right", "FireJump_Right.png", 0, 9, 0.1f, false);
		SpriteRenderer->CreateAnimation("FireFly_Left", "FireFlying_Left.png", 0, 14, 0.1f, false);
		SpriteRenderer->CreateAnimation("FireFly_Right", "FireFlying_Right.png", 0, 14, 0.1f, false);
		SpriteRenderer->CreateAnimation("FireFlying_Left", "FireFlying_Left.png", 0, 14, 0.05f);
		SpriteRenderer->CreateAnimation("FireFlying_Right", "FireFlying_Right.png", 0, 14, 0.05f);
		SpriteRenderer->CreateAnimation("FireFlyingDown_Left", "FireJump_Left.png", 8, 9, 0.1f, false);
		SpriteRenderer->CreateAnimation("FireFlyingDown_Right", "FireJump_Right.png", 8, 9, 0.1f, false);
		SpriteRenderer->CreateAnimation("FireSlide_Left", "FireSlide_Left.png", 0, 4, 0.5f, false);
		SpriteRenderer->CreateAnimation("FireSlide_Right", "FireSlide_Right.png", 0, 4, 0.5f, false);
		SpriteRenderer->CreateAnimation("FireBreak_Left", "FireBreak_Left.png", 0, 1, 0.1f, false);
		SpriteRenderer->CreateAnimation("FireBreak_Right", "FireBreak_Right.png", 0, 1, 0.1f, false);
		SpriteRenderer->CreateAnimation("FireAttack_Left", "FireAttack_Left.png", { 0,1,2,3,1,2,3 }, 0.1f, true);
		SpriteRenderer->CreateAnimation("FireAttack_Right", "FireAttack_Right.png", { 0,1,2,3,1,2,3 }, 0.1f, true);
		SpriteRenderer->CreateAnimation("FireExhale_Left", "FireExhale_Left.png", 0, 2, 0.1f, false);
		SpriteRenderer->CreateAnimation("FireExhale_Right", "FireExhale_Right.png", 0, 2, 0.1f, false);
		SpriteRenderer->CreateAnimation("FireDash_Left", "FireDash_Left.png", 0, 0, 0.1f);
		SpriteRenderer->CreateAnimation("FireDash_Right", "FireDash_Right.png", 0, 0, 0.1f);
		SpriteRenderer->CreateAnimation("FireDamaged_Left", "FireDamaged_Left.png", 0, 7, 0.1f, false);
		SpriteRenderer->CreateAnimation("FireDamaged_Right", "FireDamaged_Right.png", 0, 7, 0.1f, false);

		//spark
		SpriteRenderer->CreateAnimation("SparkChange", "SparkChange.png", 0, 0, 0.4f);
		SpriteRenderer->CreateAnimation("SparkIdle_Left", "AllSparkKirby_Left.png", 0, 7, 0.2f);
		SpriteRenderer->CreateAnimation("SparkIdle_Right", "AllSparkKirby_Right.png", 0, 7, 0.2f);
		SpriteRenderer->CreateAnimation("SparkRun_Left", "AllSparkKirby_Left.png", 114,119, 0.1f,true);
		SpriteRenderer->CreateAnimation("SparkRun_Right", "AllSparkKirby_Right.png", 114,119, 0.1f, true);
		SpriteRenderer->CreateAnimation("SparkWalk_Left", "AllSparkKirby_Left.png", 96, 112, 0.05f);
		SpriteRenderer->CreateAnimation("SparkWalk_Right", "AllSparkKirby_Right.png", 96, 112, 0.05f);
		SpriteRenderer->CreateAnimation("SparkCrouch_Left", "AllSparkKirby_Left.png", 7, 14, 0.2f, false);
		SpriteRenderer->CreateAnimation("SparkCrouch_Right", "AllSparkKirby_Right.png", 7, 14, 0.2f, false);
		SpriteRenderer->CreateAnimation("SparkJump_Left", "AllSparkKirby_Left.png", 85, 94, 0.1f, false);
		SpriteRenderer->CreateAnimation("SparkJump_Right", "AllSparkKirby_Right.png", 85, 94, 0.1f, false);
		SpriteRenderer->CreateAnimation("SparkFly_Left", "AllSparkKirby_Left.png", 134, 143, 0.1f, false);
		SpriteRenderer->CreateAnimation("SparkFly_Right", "AllSparkKirby_Right.png", 134, 143, 0.1f, false);
		SpriteRenderer->CreateAnimation("SparkFlying_Left", "AllSparkKirby_Left.png", 136, 160, 0.05f);
		SpriteRenderer->CreateAnimation("SparkFlying_Right", "AllSparkKirby_Right.png", 136, 160, 0.05f);
		SpriteRenderer->CreateAnimation("SparkFlyingDown_Left", "AllSparkKirby_Left.png", 171, 179, 0.1f, false);
		SpriteRenderer->CreateAnimation("SparkFlyingDown_Right", "AllSparkKirby_Right.png", 171, 179, 0.1f, false);
		SpriteRenderer->CreateAnimation("SparkSlide_Left", "AllSparkKirby_Left.png", 80, 84, 0.5f, false);
		SpriteRenderer->CreateAnimation("SparkSlide_Right", "AllSparkKirby_Right.png", 80, 84, 0.5f, false);
		//SpriteRenderer->CreateAnimation("SparkBreak_Left", "AllSparkKirby_Left.png", 0, 1, 0.1f, false);
		//SpriteRenderer->CreateAnimation("SparkBreak_Right", "AllSparkKirby_Right.png", 0, 1, 0.1f, false);
		SpriteRenderer->CreateAnimation("SparkAttack_Left", "AttackKirby_Left.png", 0,6, 0.2f, true);
		SpriteRenderer->CreateAnimation("SparkAttack_Right", "AttackKirby_Right.png", 0,6, 0.2f, true);
		//SpriteRenderer->CreateAnimation("SparkExhale_Left", "AllSparkKirby_Left.png", 0, 2, 0.1f, false);
		//SpriteRenderer->CreateAnimation("SparkExhale_Right", "AllSparkKirby_Right.png", 0, 2, 0.1f, false);


		SpriteRenderer->ChangeAnimation("Idle_Right");

		
	}
	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, -20 });
		CollisionComponent->SetComponentScale({ 50, 50 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::PlayerBody);
		CollisionComponent->SetCollisionType(ECollisionType::CirCle);

		CollisionComponent->SetCollisionEnter(std::bind(&APlayer::CollisionEnter, this, std::placeholders::_1));
		//CollisionComponent->SetCollisionStay(std::bind(&APlayer::CollisionStay, this, std::placeholders::_1));
		//CollisionComponent->SetCollisionEnd(std::bind(&APlayer::CollisionEnd, this, std::placeholders::_1));
		
	}
	{
		InhaleRightComponent = CreateDefaultSubObject<U2DCollision>();
		InhaleRightComponent->SetComponentLocation({ 90, -20 });
		InhaleRightComponent->SetComponentScale({ 80, 60 });
		InhaleRightComponent->SetCollisionGroup(ECollisionGroup::PlayerInhaleRange);
		InhaleRightComponent->SetCollisionType(ECollisionType::Rect);

		InhaleRightComponent->SetActive(false);
	}
	{
		InhaleLeftComponent = CreateDefaultSubObject<U2DCollision>();
		InhaleLeftComponent->SetComponentLocation({ -90, -20 });
		InhaleLeftComponent->SetComponentScale({ 80, 60 });
		InhaleLeftComponent->SetCollisionGroup(ECollisionGroup::PlayerInhaleRange);
		InhaleLeftComponent->SetCollisionType(ECollisionType::Rect);

		InhaleLeftComponent->SetActive(false);
	}
}

APlayer::~APlayer()
{
}
void APlayer::BlockCameraPos(FVector2D _MapScale, FVector2D _WinSize)
{
	ULevel* CurLevel = GetWorld();
	CurLevel->SetCameraPos(GetActorLocation() - Size.Half());

	FVector2D CamPos = CurLevel->GetCameraPos();

	if (0.0f > CamPos.X)
	{
		CamPos.X = 0.0f;
	}
	if (0.0f > CamPos.Y)
	{
		CamPos.Y = 0.0f;
	}

	if (_MapScale.X < CamPos.X + _WinSize.X)
	{
		CamPos.X = (CamPos.X + _WinSize.X);
		CamPos.X -= (CamPos.X + _WinSize.X) - _MapScale.X;
	}
	if (_MapScale.Y < CamPos.Y + _WinSize.Y)
	{
		CamPos.Y = (CamPos.Y + _WinSize.Y);
		CamPos.Y -= (CamPos.Y + _WinSize.Y) - _MapScale.Y;
	}
	GetWorld()->SetCameraPos(CamPos);


	BlockPlayerPos(_MapScale);
	
}
void APlayer::SetColImage(std::string_view _ColImageName)
{
	ColImage = UImageManager::GetInst().FindImage(_ColImageName);
}

void APlayer::BeginPlay()
{
	Super::BeginPlay();



	//ABullet* Bullet = GetWorld()->SpawnActor<ABullet>();

	//CollisionComponent->SetActive(true);

	Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPivot(Size.Half() * -1.0f);
	GetWorld()->SetCameraToMainPawn(false);


	//저장되어 있는 커비 스탯 가져오기
	CurPlayerCopyState = PlayerStatsManager::GetInst().GetCopyAbilityState();
	Life = PlayerStatsManager::GetInst().GetLife();
	CurHp = PlayerStatsManager::GetInst().GetHp();

	//커비 UI 띄우기
	PlayerHud = GetWorld()->SpawnActor<AKirbyWidget>();
	PlayerHud->SetOwner(this);

	

	ChangeState(EPlayerState::Idle);
	
	//키 바인딩
	//인자를 호출할 때 넣어줌을 명시하는 것이 placeholders

	/*UEngineInput::GetInst().BindAction('A', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::LEFT));
	UEngineInput::GetInst().BindAction('D', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::RIGHT));
	UEngineInput::GetInst().BindAction('S', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::DOWN));
	UEngineInput::GetInst().BindAction('W', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::UP));*/

	DebugOn();
}


void APlayer::ChangeState(EPlayerState _CurPlayerState)
{
	switch (_CurPlayerState)
	{
	case EPlayerState::Idle:


		switch (CurPlayerCopyState)
		{
		case ECopyAbilityState::Normal:
			switch (CurPlayerEatState)
			{
			case EPlayerEatState::Normal:
				IdleStart();
				break;
			case EPlayerEatState::Eating:
				EatingIdleStart();
				break;
			default:
				break;
			}
			break;
		case ECopyAbilityState::Spark:
			SparkIdleStart();
			break;
		case ECopyAbilityState::Beam:
			break;
		case ECopyAbilityState::Fire:
			
			FireIdleStart();
			break;
		default:
			break;
		}

		break;




		//볼빵빵 상태는 crouch 안된다.
	case EPlayerState::Crouch:
		switch (CurPlayerCopyState)
		{
		case ECopyAbilityState::Normal:
			switch (CurPlayerEatState)
			{
			case EPlayerEatState::Normal:
				CrouchStart();

				break;
			case EPlayerEatState::Eating:
				EatingCrouchStart();
				break;
			default:
				break;
			}
			break;
		case ECopyAbilityState::Spark:
			
			SparkCrouchStart();
			break;
		case ECopyAbilityState::Beam:
			break;
		case ECopyAbilityState::Fire:
			FireCrouchStart();
			break;
		default:
			break;
		}
		break;

	case EPlayerState::Move:
		switch (CurPlayerCopyState)
		{
		case ECopyAbilityState::Normal:
			switch (CurPlayerEatState)
			{
			case EPlayerEatState::Normal:
				MoveStart();
				break;
			case EPlayerEatState::Eating:
				EatingMoveStart();
				break;
			default:
				break;
			}
			break;
		case ECopyAbilityState::Spark:
			SparkMoveStart();
			break;
		case ECopyAbilityState::Beam:
			break;
		case ECopyAbilityState::Fire:
			FireMoveStart();
			break;
		default:
			break;
		}
		break;

	case EPlayerState::Dash:

		switch (CurPlayerCopyState)
		{
		case ECopyAbilityState::Normal:
			
			switch (CurPlayerEatState)
			{
			case EPlayerEatState::Normal:
				DashStart();
				break;
			case EPlayerEatState::Eating:
				EatingDashStart();
				break;
			default:
				break;
			}
			break;

		case ECopyAbilityState::Spark:
			SparkDashStart();
			break;

		case ECopyAbilityState::Beam:
			break;

		case ECopyAbilityState::Fire:
			FireDashStart();
			break;

		default:
			break;

		}
		
		break;


	case EPlayerState::Break:

		switch (CurPlayerCopyState)
		{
		case ECopyAbilityState::Normal:
			BreakStart();
			break;
		case ECopyAbilityState::Spark:

			break;
		case ECopyAbilityState::Beam:
			break;
		case ECopyAbilityState::Fire:
			FireBreakStart();
			break;
		default:
			break;
		}
		break;



	case EPlayerState::Jump:
		switch (CurPlayerCopyState)
		{
		case ECopyAbilityState::Normal:
			switch (CurPlayerEatState)
			{
			case EPlayerEatState::Normal:
				JumpStart();
				break;
			case EPlayerEatState::Eating:
				EatingJumpStart();
				break;
			default:
				break;
			}
			break;

		case ECopyAbilityState::Spark:
			SparkJumpStart();
			break;
		case ECopyAbilityState::Beam:
			break;
		case ECopyAbilityState::Fire:
			FireJumpStart();
			break;
		default:
			break;
		}

		break;



		//볼빵빵은 안들어옴
	case EPlayerState::Fly:

		switch (CurPlayerCopyState)
		{
		case ECopyAbilityState::Normal:
			FlyStart();

			break;
		case ECopyAbilityState::Spark:
			SparkFlyStart();
			break;
		case ECopyAbilityState::Beam:
			break;
		case ECopyAbilityState::Fire:
			FireFlyStart();
			break;
		default:
			break;
		}
		break;




	case EPlayerState::FlyDown:

		switch (CurPlayerCopyState)
		{
		case ECopyAbilityState::Normal:
			FlyDownStart();
			break;
		case ECopyAbilityState::Spark:
			SparkFlyDownStart();
			break;
		case ECopyAbilityState::Beam:
			break;
		case ECopyAbilityState::Fire:
			FireFlyDownStart();
			break;
		default:
			break;
		}

		break;




	case EPlayerState::Slide:

		switch (CurPlayerCopyState)
		{
		case ECopyAbilityState::Normal:
			SlideStart();
			break;
		case ECopyAbilityState::Spark:
			SparkSlideStart();
			break;
		case ECopyAbilityState::Beam:
			break;
		case ECopyAbilityState::Fire:
			FireSlideStart();
			break;
		default:
			break;
		}
		
		//
		break;




	case EPlayerState::Inhale:

		switch (CurPlayerCopyState)
		{
		case ECopyAbilityState::Normal:
			InhaleStart();
			break;
		case ECopyAbilityState::Spark:

			break;
		case ECopyAbilityState::Beam:
			break;
		case ECopyAbilityState::Fire:
			
			break;
		default:
			break;
		}

		break;
	case EPlayerState::Exhale:
		ExhaleStart();
		break;
	//copy 상태일 때만 상태 변경
	case EPlayerState::Attack:
		switch (CurPlayerCopyState)
		{
		case ECopyAbilityState::Normal:
			break;
		case ECopyAbilityState::Fire:
			FireAttackStart();

			break;
		case ECopyAbilityState::Spark:
			SparkAttackStart();
			break;
		case ECopyAbilityState::Beam:
			break;
		default:
			break;
		}
		break;

	case EPlayerState::KnockBack:
		CreateJumpStar();
		KnockBackStart();


		break;

	case EPlayerState::Die:
		DieStart();
		break;

	case EPlayerState::Change:
		switch (CurPlayerCopyState)
		{
		case ECopyAbilityState::Normal:
			//ChangeStart();
			break;
		case ECopyAbilityState::Fire:
			FireChangeStart();

			break;
		case ECopyAbilityState::Spark:
			SparkChangeStart();
			break;
		case ECopyAbilityState::Beam:
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}
	



	CurPlayerState = _CurPlayerState;

}
void APlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	//int CurLife= PlayerStatsManager::GetInst().GetLife();

	
	if (Life <= 0 && GetCurHp() <= 0)
	{
		
	}

	else if (GetCurHp() <= 0 )
	{
		if (CurPlayerState != EPlayerState::Die)
		{
			ChangeState(EPlayerState::Die);

		}//return;
	}


	if (CurPlayerColl == ECollisionGroup::PlayerInvincible)
	{
		if (CurColTime > ColTime)
		{
			CurColTime = 0.0f;
			SetPlayerColl(ECollisionGroup::PlayerBody);
			CollisionComponent->SetCollisionGroup(ECollisionGroup::PlayerBody);
		}
		CurColTime += 0.2f;

	}

	if (CurPlayerCopyState != PlayerStatsManager::GetInst().GetCopyAbilityState())
	{
		PlayerStatsManager::GetInst().SetCopyAbilityState(CurPlayerCopyState);
	}

	if (Life != PlayerStatsManager::GetInst().GetLife())
	{
		PlayerStatsManager::GetInst().SetLife(Life);
	}
	if (CurHp != PlayerStatsManager::GetInst().GetHp())
	{
		PlayerStatsManager::GetInst().SetHp(CurHp);
	}



	if (true == UEngineInput::GetInst().IsDown(VK_F2))
	{
		UEngineDebug::SwitchIsDebug();
	}

	if (true == UEngineInput::GetInst().IsDown(VK_F3))
	{
		//BGMPlayer.OnOffSwtich();

	}
	if (true == UEngineInput::GetInst().IsDown(VK_F3))
	{

		//UEngineAPICore::GetCore()->ResetLevel<, ANewPlayer>("Play");
		//UEngineAPICore::GetCore()->OpenLevel("Play");
	}

	
	UEngineDebug::CoreOutPutString("FPS : " + std::to_string(1.0f / _DeltaTime));
	UEngineDebug::CoreOutPutString("PlayerPos : " + GetActorLocation().ToString());

	/*FTransform PlayerTransform = GetTransform();
	PlayerTransform.Location += FVector2D(20, 0) - GetWorld()->GetCameraPos();
	PlayerTransform.Scale = { 6,6 };
	UEngineDebug::CoreDebugRender(PlayerTransform, UEngineDebug::EDebugPosType::Circle);*/

	DirCheck();

	switch (CurPlayerState)
	{
	case EPlayerState::Idle:
		Idle(_DeltaTime);
		break;
	case EPlayerState::Crouch:
		Crouch(_DeltaTime);
		break;
	case EPlayerState::Move:
		Move(_DeltaTime);
		break;
	case EPlayerState::Dash:
		Dash(_DeltaTime);
		break;
	case EPlayerState::Break:
		Breaking(_DeltaTime);
		break;
	case EPlayerState::Jump:
		Jump(_DeltaTime);
		break;
	case EPlayerState::Fly:
		Fly(_DeltaTime);
		break;
	case EPlayerState::FlyDown:
		FlyDown(_DeltaTime);
		break;
	case EPlayerState::Slide:
		Slide(_DeltaTime);
		break;
	case EPlayerState::Inhale:
		Inhale(_DeltaTime);
		break;
	case EPlayerState::Exhale:
		Exhale(_DeltaTime);
		break;
	case EPlayerState::Attack:
		Attack(_DeltaTime);
		break;
	case EPlayerState::KnockBack:
		KnockBack(_DeltaTime);
		break;
	case EPlayerState::Die:
		Die(_DeltaTime);
		break;
	case EPlayerState::Change:
		Change(_DeltaTime);
		break;
	default:
		break;
	}
	

}

void APlayer::DirCheck()
{

	if (true == UEngineInput::GetInst().IsPress(VK_LEFT) && true == UEngineInput::GetInst().IsPress(VK_RIGHT)) { 
		if (CurPlayerState == EPlayerState::Dash) {
			ChangeState(EPlayerState::Break);
			return; 
		}
		
		else return;
	
	}
	if (true == UEngineInput::GetInst().IsPress(VK_LEFT))
	{
		DirString = "_Left";
	}
	else if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))
	{
		DirString = "_Right";
	}
}

void APlayer::LevelChangeStart()
{
	Super::LevelChangeStart();
}

void APlayer::LevelChangeEnd()
{
	Super::LevelChangeEnd();
}

void APlayer::KnockBackStart()
{
	if (nullptr != ColBullet)
	{
		FireKnockBackStart();
		ColBullet = nullptr;
		return;
	}
	DirCheck();
	CurPlayerCopyState = ECopyAbilityState::Normal;

	SpriteRenderer->SetComponentScale({ 270,270 });
	SpriteRenderer->ChangeAnimation("Damaged" + DirString);
	CollisionComponent->SetActive(false);
	AlphaTime = 1.f;


}
void APlayer::FireKnockBackStart()
{
	DirCheck();
	CurPlayerCopyState = ECopyAbilityState::Normal;

	SpriteRenderer->SetComponentScale({ 270,270 });
	SpriteRenderer->ChangeAnimation("FireDamaged" + DirString);
	CollisionComponent->SetActive(false);
}
void APlayer::KnockBack(float _DeltaTime)
{
	AlphaTime -= _DeltaTime;

	// Gravity(_DeltaTime);


	if (AlphaTime > 0.f)
	{
		SpriteRenderer->SetAlphafloat(AlphaVar);
		AlphaVar = 1.f - AlphaVar;
	}
	if (true == SpriteRenderer->IsCurAnimationEnd() && GetCurHp()>0 )
	{
		CollisionComponent->SetActive(true);

		ChangeState(EPlayerState::Idle);
		return;
	}
	if (0>=GetCurHp() && true==SpriteRenderer->IsCurAnimationEnd())
	{
		CollisionComponent->SetActive(true);

		ChangeState(EPlayerState::Die);
		return;
	}
	if (true == PlayerKnockBackNextPosCheck(_DeltaTime, KnockBackVec))
	{

		AddActorLocation(KnockBackVec * _DeltaTime);



	}
	//while (true)
	//{
	//	UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
	//	if (Color == UColor::GRAY)
	//	{
	//		// 나가 땅위로 올라갈때까지 while 계속 올려준다.
	//		AddActorLocation(FVector2D::UP * Speed * _DeltaTime);
	//	}
	//	else {
	//		break;
	//	}
	//}

}
void APlayer::DieStart()
{
	Life -= 1;

	if (0 >= Life) {
		GravityForce = FVector2D::ZERO;
		SpriteRenderer->ChangeAnimation("Die");
	}
	if (0 < Life)
	{
		CurHp = GetMaxHp(); // 생명이 남아 있다. 다시 풀피도 채운다.
	}
	
}
void APlayer::Die(float _DeltaTime)
{
	
	// 리셋 레벨은 hp가 0보다 작을때 실행된다.
	if (true == SpriteRenderer->IsCurAnimationEnd())
	{
		CollisionComponent->SetActive(true);

		AGameMode* gm = GetWorld()->GetGameMode<AGameMode>();
		if (gm == nullptr) return;

		if ("Stage1_1" == gm->GetName()) {

			UEngineAPICore::GetCore()->ResetLevel<AStage1_1GameMode, APlayer>(gm->GetName());
		}
		else if ("Stage1_2" == gm->GetName()) {

			UEngineAPICore::GetCore()->ResetLevel<AStage1_2GameMode, APlayer>(gm->GetName());
		}
		else if ("Stage1_3" == gm->GetName()) {

			UEngineAPICore::GetCore()->ResetLevel<AStage1_3GameMode, APlayer>(gm->GetName());
		}
		/*else if ("Stage1_4" == gm->GetName()) {

			UEngineAPICore::GetCore()->ResetLevel<AStage1_4GameMode, APlayer>(gm->GetName());
		}*/

		else if ("ItemRoomBeforeBoss" == gm->GetName()) {

			UEngineAPICore::GetCore()->ResetLevel<AItemRoomBeforeBossGameMode, APlayer>(gm->GetName());
		}
		else if ("StageBossKingDedede" == gm->GetName()) {

			UEngineAPICore::GetCore()->ResetLevel<AStageBossKingDededeGameMode, APlayer>(gm->GetName());
		}
	}
	
	
	JumpGravity(_DeltaTime);
	AddActorLocation(JumpPower*_DeltaTime);
		
	
}

void APlayer::FireAttackStart()
{
	Speed = 300.0f;

	if (true == BGMPlayer.IsPlaying())
	{
		BGMPlayer.Stop();
	}
	BGMPlayer = UEngineSound::Play("AttackFire.WAV");

	SpriteRenderer->SetComponentScale({ 270,270 });
	SpriteRenderer->ChangeAnimation("FireAttack" + DirString);
	{
		InhaleRightComponent->SetComponentLocation({ 90, -20 });
		InhaleRightComponent->SetComponentScale({ 80, 60 });
		InhaleRightComponent->SetCollisionType(ECollisionType::Rect);
	}
	{
		InhaleLeftComponent->SetComponentLocation({ -90, -20 });
		InhaleLeftComponent->SetComponentScale({ 80, 60 });
		InhaleLeftComponent->SetCollisionType(ECollisionType::Rect);
	}
	{
		AFireBullet* Bullet = GetWorld()->SpawnActor<AFireBullet>();
		//AFireBullet2* Bullet = GetWorld()->SpawnActor<AFireBullet2>();
		Bullet->SetActorLocation(GetActorLocation());
		Bullet->SetMainPawn(this);
	}
}
void APlayer::SparkAttackStart()
{
	Speed = 300.0f;
	if (true == BGMPlayer.IsPlaying())
	{
		BGMPlayer.Stop();
	}
	//BGMPlayer = UEngineSound::Play("AttackSpark.WAV");

		BGMPlayer = UEngineSound::Play("AttackSpark.WAV");
		BGMPlayer.Loop(1);
	

	SpriteRenderer->ChangeAnimation("SparkAttack" + DirString);
	{
		InhaleRightComponent->SetComponentLocation({ 0, 0 });
		InhaleRightComponent->SetComponentScale({ 100, 100 });
		InhaleRightComponent->SetCollisionType(ECollisionType::CirCle);
	}
	{
		InhaleLeftComponent->SetComponentLocation({ 0, 0 });
		InhaleLeftComponent->SetComponentScale({ 100, 100 });
		InhaleLeftComponent->SetCollisionType(ECollisionType::CirCle);
	}

	
}
void APlayer::Attack(float _DeltaTime)
{
	DirCheck();

	
	if (true == SpriteRenderer->IsCurAnimationEnd())
	{
		if (true == BGMPlayer.IsPlaying())
		{
			BGMPlayer.Stop();
		}

		//ColMonster = nullptr;
		InhaleRightComponent->SetActive(false);
		InhaleLeftComponent->SetActive(false);
		ChangeState(EPlayerState::Idle);
		return;
	}

	FVector2D Vector = FVector2D::ZERO;
	if (true == UEngineInput::GetInst().IsUp('X'))
	{
		//ColMonster = nullptr;
		InhaleRightComponent->SetActive(false);
		InhaleLeftComponent->SetActive(false);

		ChangeState(EPlayerState::Idle);
		return;
	}
	AActor* ColActor = nullptr;
	if (DirString == "_Right")
	{
		InhaleRightComponent->SetActive(true);
		ColActor = InhaleRightComponent->CollisionOnce(ECollisionGroup::MonsterBody);
		Vector = FVector2D::RIGHT;
	}
	else if (DirString == "_Left")
	{
		InhaleLeftComponent->SetActive(true);
		ColActor = InhaleLeftComponent->CollisionOnce(ECollisionGroup::MonsterBody);
		Vector = FVector2D::LEFT;
	}

	if (ColActor != nullptr) {

		AMonster* Target = dynamic_cast<AMonster*>(ColActor);

		Target->ColKnockBackEnter(this);

		//AFireBullet* NewFireBullet = GetWorld()->SpawnActor<AFireBullet>();
		//BulletVector.push_back(NewFireBullet);

		//Monster->ChangeState(EMonsterState::KnockBack);

	}
}
void APlayer::AttackStartAnim()
{
	switch (CurPlayerCopyState)
	{
	case ECopyAbilityState::Normal:
		break;
	case ECopyAbilityState::Fire:
		FireAttackStart();
		break;
	case ECopyAbilityState::Spark:
		SparkAttackStart();
		break;
	case ECopyAbilityState::Beam:
		break;
	default:
		break;
	}
}
void APlayer::IdleStart()
{
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("Idle" + DirString);

	SpriteRenderer->SetAlphafloat(1.0f);

}
void APlayer::FireIdleStart()
{
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("FireIdle" + DirString);
	SpriteRenderer->SetComponentScale({ 270,270 });

}
void APlayer::EatingIdleStart()
{
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("Eating" + DirString);

}
void APlayer::SparkIdleStart()
{
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("SparkIdle" + DirString);

}
void APlayer::Idle(float _DeltaTime)
{

	PlayerGroundCheck(GravityForce);
	Gravity(_DeltaTime);


	PlayerKnockBack();
	if (true == UEngineInput::GetInst().IsPress(VK_LEFT) ||
		true == UEngineInput::GetInst().IsPress(VK_RIGHT))
	{ 
		ChangeState(EPlayerState::Move);
	}

	if (true == UEngineInput::GetInst().IsDoubleClick(VK_RIGHT, 0.5f)|| true == UEngineInput::GetInst().IsDoubleClick(VK_LEFT, 0.5f))
	{
		ChangeState(EPlayerState::Dash);
		return;
	}

	if (true == UEngineInput::GetInst().IsPress('Z'))
	{
		ChangeState(EPlayerState::Jump);
		return;
	}

	if (true == UEngineInput::GetInst().IsDown('X'))
	{

		ChangeIdleStateByCopy('X');		
		return;
	}
	if (true == UEngineInput::GetInst().IsDown('A'))
	{
		ChangeIdleStateByCopy('A');
		return;
	}
	if (true == UEngineInput::GetInst().IsPress(VK_DOWN))
	{
		ChangeIdleStateByCopy(VK_DOWN);
		return;
	}
}



void APlayer::CrouchStart()
{
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("Crouch" + DirString);
}
void APlayer::FireCrouchStart()
{
	Speed = 300.0f;
	SpriteRenderer->SetComponentScale({ 270,270 });



	SpriteRenderer->ChangeAnimation("FireCrouch" + DirString);
}
void APlayer::SparkCrouchStart()
{

	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("SparkCrouch" + DirString);
}
void APlayer::EatingCrouchStart()
{
	if (true == BGMPlayer.IsPlaying())
	{
		BGMPlayer.Stop();
	}
	BGMPlayer = UEngineSound::Play("Kirby Eating Down.WAV");
	Speed = 300.0f;
	CurPlayerEatState = EPlayerEatState::Normal;

	AJumpStar* Star = dynamic_cast<AJumpStar*>(ColAnyActor);
	if (Star != nullptr)
	{
		CurPlayerCopyState = Star->GetCopyState();


	}

	/*AMonsterBullet* MonStar = dynamic_cast<AMonsterBullet*>(ColAnyActor);
	if (MonStar != nullptr)
	{
		CurPlayerCopyState = MonStar->GetCopyState();

	}*/
	AMonster* Mon = dynamic_cast<AMonster*>(ColAnyActor);
	if (Mon != nullptr)
	{

		CurPlayerCopyState = Mon->GetCopyAbilityState();

	}

	AEatItem* Item = dynamic_cast<AEatItem*>(ColAnyActor);
	if (Item != nullptr)
	{
		BGMPlayer = UEngineSound::Play("Kirby Copy Change.WAV");
		CurPlayerCopyState = Item->GetCopyState();

	}
	SpriteRenderer->ChangeAnimation("EatingCrouch" + DirString);

}

void APlayer::Crouch(float _DeltaTime)
{
	DirCheck();
	//CrouchStartAnim();

	if (true == UEngineInput::GetInst().IsPress('Z'))
	{
		ChangeState(EPlayerState::Slide);
		return;
	}
	if (true == UEngineInput::GetInst().IsFree(VK_DOWN))
	{

		if (false == IsChange)
		{
			if (true == SpriteRenderer->IsCurAnimationEnd())
			{
				//여기서 ㅜ> copy 있는  상태로 변환하면 change 
				//
				ChangeState(EPlayerState::Change);
				//BGMPlayer = UEngineSound::Play("Kirby Copy Change.WAV");
				IsChange = true;
				return;

			}
		}
		else {
			if (true == SpriteRenderer->IsCurAnimationEnd())
			{
			
				ChangeState(EPlayerState::Idle);
				//BGMPlayer = UEngineSound::Play("Kirby Copy Change.WAV");
				return;

			}
		}

		
	}
}
void APlayer::ChangeStart()
{
	//UEngineAPICore::GetCore()->SetGlobalTimeScale(1.0f);
	//ChangeState(EPlayerState::Idle);
	//return;
}
void APlayer::FireChangeStart()
{

	BGMPlayer = UEngineSound::Play("Kirby Copy Change.WAV");
	UEngineAPICore::GetCore()->SetGlobalTimeScale(0.0f);
	SpriteRenderer->ChangeAnimation("FireChange");

}
void APlayer::SparkChangeStart()
{
	BGMPlayer = UEngineSound::Play("Kirby Copy Change.WAV");
	UEngineAPICore::GetCore()->SetGlobalTimeScale(0.0f);
	SpriteRenderer->ChangeAnimation("SparkChange");
}
void APlayer::Change(float _DeltaTime)
{

	if (CurChangeTime > ChangeTime)
	{
		UEngineAPICore::GetCore()->SetGlobalTimeScale(1.0f);
		if (true == SpriteRenderer->IsCurAnimationEnd())
		{
			CurChangeTime = 0.0f;
			
			ChangeState(EPlayerState::Idle);
		}
	}
	CurChangeTime += 0.05f;

	
	if (true == SpriteRenderer->IsCurAnimationEnd())
	{

		ChangeState(EPlayerState::Idle);
	}
}
void APlayer::CrouchStartAnim()
{
	switch (CurPlayerCopyState)
	{
	case ECopyAbilityState::Normal:
		CrouchStart();

		break;
	case ECopyAbilityState::Spark:
		SparkCrouchStart();
		break;
	case ECopyAbilityState::Beam:
		break;
	case ECopyAbilityState::Fire:
		FireCrouchStart();
		break;
	default:
		break;
	}
}

bool APlayer::PlayerNextPosCheck(float _DeltaTime, FVector2D _Vector)
{
	UColor Color = ColImage->GetColor(GetActorLocation() + _Vector * _DeltaTime*Speed, UColor::WHITE);
	if (Color != UColor::WHITE)
	{
		return false;
	}
	else
	{
		return true;
	}

}

bool APlayer::PlayerKnockBackNextPosCheck(float _DeltaTime, FVector2D _Vector)
{
	FVector2D Vector = { 0,-1 };


	UColor Color = ColImage->GetColor(GetActorLocation() + _Vector * _DeltaTime + Vector, UColor::WHITE);
	if (Color != UColor::WHITE)
	{
		return false;
	}
	else
	{
		return true;
	}

}

void APlayer::EatingJumpStart()
{
	BGMPlayer = UEngineSound::Play("Kirby Jump.WAV");

	GravityForce = FVector2D::ZERO;
	Speed = 150.0f;
	SpriteRenderer->ChangeAnimation("EatingJump" + DirString);
}
void APlayer::JumpStart()
{
	BGMPlayer = UEngineSound::Play("Kirby Jump.WAV"); 
	GravityForce = FVector2D::ZERO;
	Speed = 300.0f;

	SpriteRenderer->ChangeAnimation("Jump"+DirString);
}
void APlayer::SparkJumpStart()
{
	BGMPlayer = UEngineSound::Play("Kirby Jump.WAV");

	GravityForce = FVector2D::ZERO;
	Speed = 300.0f;

	SpriteRenderer->ChangeAnimation("SparkJump" + DirString);
}
void APlayer::FireJumpStart()
{
	BGMPlayer = UEngineSound::Play("Kirby Jump.WAV");

	GravityForce = FVector2D::ZERO;
	Speed = 300.0f;
	SpriteRenderer->SetComponentScale({ 270,270 });
	SpriteRenderer->ChangeAnimation("FireJump" + DirString);
}
void APlayer::ChangeJumpStateByEat(int _KeyIndx,bool _IsFly) {

	if (true == _IsFly) {
		switch (_KeyIndx)
		{
		case 'Z':
			switch (CurPlayerEatState)
			{
			case EPlayerEatState::Normal:
				ChangeState(EPlayerState::Fly);
				break;
			case EPlayerEatState::Eating:

				break;
			default:
				break;
			}
			break;

		default:
			break;
		}
	}
	
}
void APlayer::Jump(float _DeltaTime)
{
	DirCheck();

	PlayerKnockBack();

	PlayerGroundCheck(GravityForce);
	JumpGravity(_DeltaTime);
	AddActorLocation(JumpPower*_DeltaTime);

	FVector2D Vector = FVector2D::ZERO;

	if (true == UEngineInput::GetInst().IsPress(VK_LEFT)) Vector += FVector2D::LEFT;
	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))  Vector += FVector2D::RIGHT;
	if (true == UEngineInput::GetInst().IsPress('Z') && true == IsFly) {

		ChangeJumpStateByEat('Z', IsFly);
		return;
	}

	//다음 위치로 갈 수 있다.
	if (true == PlayerNextPosCheck(_DeltaTime, Vector))
	{
		AddActorLocation(Vector  * _DeltaTime * 150.0f);
	}

	/*UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
	if (Color == UColor::BLACK)
	{
		UColor NextColor = ColImage->GetColor(GetActorLocation() + FVector2D::UP, UColor::WHITE);
		if (NextColor != UColor::BLACK)
		{
			AddActorLocation(FVector2D::UP);
		}

	}*/
	PlayerFlyCheck();
	if (true == IsGround)
	{
		ChangeState(EPlayerState::Idle);
		return;
	}
}


void APlayer::MoveStart()
{
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("Walk" + DirString);

}
void APlayer::FireMoveStart()
{
	Speed = 300.0f;
	SpriteRenderer->SetComponentScale({ 270,270 });
	SpriteRenderer->ChangeAnimation("FireWalk" + DirString);
}
void APlayer::SparkMoveStart()
{
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("SparkWalk" + DirString);

}

void APlayer::EatingMoveStart()
{
	Speed = 150.0f;
	SpriteRenderer->ChangeAnimation("EatingWalk" + DirString);
}



void APlayer::ChangeMoveStateByCopy(int _KeyIndex)
{
	switch (_KeyIndex)
	{
	case 'X':
		switch (CurPlayerCopyState)
		{
		case ECopyAbilityState::Normal:
			switch (CurPlayerEatState)
			{
			case EPlayerEatState::Normal:
				ChangeState(EPlayerState::Inhale);
				break;
			case EPlayerEatState::Eating:
				CurPlayerEatState = EPlayerEatState::Normal;
				ChangeState(EPlayerState::Exhale);
				break;
			default:
				break;
			}
			break;
		case ECopyAbilityState::Spark:
			ChangeState(EPlayerState::Attack);

			break;
		case ECopyAbilityState::Beam:
			break;
		case ECopyAbilityState::Fire:
			ChangeState(EPlayerState::Attack);

			//CurPlayerCopyState = ECopyAbilityState::Normal;
			//ChangeState(EPlayerState::Idle);
			
			break;
		default:
			break;
		}
		break;
	case 'A':
		switch (CurPlayerCopyState)
		{
		case ECopyAbilityState::Normal:
			ChangeState(EPlayerState::Idle);
			break;
		case ECopyAbilityState::Spark:
			CurPlayerCopyState = ECopyAbilityState::Normal;
			ChangeState(EPlayerState::Idle);
			break;
		case ECopyAbilityState::Beam:
			CurPlayerCopyState = ECopyAbilityState::Normal;
			ChangeState(EPlayerState::Idle);
			break;
		case ECopyAbilityState::Fire:

			CreateJumpStar();
			CurPlayerCopyState = ECopyAbilityState::Normal;
			ChangeState(EPlayerState::Idle);
			//능력뱉기
			break;
		default:
			break;
		}

	break;

	default:
		break;
	}
}
void APlayer::CreateJumpStar()
{
	switch (CurPlayerCopyState)
	{
	case ECopyAbilityState::Normal:
		return;
		break;
	case ECopyAbilityState::Fire:
		//Dash 상태에서 벽 부딪혔다.
		if (true == IsFireDashState) return;
		break;
	case ECopyAbilityState::Spark:
		break;
	case ECopyAbilityState::Beam:
		break;
	default:
		break;
	}
	AJumpStar* Star = GetWorld()->SpawnActor<AJumpStar>();
	Star->SetActorLocation(GetActorLocation());
	Star->SetMainPawn(this);
	Star->SetCopyState(CurPlayerCopyState);
	
}
void APlayer::Move(float _DeltaTime)
{
	DirCheck();
	PlayerGroundCheck(GravityForce);
	//DownHillGravity(_DeltaTime);
	Gravity(_DeltaTime);
	
	PlayerKnockBack();


	FVector2D Vector = FVector2D::ZERO;
	
	if (true == UEngineInput::GetInst().IsPress(VK_DOWN))
	{
		Vector += FVector2D::DOWN;
	}
	if (true == UEngineInput::GetInst().IsPress(VK_LEFT))
	{
		 Vector += FVector2D::LEFT;
	}
	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))
	{
		Vector += FVector2D::RIGHT;
	}
	if (true == UEngineInput::GetInst().IsDown('Z') && true == UEngineInput::GetInst().IsPress(VK_DOWN))
	{
		ChangeState(EPlayerState::Slide);
		return;
	}
	if (true == UEngineInput::GetInst().IsPress('Z'))
	{
		ChangeState(EPlayerState::Jump);
		return;
	}
	 if (true == UEngineInput::GetInst().IsPress('X'))
	 {
		 ChangeMoveStateByCopy('X');
		 return;
	 }
	 if (true == UEngineInput::GetInst().IsDown('A'))
	 {
		 ChangeMoveStateByCopy('A');
		 return;
	 }
	if (true == UEngineInput::GetInst().IsPress(VK_DOWN))
	{
		ChangeState(EPlayerState::Crouch);
		return;
	}
	if (true == UEngineInput::GetInst().IsDoubleClick(VK_RIGHT, 0.5f))
	{

		ChangeState(EPlayerState::Dash);
		return;
	}
	
	if (false == UEngineInput::GetInst().IsPress(VK_LEFT) &&
		false == UEngineInput::GetInst().IsPress(VK_RIGHT) &&
		false == UEngineInput::GetInst().IsPress(VK_DOWN))
	{
		ChangeState(EPlayerState::Idle);
		return;
	}
	if (true == PlayerNextPosCheck(_DeltaTime, Vector))
	{
		AddActorLocation(Vector * Speed * _DeltaTime);
	}
	else {
		UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
		if (Color == UColor::BLACK)
		{
			UColor NextColor = ColImage->GetColor(GetActorLocation() + FVector2D::UP * Speed * _DeltaTime, UColor::WHITE);
			if (NextColor != UColor::BLACK)
			{
				AddActorLocation(FVector2D::UP * Speed * _DeltaTime);
			}

		}
		else AddActorLocation(Vector * Speed * _DeltaTime);
	}
	


	while (true)
	{
		UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
		if (Color == UColor::GRAY)
		{
			// 나가 땅위로 올라갈때까지 while 계속 올려준다.
			AddActorLocation(FVector2D::UP*Speed * _DeltaTime);
		}
		else {
			break;
		}
	}
	
	
}



void APlayer::BreakStart()
{
	//speed=0?
	SpriteRenderer->ChangeAnimation("Break" + DirString);
	

}
void APlayer::FireBreakStart()
{
	SpriteRenderer->SetComponentScale({ 270,270 });
	SpriteRenderer->ChangeAnimation("FireBreak" + DirString);
}
void APlayer::Breaking(float _DeltaTime)
{
	PlayerGroundCheck(GravityForce );
	Gravity(_DeltaTime);
	FVector2D Vector = FVector2D::ZERO;

	if (true == UEngineInput::GetInst().IsPress(VK_LEFT))
	{
		Vector += FVector2D::LEFT;

	}
	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))
	{

		Vector += FVector2D::RIGHT;
	}
	AddActorLocation(Vector * _DeltaTime * BreakTime);

	if (true == SpriteRenderer->IsCurAnimationEnd())
	{

		ChangeState(EPlayerState::Idle);
		return;
	}
}
void APlayer::EatingDashStart()
{
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("EatingRun" + DirString);
}
void APlayer::FireDashStart()
{
	SpriteRenderer->SetComponentScale({ 180,180 });

	SpriteRenderer->ChangeAnimation("FireRun" + DirString);
	Speed = 500.0f;
}
void APlayer::SparkDashStart()
{
	SpriteRenderer->ChangeAnimation("SparkRun" + DirString);
	Speed = 500.0f;
}
void APlayer::DashStart()
{
	SpriteRenderer->ChangeAnimation("Run" + DirString);
	Speed = 500.0f;

	
	//SpriteRenderer->SetSpriteScale(0.1f);

}
void APlayer::ChangeDashStateByCopy(int _KeyIndex)
{
	switch (_KeyIndex)
	{
	case 'X':
		switch (CurPlayerCopyState)
		{
		case ECopyAbilityState::Normal:
			switch (CurPlayerEatState)
			{
			case EPlayerEatState::Normal:
				ChangeState(EPlayerState::Inhale);
				break;
			case EPlayerEatState::Eating:
				CurPlayerEatState = EPlayerEatState::Normal;
				ChangeState(EPlayerState::Exhale);
				break;
			default:
				break;
			}
			break;
		case ECopyAbilityState::Spark:
			ChangeState(EPlayerState::Attack);

			break;
		case ECopyAbilityState::Beam:
			ChangeState(EPlayerState::Attack);

			break;
		case ECopyAbilityState::Fire:
			ChangeState(EPlayerState::Attack);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
void APlayer::Dash(float _DeltaTime)
{
	DirCheck();
	PlayerGroundCheck(GravityForce);

	Gravity(_DeltaTime);


	AActor* _ColActor = CollisionComponent->CollisionOnce(ECollisionGroup::MonsterBody);
	if (_ColActor != nullptr)
	{
		AMonster* Target = dynamic_cast<AMonster*>(_ColActor);
		if (nullptr != Target) {


			//this->ColKnockBackEnter(_ColActor);
			if (CurPlayerCopyState == ECopyAbilityState::Fire)
			{
				Target->ColKnockBackEnter(this);

			}
			else {


				Target->ColKnockBackEnter(this);
				this->ColKnockBackEnter(Target);
			}
		}

	}
	

	


	FVector2D Vector = FVector2D::ZERO;
	if (true == UEngineInput::GetInst().IsDown('Z') && true == UEngineInput::GetInst().IsPress(VK_DOWN))
	{
		ChangeState(EPlayerState::Slide);
		return;
	}
	 if (true == UEngineInput::GetInst().IsPress(VK_DOWN))
	{
		Vector += FVector2D::DOWN;
	}
	 if (true == UEngineInput::GetInst().IsPress(VK_LEFT))
	{

		Vector += FVector2D::LEFT;

	}
	 if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))
	{

		Vector += FVector2D::RIGHT;
	}

	
	 if (true == UEngineInput::GetInst().IsPress('Z'))
	{
		ChangeState(EPlayerState::Jump);
		return;
	}
	 if (true == UEngineInput::GetInst().IsDown('X'))
	{
		ChangeDashStateByCopy('X');
		return;
	}
	 if (true == UEngineInput::GetInst().IsPress(VK_DOWN))
	{
		ChangeDashStateByEat(VK_DOWN);
		return;
	}



	if (false == UEngineInput::GetInst().IsPress(VK_LEFT) &&
		false == UEngineInput::GetInst().IsPress(VK_RIGHT) &&
		false == UEngineInput::GetInst().IsPress(VK_DOWN)) 
	{
		ChangeState(EPlayerState::Idle);
		return;
	}


	
	
		UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
		if (Color == UColor::BLACK)
		{
			UColor NextColor = ColImage->GetColor(GetActorLocation() + FVector2D::UP * Speed * _DeltaTime, UColor::WHITE);
			if (NextColor != UColor::BLACK)
			{
				AddActorLocation(FVector2D::UP * Speed * _DeltaTime);
			}

		}
		else AddActorLocation(Vector * Speed * _DeltaTime);
	

	while (true)
	{
		UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
		if (Color == UColor::GRAY)
		{
			// 나가 땅위로 올라갈때까지 while 계속 올려준다.
			AddActorLocation(FVector2D::UP * Speed * _DeltaTime);
		}
		else {
			break;
		}
	}
	//CheckFireDashState(_DeltaTime, Vector);
}
void APlayer::PlayerKnockBack()
{

	AActor* _ColActor = CollisionComponent->CollisionOnce(ECollisionGroup::MonsterBody);
	if (_ColActor != nullptr)
	{
		AMonster* Target = dynamic_cast<AMonster*>(_ColActor);
		if (nullptr != Target) {


				Target->ColKnockBackEnter(this);
				this->ColKnockBackEnter(Target);
		}

	}
}
void APlayer::CheckFireDashState(float _DeltaTime, const FVector2D& Vector)
{
	if (CurPlayerCopyState == ECopyAbilityState::Fire)
	{
		if (false == PlayerNextPosCheck(_DeltaTime, FVector2D::UP))
		{
			IsFireDashState = true;
			this->ColKnockBackEnter(Vector);
		}
	}
}
void APlayer::ColKnockBackEnter(FVector2D _Vector)
{
	_Vector = _Vector * (-1.0f);

	_Vector.Normalize();
	SetKnockBackForce(_Vector*150.f);

	IsFireDashState = false;
	//넉백 상태로
	ChangeState(EPlayerState::KnockBack);
}
void APlayer::ChangeDashStateByEat(int _KeyIndex)
{
	switch (_KeyIndex)
	{
	case VK_DOWN:
		switch (CurPlayerEatState)
		{
		case EPlayerEatState::Normal:
			ChangeState(EPlayerState::Crouch);
			break;
		case EPlayerEatState::Eating:
			CurPlayerEatState = EPlayerEatState::Normal;

			ChangeState(EPlayerState::Idle);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	
}

void APlayer::PlayerFlyCheck()
{
	if (true == UEngineInput::GetInst().IsUp('Z')) IsFly = true;
	if(true == IsGround) IsFly = false;
}

void APlayer::Accel(float _DeltaTime, FVector2D Vector)
{
	Acc += Vector * Speed * _DeltaTime;

	// 최대 속도 제한한다
	float AccSize = (Acc.X * Acc.X) + (Acc.Y * Acc.Y);
	if (AccSize > MaxAcc * MaxAcc)
	{
		Acc = Vector * MaxAcc;
	}

	if (FVector2D::ZERO == Vector)
	{
		Acc = Acc * 0.9f;
	}

	AddActorLocation(Acc);
}

void APlayer::SlideStart()
{
	SpriteRenderer->ChangeAnimation("Slide" + DirString);

	CheckSlideDir();

}

void APlayer::FireSlideStart()
{
	SpriteRenderer->ChangeAnimation("FireSlide" + DirString);

	CheckSlideDir();

}

void APlayer::CheckSlideDir()
{
	if (DirString == "_Right")
	{
		CurSlidePower = SlidePower;
		CurRSlidePower = -SlidePower;
	}
	else if (DirString == "_Left")
	{
		CurSlidePower = -SlidePower;
		CurRSlidePower = SlidePower;
	}
}

void APlayer::SparkSlideStart()
{
	SpriteRenderer->ChangeAnimation("SparkSlide" + DirString);

	CheckSlideDir();

}

void APlayer::Slide(float _DeltaTime)
{
	FVector2D NextPos = GetActorLocation() + CurSlidePower * _DeltaTime ;

	UColor Color = ColImage->GetColor(NextPos, UColor::WHITE);
	if (Color != UColor::WHITE)
	{
		ChangeState(EPlayerState::Idle);
		return;
	}
	CurSlidePower += CurRSlidePower * _DeltaTime;

	if (5 >= CurSlidePower.Length())
	{
		ChangeState(EPlayerState::Idle);
		return;
	}

	AddActorLocation(CurSlidePower * _DeltaTime);

	// Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
	//if (Color == UColor::WHITE)
	//{
	//	// 나가 땅위로 올라갈때까지 while 계속 올려준다.
	//	AddActorLocation(FVector2D::DOWN);
	//}
	
}
void APlayer::FlyStart()
{
	BGMPlayer = UEngineSound::Play("Kirby Flying.WAV");
	GravityForce = FVector2D::ZERO;
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("Fly"+DirString);
}
void APlayer::FireFlyStart()
{
	BGMPlayer = UEngineSound::Play("Kirby Flying.WAV");
	GravityForce = FVector2D::ZERO;
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("FireFly" + DirString);
}
void APlayer::SparkFlyStart()
{
	BGMPlayer = UEngineSound::Play("Kirby Flying.WAV");
	GravityForce = FVector2D::ZERO;
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("SparkFly" + DirString);
}

void APlayer::FireFlyingStart()
{
	Speed = 300.0f;
	//GravityForce = FVector2D::ZERO;
	SpriteRenderer->ChangeAnimation("FireFlying" + DirString);
}
void APlayer::SparkFlyingStart()
{
	Speed = 300.0f;
	//GravityForce = FVector2D::ZERO;
	SpriteRenderer->ChangeAnimation("SparkFlying" + DirString);
}
void APlayer::FlyingStart()
{
	Speed = 300.0f;
	//GravityForce = FVector2D::ZERO;
	SpriteRenderer->ChangeAnimation("Flying" + DirString);
}
void APlayer::Fly(float _DeltaTime)
{
	DirCheck();
	FlyStartAnim();

	PlayerGroundCheck(GravityForce);

	FlyGravity(_DeltaTime);

	FVector2D Vector = FVector2D::ZERO;
	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))
	{
		Vector += FVector2D::RIGHT;
	}
	if (true == UEngineInput::GetInst().IsPress(VK_LEFT))
	{
		Vector += FVector2D::LEFT;
	}
	if (true == UEngineInput::GetInst().IsDown('X'))
	{
		IsFly = false;
		if (true == BGMPlayer.IsPlaying())
		{
			BGMPlayer.Stop();
		}
		BGMPlayer = UEngineSound::Play("Kirby Air Pang.WAV");

		ChangeState(EPlayerState::FlyDown);
		return;

	}if (true == UEngineInput::GetInst().IsPress('Z'))
	{
		if (true == BGMPlayer.IsPlaying())
		{
			BGMPlayer.Stop();
		}
		BGMPlayer = UEngineSound::Play("Kirby Flying.WAV");
		GravityForce = FVector2D::ZERO;
		Vector += FVector2D::UP;
	}
	PlayerKnockBack();
	if (true ==PlayerNextPosCheck(_DeltaTime, Vector))
	{
		AddActorLocation(Vector * Speed * _DeltaTime);
	}

}
void APlayer::FlyStartAnim()
{
	switch (CurPlayerCopyState)
	{
	case ECopyAbilityState::Normal:
		FlyingStart();
		break;
	case ECopyAbilityState::Spark:
		SparkFlyingStart();
		break;
	case ECopyAbilityState::Beam:
		break;
	case ECopyAbilityState::Fire:
		FireFlyingStart();
		break;
	default:
		break;
	}
}
void APlayer::FlyDownAnim()
{
	switch (CurPlayerCopyState)
	{
	case ECopyAbilityState::Normal:
		FlyDownStart();
		break;
	case ECopyAbilityState::Spark:
		SparkFlyDownStart();
		break;
	case ECopyAbilityState::Beam:
		break;
	case ECopyAbilityState::Fire:
		FireFlyDownStart();
		break;
	default:
		break;
	}
}
void APlayer::FlyDownStart()
{
	//BGMPlayer = UEngineSound::Play("Kirby Jump.WAV");
	SpriteRenderer->ChangeAnimation("FlyingDown" + DirString);
}
void APlayer::FireFlyDownStart()
{
	//BGMPlayer = UEngineSound::Play("Kirby Jump.WAV");
	SpriteRenderer->ChangeAnimation("FireFlyingDown" + DirString);

}
void APlayer::SparkFlyDownStart()
{
	SpriteRenderer->ChangeAnimation("SparkFlyingDown" + DirString);

}
void APlayer::FlyDown(float _DeltaTime)
{
	DirCheck();
	FlyDownAnim();

	if (true == IsGround) {
		ChangeState(EPlayerState::Idle);
		return;
	}

	FVector2D Vector = FVector2D::ZERO;
	PlayerGroundCheck(FVector2D::DOWN);
	FlyGravity(_DeltaTime);
	PlayerKnockBack();
	
	if (true == UEngineInput::GetInst().IsPress(VK_LEFT))
	{
		Vector += FVector2D::LEFT;
	}
	else if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))
	{
		Vector += FVector2D::RIGHT;
	}
	else if (true == UEngineInput::GetInst().IsPress(VK_DOWN))
	{
		Vector += FVector2D::DOWN;
	}
	AddActorLocation(Vector * _DeltaTime * Speed);
}
void APlayer::ExhaleStart()
{
	if (true == BGMPlayer.IsPlaying())
	{
		BGMPlayer.Stop();
	}
	BGMPlayer = UEngineSound::Play("Star Pang.WAV");
	SpriteRenderer->ChangeAnimation("Exhale" + DirString);


	ABullet* Bullet = GetWorld()->SpawnActor<ABullet>();
	Bullet->SetMainPawn(this);

	AGameMode* gm = GetWorld()->GetGameMode<AGameMode>();
	if (gm == nullptr) return;

	if ("Stage1_1" == gm->GetName()) {
		Bullet->SetColImage("foreground1-1_col.png");
	}
	else if ("Stage1_2" == gm->GetName()) {
		Bullet->SetColImage("foreground1-2_col.png");

	}
	else if ("Stage1_3" == gm->GetName()) {
		Bullet->SetColImage("foreground1-3_col.png");

	}
	/*else if ("Stage1_4" == gm->GetName()) {
		Bullet->SetColImage("foreground1-4_col.png");

	}*/
	else if ("ItemRoomBeforeBoss" == gm->GetName()) {
		Bullet->SetColImage("StageBossKingDedede.png");
	}
	else if ("StageBossKingDedede" == gm->GetName()) {
		Bullet->SetColImage("foregroundKingDedede1-1_col.png");
	}


	FVector2D Vector = FVector2D::ZERO;
	if (DirString == "_Left")
	{
		Bullet->SetActorLocation({ GetActorLocation().X - 30,GetActorLocation().Y - 23 });

	}
	else {
		Bullet->SetActorLocation({ GetActorLocation().X + 30,GetActorLocation().Y - 23 });

	}


	

}
void APlayer::Exhale(float _DeltaTime)
{
	//DirCheck();
	//ExhaleStart();

	if (true == SpriteRenderer->IsCurAnimationEnd())
	{
		ChangeState(EPlayerState::Idle);
		return;
	}

}
void APlayer::InhaleStart()
{
	if (true == BGMPlayer.IsPlaying())
	{
		BGMPlayer.Stop();
	}
	BGMPlayer = UEngineSound::Play("Kirby Inhale.WAV");

	SpriteRenderer->ChangeAnimation("Inhale" + DirString);
}

void APlayer::Inhale(float _DeltaTime)
{
	DirCheck();
	
	FVector2D Vector = FVector2D::ZERO;
	if (true == UEngineInput::GetInst().IsUp('X'))
	{
		//ColMonster = nullptr;

		if (star != nullptr) {
			star->SetIshale(false);
		}
		InhaleRightComponent->SetActive(false);
		InhaleLeftComponent->SetActive(false);

		ChangeState(EPlayerState::Idle);
		return;
	}
	AActor* ColMon = nullptr;
	AActor* ColStar = nullptr;
	if (DirString=="_Right")
	{
		InhaleRightComponent->SetActive(true);
		ColMon = InhaleRightComponent->CollisionOnce(ECollisionGroup::MonsterBody);
		ColStar = InhaleRightComponent->CollisionOnce(ECollisionGroup::Block);
		//Vector = FVector2D::LEFT;
	}
	else if (DirString == "_Left")
	{
		InhaleLeftComponent->SetActive(true);
		ColMon = InhaleLeftComponent->CollisionOnce(ECollisionGroup::MonsterBody);
		ColStar = InhaleLeftComponent->CollisionOnce(ECollisionGroup::Block);
		//Vector = FVector2D::RIGHT;
	}

	if (ColStar != nullptr) {

		star = dynamic_cast<AJumpStar*>(ColStar);

		if (nullptr != star)
		{
			Vector = GetActorLocation() - star->GetActorLocation();
			Vector.Normalize();
			star->SetIshale(true);
			star->InhalingGravity(_DeltaTime, Vector);
		}
		MonsterBullet = dynamic_cast<AMonsterBullet*>(ColStar);

		if (nullptr != MonsterBullet)
		{
			Vector = GetActorLocation() - MonsterBullet->GetActorLocation();
			Vector.Normalize();
			//StarBlock->SetIshale(true);
			MonsterBullet->InhalingGravity(_DeltaTime, Vector);
		}

	}

	if (ColMon != nullptr) {
		int a = 0;
		AMonster* Monster = dynamic_cast<AMonster*>(ColMon);

		if (nullptr != Monster) {

			
			

			if (Monster->GetCurMonsterState() != EMonsterState::Inhaled) {
				Monster->ChangeState(EMonsterState::Inhaled);

			}
			Vector = GetActorLocation() - Monster->GetActorLocation();
			Vector.Normalize();
			Monster->InhalingGravity(_DeltaTime, Vector);
		}
	
	}



	ColStar = CollisionComponent->CollisionOnce(ECollisionGroup::Block);
	AJumpStar* Jumpstar = dynamic_cast<AJumpStar*>(ColStar);

	if (Jumpstar != nullptr)
	{

		if (true == BGMPlayer.IsPlaying())
		{
			BGMPlayer.Stop();
		}
		BGMPlayer = UEngineSound::Play("Kirby Inhale Eating.WAV");

		ColAnyActor = ColStar;

		CurPlayerEatState = EPlayerEatState::Eating;
		Jumpstar->SetActive(false);
		InhaleRightComponent->SetActive(false);
		InhaleLeftComponent->SetActive(false);

		ChangeState(EPlayerState::Idle);
		return;
	}

	ColStar = CollisionComponent->CollisionOnce(ECollisionGroup::Block);
	AMonsterBullet* MonsterBullet = dynamic_cast<AMonsterBullet*>(ColStar);

 	if (MonsterBullet != nullptr)
	{

		if (true == BGMPlayer.IsPlaying())
		{
			BGMPlayer.Stop();
		}
		BGMPlayer = UEngineSound::Play("Kirby Inhale Eating.WAV");

		ColAnyActor = ColStar;

		CurPlayerEatState = EPlayerEatState::Eating;
		InhaleRightComponent->SetActive(false);
		InhaleLeftComponent->SetActive(false);


		MonsterBullet->SetActive(false);

		ChangeState(EPlayerState::Idle);
		return;
	}

	ColMon = CollisionComponent->CollisionOnce(ECollisionGroup::MonsterBody);
	if (ColMon != nullptr)
	{
		AMonster* ColMonster= dynamic_cast<AMonster*>(ColMon);
		if (ColMonster != nullptr) {

			if (true == BGMPlayer.IsPlaying())
			{
				BGMPlayer.Stop();
			}
			BGMPlayer = UEngineSound::Play("Kirby Inhale Eating.WAV");

			ColAnyActor = ColMon;

			CurPlayerEatState = EPlayerEatState::Eating;
			ColMonster->SetActive(false);
			InhaleRightComponent->SetActive(false);
			InhaleLeftComponent->SetActive(false);

			
			// 몬스터 흡입한 상태 커비 애니메이션
			ChangeState(EPlayerState::Idle);

			if (star != nullptr) {
				star->SetIshale(false);
			}
		}
		return;
	}

	

	


}




void APlayer::PlayerCameraCheck()
{
	FVector2D WindowSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPos(GetActorLocation() - WindowSize.Half());
}


void APlayer::PlayerGroundCheck(FVector2D _MovePos)
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
		else 
		{
			IsGround = true;
		}
	}
}

void APlayer::BlockPlayerPos(FVector2D _MapScale)
{
	FVector2D PlayerPos = GetActorLocation();

	if (0.0f > PlayerPos.X)
	{
		PlayerPos.X = 0.0f;
	}
	if (0.0f > PlayerPos.Y)
	{
		PlayerPos.Y = 0.0f;
	}

	if (_MapScale.X-10 < PlayerPos.X)
	{
		PlayerPos.X = _MapScale.X-10;
	}
	SetActorLocation(PlayerPos);
}

void APlayer::PlayerSlideCheck (float _DeltaTime, FVector2D _Vector)
{
	FVector2D NextPos = GetActorLocation() + _Vector;
	UColor Color = ColImage->GetColor(NextPos, UColor::WHITE);
	if (Color == UColor::WHITE)
	{
		AddActorLocation(_Vector * _DeltaTime * Speed);

	}
}
void APlayer::InhaleCollisionEnter(AActor* _ColActor)
{
	
	int a = 0;

}
void APlayer::InhaleCollisionStay(AActor* _ColActor)
{
	ColMonster = dynamic_cast<AMonster*>(_ColActor);

	//
}
void APlayer::InhaleCollisionEnd(AActor* _ColActor)
{

}

void APlayer::CollisionEnter(AActor* _ColActor)
{
	int a = 0;

	ColBullet = dynamic_cast<AMonsterFireBullet*>(_ColActor);
	if (nullptr != ColBullet)
	{
		FVector2D Vector = GetActorLocation() - _ColActor->GetActorLocation();
		Vector.Normalize();
		Vector.Y = 0.0f;
		SetKnockBackForce(Vector * 150.0f);

		SetIsDamagedState(true);
		ChangeState(EPlayerState::KnockBack);
	}

	AKingDedede* king = dynamic_cast<AKingDedede*>(_ColActor);
	if (nullptr != king)
	{

	}
}
	
void APlayer::ColKnockBackEnter(AActor* _ColActor)
{
	FVector2D Vector = GetActorLocation()- _ColActor->GetActorLocation();
	Vector.Normalize();
	Vector.Y = 0.0f;

	SetKnockBackForce(Vector*150.0f);
	SetIsDamagedState(true);

	 //GetWorld()->SpawnActor<AJumpStar*>();
	ChangeState(EPlayerState::KnockBack);
}


void APlayer::CollisionStay(AActor* _ColActor)
{
	int a = 0;
}

void APlayer::CollisionEnd(AActor* _ColActor)
{
	int  a = 0;
}
void APlayer::ChangeIdleStateByCopy(int _KeyIndex)
{

	switch (_KeyIndex)
	{
	case VK_DOWN:

		ChangeState(EPlayerState::Crouch);

	break;

	case 'X':
		switch (CurPlayerCopyState)
		{
		case ECopyAbilityState::Normal:
			switch (CurPlayerEatState)
			{
			case EPlayerEatState::Normal:
				ChangeState(EPlayerState::Inhale);
				break;
			case EPlayerEatState::Eating:
				CurPlayerEatState = EPlayerEatState::Normal;
				ChangeState(EPlayerState::Exhale);
				break;
			default:
				break;
			}
			break;
		case ECopyAbilityState::Spark:
			ChangeState(EPlayerState::Attack);

			break;
		case ECopyAbilityState::Beam:
			break;
		case ECopyAbilityState::Fire:
			ChangeState(EPlayerState::Attack);
			break;
		default:
			break;
		}
		break;
	case 'A':
		IsChange = false;
		switch (CurPlayerCopyState)
		{
		case ECopyAbilityState::Normal:
			ChangeState(EPlayerState::Idle);
			break;
		case ECopyAbilityState::Spark:
			CreateJumpStar();
			CurPlayerCopyState = ECopyAbilityState::Normal;
			ChangeState(EPlayerState::Idle);
			break;
		case ECopyAbilityState::Beam:
			CreateJumpStar();
			CurPlayerCopyState = ECopyAbilityState::Normal;
			ChangeState(EPlayerState::Idle);
			break;
		case ECopyAbilityState::Fire:
			CreateJumpStar();
			CurPlayerCopyState = ECopyAbilityState::Normal;
			ChangeState(EPlayerState::Idle);
			//능력뱉기
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

}