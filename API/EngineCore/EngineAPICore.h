#pragma once
#include <string>
#include <Windows.h>
#include <EnginePlatform/EngineWindow.h>
#include <EngineBase/EngineTimer.h>

#pragma comment (lib, "EngineBase.lib")
#pragma comment (lib, "EnginePlatform.lib")

#include "Level.h"

// �Լ�������
// �����Լ�

class UContentsCore
{
public:
	virtual void BeginPlay() = 0;
	virtual void Tick() = 0;
};

// UEngineAPICore => �𸮾�� ���� world��� ���� �ִ�.

// ���� :
class UEngineAPICore
{
public:
	// constrcuter destructer
	UEngineAPICore();
	~UEngineAPICore();

	// delete Function
	UEngineAPICore(const UEngineAPICore& _Other) = delete;
	UEngineAPICore(UEngineAPICore&& _Other) noexcept = delete;
	UEngineAPICore& operator=(const UEngineAPICore& _Other) = delete;
	UEngineAPICore& operator=(UEngineAPICore&& _Other) noexcept = delete;

	static int EngineStart(HINSTANCE _Inst, UContentsCore* _UserCore);

	static class UEngineAPICore* GetCore()
	{
		return MainCore;
	}

	UEngineWindow& GetMainWindow()
	{
		return EngineMainWindow;
	}
	float GetDeltaTime()
	{
		return DeltaTimer.GetDeltaTime();
	}

	template<typename GameModeType, typename MainPawnType>
	ULevel* CreateLevel(std::string_view _LevelName)
	{
		ULevel* NewLevel = new ULevel();

		// ���Ӹ�尡 Level�� Ư���� �����Ѵ�.
		NewLevel->CreateGameMode<GameModeType, MainPawnType>();

		Levels.insert({ _LevelName.data() , NewLevel});

		return NewLevel;
	}

	void OpenLevel(std::string_view _LevelName);



protected:

private:
	static void EngineBeginPlay();
	static void EngineTick();
	static UEngineAPICore* MainCore;
	static UContentsCore* UserCore;

	UEngineTimer DeltaTimer = UEngineTimer();
	UEngineWindow EngineMainWindow; // ���� ���� ������

	// ���� ������ �����ڶ�� ������ ��°� ����?

	// ������� ��� ����
	std::map<std::string, class ULevel*> Levels;

	// ���� ���� ������ ���� �־���ϴ� ����
	// ���ư��� �ִ� ����
	// ������ ü���� ���
	class ULevel* CurLevel = nullptr;

	void Tick();

};