#pragma once

#include <Windows.h>

class Input
{
public:
	Input() = delete;
	~Input() = delete;

	static void		Init(HWND hWnd) noexcept;
	static void		Update() noexcept;

	static bool		GetAnyButton() noexcept;
	static bool		GetAnyButtonDown() noexcept;

	static bool		GetButton(BYTE vkey) noexcept;
	static bool		GetButtonDown(BYTE vkey) noexcept;
	static bool		GetButtonUp(BYTE vkey) noexcept;

	static POINT	GetMousePosition() noexcept;
private:
	static bool		_currentKeyStates[256];
	static bool		_prevKeyStates[256];
	static POINT	_mousePosition;
	static HWND		_hWnd;
};

