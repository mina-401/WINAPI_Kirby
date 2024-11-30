#include "PreCompile.h"
#include "EngineAPICore.h"
#include <EnginePlatform/EngineInput.h>

#include <EnginePlatform/EngineWindow.h>
#include <EnginePlatform/EngineSound.h>
#include <EngineBase/EngineDelegate.h>
#include <EngineBase/EngineDebug.h>



// ������ ��Ʋ� 1�� ��������� ������.
// 1�� ���õǰ� ����� �ٲ��� �����Ŵ�.
UEngineAPICore* UEngineAPICore::MainCore = nullptr;
UContentsCore* UEngineAPICore::UserCore = nullptr;

#include <Windows.h>
// 1 ���� �ʴ� ��ư�� 1�� ������
//QueryPerformanceCounter

// 3 ������� 3�� ������� 
//QueryPerformanceFrequency

// #include <chrono>

UEngineAPICore::UEngineAPICore()
{

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

	UEngineSound::Release();
}


int UEngineAPICore::EngineStart(HINSTANCE _Inst, UContentsCore* _UserCore)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	UserCore = _UserCore;

	UEngineWindow::EngineWindowInit(_Inst);

	// ��ü �ȸ���� ��ü������ �ƴѰ� ���Ƽ� ��ü�� ����.
	// ������ ����� ����Ǿ� �ִ�. CreateLevel;
	UEngineAPICore Core = UEngineAPICore();
	Core.EngineMainWindow.Open();
	MainCore = &Core;

	EngineDelegate Start = EngineDelegate(std::bind(EngineBeginPlay));
	EngineDelegate FrameLoop = EngineDelegate(std::bind(EngineTick));;
	return UEngineWindow::WindowMessageLoop(Start, FrameLoop);
}

void UEngineAPICore::EngineBeginPlay()
{
	UserCore->BeginPlay();
}

// �� �Լ��� 1�ʿ� ��� ����ǳİ� �������Դϴ�.
void UEngineAPICore::EngineTick()
{


	//AXVidio NewVidio;
	//NewVidio.Play("AAAA.avi");

	// �ð����
	// �̺�Ʈ
	// ������
	// �浹


	// ���� ���� �뵵�� ã�� ���ؼ� ������� �ʴ� �Լ��Դϴ�.
	UserCore->Tick();

	// MainCore->TimeCheck();
	MainCore->Tick();
	// MainCore->Render();
	// MainCore->Collision();
}

void UEngineAPICore::Tick()
{
	if (true == IsCurLevelReset)
	{
		delete CurLevel;
		CurLevel = nullptr;
		IsCurLevelReset = false;
	}



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

	DeltaTime *= GlobalTimeScale;

	// ������� �Ѵ�.
	UEngineSound::Update();

	// Űüũ
	UEngineInput::GetInst().KeyCheck(DeltaTime);

	if (nullptr == CurLevel)
	{
		MSGASSERT("���� �ھ ���� ������ �������� �ʾҽ��ϴ�");
		return;
	}

	UEngineInput::GetInst().EventCheck(DeltaTime);
	CurLevel->Tick(DeltaTime);
	//  UEngineInput::GetInst().EventCheck(DeltaTime);
	CurLevel->Render(DeltaTime);

	// ���� �̰� �Ⱦ��Ѵ�.
	CurLevel->Collision(DeltaTime);

	// ƽ���� �������� ������
	CurLevel->Release(DeltaTime);
}


void UEngineAPICore::OpenLevel(std::string_view _LevelName)
{
	std::string UpperName = UEngineString::ToUpper(_LevelName);


	std::map<std::string, class ULevel*>::iterator FindIter = Levels.find(UpperName);
	std::map<std::string, class ULevel*>::iterator EndIter = Levels.end();

	if (EndIter == FindIter)
	{
		MSGASSERT(UpperName + " ��� �̸��� ������ �������� �ʽ��ϴ�.");
		return;
	}

	NextLevel = FindIter->second;

}