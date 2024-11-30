#pragma once
#include <string>
// �����е��� ���⿡�ٰ� �̷��� Ư�� ����� ������
// F5�� ����������. #include <Windows.h>�� ���� �ȴ�.
// �̸������ϵ� ����� ����ϸ�
// �̸������ϵ� ����� �־��� ����� ��带�ϸ� .pch���Ͽ� ������� ����
// ���Ŀ��� ������ �ʴ´�.
// ������ �ð��� 
#include <Windows.h>
#include <EnginePlatform/EngineWindow.h>
#include <EngineBase/EngineTimer.h>
#include <EngineBase/EngineString.h>

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
		std::string UpperName = UEngineString::ToUpper(_LevelName);

		if (false != Levels.contains(UpperName))
		{
			MSGASSERT("�����ϴ� �̸��� ������ �� ����� �����ϴ�" + UpperName);
			return nullptr;
		}


		ULevel* NewLevel = new ULevel();

		// ���� ��尡 ������ Ư���� �����ϴ� �߿��� ��ü
		NewLevel->CreateGameMode<GameModeType, MainPawnType>();
		NewLevel->SetName(UpperName);


		// ������ string���� �����ϰ� string���� ȣ���Ѵ�.
		Levels.insert({ UpperName, NewLevel });

		return NewLevel;
	}


	template<typename GameModeType, typename MainPawnType>
	void ResetLevel(std::string_view _LevelName)
	{
		// DestroyLevelName = _LevelName;
		std::string UpperName = UEngineString::ToUpper(_LevelName);

		// ���� ���� �̳༮�� ����� �ȵȴ�.
		if (CurLevel->GetName() != UpperName)
		{
			DestroyLevel(_LevelName);
			CreateLevel<GameModeType, MainPawnType>(UpperName);
			return;
		}

		// CurLevel�� �����Ǿ�� �Ѵ�.
		// ���� �����ʹ� ����ִ�. CurLevel
		std::map<std::string, class ULevel*>::iterator FindIter = Levels.find(UpperName);
		Levels.erase(FindIter);
		NextLevel = CreateLevel<GameModeType, MainPawnType>(UpperName);
		IsCurLevelReset = true;
	}

	void DestroyLevel(std::string_view _LevelName)
	{
		std::string UpperName = UEngineString::ToUpper(_LevelName);

		if (false == Levels.contains(UpperName))
		{
			// MSGASSERT("�������� �ʴ� ������ �����Ҽ� �����ϴ�." + UpperName);
			return;
		}

		std::map<std::string, class ULevel*>::iterator FindIter = Levels.find(UpperName);

		if (nullptr != FindIter->second)
		{
			delete FindIter->second;
			FindIter->second = nullptr;
		}

		Levels.erase(FindIter);
	}


	void OpenLevel(std::string_view _LevelName);

	void SetGlobalTimeScale(float _Scale)
	{
		GlobalTimeScale = _Scale;
	}


protected:

private:
	static void EngineBeginPlay();
	static void EngineTick();
	static UEngineAPICore* MainCore;
	static UContentsCore* UserCore;

	UEngineTimer DeltaTimer = UEngineTimer();
	UEngineWindow EngineMainWindow = UEngineWindow(); // ���� ���� ������

	// ���� ������ �����ڶ�� ������ ��°� ����?

	// ������� ��� ����
	std::map<std::string, class ULevel*> Levels;

	// ���� ���� ������ ���� �־���ϴ� ����
	// ���ư��� �ִ� ����
	// ������ ü���� ���
	class ULevel* CurLevel = nullptr;
	class ULevel* NextLevel = nullptr;
	bool IsCurLevelReset = false;

	float GlobalTimeScale = 1.0f;

	void Tick();

};