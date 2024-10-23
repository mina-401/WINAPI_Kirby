#pragma once
#include <functional>
// 설명 :
class EngineDelegate
{
public:
	// constrcuter destructer
	EngineDelegate();
	~EngineDelegate();

	// delete Function
	//EngineDelegate(const EngineDelegate& _Other) = delete;
	//EngineDelegate(EngineDelegate&& _Other) noexcept = delete;
	//EngineDelegate& operator=(const EngineDelegate& _Other) = delete;
	//EngineDelegate& operator=(EngineDelegate&& _Other) noexcept = delete;

	bool IsBind()
	{
		return false == Functions.empty();
	}
	void operator=(std::function<void()> _Function)
	{
		Functions.push_back(_Function);
	}
	void operator()()
	{
		std::list<std::function<void()>>::iterator StartIter = Functions.begin();
		std::list<std::function<void()>>::iterator EndIter = Functions.end();

		//다 돌아서 델리게이트 function 실행
		for (; StartIter != EndIter; ++StartIter)
		{
			std::function<void()>& Function = *StartIter;
			Function();
		}
	}
	void Clear()
	{
		Functions.clear();
	}

protected:

private:
	std::list<std::function<void()>> Functions;
};

