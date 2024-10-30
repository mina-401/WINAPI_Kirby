#include "PreCompile.h"
#include "Player.h"
#include <EnginePlatform/EngineInput.h>

#include <EngineCore/EngineAPICore.h>

APlayer::APlayer()
{
	// UEngineAPICore::GetCore()->CreateLevel("Title");
	//UEngineAPICore::GetCore()->GetMainWindow().GetBackBuffer();
	SetActorLocation({100, 100});
	SetActorScale({ 100, 100 });
}

APlayer::~APlayer()
{
}


void APlayer::BeginPlay()
{

	//Ű ���ε�
	//���ڸ� ȣ���� �� �־����� ����ϴ� ���� placeholders

	/*UEngineInput::GetInst().BindAction('A', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::LEFT));
	UEngineInput::GetInst().BindAction('D', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::RIGHT));
	UEngineInput::GetInst().BindAction('S', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::DOWN));
	UEngineInput::GetInst().BindAction('W', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::UP));*/

	



}

void APlayer::Tick(float _DeltaTime)
{
	//if (3.0f < UEngineInput::GetInst().IsPressTime(VK_LBUTTON))
	//{
	//	// �ֿܼ��� ���� ������� API�ͼ��� ��������.
	//	MoveFunction(FVector2D::RIGHT);
	//}
}
void APlayer::MoveFunction(FVector2D _Dir/*, AMonster* Monster*/)
{
	// ���͸� ã�ƿ��� �Լ��� �����Ұ��̴�.
	// ���� ��ü�� �����ϱ� ������.
	// ã�ƿ��� �Լ��� �����մϴ�.

	float DeltaTime = UEngineAPICore::GetCore()->GetDeltaTime();

	AddActorLocation(_Dir * DeltaTime * Speed);
}

