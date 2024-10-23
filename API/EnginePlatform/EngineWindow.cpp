#include "PreCompile.h"
#include "EngineWindow.h"
#include <EngineBase/EngineDebug.h>
#include <Windows.h>

HINSTANCE UEngineWindow::hInstance = nullptr;
std::map<std::string, WNDCLASSEXA> UEngineWindow::WindowClasses;
int WindowCount = 0;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        //PostQuitMessage(0);
        --WindowCount;
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

void UEngineWindow::EngineWindowInit(HINSTANCE _Instance)
{
    // WNDCLASSEXW => WNDCLASSEXA 멀티바이트로 사용한다.
    //-Register Class-----------------------------------
    hInstance = _Instance;
    WNDCLASSEXA wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance; 
    wcex.hIcon = nullptr;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = "Default"; 
    wcex.hIconSm = nullptr;
    CreateWindowClass(wcex);
}

void UEngineWindow::CreateWindowClass(const WNDCLASSEXA& _Class)
{
    std::map<std::string, WNDCLASSEXA>::iterator EndIter = WindowClasses.end();
    //윈도우가 등록되어 있는지 찾는다.
    std::map<std::string, WNDCLASSEXA>::iterator FindIter = WindowClasses.find(std::string(_Class.lpszClassName));

 
    if (EndIter != FindIter)
    {
        MSGASSERT("같은 이름의 윈도우 클래스를 2번 등록했습니다 " + std::string(_Class.lpszClassName));
        return;
    }
    //윈도우를 등록한다.
    RegisterClassExA(&_Class);

    //등록한 윈도우는 맵에 저장한다. 윈도우 클래스 이름, 클래스 객체 
    WindowClasses.insert(std::pair{ _Class.lpszClassName, _Class });
}

int UEngineWindow::WindowMessageLoop(EngineDelegate _FrameFunction)
{
    MSG msg;

    while (WindowCount)
    {
        // if (!TranslateAccelerator(msg.hwnd, nullptr, &msg))  => 윈도우 단축키 자체를 사용하지
        // 않을 것이므로 그냥 무시

        // PM_REMOVE == 내가 처리할때 지금까지 쌓인 메세지 다지워.
        if (0 != PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        if (true == _FrameFunction.IsBind())
        {
            _FrameFunction();
        }
        // 메세지가 없는 시간에 내 게임을 돌리는거야.
        // 메세지 처리하고 나서 내 게임엔진을 돌린다.
    }


    return (int)msg.wParam;
}
UEngineWindow::UEngineWindow()
{
}
UEngineWindow::~UEngineWindow()
{
}
void UEngineWindow::Create(std::string_view _TitleName, std::string_view _ClassName)
{


    //window class에 윈도우가 등록됬는가?
    if (false == WindowClasses.contains(_ClassName.data()))
    {
        MSGASSERT("등록하지 않은 클래스로 윈도우창을 만들려고 했습니다" + std::string(_ClassName));
        return;
    }
    WindowHandle = CreateWindowA(_ClassName.data(), _TitleName.data(), WS_OVERLAPPEDWINDOW
        , 0, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!WindowHandle)
    {
        MSGASSERT("윈도우 생성에 실패했습니다." + std::string(_TitleName));
        return;
    }

    int a = 0;
}

void UEngineWindow::Open()
{
    if (nullptr == WindowHandle)
    {
        // 윈도우 생성
        Create("Window");
    }

    //윈도우 창을 띄운다.
	ShowWindow(WindowHandle,SW_SHOW);
	UpdateWindow(WindowHandle);
    ++WindowCount;
}
  