#pragma once

#include <Windows.h>
#include <vector>

class Component;

class GameObject abstract
{
public:
	GameObject() noexcept = default;
	virtual ~GameObject() noexcept;

	virtual bool	Init();
	virtual void	Update();
	virtual void	Render(HDC hdc);
	virtual void	Release();

	void			AddComponent(Component* component);
	void			RemoveComponent(Component* component);

	void			SetX(INT32 x);
	INT32			GetX() const noexcept;
	void			SetY(INT32 y);
	INT32			GetY() const noexcept;

private:
	POINT						_position = {};
	std::vector<Component*>		_components;
};