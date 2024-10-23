#pragma once
#include <Windows.h>
#include <string>
#include <map>
#include <EngineBase/EngineDelegate.h>
// ���� �� ��

// ���� :
class UEngineWindow
{
public:
	static void EngineWindowInit(HINSTANCE _Instance);
	static void CreateWindowClass(const WNDCLASSEXA& _Class);
	//static bool IsWindowClass(const std::string_view _Text);

	static int WindowMessageLoop(EngineDelegate _FrameFunction);
	//������Ŭ���� ���� 
	//������Ŭ������ ����� ���°�   

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
	// ������������ �������� �ȵǰų� ������ �ȵǴ� �ڵ尡 �ȴ�.
	// hwnd => ������ â 1��
	HWND WindowHandle = nullptr;

};

