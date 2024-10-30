#pragma once
#include <EngineBase/EngineDelegate.h>
#include <EngineBase/EngineDebug.h>

#include <vector>
#include <functional>

enum class KeyEvent
{
	Down,
	Press,
	Free,
	Up,
};
class UEngineInput
{
public:
	// constrcuter destructer
	~UEngineInput();

	// delete Function
	UEngineInput(const UEngineInput& _Other) = delete;
	UEngineInput(UEngineInput&& _Other) noexcept = delete;
	UEngineInput& operator=(const UEngineInput& _Other) = delete;
	UEngineInput& operator=(UEngineInput&& _Other) noexcept = delete;

	// 크게 포인터형과 값형으로 나눈다.
	static UEngineInput& GetInst()
	{
		//클래스 내부의 static은 외부 공개가 까다로움
		static UEngineInput Inst = UEngineInput(); //지역 static
		return Inst;
	}

	//------------------------------
	// 포인터형의 장점은 딱 1개이다.
	//static UEngineInput* GetInst()
	//{
	//	if (nullptr == Inst)
	//	{
	//		Inst = new UEngineInput();
	//	}

	//	return Inst;
	//}

	//// 한쌍의 삭제함수를 무조건 만들어줘야 한다.
	//static void DestroyInst()
	//{
	//	if (nullptr != Inst)
	//	{
	//		delete Inst;
	//		Inst = nullptr;
	//	}
	//}
	// ----------------------------------

protected:
private:
	class UEngineKey
	{
	public:
		int Key = -1;

		// 키가 안눌리다가 처음 눌렸을때
		bool IsDown = false;

		// 키가 눌린 이후로 계속 누르고 있을때
		bool IsPress = false;

		// 키가 눌리다가 땠을때
		bool IsUp = false;

		// 키가 안누르고 있을때
		bool IsFree = true;

		float PressTime = 0.0f;

		std::vector<std::function<void()>> PressEvents;
		std::vector<std::function<void()>> DownEvents;
		std::vector<std::function<void()>> UpEvents;
		std::vector<std::function<void()>> FreeEvents;


		// 벡터나 리스트를 사용하면 에러가 난다.
		// 학생들이 대처를 못하는데
		// 결국 맨위로 올라가면 됩니다.

		UEngineKey()
		{
		}

		UEngineKey(int _Key)
			: Key(_Key)
		{
		}

		void EventCheck();

		void KeyCheck(float _DeltaTime);

	};


public:
	void KeyCheck(float _DeltaTime);
	void EventCheck(float _DeltaTime);

	bool IsDown(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("아직도 등록되지 않은 키가 존재합니다.");
			return false;
		}
		return Keys[_KeyIndex].IsDown;
	}

	bool IsUp(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("아직도 등록되지 않은 키가 존재합니다.");
			return false;
		}

		return Keys[_KeyIndex].IsUp;
	}

	bool IsPress(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("아직도 등록되지 않은 키가 존재합니다.");
			return false;
		}

		return Keys[_KeyIndex].IsPress;
	}

	float IsPressTime(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("아직도 등록되지 않은 키가 존재합니다.");
			return false;
		}

		return Keys[_KeyIndex].PressTime;
	}


	bool IsFree(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("아직도 등록되지 않은 키가 존재합니다.");
			return false;
		}

		return Keys[_KeyIndex].IsFree;
	}

	void BindAction(int _KeyIndex, KeyEvent _EventType, std::function<void()> _Function);

private:

	//전역 static. 여기서는안씀
	//static UEngineInput* Inst;

	//다른데서 생성하지 못하도록 한다.
	std::map<int, UEngineKey> Keys;

	UEngineInput();


};

