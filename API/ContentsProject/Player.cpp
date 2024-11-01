#include "PreCompile.h"
#include "Player.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineAPICore.h>

APlayer::APlayer()
{
	// UEngineAPICore::GetCore()->CreateLevel("Title");
	//UEngineAPICore::GetCore()->GetMainWindow().GetBackBuffer();
	SetActorLocation({ 100, 100 });

	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite("KirbyDance.png");
	SpriteRenderer->SetComponentScale({ 150, 150 });
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

	if (true == UEngineInput::GetInst().IsDown('R'))
	{
		UEngineAPICore::GetCore()->OpenLevel("Title");
		// UEngineDebug::SwitchIsDebug();
	}
	if (true == UEngineInput::GetInst().IsPress('D'))
	{
		AddActorLocation(FVector2D::RIGHT * _DeltaTime * Speed);
	}
	if (true == UEngineInput::GetInst().IsPress('A'))
	{
		AddActorLocation(FVector2D::LEFT * _DeltaTime * Speed);
	}
	if (true == UEngineInput::GetInst().IsPress('S'))
	{
		AddActorLocation(FVector2D::DOWN * _DeltaTime * Speed);
	}
	if (true == UEngineInput::GetInst().IsPress('W'))
	{
		AddActorLocation(FVector2D::UP * _DeltaTime * Speed);
	}

	if (true == UEngineInput::GetInst().IsDown('R'))
	{
		/*SpriteRenderer->SetSprite("KirbyDance.png", MySpriteIndex);
		++MySpriteIndex;*/
		UEngineAPICore::GetCore()->OpenLevel("Title");
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