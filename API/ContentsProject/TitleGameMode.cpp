#include "PreCompile.h"
#include "TitleGameMode.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
#include "Player.h"


ATitleGameMode::ATitleGameMode()
{
}

ATitleGameMode::~ATitleGameMode()
{
}

void ATitleGameMode::ClickFunction(int _KeyIndex)
{
	//int a;
	//switch (_KeyIndex)
	//{
	//case VK_LBUTTON:
	//	//UEngineAPICore::GetCore()->CreateLevel<APlayGameMode, APlayer>("Title");
	//	/*UEngineAPICore::GetCore()->CreateLevel<ATitleGameMode, APlayer>("Play");
	//	UEngineAPICore::GetCore()->OpenLevel("Play");*/
	//	break;
	//default:
	//	break;
	//}
}

void ATitleGameMode::Tick(float _DeltaTime)
{
//	if (true == UEngineInput::GetInst().IsDown(VK_LBUTTON))
//	{
//		// �ֿܼ��� ���� ������� API�ͼ��� ��������.
//		ClickFunction(VK_LBUTTON);
//	}
}

