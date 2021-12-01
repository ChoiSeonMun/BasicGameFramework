#pragma once

#include <Windows.h>
#include <vector>

class GameObject;

class Scene abstract
{
public:
	virtual ~Scene() = default;

	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	vector<GameObject*>		_objects;
};