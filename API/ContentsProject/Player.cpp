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
	SpriteRenderer->CreateAnimation("Jump_Left", "Jump_Left.png",  0, 8, 0.1f, false);
	SpriteRenderer->CreateAnimation("Jump_Right", "Jump_Right.png",  0, 8, 0.1f), false;
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


	ChangeState(PlayerState::Idle);
	
	//Ű ���ε�
	//���ڸ� ȣ���� �� �־����� ����ϴ� ���� placeholders

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

	UEngineDebug::CoreOutPutString("FPS : " + std::to_string(1.0f / _DeltaTime));
	UEngineDebug::CoreOutPutString("PlayerPos : " + GetActorLocation().ToString());

	/*FTransform PlayerTransform = GetTransform();
	PlayerTransform.Location += FVector2D(20, 0) - GetWorld()->GetCameraPos();
	PlayerTransform.Scale = { 6,6 };
	UEngineDebug::CoreDebugRender(PlayerTransform, UEngineDebug::EDebugPosType::Circle);*/

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

	//PlayerCameraCheck();
	PlayerGroundCheck(GravityForce);
	Gravity(_DeltaTime);

	//PlayerGroundCheck(FVector2D::ZERO);

	if (true == IsDebug)
	{
		if (true == UEngineInput::GetInst().IsPress(VK_LEFT) ||
			true == UEngineInput::GetInst().IsPress(VK_RIGHT) ||
			true == UEngineInput::GetInst().IsPress(VK_DOWN))
		{

			ChangeState(PlayerState::Move);
			return;
		}
	}
	else {
		if (true == UEngineInput::GetInst().IsPress(VK_LEFT) ||
			true == UEngineInput::GetInst().IsPress(VK_RIGHT))

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

	//Accel(_DeltaTime, FVector2D::ZERO);
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
	SpriteRenderer->ChangeAnimation("Jump_Right");
	if (true == UEngineInput::GetInst().IsPress(VK_LEFT)) SpriteRenderer->ChangeAnimation("Jump_Left");
	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT)) SpriteRenderer->ChangeAnimation("Jump_Right");
}
void APlayer::Jump(float _DeltaTime)
{
	PlayerGroundCheck(GravityForce);
	FVector2D Vector = FVector2D::ZERO;

	if (true == UEngineInput::GetInst().IsPress(VK_LEFT)) Vector = FVector2D::LEFT;
	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))  Vector = FVector2D::RIGHT;


	UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
	if (Color == UColor::BLACK)
	{
		UColor NextColor = ColImage->GetColor(GetActorLocation() + Vector, UColor::WHITE);
		if (NextColor != UColor::BLACK)
			AddActorLocation(Vector); //���� �������� �̵�


	}
	else
		AddActorLocation(Vector * Speed * _DeltaTime);

	if (CurrJumpTime > JumpTime)
	{
		if (true == IsGround)
		{
			CurrJumpTime = 0;
			ChangeState(PlayerState::Idle);
			return;
		}
		JumpDown(_DeltaTime);
	}
	else {
		CurrJumpTime += 0.2f;
		JumpUp(_DeltaTime);
	}
	//if (true == UEngineInput::GetInst().IsPress('Z'))
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
		ChangeState(PlayerState::Slide);
		return;
	}
	if (true == UEngineInput::GetInst().IsPress('Z'))
	{
		ChangeState(PlayerState::Jump);
		return;
	}
	if (false == UEngineInput::GetInst().IsPress(VK_LEFT) &&
		false == UEngineInput::GetInst().IsPress(VK_RIGHT) &&
		false == UEngineInput
		::GetInst().IsPress(VK_UP) &&
		false == UEngineInput::GetInst().IsPress(VK_DOWN))
	{
		ChangeState(PlayerState::Idle);
		return;
	}


	UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
	if (Color == UColor::BLACK)
	{
		UColor NextColor = ColImage->GetColor(GetActorLocation() + FVector2D::UP * 3, UColor::WHITE);
		if (NextColor != UColor::BLACK)
			AddActorLocation(FVector2D::UP); //���� �������� �̵�


	}
	else
		AddActorLocation(Vector * Speed * _DeltaTime);

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
	if (CurrSlideTime >SlideTime)
	{
		CurrSlideTime = 0;
		ChangeState(PlayerState::Idle);
		
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
		// �ȼ��浹���� ���� �߿��Ѱ� ���ʿ� ������ �ʴ°��̴�.
		FVector2D NextPos = GetActorLocation() + _MovePos;

		//NextPos.X = floorf(NextPos.X);
		//NextPos.Y = floorf(NextPos.Y);

		UColor Color = ColImage->GetColor(NextPos, UColor::WHITE);
		if (Color == UColor::WHITE)
		{
			IsGround = false;
		}
		else if (Color == UColor::BLACK)
		{
			IsGround = true;
			// ���� ������ ���������� �÷��ִ� ��ɵ� �Բ� ����ų� �ؾ��Ѵ�.
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

	//	// �� ���� white, �Ʒ��� black �̸� 
	//	UColor ColorNext = ColImage->GetColor(PlayerTransformNext.Location, UColor::WHITE);
	//	UColor ColorDown = ColImage->GetColor(PlayerTransformDown.Location, UColor::WHITE);
	//	if (ColorNext == UColor::WHITE && ColorDown == UColor::BLACK) AddActorLocation(FVector2D::DOWN * 5);

	//	UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
	//	if (Color == UColor::BLACK) break;
	//	else break;

	//}
}
