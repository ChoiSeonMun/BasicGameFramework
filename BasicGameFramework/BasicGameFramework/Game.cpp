#include "stdafx.h"
#include "Game.h"
#include "Util/Timer.h"

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

    return true;
}

INT32 Game::Run()
{
    Timer::GetInstance()->Init();

    MSG msg;

    while (TRUE)
    {
        while (PeekMessage(&msg, nullptr, NULL, NULL, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        if (msg.message == WM_QUIT)
        {
            break;
        }

        Timer::GetInstance()->Update();

        if (Timer::GetInstance()->GetDeltaTime() < Timer::MS_PER_UPDATE)
        {
            continue;
        }

        processInput();
        update();
        render(_backDC);
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
}

void Game::update()
{
}

void Game::render(HDC hdc)
{
}