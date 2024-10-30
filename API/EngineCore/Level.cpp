#include "PreCompile.h"
#include "Level.h"
#include <EngineCore/EngineAPICore.h>

ULevel::ULevel()
{
}

ULevel::~ULevel()
{
	//if (nullptr != GameMode)
	//{
	//	delete GameMode;
	//	GameMode = nullptr;
	//}

	std::list<AActor*>::iterator StartIter = AllActors.begin();
	std::list<AActor*>::iterator EndIter = AllActors.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		AActor* CurActor = *StartIter;

		if (nullptr != CurActor)
		{
			delete *StartIter;
		}
	}
}

void ULevel::Tick(float _deltaTime)
{
	std::list<AActor*>::iterator StartIter = AllActors.begin();
	std::list<AActor*>::iterator EndIter = AllActors.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		AActor* CurActor = *StartIter;

		CurActor->Tick(_deltaTime);
	}
}

void ULevel::Render()
{
	ScreenClear();
	// ���͸� ������� �������� �����°� �� ������ �̴ϴ�.
	std::list<AActor*>::iterator StartIter = AllActors.begin();
	std::list<AActor*>::iterator EndIter = AllActors.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		AActor* CurActor = *StartIter;

		CurActor->Render();
	}

	DoubleBuffering();
}
void ULevel::ScreenClear()
{
	UEngineWindow& MainWindow = UEngineAPICore::GetCore()->GetMainWindow();
	UEngineWinImage* BackBufferImage = MainWindow.GetBackBuffer();
	FVector2D Size = MainWindow.GetWindowSize();

	Rectangle(BackBufferImage->GetDC(), 0, 0, Size.iX(), Size.iY());
}


void ULevel::DoubleBuffering()
{
	// ������ �������� ������.
	UEngineWindow& MainWindow = UEngineAPICore::GetCore()->GetMainWindow();

	UEngineWinImage* WindowImage = MainWindow.GetWindowImage();
	UEngineWinImage* BackBufferImage = MainWindow.GetBackBuffer();

	FTransform Trans;
	Trans.Location = MainWindow.GetWindowSize().Half();
	Trans.Scale = MainWindow.GetWindowSize();

	// �̹��� ���� ����ۿ� �� �׷����� ���̴�.
	BackBufferImage->CopyToBit(WindowImage, Trans);

}