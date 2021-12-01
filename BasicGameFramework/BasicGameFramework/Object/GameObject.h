#pragma once

#include <Windows.h>
#include <vector>

class Component;
class DrawComponent;

class GameObject abstract
{
public:
	GameObject() noexcept = default;
	GameObject(INT32 zOrder) noexcept;
	virtual ~GameObject() noexcept;

	virtual bool	Init();
	virtual void	Update();
	virtual void	Render(HDC hdc);
	virtual void	Release();

	void			AddComponent(Component* component);
	void			RemoveComponent(Component* component);
	void			AddDrawComponent(DrawComponent* drawComponent);
	void			RemoveDrawComponent(DrawComponent* drawComponent);

	void			SetPosition(POINT pos);
	POINT			GetPosition() const noexcept;
	void			SetZOrder(INT32 zOrder);
	INT32			GetZOrder() const noexcept;
	void			SetX(INT32 x);
	INT32			GetX() const noexcept;
	void			SetY(INT32 y);
	INT32			GetY() const noexcept;
private:
	POINT						_position = {};
	INT32						_zOrder = 100;
	vector<Component*>			_components;
	vector<DrawComponent*>		_drawComponents;
};