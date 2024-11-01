#include "PreCompile.h"
#include "EngineAPICore.h"
#include <EnginePlatform/EngineInput.h>
#include <EnginePlatform/EngineWindow.h>
#include <EngineBase/EngineDelegate.h>
#include <EngineBase/EngineDebug.h>

// ������ ��Ʋ� 1�� ��������� ������.
// 1�� ���õǰ� ����� �ٲ��� �����Ŵ�.
UEngineAPICore* UEngineAPICore::MainCore = nullptr;
UContentsCore* UEngineAPICore::UserCore = nullptr;


UEngineAPICore::UEngineAPICore()
{
	MainCore = this;
}

UEngineAPICore::~UEngineAPICore()
{
	std::map<std::string, class ULevel*>::iterator StartIter = Levels.begin();
	std::map<std::string, class ULevel*>::iterator EndIter = Levels.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		if (nullptr != StartIter->second)
		{
			delete StartIter->second;
			StartIter->second = nullptr;
		}
	}

	Levels.clear();
}


int UEngineAPICore::EngineStart(HINSTANCE _Inst, UContentsCore* _UserCore)
{
	//�� üũ
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	UserCore = _UserCore;

	UEngineWindow::EngineWindowInit(_Inst);

	UEngineAPICore Core = UEngineAPICore();
	Core.EngineMainWindow.Open();
	//MainCore = &Core; //�����ڿ��� MainCore = this�� ����

	//����: user begin, tick -> engine level tick, render
	EngineDelegate Start = EngineDelegate(std::bind(EngineBeginPlay));
	EngineDelegate FrameLoop = EngineDelegate(std::bind(EngineTick));;
	return UEngineWindow::WindowMessageLoop(Start, FrameLoop);
}

void UEngineAPICore::EngineBeginPlay()
{
	UserCore->BeginPlay();
}

void UEngineAPICore::EngineTick()
{

	// �ð����
	// �̺�Ʈ
	// ������
	// �浹
	UserCore->Tick();

	// MainCore->TimeCheck();
	MainCore->Tick();
	// MainCore->Render();
	// MainCore->Collision();
}

void UEngineAPICore::Tick()
{
	if (nullptr != NextLevel)
	{
		// �������� �Դٰ��� �Ҷ��� �ֱ� ������.
		// �� �������� �����е��� ������ ���ְ� �������� �ִ�.

		if (nullptr != CurLevel)
		{
			CurLevel->LevelChangeEnd();
		}

		CurLevel = NextLevel;

		NextLevel->LevelChangeStart();

		NextLevel = nullptr;
		// ��ŸŸ���� �����ɼ� �����Ƿ� ��ŸŸ���� �ʱ�ȭ�����ִ°��� ����.
		DeltaTimer.TimeStart();
	}
	// �ð��� ��̴ϴ�. ����ð� 
	DeltaTimer.TimeCheck();
	float DeltaTime = DeltaTimer.GetDeltaTime();

	// Űüũ
	UEngineInput::GetInst().KeyCheck(DeltaTime);

	if (nullptr == CurLevel)
	{
		MSGASSERT("���� �ھ ���� ������ �������� �ʾҽ��ϴ�");
		return;
	}

	UEngineInput::GetInst().EventCheck(DeltaTime);
	CurLevel->Tick(DeltaTime);
	CurLevel->Render(DeltaTime);
}


void UEngineAPICore::OpenLevel(std::string_view _LevelName)
{
	std::string ChangeName = _LevelName.data();

	//if (false == Levels.contains(ChangeName))
	//{
	//	MSGASSERT(ChangeName + "��� �̸��� ������ �������� �ʽ��ϴ�.");
	//	return;
	//}

	// // �ֽ� ���
	// //���ο��� ������ �����.
	// CurLevel = Levels[ChangeName];

	std::map<std::string, class ULevel*>::iterator FindIter = Levels.find(ChangeName);
	std::map<std::string, class ULevel*>::iterator EndIter = Levels.end();

	if (EndIter == FindIter)
	{
		MSGASSERT(ChangeName + "��� �̸��� ������ �������� �ʽ��ϴ�.");
		return;
	}

	//// �ֽ� ���
	 NextLevel = FindIter->second;
}