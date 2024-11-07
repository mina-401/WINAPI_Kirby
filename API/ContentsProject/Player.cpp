#include "PreCompile.h"
#include "Player.h"

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
	// UEngineAPICore::GetCore()->CreateLevel("Title");
	//UEngineAPICore::GetCore()->GetMainWindow().GetBackBuffer();
	SetActorLocation({ 0, 0 });
	

	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite("Idle_Right.png");
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
	SpriteRenderer->SetComponentScale({ 270, 270 });

	SetName("Kirby");
	UImageManager::GetInst().CuttingSprite("Idle_Left.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("Idle_Right.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("Run_Left.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("Run_Right.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("Jump_Left.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("Jump_Right.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("Slide_Left.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("Slide_Right.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("Break_Left.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("Break_Right.png", { 128, 128 });
	SpriteRenderer->CreateAnimation("Idle_Left", "Idle_Left.png", 0, 2, 3.f);
	SpriteRenderer->CreateAnimation("Idle_Right", "Idle_Right.png", 0, 2, 3.f);
	SpriteRenderer->CreateAnimation("Run_Left", "Run_Left.png",  0, 6, 0.1f);
	SpriteRenderer->CreateAnimation("Run_Right", "Run_Right.png",  0, 6, 0.1f);
	SpriteRenderer->CreateAnimation("Jump_Left", "Jump_Left.png",  0, 8, 0.1f);
	SpriteRenderer->CreateAnimation("Jump_Right", "Jump_Right.png",  0, 8, 0.1f);
	SpriteRenderer->CreateAnimation("Slide_Left", "Slide_Left.png", 0, 0, 0.5f,false);
	SpriteRenderer->CreateAnimation("Slide_Right", "Slide_Right.png", 0, 0, 0.5f, false);
	SpriteRenderer->CreateAnimation("Break_Left", "Break_Left.png", 0, 0, 0.2f);
	SpriteRenderer->CreateAnimation("Break_Right", "Break_Right.png", 0, 0, 0.2f);

	SpriteRenderer->ChangeAnimation("Idle_Right");
	

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentLocation({ 200, 0 });
		CollisionComponent->SetComponentScale({ 50, 50 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::PlayerBody);
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


	ChangeState(PlayerState::Idle);
	
	//키 바인딩
	//인자를 호출할 때 넣어줌을 명시하는 것이 placeholders

	/*UEngineInput::GetInst().BindAction('A', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::LEFT));
	UEngineInput::GetInst().BindAction('D', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::RIGHT));
	UEngineInput::GetInst().BindAction('S', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::DOWN));
	UEngineInput::GetInst().BindAction('W', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::UP));*/

	DebugOn();
}

void APlayer::IdleStart()
{
	SpriteRenderer->ChangeAnimation("Idle_Right");
}

void APlayer::ChangeState(PlayerState _CurPlayerState)
{
	switch (_CurPlayerState)
	{
	case PlayerState::Idle:
		IdleStart();
		break;
	case PlayerState::Move:
		MoveStart();
		break;
	case PlayerState::Jump:
		JumpStart();
		break;
	case PlayerState::Slide:
		SlideStart();
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
	
		// CameraPivot = FVector2D(-1280, -720) * 0.5f;
	
	
	UEngineDebug::CoreOutPutString("FPS : " + std::to_string(1.0f / _DeltaTime));
	UEngineDebug::CoreOutPutString("PlayerPos : " + GetActorLocation().ToString());


	switch (CurPlayerState)
	{
	case PlayerState::Idle:
		Idle(_DeltaTime);
		break;
	case PlayerState::Move:
		Move(_DeltaTime);
		break;
	case PlayerState::Jump:
		Jump(_DeltaTime);
		break;
	case PlayerState::Slide:
		Slide(_DeltaTime);
		break;
	default:
		break;
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

void APlayer::Idle(float _DeltaTime)
{
	//Gravity();

	/*PlayerCameraCheck();
	PlayerGroundCheck(GravityForce);
	Gravity(_DeltaTime);*/

	//Acc = FVector2D::ZERO;

	if (true == IsDebug)
	{
		if (true == UEngineInput::GetInst().IsPress(VK_LEFT) ||
			true == UEngineInput::GetInst().IsPress(VK_RIGHT) ||
			true == UEngineInput::GetInst().IsPress(VK_UP) ||
			true == UEngineInput::GetInst().IsPress(VK_DOWN))
		{

			ChangeState(PlayerState::Move);
			return;
		}
	}
	else {
		if (true == UEngineInput::GetInst().IsPress(VK_LEFT) ||
			true == UEngineInput::GetInst().IsPress(VK_RIGHT) ||
			true == UEngineInput::GetInst().IsPress(VK_UP) )
			
		{

			ChangeState(PlayerState::Move);
			return;
		}
	}

	if (true == UEngineInput::GetInst().IsPress('Z'))
	{
		ChangeState(PlayerState::Jump);
		return;
	}



}

void APlayer::MoveStart()
{
	if (true == UEngineInput::GetInst().IsPress(VK_LEFT)) SpriteRenderer->ChangeAnimation("Run_Left");
	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT)) SpriteRenderer->ChangeAnimation("Run_Right");
	if (true == UEngineInput::GetInst().IsPress(VK_UP)) {}
	if (true == UEngineInput::GetInst().IsPress(VK_DOWN)) {}
		

}
void APlayer::JumpStart()
{
	if (true == UEngineInput::GetInst().IsPress(VK_LEFT)) SpriteRenderer->ChangeAnimation("Jump_Left");
	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT)) SpriteRenderer->ChangeAnimation("Jump_Right");
}
void APlayer::Jump(float _DeltaTime)
{
	//Gravity();

	if ( 100.0f<CurrJumpTime)
	{
		CurrJumpTime = 0;
		ChangeState(PlayerState::Idle);

	}
	CurrJumpTime += 0.2f;
	//if (true == isJumpLanding) isJump = false;
	//if (true == isJump) return;

	FVector2D Vector = FVector2D::ZERO;

	if (true == UEngineInput::GetInst().IsDown('Z')) {
		isJump = true;
		JumpUp(_DeltaTime);
	}
	////if (true == UEngineInput::GetInst().IsUp('Z')) isJump = false;
	//

	//시간재서 1초지나면 JumpDown

}
void APlayer::JumpUp(float _DeltaTime)
{
	
	AddActorLocation(FVector2D::UP * _DeltaTime * Speed);
}
void APlayer::JumpDown(float _DeltaTime)
{
	AddActorLocation(FVector2D::DOWN * _DeltaTime * Speed);
	//
}
void APlayer::Move(float _DeltaTime)
{
	FVector2D Vector = FVector2D::ZERO;

	if (true == UEngineInput::GetInst().IsPress(VK_UP))
	{
		Vector += FVector2D::UP;

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

	//Accel(_DeltaTime, Vector);

	if (true == UEngineInput::GetInst().IsDown('Z') && true == UEngineInput::GetInst().IsPress(VK_DOWN))
	{
		ChangeState(PlayerState::Slide);
		return;
	}
	if (true == UEngineInput::GetInst().IsPress('Z'))
	{
		//ChangeState(PlayerState::Jump);
		//return;
	}
	if (false == UEngineInput::GetInst().IsPress(VK_LEFT) &&
		false == UEngineInput::GetInst().IsPress(VK_RIGHT) &&
		false == UEngineInput::GetInst().IsPress(VK_UP) &&
		false == UEngineInput::GetInst().IsPress(VK_DOWN))
	{
		ChangeState(PlayerState::Idle);
		return;
	}
	if (nullptr != ColImage)
	{

	//	// 픽셀충돌에서 제일 중요한건 애초에 박히지 않는것이다.
		FVector2D NextPos = GetActorLocation() + Vector * _DeltaTime * Speed;

	UColor Color = ColImage->GetColor(NextPos, UColor::BLACK);

		if (Color == UColor::WHITE)
		{
			AddActorLocation(Vector * _DeltaTime * Speed);
		}
	}
	

}

void APlayer::SlideStart()
{

	if (true == UEngineInput::GetInst().IsPress(VK_LEFT)) SpriteRenderer->ChangeAnimation("Slide_Left");
	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT)) SpriteRenderer->ChangeAnimation("Slide_Right");

}

void APlayer::BreakRunning()
{
	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT)) SpriteRenderer->ChangeAnimation("Break_Left");
	if (true == UEngineInput::GetInst().IsPress(VK_LEFT)) SpriteRenderer->ChangeAnimation("Break_right");


}

void APlayer::Slide(float _DeltaTime)
{
	if (CurrTime >80.0f)
	{
		CurrTime = 0;
		ChangeState(PlayerState::Idle);
		
	}
	CurrTime += 0.2f;
	FVector2D Vector = FVector2D::ZERO;

	if (true == UEngineInput::GetInst().IsPress(VK_LEFT))
	{
		Vector += FVector2D::LEFT;

	}
	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))
	{
		Vector += FVector2D::RIGHT;
	}
	
	if (nullptr != ColImage)
	{

		// 픽셀충돌에서 제일 중요한건 애초에 박히지 않는것이다.
		FVector2D NextPos = GetActorLocation() + Vector * _DeltaTime * Speed;

		UColor Color = ColImage->GetColor(NextPos, UColor::BLACK);

		if (Color == UColor::WHITE)
		{
			AddActorLocation(Vector * _DeltaTime * Speed);
		}
	}
	//AddActorLocation(Vector * _DeltaTime * Speed);
}void APlayer::PlayerCameraCheck()
{
	FVector2D WindowSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPos(GetActorLocation() - WindowSize.Half());
}

void APlayer::PlayerGroundCheck(FVector2D _MovePos)
{
	IsMove = false;
	IsGround = false;

	if (nullptr != ColImage)
	{
		// 픽셀충돌에서 제일 중요한건 애초에 박히지 않는것이다.
		FVector2D NextPos = GetActorLocation() + _MovePos;

		UColor Color = ColImage->GetColor(NextPos, UColor::BLACK);
		if (Color == UColor::WHITE)
		{
			IsMove = true;
		}
		else if(Color == UColor::BLACK)
		{
			IsGround = true;
		}
	}
}

//void APlayer::Gravity(float _DeltaTime)
//{
//	if (false == IsGround)
//	{
//		GravityForce += FVector2D::DOWN * _DeltaTime * 0.1f;
//	}
//	else {
//		GravityForce = FVector2D::ZERO;
//	}
//
//	// 상시 
//	AddActorLocation(GravityForce);
//}
