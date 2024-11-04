#include "PreCompile.h"
#include "Player.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/ImageManager.h>

APlayer::APlayer()
{
	// UEngineAPICore::GetCore()->CreateLevel("Title");
	//UEngineAPICore::GetCore()->GetMainWindow().GetBackBuffer();
	SetActorLocation({ 150, 325 });

	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite("Idle_Right.png");
	SpriteRenderer->SetComponentScale({ 270, 270 });

	SetName("Kirby");
	UImageManager::GetInst().CuttingSprite("Idle_Left.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("Idle_Right.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("Run_Left.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("Run_Right.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("Jump_Left.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("Jump_Right.png", { 128, 128 });
	SpriteRenderer->CreateAnimation("Idle_Left", "Idle_Left.png", 0, 2, 3.f);
	SpriteRenderer->CreateAnimation("Idle_Right", "Idle_Right.png", 0, 2, 3.f);
	SpriteRenderer->CreateAnimation("Run_Left", "Run_Left.png",  0, 6, 0.1f);
	SpriteRenderer->CreateAnimation("Run_Right", "Run_Right.png",  0, 6, 0.1f);
	SpriteRenderer->CreateAnimation("Jump_Left", "Jump_Left.png",  0, 8, 0.1f);
	SpriteRenderer->CreateAnimation("Jump_Right", "Jump_Right.png",  0, 8, 0.1f);

	SpriteRenderer->ChangeAnimation("Idle_Right");
	//SpriteRenderer->SetAnimationEvent("Run_Right", 2, std::bind(&APlayer::RunSoundPlay, this));

	//std::string Name = SpriteRenderer->GetCurSpriteName();
}

APlayer::~APlayer()
{
}


void APlayer::BeginPlay()
{
	Super::BeginPlay();

	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPivot(Size.Half() * -1.0f);

	
	//키 바인딩
	//인자를 호출할 때 넣어줌을 명시하는 것이 placeholders

	/*UEngineInput::GetInst().BindAction('A', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::LEFT));
	UEngineInput::GetInst().BindAction('D', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::RIGHT));
	UEngineInput::GetInst().BindAction('S', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::DOWN));
	UEngineInput::GetInst().BindAction('W', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::UP));*/
}

void APlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	UEngineDebug::CoreOutPutString("FPS : " + std::to_string(1.0f / _DeltaTime));
	UEngineDebug::CoreOutPutString("PlayerPos : " + GetActorLocation().ToString());

	if (true == UEngineInput::GetInst().IsPress('Z'))
	{
		SpriteRenderer->ChangeAnimation("Jump_Right");
	}
	if (true == UEngineInput::GetInst().IsPress('X'))
	{
		//SpriteRenderer->ChangeAnimation("Run_Right");
		//AddActorLocation(FVector2D::UP * _DeltaTime * Speed);
	}
	if (true == UEngineInput::GetInst().IsPress(VK_LEFT))
	{
		SpriteRenderer->ChangeAnimation("Run_Left");
		AddActorLocation(FVector2D::LEFT * _DeltaTime * Speed);
	}

	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))
	{
		SpriteRenderer->ChangeAnimation("Run_Right");
		AddActorLocation(FVector2D::RIGHT * _DeltaTime * Speed);
	}
	if (false == UEngineInput::GetInst().IsPress(VK_LEFT) &&
		false == UEngineInput::GetInst().IsPress(VK_RIGHT) &&
		false == UEngineInput::GetInst().IsPress(VK_UP) &&
		false == UEngineInput::GetInst().IsPress(VK_DOWN))
	{
		SpriteRenderer->ChangeAnimation("Idle_Right");
	}

}
void APlayer::MoveFunction(FVector2D _Dir/*, AMonster* Monster*/)
{
	// 몬스터를 찾아오는 함수가 존재할것이다.
	// 액터 전체르 관리하기 때문에.
	// 찾아오는 함수가 존재합니다.

	float DeltaTime = UEngineAPICore::GetCore()->GetDeltaTime();

	AddActorLocation(_Dir * DeltaTime * Speed);
}

void APlayer::LevelChangeStart()
{
	Super::LevelChangeStart();
}

void APlayer::LevelChangeEnd()
{
	Super::LevelChangeEnd();


}