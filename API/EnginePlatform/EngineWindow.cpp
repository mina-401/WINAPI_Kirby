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
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
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
    // WNDCLASSEXW => WNDCLASSEXA ��Ƽ����Ʈ�� ����Ѵ�.
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
    //�����찡 ��ϵǾ� �ִ��� ã�´�.
    std::map<std::string, WNDCLASSEXA>::iterator FindIter = WindowClasses.find(std::string(_Class.lpszClassName));

 
    if (EndIter != FindIter)
    {
        MSGASSERT("���� �̸��� ������ Ŭ������ 2�� ����߽��ϴ� " + std::string(_Class.lpszClassName));
        return;
    }
    //�����츦 ����Ѵ�.
    RegisterClassExA(&_Class);

    //����� ������� �ʿ� �����Ѵ�. ������ Ŭ���� �̸�, Ŭ���� ��ü 
    WindowClasses.insert(std::pair{ _Class.lpszClassName, _Class });
}

int UEngineWindow::WindowMessageLoop(EngineDelegate _FrameFunction)
{
    MSG msg;

    while (WindowCount)
    {
        // if (!TranslateAccelerator(msg.hwnd, nullptr, &msg))  => ������ ����Ű ��ü�� �������
        // ���� ���̹Ƿ� �׳� ����

        // PM_REMOVE == ���� ó���Ҷ� ���ݱ��� ���� �޼��� ������.
        if (0 != PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        if (true == _FrameFunction.IsBind())
        {
            _FrameFunction();
        }
        // �޼����� ���� �ð��� �� ������ �����°ž�.
        // �޼��� ó���ϰ� ���� �� ���ӿ����� ������.
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


    //window class�� �����찡 ��ω�°�?
    if (false == WindowClasses.contains(_ClassName.data()))
    {
        MSGASSERT("������� ���� Ŭ������ ������â�� ������� �߽��ϴ�" + std::string(_ClassName));
        return;
    }
    WindowHandle = CreateWindowA(_ClassName.data(), _TitleName.data(), WS_OVERLAPPEDWINDOW
        , 0, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!WindowHandle)
    {
        MSGASSERT("������ ������ �����߽��ϴ�." + std::string(_TitleName));
        return;
    }

    int a = 0;
}

void UEngineWindow::Open()
{
    if (nullptr == WindowHandle)
    {
        // ������ ����
        Create("Window");
    }

    //������ â�� ����.
	ShowWindow(WindowHandle,SW_SHOW);
	UpdateWindow(WindowHandle);
    ++WindowCount;
}
  