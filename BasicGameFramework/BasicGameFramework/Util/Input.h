#pragma once

#include "Singleton.h"

class Input
{
public:
	Input() = delete;
	~Input() = delete;

	static void Update();

	static bool GetKey();
	static bool GetKeyDown();
	static bool GetKeyUp();

	static bool GetMouseButton();
	static bool GetMouseButtonDown();
	static bool GetMouseButtonUp();
private:
};

