#pragma once
#include <Windows.h>
#include <string>
#include <map>
#include <EngineBase/EngineDelegate.h>
// 정신 잘 붙

// 설명 :
class UEngineWindow
{
public:
	static void EngineWindowInit(HINSTANCE _Instance);
	static void CreateWindowClass(const WNDCLASSEXA& _Class);
	//static bool IsWindowClass(const std::string_view _Text);

	static int WindowMessageLoop(EngineDelegate _FrameFunction);
	//윈도우클래스 생성 
	//윈도우클래스가 만들어 졌는가   

	// constrcuter destructer
	UEngineWindow();
	~UEngineWindow();

	// delete Function
	UEngineWindow(const UEngineWindow& _Other) = delete;
	UEngineWindow(UEngineWindow&& _Other) noexcept = delete;
	UEngineWindow& operator=(const UEngineWindow& _Other) = delete;
	UEngineWindow& operator=(UEngineWindow&& _Other) noexcept = delete;

	void Create(std::string_view _TitleName, std::string_view _ClassName = "Default");
	void Open();
	//create


protected:

private:
	static HINSTANCE hInstance;
	static std::map<std::string, WNDCLASSEXA> WindowClasses;
	// 리눅스에서는 컴파일이 안되거나 실행이 안되는 코드가 된다.
	// hwnd => 위도우 창 1개
	HWND WindowHandle = nullptr;

};

