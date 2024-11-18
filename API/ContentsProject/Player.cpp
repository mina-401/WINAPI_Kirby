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

APlayer::APlayer()
{

	{	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetSprite("Idle_Right.png");
		SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
		SpriteRenderer->SetComponentScale({ 270, 270 });

		SetName("Kirby");
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

		UImageManager::GetInst().CuttingSprite("Eating_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Eating_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("EatingMove_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("EatingMove_Right.png", { 128, 128 });

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


		//Eating 
		SpriteRenderer->CreateAnimation("Eating_Left", "Eating_Left.png", 5, 6, 0.1f,false);
		SpriteRenderer->CreateAnimation("Eating_Right", "Eating_Right.png", 5, 6, 0.1f);
		SpriteRenderer->CreateAnimation("EatingRun_Left", "EatingMove_Left.png", 0, 14, 0.1f);
		SpriteRenderer->CreateAnimation("EatingRun_Right", "EatingMove_Right.png", 0, 14, 0.1f);
		SpriteRenderer->CreateAnimation("EatingWalk_Left", "EatingMove_Left.png", 0, 14, 0.1f);
		SpriteRenderer->CreateAnimation("EatingWalk_Right", "EatingMove_Right.png", 0, 14, 0.1f);
		SpriteRenderer->CreateAnimation("EatingJump_Left", "EatingJump_Left.png", 0, 8, 0.1f, false);
		SpriteRenderer->CreateAnimation("EatingJump_Right", "EatingJump_Right.png", 0, 8, 0.1f, false);

		//Fire
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



		SpriteRenderer->ChangeAnimation("Idle_Right");

		
	}
	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, 0 });
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

	{  
		//BGMPlayLevelPrismPlayer = UEngineSound::Play("04. Prism Plains.mp3");
		//BGMPlayLevelPrismPlayer.Loop(1);
		
		//BGMPlayer = UEngineSound::Play("05. Victory Star.mp3");

	}

	Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPivot(Size.Half() * -1.0f);
	GetWorld()->SetCameraToMainPawn(false);

	PlayerHud = GetWorld()->SpawnActor<AKirbyWidget>();


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
		case EPlayerCopyState::Normal:
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
		case EPlayerCopyState::Spark:
			break;
		case EPlayerCopyState::Beam:
			break;
		case EPlayerCopyState::Fire:
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
		case EPlayerCopyState::Normal:
			CrouchStart();
			break;
		case EPlayerCopyState::Spark:
			break;
		case EPlayerCopyState::Beam:
			break;
		case EPlayerCopyState::Fire:
			FireCrouchStart();
			break;
		default:
			break;
		}
		break;




	case EPlayerState::Move:

		switch (CurPlayerCopyState)
		{
		case EPlayerCopyState::Normal:
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
		case EPlayerCopyState::Spark:
			break;
		case EPlayerCopyState::Beam:
			break;
		case EPlayerCopyState::Fire:
			FireMoveStart();
			break;
		default:
			break;
		}
		break;




	case EPlayerState::Dash:

		switch (CurPlayerCopyState)
		{
		case EPlayerCopyState::Normal:
			
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

		case EPlayerCopyState::Spark:
			break;

		case EPlayerCopyState::Beam:
			break;

		case EPlayerCopyState::Fire:
			FireDashStart();
			break;

		default:
			break;

		}
		
		break;


	case EPlayerState::Break:

		switch (CurPlayerCopyState)
		{
		case EPlayerCopyState::Normal:
			BreakStart();
			break;
		case EPlayerCopyState::Spark:
			break;
		case EPlayerCopyState::Beam:
			break;
		case EPlayerCopyState::Fire:
			FireBreakStart();
			break;
		default:
			break;
		}
		break;



	case EPlayerState::Jump:
		switch (CurPlayerCopyState)
		{
		case EPlayerCopyState::Normal:
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

		case EPlayerCopyState::Spark:
			break;
		case EPlayerCopyState::Beam:
			break;
		case EPlayerCopyState::Fire:
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
		case EPlayerCopyState::Normal:
			FlyStart();

			break;
		case EPlayerCopyState::Spark:
			break;
		case EPlayerCopyState::Beam:
			break;
		case EPlayerCopyState::Fire:
			FireFlyStart();
			break;
		default:
			break;
		}
		break;




	case EPlayerState::FlyDown:

		switch (CurPlayerCopyState)
		{
		case EPlayerCopyState::Normal:
			FlyDownStart();

			break;
		case EPlayerCopyState::Spark:
			break;
		case EPlayerCopyState::Beam:
			break;
		case EPlayerCopyState::Fire:
			FireFlyDownStart();
			break;
		default:
			break;
		}

		break;




	case EPlayerState::Slide:

		switch (CurPlayerCopyState)
		{
		case EPlayerCopyState::Normal:
			SlideStart();

			break;
		case EPlayerCopyState::Spark:
			break;
		case EPlayerCopyState::Beam:
			break;
		case EPlayerCopyState::Fire:
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
		case EPlayerCopyState::Normal:
			InhaleStart();
			break;
		case EPlayerCopyState::Spark:
			break;
		case EPlayerCopyState::Beam:
			break;
		case EPlayerCopyState::Fire:
			
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
		AttackStart();
		break;


	default:
		break;
	}




	CurPlayerState = _CurPlayerState;

}
void APlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
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
void APlayer::DamageMonster(float _DeltaTime, FVector2D _Vector)
{
	FVector2D Pos = _Vector * _DeltaTime * 150.0f;

	ColMonster->AddActorLocation(Pos);
}

void APlayer::AttackStart()
{
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("FireAttack" + DirString);
}
void APlayer::Attack(float _DeltaTime)
{
	DirCheck();
	AttackStart();

	if (true == SpriteRenderer->IsCurAnimationEnd())
	{
		ChangeState(EPlayerState::Idle);
		return;
	}

	FVector2D Vector = FVector2D::ZERO;
	if (true == UEngineInput::GetInst().IsUp('X'))
	{
		ColMonster = nullptr;
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

		ColMonster = dynamic_cast<AMonster*>(ColActor);
		ColMonster->ChangeState(EMonsterState::Hurt);
	
		

	}
	ColActor = nullptr;
	//ColActor = CollisionComponent->CollisionOnce(ECollisionGroup::MonsterBody);
	//if (ColActor != nullptr)
	//{
	//	ColActor->Destroy();
	//	ColMonster = nullptr;
	//	InhaleRightComponent->SetActive(false);
	//	InhaleLeftComponent->SetActive(false);

	//	CurPlayerEatState = EPlayerEatState::Eating;
	//	// 몬스터 흡입한 상태 커비 애니메이션
	//	ChangeState(EPlayerState::Idle);
	//	return;

	//}
	int a = 0;
}
void APlayer::IdleStart()
{
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("Idle" + DirString);

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
void APlayer::Idle(float _DeltaTime)
{
	PlayerGroundCheck(GravityForce*_DeltaTime);
	Gravity(_DeltaTime);
	//DownHillGravity(_DeltaTime);


	if (true == UEngineInput::GetInst().IsPress(VK_LEFT) ||
		true == UEngineInput::GetInst().IsPress(VK_RIGHT))

	{ 
		//GravityForce = FVector2D::ZERO;
		//AddActorLocation()
		ChangeState(EPlayerState::Move);
	}

	if (true == UEngineInput::GetInst().IsDoubleClick(VK_RIGHT, 0.5f)|| true == UEngineInput::GetInst().IsDoubleClick(VK_LEFT, 0.5f))
	{
		//GravityForce = FVector2D::ZERO;

		ChangeState(EPlayerState::Dash);
		return;
	}

	

	if (true == UEngineInput::GetInst().IsPress('Z'))
	{
		//GravityForce = FVector2D::ZERO;
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



void APlayer::Crouch(float _DeltaTime)
{
	DirCheck();
	switch (CurPlayerCopyState)
	{
	case EPlayerCopyState::Normal:
		CrouchStart();

		break;
	case EPlayerCopyState::Spark:
		break;
	case EPlayerCopyState::Beam:
		break;
	case EPlayerCopyState::Fire:
		FireCrouchStart();
		break;
	default:
		break;
	}

	if (true == UEngineInput::GetInst().IsPress('Z'))
	{
		ChangeState(EPlayerState::Slide);
		return;
	}
	if (true == UEngineInput::GetInst().IsUp(VK_DOWN))
	{
		ChangeState(EPlayerState::Idle);
		return;
	}
}

bool APlayer::PlayerNextPosCheck(float _DeltaTime, FVector2D _Vector)
{
	UColor Color = ColImage->GetColor(GetActorLocation() + _Vector * _DeltaTime*Speed, UColor::WHITE);
	if (Color == UColor::BLACK)
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
	Speed = 150.0f;
	SpriteRenderer->ChangeAnimation("EatingJump" + DirString);
}
void APlayer::JumpStart()
{
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("Jump"+DirString);
}
void APlayer::FireJumpStart()
{
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

	PlayerGroundCheck(GravityForce * _DeltaTime);
	
	AddActorLocation(JumpPower * _DeltaTime);
	JumpGravity(_DeltaTime);
	
	FVector2D Vector = FVector2D::ZERO;

	if (true == UEngineInput::GetInst().IsPress(VK_LEFT)) Vector = FVector2D::LEFT;
	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))  Vector = FVector2D::RIGHT;
	if (true == UEngineInput::GetInst().IsPress('Z') && true == IsFly) {

		ChangeJumpStateByEat('Z', IsFly);
		return;
	}

	//다음 위치로 갈 수 있다.
	if (true == PlayerNextPosCheck(_DeltaTime, Vector))
	{
		AddActorLocation(Vector  * _DeltaTime * 150.0f);
	}
	if (true == IsGround)
	{
		ChangeState(EPlayerState::Idle);
		return;
	}
	PlayerFlyCheck();
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
		case EPlayerCopyState::Normal:
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
		case EPlayerCopyState::Spark:
			break;
		case EPlayerCopyState::Beam:
			break;
		case EPlayerCopyState::Fire:
			CurPlayerCopyState = EPlayerCopyState::Normal;
			ChangeState(EPlayerState::Idle);
			
			break;
		default:
			break;
		}
		break;
	case 'A':
		switch (CurPlayerCopyState)
		{
		case EPlayerCopyState::Normal:
			break;
		case EPlayerCopyState::Spark:
			break;
		case EPlayerCopyState::Beam:
			break;
		case EPlayerCopyState::Fire:
			CurPlayerCopyState = EPlayerCopyState::Normal;
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
void APlayer::Move(float _DeltaTime)
{
	DirCheck();
	PlayerGroundCheck(GravityForce * _DeltaTime);
	//DownHillGravity(_DeltaTime);
	Gravity(_DeltaTime);
	
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
			UColor NextColor = ColImage->GetColor(GetActorLocation() + FVector2D::UP, UColor::WHITE);
			if (NextColor != UColor::BLACK)
			{
				AddActorLocation(FVector2D::UP);
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
			AddActorLocation(FVector2D::UP);
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
	PlayerGroundCheck(GravityForce * _DeltaTime);
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
	SpriteRenderer->SetComponentScale({ 270,270 });
	SpriteRenderer->ChangeAnimation("FireRun" + DirString);
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
		case EPlayerCopyState::Normal:
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
		case EPlayerCopyState::Spark:
			ChangeState(EPlayerState::Attack);

			break;
		case EPlayerCopyState::Beam:
			ChangeState(EPlayerState::Attack);

			break;
		case EPlayerCopyState::Fire:
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
	PlayerGroundCheck(GravityForce * _DeltaTime);
	//DownHillGravity(_DeltaTime);
	Gravity(_DeltaTime);
	if (CurPlayerCopyState == EPlayerCopyState::Fire)
	{
		SpriteRenderer->SetComponentScale({180,180});

	}
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
		//절벽을 만났는지
		UColor NextColor = ColImage->GetColor(GetActorLocation() + FVector2D::UP, UColor::WHITE);
		if (NextColor != UColor::BLACK)
		{
			//경사이다.
			AddActorLocation(FVector2D::UP);
		}

	}
	else AddActorLocation(Vector * Speed * _DeltaTime);


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

	if (DirString == "_Right")
	{
		CurSlidePower = SlidePower;
		CurRSlidePower = -SlidePower;
	}else if (DirString == "_Left")
	{
		CurSlidePower = -SlidePower;
		CurRSlidePower = SlidePower;
	}
	

}

void APlayer::FireSlideStart()
{
	SpriteRenderer->ChangeAnimation("FireSlide" + DirString);

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

}
void APlayer::FlyStart()
{
	GravityForce = FVector2D::ZERO;
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("Fly"+DirString);
}
void APlayer::FireFlyStart()
{
	GravityForce = FVector2D::ZERO;
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("FireFly" + DirString);
}

void APlayer::FireFlyingStart()
{
	Speed = 300.0f;
	//GravityForce = FVector2D::ZERO;
	SpriteRenderer->ChangeAnimation("FireFlying" + DirString);
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

	
	PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);

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
		ChangeState(EPlayerState::FlyDown);
		return;

	}if (true == UEngineInput::GetInst().IsPress('Z'))
	{
		Vector += FVector2D::UP;
	}

	if (true ==PlayerNextPosCheck(_DeltaTime, Vector))
	{
		AddActorLocation(Vector * Speed * _DeltaTime);
	}

}
void APlayer::FlyStartAnim()
{
	switch (CurPlayerCopyState)
	{
	case EPlayerCopyState::Normal:
		FlyingStart();
		break;
	case EPlayerCopyState::Spark:
		break;
	case EPlayerCopyState::Beam:
		break;
	case EPlayerCopyState::Fire:
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
	case EPlayerCopyState::Normal:
		FlyDownStart();
		break;
	case EPlayerCopyState::Spark:
		break;
	case EPlayerCopyState::Beam:
		break;
	case EPlayerCopyState::Fire:
		FireFlyDownStart();
		break;
	default:
		break;
	}
}
void APlayer::FlyDownStart()
{
	SpriteRenderer->ChangeAnimation("FlyingDown" + DirString);
}
void APlayer::FireFlyDownStart()
{
	SpriteRenderer->ChangeAnimation("FireFlyingDown" + DirString);

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
	SpriteRenderer->ChangeAnimation("Exhale" + DirString);
}
void APlayer::Exhale(float _DeltaTime)
{
	DirCheck();


	if (true == SpriteRenderer->IsCurAnimationEnd())
	{
		ChangeState(EPlayerState::Idle);
		return;
	}

}
void APlayer::InhaleStart()
{
	SpriteRenderer->ChangeAnimation("Inhale" + DirString);
}

void APlayer::Inhale(float _DeltaTime)
{
	//DirCheck();

	FVector2D Vector = FVector2D::ZERO;
	if (true == UEngineInput::GetInst().IsUp('X'))
	{
		ColMonster = nullptr;
		InhaleRightComponent->SetActive(false);
		InhaleLeftComponent->SetActive(false);
		
		ChangeState(EPlayerState::Idle);
		return;
	}
	AActor* ColActor = nullptr;
	if (DirString=="_Right")
	{
		InhaleRightComponent->SetActive(true);
		ColActor = InhaleRightComponent->CollisionOnce(ECollisionGroup::MonsterBody);
		Vector = FVector2D::LEFT;
	}
	else if (DirString == "_Left")
	{
		InhaleLeftComponent->SetActive(true);
		ColActor = InhaleLeftComponent->CollisionOnce(ECollisionGroup::MonsterBody);
		Vector = FVector2D::RIGHT;
	}
	
	if (ColActor != nullptr) {

		ColMonster = dynamic_cast<AMonster*>(ColActor);
		if (ColMonster->GetCurMonsterState() != EMonsterState::Inhaled) {
			ColMonster->ChangeState(EMonsterState::Inhaled);
		}
		InhalingGravity(_DeltaTime,Vector);

	}
	ColActor = nullptr;
	ColActor = CollisionComponent->CollisionOnce(ECollisionGroup::MonsterBody);
	if (ColActor != nullptr)
	{
		ColActor->Destroy();
		ColMonster = nullptr;
		InhaleRightComponent->SetActive(false);
		InhaleLeftComponent->SetActive(false);

		CurPlayerEatState=EPlayerEatState::Eating;
		// 몬스터 흡입한 상태 커비 애니메이션
		ChangeState(EPlayerState::Idle);
		return;

	}


}

void APlayer::InhalingGravity(float _DeltaTime,FVector2D _Vector)
{
	InhalingForce = _Vector * _DeltaTime * 150.0f;
	ColMonster->AddActorLocation(InhalingForce);
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

	//AMonster* Monster = dynamic_cast<AMonster*>(_ColActor);
	//if (nullptr == Monster) return;

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
		switch (CurPlayerEatState)
		{
		case EPlayerEatState::Normal:
			ChangeState(EPlayerState::Crouch);
			break;
		case EPlayerEatState::Eating:
			CurPlayerEatState = EPlayerEatState::Normal;
			CurPlayerCopyState = EPlayerCopyState::Fire;

			ChangeState(EPlayerState::Idle);
			break;
		default:
			break;
		}
		break;

	case 'X':
		switch (CurPlayerCopyState)
		{
		case EPlayerCopyState::Normal:
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
		case EPlayerCopyState::Spark:
			break;
		case EPlayerCopyState::Beam:
			break;
		case EPlayerCopyState::Fire:
			ChangeState(EPlayerState::Attack);
			break;
		default:
			break;
		}
		break;
	case 'A':
		switch (CurPlayerCopyState)
		{
		case EPlayerCopyState::Normal:
			break;
		case EPlayerCopyState::Spark:
			CurPlayerCopyState = EPlayerCopyState::Normal;
			break;
		case EPlayerCopyState::Beam:
			CurPlayerCopyState = EPlayerCopyState::Normal;
			break;
		case EPlayerCopyState::Fire:
			CurPlayerCopyState = EPlayerCopyState::Normal;
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