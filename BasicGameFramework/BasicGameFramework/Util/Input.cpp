#include "Input.h"

bool Input::_currentKeyStates[256] = { false };
bool Input::_prevKeyStates[256] = { false };

void Input::Update() noexcept
{
	memcpy(_prevKeyStates, _currentKeyStates, sizeof(_currentKeyStates));

	for (size_t vkey = 0; vkey < 256; ++vkey)
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
}

bool Input::GetKey(BYTE vkey) noexcept
{
	return (_currentKeyStates[vkey] && _prevKeyStates[vkey]);
}

bool Input::GetKeyDown(BYTE vkey) noexcept
{
	return _currentKeyStates[vkey];
}

bool Input::GetKeyUp(BYTE vkey) noexcept
{
	return (_currentKeyStates[vkey] == false && _prevKeyStates[vkey]);
}
