#include "Input.h"

bool Input::_currentKeyStates[256] = { false };
bool Input::_prevKeyStates[256] = { false };
POINT Input::_mousePosition = {};
HWND Input::_hWnd = {};

void Input::Init(HWND hWnd) noexcept
{
	_hWnd = hWnd;
}

void Input::Update() noexcept
{
	memcpy(_prevKeyStates, _currentKeyStates, sizeof(_currentKeyStates));

	for (int vkey = 0; vkey < 256; ++vkey)
	{
		if (GetAsyncKeyState(vkey) & 0x8000)
		{
			_currentKeyStates[vkey] = true;
		}
		else
		{
			_currentKeyStates[vkey] = false;
		}
	}

	GetCursorPos(&_mousePosition);
	ScreenToClient(_hWnd, &_mousePosition);
}

bool Input::GetAnyButton() noexcept
{
	for (BYTE key = 0; key < 256; ++key)
	{
		if (GetButton(key))
		{
			return true;
		}
	}

	return false;
}

bool Input::GetAnyButtonDown() noexcept
{
	for (BYTE key = 0; key < 256; ++key)
	{
		if (GetButtonDown(key))
		{
			return true;
		}
	}

	return false;
}

bool Input::GetButton(BYTE vkey) noexcept
{
	return (_currentKeyStates[vkey] && _prevKeyStates[vkey]);
}

bool Input::GetButtonDown(BYTE vkey) noexcept
{
	return (_currentKeyStates[vkey] && _prevKeyStates[vkey] == false);
}

bool Input::GetButtonUp(BYTE vkey) noexcept
{
	return (_currentKeyStates[vkey] == false && _prevKeyStates[vkey]);
}

POINT Input::GetMousePosition() noexcept
{
	return _mousePosition;
}