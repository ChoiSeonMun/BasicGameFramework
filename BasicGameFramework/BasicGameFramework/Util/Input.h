#pragma once

#include <Windows.h>

class Input
{
public:
	Input() = delete;
	~Input() = delete;

	static void Update() noexcept;

	static bool GetKey(BYTE vkey) noexcept;
	static bool GetKeyDown(BYTE vkey) noexcept;
	static bool GetKeyUp(BYTE vkey) noexcept;

	static bool GetMouseButton();
	static bool GetMouseButtonDown();
	static bool GetMouseButtonUp();
private:
	static bool _currentKeyStates[256];
	static bool _prevKeyStates[256];
};

