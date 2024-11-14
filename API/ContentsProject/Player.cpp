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

APlayer::APlayer()
{
	//SetActorLocation({ 3050,50 });


	{	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetSprite("Idle_Right.png");
		SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
		SpriteRenderer->SetComponentScale({ 270, 270 });

		SetName("Kirby");
		UImageManager::GetInst().CuttingSprite("Idle_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Idle_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Eating_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("Eating_Right.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("EatingMove_Left.png", { 128, 128 });
		UImageManager::GetInst().CuttingSprite("EatingMove_Right.png", { 128, 128 });
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
		SpriteRenderer->CreateAnimation("Idle_Left", "Idle_Left.png", 0, 2, 3.f);
		SpriteRenderer->CreateAnimation("Idle_Right", "Idle_Right.png", 0, 2, 3.f);
		SpriteRenderer->CreateAnimation("Eating_Left", "Eating_Left.png", 5, 6, 0.1f,false);
		SpriteRenderer->CreateAnimation("Eating_Right", "Eating_Right.png", 5, 6, 0.1f);
		SpriteRenderer->CreateAnimation("Crouch_Left", "Crouch_Left.png", 0, 1, 0.2f, false);
		SpriteRenderer->CreateAnimation("Crouch_Right", "Crouch_Right.png", 0, 1, 0.2f, false);
		SpriteRenderer->CreateAnimation("Walk_Left", "Walk_Left.png", 0, 3, 0.25f);
		SpriteRenderer->CreateAnimation("Walk_Right", "Walk_Right.png", 0, 3, 0.25f);
		SpriteRenderer->CreateAnimation("EatingWalk_Left", "EatingMove_Left.png", 0, 14, 0.1f);
		SpriteRenderer->CreateAnimation("EatingWalk_Right", "EatingMove_Right.png", 0, 14, 0.1f);
		SpriteRenderer->CreateAnimation("Run_Left", "Run_Left.png", 0, 6, 0.1f);
		SpriteRenderer->CreateAnimation("Run_Right", "Run_Right.png", 0, 6, 0.1f);
		SpriteRenderer->CreateAnimation("EatingRun_Left", "EatingMove_Left.png", 0, 14, 0.1f);
		SpriteRenderer->CreateAnimation("EatingRun_Right", "EatingMove_Right.png", 0, 14, 0.1f);
		SpriteRenderer->CreateAnimation("Jump_Left", "Jump_Left.png", 0, 8, 0.1f, false);
		SpriteRenderer->CreateAnimation("Jump_Right", "Jump_Right.png", 0, 8, 0.1f, false);
		SpriteRenderer->CreateAnimation("EatingJump_Left", "EatingJump_Left.png", 0, 8, 0.1f, false);
		SpriteRenderer->CreateAnimation("EatingJump_Right", "EatingJump_Right.png", 0, 8, 0.1f, false);
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
		SpriteRenderer->CreateAnimation("Inhale_Left", "Inhale_Left.png", { 4,5,6,7,8,7,8,7,8,7,8,7,8,7,8,7,6,9,10,11,12 }, 0.1f,false);
		SpriteRenderer->CreateAnimation("Inhale_Right", "Inhale_Right.png", { 4,5,6,7,8,7,8,7,8,7,8,7,8,7,8,7,6,9,10,11,12 }, 0.1f,false);
		//SpriteRenderer->CreateAnimation("Inhaling_Left", "Inhale_Left.png", { 6,7,8,7 }, { 0.15f }, true);
		//SpriteRenderer->CreateAnimation("Inhaling_Right", "Inhale_Right.png", { 4,5,6,7,8,7,8,7,6 }, { 0.15f }, true);

		SpriteRenderer->ChangeAnimation("Idle_Right");
	}
	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 0, 0 });
		CollisionComponent->SetComponentScale({ 50, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::PlayerBody);
	}
	{
		InhaleComponent = CreateDefaultSubObject<U2DCollision>();
		InhaleComponent->SetComponentLocation({ 90, -20 });
		InhaleComponent->SetComponentScale({ 80, 60 });
		InhaleComponent->SetCollisionGroup(ECollisionGroup::PlayerInhaleRange);
		InhaleComponent->SetCollisionType(ECollisionType::Rect);

		//InhaleComponent->SetCollisionEnter(std::bind(&APlayer::InhaleCollisionEnter, this, std::placeholders::_1));
		//InhaleComponent->SetCollisionStay(std::bind(&APlayer::InhaleCollisionStay, this, std::placeholders::_1));
		//InhaleComponent->SetCollisionEnd(std::bind(&APlayer::InhaleCollisionEnd, this, std::placeholders::_1));

		//
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
	case EPlayerState::Crouch:
		CrouchStart();
		break;
	case EPlayerState::Move:
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
	case EPlayerState::Dash:
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
	case EPlayerState::Break:
		BreakStart();
		break;
	case EPlayerState::Jump:
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
	case EPlayerState::Fly:
		FlyStart();
		break;
	case EPlayerState::FlyDown:
		FlyDownStart();
		break;
	case EPlayerState::Slide:
		SlideStart();
		//
		break;
	case EPlayerState::Inhale:
		InhaleStart();
		//
		break;
	default:
		break;
	}

	CurPlayerState = _CurPlayerState;

}
void APlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (true == UEngineInput::GetInst().IsDown('R'))
	{
		UEngineDebug::SwitchIsDebug();
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
void APlayer::IdleStart()
{
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("Idle" + DirString);

}
void APlayer::EatingIdleStart()
{
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("Eating" + DirString);

}
void APlayer::Idle(float _DeltaTime)
{
	PlayerGroundCheck(GravityForce);
	Gravity(_DeltaTime);


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
	if (true == UEngineInput::GetInst().IsPress('S'))
	{
		ChangeState(EPlayerState::Fly);
		return;
	}
	if (true == UEngineInput::GetInst().IsDown('X'))
	{
		switch (CurPlayerEatState)
		{
		case EPlayerEatState::Normal:
			ChangeState(EPlayerState::Inhale);
			break;
		case EPlayerEatState::Eating:
			CurPlayerEatState = EPlayerEatState::Normal;
			//ChangeState(EPlayerState::Idle);
			break;
		default:
			break;
		}
		
		return;
	}
	if (true == UEngineInput::GetInst().IsPress(VK_DOWN))
	{
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
		
		
		return;
	}
}

void APlayer::CrouchStart()
{
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("Crouch" + DirString);
}

void APlayer::Crouch(float _DeltaTime)
{
	DirCheck();
	CrouchStart();

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
	UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
	if (Color == UColor::BLACK)
	{
		UColor NextColor = ColImage->GetColor(GetActorLocation() + _Vector, UColor::WHITE);
		if (NextColor != UColor::BLACK)
		{
			AddActorLocation(_Vector);
			return false;
		}
	}
	else
	{
		return true;
	}
	return false;

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
void APlayer::Jump(float _DeltaTime)
{
	if (true == IsGround)
	{
		ChangeState(EPlayerState::Idle);
		return;
	}
	PlayerGroundCheck(GravityForce * _DeltaTime);
	PlayerFlyCheck( );
	
	JumpGravity(_DeltaTime);
	AddActorLocation(JumpPower * _DeltaTime);
	
	FVector2D Vector = FVector2D::ZERO;

	if (true == UEngineInput::GetInst().IsPress(VK_LEFT)) Vector = FVector2D::LEFT;
	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))  Vector = FVector2D::RIGHT;
	if (true == UEngineInput::GetInst().IsPress('Z') && true == IsFly) {

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

		//ChangeState(EPlayerState::Fly);
		return;
	}

	////다음 위치로 갈 수 있다.
	if (true == PlayerNextPosCheck(_DeltaTime, Vector))
	{
		AddActorLocation(Vector  * _DeltaTime * 150.0f);
	}
	
}


void APlayer::MoveStart()
{
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("Walk" + DirString);

}
void APlayer::EatingMoveStart()
{
	Speed = 150.0f;
	SpriteRenderer->ChangeAnimation("EatingWalk" + DirString);
}


void APlayer::EatingAttackStart()
{
	int a = 0;
}
void APlayer::Move(float _DeltaTime)
{
	DirCheck();
	PlayerGroundCheck(GravityForce);
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
		 ChangeState(EPlayerState::Inhale);
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
	Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);


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

void APlayer::EatingDashStart()
{
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("EatingRun" + DirString);
}

void APlayer::DashStart()
{
	SpriteRenderer->ChangeAnimation("Run" + DirString);
	Speed = 500.0f;

}
void APlayer::BreakStart()
{
	
	SpriteRenderer->ChangeAnimation("Break" + DirString);
	

}
void APlayer::Breaking(float _DeltaTime)
{
	PlayerGroundCheck(GravityForce);
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

void APlayer::Dash(float _DeltaTime)
{
	DirCheck();
	PlayerGroundCheck(GravityForce);
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
		ChangeState(EPlayerState::Inhale);
		return;
	}
	if (true == UEngineInput::GetInst().IsPress(VK_DOWN))
	{
		switch (CurPlayerEatState)
		{
		case EPlayerEatState::Normal:
			ChangeState(EPlayerState::Crouch);
			break;
		case EPlayerEatState::Eating:
			CurPlayerEatState = EPlayerEatState::Normal;
			//ChangeState(EPlayerState::Idle);
			break;
		default:
			break;
		}
		return;
	}



	if (false == UEngineInput::GetInst().IsPress(VK_LEFT) &&
		false == UEngineInput::GetInst().IsPress(VK_RIGHT) &&
		false == UEngineInput::GetInst().IsPress(VK_DOWN)) 
	{
		ChangeState(EPlayerState::Idle);
		return;
	}


	/*UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
	if (Color == UColor::BLACK)
	{
		UColor NextColor = ColImage->GetColor(GetActorLocation() + FVector2D::UP, UColor::WHITE);
		if (NextColor != UColor::BLACK)
		{
			AddActorLocation(FVector2D::UP);

		}

	}
	else { AddActorLocation(Vector * Speed * _DeltaTime); }*/

	UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
	if (Color == UColor::BLACK)
	{
		UColor NextColor = ColImage->GetColor(GetActorLocation()+FVector2D::UP, UColor::WHITE);
		if (NextColor != UColor::BLACK)
		{
			AddActorLocation(FVector2D::UP);
		}

	}
	else AddActorLocation(Vector * Speed * _DeltaTime);
	Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);


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

}



void APlayer::Slide(float _DeltaTime)
{
	if (CurrSlideTime >SlideTime)
	{
		CurrSlideTime = 0;
		ChangeState(EPlayerState::Idle);
		
	}
	CurrSlideTime += 0.2f;
	FVector2D Vector = FVector2D::ZERO;

	if (true == UEngineInput::GetInst().IsPress(VK_LEFT))
	{
		Vector += FVector2D::LEFT;

	}
	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))
	{
		Vector += FVector2D::RIGHT;
	}
	PlayerSlideCheck(_DeltaTime, Vector);
	
}
void APlayer::FlyStart()
{
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("Fly"+DirString);
}
void APlayer::FlyingStart()
{
	Speed = 300.0f;
	SpriteRenderer->ChangeAnimation("Flying" + DirString);
}
void APlayer::Fly(float _DeltaTime)
{
	DirCheck();
	FlyingStart();
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
		ChangeState(EPlayerState::FlyDown);
		return;

	}if (true == UEngineInput::GetInst().IsPress('Z'))
	{
		Vector += FVector2D::UP;

	
	}

	if (PlayerNextPosCheck(_DeltaTime, Vector))
	{
		AddActorLocation(Vector * Speed * _DeltaTime);
	}

}
void APlayer::FlyDownStart()
{
	SpriteRenderer->ChangeAnimation("FlyingDown" + DirString);
}
void APlayer::FlyDown(float _DeltaTime)
{
	DirCheck();
	FlyDownStart();

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

void APlayer::InhaleStart()
{
	SpriteRenderer->ChangeAnimation("Inhale" + DirString);
}

void APlayer::Inhale(float _DeltaTime)
{

	if (true == UEngineInput::GetInst().IsUp('X'))
	{
		ColMonster = nullptr;
		ChangeState(EPlayerState::Idle);
		return;
	}

	AActor* ColActor = InhaleComponent->CollisionOnce(ECollisionGroup::MonsterBody);
	if (ColActor != nullptr) {

		ColMonster = dynamic_cast<AMonster*>(ColActor);
		if (ColMonster->CurMonsterState != EMonsterState::Inhaled) {
			ColMonster->ChangeState(EMonsterState::Inhaled);
		}
		InhalingGravity(_DeltaTime);

	}
	ColActor = nullptr;
	ColActor = CollisionComponent->CollisionOnce(ECollisionGroup::MonsterBody);
	if (ColActor != nullptr)
	{
		ColActor->Destroy();
		CurPlayerEatState=EPlayerEatState::Eating;
		// 몬스터 흡입한 상태 커비 애니메이션
		ChangeState(EPlayerState::Idle);
		return;

	}


}
void APlayer::CheckInhaleMonster() {
	//if(ColMonster !=nullptr)

}
void APlayer::InhalingGravity(float _DeltaTime)
{
	InhalingForce = InhalingVector * _DeltaTime * 150.0f;
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
	//FTransform PlayerTransformNext = GetTransform();
	//PlayerTransformNext.Location += FVector2D(30, 0) - GetWorld()->GetCameraPos();
	//PlayerTransformNext.Scale = { 6,6 };
	//UEngineDebug::CoreDebugRender(PlayerTransformNext, UEngineDebug::EDebugPosType::Circle);

	//FTransform PlayerTransformDown = GetTransform();
	//PlayerTransformDown.Location += FVector2D(30, 30) - GetWorld()->GetCameraPos();
	//PlayerTransformDown.Scale = { 6,6 };
	//UEngineDebug::CoreDebugRender(PlayerTransformDown, UEngineDebug::EDebugPosType::Circle);
	//while (false == IsGround)
	//{

	//	// 내 앞이 white, 아래가 black 이면 
	//	UColor ColorNext = ColImage->GetColor(PlayerTransformNext.Location, UColor::WHITE);
	//	UColor ColorDown = ColImage->GetColor(PlayerTransformDown.Location, UColor::WHITE);
	//	if (ColorNext == UColor::WHITE && ColorDown == UColor::BLACK) AddActorLocation(FVector2D::DOWN * 5);

	//	UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
	//	if (Color == UColor::BLACK) break;
	//	else break;

	//}
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
}

void APlayer::CollisionStay(AActor* _ColActor)
{
	int a = 0;
}

void APlayer::CollisionEnd(AActor* _ColActor)
{
	int  a = 0;
}
