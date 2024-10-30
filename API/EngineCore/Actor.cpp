#include "PreCompile.h"
#include "Actor.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineBase/EngineMath.h>
#include <EnginePlatform/EngineWindow.h>
#include <EnginePlatform/EngineWinImage.h>

#include "EngineSprite.h"
#include <EngineBase/EngineDebug.h>

AActor::AActor()
{
}

AActor::~AActor()
{
}


void AActor::Render()
{
	if (nullptr == Sprite)
	{
		MSGASSERT("��������Ʈ�� ���õ��� ���� ���͸� �������� �Ҽ� �����ϴ�.");
	}

	////                  100 100  - 50 50 => 50 50
	//FVector2D LeftTop = Transform.Location - Transform.Scale.Half();
	////                  100 100  + 50 50 => 150 150
	//FVector2D RightBot = Transform.Location + Transform.Scale.Half();



	// // MainWindowDc�� �׸��� �׷����� �ֵ��� ������ ��ĥ��쿡�� �����̴� ���������� ��������.
	// // HDC�� Ư�� ������ ������ ���̴� 2���� ������
	////Rectangle(MainWindow.GetWindowMainDC(), LeftTop.iX(), LeftTop.iY(), RightBot.iX(), RightBot.iY());

	//// 
	//UEngineWindow& MainWindow = UEngineAPICore::GetCore()->GetMainWindow();
	//UEngineWinImage* BackBufferImage = MainWindow.GetBackBuffer();
	//HDC BackBufferDC = BackBufferImage->GetDC();
	//Rectangle(BackBufferDC, LeftTop.iX(), LeftTop.iY(), RightBot.iX(), RightBot.iY());
}



void AActor::SetSprite(std::string_view _Name)
{
}