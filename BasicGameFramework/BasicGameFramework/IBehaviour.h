#pragma once

#include <Windows.h>

struct IBehaviour
{
	virtual ~IBehaviour() = 0;

	virtual void		Init() { }
	virtual void		Update() { }
	virtual void		PhysicsUpdate() { }
	virtual void		LateUpdate() { }
	virtual void		Render(HDC hdc) { }
	virtual void		Release() { }
	virtual void		OnCollision() { }
	virtual void		OnDebug(HDC hdc) { }
};