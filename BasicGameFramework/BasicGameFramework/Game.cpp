#include "stdafx.h"
#include "Game.h"

#include "Util/Timer.h"
#include "Manager/SceneManager.h"

LRESULT Game::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }

    return 0;
}

Game::~Game() noexcept
{
    DeleteObject(_backBitmap);
    DeleteDC(_backDC);
    ReleaseDC(_hWnd, _hDC);
}

bool Game::Init(HINSTANCE hInst)
{
    LoadStringW(hInst, IDS_APP_TITLE, _title, MAX_LOADSTRING);
    LoadStringW(hInst, IDC_BASICGAMEFRAMEWORK, _windowName, MAX_LOADSTRING);

    _hInst = hInst;

    if (0 == registerClass())
    {
        return false;
    }

    _hWnd = CreateWindowW(_windowName, _title, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, _hInst, nullptr);

    if (_hWnd == NULL)
    {
        return false;
    }

    RECT cr = { 0, 0, _res.Width, _res.Height };
    AdjustWindowRect(&cr, WS_OVERLAPPEDWINDOW, FALSE);
    SetWindowPos(_hWnd, HWND_TOPMOST, 100, 100, cr.right - cr.left, cr.bottom - cr.top, SWP_NOMOVE | SWP_NOZORDER);

    ShowWindow(_hWnd, SW_SHOW);
    UpdateWindow(_hWnd);

    _hDC = GetDC(_hWnd);
    _backDC = CreateCompatibleDC(_hDC);
    _backBitmap = CreateCompatibleBitmap(_hDC, _res.Width, _res.Height);
    SelectObject(_backDC, _backBitmap);

    Input::Init(_hWnd);
    SceneManager::GetInstance()->Init();

    return true;
}

INT32 Game::Run()
{
    Timer::Init();

    MSG msg;

    while (TRUE)
    {
        if (PeekMessage(&msg, nullptr, NULL, NULL, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                break;
            }

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            if (Timer::CanUpdate())
            {
                processInput();
                update();
                render();
            }
        }
    }

    return static_cast<INT32>(msg.wParam);
}

ATOM Game::registerClass()
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = _hInst;
    wcex.hIcon = LoadIcon(_hInst, MAKEINTRESOURCE(IDI_BASICGAMEFRAMEWORK));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = _windowName;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

void Game::processInput()
{
    Input::Update();
}

void Game::update()
{
    //SceneManager::GetInstance()->Update();
}

void Game::render()
{
    PatBlt(_backDC, 0, 0, _res.Width, _res.Height, WHITENESS);

    INT32 fps = static_cast<INT32>(1000.0f / Timer::GetDeltaTime());
    WCHAR str[32];
    swprintf_s(str, L"FPS : %d", fps);
    TextOut(_backDC, 1200, 10, str, wcslen(str));

    //SceneManager::GetInstance()->Render(hdc);

    WCHAR str2[128] = L"";
    if (Input::GetButton('W'))
    {
        swprintf_s(str2, L"W키 꾹 누름");
    }
    else if (Input::GetButtonDown('W'))
    {
        swprintf_s(str2, L"W키 눌림");
    }
    TextOut(_backDC, 500, 500, str2, wcslen(str2));

    auto mousePos = Input::GetMousePosition();
    WCHAR posText[128] = L"";
    swprintf_s(posText, L"Mouse Position (%d, %d)", mousePos.x, mousePos.y);
    TextOut(_backDC, 1100, 100, posText, wcslen(posText));

    WCHAR str3[128] = L"";
    if (Input::GetButton(VK_LBUTTON))
    {
        swprintf_s(str3, L"마우스 왼쪽 버튼 꾹 누름");
    }
    TextOut(_backDC, 500, 600, str3, wcslen(str3));

    BitBlt(_hDC, 0, 0, _res.Width, _res.Height,
        _backDC, 0, 0, SRCCOPY);
}
