#pragma once

#include "Util/Type.h"

class Game
{
	enum { MAX_LOADSTRING = 100 };

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

public:
	bool				Init(HINSTANCE hInst);
	INT32				Run();

private:
	ATOM				registerClass();

	void				processInput();
	void				update();
	void				render(HDC hdc);
private:
	HINSTANCE			_hInst = {};
	HWND				_hWnd = {};
	WCHAR				_title[MAX_LOADSTRING] = {};
	WCHAR				_windowName[MAX_LOADSTRING] = {};
	HDC					_hDC = {};
	HDC					_backDC = {};
	HBITMAP				_backBitmap = {};

	Resolution			_res = { 1280, 720 };
};

