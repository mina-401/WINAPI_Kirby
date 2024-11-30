#include "PreCompile.h"
#include "EngineWindow.h"
#include <EngineBase/EngineDebug.h>

//class AActor
//{
//    Player* NewPlayer; // <= ���ߴ�.
//};
//
//class Player : public AActor
//{
//
//};

// ������ ���� ����� ������ ���� 
// #include <EngineCore/EngineAPICore.h>

//#ifdef _WINDOWS
//#include <Windows.h>
//#elseif _������
//#include <Windows.h>
//#elseif �ȵ���̵�
//#endif 

HINSTANCE UEngineWindow::hInstance = nullptr;
std::map<std::string, WNDCLASSEXA> UEngineWindow::WindowClasss;
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
    //case WM_SIZING:
    //{
    //    int a = 0;
    //}
    break;
    case WM_DESTROY:
        --WindowCount;
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


void UEngineWindow::EngineWindowInit(HINSTANCE _Instance)
{
    hInstance = _Instance;

    // ������ ������ ����� �Ѵٸ� ���⼭ �Ϸ��� �Ѱ�.
    // ����Ʈ ������ Ŭ���� ���
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

int UEngineWindow::WindowMessageLoop(EngineDelegate _StartFunction, EngineDelegate _FrameFunction)
{
    // ����Ű �ε� ����
    // HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT2));
    MSG msg = MSG();

    // �⺻ �޽��� �����Դϴ�:
    // �޼��� ������ getMessage��� ������ ������ ������ ����.
    // ���� �Լ��̱� �����̴�.
    // ���� �ڽ��� ������ ���������� �����ϴ� �Լ�.

    // GetMessage
    // �޼����� ���� => ������ ��ٸ�
    // �޼����� �ִ� => ó���ϰ� ����

    // ó���ϰ� ����
    // �޼����� ���� => ����
    // �޼����� �ִ� => ó���ϰ� ����

    // WindowCount;

    // ���α׷� �����ϰ� �� 1�� �ؾ����� �ִٸ� ���⿡ �־��.
    // �ִ��� ����ó�� ���ִ°� ����.
    if (true == _StartFunction.IsBind())
    {
        _StartFunction();
    }

    while (0 != WindowCount)
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

void UEngineWindow::CreateWindowClass(const WNDCLASSEXA& _Class)
{
    // �Ϲ����� ���� ����

    std::map<std::string, WNDCLASSEXA>::iterator EndIter = WindowClasss.end();
    std::map<std::string, WNDCLASSEXA>::iterator FindIter = WindowClasss.find(std::string(_Class.lpszClassName));

    // ckw
    if (EndIter != FindIter)
    {
        // std::string ErrorText = "���� �̸��� ������ Ŭ������ 2�� ����߽��ϴ�" + std::string(_Class.lpszClassName);

        // std::string ���ο� ��� �ִ� �ɹ����� => std::string => std::vector<char>
        // std::vector<char> char* = new char[100];
        // ErrorText const char* �������ִ� �Լ��� c_str()
        // const char* Text = ErrorText.c_str();
        MSGASSERT(std::string(_Class.lpszClassName) + " ���� �̸��� ������ Ŭ������ 2�� ����߽��ϴ�");
        return;
    }

    RegisterClassExA(&_Class);

    WindowClasss.insert(std::pair{ _Class.lpszClassName, _Class });
}

UEngineWindow::UEngineWindow()
{

}

UEngineWindow::~UEngineWindow()
{
    if (nullptr != WindowImage)
    {
        delete WindowImage;
        WindowImage = nullptr;
    }

    if (nullptr != BackBufferImage)
    {
        delete BackBufferImage;
        BackBufferImage = nullptr;
    }

    // �������ϴ� ������ �ظ��ϸ� ������� ������ ������ ����.
    if (nullptr != WindowHandle)
    {
        DestroyWindow(WindowHandle);
        WindowHandle = nullptr;
    }
}

void UEngineWindow::Create(std::string_view _TitleName, std::string_view _ClassName)
{
    if (false == WindowClasss.contains(_ClassName.data()))
    {
        MSGASSERT(std::string(_ClassName) + " ������� ���� Ŭ������ ������â�� ������� �߽��ϴ�");
        return;
    }

    WindowHandle = CreateWindowA(_ClassName.data(), _TitleName.data(), WS_OVERLAPPEDWINDOW,
        0, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (nullptr == WindowHandle)
    {
        MSGASSERT(std::string(_TitleName) + " ������ ������ �����߽��ϴ�.");
        return;
    }

    // �����찡 ��������� hdc�� ���⼭ ���� �̴ϴ�.
    HDC WindowMainDC = GetDC(WindowHandle);

    // nullptr�� �ƴϰ� ���� ���� ���� ��¥ ������ ���۰� ���������.
    WindowImage = new UEngineWinImage();
    // �̰� ����ٴ� ������ �ƴϴ�.
    WindowImage->Create(WindowMainDC);
}

void UEngineWindow::Open(std::string_view _TitleName /*= "Window"*/)
{
    // �� window �ȸ���� ������ �ϳ�?
    if (0 == WindowHandle)
    {
        // �����
        Create(_TitleName);
    }

    if (0 == WindowHandle)
    {
        return;
    }

    // �ܼ��� ����â�� �����ִ� �͸��� �ƴ϶�
    ShowWindow(WindowHandle, SW_SHOW);
    UpdateWindow(WindowHandle);
    ++WindowCount;
    // ShowWindow(WindowHandle, SW_HIDE);
}

void UEngineWindow::SetWindowPosAndScale(FVector2D _Pos, FVector2D _Scale)
{
    // ������ ũ��� �޶��������� ����۸� ���� ���� ���̴�.
    if (false == WindowSize.EqualToInt(_Scale))
    {
        // ȭ���� ũ��� ���� ������ ũ�⿩�� �Ѵ�.
        // ������ ȣ���ϸ� ������ ������� �༮�� Leck�� �ǹǷ�
        // ȭ��ũ�⸦ ������ ������ ��������� �Ѵ�.
        if (nullptr != BackBufferImage)
        {
            // ���� ����۴� ����������
            delete BackBufferImage;
            BackBufferImage = nullptr;
        }

        BackBufferImage = new UEngineWinImage();
        BackBufferImage->Create(WindowImage, _Scale);
    }

    WindowSize = _Scale;

    RECT Rc = { 0, 0, _Scale.iX(), _Scale.iY() };

    // �̰� �� ������ִ� �Լ��̴�.
    // Ÿ��Ʋ�� ũ����� ������ ũ��� �ش�.
    // ������ ����
    // ���� �������� ��Ÿ���� �־���� �Ѵ�.

    // �׷��� �� �̳༮�� 
    // �����쿡�� �������� ��ġ�� ������ ũ�⸦ �ְ� �ȴ�.
    AdjustWindowRect(&Rc, WS_OVERLAPPEDWINDOW, FALSE);

    ::SetWindowPos(WindowHandle, nullptr, _Pos.iX(), _Pos.iY(), Rc.right - Rc.left, Rc.bottom - Rc.top, SWP_NOZORDER);
}

FVector2D UEngineWindow::GetMousePos()
{
    POINT MousePoint;

    GetCursorPos(&MousePoint);
    // ������â ��ġ�������� ���콺 �������� 
    ScreenToClient(WindowHandle, &MousePoint);

    return FVector2D(MousePoint.x, MousePoint.y);
}